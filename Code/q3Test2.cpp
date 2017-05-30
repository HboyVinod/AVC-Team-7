#include <stdio.h>
#include <time.h>
#include "E101.h"

// Global Variables

// Whether or not you're testing the code (changes whether or not the print statements are used.)
const int testing = true;

// The current quadrant.
int quadrant = 3;

// The default speed of the wheels.
const int defaultSpeed = 40;
const int maxSpeed = 150;

// The current speed of each wheel.
int leftWheel = defaultSpeed;
int rightWheel = defaultSpeed;

// The width of the tape
int tapeWidth = 60;

/*
// The number of times the robot has had to back up
int backCount = 0;
// The number of times the robot has gone forwards
int forwardCount = 0;*/

// Q2 Constants
const double pConstant = 0.0025;
const int testPoints = 320;
int row[testPoints];

// Q3 constants
const int testPointsCol = 240;
int col[testPointsCol];


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
int getRow(int targetRow) {
	int threshold = 100;

	take_picture();
	//display_picture(3,0);
	for(int i = 0; i < testPoints; i++) {
		char brightness = get_pixel(targetRow, (int)((320/testPoints) * i), 3);
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
	sleep1(0,500);
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
 * TapeWidth function calculates the number of white pixels the tape is across and returns this value.
 */
int getTapeWidth() {
	tapeWidth = 0;
	for(int i = 0; i < testPoints; i++) {
		if(row[i] == 1) {
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
		if(row[i] == 1) {
			count++;
		}
	} if(count < (0.5*tapeWidth)) {
		if (testing){printf("goBackward true");}
		return true;

	} else {
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
 * Tests if there is white tape on the right (column 300)
 */
bool rightTape(){

	int count = 0;
	getCol(300);
	for(int i=0; i<testPointsCol; i++){
		if(col[i] == 1){
			count++;
		}
	}
	//count += 15;
	if(testing){printf("%d\n", count);}
	if(count > 30){
		if (testing){printf("rightTape true\n");}
		return true;
	}else{
		if (testing){printf("rightTape false\n");}
		return false;
	}
}


/*
 * Tests if there is white tape on the top (row 20)
 */
bool topTape() {
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
 * The code for quadrant 2,
 * Creates an error signal based on how far left or right the line is (0 means the line is central),
 * turns based on this error signal.
 */
int q2() {

	getRow(120);

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

	if(goBackward()) {
		backwards();
	} else {
		turn(error);
	}

	return 0;
}

int q1() {
	char message[24];
	char server_address[] = "130.195.6.196";
	char pls[] = "Please";
	connect_to_server(server_address, 1024);
	send_to_server(pls);	receive_from_server(message);//could be buggy, test it
	send_to_server(message);
}


/*
 * Main control for quadrant 3, determines direction to turn at a junction
 * it ignores the check for right tape, as long as q2 code can handle sharp corners it should be fine?
 */
int q3 (){
	if (atJunction){
		if (topTape()){
			forward();
		} else if (leftTape()){
			leftWheel = 5;
			rightWheel = 60;
			updateSpeeds();
		} else {
			q2();
		}
	} else {
		q2();
	}
	return 0;
}


/*
 * Checks if the current quadrant is finished. Returns true if it is, and false if it isn't.
 */
bool finishedQ(int currentQ) {

	if(currentQ == 1 && currentQ == quadrant) {
		quadrant ++;
		return false;
	}
	if(currentQ == 2) {
		return false;

	}
	if(currentQ == 3) {
		return false;
	}
	return true;
}

/*
 * Calls the finishedQ function to keep track of what quadrant the pi is in.
 * Runs the functions instrumental to each quadrant, and keeps the user(?) up to date on where the robot is.
 */
int main() {
	init();
	q1();
	while(true) {
		if (quadrant == 1) {
			if(finishedQ(1)) {
				quadrant++;
				printf("Finished Quadrant One!\n");
			} else {
				q1();
			}
		}
		if(quadrant == 2) {
			if(finishedQ(2)) {
				quadrant++;
				printf("Finished Quadrant Two!\n");
			} else {
				q2();
			}
		}
		if(quadrant == 3) {
			if(finishedQ(3)){
				quadrant++;
				printf("Finished Quadrant Three!\n");
			} else {
				q3();
			}
		}
		sleep1(0,500);
		/*
		switch(quadrant) {
			case 1:
				if(finishedQ(1)) {
					quadrant++;
					printf("Finished Quadrant One!\n");
				} else {
					// do Q1 stuff
				}
				//break;

			case 2:
				if(finishedQ(2)) {
					quadrant++;
					printf("Finished Quadrant Two!\n");
				} else {
					q2();
				}
				//break;

			case 3:
				if(finishedQ(3)) {
					quadrant++;
					printf("Finished Quadrant Three!\n");
				} else {
					// do Q3 stuff
				}
				//break;

			case 4:
				if(finishedQ(4)) {
					printf("Yay! I finished!\n");
					stop(1);
					return(0);
				} else {
					// do Q4 stuff
				}
				//break;

			default: // If it has no idea which quadrant it's in, break!
				printf("OhGodHelpPlz\n");
				stop(1);
				return 0;
				//break;
		}
		*/
	}
	return 0;
}
