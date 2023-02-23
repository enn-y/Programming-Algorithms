/* Name: Lua Chong En Student ID: 20417309 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct visitData{
    char *SrNo;
    char *ticketNo;
    char *Name;
    char *ID;
};

struct ticket{
    struct visitData visitor;
    struct ticket *nextPtr;
};

struct ticket* headnode; //initialising struct
int appendinfront (char *s, char *t); //Function Prototype
int addvisitor(struct ticket** FirstPtr); //Function Prototype
int searchvisitor(struct ticket** FirstPtr); //Function Prototype
int deletevisitorTN(struct ticket** FirstPtr); //Function Prototype
int deletevisitorFN(struct ticket** FirstPtr); //Function Prototype
int deletevisitorID(struct ticket** FirstPtr); //Function Prototype
int displayvisitor(); //Function Prototype
int repeatingname(char *a); //Function Prototype
int countervar(); //Function Prototype
int i=0; //counter to ensure that the limit is 40

int main(){
    int choice;

    printf("\n\nIndividual Coursework | Programming and Algorithms");
    printf("\nThis program is a booking system for a Theme Park");

    do{ //Do while loop utilised
        struct ticket* headnode=NULL; //Assigning the "headnode" to NULL
        printf("\n 1. Add a new visitor"); 
        printf("\n 2. Search visitor with Ticket Number, Name or ID");
        printf("\n 3. Delete visitor with Ticket Number");
        printf("\n 4. Delete visitor with Full Name");
        printf("\n 5. Delete visitor with ID");
        printf("\n 6. Display Total No of tickets sold");
        printf("\n 7. Exit Program");

        printf("\n Choose your option from 1-7: ");
        scanf("%d", &choice);

        switch(choice){ //Switch used to organise the 7 options
            case 1:
                addvisitor(&headnode); //Function call 
                break;     
            case 2:
                searchvisitor(&headnode); //Function call 
                break;
            case 3: 
                deletevisitorTN(&headnode); //Function call 
                break;
            case 4:
                deletevisitorFN(&headnode); //Function call 
                break;
            case 5:
                deletevisitorID(&headnode); //Function call 
                break;
            case 6:
                displayvisitor(); //Function call 
                break;
            case 7:
                printf("\n\nProgram exited.");
                exit(0);
                break;
            default:
                printf("\nInvalid input. Enter a number between 1-7");
        }
    } while(choice != 7); //While loop conditions
}

int addvisitor(struct ticket** FirstPtr){ //ADDING VISITOR INPUT
    char SrNo[20], Name[30], ID[20],TicketNo[30]; //Arrays to store user input
    int typeofvisitor, temp, j, serialnum, ticketnumber, vn;
    char ticketname[30], ticket1[30], ticket2[30]={0}; //ticket number initialised arrays
    char* ptrticketnumber=ticket2;
    char visitornumber[20]; //Visitor number 

    FILE *fl = NULL; //Initializing File operation
    i++;

    if(i > 40){ //If statement used to ensure that the maximum is 40 visitors 
        printf("\n\n\nYou have reached the maximum of 40 visitors."); 
        main();
    }

    printf("\n\nEnter information of the visitor"); //Following inputs are stored in the arrays

    vn = countervar(); //Visitor Number using countervar function, so when program is restarted, it adds visitor from previous closing point
    sprintf(visitornumber, "%d", vn);
    printf("\nVisitor %s", visitornumber);

    serialnum = countervar(); //Serial Number using countervar function, so when program is restarted, it adds visitor from previous closing point
    sprintf(SrNo, "%02d", serialnum); //Assign the serialnum to SrNo
    printf("\nSerial Number: %s", SrNo);
    
    printf("\nEnter Name: "); //Name input
    scanf("%d", &temp);
    scanf("%30[^\n]s", Name);

    for(int j=0;j<=sizeof(Name);j++){
        ticketname[j] = Name[j]; //copy Name to another array to ensure that the original input is not tampered with
    }

    if(sizeof(ticketname) < 6){ //if the name in copied array is less than 6, append spaces 
        for(j=0; j<(6-sizeof(ticketname)); j++){
            appendinfront(ticketname, " ");
        }
    }

    for(j=0;j<6;j++){ //For loop to get ticket number according to ascii
        ticketnumber = ticketname[j];
        sprintf(ticket1, "%d", ticketnumber); //Store the number in ticket1
        strcat(ptrticketnumber, ticket1); //concatenate the number to ptrticketnumber which is equal to a array with 0
    }
    strcat(ptrticketnumber, SrNo); //Concatenate the serial number to the ptrticketnumber

    for(j=0;j<=sizeof(Name);j++){ //If there are spaces in the name input, change the spaces to underscore
        if(Name[j] == ' '){
            Name[j] = '_';
        }
    }

    printf("\nAre you a local or international visitor?\nEnter 0 for local and 1 for international: "); //check user for local id or international id
    scanf("%d", &typeofvisitor);

    if(typeofvisitor == 0){ //If 0 then is local visitor
        printf("\n\n--Local Visitor--");

        printf("\nEnter ID: ");
        scanf("%s", ID); //ID user input

        appendinfront(ID, "IC"); //Appending "IC" to the front of the ID input
    }
    else if (typeofvisitor == 1){ //Else if 1 then is international visitor
        printf("\n\n--International Visitor--");

        printf("\nEnter ID: ");
        scanf("%s", ID); //ID user input

        appendinfront(ID, "PASS"); //Appending "PASS" to the front of the ID input
    }
    else{ 
        printf("Invalid input.");
        exit(0);
    }

    printf("\nVisitor Information entered: %s %s %s %s", SrNo, ptrticketnumber, Name, ID); //Display the entered information that is also going to be stored in ticket.txt

    printf("\n\nThe information of %s is recorded", Name);

    if((fl = fopen("output.txt", "a+")) == NULL){ //Open for reading and appending
        printf("File could not be opened.");
    }
    else{
        fprintf(fl, "The information of %s is recorded\n", Name); //Command stored in output.txt
    }

    fclose(fl); //Close file

    //INITIALIZING LINKED LIST AND STORING USER DATA INTO FOLLOWING LINKED LIST

    struct ticket* Ptr=malloc(sizeof(struct ticket)); //creating memory to store the data, using malloc

    Ptr->nextPtr = NULL;
    Ptr->visitor.SrNo = SrNo; //Assign the struct data SrNo to SrNo array that stores user input
    Ptr->visitor.Name = Name; //Assign the struct data Name to Name array that stores user input
    Ptr->visitor.ticketNo = ptrticketnumber; //Assign the struct data ticketNo to ptrticketnumber array that stores user input
    Ptr->visitor.ID = ID; //Assign the struct data ID to ID array that stores user input

    struct ticket* PreviousPtr = NULL; //Initializing the pointer
    struct ticket* CurrentPtr = *FirstPtr; //Initialize the current

    while(CurrentPtr != NULL){
        PreviousPtr = CurrentPtr; 
        CurrentPtr = CurrentPtr->nextPtr; //Pointing to the next node
    }
    if(PreviousPtr == NULL){
        Ptr->nextPtr = *FirstPtr;
        *FirstPtr = Ptr;
    }
    else{
        PreviousPtr->nextPtr = Ptr;
        Ptr->nextPtr = CurrentPtr;
    }

    //WRITING TO FILE

    FILE *fp = NULL; //Initializing File operation

    if((fp = fopen("ticket.txt", "a+")) == NULL){ //Open for reading and appending
        printf("\nFile could not be opened.");
    }
    else{
        struct ticket *currentPtr = *FirstPtr;
        while(currentPtr != NULL){
            fprintf(fp, "Visitor %s: %s %s %s %s\n", visitornumber, currentPtr->visitor.SrNo, currentPtr->visitor.ticketNo, currentPtr->visitor.Name, currentPtr->visitor.ID); //Printing the following string into the "ticket.txt" file with struct pointers
            currentPtr=currentPtr->nextPtr; //Pointing to the next set of data
            printf("\n\nVisitor data recorded.");
        }
    }
    fclose(fp);

    main();
    return 0;
}

int searchvisitor(struct ticket** FirstPtr){ //SEARCHING FOR VISITOR INPUT
    char sTicketNo[50], sName[50], sID[50]; //user input
    int selection, j, vn;
    FILE *fl = fopen("output.txt", "a+"); //Initializing File operation
    char visitornumber[20];

    vn = countervar(); //Visitor Number using countervar function, so when program is restarted, it adds visitor from previous closing point
    sprintf(visitornumber, "%d", vn);

    struct ticket* PreviousPtr = NULL; //Initializing the pointer
    struct ticket* CurrentPtr = *FirstPtr; //Initialize the current

    printf("\n\nSearch Visitor by:");
    printf("\n1. Ticket Number"); //Search with Ticket Number
    printf("\n2. Full Name"); //Search with Full Name
    printf("\n3. ID"); //Search with ID

    printf("\n\nChoose from 1-3: ");
    scanf("%d", &selection);

    do{ //do while loop utilised here
        switch(selection){
            case 1:
                printf("Enter Ticket Number: "); //User input for Ticket Number
                scanf("%s", sTicketNo);

                while(CurrentPtr != NULL){ //Traversing through linked list
                    if(strcmp(CurrentPtr->visitor.ticketNo, sTicketNo) == 0){ //if equal
                        printf("\n\nThe following record of the visitor is found:\n"); //print
                        printf("Visitor %s: %s %s %s %s\n", visitornumber, CurrentPtr->visitor.SrNo, CurrentPtr->visitor.ticketNo, CurrentPtr->visitor.Name, CurrentPtr->visitor.ID); //print out searced visitor data

                        fprintf(fl, "The following record of the visitor is found:\n"); //print to output file
                        fprintf(fl, "Visitor %s: %s %s %s %s\n", visitornumber, CurrentPtr->visitor.SrNo, CurrentPtr->visitor.ticketNo, CurrentPtr->visitor.Name, CurrentPtr->visitor.ID); //print to output file
                        CurrentPtr=CurrentPtr->nextPtr; //Pointing to the next set of data
                    }
                }
                break;
            case 2:
                printf("Enter Full Name: "); //User input for Ticket Number
                scanf("%s", sName);

                for(j=0;j<=sizeof(sName);j++){ //Convert user input name into lower case 
                    sName[j] = tolower(sName[j]);
                }

                for(j=0;j<=sizeof(sName);j++){ //Making sure the spaces is converted to underscore
                    if(sName[j] == ' '){
                        sName[j] = '_';
                    }
                }

                while(CurrentPtr != NULL){ //Traversing through linked list
                    if(strcasecmp(CurrentPtr->visitor.Name, sName) == 0){ //if equal
                        printf("\n\nThe following record of the visitor is found:\n");
                        printf("Visitor %s: %s %s %s %s\n", visitornumber, CurrentPtr->visitor.SrNo, CurrentPtr->visitor.ticketNo, CurrentPtr->visitor.Name, CurrentPtr->visitor.ID); //print out searced visitor data

                        fprintf(fl, "The following record of the visitor is found:\n"); //print to output file
                        fprintf(fl, "Visitor %s: %s %s %s %s\n", visitornumber, CurrentPtr->visitor.SrNo, CurrentPtr->visitor.ticketNo, CurrentPtr->visitor.Name, CurrentPtr->visitor.ID); //print to output file
                        CurrentPtr=CurrentPtr->nextPtr; //Pointing to the next set of data
                    }
                }
                break;
            case 3:
                printf("Enter ID: "); //User input for ID
                scanf("%s", sID);

                while(CurrentPtr != NULL){ //Traversing through linked list
                    if(strcmp(CurrentPtr->visitor.ID, sID) == 0){ //if equal
                        printf("\n\nThe following record of the visitor is found:\n");
                        printf("Visitor %s: %s %s %s %s\n", visitornumber, CurrentPtr->visitor.SrNo, CurrentPtr->visitor.ticketNo, CurrentPtr->visitor.Name, CurrentPtr->visitor.ID); //print out searced visitor data

                        fprintf(fl, "The following record of the visitor is found:\n");
                        fprintf(fl, "Visitor %s: %s %s %s %s\n", visitornumber, CurrentPtr->visitor.SrNo, CurrentPtr->visitor.ticketNo, CurrentPtr->visitor.Name, CurrentPtr->visitor.ID);
                        CurrentPtr=CurrentPtr->nextPtr; //Pointing to the next set of data
                    }
                }
                break;
            default:
                printf("\nInvalid input. Enter a number between 1-3");
        }   
    } while(selection != 3); //do while loop condition

    main();
    return 0;
}

int appendinfront(char *a, char *b){ //Function to append "in front"
    size_t lengthofstring = strlen(b);
    memmove(a + lengthofstring, a, strlen(a) + 1);
    memcpy(a, b, lengthofstring);

    return 0;
}

int deletevisitorTN(struct ticket** FirstPtr){ //DELETE VISITOR BY TICKET NUMBER
    char sTicketNo[30]; //user input
    FILE *fn = fopen("output.txt", "a+"); //Initializing File operation
    i--; //subtracting the "i" counter 

    printf("\nEnter Ticket Number: ");
    scanf("%s", sTicketNo);

    struct ticket* PreviousPtr = NULL; //Initializing the pointer
    struct ticket* CurrentPtr = *FirstPtr; //Initialize the current

    while(CurrentPtr != NULL){ //Traversing through linked list
        if(strcmp(CurrentPtr->visitor.ticketNo, sTicketNo) == 0){
            if(CurrentPtr == *FirstPtr){
                *FirstPtr = CurrentPtr->nextPtr;
                free(CurrentPtr); //free the node
                printf("\nThe visitor with ID: %s, information is deleted.\n", sTicketNo);
                fprintf(fn, "The visitor with Ticket Number: %s, information is deleted.\n", sTicketNo);
            }
            else{
                PreviousPtr->nextPtr = CurrentPtr->nextPtr;
                free(CurrentPtr); //free the node
            }
        }   
    }
    
    main();
    return 0;
}

int deletevisitorFN(struct ticket** FirstPtr){ //DELETE VISITOR BY NAME
    char sName[20]; //USER INPUT
    int temp, j; //variable to clear buffer
    i--; //subtracting the "i" counter 
    FILE *fn = fopen("output.txt", "a+"); //open for reading and appending and initializing File operation
    
    printf("\nEnter Full Name: ");
    scanf("%d", &temp); //to clear buffer to accept input
    fgets(sName, sizeof(sName), stdin);

    for(int l=0;l<=sizeof(sName);l++){ //Convert the user input to lowercase
        sName[l]=tolower(sName[l]);
    }

    for(int k=0;k<=sizeof(sName);k++){ //Conver the user input spaces into underscore
        if(sName[k] == ' '){
            sName[k] = '_';
        }
    }

    if(repeatingname(sName) > 1){ //Function call where if the name input is repeated in the "ticket.txt" file, then, 
        printf("\n\nRepeating Names Found. Continue by searching with ID.");
        deletevisitorID(&headnode);
    }

    struct ticket* PreviousPtr = NULL; //Initializing the pointer
    struct ticket* CurrentPtr = *FirstPtr; //Initialize the current

    while(CurrentPtr != NULL){ //Traversing through linked list
        for(j=0; sizeof(CurrentPtr->visitor.Name);j++){
            CurrentPtr->visitor.Name[j] = tolower(CurrentPtr->visitor.Name[j]);
        }
        if(strcmp(CurrentPtr->visitor.Name, sName) == 0){
            if(CurrentPtr == *FirstPtr){
                *FirstPtr = CurrentPtr->nextPtr;
                free(CurrentPtr); //free the node
                printf("\nThe visitor with ID: %s, information is deleted.\n", sName);
                fprintf(fn, "The visitor: %s, information is deleted.\n", sName);
            }
            else{
                PreviousPtr->nextPtr = CurrentPtr->nextPtr;
                free(CurrentPtr); //free the node
            }
        }
    }

    main();
    return 0;
}

int deletevisitorID(struct ticket** FirstPtr){ //DELETE VISITOR BY ID
    char sID[20]; //user input
    i--; //subtracting the "i" counter 
    FILE *fn = fopen("output.txt", "a+"); //open for reading and appending and initializing File operation

    printf("\nEnter ID: ");
    scanf("%s", sID);

    struct ticket* PreviousPtr = NULL; //Initializing the pointer
    struct ticket* CurrentPtr = *FirstPtr; //Initialize the current

    while(CurrentPtr != NULL){ //Traversing through linked list
        if(strcmp(CurrentPtr->visitor.ID, sID) == 0){
            if(CurrentPtr == *FirstPtr){
                *FirstPtr = CurrentPtr->nextPtr;
                free(CurrentPtr); //free the node
                printf("\nThe visitor with ID: %s, information is deleted.\n", sID);
                fprintf(fn, "The visitor with ID: %s, information is deleted.\n", sID);
            }
            else{
                PreviousPtr->nextPtr = CurrentPtr->nextPtr;
                free(CurrentPtr); //free the node
            }
        }
    }

    main();
    return 0;
}

int repeatingname(char *a){ //CHECK FOR REPEATING NAME IN "ticket.txt"
    char num[100], SrNo[100], Name[100], TicketNo[100], ID[100]; //from file
    int count, m;
    
    FILE *fp = NULL; //Initializing File operation

    if((fp = fopen("ticket.txt", "a+")) == NULL){ //open for reading and appending
        printf("\nFile could not be opened.");
    }
    else{
        while(fscanf(fp, "Visitor %s: %s %s %s %s\n", num, SrNo, TicketNo, Name, ID) == 5){
            for(m=0;m<=sizeof(Name);m++){
                Name[m]=tolower(Name[m]);
            }
            if(a == Name){ //If the argument passed is equal to to the name, then increase count which signals a repition
                count++;
            }
        }
    }
    fclose(fp); //close file
    return count; //return the count
}

int displayvisitor(){   
    printf("\nTotal No of tickets sold: %d", i);

    main();
    return 0;
}

int countervar(){ //Reads "ticket.txt" and returns the number of lines in the file, this will allow the program to adding from where it left off even if user ends program
    FILE *fp=NULL; 
    int count=1; //initializing the count to be 1, so when the function is first called, it will start at 1 instead of 0
    char a;

    if((fp = fopen("ticket.txt", "r")) == NULL){ //Open "ticket.txt" in reading mode
        printf("\nFile could not be opened");
    }
    else{
        for(a=getc(fp);a!=EOF;a=getc(fp)){ //using getc which gets the next character, until the condition EOF
            if(a == '\n'){ //if a which is getc(fp) is equal to a new line character 
                count++; //increment count which mean the number of entries in "ticket.txt"
            }
        }
    }
    fclose(fp);
    return count;
}