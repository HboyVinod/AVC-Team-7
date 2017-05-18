#include <stdio.h>
#include <time.h>
#include "E101.h"

extern "C" int take_picture();
extern "C" int save_picture(filename);
extern "C" int Sleep(int sec, int usec);

int main(){
	init(0);
	while (true){
		take_picture();
		save_picture("a.bmp");
		Sleep(0,500000);
	}
return 0; }
