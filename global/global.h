#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdbool.h>

// User info
extern char name[25];
extern char surname[25];
extern int year, month, day;
extern int code;
extern int pin;
extern long long contact;
extern char email[40];

// Navigation / control
extern int choice;
extern int option;
extern int bus_choice;
extern char transaction[15];

// Loop flags
extern bool flag;
extern bool flag_1;
extern bool flag_2;
extern bool flag_3;
extern bool flag_4;

// --- Definitions (only compiled once, from bus.c) ---
#ifdef GLOBAL_IMPL
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
bool flag    = true;
bool flag_1  = true;
bool flag_2  = true;
bool flag_3  = true;
bool flag_4  = true;
#endif

#endif // GLOBAL_H
