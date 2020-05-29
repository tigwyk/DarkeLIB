// /wizards/excelsior/crits/crit_func
// special results for the aether crit table, accessed with
// eog metal as of 5-6-96
// Excelsior 5-6-96

#define AETHER_ELEMENTS ({"vacuum","electricity","fire","cold","holy"})
#define A_NAME ((string)from->query_name())
#define T_NAME ((string)to->query_name())
#define MONEY_TYPES ({"gold","silver","mithril","electrum","copper",\
	"platinum"})


object environment;
int times;

void pass_storm(object to, object from);
void do_element(object to,object from);

void mad_attack(object from,object to) {
	int rounds;
	object shadow;
	rounds = 2+random(5);
	while(rounds--) {
		message("info","%^ORANGE%^%^BOLD%^"+((string)from->query_cap_name())+" attacks "+((string)to->query_cap_name())+" in a crazed, "+
			"magic induced rage!",
			environment(from),({to,from}));
		message("info","%^ORANGE%^%^BOLD%^You attack "+((string)to->query_cap_name())+" in a crazed, "+
			"magic induced rage!",from);
		message("info","%^ORANGE%^%^BOLD%^"+((string)from->query_cap_name())+" attacks you in a crazed, "+
			"magic induced rage!",to);
		from->continue_attack();
	}
}

void energy_barrier(object from,object to) {
  object ob;
  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(15 + random(25));
  ob->set_expire_message("The energy barrier around you fades away.");
  ob->start_shadow(from, 60);
  return;
}

void melt_inv(object from,object to) {
	object *inv;
	int i, r;
	inv = all_inventory(to);
	i = sizeof(inv);
	r = random(i);
	inv[r]->remove();
	
	message("info","%^RED%^%^BOLD%^Your entire inventory has melted into "+
		"nothingness!!!",to);
}

void lower_max_hp(object from,object to) {
	object shadow;
	seteuid(getuid());
	shadow = new("/std/spells/shadows/max_hp_shadow");
	shadow->start_shadow(to,-(random(400)+100),60);
}

void knock_back(object from,object to) {
	int i;
	string *tmp,destination;
	tmp = environment(to)->query_exits();
	i = sizeof(tmp);
	i--;
        if(i < 0) return;
	while((string)environment(to)->query_pre_exit_func(tmp[i]) &&
		!call_other(environment(to),(string)environment(
			to)->query_pre_exit_func(tmp[i]))) {
		i--; 
		if(i < 0) {
			message("info","%^GREEN%^%^BOLD%^"+(string)to->query_cap_name()+
			" has nowhere to fly.",
				environment(from));
			message("info","%^GREEN%^%^BOLD%^You have nowhere to be hit to.",to);
			return;
		}
	}
	destination = environment(to)->query_exit(tmp[i]);
	to->move(destination);
	message("info","%^GREEN%^%^BOLD%^"+(string)to->query_cap_name()+
		" flies "+tmp[i]+" very fast.",
		environment(from));
	message("info","%^GREEN%^%^BOLD%^You fly "+tmp[i]+" very fast.",to);
}

void bright_light(object from,object to) {	
	object shadow;
	seteuid(getuid());
	shadow = new("/std/spells/shadows/light_shad");
	shadow->set_light(20);
	shadow->start_shadow(to);
	call_out("remove_light_shadow",500,shadow,to);
}

void no_light(object from,object to) {	
	object shadow;
	seteuid(getuid());
	shadow = new("/std/spells/shadows/light_shad");
	shadow->set_light(-25);
	shadow->start_shadow(to);
	call_out("remove_light_shadow",500,shadow,to);
}

void remove_light_shadow(object shadow,object to) {
	shadow->external_destruct(shadow);
	message("info","The light reality hole around your body finally wears off.",to);
}

