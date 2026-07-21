#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../../global/global.h"
#include "../user/user.h"
#include "transaction.h"

/* ------------------------------------------------------------------ */
/*  Helper: map departure city to a simple destination for the ticket  */
/* ------------------------------------------------------------------ */
static const char *getDestination(const char *departure_city) {
    if (strcmp(departure_city, "Mumbai")    == 0) return "Pune";
    if (strcmp(departure_city, "Pune")      == 0) return "Mumbai";
    if (strcmp(departure_city, "Delhi")     == 0) return "Jaipur";
    if (strcmp(departure_city, "Jaipur")    == 0) return "Delhi";
    if (strcmp(departure_city, "Bengaluru") == 0) return "Chennai";
    if (strcmp(departure_city, "Chennai")   == 0) return "Bengaluru";
    if (strcmp(departure_city, "Ahmedabad") == 0) return "Mumbai";
    if (strcmp(departure_city, "Hyderabad") == 0) return "Bengaluru";
    if (strcmp(departure_city, "Chandigarh")== 0) return "Delhi";
    if (strcmp(departure_city, "Kolkata")   == 0) return "Hyderabad";
    return "Goa";   /* default for Goa -> anywhere */
}

/* ------------------------------------------------------------------ */
/*  Print the boarding pass                                            */
/* ------------------------------------------------------------------ */
void printTicket(booking details, const char *bus_name, int fare) {
    const char *destination = getDestination(details.city_city);

    printf("\n==================================================");
    printf("\n                  BOARDING PASS                  ");
    printf("\n==================================================");
    printf("\n Passenger Name : %s %s",       name, surname);
    printf("\n Contact Info   : +%d-%lld",    code, contact);
    printf("\n Email          : %s",           email);
    printf("\n--------------------------------------------------");
    printf("\n Route          : %s  ===>  %s", details.city_city, destination);
    printf("\n Travel Date    : Day %d of the month", details.date);
    printf("\n Preferred Time : %s",           details.am_pm);
    printf("\n--------------------------------------------------");
    printf("\n Assigned Bus   : %s",           bus_name);
    printf("\n Fare Paid      : INR %d (Transaction Successful)", fare);
    printf("\n Seat Number    : Seat 18A (Window)");
    printf("\n Ticket Code    : #TXN-12546728");
    printf("\n==================================================\n\n");
}

/* ------------------------------------------------------------------ */
/*  Shared payment helper — collects card number and PIN              */
/*  Returns true if PIN was valid, false otherwise.                   */
/* ------------------------------------------------------------------ */
static bool collectPayment(booking details, const char *bus_name, int fare) {
    printf("Enter your card number: ");
    scanf(" %14s", transaction);
    printf("Your amount to be paid: %d\n", fare);
    printf("Enter your 4-digit PIN: ");
    scanf(" %d", &pin);

    if (pin > 999 && pin <= 9999) {
        printf("\nProcessing Payment...\n");
        printTicket(details, bus_name, fare);
        return true;
    }
    printf("\nIncorrect PIN. Try again!\n");
    return false;
}

/* ------------------------------------------------------------------ */
/*  transaction_1  —  standard long-travel (budget 1500-5000)        */
/*  Buses: Deccan Queen (1800) | Northern Shuttle (2200)             */
/* ------------------------------------------------------------------ */
void transaction_1(booking details) {
    flag_4 = true;

    while (flag_4 == true) {
        printf("\nEnter your bus choice number: ");
        scanf(" %d", &bus_choice);

        switch (bus_choice) {
            case 1:
                printf("\nYOUR CHOICE: [MH-14-LX-8890] Deccan Queen Transports (Luxury Seater) - Fare: 1800\n");
                if (collectPayment(details, "[MH-14-LX-8890] Deccan Queen Transports (Luxury Seater)", 1800))
                    flag_4 = false;
                break;

            case 2:
                printf("\nYOUR CHOICE: [CH-02-EX-9011] Northern Shuttle (AC Express) - Fare: 2200\n");
                if (collectPayment(details, "[CH-02-EX-9011] Northern Shuttle (AC Express)", 2200))
                    flag_4 = false;
                break;

            default:
                printf("\nInvalid input, try again!\n");
                break;
        }
    }
}

