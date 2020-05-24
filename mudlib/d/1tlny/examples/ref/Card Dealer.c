// a fun poker dealer

//  __________  __________  __________  __________  __________
// | 5        || A        || 10       || J        ||          |
// |    /\    ||    /\    ||   /\/\   ||    /\    ||          |          
// |   /  \   ||   /  \   ||   \  /   ||  |~  ~|  ||          |
// |   \  /   ||   ~||~   ||    \/    ||   ~||~   ||          |
// |    \/    ||          ||          ||    ||    ||          |
// |        5 ||        A ||        10||        J ||          |
// |__________||__________||__________||__________||__________|
//      1           2           3           4           5

#include <std.h>

#define FIRST_LINE " __________  __________  __________  __________  __________"
#define SECOND_LINE ({"| ","       || ","       || ","       || ","       || ","       |"})
#define SUIT_LINES ({ ({"|   ","   ||   ","   ||   ","   ||   ","   ||   ","   |"}), \
			({"|  ","  ||  ","  ||  ","  ||  ","  ||  ","  |"}), \
			({"|   ","   ||   ","   ||   ","   ||   ","   ||   ","   |"}), \
			({"|    ","    ||    ","    ||    ","    ||    ","    ||    ","    |"}) }) 
#define SEVENTH_LINE ({"|        ","||        ","||        ","||        ","||        ","|"})
#define EIGHT_LINE "|__________||__________||__________||__________||__________|"
#define HEARTS ({"%^RED%^%^BOLD%^/\\/\\%^RESET%^","%^RED%^%^BOLD%^ \\  / %^RESET%^","%^RED%^%^BOLD%^ \\/ %^RESET%^","  "})
#define SPADES ({"%^BOLD%^ /\\ %^RESET%^","%^BOLD%^ /  \\ %^RESET%^","%^BOLD%^~||~%^RESET%^","  "})       
#define DIAMONDS ({"%^RED%^%^BOLD%^ /\\ %^RESET%^","%^RED%^%^BOLD%^ /  \\ %^RESET%^","%^RED%^%^BOLD%^\\  /%^RESET%^","%^RED%^%^BOLD%^\\/%^RESET%^"})
#define CLUBS ({"%^BOLD%^ /\\ %^RESET%^","%^BOLD%^|~  ~|%^RESET%^","%^BOLD%^~||~%^RESET%^","%^BOLD%^||%^RESET%^"})
#define FACE ({" A"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," K"," Q"})
#define SUIT ({"D","S","C","H"})

inherit MONSTER;

string *cards_dealt;
mapping hands,met_raise;
int pot,flag,whose_turn,current_bet,raises;
object *players;

void display_hand(object who,object to_who);
void fold();
void ante();
void start_game();
void next_turn();
void who_wins();
string deal_card();

void display_hand(object who,object to_who) {
	int n,i,row;
	string name,suit_pic,*tmp,str;
	name = (string)who->query_name();
	if(!hands[name]) {
		write("You don't have any cards.");
		return;
	}
	message("info",FIRST_LINE,to_who);
	n = 0;
	i = 0;
	while(n < 6) {
		if(n != 5) {
			message("Ninfo",SECOND_LINE[n]+hands[name][i][0..1],to_who);
			i++;
			n++;
		}
		else {
			message("Ninfo",SECOND_LINE[n]+"\n",to_who);
			n++;
		}
	}
	row = 0;
	n = 0;
	i = 0;
	while(row < 4) {
		while(n < 6) {
			if(n != 5) {
				switch(hands[name][i][2..2]) {
				case "S":
					message("Ninfo",SUIT_LINES[row][n]+SPADES[row],to_who);
					break;
				case "D":
					message("Ninfo",SUIT_LINES[row][n]+DIAMONDS[row],to_who);
					break;
				case "C":
					message("Ninfo",SUIT_LINES[row][n]+CLUBS[row],to_who);
					break;	
				case "H":
					message("Ninfo",SUIT_LINES[row][n]+HEARTS[row],to_who);
					break;	
				}
				i++;
				n++;
			}
			else {
				message("Ninfo",SUIT_LINES[row][n]+"\n",to_who);
				n++;
			}
		}
		row++;
		n = 0;
		i = 0;
	}
	n = 0;
	i = 0;
	while(n < 6) {
		if(n != 5) {
			message("Ninfo",SEVENTH_LINE[n]+
				hands[name][i][0..1],to_who);
			i++;
			n++;
		}
		else {
			message("Ninfo",SEVENTH_LINE[n]+"\n",to_who);
			n++;
		}
	}
	message("info",EIGHT_LINE,to_who);
	message("info","%^BLUE%^%^BOLD%^     1           2           3 "+
		"          4           5",to_who);
}

int present_players(object who) {
	if(!present(who,environment())) return 0;
	return 1;
}

