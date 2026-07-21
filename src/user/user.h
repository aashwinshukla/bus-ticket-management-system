#ifndef USER_H
#define USER_H

#include <stdbool.h>

/* booking details collected per reservation */
typedef struct {
    int  date;
    char city_city[15];
    char budget[6];
    char am_pm[3];
} booking;

void    userData(void);
booking getBookingDetails(void);

#endif /* USER_H */
