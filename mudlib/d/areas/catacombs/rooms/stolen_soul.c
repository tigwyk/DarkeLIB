 
inherit "std/quest_ob";
 
void create() {
    set_name("stolen_soul");
    set_id( ({ "stolen", "stolen_soul", "quest_object" }) );
    set_short("The Quest for the Stolen Soul");
    set_long(
"The famous adventurer Rufus Tenderfoot has fallen under the curse of an\n"+
"evil lich, who has stolen his soul.  Find Rufus's soul so that he can\n"+
"once again walk among the living.  Look for him underground, where\n"+
"the living dead rule supreme.\n"+
"     Quest rating: High Mortal\n");
    set_quest_points(35);
}
 