string deal_card() {
	string test;
	int i,i2,flag3;
	i = sizeof(FACE);
	i2 = sizeof(SUIT);
	flag3 = 1;
	while(flag3) {
		test = FACE[random(i)]+SUIT[random(i2)];
		if(member_array(test,cards_dealt) < 0) {
			flag3 = 0;
		}
	}
	cards_dealt += ({test});
	return test;
}

void init() {
	::init();
	add_action("ante","ante");
	add_action("bet","bet");
	add_action("call_bet","call");
	add_action("check","check");
	add_action("raise","raise");
	add_action("discard","discard");
	add_action("fold","fold");
	add_action("hand","hand");
	add_action("turn","turn");
	add_action("pot","pot");
}

int hand() {
	display_hand(this_player(),this_player());
	return 1;
}

int	turn() {
	if(!flag) {
		write("No game is currently in progress.");
		return 1;
	}
	if (!players) return 0;
	if(whose_turn >= sizeof(players)) {
		write("No game is currently in progress.");
		return 1;
	}
	if(players[whose_turn] == this_player()) {
		write("It is currently your turn to play.");
		return 1;
	}
	write("It is currently "+(string)players[whose_turn]->query_cap_name()
		+"'s turn.");
	return 1;
}
	
int discard(string cards) {
	mixed *stf2;
	int i,flg,*stf;
	if(players[whose_turn] != this_player()) {
		write("It it not your turn to play.");
		return 1;
	}
	if(current_bet || flag != 2) {
		write("Discarding is not an option right now.");
		return 1;
	}
	if(!cards) {
		whose_turn++;
		next_turn();
		return 1;
	}
	replace_string(cards," ","");
	stf2 = explode(cards,",");
	stf = allocate(sizeof(stf2));
	i = sizeof(stf2);
	while(i--) {
		if(sscanf(stf2[i],"%d",stf[i]) != 1
				|| stf[i] > 5 || stf[i] < 1) {
			flg = 1;
			break;
		}
	}
	if(flg) {
		write("That is not in the right format.");
		return 1;
	}
	i = sizeof(stf);
	this_player()->more(hands[(string)this_player()->query_name()]);
	while(i--) 
		hands[(string)this_player()->query_name()][stf[i]-1] = deal_card();
	this_player()->more(hands[(string)this_player()->query_name()]);
	display_hand(this_player(),this_player());
	whose_turn++;
	next_turn();
	return 1;
}

void pot() {
	int bet;
	if(!flag) {
		write("No game is currently in progress.");
		return 1;
	}
	if (!players) return 0;
	if(whose_turn >= sizeof(players)) {
		write("No game is currently in progress.");
		return 1;
	}
	if(flag != 2 && flag < 4) {
		bet = current_bet*sizeof(players);
	} else {
		bet = 0;
	}
	bet += pot;
	write("The pot is currently worth %^BLUE%^"+bet+"%^RESET%^ gold.");
	return 1;
}

void create() {
	::create();
	set_name("dealer");
	set("id",({"dealer","poker dealer","card dealer"}));
	set("short","[10]card dealer");
	set_level(10);
}

void start_game() {
	object *p_present;
	int i,n;
	if(!players) return;
	p_present = filter_array(players,"present_players",this_object());
	if(sizeof(p_present) <= 1) {
		players = 0;
		flag = 0;
		if(!sizeof(p_present))	return;
		message("info","You are the only one in the game still here, so the pot "+
			"is returned to you.",p_present[0]);
		p_present[0]->add_money("gold",pot);
		return;
	}
	flag = 1;
	players = p_present;
	i = sizeof(players);
	cards_dealt = ({});
	hands = ([]);
	raises = 0;
	current_bet = 0;
	met_raise = ([]);
	whose_turn = 0;
	message("info","The dealer deals the cards.",environment());
	while(i--) {
		n = 5;
		hands[(string)players[i]->query_name()] = ({});
		while(n > 0) {
			hands[(string)players[i]->query_name()] += ({deal_card()});
			n--;
		}
		display_hand(players[i],players[i]);
	}
	whose_turn = 0;
	next_turn();
}

int fold() {
	int i;
	if(flag == 2) {
		write("You can't fold right now.");
		return 1;
	}
	if(players[whose_turn] != this_player()) {
		write("It it not your turn to play.");
		return 1;
	}
	write("You throw in your cards.");
	message("info",(string)this_player()->query_cap_name()+
		" %^GREEN%^%^BOLD%^folds.",environment(),({this_player()}));
	i = member_array(this_player(),players);
	players -= ({this_player()});
	if(met_raise[(string)this_player()->query_name()] > 
			(int)this_player()->query_money("gold")) {
		this_player()->set_money("gold",0); }
	else { this_player()->set_money("gold",
		-met_raise[(string)this_player()->query_name()]); }
	hands[(string)this_player()->query_name()] = 0;
	whose_turn++;
	next_turn();
	return 1;
}

