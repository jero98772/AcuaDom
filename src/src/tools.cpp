#include <tools.h>
#include "constants_defines.h"

 short int tools::ctoi(char x){
	return x - '0';
}
 long tools::timetototalSeconds(String time){
  int hours = ctoi(time[0])*10+ctoi(time[1]);
  int minutes = ctoi(time[3])*10+ctoi(time[4]);
  return hours*60*60+minutes*60;
}