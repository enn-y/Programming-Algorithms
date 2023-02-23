#include <stdio.h>
#define SIZE 500

int search(int a[], int key, int l, int h); //Function prototype

int main(){
    int i; //i counter is initialised
    int a[SIZE]={0}; //Array initialised
    int searchkey; //This is the searchkey for user input
    int number; //this is where input is saved
    
    for(i=0;i<SIZE;i++){
        a[i]=i*2; //For loop, There are 500 integer values and each time is a multiple of 2
    }

    printf("\n\n500 integer values multiples of 2 Array: \n\n");
    for(i=0;i<SIZE;i++){ 
        printf("% d", a[i]); //Here the array is printed
    }

    printf("\n\nEnter a searchkey: "); //User input for searchkey
    scanf("%d", &number);

    if(number % 2 !=0 && number % 6 !=0){ //Condition for multiple of 2 and 6
        printf("\nSearch key is not multiple of 6");
        printf("\nEnter the integer search key multiple of 6: ");
        scanf("%d", &number);
    }

    searchkey = search(a, number, 0, SIZE); //Function call

    if(searchkey != -1){ //Condition according to "search" function
        printf("\nFound value in element %d", searchkey);
    }
    else{
        printf("\nValue not found");
    }

    return 0;
}

int search(int a[], int key, int l, int h){
    if(h<l){ //If the high is lower than low then we return -1 
        return -1;
    }
    else if(a[l] == key){ //If number is at l then we return l
        return l;
    }
    else if(a[h] == key){ //If number is at h then we return h
        return h;
    }
    else{
        return search(a, key, l+1, h-1); //Recursion, this time we add 1 to low and minus 1 from high and it will continue until we find the key
    }
}