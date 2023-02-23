#include <stdio.h>

int main(){ 
    int designation; //Number for the hierarchy of workers
    float daysworked; //Input for days worked for identified worker
    float overtime; //Input for overtime, only for workers whos job allows overtime
    float dailyrate; //Input for worker to help calculate
    float total=0; //Total calculation
    float hoursworked; //Input for worker on hours worked
    float hourlyrate; //Input for worker on hourly rate

    float weeksworked; //Input for worker on weeks worked
    float totalsales; //Input for worker on total sales

    float itemspacked; //Input for worker on itemspacked
    float subtotal=0; //Subtotal to help calculate total

    while(designation>0 || designation<5){
        printf("\n\nPlease enter a number based in designation: ");
        scanf("%d", &designation);

        switch(designation){
            case 1:
                printf("\nManager (1):\nSalary: Fixed Monthly Salary");
                break;
            case 2:
                printf("\nDaily Workers (2):");
                printf("\nDays worked this week: ");
                scanf("%f", &daysworked);
                while(daysworked < 0 || daysworked > 6){
                    printf("\nInvalid value, Please enter again");
                    printf("\nDays worked this week: ");
                    scanf("%f", &daysworked);
                }
                printf("\nNumber of overtime days: ");
                scanf("%f", &overtime);
                printf("\nDaily rate: ");
                scanf("%f", &dailyrate);

                total = dailyrate * daysworked + (overtime * dailyrate * 2/3);
                printf("\n\nSalary: %.2f", total);
                break;
            case 3:
                printf("\nHourly Workers (3):");
                printf("\nHours worked this week: ");
                scanf("%f", &hoursworked);
                while(hoursworked < 0 || hoursworked > 50){
                    printf("\nInvalid value, Please enter again");
                    printf("\nHours worked this week: ");
                    scanf("%f", &hoursworked);
                }
                printf("Overtime hours: ");
                scanf("%f", &overtime);
                printf("Hourly rate: ");
                scanf("%f", &hourlyrate);
                
                total = hoursworked * hourlyrate + ((overtime * hourlyrate)/2);
                printf("Salary: %.2f", total);
                break;
            case 4:
                printf("\nCommission Worker (4):");
                printf("\nWeeks worked: ");
                scanf("%f", &weeksworked);

                for(int i=1;i<=weeksworked;i++){
                    printf("\nTotal sales in week - %d: ",i);
                    scanf("%f", &totalsales);
                    subtotal += totalsales;
                }

                total = (230 * weeksworked) + (subtotal * 0.059);
                printf("\nSalary: %.2f", total);
                break;
            case 5:
                printf("\nLabour at product packing (5):");
                printf("\nWeeks worked: ");
                scanf("%f", &weeksworked);

                for(int i=1;i<=weeksworked;i++){
                    printf("\nItems packed in week - %d: ",i);
                    scanf("%f", &itemspacked);
                    subtotal += itemspacked;
                }

                total = subtotal * 0.0005;
                printf("\nSalary: %.2f", total);
                break;
        }
    }
}

//END OF CODE