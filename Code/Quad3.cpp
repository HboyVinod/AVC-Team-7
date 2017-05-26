#include <stdio.h>
#include <time.h>
#include "E101.h"

// Number of test points in column
const int testPointsCol = 240;

// Arrays to hold 0 and 1 black and white values
int col[testPointsCol];
int topRow[testPoints];

// Value that indiates junction in Q3
int junctionThreshold = 90;

// The current speed of each wheel.
int leftWheel = defaultSpeed;
int rightWheel = defaultSpeed;


// The width of the tape
int tapeWidth = 60;

/*
 * Stop the robot (set motor speeds to zero)
 */
int stop() {
	rightWheel = 0;
	leftWheel = 0;
	updateSpeeds();
	return 0;
}

/*
 * Reset the motor speeds to be moving forwards.
 */
int forward() {
	rightWheel = defaultSpeed;
	leftWheel = defaultSpeed;
	updateSpeeds();
	return 0;
}

/*
 * Set the speeds so the motor is going backwards.
 */
int backwards() {
	rightWheel = -1 * defaultSpeed;
	leftWheel = -1 * defaultSpeed;
	updateSpeeds();
	return 0;
}


/*
 * Backwards function compares the number of white pixels with the tapeWidth and if it is less than that number it will change course
 * and go backwards. Returns TRUE if it should go backwards and returns FALSE if it should continue going forward.
 */
bool goBackward() {
	int count = 0;
	for(int i = 0; i < testPoints; i++){
		if(row[i] == 1;){
			count++;
		}
	}if(count < tapeWidth){
		return true;
	}else{
		return false;
	}
}

int getCol(int column) {
	int threshold = 100;
	take_picture();
	//display_picture(3,0);
	for(int i = 0; i < testPointsCol; i++) {
		char brightness = get_pixel((int)((240/testPointsCol) * i),column , 3);
		if(brightness <= threshold) {
			// black
			col[i] = 0;
		} else {
			// white
			col[i] = 1;
		}
	}
	return 0;
}


bool leftTape(){
	int count = 0;
	getCol(20);
	for(int i=0; i<testPointsCol; i++){
		if(col[i] == 1){
			count++;
		}
	}
	if(tapeWidth < count){
		return true;
	}else{
		return false;
	}
	
bool rightTape(){
	int count = 0;
	getCol(220);
	for(int i=0; i<testPointsCol; i++){
		if(col[i] == 1){
			count++;
		}
	}
	if(tapeWidth < count){
		return true;
	}else{
		return false;
	}
}
	
bool topTape(){
	int count = 0;
	getRow(20);
	for(int i=0; i<testPointsCol; i++){
		if(col[i] == 1){
			count++;
		}
	}
	if(tapeWidth < count){
		return true;
	}else{
		return false;
	}
}

bool atJunction(){
	getRow(120);
	int whiteCount = 0;
	for(int i = 0; i<testPoints; i++){
		if(row[i] == 1){count++;}
	}
	double proportionWhite = whiteCount/testPoints;
	
}

int control (){ //can be iterated
	
	if (topTape()){
		//go forwards
		//do normal  
	} else if (leftTape()){
		//go left
	} else if (rightTape()){
		//go right
	} else {
		//go backwards
	}
	

return 0;}

