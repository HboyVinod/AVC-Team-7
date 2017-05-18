#include <stdio.h>
#include <time.h>
#include "E101.h"

int abs(int num) {
	int ans = 0;
	if(num < 0) {
		ans = -1 * num;
	} else {
		ans = num;
	}
	return ans;
}

int q2() {
	int testPoints = 320;
	int threshold = 100;
	
	take_picture();
	//display_picture(3,0);
	int row[testPoints];
	for(int i = 0; i < testPoints; i++) {
		char brightness = get_pixel(120, (int)((320/testPoints) * i), 3);
		if(brightness <= threshold) {
			// black
			row[i] = 0;
		} else {
			// white
			row[i] = 1;
		}
	}
	
	int error = 0;
	int total = 0;
	for(int i = 0; i < testPoints; i++) {
		//printf("%d ", row[i]);
		error = error + row[i] * (i-(testPoints/2));
		total = total + row[i] * abs(i-(testPoints/2));
	}
	
	return 0;
}

int main() {
	bool inQ2 = true;
	// check what q you're in.

	while(inQ2) {
		q2();
	} 	
	
	return 0;
}
