/* Elixir of Youth coded by Duridian for DarkeMud.
   Heals players, needed to complete the catacombs quest. */
 
inherit "/std/drink";
 
void create() {
   ::create();
   set_name("elixir of youth");
   set("id", ({"elixir", "potion", "elixir of youth", "vial", "small vial", "elixir_of_youth"}) );
   set("short", "Elixir of Youth");
   set("long",  "The small vial is filled with a pink liquid.");
   set("empty name", "small vial");
   set("value", random(100)+100);
   set_strength(random(10)+5);
   set_weight(20);
}
