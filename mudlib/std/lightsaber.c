/* Definitely added some code from SWMud.
	Credit to the following people:
		Stavros
		Ichthus
		Morgan
		and whoever else originally added stuff for sabers and weapons
*/

#define PLAIN_COLORS ({\
	/* WC */ /* COLOR */\
	/*  0 */  "gray"\
	/*  1 */ ,"dirty pink"\
	/*  2 */ ,"dim pink"\
	/*  3 */ ,"pink"\
	/*  4 */ ,"rosy pink"\
	/*  5 */ ,"neon pink"\
	/*  6 */ ,"very dim violet"\
	/*  7 */ ,"dim violet"\
	/*  8 */ ,"violet"\
	/*  9 */ ,"bright violet"\
	/* 10 */ ,"very bright violet"\
	/* 11 */ ,"very dim orange"\
	/* 12 */ ,"dim orange"\
	/* 13 */ ,"orange"\
	/* 14 */ ,"bright orange"\
	/* 15 */ ,"very bright orange"\
	/* 16 */ ,"very dim yellow"\
	/* 17 */ ,"dim yellow"\
	/* 18 */ ,"yellow"\
	/* 19 */ ,"bright yellow"\
	/* 20 */ ,"very bright yellow"\
	/* 21 */ ,"very dim blue"\
	/* 22 */ ,"dim blue"\
	/* 23 */ ,"blue"\
	/* 24 */ ,"sapphire blue"\
	/* 25 */ ,"sparkling sapphire blue"\
	/* 26 */ ,"very dim red"\
	/* 27 */ ,"dim red"\
	/* 28 */ ,"red"\
	/* 29 */ ,"bright red"\
	/* 30 */ ,"vivid scarlet red"\
	/* 31 */ ,"very dim green"\
	/* 32 */ ,"dim green"\
	/* 33 */ ,"green"\
	/* 34 */ ,"verdant green"\
	/* 35 */ ,"richly verdant green"\
	/* 36 */ ,"very dim cyan"\
	/* 37 */ ,"dim cyan"\
	/* 38 */ ,"cyan"\
	/* 39 */ ,"dazzling cyan"\
	/* 40 */ ,"intensely dazzling cyan"\
	/* 41 */ ,"very dim white"\
	/* 42 */ ,"dim white"\
	/* 43 */ ,"white"\
	/* 44 */ ,"blinding white"\
	/* 45 */ ,"brilliantly blinding white"\
	/* 46 */ ,"very dim black"\
	/* 46 */ ,"dim black"\
	/* 48 */ ,"black"\
	/* 49 */ ,"deep black"\
	/* 50 */ ,"immensely deep black"\
	/* 51 */ ,"rainbow"\
	})

