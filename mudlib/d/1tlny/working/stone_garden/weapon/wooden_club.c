//  Wizard:  Khojem
//  Wooden Club
//  wooden_club.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("wooden club");
    set_ac(2);
    set("id", ({ "wooden club", "club" }));
    set("short", "wooden club");
    set("long", "A large, knot-filled wooden club."
    );
    set_type("blunt");
    set_quality(random(4)+1);
    set_wc(8, "crushing");
    set_verb("pound");
    set_parry_bonus(-15);
    set_weight(350);
    set_value(25);
}
