#include <stdio.h>

int main(){
    int i; //Initialize integer i as control variable
    int j; //Initialize integer j as control variable is columns
    int k; //Initialize integer k as control variable is space
    int rows=10; //Initialize rows as 10

    for(i=1;i<=rows;i++){ //First Triangle and outer loop
        for(j=1;j<=i;j++){ //Inner loop
            printf("^"); //Print asterisk
        }
        printf("\n");
    }

    printf("\n"); //space between triangles

    for(i=rows;i>=1;i--){ //Second Triangle and outer loop
        for(j=i;j>0;j--){ //Inner loop
            printf("^"); //Print asterisk
        }
        printf("\n");
    }

    printf("\n");

    for(i=1;i<=rows;i++){ //Third Triangle and outer loop
        for(k=0;k<i;k++){ //Inner loop
            printf(" "); //space to make right side long edge of triangle
        }
        for(j=i;j<=rows;j++){
            printf("^"); //Print asterisk
        }
        printf("\n");
    }

    printf("\n");

    for(i=1;i<=rows;i++){ //Fourth Triangle and outer loop
        for(k=i;k<rows;k++){ //Inner loop
            printf(" "); //space to make right side long edge of triangle
        }
        for(j=1;j<=i;j++){
            printf("^"); //Print asterisk
        }
        printf("\n");
    }
}

//END OF CODE