// same as above, but with coloration
#define COLORS ({\
	/* WC */ /* COLOR */\
	/*  0 */  "gray"\
	/*  1 */ ,"%^COLOR197%^dirty pink%^RESET%^"\
	/*  2 */ ,"%^COLOR198%^dim pink%^RESET%^"\
	/*  3 */ ,"%^BOLD%^MAGENTA%^pink%^RESET%^"\
	/*  4 */ ,"%^COLOR200%^rosy pink%^RESET%^"\
	/*  5 */ ,"%^COLOR201%^neon pink%^RESET%^"\
	/*  6 */ ,"%^COLOR53%^very dim violet%^RESET%^"\
	/*  7 */ ,"%^COLOR54%^dim violet%^RESET%^"\
	/*  8 */ ,"%^COLOR55%^violet%^RESET%^"\
	/*  9 */ ,"%^COLOR56%^bright violet%^RESET%^"\
	/* 10 */ ,"%^COLOR57%^very bright violet%^RESET%^"\
	/* 11 */ ,"%^COLOR130%^very dim orange%^RESET%^"\
	/* 12 */ ,"%^COLOR166%^dim orange%^RESET%^"\
	/* 13 */ ,"%^COLOR202%^orange%^RESET%^"\
	/* 14 */ ,"%^COLOR208%^bright orange%^RESET%^"\
	/* 15 */ ,"%^COLOR215%^very bright orange%^RESET%^"\
	/* 16 */ ,"%^COLOR100%^very dim yellow%^RESET%^"\
	/* 17 */ ,"%^COLOR142%^dim yellow%^RESET%^"\
	/* 18 */ ,"%^COLOR184%^yellow%^RESET%^"\
	/* 19 */ ,"%^COLOR190%^bright yellow%^RESET%^"\
	/* 20 */ ,"%^COLOR226%^very bright yellow%^RESET%^"\
	/* 21 */ ,"%^COLOR17%^very dim blue%^RESET%^"\
	/* 22 */ ,"%^COLOR18%^dim blue%^RESET%^"\
	/* 23 */ ,"%^COLOR19%^blue%^RESET%^"\
	/* 24 */ ,"%^COLOR20%^sapphire blue%^RESET%^"\
	/* 25 */ ,"%^COLOR21%^sparkling sapphire blue%^RESET%^"\
	/* 26 */ ,"%^COLOR52%^very dim red%^RESET%^"\
	/* 27 */ ,"%^COLOR88%^dim red%^RESET%^"\
	/* 28 */ ,"%^COLOR124%^red%^RESET%^"\
	/* 29 */ ,"%^COLOR160%^bright red%^RESET%^"\
	/* 30 */ ,"%^COLOR196%^vivid scarlet red%^RESET%^"\
	/* 31 */ ,"%^COLOR22%^very dim green%^RESET%^"\
	/* 32 */ ,"%^COLOR28%^dim green%^RESET%^"\
	/* 33 */ ,"%^COLOR34%^green%^RESET%^"\
	/* 34 */ ,"%^COLOR40%^verdant green%^RESET%^"\
	/* 35 */ ,"%^COLOR46%^richly verdant green%^RESET%^"\
	/* 36 */ ,"%^COLOR27%^very dim cyan%^RESET%^"\
	/* 37 */ ,"%^COLOR33%^dim cyan%^RESET%^"\
	/* 38 */ ,"%^COLOR39%^cyan%^RESET%^"\
	/* 39 */ ,"%^COLOR45%^dazzling cyan%^RESET%^"\
	/* 40 */ ,"%^COLOR51%^intensely dazzling cyan%^RESET%^"\
	/* 41 */ ,"%^COLOR251%^very dim white%^RESET%^"\
	/* 42 */ ,"%^COLOR252%^dim white%^RESET%^"\
	/* 43 */ ,"%^COLOR253%^white%^RESET%^"\
	/* 44 */ ,"%^COLOR254%^blinding white%^RESET%^"\
	/* 45 */ ,"%^COLOR255%^brilliantly blinding white%^RESET%^"\
	/* 46 */ ,"%^COLOR236%^very dim black%^RESET%^"\
	/* 46 */ ,"%^COLOR235%^dim black%^RESET%^"\
	/* 48 */ ,"%^COLOR234%^black%^RESET%^"\
	/* 49 */ ,"%^COLOR233%^deep black%^RESET%^"\
	/* 50 */ ,"%^COLOR232%^immensely deep black%^RESET%^"\
	/* 51 */ ,"%^MAGENTA%^r%^ORANGE%^a%^YELLOW%^i%^BLUE%^n%^RED%^b%^GREEN%^o%^CYAN%^w%^RESET%^"\
	})

inherit "/std/weapon";

string saber_color;
int retracted;



varargs string query_color(int x) {
	if (saber_color)
	  return saber_color;
	if(x)
		return COLORS[x];
	else
		//return "%^BOLD%^GREEN%^bright green%^RESET%^";
		return COLORS[3];
  }

string base_saber_name() {
	return "lightsaber";
  }

string lightsaber_short() {
	string ret = "";
	if (query_wielded()) {
	  ret += query_color()+" ";
	}
	ret += base_saber_name();
	if (!query_wielded())
	  ret += " handle";
	return ret;
  }


