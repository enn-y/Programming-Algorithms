#include <stdio.h>

int main(){
    float i=4.5; //Initialise float i as 4.5

    printf("number\t\tsquare\t\tcube\n");

    for(i=4.5;i<=18.0;i+=4.5){ //For loop of 4.5 from 4.5 to 18 because 22.5 is greater than 10000
        printf("%.6f\t%.6f\t%.6f\n", i, i*i, i*i*i);
    }
}

//END OF CODE