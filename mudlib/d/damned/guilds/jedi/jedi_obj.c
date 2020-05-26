inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("jedi object");
  set_short("The symbol of the Jedi Guildmaster");
  set_id(({ "guildmaster object", "jedi object", "symbol" }) );
  set_long(
"This symbol takes the form of a small bejeweled lightsaber.  Type "
"'help guildmaster' for help.");
  set_join_room("/d/damned/guilds/join_rooms/jedi_join");
  return;
}

