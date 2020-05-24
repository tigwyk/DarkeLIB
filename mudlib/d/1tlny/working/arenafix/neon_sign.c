/*  /d/damned/arena/neon_sign.c
 *  Made for DarkeMUD
 *  Created by Geldron 031096
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

#include "arena.h"

inherit OBJECT;

void create();
int get();
string long();

void create() {
    ::create();
    set_name("neon sign");
    set_id( ({ "sign", "neon sign" }) );
    set_short("a neon sign");
    set_long( (: long :) );
    set_value(0);
}

int get() {
    if(TP) message("get", "It is stuck to the booths.", TP);
    return 0;
}

string long() {
    string tmp;

    tmp = "%^BLUE%^" + repeat_string("-", 13) + "%^GREEN%^] %^BOLD%^%^CYAN%^"
    ARENA_NAME + " Commands%^RESET%^ %^GREEN%^[%^BLUE%^" + repeat_string("-", 13) +
    "%^RESET%^\n" + sprintf("%-20s %47s", syntax("challenge USER"),
      "Challenges USER to fight in the Arena");
    tmp += "\n" + sprintf("%-20s %52s", syntax("co-owners"),
      "Lists co-owners of the Arena");
    return tmp;
}

nomask int query_prevent_shadow() { return 1; }
