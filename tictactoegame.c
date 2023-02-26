#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
char PLAYER = 'X';
char COMPUTER = 'O';

int BoardReset();
int DisplayBoard();
int CheckForSpace();
int UserMove();
int ComputerMove();
char CheckWinner();
int PrintWinner(char);

int main(){
   char winner = ' ';
   char response = ' ';

   do
   {
      winner = ' ';
      response = ' ';
      BoardReset();

      while(winner == ' ' && CheckForSpace() != 0)
      {
         DisplayBoard();

         UserMove();
         winner = CheckWinner();
         if(winner != ' ' || CheckForSpace() == 0)
         {
            break;
         }

         ComputerMove();
         winner = CheckWinner();
         if(winner != ' ' || CheckForSpace() == 0)
         {
            break;
         }
      }

      DisplayBoard();
      PrintWinner(winner);

      printf("\nWould you like to play again? (Y/N): ");
      scanf("\n%s");
      scanf("\n%s", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("Thanks for playing!");

   return 0;
}

int BoardReset(){
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
int DisplayBoard(){
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
int CheckForSpace(){
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
int UserMove(){
   int x;
   int y;

   do
   {
      printf("Enter row #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-3): ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');
   
}
int ComputerMove(){
   srand(time(0));
   int x;
   int y;

   if(CheckForSpace() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');
      
      board[x][y] = COMPUTER;
   }
   else
   {
      PrintWinner(' ');
   }
}
char CheckWinner(){
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
int PrintWinner(char winner){
   if(winner == PLAYER)
   {
      printf("YOU WIN!");
   }
   else if(winner == COMPUTER)
   {
      printf("YOU LOSE!");
   }
   else{
      printf("IT'S A TIE!");
   }
}