int bet(string number) {
	int amount;
	if(players[whose_turn] != this_player()) {
		write("It it not your turn to play.");
		return 1;
	}
	if(current_bet || flag == 2 || flag >= 4) {
		write("Betting is not an option right now.");
		return 1;
	}
	if(sscanf(number,"%d",amount) != 1) {
		write("Bet how much?");
		return 1;
	}
	if(amount > 100) {
		write("The maximum bet allowed is 100 gold.");
		return 1;
	}
	if(amount > (int)this_player()->query_money("gold")) {
		write("You cannot afford that bet.");
		return 1;
	}
	current_bet = amount;
	met_raise[(string)this_player()->query_name()] = amount;
	this_player()->add_money("gold",-amount);
	message("info",(string)this_player()->query_cap_name()+
		" %^GREEN%^bets%^RESET%^ %^BLUE%^"+amount+"%^RESET%^ "+
		"gold.",environment(),({this_player()}));
	message("info","You bet %^BLUE%^"+amount+"%^RESET%^ gold.",
		this_player());
	if(!this_player()->query_env("NO_GOLD_REPORT")) 
		write("You have: %^CYAN%^"+(int)this_player()->query_money(
			"gold")+"%^RESET%^ gold.");
	whose_turn++;
	raises++;
	next_turn();
	return 1;
}
	
int raise(string number) {
	int amount;
	if(players[whose_turn] != this_player()) {
		write("It it not your turn to play.");
		return 1;
	}
	if(!current_bet || flag == 2 || flag >= 4) {
		write("Raising is not an option right now.");
		return 1;
	}
	if(sscanf(number,"%d",amount) != 1) {
		write("Raise how much?");
		return 1;
	}
	if(amount > 100) {
		write("The maximum raise allowed is 100 gold.");
		return 1;
	}
	if((amount+current_bet) > (int)this_player()->query_money("gold")) {
		write("You cannot afford that bet.");
		return 1;
	}
	current_bet += amount;
	this_player()->add_money("gold",
		-(current_bet - met_raise[(string)this_player()->query_name()]));
	met_raise[(string)this_player()->query_name()] = current_bet;
	message("info",(string)this_player()->query_cap_name()+
		" %^GREEN%^raises%^RESET%^ the pot %^BLUE%^"+amount+"%^RESET%^ "+
		"gold.",environment(),({this_player()}));
	message("info","You raise the pot %^BLUE%^"+amount+"%^RESET%^ gold.",
		this_player());
	if(!this_player()->query_env("NO_GOLD_REPORT")) 
		write("You have: %^CYAN%^"+(int)this_player()->query_money(
			"gold")+"%^RESET%^ gold.");
	whose_turn++;
	raises++;
	next_turn();
	return 1;
}

void call_bet() {
	if(players[whose_turn] != this_player()) {
		write("It it not your turn to play.");
		return 1;
	}
	if(!current_bet || flag == 2 || flag >= 4) {
		write("Calling is not an option right now.");
		return 1;
	}
	message("info","You call the bet.",this_player());
	message("info",(string)this_player()->query_cap_name()+
		" %^GREEN%^%^BOLD%^calls%^RESET%^.",environment(),
		({this_player()}));
	this_player()->add_money("gold",
		-(current_bet - met_raise[(string)this_player()->query_name()]));
	met_raise[(string)this_player()->query_name()] = current_bet;
	if(!this_player()->query_env("NO_GOLD_REPORT")) 
		write("You have: %^CYAN%^"+(int)this_player()->query_money(
			"gold")+"%^RESET%^ gold.");
	whose_turn++;
	next_turn();
	return 1;
}

void check() {
	if(players[whose_turn] != this_player()) {
		write("It it not your turn to play.");
		return 1;
	}
	if(current_bet || flag == 2 || flag >= 4) {
		write("Checking is not an option right now.");
		return 1;
	}
	message("info","You check.",this_player());
	message("info",(string)this_player()->query_cap_name()+
		" %^GREEN%^%^BOLD%^checks%^RESET%^.",environment(),
		({this_player()}));
	met_raise[(string)this_player()->query_name()] = current_bet;
	whose_turn++;
	next_turn();
	return 1;
}

