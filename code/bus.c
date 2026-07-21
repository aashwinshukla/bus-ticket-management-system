#include <stdio.h>

/* Pull in global variable storage (defined here, extern everywhere else) */
#define GLOBAL_IMPL
#include "../global/global.h"

/* Modules */
#include "../src/user/user.h"
#include "../src/menu/menu.h"
#include "../src/travel/travel.h"
#include "../src/transaction/transaction.h"

/* Each .c module is compiled as part of this translation unit so the
   project builds with a single gcc command (no Makefile needed). */
#include "../src/user/user.c"
#include "../src/menu/menu.c"
#include "../src/travel/travel.c"
#include "../src/transaction/transaction.c"

/* ------------------------------------------------------------------ */
int main(void) {

    /* --- Collect user info --- */
    printf("\n---WELCOME USER---\n");
    printf("Enter your name: ");
    scanf(" %24s", name);
    printf("Enter your surname: ");
    scanf(" %24s", surname);

    printf("Enter your date of birth\n");
    printf("  Year:  "); scanf(" %d", &year);
    printf("  Month: "); scanf(" %d", &month);
    printf("  Day:   "); scanf(" %d", &day);

    printf("Enter your country code: ");  scanf(" %d",  &code);
    printf("Enter your mobile number: "); scanf(" %lld", &contact);
    printf("Enter your email: ");         scanf(" %39s", email);

    printf("\n\n--- Thanks for signing in, %s! ---\n\n", name);

    /* --- Main loop --- */
    flag = true;
    while (flag == true) {

        choice = yourChoice();

        switch (choice) {

            case 1:
                flag_1 = true;
                while (flag_1 == true) {

                    option = busReservation();

                    switch (option) {

                        case 1: {
                            booking my_trip = getBookingDetails();
                            longTravel(my_trip);
                            break;
                        }

                        case 2: {
                            booking my_trip = getBookingDetails();
                            localTravel(my_trip);
                            break;
                        }

                        case 3:
                            flag_1 = false;
                            break;

                        default:
                            printf("\nInvalid input, try again!\n");
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
                printf("\nThanks for using our service. Goodbye!\n");
                flag = false;
                break;

            default:
                printf("\nInvalid input, try again!\n");
                break;
        }
    }

    return 0;
}
