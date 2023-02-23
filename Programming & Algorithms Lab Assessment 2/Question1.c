void ascending(int a[]); 
void descending(int a[]); 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(void) {

    int a[SIZE] = {0};
    srand(time(NULL));
   for (size_t i = 0; i<SIZE; ++i){
    a[i] = 1+rand() %SIZE;
   }

   puts("Data items in original order");

   for (size_t i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   }

       char g;
       printf("\n Enter A for Ascending and D for Descending: ");
       scanf("%c",&g);

   switch(g)
   {
   case 'A':
   case 'a':
       {
// Ascending
   
    ascending(a); //ascending function is called here

   puts("\nData items in ascending order");
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   }
   puts("");
   break;
   }
   case 'D':
    case 'd':
    {
   // Descending
   
    descending(a); //descending function is called here
   
   puts("\nData items in descending order");
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   }
   puts("");
   break;}
   }
   return 0;
}

void ascending(int a[]){
    int i;
    for (int pass = 1; pass < SIZE; ++pass) {
      for (size_t i = 0; i < SIZE - 1; ++i) {
         if (a[i] > a[i + 1]) {
            int hold = a[i];
            a[i] = a[i + 1];
            a[i + 1] = hold;
         }
      }
   }
}

void descending(int a[]){
    int i;

    for (int pass = 1; pass < SIZE; ++pass) {
      for (size_t i = 0; i < SIZE - 1; ++i) {
         if (a[i] < a[i + 1]) {
            int hold = a[i];
            a[i] = a[i + 1];
            a[i + 1] = hold;
         }
      }
   }
}