void rob_money(object from,object to) {
	int i;
	i = sizeof(MONEY_TYPES);
	while(i--) {
		if(to->query_money(MONEY_TYPES[i])) {
			from->add_money(MONEY_TYPES[i],
				(int)to->query_money(MONEY_TYPES[i]));
			to->add_money(MONEY_TYPES[i],
				-(int)to->query_money(MONEY_TYPES[i]));
		}
	}
	message("info","%^RED%^You have lost all the money on your person!!!",to);
}

void drop_all(object from,object to) {
	object *inv;
	int i;
	inv = all_inventory(to);
	i = sizeof(inv);
	while(i--) inv[i]->move(environment(to));
}

void melt_armour(object from, object to) {
	object *inv;
	int i;
	inv = all_inventory(to);
	i = sizeof(inv);
	while(i--) {
		if(inv[i]->is_armour() && inv[i]->query_worn()) {
			message("info","%^BLUE%^"+
				capitalize((string)inv[i]->query_short())+" melts away!",to);
			inv[i]->remove();
			return;
		}
	}
}

void transfer_hp(object from,object to) {
	int amount;
	amount = random(300) + 20;
	from->add_hp(amount);
	if(((int)to->query_hp() - amount) <= 0) {
                if(!(int)to->is_player()) from->add_exp2((int)to->query_exp()/5);
		to->add_hp(-((int)to->query_hp() + 10));
		return;
	}
	to->add_hp(-amount);
}

void heavy_drop(object from,object to) {
	object *inv;
	int i;
	inv = all_inventory(to);
	i = sizeof(inv);
	while(i--) {
		if((int)inv[i]->query_weight() > 120) {
			message("info","%^BLUE%^"+
				capitalize((string)inv[i]->query_short())+" falls to the ground!",to);
			message("info","%^BLUE%^"+((string)to->query_cap_name())+" can no longer hold onto "+
				capitalize((string)inv[i]->query_short())+", so it "+
				"falls to the ground!",environment(to),({to}));
			inv[i]->move(environment(to));
		}
	}
}

void poison_blood(object from,object to) {
	to->add_poisoning(300);
}

void lesser_unworldly(object from,object to) {
	object mon;
	seteuid(getuid());
	mon = new("/wizards/excelsior/crits/lesser_unworldly");
	mon->move(environment(to));
	mon->set_owner((string)from->query_name());
	mon->kill_ob(to,0);
}

void leave_rooms(object from,object to) {
	int flag,damage,whee;
	string direction,dest,func;
	whee = 0;
	while(!flag) {
		if(!to || !environment(to)) flag = 1;
		if(!random(40)) flag = 1;
		if(whee > 80) flag = 1;
		if(!direction)
			direction = ((string *)environment(to)->query_exits())[
				random(sizeof((string *)environment(to)->query_exits()))];
		if(!random(3))
			direction = ((string *)environment(to)->query_exits())[
				random(sizeof((string *)environment(to)->query_exits()))];
		dest = (string)environment(to)->query_exit(direction);
		func = environment(to)->query_exit_func(direction);
		if(!dest || flag || (func && !call_other(environment(to),func))) {
			message("info","You finally come to a rest on a hard surface. OUCH!",
				to);
			message("info",(string)to->query_cap_name()+
				" finally comes to a rest on a hard surface. "+
				"%^YELLOW%^%^BOLD%^AWESOME HIT!!\n"+
				(string)to->query_psubjective()+" can be found at: "+
				"%^RED%^"+(string)environment(to)->query_short()+".",
				environment(from));
			if((int)to->query_hp() <= 0) return;
			damage = -(random(30)+20);
			if(((int)to->query_hp() + damage) <= 0) {
				if(!(int)to->is_player()) from->add_exp2((int)to->query_exp());
				to->add_hp(-((int)to->query_hp() + 10));
			} else { to->add_hp(damage); }
			whee++;
			break;
		}
		message("other_action","%^MAGENTA%^"+(string)to->query_cap_name()+
		" is flung "+direction+"!",from);
		message("other_action","%^MAGENTA%^"+(string)to->query_cap_name()+
		" is flung "+direction+"!",environment(to),({to}));		
		message("my_action","%^MAGENTA%^You are flung "+direction+"!",to);
		to->move(dest);		
		damage = -(random(10)+15);
		if(((int)to->query_hp() + damage) <= 0) {
			if(!(int)to->is_player()) from->add_exp2((int)to->query_exp());
			to->add_hp(-((int)to->query_hp() + 10));
		} else { to->add_hp(damage); }
	}
}

