/*
 *   ROLECALL - GENERATES A WWW LIST OF ALL USERS IN THE  *
 *   MUD WHO ARE NOT INVISIBLE.                           *
 *   CODED ON: 9/23/96 FOR DARKEMUD LIBRARY               *
 *   CODED BY: SHADOWRAITH                                *
 */

#include <daemons.h>

#define FILE_NAME "/www/wholist.html"

void html();             //HTML Function
int body(object *list);  //WHO Filter

object *everyone;        //List of all Users

void create() {
   seteuid( "www" );
	html();
	return;
}

void html() {
   int tot, nrbt;
	
   everyone = users();
	nrbt = (int)EVENTS_D->query_next_reboot() - time();
	
	rm(FILE_NAME);
   write_file(FILE_NAME,"<HEAD>\n");
   write_file(FILE_NAME,"<TITLE>Players in Darkemud</TITLE>\n");
   write_file(FILE_NAME,"</HEAD>\n\n");
   write_file(FILE_NAME,"<BODY BACKGROUND = \"darke/images/grey.jpg\" "+
      "LINK = \"#7000E0\" TEXT = \"#000000\" VLINK = \"#900000\" "+
      "ALINK = \"#C000FF\" >\n"); 
   write_file(FILE_NAME,"<CENTER><IMG SRC=\"darke/images/logo1.gif\">"+
      "</CENTER><H5><CENTER><FONT SIZE=+2>P</FONT>LAYERS <FONT SIZE"+
      " = +2>L</FONT>IVING AND <FONT SIZE = +2>D</FONT>YING IN "+
      "<FONT SIZE = +2>D</FONT>ARKEMUD"+
      "</CENTER><CENTER>( "+ctime(time())+ " )</H5><HR SIZE = 4>\n" );
   write_file(FILE_NAME,"</CENTER>\n<BODY>\n");
   write_file(FILE_NAME,"<UL>\n");
   tot = body(everyone);
   write_file(FILE_NAME,"</UL>\n<hr>\n");
   write_file(FILE_NAME,"<CENTER>Total of " + tot +
      " players.</CENTER><CENTER>[Next Reboot " + 
      ctime( time() + nrbt ) + "]</CENTER>\n");
   write_file(FILE_NAME,"</BODY>");
   return;
   }

int body (object *list) {
	int i, j, tot;
	
	i = sizeof(list);
	while (j < i) {
		tot += 1;
		if ( !list[j]->query_invis() && !hiddenp(list[j]) )
		write_file(FILE_NAME, "<LI>" +
		  eliminate_colour( list[j]->query_short() ) + "\n");
		j++;
	}
	return tot;
}

