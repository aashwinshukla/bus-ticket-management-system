#include<stdio.h>
#include<stdbool.h>

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
long long contact;
char email[40];
int choice;
int option;
bool flag=true;
bool flag_1=true;
bool flag_2=true;
bool flag_3=true;



void userData();
int yourChoice();
void cities();
void buses();
int busReservation();

Booking getBookingDetails();
void longTravel(Booking details);  
void localTravel(Booking details);

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
    choice = yourChoice(choice);
        switch(choice){
            case 1:
            
            while(flag_1==true){
                option=busReservation(option);
                    switch(option){
                        case 1:
                        booking my_trip=getBookingDetails();
                        longTravel(my_trip);
                        break;
                
                        case 2:
                        booking my_trip=getBookingDetails();
                        localTravel(my_trip);
                        break;
                
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

    switch(option){
        case 1:
        printf("\nlong travel coming soon");
        break;

        case 2:
        printf("\nlocal travel coming soon");
        break;

        case 3:
        yourChoice();
        break;

        default:
        printf("\nwrong input!, try again");
        break;
    }
}


booking getBookingDetails(){
    booking currentBooking;
    
    printf("\n--- ENTER RESERVATION DETAILS ---\n");
    printf("Enter the date of the month of the departure :\n");
    scanf("%d", currentBooking.date);
    while(flag_2=true){
        if(currentBooking.date <=31 || currentBooking.date >0){
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

    while(flag_3=true){
        if(currentBooking.city_city==Mumbai,
            currentBooking.city_city==Pune,
            currentBooking.city_city==Ahmedabad,
            currentBooking.city_city==Goa,
            currentBooking.city_city==Delhi,
            currentBooking.city_city==Jaipur,
            currentBooking.city_city==Chandigarh,
            currentBooking.city_city==Bengaluru,
            currentBooking.city_city==Hyderabad,
            currentBooking.city_city==Chennai,
            currentBooking.city_city==Kolkata){
                flag_3=false;
                break;
            }else{
                printf("\nTHIS CITY IS NOT AVALAIBALE IN OUR SERVICES, SORRY FOR INCONVINENCE PLEASE TRY ANOTHER CITY\n");
            }
    }

    printf("\nPlease enter your budget or type 'any' : \n");
    scanf(" %s", currentBooking.budget );

    while(flag_3=true){
        if(currentBooking.budget>500 && currentBooking.budget<10000){
            flag_3=false;
            break;
        }else if(currentBooking.budget==any){
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
    if(details.date<16 && details.date>0){
        if(details.budget>500 && details.budget=<1500){
            printf("\nsorry no bus for long distance travel:");
        }else if(details.budget>1500 && details.budget=<5000){
            printf("\nthese are the available buses ");
        }else if(details.budget>5000 && details.budget<=10000){
            printf("\nthese are the available buses :");
        }else if(details.budget==any){
            printf("\nall the buses");
        }else{
            printf("\nthese are the available buses:");
        }
    }else{
        if(details.budget>500 && details.budget=<1500){
            printf("\nsorry no bus for long distance travel:");
        }else if(details.budget>1500 && details.budget=<5000){
            printf("\nthese are the available buses ");
        }else if(details.budget>5000 && details.budget<=10000){
            printf("\nthese are the available buses :");
        }else if(details.budget==any){
            printf("\nall the buses");
        }else{
            printf("\nthese are the available buses:");
        }
    }
}

void localTravel(booking details){
    printf("\n--- Processing Local Travel Booking ---\n");
    printf("on %d of the month from %s \nbudget of %s ", details.date, details.city_city, details.budget);
    if(details.date<16 && details.date>0){
        if(details.budget>500 && details.budget=<1500 || details.budget==any){
            printf("\nthese are the available buses ");
        }else{
            printf("\nno available buses at this price range:");
        }
    }else{
        if(details.budget>500 && details.budget=<1500 || details.budget==any){
            printf("\nthese are the available buses ");
        }else{
            printf("\nno available buses at this price range:");
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
