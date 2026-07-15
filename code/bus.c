#include<stdio.h>
#include<stdbool.h>

char name[25];
char surname[25];
int year, month, day;
int code;
long long contact;
char email[40];
int choice;
bool flag=true;

void userData();
int yourChoice();

int main(){

    printf("\n---WELCOME USER---\n");
    printf("Enter your name:\n");
    scanf(" %s", name);
    printf("\nEnter your Surname:\n");
    scanf("%s", surname);
    printf("\nEnter you date of birth\n");
    printf("Year:");
    scanf(" %d", &year );
    printf("\nMonth:");
    scanf(" %d", &month);
    printf("\nDay:");
    scanf(" %d", &day);
    printf("\nEnter your Country code:");
    scanf(" %d", &code);
    printf("\nEnter you mobile number:");
    scanf(" %lld", &contact);
    printf("\nEnter you Email:");
    scanf(" %s", email);

    printf("\n\n---Thanks for Login---\n\n");
    yourChoice(choice);
    
    // printf("whats on your mind?");
    // printf("\n1. Bus Reservation ");
    // printf("\n2. Buses");
    // printf("\n3. Cities");
    // printf("\n4. Profile");
    // printf("\n5. Exit\n");

    // scanf("%d", &choice);
while(flag==true){
    choice = yourChoice(choice);
        switch(choice){
            case 1:
            printf("ticket reservetion coming soon ");
            break;
            
            case 2:
            printf("buses info coming soon");
            break;

            case 3:
            printf("cities coming soon");
            break;

            case 4:
            userData();
            break;

            case 5:
            printf("thanks for using our service");
            flag = false;
            break;

            default:
            printf("wrong input ,try again!");
            break;
        }

    }
}

void userData(){
                    printf("\n----YOUR DATA----\n");
                    printf("Name: %s %s\n", name, surname);
                    printf("Date of Birth :%d/%d/%d\n", year, month, day);
                    printf("\nContact info:\n");
                    printf("mobile number: +%d-%lld", code, contact);
                    printf("\nEmail: %s", email);
                }

int yourChoice(){
    int local_choice;
    printf("whats on your mind?");
    printf("\n1. Bus Reservation ");
    printf("\n2. Buses");
    printf("\n3. Cities");
    printf("\n4. Profile");
    printf("\n5. Exit\n");

    scanf("%d", &local_choice);

    return local_choice;
}