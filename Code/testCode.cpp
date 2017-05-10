#include <stdio.h>
#include <time.h>
#include "E101.h"

int main() {
	// parameters
	// higher than this means the pixel is white, lower means it's black.
	char threshold = 127;
	// number of test points across the picture which we measure the brightness of.
	int testPoints = 320;
	
	
	init();
	take_picture();
	int row[testPoints];
	for(int i = 0; i < testPoints; i++) {
		char brightness = get_pixel(120, i, 3);
		if(brightness <= threshold) {
			// black
			row[i] = 0;
		} else {
			// white
			row[i] = 1;
		}
	}
	int total = 0;
	for(int i = 0; i < testPoints; i++) {
		total = total + row[i] * (i-(testPoints/2));
	}
	// If negative, turn right.
	
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