void elemental_control(object from,object to) {
	do_element(to,from);
}

void do_element(object to,object from) {
	string crit;
	int i;
	object tmp;
	i = random(30);
	if(to->query_ghost() || !i || !find_living((string)to->query_name())) {
		if(!i) message("info","%^PINK%^You feel your elemental control "+
			"fade away...",from);
		return;
	}
	i = random(2);
	tmp = present(to,environment(from));
	if(!tmp && !i) {
		message("info","%^GREEN%^%^BOLD%^"+(string)from->query_cap_name()+" uses a powerful wind to drag "+
			"you back into battle!",to);
		message("info","%^GREEN%^%^BOLD%^A powerful wind suddenly "+
			"drags "+(string)to->query_cap_name()+" away.",environment(to),
			({to}));
		message("info","%^GREEN%^%^BOLD%^"+(string)from->query_cap_name()+" uses a powerful wind to "+
			"drag "+(string)to->query_cap_name()+" back into the "+
			"room.",environment(from),({from}));
		message("info","%^GREEN%^%^BOLD%^HA! You're not about to let "+
		(string)to->query_cap_name()+""+((string)to->query_cap_name())+" get "+
			"away that easily! "+
			"You drag "+(string)to->query_objective()+" back into the room!",from);
		to->move(environment(from));
	} else {
		if(!tmp) {
			return;
		}
	}
	i = random(sizeof(AETHER_ELEMENTS));
	crit = AETHER_ELEMENTS[i];
	message("info",((string)from->query_cap_name())+" uses %^RED%^"+crit+"%^RESET%^.",
		environment(from),({from}));
	message("info","You use %^RED%^"+crit+"%^RESET%^.",
		from);
	crit = crit+" "+({"B","C","D","E"})[random(4)];
	do_critical(from, to, ({ crit }) );
	call_out("do_element",2,to,from);
}

void remove_corpse(object from,object to) {
	object *inv;
	if(!(int)to->is_player()) from->add_exp2((int)to->query_exp());
	to->add_hp(-((int)to->query_hp() + 10));
	if(to->is_player()) {
		times = 0;
		call_out("corpse_check",3,to,from);
	}
}		

void greater_unworldly(object from,object to) {
	object mon;
	seteuid(getuid());
	mon = new("/wizards/excelsior/crits/greater_unworldly");
	mon->move(environment(to));
	mon->set_owner((string)from->query_name());
	mon->kill_ob(to,0);
	call_out("remove_pet",3000,mon);
}

void remove_pet(object ob) {
	message("info",(string)ob->query_short()+" suddenly dissapears.",
		 environment(ob));
	ob->remove();
}

void no_balance(object from,object to) {
	object ob;
	message("info","%^MAGENTA%^You begin to have serious trouble focusing on "+
				"things.",to);
	seteuid(getuid());
	ob = new("/std/spells/shadows/blur_shadow");
	ob->set_penalty(random(5)+10);
	ob->start_shadow(to,(100+random(80)),
		"%^CYAN%^You regain control of your vision.");
	call_out("do_balance",1,from,to);
}

