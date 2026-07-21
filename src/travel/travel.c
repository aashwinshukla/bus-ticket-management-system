#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../../global/global.h"
#include "../user/user.h"
#include "../transaction/transaction.h"
#include "travel.h"

/* Long-distance travel — picks the right bus tier and transaction handler */
void longTravel(booking details) {
    printf("\n--- Processing Long Travel Booking ---\n");
    printf("Date: %d of the month | From: %s | Budget: %s\n",
           details.date, details.city_city, details.budget);

    int  budget_val = atoi(details.budget);
    bool is_any     = (strcmp(details.budget, "any") == 0);

    if (details.date > 0 && details.date < 16) {
        /* First half of the month — peak season */
        if (!is_any && budget_val <= 1500) {
            printf("\nSorry, no bus available for long-distance travel in this budget.\n");
        } else if (is_any || (budget_val > 1500 && budget_val <= 5000)) {
            printf("\n========== AVAILABLE STANDARD LONG-TRAVEL BUSES ==========\n");
            printf("  1. [MH-14-LX-8890] Deccan Queen Transports (Luxury Seater) - Fare: 1800\n");
            printf("  2. [CH-02-EX-9011] Northern Shuttle (AC Express)            - Fare: 2200\n");
            printf("==========================================================\n");
            transaction_1(details);
        } else {
            printf("\n========== AVAILABLE LUXURY SLEEPER BUSES ==========\n");
            printf("  1. [MH-12-AS-4521] Bharat Express (AC Sleeper)             - Fare: 5500\n");
            printf("  2. [DL-01-NE-1092] Capital Flyer (Premium Sleeper)         - Fare: 6200\n");
            printf("  3. [KA-03-SV-2287] Silicon Valley Voyager (Multi-Axle AC)  - Fare: 7000\n");
            printf("====================================================\n");
            transaction_2(details);
        }
    } else {
        /* Second half of the month — off-peak season */
        if (!is_any && budget_val <= 1500) {
            printf("\nSorry, no bus available for long-distance travel in this budget.\n");
        } else {
            printf("\n========== AVAILABLE OFF-PEAK LONG-TRAVEL BUSES ==========\n");
            printf("  1. [RJ-14-HT-5543] Pink City Travels (Non-AC Seater)      - Fare: 1600\n");
            printf("  2. [GJ-01-EE-3214] Western Fleet (Electric Express)        - Fare: 2400\n");
            printf("  3. [WB-02-CC-1254] Eastern Star Liners (Luxury Seater)     - Fare: 3000\n");
            printf("  4. [TS-09-CB-6641] Cyberabad Cruiser (AC Sleeper)          - Fare: 4500\n");
            printf("==========================================================\n");
            transaction_3(details);
        }
    }
}

/* Local travel — picks the budget tier and transaction handler */
void localTravel(booking details) {
    printf("\n--- Processing Local Travel Booking ---\n");
    printf("Date: %d of the month | From: %s | Budget: %s\n",
           details.date, details.city_city, details.budget);

    int  budget_val = atoi(details.budget);
    bool is_any     = (strcmp(details.budget, "any") == 0);

    if (is_any || (budget_val >= 500 && budget_val <= 1500)) {
        printf("\n========== AVAILABLE LOCAL SHUTTLE BUSES ==========\n");
        printf("  1. [GA-03-TR-7765] Coastal Cruise Liners (Multi-Axle AC)  - Fare: 950\n");
        printf("  2. [TN-01-AC-4432] Coromandel Connect (Electric Express)  - Fare: 1200\n");
        printf("===================================================\n");
        transaction_4(details);
    } else {
        printf("\n[INFO] Your budget is higher than standard local fares.\n");
        printf("We recommend our premium localized shuttle:\n");
        printf("  1. [TN-01-AC-4432] Coromandel Connect (Electric Express) - Fare: 1200\n");
        printf("(Any remaining change will be refunded at the boarding counter.)\n");
        transaction_4(details);
    }
}
