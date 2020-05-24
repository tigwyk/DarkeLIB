inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","enchanter mark");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",8);
    set_property("base mp cost",37);
    set_property("dev cost", 22);
    set_property("fast dev cost", 56);
    set_property("spell level", 4);
    set_property("moon","luna");
    set_property("caster message","You begin carve your markings into the item.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a item.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell allows the enchanter to carve his mark into an item.  "
"IE name the item to whatever he/she wishes.  Higher power levels  "
"will shorten the casting time on this spell. "
"The format for this spell is as follows: "
"cast <pow> enchanter mark at <item> with <desc> "
"Example: cast *6 enchanter mark at sword with Excalibur"
"This is a long-term spell (see help long-term), and may take much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
  int time,mod;
  string *ids, id;
  if(at->is_living()) {
    message("info", "You cannot mark a living thing!",
            caster);
          caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the enchanting energies and scribble "+
            "all over your item!", caster);
    message("info", (string)caster->query_cap_name() + " scribbles furiously on the item.",
            environment(caster), ({ caster }) );
    at->set_short((string)caster->query_cap_name() + " is a loser!");
    remove();
    return;
  }
  ids=at->query_id();
  id=ids[0];
  at->set_property("new desc", args+" {"+id+"}");
  set_work_message("You enchant the item.");
  time = 1200/power;

  mod = 30+2*props["spell level"];
  start_work(at, caster, (time*mod)/caster->query_skill("enchantment"), power);
  return;
}

void finish_work(object caster, object at, int power) {
//  int ench, i, idx;
 // mixed tmp;

  if(power <= 0) {
    message("info", "BUG in Enchanter spell....unable to complete.", environment(caster));
    remove();
    return;
  }
  message("info", "You are finished enchanting!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+ "magical incantations.", environment(caster), ({ caster }) );
  at->set_short((string)at->query_property("new desc"));
  
  remove();
  return;
}