void next_turn() {
	object *p_present;
	string options;
	int whee;
	if(!players) {
		flag = 0;
		return;
	}
	p_present = filter_array(players,"present_players",this_object());
	if(sizeof(p_present) <= 1) {
		players = 0;
		flag = 0;
		if(!sizeof(p_present))	return;
		message("info","You are the only one in the game still here, so the pot "+
			"is returned to you.",p_present[0]);
		p_present[0]->add_money("gold",pot);
		return;
	}
	whee = 0;
	if(current_bet) {
		if(whose_turn >= sizeof(players)) whose_turn = 0;
		while(met_raise[(string)players[whose_turn]->query_name()] 
				>= current_bet) {
		 	whose_turn++;
		 	whee++;
		 	if(whose_turn >= sizeof(players)) whose_turn = 0;	
		 	if(whee >= sizeof(players)) {
		 		whose_turn = whee;
		 		break;
		 	}
		}
	}
	if(whose_turn >= sizeof(players)) {
		message("info",sprintf("%d",flag),environment());
		met_raise = ([]);
		switch(flag) {
			case 0:
				return;
			case 1:
				pot += current_bet * sizeof(players);
				message("info","Discarding begins.",environment());
				whose_turn = 0;
				current_bet = 0;
				break;
			case 2:
				message("info","The second betting round begins.",
					environment());
				whose_turn = 0;
				met_raise = ([]);
				current_bet = 0;
				raises = 0;
				break;
			case 3:
				pot += current_bet * sizeof(players);
//				who_wins();
				return;
		}
		flag++;
	}
	message("info",sprintf("%d",flag),environment());
	message("info","The dealer looks towards "+
		(string)players[whose_turn]->query_cap_name()+".",environment(),
		({players[whose_turn]}));
	switch(flag) {
		case 0:
			return;
		case 1:
			if(current_bet) {
				options = "You can '%^GREEN%^fold%^RESET%^', "+
					"'%^GREEN%^call%^RESET%^'"+
					", or '%^GREEN%^raise%^RESET%^'.";
				break;
			}
			options = "'%^GREEN%^fold%^RESET%^', '%^GREEN%^check%^RESET%^'"+
				", or '%^GREEN%^bet%^RESET%^'.";
			break;
		case 2:
			options = "You can now '%^GREEN%^discard <#>%^RESET%^'. "+
				"This must "+
				"be in the form 'discard 1,2,3' etc. If you wish to keep "+
				"your current hand supply no numbers with the command.";
			break;
		case 3:
			if(current_bet) {
				options = "'%^GREEN%^fold%^RESET%^', "+
					"'%^GREEN%^call%^RESET%^'"+
					", or '%^GREEN%^raise%^RESET%^'.";
				break;
			}
			options = "'%^GREEN%^fold%^RESET%^', '%^GREEN%^check%^RESET%^'"+
				", or '%^GREEN%^bet%^RESET%^'.";
			break;
	}
	message("info","The dealer looks at you. "+options
		,players[whose_turn],({}));
}
	
int ante() {
	int flag2,i;
	if(flag) {
		write("You must wait until the current game is over.");
		return 1;
	}
	if((int)this_player()->query_money("gold") < 10) {
		write("You don't have enough gold to play.");
		return 1;
	}
	if(!players) players = ({});
	if(member_array(this_player(),players) > -1) {
		write("You have already put in your money stupid.");
		return 1;
	}
	message("info","You pound down 10 gold and join the hand.",this_player());
	message("info",(string)this_player()->query_cap_name()+" pounds done "+
		"10 gold and enters the hand.",environment(this_object()),({this_player()}));
	this_player()->add_money("gold",-10);
	pot += 10;
	hands = ([]);
	cards_dealt = ({});
	players += ({this_player()});
	i = sizeof(call_out_info());
	while(i--) {	
		if(call_out_info()[i][0] == this_object() && 
			call_out_info()[i][1] == "start_game") {
			flag2 = 1;
			break;
		}
	}
	if(!flag2) {
		call_out("start_game",20);
		message("info","%^GREEN%^%^BOLD%^The game will begin in 20 seconds.",
			this_player());
		message("info",(string)this_player()->query_cap_name()+" has started "+
			"a hand! \n%^GREEN%^%^BOLD%^The game will begin in 20 secs.",
			environment(this_object()),({this_player()}));
	}
	return 1;
}

void who_wins() {
	int i,n,x,whee,*scores;
	string h,name;
	i = sizeof(players);
	scores = allocate(sizeof(players));
	while(i--) {
		name = (string)players[i]->query_name();
		scores[i] = allocate(3);
		n = 0;
		while( hands[name][n][2..2] = hands[name][0][2..2]) {
			n++;
			if(n >= sizeof(hands[name])) break;
		}
		if(n >= sizeof(hands[name])) scores[i][2] = 1;
		n = sizeof(hands[name]);
		while(n--) {
			x = sizeof(hands[name]);
			while(x--) {
				if(hands[name][x][1..1] == hands[name][n][1..1]) {
					hands[name] -= ({ hands[name][x] });
					whee++;
				}
			}
			if(whee == 4) {
				score[i][1] = 7;
				scanff(hands[name][n][1..1],"%d",score[i][3]);
				break;
			}
			if(whee == 3) {
				
