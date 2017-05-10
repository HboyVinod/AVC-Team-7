#include "E101.h"
#include <stdio.h>
#include <time.h>

//the time it takes to move 90 degrees, will be changed with experimentation
double seconds = 1;
double millis =  5000;

double motor_speed = 200;

int turnOnSpot(String direction){
	// direction can be left, right or back
	
	if (direction != ("left" || "right" || "back")){
		//failed, invalid direction
		return 1;
		} 
	
	init(); 
	
	//starts motors in correct direction
	if (direction == "right"){
        set_motor(1, motor_speed);    
        set_motor(2, -1 * motor_speed);
	} else {
		set_motor(1, -1 * motor_speed);    
        set_motor(2, motor_speed);
	}
	
	// keeps motors on for necessary time
	if (direction == "back"){
        sleep1(seconds*2, millis*2);
	} else {
		sleep1(seconds, millis);
    }	
	
	//turns motors off
	stop(1);
    stop(2);
	
return 0;}