/* ------------------------------------------------------------------ */
/*  transaction_2  —  luxury long-travel (budget > 5000)             */
/*  Buses: Bharat Express (5500) | Capital Flyer (6200)              */
/*         Silicon Valley Voyager (7000)                             */
/* ------------------------------------------------------------------ */
void transaction_2(booking details) {
    flag_4 = true;

    while (flag_4 == true) {
        printf("\nEnter your bus choice number: ");
        scanf(" %d", &bus_choice);

        switch (bus_choice) {
            case 1:
                printf("\nYOUR CHOICE: [MH-12-AS-4521] Bharat Express (AC Sleeper) - Fare: 5500\n");
                if (collectPayment(details, "[MH-12-AS-4521] Bharat Express (AC Sleeper)", 5500))
                    flag_4 = false;
                break;

            case 2:
                printf("\nYOUR CHOICE: [DL-01-NE-1092] Capital Flyer (Premium Sleeper) - Fare: 6200\n");
                if (collectPayment(details, "[DL-01-NE-1092] Capital Flyer (Premium Sleeper)", 6200))
                    flag_4 = false;
                break;

            case 3:
                printf("\nYOUR CHOICE: [KA-03-SV-2287] Silicon Valley Voyager (Multi-Axle AC) - Fare: 7000\n");
                if (collectPayment(details, "[KA-03-SV-2287] Silicon Valley Voyager (Multi-Axle AC)", 7000))
                    flag_4 = false;
                break;

            default:
                printf("\nInvalid input, try again!\n");
                break;
        }
    }
}

/* ------------------------------------------------------------------ */
/*  transaction_3  —  off-peak long-travel                           */
/*  Buses: Pink City (1600) | Western Fleet (2400)                   */
/*         Eastern Star (3000) | Cyberabad Cruiser (4500)            */
/* ------------------------------------------------------------------ */
void transaction_3(booking details) {
    flag_4 = true;

    while (flag_4 == true) {
        printf("\nEnter your bus choice number: ");
        scanf(" %d", &bus_choice);

        switch (bus_choice) {
            case 1:
                printf("\nYOUR CHOICE: [RJ-14-HT-5543] Pink City Travels (Non-AC Seater) - Fare: 1600\n");
                if (collectPayment(details, "[RJ-14-HT-5543] Pink City Travels (Non-AC Seater)", 1600))
                    flag_4 = false;
                break;

            case 2:
                printf("\nYOUR CHOICE: [GJ-01-EE-3214] Western Fleet (Electric Express) - Fare: 2400\n");
                if (collectPayment(details, "[GJ-01-EE-3214] Western Fleet (Electric Express)", 2400))
                    flag_4 = false;
                break;

            case 3:
                printf("\nYOUR CHOICE: [WB-02-CC-1254] Eastern Star Liners (Luxury Seater) - Fare: 3000\n");
                if (collectPayment(details, "[WB-02-CC-1254] Eastern Star Liners (Luxury Seater)", 3000))
                    flag_4 = false;
                break;

            case 4:
                printf("\nYOUR CHOICE: [TS-09-CB-6641] Cyberabad Cruiser (AC Sleeper) - Fare: 4500\n");
                if (collectPayment(details, "[TS-09-CB-6641] Cyberabad Cruiser (AC Sleeper)", 4500))
                    flag_4 = false;
                break;

            default:
                printf("\nInvalid input, try again!\n");
                break;
        }
    }
}

/* ------------------------------------------------------------------ */
/*  transaction_4  —  local travel                                   */
/*  Buses: Coastal Cruise (950) | Coromandel Connect (1200)          */
/* ------------------------------------------------------------------ */
void transaction_4(booking details) {
    flag_4 = true;

    while (flag_4 == true) {
        printf("\nEnter your bus choice number: ");
        scanf(" %d", &bus_choice);

        switch (bus_choice) {
            case 1:
                printf("\nYOUR CHOICE: [GA-03-TR-7765] Coastal Cruise Liners (Multi-Axle AC) - Fare: 950\n");
                if (collectPayment(details, "[GA-03-TR-7765] Coastal Cruise Liners (Multi-Axle AC)", 950))
                    flag_4 = false;
                break;

            case 2:
                printf("\nYOUR CHOICE: [TN-01-AC-4432] Coromandel Connect (Electric Express) - Fare: 1200\n");
                if (collectPayment(details, "[TN-01-AC-4432] Coromandel Connect (Electric Express)", 1200))
                    flag_4 = false;
                break;

            default:
                printf("\nInvalid input, try again!\n");
                break;
        }
    }
}
