#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>
#define SIZE 100

int FullNameA(char *name); //Function prototype
int FullNameB(char *name); //Function prototype
int FullNameC(char *name); //Function prototype
int FullNameD(char *name); //Function prototype
int StudentID(char *ID); //Function prototype
int TelephoneNumber(char *telno); //Function prototype

int main(){

    char name[SIZE] = {'\0'};
    char studentid[SIZE] = {'\0'};
    char telephoneno[SIZE]= {'\0'};

    printf("\nEnter your Full Name: ");
    fgets(name, SIZE, stdin); //using fgets

    printf("\nEnter your Student ID: ");
    fgets(studentid, SIZE, stdin); //using fgets
    
    printf("\nEnter your Telephone Number: ");
    fgets(telephoneno, SIZE, stdin); //using fgets
    
    FullNameA(name); //Function call
    printf("\n\n");

    FullNameB(name); //Function call
    printf("\n\n");

    FullNameC(name); //Function call
    printf("\n\n");

    FullNameD(name); //Function call
    printf("\n\n");

    StudentID(studentid); //Function call
    printf("\n\n");

    TelephoneNumber(telephoneno); //Function call
    printf("\n\n");
}

int FullNameA(char *name){

    int i=0; //initialize i
    int j=0; //initialize j

    printf("\nFull Name in uppercase: ");
    while(name[i] != '\0'){ //While name at i is not equal to terminating null character
        printf("%c", toupper(name[i]));
        i++;
    }

    printf("\nFull Name in lowercase: ");
    while(name[j] != '\0'){ //While name at i is not equal to terminating null character
        printf("%c", tolower(name[j]));
        j++;
    }
}

int FullNameB(char *name){
    int i=0, count=0; //initialize i and count
    
    while(name[i] != '\0'){ //While name at i is not equal to terminating null character
        if(name[i] == name[0] || name[i] == name[1]){
            count++; //increment count
        }
    }

    printf("\nThe occurrence of first two letters in the string(Full Name) is %d", count);
}

int FullNameC(char *name){
    int  i=0; //initialize i

    while(name[i] != '\0'){ //While name at i is not equal to terminating null character
        i++;
    }
    
    printf("The length of the Full Name is %d", i);
}

int FullNameD(char *name){
    int i=0; //initialize i
    char lastletter = name[strlen(name) - 1]; 

    while(name[i] != '\0'){ //While name at i is not equal to terminating null character
        if(lastletter = name[i]){
            name[0] = lastletter;
            i++;
        }
    }

    printf("Name: %s", name);
}


int StudentID(char *ID){

    int number;

    sscanf(ID, "%d", &number);

    printf("The value of ID is %d", number);
}

int TelephoneNumber(char *telno){

    int i,j,k; //initialize i, j, k
    int countrycode[SIZE];
    int citycode[SIZE];
    int telephonenumber[SIZE];

    printf("\nCountry Code: ");
    for(i=1;i<5;i++){
        telno[i] == countrycode[i];
        printf("%d", countrycode[i]);

    }
    
    printf("\nCity Code: ");
    for(j=6;j<8;i++){
        telno[j] == citycode[j];
        printf("%d", citycode[j]);
    }

    printf("\nTelephone Number: ");
    for(k=9;k<15;k++){
        telno[k] == telephonenumber[k];
        printf("%d", telephonenumber[k]);
    }
}
