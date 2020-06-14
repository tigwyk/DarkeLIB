//TLNY2020 Example of basic creatures
 
#include <std.h>

inherit MONSTER;
string mtlname;
string damage1;
string damage2;
int zlevel;

int is_mon() { return 1; }
init() {
  if( this_player()->query_race() == "tyranid" ) {
    force_me("kill tyranid"); //+this_player()->query_name());
  }
}
 
void create() {
   object ob;
   ::create();


    
    switch(random(14)){
      case 0:mtlname="iron";break;
      case 1:mtlname="steel";break;
      case 2:mtlname="boernerine";break;
      case 3:mtlname="mcgrail";break;
      case 4:mtlname="neorolite";break;
      case 5:mtlname="catoetine";break;
      case 6:mtlname="raysorite";break;
      case 7:mtlname="inniculmoid";break;
      case 8:mtlname="elrodnite";break;
      case 9:mtlname="mithril";break;
      case 10:mtlname="platnite";break;
      case 11:mtlname="mabril";break;
      case 12:mtlname="iysaughton";break;
      case 13:mtlname="laen";break;
    }
    switch(random(11)){
      case 0:damage1="crushing";break;
      case 1:damage1="cutting";break;
      case 2:damage1="impaling";break;
      case 3:damage1="impact";break;
      case 4:damage1="stress";break;
      case 5:damage1="fire";break;
      case 6:damage1="cold";break;
      case 7:damage1="vacuum";break;
      case 8:damage1="electricity";break;
      case 9:damage1="disruption";break;
      case 10:damage1="plasma";break;
    }
    switch(random(11)){
      case 0:damage2="crushing";break;
      case 1:damage2="cutting";break;
      case 2:damage2="impaling";break;
      case 3:damage2="impact";break;
      case 4:damage2="stress";break;
      case 5:damage2="fire";break;
      case 6:damage2="cold";break;
      case 7:damage2="vacuum";break;
      case 8:damage2="electricity";break;
      case 9:damage2="disruption";break;
      case 10:damage2="plasma";break;
    }
    zlevel = (30+random(5));

   set_level(zlevel);
   set_overall_ac(zlevel*2);
   set_property("magic resistance", zlevel);
   set_skill("resist stun", zlevel+zlevel+zlevel);
   set_melee_damage(([ "crushing" : zlevel,"plasma" : zlevel, "impact" : zlevel ]));

   set_money("silver", random(100)+5*zlevel); 
   set_name("Space Marine");
   set("id", ({"marine", "space marine"}) );
   set("long"," Space Marines, also known as the Adeptus Astartes, are superhuman warrior-monks who fight for the Imperium of Man. They wear mechanized suits of armor and have modified genomes that grant them superhuman abilities.");
   set_short("["+zlevel+"]Space Marine");    

   set("race", "human");
   set_body_type("human");
   set_gender("male");
   set_alignment(100);
   //set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
   // set("aggressive", 0);

    //set_max_hp(10);
    //set_hp(10);
    //set_max_mp(7000);
    //set_mp(7000);

    set_stats("strength", 150 + 1*zlevel);
    set_stats("dexterity", 150 + 1*zlevel);
    set_stats("constitution", 150 + 1*zlevel);
    set_stats("wisdom", 150 + 1*zlevel);
    set_stats("intelligence", 150 + 1*zlevel);
    set_stats("charisma", 150 + 1*zlevel);
    
    set_skill("axe", 150 + 1*zlevel);
    set_skill("two handed blade", 150 + 1*zlevel);
    set_skill("two handed blunt", 150 + 1*zlevel);
    set_skill("two handed flail", 150 + 1*zlevel);
    set_skill("two handed polearm", 150 + 1*zlevel);
    set_skill("two handed staff", 150 + 1*zlevel);
    set_skill("blade", 150 + 1*zlevel);
    set_skill("blunt", 150 + 1*zlevel);
    set_skill("knife", 150 + 1*zlevel);
    set_skill("flail", 150 + 1*zlevel);
/*
    set_skill("shield bash", 50 + 1*zlevel);
    set_skill("reverse stroke", 50 + 1*zlevel);
    set_skill("combo", 50 + 1*zlevel); //Whirlwind
    set_skill("block", 50 + 1*zlevel);
    set_skill("parry", 50 + 1*zlevel);
    set_skill("melee", 50 + 1*zlevel);
    set_skill("attack", 50 + 1*zlevel);
    set_skill("defense", 50 + 1*zlevel);
    set_skill("dodge", 50 + 1*zlevel);
*/
    set_property("handedness", "right hand");


    ob = new("/d/damned/virtual/vibroaxe_6.weapon");
    ob -> set("short", "%^BOLD%^Power%^RESET%^Axe");
    ob -> set("long", @EndText
A Power Axe is a Power Weapon taking the form of a single or double-edged battle axe. Power Axes vary in length and design, and have been known to be crafted from one of any number of different materials, though usually Adamantium. As with all Power Weapons, when its power field is activated, usually by operating a control located on the hilt, the blade is sheathed in a lethal corona of disruptive energy. This energy field allows the blade to carve through flesh, bone and most forms of armour plate alike, making a Power Axe a highly effective close combat weapon.
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/mabril");
    ob->move(this_object());

    ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("short", "%^BOLD%^Storm%^RESET%^shield");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
 
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^mail");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^greaves");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object()); 

    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^bracer");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^bracer");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^helm");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/metal-boots.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^boots");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/gauntlet.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^gauntlet");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/gauntlet.armour");
    ob -> set("short", "%^BOLD%^Power%^RESET%^gauntlet");
    ob -> set("long", @EndText
The enclosing suits of armour worn by Space Marines are made from thick ceramite plates and would be cumbersome but for electrically motivated fibre bundles that replicate the movements of the wearer and supplement his strength. The last gene-seed organ to be implanted in a Space Marine
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("equip");
}

int loot;

void die(object ob) {
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
loot=(1+random(17));

if (loot == 1){ 
    ob = new("/d/damned/virtual/great-helm.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" helm of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else 
if (loot == 2) { 
    ob = new("/d/damned/virtual/gauntlet.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" gauntlet of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 3) {   
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" mail of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 4) {  
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" boots of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 5) {  
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" shield of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 6) {    
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" greaves of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 7) {   
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" bracer of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 8) {   
    ob = new("/d/damned/virtual/broad-vibrosword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" broad-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 9) {   
    ob = new("/d/damned/virtual/vibroknife_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" knife of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 10) {   
    ob = new("/d/damned/virtual/footman's-mace_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" footman's-mace of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 11) {   
    ob = new("/d/damned/virtual/vibroaxe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" battle-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 12) {   
    ob = new("/d/damned/virtual/two-handed-vibrosword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" two-handed-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 13) {   
    ob = new("/d/damned/virtual/war-hammer_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" war-hammer of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 14) {   
    ob = new("/d/damned/virtual/greate-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" greate-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 15) {   
    ob = new("/d/damned/virtual/shod-staff_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" shod-staff of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else {
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
}
 
   ::die();
}

//Aggressive code to only kill payers see below line above
//set("aggressive", (: call_other, this_object(), "no_other_monsters" :));

int no_other_monsters(object who) {
  if(who->is_player()) {
    if(who->query_invis()) { return 0; }
    if(who->query_hiding() >= 70)  { return 0; }
    if(who->query_stealth() >= 80) { return 0; }
   this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}
