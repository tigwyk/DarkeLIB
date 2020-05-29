/*  /wizards/misery/pt/ansi_convert.c
 *  Made for DarkeMUD
 *  Created by Geldron 030296
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

string ansi_convert(string str) {
    if(str == "reset") return "%^RESET%^";
    if(str == "red") return "%^RED%^";
    if(str == "green") return "%^GREEN%^";
    if(str == "yellow") return "%^ORANGE%^";
    if(str == "blue") return "%^BLUE%^";
    if(str == "cyan") return "%^CYAN%^";
    if(str == "magenta") return "%^MAGENTA%^";
    if(str == "black") return "%^BLACK%^";
    if(str == "hired") return "%^BOLD%^%^RED%^";
    if(str == "higreen") return "%^BOLD%^%^GREEN%^";
    if(str == "hiblue") return "%^BOLD%^%^BLUE%^";
    if(str == "hiyellow") return "%^BOLD%^%^ORANGE%^";
    if(str == "hicyan") return "%^BOLD%^%^CYAN%^";
    if(str == "hiblack") return "%^BOLD%^%^BLACK%^";
    return "";
}
