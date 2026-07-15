#include<stdio.h>
char name[25];
char surname[25];
int year, month, day;
int code;
long long contact;
char email[40];

void userData();


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

    // userData( year, month, day, code, contact, 
    //     name, email);


}

void userData(int year, int month, int day, int code, long long contact,
                char name[], char email[]){
                    printf("\n----YOUR DATA----\n");
                    printf("Name: %s %s\n", name, surname);
                    printf("Date of Birth :%d/%d/%d\n", year, month, day);
                    printf("\nContact info:\n");
                    printf("mobile number: +%d-%lld", code, contact);
                    printf("\nEmail: %s", email);
                }