void do_balance(object from,object to) {
	object *stuff;
	int i;
	if(!random(30)) return;
	switch(random(4)) {
		case(0):
			stuff = filter_array(map_array((string *)to->query_limbs(),
        		(: call_other, to, "query_weapon" :)),
        		(: ($1 != $2) :), 0);
        	message("info","%^MAGENTA%^In your unbalanced state you are unable to wield "+
        		"your weapons!",to);
        	i = sizeof(stuff);
        	while(i--) {
        		if(stuff[i]->query_wielded())
        			stuff[i]->__ActuallyUnwield();
        	}
        	break;
        case(1):
        	message("my_action","%^MAGENTA%^Shoot! You trip and fall down on one of "+
        		"your weapons!",to);
        	message("other_action","%^MAGENTA%^In "+(string)to->query_possessive()+
        		" unbalanced state "+(string)to->query_cap_name()+" trips and "+
        		"falls on one of his weapons.",environment(to),({to}));
        	i = random(30) + 1;
        	if(to->query_hp() - i <= 0) {
        		from->add_exp2(to->query_exp());
        		to->add_hp(-i);
        		return;
        	}
        	to->add_hp(-i);
        	break;	
        case(2):
        	message("my_action","%^MAGENTA%^You walk into something.",to);
        	message("other_action","%^MAGENTA%^"+(string)to->query_cap_name()+
        	" walks into something.",environment(to),({to}));
        	i = random(20) + 1;
        	if(to->query_hp() - i <= 0) {
        		from->add_exp2(to->query_exp());
        		to->add_hp(-i);
        		return;
        	}
        	to->add_hp(-i);
        	break;
        case(3):
        	message("my_action","%^MAGENTA%^You collapse on the ground.",to);
        	message("other_action","%^MAGENTA%^"+(string)to->query_cap_name()+
        	" collapses on the ground.",environment(to),({to}));
        	i = random(15) + 1;
        	if(to->query_hp() - i <= 0) {
        		from->add_exp2(to->query_exp());
        		to->add_hp(-i);
        		return;
        	}
        	to->add_hp(-i);
        	break;	
        }
       call_out("do_balance",2,from,to);
}
void disturbance(object from,object to) {
	object ob;
	string name;
	message("info","%^YELLOW%^%^BOLD%^The sky grows darker and a thunder storm "+
		"appears out of nowhere. The earth seems to have gone mad!",environment(from));
	seteuid(getuid());
	environment = new("/wizards/excelsior/crits/environment_shadow");
	environment->start_shadow(environment(to),({to,from}));
	message("my_action","%^BLUE%^You rise up into the sky, supported by your "+
		"own magical energies.",from);
	message("info","%^BLUE%^"+(string)from->query_cape_name()+
		" rises up into the sky, supported by "+
		(string)from->query_possessive()+" own magical energies.",environment(to),
			({from}));
	call_out("first_attack",3,to,from);
}

void first_attack(object to,object from) {
	int damage;
	message("my_action","%^BLUE%^Raising you hands into the air, you "+
		"annihilate "+(string)to->query_cap_name()+
		" with a powerful electrical blast.",from);
	message("info","%^BLUE%^"+(string)from->query_cap_name()+" raises "+
		(string)from->query_possessive()+" hands into the air and utterly "+
			"devestates "+(string)to->query_cap_name()+
			" with a powerful electrical blast.",environment(to),
			({from,to}));
	message("info","%^BLUE%^"+(string)from->query_cap_name()+" raises "+
		(string)from->query_possessive()+" hands into the air and utterly "+
		"devestates you with a powerful electrical blast.",
		to);
	damage = random(100)+10;
	if(((int)to->query_hp() - damage) <= 0) {
		if(!(int)to->is_player()) from->add_exp2((int)to->query_exp());
		to->add_hp(-((int)to->query_hp() + 10));
		pass_storm(to,from);
	}
	call_out("second_attack",3,to,from);
}

