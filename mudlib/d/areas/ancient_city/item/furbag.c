
inherit "/std/bag_logic.c";

        create() {
        ::create();
set_name("grey fur bag.");
set("id", ({"bag", "grey fur bag"}) );
set("short", "A grey fur bag.");
set("long", "A bag made out of rat fur from the shaded fur of the rats
around the area");
        set_weight(5);
        set_max_internal_encumbrance(100);
        set_value(10);
}
