#include <stdio.h>
#include <time.h>
#include "E101.h"


// The current quadrant.
int quadrant = 3;


// The default speed of the wheels.
const int defaultSpeed = 40;
const int maxSpeed = 150;


// The current speed of each wheel.
int leftWheel = defaultSpeed;
int rightWheel = defaultSpeed;


// The width of the tape
int tapeWidth = getTapeWidth();


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
 * TapeWidth function calculates the number of white pixels the tape is across and returns this value.
 */
int getTapeWidth() {
	tapeWidth = 0;
	for(int i = 0; i < testPoints; i++){
		if(row[i] == 1;){
			tapeWidth++;
		}

	}
	return tapeWidth;
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

	}
	return 0;
}