void second_attack(object to,object from) {
	object ob;
	int i;
	message("my_action","%^BLUE%^In your game of playing god, you create "+
		"several little dwarvish creatures to attack "+
		(string)to->query_cap_name()+".",from);
	message("my_action","%^BLUE%^"+(string)from->query_cap_name()+
		" creates several dwarvish creatures to attack "+
		(string)to->query_cap_name()+".",environment(to),({to,from}));
	message("my_action","%^BLUE%^"+(string)from->query_cap_name()+
		" creates several dwarvish creatures to attack "+
		"you.",to);
	i = random(3)+7;
	while(i > 0) {
		seteuid(getuid());
		ob = new("/wizards/excelsior/crits/gnome_man");
		ob->move(environment(to));
		ob->target(to,from);
		i--;
	}
	call_out("pass_storm",random(300)+300,to,from);
}

void pass_storm(object to,object from) {
	int i;
	while(present("gnome_man",environment(to))) {
		message("info","A small gnome man suddenly dissolves.",environment(to));
		present("gnome_man",environment(to))->remove();
	}
	environment->external_destruct(environment);
	message("info","%^YELLOW%^%^BOLD%^The sky grows light again as the temporal "+
		"disturbance passes.",environment(from));
}

void leave_dimension(object from,object to) {
	object where,ob;
	int n;
	n = 5;
	message("info","%^CYAN%^Several %^RED%^portals "+
		"%^RESET%^%^CAYN%^appear as reality weakens.");
	while(n--) {
		seteuid(getuid());
		ob = new("/wizards/excelsior/misc/portal");
		ob->move(environment(from));
		ob->setup_color();
	}
	to->add_hp(-((int)to->query_hp() + 30));
	message("info","%^RED%^"+(string)to->query_cap_name()+" suddenly "+
		"fades into nothingness.",environment(to),({to}));
	if(!to->is_player()) return;
	message("info","%^RED%^You find yourself transported to a very strange place.",
		to);
	where = new("/wizards/excelsior/crits/dimensional_room");
	to->move(where);
	times = 0;
	call_out("corpse_check",3,to,from);
}

void corpse_check(object who,object from) {
	object ob;
	if(!who->query_ghost()) {
		if(times > 30) return;
		call_out("corpse_check",3,who,from);
		times++;
		return;
	}
	ob = (object)who->query("corpse ob");
	if(!present(ob,environment(from))) ob->move(environment(from));
	ob->remove();
}

