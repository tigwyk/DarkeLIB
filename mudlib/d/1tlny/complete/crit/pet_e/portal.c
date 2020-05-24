// /wizards/excelsior/misc/portal
// creates a doorway to a random destination

#include <std.h>

#define DESTINATIONS ({"/d/damned/akkad/ak_center",\
	"/d/damned/virtual/room_19_30.world",\
	"/d/damned/guilds/join_rooms/thief_join",\
	"/wizards/excelsior/rooms/ent_shack",\
	"/d/damned/virtual/room_28_34.world",\
	"/wizards/khojem/new/room/orc6",\
	"/d/damned/virtual/room_3_25.world",\
	"/d/damned/virtual/room_1_1.world",\
	"/d/damned/virtual/room_39_39.world",\
	"/wizards/duridian/catacomb/catac003"})
#define COLORS ({"%^BOLD%^%^BLUE%^blue","%^BOLD%^%^RED%^red",\
	"%^BOLD%^%^YELLOW%^yellow","%^BOLD%^%^GREEN%^green","%^BOLD%^%^CYAN%^cyan"})
#define COLOR_NAMES ({"blue","red","yellow","green","cyan"})
	
inherit OBJECT;

string where,colour;

void set_color(string color);
string query_color();

void init() {
	::init();
	add_action("enter","enter");
}

string query_destination() { return where; }

int enter(string str) {
	if(id(str)) {
		message("my_action","%^BLUE%^You enter the portal and appear elsewhere.",
			this_player());
		this_player()->move_player(where);
		return 1;
	}
	notify_fail("Enter what?\n");
	return 0;
}

void create() {
	string color;
	int i,n;
	::create();
	set_property("no get",1);
	set_name("portal");
	set("id",({"portal","excelportalid1234"}));
	set_weight(3000000);
	set_value(1);
	set("short","A floating portal");
	set("long","This portal could lead anywhere. Try 'enter'ing "+
		"it. Very interesting...");
	set_color("black");
	i = sizeof(DESTINATIONS);
	where = DESTINATIONS[random(i)];
	call_out("dissolve_portal",500);
}

void set_color(string color) { 
	int i;
	i = member_array(color,COLOR_NAMES);
	if(i < 0) return;
	colour = color;
	i = sizeof(DESTINATIONS);
	where = DESTINATIONS[random(i)];
}

string query_color() { return colour; }

int find_new_color(object *what) {
	int n,i,tmp;
	string *places,*colors;
	what = filter_array(what,"is_portal");
	n = sizeof(what);
	if(!n) return random(sizeof(COLOR_NAMES));
	i = 0;
	places = ({});
	colors = ({});
	while(n--) {
		places += ({ (string)what[n]->query_destination() });
		colors += ({ (string)what[n]->query_color() });
	}
	i = sizeof(COLOR_NAMES);
	n = 0;
	tmp = random(i);
	while(member_array(COLOR_NAMES[tmp], colors) > -1) {
		tmp = random(i);
		n++;
		if(n >= i) return -1;
	}
	i = sizeof(DESTINATIONS);
	n = 0;
	while(member_array(where, places) > -1) {
		where = DESTINATIONS[random(i)];
		n++;
		if(n >= i) return -1;
	}
	return tmp;
}

void setup_color() {
	int i;
	if(!environment(this_object())) return;
	i = find_new_color(all_inventory(environment(this_object())));
	if(i >= 0) set_color(COLOR_NAMES[i]);	
}

int is_portal(object ob) {
	if(ob == this_object()) return 0;
	if(ob->id("excelportalid1234")) return 1;
	return 0;
}

string query_short() {
	int i;
	i = member_array(query_color(),COLOR_NAMES);
	if(i < 0) return "A floating portal";
	return "A "+COLORS[i]+"%^RESET%^%^BOLD%^%^MAGENTA%^ floating portal";
}

int id(string what) {
	if(what == query_color() || what == query_color()+" portal") return 1;
	return ::id(what);
}

void dissolve_portal() {
	message("info","%^BLUE%^Reality stabalizes and the portal dissolves.",
		environment());
	remove();
}
