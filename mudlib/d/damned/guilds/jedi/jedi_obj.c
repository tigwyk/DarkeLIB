inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("sword-mage object");
  set_short("The symbol of the Sword-mage Guildmaster");
  set_id(({ "guildmaster object", "sword-mage object", "symbol" }) );
  set_long(
"This symbol takes the form of a small bejeweled sword.  Type "
"'help guildmaster' for help.");
  set_join_room("/d/damned/guilds/join_rooms/sword-mage_join");
  return;
}