void go_to_hell(object from,object to) {
		message("info","%^RESET%^%^BOLD%^%^RED%^FFFFFF%^RESET%^%^BOLD%^\\ "+
" %^RED%^AAAAAA%^RESET%^%^BOLD%^\\  "+
"  %^RED%^TTTTTT%^RESET%^%^BOLD%^\\"+
"  %^RED%^AAAAAA%^RESET%^%^BOLD%^\\  %^RED%^LL%^RESET%^%^BOLD%^\\ "+
"     %^RED%^III%^RESET%^%^BOLD%^\\  %^RED%^TTTTTT%^RESET%^%^BOLD%^\\  "+
"%^RED%^YY  YY%^RESET%^%^BOLD%^\\\n"+   
"%^RESET%^%^BOLD%^%^RED%^FFFFFF%^RESET%^%^BOLD%^\\ "+
" %^RED%^AA%^RESET%^%^BOLD%^\\\\%^RED%^AA%^RESET%^%^BOLD%^\\ "+
" %^RED%^TTTTTT%^RESET%^%^BOLD%^\\  %^RED%^AA%^RESET%^%^BOLD%^\\\\%^RED%^A"+
"A%^RESET%^%^BOLD%^\\  %^RED%^LL%^RESET%^%^BOLD%^\\   "+
"   %^RED%^III%^RESET%^%^BOLD%^\\  %^RED%^TTTTTT%^RESET%^%^BOLD%^\\  %^RED%^YY  YY%^RESET%^%^BOLD%^\\\n"+
"%^RESET%^%^BOLD%^%^RED%^FF%^RESET%^%^BOLD%^\\\\\\\\\\  "+
"%^RED%^AA%^RESET%^%^BOLD%^\\ %^RED%^AA%^RESET%^%^BOLD%^\\  "+
"  %^RED%^TT%^RESET%^%^BOLD%^\\\\\\  %^RED%^AA%^RESET%^%^BOLD%^\\ "+
"%^RED%^AA%^RESET%^%^BOLD%^\\  %^RED%^LL%^RESET%^%^BOLD%^\\  "+
"    %^RED%^III%^RESET%^%^BOLD%^\\    %^RED%^TT%^RESET%^%^BOLD%^\\\\\\  "+
"%^RED%^YY  YY%^RESET%^%^BOLD%^\\\n"+
"%^RESET%^%^BOLD%^%^RED%^FFFFFF%^RESET%^%^BOLD%^\\%^RED%^  "+
"%^RED%^AAAAAA%^RESET%^%^BOLD%^\\    %^RED%^TT%^RESET%^%^BOLD%^\\  "+
"  %^RED%^AAAAAA%^RESET%^%^BOLD%^\\  %^RED%^LL%^RESET%^%^BOLD%^\\  "+
"    %^RED%^III%^RESET%^%^BOLD%^\\    %^RED%^TT%^RESET%^%^BOLD%^\\  "+
"  %^RED%^YYYYYY%^RESET%^%^BOLD%^\\\n"+
"%^RESET%^%^BOLD%^%^RED%^FF%^RESET%^%^BOLD%^\\\\\\\\\\ "+
" %^RED%^AA%^RESET%^%^BOLD%^\\\\%^RED%^AA%^RESET%^%^BOLD%^\\  "+
"  %^RED%^TT%^RESET%^%^BOLD%^\\    %^RED%^AA%^RESET%^%^BOLD%^\\\\%^RED%^A"+
"A%^RESET%^%^BOLD%^\\  %^RED%^LL%^RESET%^%^BOLD%^\\"+
"      %^RED%^III%^RESET%^%^BOLD%^\\    %^RED%^TT%^RESET%^%^BOLD%^\\   "+
"   %^RED%^YY%^RESET%^%^BOLD%^\\\n"+
"%^RESET%^%^BOLD%^%^RED%^FF%^RESET%^%^BOLD%^\\  "+
"    %^RED%^AA%^RESET%^%^BOLD%^\\ %^RED%^AA%^RESET%^%^BOLD%^\\  "+
"  %^RED%^TT%^RESET%^%^BOLD%^\\    %^RED%^AA%^RESET%^%^BOLD%^\\ "+
"%^RED%^AA%^RESET%^%^BOLD%^\\  %^RED%^LLLLLL%^RESET%^%^BOLD%^\\  "+
"%^RED%^III%^RESET%^%^BOLD%^\\    %^RED%^TT%^RESET%^%^BOLD%^\\   "+
"   %^RED%^YY%^RESET%^%^BOLD%^\\\n"+
"%^RESET%^%^BOLD%^%^RED%^FF%^RESET%^%^BOLD%^\\     "+
" %^RED%^AA%^RESET%^%^BOLD%^\\ %^RED%^AA%^RESET%^%^BOLD%^\\  "+
"  %^RED%^TT%^RESET%^%^BOLD%^\\    %^RED%^AA%^RESET%^%^BOLD%^\\ "+
"%^RED%^AA%^RESET%^%^BOLD%^\\  %^RED%^LLLLLL%^RESET%^%^BOLD%^\\  "+
"%^RED%^III%^RESET%^%^BOLD%^\\    %^RED%^TT%^RESET%^%^BOLD%^\\"+
"      %^RED%^YY%^RESET%^%^BOLD%^\\\n"+
"%^RESET%^%^BOLD%^\\\\\\      \\\\\\ \\\\\\    \\\\\\    \\\\\\ \\\\\\ "+
" \\\\\\\\\\\\\\  \\\\\\\\    \\\\\\      \\\\\\\n",environment(from));
	if(!to->is_player()) return;
	to->move_player("/wizards/excelsior/crits/hell");
}





