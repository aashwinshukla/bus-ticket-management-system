# Bus Ticket Management System

A console-based bus reservation system written in C. Enter your profile, browse cities and buses across India, book long-distance or local travel based on your budget and preferred travel window, complete a simulated payment, and receive a printed boarding pass — all from the terminal.

Built as a hands-on C project to practice structs, input validation, menu-driven flow, and modular code organisation.

---

## Features

- **User profile** — Registers name, date of birth, country code, mobile number, and email at startup
- **Bus reservation** — Supports both long-distance (10+ hrs) and local travel bookings
- **Smart bus filtering** — Available buses are narrowed down by departure date (peak/off-peak), city, and budget range
- **Simulated payment** — Select a bus, enter a card number and 4-digit PIN to confirm
- **Boarding pass** — Printed to the terminal with passenger details, route, bus, fare, seat, and ticket code
- **Browse mode** — View the full list of supported cities (with region hubs) and all buses (with registration numbers) at any time

---

## Project Structure

```
bus-ticket-management-system/
├── code/
│   └── bus.c                   # Entry point — main() and module includes
├── global/
│   └── global.h                # Global variables (extern declarations + GLOBAL_IMPL storage guard)
├── src/
│   ├── user/
│   │   ├── user.h              # booking struct, userData(), getBookingDetails()
│   │   └── user.c
│   ├── menu/
│   │   ├── menu.h              # yourChoice(), busReservation(), cities(), buses()
│   │   └── menu.c
│   ├── travel/
│   │   ├── travel.h            # longTravel(), localTravel()
│   │   └── travel.c
│   └── transaction/
│       ├── transaction.h       # transaction_1/2/3/4(), printTicket()
│       └── transaction.c
├── LICENSE
└── README.md
```

---

## Getting Started

### Prerequisites

- A C compiler — `gcc` (recommended), `clang`, or MSVC

### Compile & Run

From the repo root:

```bash
# Linux / macOS
gcc code/bus.c -o bus
./bus

# Windows (PowerShell or CMD)
gcc code\bus.c -o bus.exe
.\bus.exe
```

No Makefile needed — `bus.c` includes the module `.c` files directly, so a single compile command builds the whole project.

---

## How to Use

### 1. Login

On startup you'll be asked for:
- First name and surname
- Date of birth (year, month, day)
- Country code and mobile number
- Email address

### 2. Main Menu

```
1. Bus Reservation
2. Buses
3. Cities
4. Profile
5. Exit
```

### 3. Booking a Trip

1. Choose **Bus Reservation** → **Long travel** or **Local travel**
2. Fill in the booking details:

   | Field | What to enter |
   |---|---|
   | Departure date | Day of the month (1–31) |
   | Departure city | Exact city name from the list (e.g. `Mumbai`) |
   | Budget | `500`–`10000` or `any` |
   | Travel window | `AM` or `PM` |

3. A filtered list of buses with fares is displayed — enter the number of your choice
4. Enter a card number and 4-digit PIN to simulate payment
5. Your **boarding pass** prints to the terminal

---

## Supported Cities

| Region | Cities |
|--------|--------|
| West   | Mumbai, Pune, Ahmedabad, Goa |
| North  | Delhi, Jaipur, Chandigarh |
| South  | Bengaluru, Hyderabad, Chennai |
| East   | Kolkata |

---

## Available Buses

| Registration | Bus Name | Type |
|---|---|---|
| MH-12-AS-4521 | Bharat Express | AC Sleeper |
| MH-14-LX-8890 | Deccan Queen Transports | Luxury Seater |
| GJ-01-EE-3214 | Western Fleet | Electric Express |
| GA-03-TR-7765 | Coastal Cruise Liners | Multi-Axle AC |
| DL-01-NE-1092 | Capital Flyer | Premium Sleeper |
| RJ-14-HT-5543 | Pink City Travels | Non-AC Seater |
| CH-02-EX-9011 | Northern Shuttle | AC Express |
| KA-03-SV-2287 | Silicon Valley Voyager | Multi-Axle AC |
| TS-09-CB-6641 | Cyberabad Cruiser | AC Sleeper |
| TN-01-AC-4432 | Coromandel Connect | Electric Express |
| WB-02-CC-1254 | Eastern Star Liners | Luxury Seater |

---

## Bus Selection Logic

| Travel type | Date range | Budget | Buses shown |
|---|---|---|---|
| Long | 1–15 (peak) | 1500–5000 | Deccan Queen, Northern Shuttle |
| Long | 1–15 (peak) | 5000+ | Bharat Express, Capital Flyer, Silicon Valley Voyager |
| Long | 16–31 (off-peak) | 1500+ | Pink City, Western Fleet, Eastern Star, Cyberabad Cruiser |
| Local | any | 500–1500 or any | Coastal Cruise, Coromandel Connect |

---

## Tech Stack

- **Language:** C (C99)
- **Standard libraries:** `stdio.h`, `stdlib.h`, `string.h`, `stdbool.h`
- **Build:** Single-file compilation via `gcc` (no Makefile required)

---

## License

This project is licensed under the [MIT License](LICENSE).