string lightsaber_long() {
	string ret;
	ret = "This is the handle of a Jedi Knight's "+query_color()+" "+base_saber_name()+". Just wield it to ignite it.\n";
	return ret;
  }

	create() {
	::create();
	set_ac(6);
	set_name("lightsaber");
  set_id( ({
    "handle",
    "saber",
    "lightsaber"
  }) );
	set_short((: this_object()->lightsaber_short() :));
  	set_long((: this_object()->lightsaber_long() :));
	set_type("lightsaber");
	 set_quality(5);
	set_material("metal/zatrichque");
    set_decay_rate(400);
	set_property("no add quality", 1);
	set_property("poisoning", 5);
	set_weight(15);
	set_wield((: call_other, this_object(), "extra_wield" :));
	set_unwield((: call_other, this_object(), "extra_unwield" :));
	set_value(30);
	set_wc(10, "cutting");
    set_property("enchantment", 4);
    set_property("flame blade", 3);
	set_wc(3, "electricity");
	set_wc(2, "fire");
	set_wc(1, "cold");
	set_verb("slash");
}

void set_saber(int x) {
	saber_color = COLORS[x];
  }

void set_custom_color(string col) {
	saber_color = col;
  }

string query_special_id() {
	return 0;
  }

void retro_set() {
  set_wield((: call_other, this_object(), "extra_wield" :));
  set_unwield((: call_other, this_object(), "extra_unwield" :));
  return;
}

int restore_me(string file) {
  int res;

  res = ::restore_me(file);
  this_object()->retro_set();
  return res;
}


// we don't do messages in two these next two functions so we can do different
// messages for different causes of retraction/extension
void retract() {
	if (retracted)
	  return;
	query_wielded()->set_property("light", -1);
	set_type("blunt");
	retracted = 1;
  }
  
  void extend() {
	if (!retracted)
	  return;
	retracted = 0;
	query_wielded()->set_property("light",1);
	set_type("saber");
  }
  

int extra_wield() {
	if (this_player()->query_class() != "jedi") {
	  write("You cannot wield a saber when cut off from the force.");
	  return 0;
	}
	if(sizeof(this_player()->query_wielded())>1) {
	  write("You are already wielding a weapon.");
	  return 0;
	}
	write("The room takes on a "+query_color()+" glow as your saber ignites with a Snap-hiss.");
	say("The room takes on a "+query_color()+" glow as "+this_player()->query_cap_name()+" ignites "+this_player()->query_possessive()+" saber with a Snap-hiss.");
	this_player()->set_property("light", 1);
	return 1;
  }
  
  int extra_unwield() {
	// different unwield message if retracted --Stav, 15 Apr 2010
	if (query_wielded()) {
	  message("info","You unwield your lightsaber.",query_wielded());
	  if (ENV(query_wielded()))
		message("info",query_wielded()->query_cap_name()+" unwields "
			+query_wielded()->query_possessive()+" lightsaber."
			,ENV(query_wielded()),query_wielded());
	  // extend it just before unwielding, so we do all of the lighting 
	  // stuff properly, and don't have to check for retracted-ness when we
	  // re-wield
	  // --Stav, 15 Apr 2010
	  extend();
	}
	else if (query_wielded()) {
	  message("info","The area darkens as you shut down your lightsaber.",
		  query_wielded());
	  if (ENV(query_wielded()))
		message("info","The area darkens as "+query_wielded()->query_cap_name()+
			" shuts down "+query_wielded()->query_possessive()+" lightsaber.",
			ENV(query_wielded()),({query_wielded()}));
	  query_wielded()->set_property("light", -1);
	}
	return 1;
  }

  string query_s_color() {
	return decolorize(query_color());
  }
  
string *query_id() {
	string c = query_s_color();
	string *ids = ({});
	ids += ::query_id();
	ids += ({ c, c+" saber", c+" lightsaber" });
	if (query_special_id()) {
	  ids += distinct_array(ids + ({ query_special_id() }));
	}
	return ids;
  }
  
  int id(string str) {
	if(!stringp(str) ) return 0;
	if(member_array(str, query_id()) != -1) return 1;
	return ::id(str);
  }