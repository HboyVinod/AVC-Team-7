#include <stdio.h>
#include <time.h>
#include "E101.h"
/*
 * TapeWidth function calculates the number of white pixels the tape is across and returns this value.
 */
int tapeWidth(int row[], testPoints){

	int tapeWidth = 0;
	for(int i = 0; i < testPoints; i++){
		if(row[i] == 1;){
			tapeWidth ++;
		}

	}
	return tapeWidth;
}

/*
 * Backwards function compares the number of white pixels with the tapeWidth and if it is less than that number it will change course
 * and go backwards. Returns TRUE if it should go backwards and returns FALSE if it should continue going forward.
 */
bool backward(int row[], testPoints, tapeWidth){
	int count = 0;
	for(int i = 0; i < testPoints; i++){
		if(row[i] == 1;){
			count ++;
		}
	}if(count < tapeWidth){
		return true;
	}else{
		return false;
	}
}

/*
 * tJunction function will check if the number of white pixels is above a value of white pixels to determine if its there or not.
 */
bool tJunction(int row[], testPoints){
	int count = 0;
	for(int i = 0; i < testPoints; i++){
		if(row[i] == 1;){
			count ++;
		}
	}if(count > (0.75*testPoints){
		return true;
	}else{
		return false;
	}

}
