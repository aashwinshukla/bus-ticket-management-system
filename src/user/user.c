#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../../global/global.h"
#include "user.h"

/* Print the stored user profile */
void userData(void) {
    printf("\n----YOUR DATA----\n");
    printf("Name: %s %s\n", name, surname);
    printf("Date of Birth: %d/%d/%d\n", year, month, day);
    printf("\nContact info:\n");
    printf("Mobile number: +%d-%lld\n", code, contact);
    printf("Email: %s\n", email);
}

/* Collect and return one set of booking details.
   Bug fix: every scanf("%d") now has a leading space so the
   leftover newline from the previous input is consumed first,
   preventing the city-validation while-loop from spinning. */
booking getBookingDetails(void) {
    booking currentBooking;

    flag_2 = true;
    flag_3 = true;

    printf("\n--- ENTER RESERVATION DETAILS ---\n");
    printf("Enter the date of the month of the departure:\n");

    while (flag_2 == true) {
        scanf(" %d", &currentBooking.date);   /* leading space eats stray \n */
        if (currentBooking.date > 0 && currentBooking.date <= 31) {
            flag_2 = false;
        } else {
            printf("Wrong date! Please enter a value between 1 and 31: ");
        }
    }

    printf("\nEnter the city you are travelling FROM (exact spelling):\n");
    printf("  1. Mumbai      2. Pune        3. Ahmedabad\n");
    printf("  4. Goa         5. Delhi       6. Jaipur\n");
    printf("  7. Chandigarh  8. Bengaluru   9. Hyderabad\n");
    printf(" 10. Chennai    11. Kolkata\n");

    while (flag_3 == true) {
        scanf(" %14s", currentBooking.city_city);
        if (strcmp(currentBooking.city_city, "Mumbai")    == 0 ||
            strcmp(currentBooking.city_city, "Pune")      == 0 ||
            strcmp(currentBooking.city_city, "Ahmedabad") == 0 ||
            strcmp(currentBooking.city_city, "Goa")       == 0 ||
            strcmp(currentBooking.city_city, "Delhi")     == 0 ||
            strcmp(currentBooking.city_city, "Jaipur")    == 0 ||
            strcmp(currentBooking.city_city, "Chandigarh")== 0 ||
            strcmp(currentBooking.city_city, "Bengaluru") == 0 ||
            strcmp(currentBooking.city_city, "Hyderabad") == 0 ||
            strcmp(currentBooking.city_city, "Chennai")   == 0 ||
            strcmp(currentBooking.city_city, "Kolkata")   == 0) {
            flag_3 = false;
        } else {
            printf("City not available. Please type the exact name from the list above: ");
        }
    }

    flag_3 = true;

    while (flag_3 == true) {
        printf("\nEnter your budget (500-10000) or type 'any': ");
        scanf(" %5s", currentBooking.budget);

        int numeric_budget = atoi(currentBooking.budget);

        if (strcmp(currentBooking.budget, "any") == 0) {
            flag_3 = false;
        } else if (numeric_budget >= 500 && numeric_budget <= 10000) {
            flag_3 = false;
        } else {
            printf("No service for this budget. Please try a value between 500 and 10000.");
        }
    }

    printf("\nEnter preferred travel window (AM or PM): ");
    scanf(" %2s", currentBooking.am_pm);

    return currentBooking;
}
