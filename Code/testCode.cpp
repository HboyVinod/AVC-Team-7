#include <stdio.h>
#include <time.h>
#include "E101.h"

// Global Variables

// the default speeds of the wheels (used and changed later).
int leftWheel = 80;
int rightWheel = 80;

int main() {
	// parameters
	// higher than this means the pixel is white, lower means it's black.
	char threshold = 50;
	// number of test points across the picture which we measure the brightness of.
	int testPoints = 160;
	// the magic value to scale the error signal by to get the speed change.
	double magicValue = 0.5
	
	
	init();
	while(true) {
		take_picture();
		// TEST!
		display_picture(5, 0);
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
			// TEST!
			printf("%d", row[i]);
		}
		int error = 0;
		int total = 0;
		for(int i = 0; i < testPoints; i++) {
			error = error + row[i] * (i-(testPoints/2));
			total = total + row[i] * abs(i-(testPoints/2))
		}
		// TEST!
		printf("\n %d", total);
		
		// If negative, turn left.
		// Value to change the wheel speeds by.
		int dSpeed = (int)(error * magicValue);
		turn(dSpeed);
		sleep1(0, 500);
	}
	return 0;}

int turn(dSpeed) {
	leftWheel = leftWheel + dSpeed;
	rightWheel = rightWheel - dSpeed;
	updateSpeeds();
	return 0;}
	
int updateSpeeds() {
	
	// Maybe check that right wheel isn't like 20 and left wheel isn't like 260 (otherwise it will just break).
	if(leftWheel > 254) {
		leftWheel = 254;
	} else if(leftWheel < -254) {
		leftWheel = -254;
	}
	
	if(rightWheel > 254) {
		rightWheel = 254;
	} else if(rightWheel < -254) {
		rightWheel = -254;
	}
	
	set_motor(1,leftWheel);
	// -1 * rightWheel may need changing depending on how the motors are wired up.
	set_motor(2, -1 * rightWheel);
	return 0;}
	
	
	
int openSesame(){
	init(1);//not sure about this lineeee
	char message[24];
	char[] server_address = "130.195.6.196";
	char[] pls = "Please";
	connect_to_server(server_address, 1024);
	send_to_server(pls);
	receive_from_server(message);
	send_to_server(message);
	
return 0;}
