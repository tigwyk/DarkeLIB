//    An inheritable object for long term skills or spells, such as weapon forging or enchanting
//    Inherited INSTEAD of skill.c, not in addition to it.
//    When the skill is finished, finish_work is called in the object with the caster/user, and
//    the object worked on as args.
//
//    DarkeLIB 0.1
//    -Diewarzau 8/13/95

inherit "/std/runes/rune";

private string sk_name;
private string rune_name;
private object working_on;
private object who_working;
private string worker_name;
private int time_to_go;
private string work_message;
private object my_shadow, your_shadow;
private int rune_level;

varargs int query_in_progress(object what, object who);
int query_time_spent(object what);
int inc_time_spent(object what);

void create() {
  int i, num;

  ::create();
  rune_name = base_name(this_object());
  i = sizeof(explode(rune_name,"/"));
  rune_name = explode(rune_name, "/")[i-1];
  i=sizeof(explode(rune_name,"_"));
  sk_name="";
  for(num=0;i>num;num++) {
    sk_name += explode(rune_name, "_")[num];
    if(num < i-1) sk_name += " ";
  }
  return;
}

// The following function returns a 1 if the rune is "in progress" on a
// certain object.

varargs int query_in_progress(object what, object who) {
  string name;

  if(who && living(who)) name = (string)who->query_name();
  else name = worker_name;
  if(!what || !objectp(what)) return 0;
  if(what->query_property("progress "+rune_name+"_"+name)) return 1;
}

//    The following function starts or continues work on an object,
//    automatically detecting which is appropriate.  Returs 1 for start,
//    0 for continue, -1 for unsuccessful.

int start_work(object what, object who, int time_needed) {
  if(!what || !objectp(what) || !who || !objectp(who)) {
    remove();
    return -1;
  }
  if(who->query("long term")) {
    message("info", "You may only work on one long term skill/spell/rune "+
	    "at a time.", who);
    remove();
    return -1;
  }
  if(who->query_current_attacker() != 0) {
    message("info", "You may not use this rune during combat.", who);
    remove();
    return -1;
  }
  who_working = who;
  worker_name = who->query_name();
  working_on = what;
/*TLNY2020 test you can walk around and work on LT -but if dropped, you stop working
  my_shadow = new("/std/spells/shadows/move_shadow");
  my_shadow->set_move_func( (: call_other, this_object(), "move_me" :) );
  my_shadow->set_move_arg(who);
  my_shadow->start_shadow(who);
*/
  your_shadow = new("/std/spells/shadows/move_shadow");
  your_shadow->set_move_func( (: call_other, this_object(), "move_me" :) );
  your_shadow->set_move_arg(who);
  your_shadow->start_shadow(what);
  who->set("long term", 1);
  if(!query_in_progress(what)) {
    what->set_property("progress "+rune_name+"_"+worker_name,0);
    message("info", "%^CYAN%^%^BOLD%^You begin work.", who);
    time_to_go = time_needed;
    call_out("inc_work_time", (time_to_go > 67)?67:time_to_go);
    return 1;
  }
  else {
    message("info", "%^BOLD%^%^CYAN%^You continue your work.", who);
    time_to_go = time_needed - (int)what->query_property("progress "+rune_name+"_"+worker_name);
    if(time_to_go < 2) time_to_go = 2;
    call_out("inc_work_time", (time_to_go > 67)?67:time_to_go);
    return 0;
  }
  return 0;
}

void move_me(object who) {
  message("my_action", "%^BOLD%^%^CYAN%^You interrupt your work.",
	  who);
  remove_call_out("inc_work_time");
/*TLNY2020 test you can walk around and work on LT
  if(objectp(my_shadow)) my_shadow->external_destruct(my_shadow);
*/
  if(objectp(your_shadow)) your_shadow->external_destruct(your_shadow);
  who->set("long term", 0);
  remove();
  return;
}
      
int query_time_spent(object what) {
  if(!what || !objectp(what)) return 0;
  return (int)what->query_property("progress "+rune_name+"_"+worker_name);
}

void set_work_message(string str) { work_message = str; }

void inc_work_time() {
  if(!working_on || !who_working || !objectp(working_on) || !objectp(who_working)) {
    if(objectp(who_working)) this_object()->move_me(who_working);
    remove();
    return;
  }

//TLNY 2020 remove interrupt during combat for long term
/*
  if(who_working->query_current_attacker() != 0) {
     message("my_action", "%^BOLD%^%^CYAN%^You interrupt your work.",
	  who_working);
     remove_call_out("inc_work_time");
     if(objectp(my_shadow)) my_shadow->external_destruct(my_shadow);
     if(objectp(your_shadow)) your_shadow->external_destruct(your_shadow);
     who_working->set("long term", 0);
     remove();
     return;
  }
*/
  time_to_go -= 67;
  working_on->set_property("progress "+rune_name+"_"+worker_name,
			   query_time_spent(working_on) + 67);
  if(time_to_go <= 0) {
    message("info", "%^BOLD%^%^CYAN%^You finish your work.", who_working);
    working_on->remove_property("progress "+rune_name+"_"+worker_name);
    who_working->set("long term", 0);
    if(objectp(my_shadow)) my_shadow->external_destruct(my_shadow);
    if(objectp(your_shadow)) your_shadow->external_destruct(your_shadow);
    this_object()->finish_work(who_working, working_on);
    return;
  }
  rune_level = who_working->query_skill(sk_name);
  if(who_working->getenv("DEBUG") == "1") {
    message("info","Funky Skill: "+rune_name, who_working);
    message("info","rune Name: "+sk_name, who_working);
    message("info","rune Level: "+rune_level, who_working);
    message("info","Exp Given: " + (60*rune_level), who_working);
  }
  message("info", work_message, who_working);
  message("info", "Time left: "+sprintf("%d:%02d:%02d",time_to_go/3600,
          (time_to_go%3600)/60,time_to_go%60), who_working);
// Re-added long term EXP TLNY 2020
 who_working->add_exp(((who_working->query_level())*(3*rune_level))+random(rune_level));
// LT EXP GONE FOR BETA, BYE BYE, Thrace June 20, 1999
  call_out("inc_work_time", (time_to_go > 67)?67:time_to_go);
  return;
}






