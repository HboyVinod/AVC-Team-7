#include <stdio.h>
#include <time.h>
#include "E101.h"

// Number of test points in column
const int testPointsCol = 240;

// Array to hold black and white values for column
int col[testPointsCol];

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


/*
 * Takes picture and populates the col array with 1 (white) and 0 (black) for specified column 
 */
int getCol(int column) {
	int threshold = 100;
	take_picture();
	for(int i = 0; i < testPointsCol; i++) {
		char brightness = get_pixel((int)((240/testPointsCol) * i), column , 3);
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


/*
 * Tests if there is white tape on the left (column 20)
 */
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
}
	

/*
 * Tests if there is white tape on the right (column 220)
 */	
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

	
/*
 * Tests if there is white tape on the top (row 20)
 */	
bool topTape(){
	int count = 0;
	getRow(20);
	for(int i=0; i<testPoints; i++){
		if(row[i] == 1){
			count++;
		}
	}
	if(tapeWidth < count){
		return true;
	}else{
		return false;
	}
}


/*
 * Tests if centre row is at a junction (when there is no longer black on left and right)
 */	
bool atJunction(){
	getRow(120);
	int whiteLeft = 0;
	int whiteRight = 0;
	for (int i = 0; i < 20; i++){
		if(row[i] == 1){
			whiteLeft++;
		} 	
	}
	for (int i = (testPoints - 20); i < testPoints; i++){
		if(row[i] == 1){
			whiteRight++;
		} 	
	}
	// If there is black on both sides, it is not at a junction
	// Can change the number, at the moment if less than 16 of the 20 tested on each side are white, it is considered black
	if (whiteLeft <= 16 && whiteRight <= 16){
		return false;
	}else {
		return true;
	}
	
}


/*
 * Main control for quadrant 3, determines direction to turn at a junction
 */	
int q3 (){ //can be iterated
	
	if (atJunction){
		if (topTape()){
			forward();
		} else if (leftTape()){
			// Should left wheel go forward slowly, stay still, or go a bit backwards? 
			// Test to find best values for speeds
			leftWheel = 5; 
			rightWheel = 100;
			updateSpeeds()
		} else if (rightTape()){
			leftWheel = 100;
			rightWheel = 5;
			updateSpeeds()
		} else {
			backwards();
		}
	} else {
		q2();
	}
	
return 0;}

