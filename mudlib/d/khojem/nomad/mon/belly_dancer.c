//  Wizard:   Khojem
//  Monster:  belly dancer
//  File:     belly_dancer.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

void init() {
  ::init();
  add_action("go_feel","feel");
  add_action("go_feel","grope");
  add_action("go_feel","caress");
  add_action("go_feel","grab");
  add_action("go_feel","fuck");
  add_action("go_feel","kiss");
}

create() {
  ::create();
    set_name("belly dancer");
    set_id( ({ "belly dancer", "dancer" }) );
    set_level(5);
    set_short("[5]belly dancer");
    set_long("The raven-haired dancer is stunningly beautiful.  Her face is "+
      "veiled, but her dark, doe-like eyes entrance you.  She is a "+
      "full-figured, olive-skinned young woman with rounded breasts.  Her "+
      "slight stomach fat undulates with every erotic movement."
      );
    set("race", "high-man");
    set_gender("female");
    set_body_type("human");
    set_wimpy(0);
    set_emotes(20, ({

	  "A dancer gyrates quickly to the music.  Her hips sway from side-to-side.",
	  "You are awed by the dancers erotic movements.",
	  "The dancer approaches you and winks suggestively.",
	  "A dancer brushes up against you as she moves across the room.",
	  "The dancer arches her back and drops to the floor at your feet.  "+
	    "She sways her stomach in beat to the music. ",
	  "The dancer arches her back and drops to the floor at your feet.  "+
	    "She sways her stomach in beat to the music. "
	}),0);
	new("/d/khojem/nomad/armor/veil")->move(this_object());
	force_me("wear veil");
	new("/d/khojem/nomad/armor/sl_pantaloons")->move(this_object());
	force_me("wear pantaloons");
	new("/d/khojem/nomad/armor/ruby_jewel")->move(this_object());
	force_me("wear ruby");
}

int query_kho_mon() { return 1;}

int go_feel(string str){
  switch(str){

    case "whore"   : break;
    case "bitch"   : break; 
    case "dancer"  : break;
    case "tit"     : break; 
    case "tits"    : break;    
    case "breast"  : break;
    case "hogans"  : break; 
    case "ass"     : break; 
    case "butt"    : break; 
    case "legs"    : break;
    default        : return 0;
  }
  tell_room(environment(this_object()),
    "A belly dancer screams loudly.\n"+
    "A belly dancer slaps "+this_player()->query_cap_name()+
     " hard across the face.\n"
  );
  return 1;
}

