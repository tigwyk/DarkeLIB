#include <std.h>
#inherit <gorge.h>

int monitor(){
 int borg,clock;
 string here;
 clock = time();
 here=file_name(environment(this_player()));
 if(this_player()->is_player())
write_file(LOG,this_player()->query_cap_name()+" "+here+" "+ctime(clock)
   +" "+getuid(this_player())+"obj\n");
tell_object(find_player("sinclair"),this_player()->query_cap_name()+
 " ("+getuid(this_player())+") has entered "+here);
 return 1;
}
