#include <stdio.h>
#include <time.h>
#include "E101.h"

int main() {
	// parameters
	// higher than this means the pixel is white, lower means it's black.
	char threshold = 127	;
	
	
	
	init();
	take_picture();
	display_picture(5,0);
	int row[320];
	for(int i = 0; i < 320; i++) {
		char brightness = get_pixel(120, i, 3);
		if(brightness <= threshold) {
			row[i] = 0;
		} else {
			row[i] = 1;
		}
	}
	
	/*
	int numLeft = 0;
	int numRight = 0;
	bool left = true;
	for(int i = 0; i < 320; i++) {
		if(row[i] = 1) {
			if(left) {
				numLeft++;
			} else {
				numRight++;
			}
		}
	}*/
	
	// Work out how much to turn!
	
return 0;}
