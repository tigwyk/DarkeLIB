#include <std.h>
#include <clock.h>
#include <def.h>

inherit OBJECT;

int last_used;

void init() {
   ::init();
   add_action("fun_orb","orb");
}
void create() {
    ::create();
    set_name("glass orb");
    set_id(({ "orb", "glowing orb" }));
    set_short("A%^YELLOW%^glowing%^RESET%^orb");
    set_long("This is a perfectly spherical glowing orb approximately nine inches in diameter. it appears like nothing but maybe if you did the commad%^YELLOW%^'orb knowledge'%^RESET%^somthing might happen\n");
    set_weight(10);
    set_value(1);
    return;
}

int fun_orb(string mesg) {
   object ob;

   if(!mesg) {
      notify_fail("orb what?\n");
      return 0;
   }
     if(mesg != "knowledge" && mesg != "knowledge") {
      notify_fail("Nothing appears to happen.\n");
      return 0;
   }
   if(time() - last_used < HOUR) {
     notify_fail("The orb is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR || !last_used) {
      last_used = time();
      ob = new("/std/spells/blessing_of_knowledge");
      ob->set_property("casting time",1);
      ob->set_property("base mp cost",0);
      ob->set_property("skill","temp casting");
      this_player()->set_skill("temp casting",100);
      ob->do_spell( (["caster":this_player(),"target":
         this_player()->query_name(),"power":4,"arg": 0]) );
      write("You cast *4 blessing of knowledge");
      this_player()->delete_skill("temp casting");
      ob->remove();
      return 1;
   }

}
