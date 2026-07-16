#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int date;
    char city_city[15];
    char budget[6];
    char am_pm[3];
}booking;

char name[25];
char surname[25];
int year, month, day;
int code;
int pin;
long long contact;
char email[40];
int choice;
int option;
int bus_choice;
char transaction[15];
bool flag=true;
bool flag_1=true;
bool flag_2=true;
bool flag_3=true;
bool flag_4=true;



void userData();
int yourChoice();
void cities();
void buses();
int busReservation();
void transaction_1();
void transaction_2();
void transaction_3();
void transaction_4();


booking getBookingDetails();
void longTravel(booking details);  
void localTravel(booking details);

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
    
    

while(flag==true){

    choice = yourChoice();

        switch(choice){

            case 1:
            flag_1=true;

            while(flag_1==true){

                option=busReservation();

                    switch(option){

                        case 1:{
                        booking my_trip = getBookingDetails();
                        longTravel(my_trip);
                        break;
                        }

                        case 2:{
                        booking my_trip=getBookingDetails();
                        localTravel(my_trip);
                        break;
                        }

                        case 3:
                        flag_1=false;
                        break;
                
                        default:
                        printf("\nwrong input!, try again");
                        break;
                    }
            }   
            break;
            
            case 2:
            buses();
            break;

            case 3:
            cities();
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


    return 0;
}


booking getBookingDetails(){
    booking currentBooking;

    flag_2=true;
    flag_3=true;


    printf("\n--- ENTER RESERVATION DETAILS ---\n");
    printf("Enter the date of the month of the departure :\n");
    scanf("%d", &currentBooking.date);

    while(flag_2==true){
        if(currentBooking.date <=31 && currentBooking.date >0){
            flag_2=false;
            break;
        }else{
            printf("\nwrong date!, try again");
        }
    }

    printf("\nEnter the city name you are travelling from (PLease write the exact name with capitals as listed .):\n");
    printf("1. Mumbai\n ");
    printf("2. Pune\n");
    printf("3. Ahmedabad\n");
    printf("4. Goa\n");
    printf("5. Delhi\n");
    printf("6. Jaipur\n");
    printf("7. Chandigarh\n");
    printf("8. Bengaluru\n");
    printf("9. Hyderabad\n");
    printf("10. Chennai\n");
    printf("11. Kolkata\n");
    scanf(" %s", currentBooking.city_city);

    while(flag_3==true){
        if(strcmp(currentBooking.city_city, "Mumbai")==0||
            strcmp(currentBooking.city_city, "Pune")==0||
            strcmp(currentBooking.city_city, "Ahmedabad")==0||
            strcmp(currentBooking.city_city, "Goa")==0||
            strcmp(currentBooking.city_city, "Delhi")==0||
            strcmp(currentBooking.city_city, "Jaipur")==0||
            strcmp(currentBooking.city_city, "Chandigarh")==0||
            strcmp(currentBooking.city_city, "Bengaluru")==0||
            strcmp(currentBooking.city_city, "Hyderabad")==0||
            strcmp(currentBooking.city_city, "Chennai")==0||
            strcmp(currentBooking.city_city, "Kolkata")==0){
                flag_3=false;
                break;
            }else{
                printf("\nTHIS CITY IS NOT AVALAIBALE IN OUR SERVICES, SORRY FOR INCONVINENCE PLEASE TRY ANOTHER CITY\n");
            }
    }

    flag_3=true;

    while(flag_3==true){
        printf("\nPlease enter your budget (500 - 10000) or type 'any': ");
        scanf("%s", currentBooking.budget);

        int numeric_budget=atoi(currentBooking.budget);

        if(strcmp(currentBooking.budget, "any")==0){
            flag_3=false;
            break;
        }else if(numeric_budget >= 500 && numeric_budget <= 10000){
            flag_3=false;
        }else{
            printf("\nno service for this budget try something else");
        }
    }

    return currentBooking;
}

void longTravel(booking details){

    printf("\n--- Processing Long Travel Booking ---\n");
    printf("on %d of the month from %s \nbudget of %s ", details.date, details.city_city, details.budget);

    int budget_val = atoi(details.budget);
    bool is_any = (strcmp(details.budget, "any") == 0);


if(details.date < 16 && details.date > 0) {
        if(!is_any && budget_val <= 1500) {
            printf("Sorry, no bus for long distance travel in this budget.\n");
        } else if(is_any || (budget_val > 1500 && budget_val <= 5000)) {
            printf("\n========== AVAILABLE STANDARD LONG-TRAVEL BUSES ==========\n");
            printf("-> [MH-14-LX-8890] Deccan Queen Transports (Luxury Seater) - Fare: 1800\n");
            printf("-> [CH-02-EX-9011] Northern Shuttle (AC Express)          - Fare: 2200\n");
            printf("=========================================================\n");
            transaction_1();
        } else {
            printf("\n========== AVAILABLE LUXURY SLEEPER BUSES ==========\n");
            printf("-> [MH-12-AS-4521] Bharat Express (AC Sleeper)            - Fare: 5500\n");
            printf("-> [DL-01-NE-1092] Capital Flyer (Premium Sleeper)        - Fare: 6200\n");
            printf("-> [KA-03-SV-2287] Silicon Valley Voyager (Multi-Axle AC)  - Fare: 7000\n");
            printf("====================================================\n");
            transaction_2();
        }
    } else {
        if(!is_any && budget_val <= 1500) {
            printf("Sorry, no bus for long distance travel in this budget.\n");
        } else {
            printf("\n========== AVAILABLE OFF-PEAK LONG-TRAVEL BUSES ==========\n");
            printf("-> [RJ-14-HT-5543] Pink City Travels (Non-AC Seater)       - Fare: 1600\n");
            printf("-> [GJ-01-EE-3214] Western Fleet (Electric Express)        - Fare: 2400\n");
            printf("-> [WB-02-CC-1254] Eastern Star Liners (Luxury Seater)     - Fare: 3000\n");
            printf("-> [TS-09-CB-6641] Cyberabad Cruiser (AC Sleeper)          - Fare: 4500\n");
            printf("==========================================================\n");
            transaction_3();
        }
    }
}

void localTravel(booking details){
    printf("\n--- Processing Local Travel Booking ---\n");
    printf("on %d of the month from %s \nbudget of %s ", details.date, details.city_city, details.budget);

    int budget_val = atoi(details.budget);
    bool is_any = (strcmp(details.budget, "any") == 0);

        if(is_any || (budget_val >= 500 && budget_val <= 1500)) {
            printf("\n========== AVAILABLE LOCAL SHUTTLE BUSES ==========\n");
            printf("-> [GA-03-TR-7765] Coastal Cruise Liners (Multi-Axle AC)  - Fare: 950\n");
            printf("-> [TN-01-AC-4432] Coromandel Connect (Electric Express)  - Fare: 1200\n");
            printf("===================================================\n");
            transaction_4();
        } else {
            printf("\n[INFO] Your budget is higher than standard local fares.\n");
            printf("We recommend our premium localized shuttle:\n");
            printf("-> [TN-01-AC-4432] Coromandel Connect (Electric Express)  - Fare: 1200  (cash only)\n");
            printf("(The remaining change will be refunded at the boarding counter.)\n");
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

void cities(){
printf("\n========= AVAILABLE CITIES & ROUTES =========\n");
printf("1. Mumbai         [West Hub - Commercial Capital]\n");
printf("2. Pune           [West Hub - IT & Education]\n");
printf("3. Ahmedabad      [West Hub - Manufacturing]\n");
printf("4. Goa            [West Hub - Coastal Tourism]\n");
printf("--------------------------------------------------\n");
printf("5. Delhi          [North Hub - National Capital]\n");
printf("6. Jaipur         [North Hub - Heritage Tourism]\n");
printf("7. Chandigarh     [North Hub - Planned City]\n");
printf("--------------------------------------------------\n");
printf("8. Bengaluru      [South Hub - Silicon Valley]\n");
printf("9. Hyderabad      [South Hub - Cyberabad Hub]\n");
printf("10. Chennai       [South Hub - Automobile Capital]\n");
printf("--------------------------------------------------\n");
printf("11. Kolkata       [East Hub - Cultural Capital]\n");
printf("==================================================\n");
printf("Note: Inter-city buses run every 30 minutes.\n");
}

void buses(){
printf("\n========= AVAILABLE BUSES & IDENTIFICATION =========\n");
printf("1.  [MH-12-AS-4521]  Bharat Express (AC Sleeper)\n");
printf("2.  [MH-14-LX-8890]  Deccan Queen Transports (Luxury Seater)\n");
printf("3.  [GJ-01-EE-3214]  Western Fleet (Electric Express)\n");
printf("4.  [GA-03-TR-7765]  Coastal Cruise Liners (Multi-Axle AC)\n");
printf("-----------------------------------------------------------\n");
printf("5.  [DL-01-NE-1092]  Capital Flyer (Premium Sleeper)\n");
printf("6.  [RJ-14-HT-5543]  Pink City Travels (Non-AC Seater)\n");
printf("7.  [CH-02-EX-9011]  Northern Shuttle (AC Express)\n");
printf("-----------------------------------------------------------\n");
printf("8.  [KA-03-SV-2287]  Silicon Valley Voyager (Multi-Axle AC)\n");
printf("9.  [TS-09-CB-6641]  Cyberabad Cruiser (AC Sleeper)\n");
printf("10. [TN-01-AC-4432]  Coromandel Connect (Electric Express)\n");
printf("-----------------------------------------------------------\n");
printf("11. [WB-02-CC-1254]  Eastern Star Liners (Luxury Seater)\n");
printf("===========================================================\n");
}

int busReservation(){
int local_option;
printf("\n=========Welcome to reservation page=========\n");
printf("select the type of your travel:\n");
printf("1. long travel (more than 10hr travel)\n");
printf("2. local travel\n");
printf("3. Back\n");
printf("\nEnter your choice number:\n");
scanf("%d", &local_option);

return local_option;

}

void transaction_1(){
    
    while(flag_4=true){
        printf("\n Enter your Bus choice number :");
        scanf("%d", &bus_choice);
            switch(bus_choice){

                case 1:
                printf("\nYOUR CHOICE: [MH-14-LX-8890] Deccan Queen Transports (Luxury Seater) - Fare: 1800\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 1800");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                case 2:
                printf("\nYOUR CHOICE: [CH-02-EX-9011] Northern Shuttle (AC Express)          - Fare: 2200\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 2200");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                default:
                printf("input invalid , try again");

            }
    }
    
}

void transaction_2(){
    while(flag_4=true){
        printf("\n Enter your Bus choice number :");
        scanf("%d", &bus_choice);
            switch(bus_choice){

                case 1:
                printf("\nYOUR CHOICE: [MH-12-AS-4521] Bharat Express (AC Sleeper)            - Fare: 5500\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 5500");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                case 2:
                printf("\nYOUR CHOICE: [DL-01-NE-1092] Capital Flyer (Premium Sleeper)        - Fare: 6200\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 6200");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                case 3:
                printf("\nYOUR CHOICE: [KA-03-SV-2287] Silicon Valley Voyager (Multi-Axle AC)  - Fare: 7000");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 7000");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("\nentered pin in incorrect try again");
                    }
                break;

                default:
                printf("\nwrong input try again");

            }
    }
    
}

void transaction_3(){
    while(flag_4=true){
        printf("\n Enter your Bus choice number :");
        scanf("%d", &bus_choice);
            switch(bus_choice){

                case 1:
                printf("\nYOUR CHOICE:[RJ-14-HT-5543] Pink City Travels (Non-AC Seater)       - Fare: 1600\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 1600");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                case 2:
                printf("\nYOUR CHOICE: [GJ-01-EE-3214] Western Fleet (Electric Express)        - Fare: 2400\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 2400");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                case 3:
                printf("\nYOUR CHOICE: [WB-02-CC-1254] Eastern Star Liners (Luxury Seater)     - Fare: 3000");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 3000");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("\nentered pin in incorrect try again");
                    }
                break;

                case 4:
                printf("\nYOUR CHOICE: [TS-09-CB-6641] Cyberabad Cruiser (AC Sleeper)          - Fare: 4500");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 4500");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("\nentered pin in incorrect try again");
                    }
                break;

                default:
                printf("\nwrong input try again");

            }
    }
}

void transaction_4(){
    while(flag_4=true){
        printf("\n Enter your Bus choice number :");
        scanf("%d", &bus_choice);
            switch(bus_choice){

                case 1:
                printf("\nYOUR CHOICE: [GA-03-TR-7765] Coastal Cruise Liners (Multi-Axle AC)  - Fare: 950\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 950");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                case 2:
                printf("\nYOUR CHOICE:[TN-01-AC-4432] Coromandel Connect (Electric Express)  - Fare: 1200\n");
                printf("Enter your card number :");
                scanf(" %s", &transaction);
                printf("\nYour amount to be paid : 1200");
                printf("\n Enter your 4 digit pin:");
                scanf("%d", &pin);
                    if(pin<=9999 && pin>999){
                        printf("\npayment completed ");
                        printf("\ntransaction number : 12546728916739268");
                        printf("\nticket number #26");
                        flag_4=false;
                        break;
                    }else{
                        printf("entered pin in incorrect try again");
                    }
                break;

                default:
                printf("input invalid , try again");

            }
    }
}

