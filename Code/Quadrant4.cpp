
#include <stdio.h>
#include <time.h>
#include "E101.h"

int 
int 

int main(){


// experimental

	int ideal_distance; // we will find this value
	int kP; // to be defined.
	int ir_reading1;
	int ir_reading2;
	int ir_reading3;
	int ideal_value = sensorIdeal1 + sensorIdeal2; // questionable method, there should be a simpler way
	
	ir_reading(0); // left sensor
	ir_reading(1); // right sensor
	
	int error = ideal_value - (ir_reading1 + ir_reading2);
	
	leftWheel = defaultSpeed - (error*kP);
	rightWheel = defaultSpeed + (error*kP);
	
	// this code should keep the AVC in the centre of the maze.
	
// next section of code should traverse the maze
	
	// sticking to the right method
	
	
	return 0;
}
