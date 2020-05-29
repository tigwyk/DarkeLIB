inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/elementalist/ele_train", "east");
   set("short","The Elementalist Treasury");
   set("long",
"This storage room is cluttered with many items. In the past the master "
"elementalists would leave items for their younger guild brothers and "
"sisters to use. You can do the same and leave useful items in the "
"lockers and chests that lie about. All around you see magical items, "
"and weapons that aid the elementalists. You can borrow them, but please "
"put them back.\n\nMAKE SURE you close a chest after using it!\n");
}

