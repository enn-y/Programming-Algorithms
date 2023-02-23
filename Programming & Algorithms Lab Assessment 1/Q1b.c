#include <stdio.h>

int main(){
    int i=5; //initialize integer i as 5

    printf("number\tsquare\tcube\n");

    for(i=5;i<=20;i+=5){ //for loop of 5 from 5 to 20 as 25 is greater than 10000
        printf("%d\t%d\t%d\n", i, i*i, i*i*i);
    }
}

//END OF CODE