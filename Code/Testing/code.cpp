#include <stdio.h>
#include <time.h>
#include "E101.h"

// Global Variables

// Whether or not you're testing the code (changes whether or not the print statements are used.)
const int testing = false;

// The current quadrant.
int quadrant = 1;

// The default speed of the wheels.
const int defaultSpeed = 40;
const int maxSpeed = 150;

// The current speed of each wheel.
int leftWheel = defaultSpeed;
int rightWheel = defaultSpeed;

// Q2 Constants
const double pConstant = 0.003;
const int testPoints = 320;
int row[testPoints];

/*
 * Return the absolute value of whatever number is passed into it.
 */
int abs(int num) {
	int ans = 0;
	if(num < 0) {
		ans = -1 * num;
	} else {
		ans = num;
	}
	return ans;
}

/*
 * Sets the wheel speeds to whatever the variables say they should be.
 * Will check that the speeds are within some max value (so the robot doesn't go too fast).
 */
int updateSpeeds() {

	if(leftWheel > maxSpeed) {
		leftWheel = maxSpeed;
	} else if(leftWheel < -1 * maxSpeed) {
		leftWheel = -1 * maxSpeed;
	}

	if(rightWheel > maxSpeed) {
		rightWheel = maxSpeed;
	} else if(rightWheel < -1 * maxSpeed) {
		rightWheel = -1 * maxSpeed;
	}

	set_motor(1, leftWheel);
	set_motor(2, rightWheel);
	return 0;
}

/*
 * Returns the row array,
 * an array of zeros and ones signifying black and while pixels, used to tell the position of the tape relative to the robot.
 */
int getRow() {
	int threshold = 100;

	take_picture();
	//display_picture(3,0);
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

	return 0;
}

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
 * Turns the robot based on the error value given.
 * scales the error so that it can be added or subtracted from the speed and turn the robot correctly.
 * if dSpeed is negative, it turns left, if dSpeed is positive it turns right.
 * Used in q2 to follow the line.
 */
int turn(int error) {
	int dSpeed = (int)(error * pConstant);
	leftWheel = defaultSpeed + dSpeed;
	rightWheel = defaultSpeed - dSpeed;
	updateSpeeds();
	return 0;
}

/*
 * The code for quadrant 2,
 * Creates an error signal based on how far left or right the line is (0 means the line is central),
 * turns based on this error signal.
 */
int q2() {

	getRow();

	int error = 0;
	int total = 0;
	for(int i = 0; i < testPoints; i++) {
		error = error + row[i] * (i-(testPoints/2));
		total = total + row[i] * abs(i-(testPoints/2));
	}

	if(testing) {
		for(int i = 0; i < (int)(testPoints/4); i++) {
			int index = 4 * i;
			printf("%d", row[index]);
		}
		printf(" - %d,%d\n", error, total);
	}

	turn(error);

	return 0;
}

bool finishedQ(int currentQ) {

	if(currentQ == 2) {
		return false;
	}

	return true;
}

/*
 * Calls the finishedQ function to keep track of what quadrant the pi is in.
 * Runs the functions instrumental to each quadrant, and keeps the user(?) up to date on where the robot is.
 */
int main() {

	while(true) {
		switch(quadrant) {
			case 1:
				if(finishedQ(1)) {
					quadrant++;
					printf("Finished Quadrant One!\n");
				} else {
					// do Q1 stuff
				}
				break;

			case 2:
				if(finishedQ(2)) {
					quadrant++;
					printf("Finished Quadrant Two!\n");
				} else {
					q2();
				}
				break;

			case 3:
				if(finishedQ(3)) {
					quadrant++;
					printf("Finished Quadrant Three!\n");
				} else {
					// do Q3 stuff
				}
				break;

			case 4:
				if(finishedQ(4)) {
					printf("Yay! I finished!\n");
					stop(1);
					return(0);
				} else {
					// do Q4 stuff
				}
				break;

			default: // If it has no idea which quadrant it's in, break!
				printf("OhGodHelpPlz\n");
				stop(1);
				return 0;
				break;
		}
	}
	return 0;
}
