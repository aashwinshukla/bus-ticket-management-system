#include <stdio.h>
#include "menu.h"

/* Main menu — returns the user's choice */
int yourChoice(void) {
    int local_choice;
    printf("\nWhat's on your mind?\n");
    printf("  1. Bus Reservation\n");
    printf("  2. Buses\n");
    printf("  3. Cities\n");
    printf("  4. Profile\n");
    printf("  5. Exit\n");
    printf("Enter choice: ");
    scanf(" %d", &local_choice);   /* leading space consumes leftover newline */
    return local_choice;
}

/* Reservation sub-menu — returns the user's option */
int busReservation(void) {
    int local_option;
    printf("\n========= Welcome to the Reservation Page =========\n");
    printf("Select the type of travel:\n");
    printf("  1. Long travel (more than 10 hrs)\n");
    printf("  2. Local travel\n");
    printf("  3. Back\n");
    printf("Enter choice: ");
    scanf(" %d", &local_option);   /* leading space consumes leftover newline */
    return local_option;
}

/* List available cities */
void cities(void) {
    printf("\n========= AVAILABLE CITIES & ROUTES =========\n");
    printf("  1. Mumbai         [West Hub  - Commercial Capital]\n");
    printf("  2. Pune           [West Hub  - IT & Education]\n");
    printf("  3. Ahmedabad      [West Hub  - Manufacturing]\n");
    printf("  4. Goa            [West Hub  - Coastal Tourism]\n");
    printf("--------------------------------------------------\n");
    printf("  5. Delhi          [North Hub - National Capital]\n");
    printf("  6. Jaipur         [North Hub - Heritage Tourism]\n");
    printf("  7. Chandigarh     [North Hub - Planned City]\n");
    printf("--------------------------------------------------\n");
    printf("  8. Bengaluru      [South Hub - Silicon Valley]\n");
    printf("  9. Hyderabad      [South Hub - Cyberabad Hub]\n");
    printf(" 10. Chennai        [South Hub - Automobile Capital]\n");
    printf("--------------------------------------------------\n");
    printf(" 11. Kolkata        [East Hub  - Cultural Capital]\n");
    printf("==================================================\n");
    printf("Note: Inter-city buses run every 30 minutes.\n");
}

/* List available buses */
void buses(void) {
    printf("\n========= AVAILABLE BUSES & IDENTIFICATION =========\n");
    printf("  1.  [MH-12-AS-4521]  Bharat Express (AC Sleeper)\n");
    printf("  2.  [MH-14-LX-8890]  Deccan Queen Transports (Luxury Seater)\n");
    printf("  3.  [GJ-01-EE-3214]  Western Fleet (Electric Express)\n");
    printf("  4.  [GA-03-TR-7765]  Coastal Cruise Liners (Multi-Axle AC)\n");
    printf("-----------------------------------------------------------\n");
    printf("  5.  [DL-01-NE-1092]  Capital Flyer (Premium Sleeper)\n");
    printf("  6.  [RJ-14-HT-5543]  Pink City Travels (Non-AC Seater)\n");
    printf("  7.  [CH-02-EX-9011]  Northern Shuttle (AC Express)\n");
    printf("-----------------------------------------------------------\n");
    printf("  8.  [KA-03-SV-2287]  Silicon Valley Voyager (Multi-Axle AC)\n");
    printf("  9.  [TS-09-CB-6641]  Cyberabad Cruiser (AC Sleeper)\n");
    printf(" 10.  [TN-01-AC-4432]  Coromandel Connect (Electric Express)\n");
    printf("-----------------------------------------------------------\n");
    printf(" 11.  [WB-02-CC-1254]  Eastern Star Liners (Luxury Seater)\n");
    printf("===========================================================\n");
}
