#include <stdio.h>

int strRev(char array[]); //Function prototpye

int main(){
    char a[100]; //Array initialised
    int i; // Counter i initialised
    int size = sizeof(a)/sizeof(a[0]); //Size is initialised here

    printf("\nThe program started\nStart typing: \n\n");
    scanf("%[^\n]", a); 

    printf("\nThis is For Loop\n");
    for(i=0;i<size;i++){ //For loop 
        printf("%c",a[i]);
    }

    printf("\nThis is While Loop\n");
    while(i<size){ //While loop
        printf("%c",a[i]);
        i++;
    }

    return 0;
}

int strRev(char array[]){ //Function
    int i;

    printf("\nThis is a string\n");
    printf("%s", array[]);

    printf("\nThe reverse string is:\n");
    for(i=0;i<sizeof(array)/sizeof(array[0]);i--){
        printf("%c", array[i]);
    }
}



