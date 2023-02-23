#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>
#define SIZE 200

int count(char *ptr);
int swap(char *ptr);

int main(){

    char string[SIZE];

    printf("\nEnter a string: ");
    fgets(string, SIZE, stdin);

    count(string);
    swap(string);
}

int count(char *ptr){
    int i;
    int words=0;

    for(i=0; ptr[i];i++){
        if(ptr[i] == 32){
        words++;
        }
    }

    if(i>0){
        words++;
    }

    printf("\nThe word count is %d", words);
}

int swap(char *ptr){

    char leftpart[100];
    char rightpart[100];
    int i;
    int j;
    int k;

    int lengthmid = strlen(ptr)/ 2;

    for(i=0;i<lengthmid;i++){
        leftpart[i] = ptr[i];
    }
    leftpart[i] = '\0';

    for(k=0;k<=lengthmid;k++){
        rightpart[k] = ptr[k];
    }

    printf("\nOriginal String: %s", ptr);
    printf("\nNew string: %s%s", rightpart, rightpart);
}