#include <stdio.h>
#include <time.h>
#include "E101.h"

}
int main() {
 /* turn motors 1 and 2 on */   
    init();    
    set_motor(1, 200);    
    set_motor(2, 200);    
    sleep1(0, 5000);
/* Turn motors 1 and 2 off */
    stop(1);
    stop(2);
    
return 0;}

}
