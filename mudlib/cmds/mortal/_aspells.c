//	_inventory.c written by Descartes October 1992

#include "move.h"
#include <std.h>

inherit DAEMON;

int cmd_aspells() {
	//object ob;

    write("\n%^BOLD%^Active Spells:");
    
	if(this_player()->query("disguise shad")) {
     write("%^CYAN%^alter visage");
      }
	// if(this_player()->query("darkvision")) {
	 //printf("dark vision, ");
   	 //}
   	 if(this_player()->query_haste()) {
     write("%^CYAN%^haste");
     }
	 if(this_player()->query_stack("rap") >= 2) {
        write("%^CYAN%^shield of ithian (2)");
      }
     if(this_player()->query_stack("rap") == 1) {
        write("%^CYAN%^shield of ithian");
      } 
      if(this_player()->query_stack("ram") == 1) {
        write("%^CYAN%^armour of oblivion");
      }
      if(this_player()->query_stack("ram") >= 2) {
        write("%^CYAN%^armour of oblivion (2)");
      }
	if(this_player()->query("holy armour #")) {
        write("%^CYAN%^holy armour");
      }
      if(this_player()->query_battle_aura()) {
        write("%^CYAN%^battle aura");
      }
      if(this_player()->query_holy_aura()) {
        write("%^CYAN%^holy aura");
      }
    //  if(this_player()->query_battle_fury()) { shows up as haste...
      //  write("%^CYAN%^battle fury");
      //}
	if(this_player()->query_shields_of_war()) {
        write("%^CYAN%^shields of war");
      }
    if(this_player()->query("see invis")) {
        write("%^CYAN%^invisibility");
      }
    if(this_player()->query("k bless num") == 1) {
        write("%^CYAN%^blessing of knowledge");
      }
      if(this_player()->query("k bless num") >= 2) {
        write("%^CYAN%^blessing of knowledge (2)");
      }
     if(this_player()->query("a bless num") >= 2) {
        write("%^CYAN%^blessing of agility (2)");
      }
      if(this_player()->query("a bless num") == 1) {
        write("%^CYAN%^blessing of agility");
      }
      if(this_player()->query_stack("unholy armour")) {
        write("%^CYAN%^unholy armour");
      }
      
      write("\n");
      return 1;
}

int
help() {
   write("Command: aspells\nSyntax: aspells\n"+
      "This command gives you a list of active spells\n"+
      "if your lucky.\n"
   );
   return 1;
}
/* EOF 

query_stack(props["stack key"])
*/


