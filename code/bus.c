#include<stdio.h>
#include<stdbool.h>

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

void userData();
int yourChoice();
void cities();
void buses();

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
    

while(flag==true){
    choice = yourChoice(choice);
        switch(choice){
            case 1:
            busReservation(option);//here is where i left
            while(flag_1==true){
                option=busReservation(option);
                    switch(option){
                        case 1:
                        printf("\nlong travel coming soon");
                        break;
                
                        case 2:
                        printf("\nlocal travel coming soon");
                        break
                
                        case 3:
                        yourChoice();
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
        break

        case 3:
        yourChoice();
        break;

        default:
        printf("\nwrong input!, try again");
        break;
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