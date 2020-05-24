
#include <std.h>

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange;

        ::create();
        set_name("rat");
        set_id(({"rat"}));
        roll=random(10);
        switch(roll){
        case 0:zlevel=1;break;
        case 1:zlevel=1;break;
        case 2:zlevel=1;break;
        case 3:zlevel=1;break;
        case 4:zlevel=2;break;
        case 5:zlevel=2;break;
        case 6:zlevel=2;break;
        case 7:zlevel=2;break;
        case 8:zlevel=3;break;
        case 9:zlevel=4;break;
}
        set("race", "rodent");
        set_short("["+zlevel+"]rat");
set_long("A dirty rat with pieces of cheeze hanging from it's mouth, it
scurries from corner to corner looking for more food to scavenge.");
set_body_type("rat");
        set_level(zlevel);
        xskill=4*zlevel;
        set_skill("dodge", xskill);
        set_skill("melee", xskill);
        set_skill("attack", xskill);
        xchange=random(2);
if(xchange)
        set_gender("male");
else set_gender("female");
}
