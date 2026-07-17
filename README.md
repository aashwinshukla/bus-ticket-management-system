# Bus Ticket Management System

A console-based bus reservation application written in C. Users can register a profile, browse available cities and buses, book long-distance or local travel, and receive a printed boarding pass after payment.

Built as a hands-on C project to practice structs, input handling, menu-driven flow, and modular function design.

## Features

- **User profile** — Store name, date of birth, contact number, and email at login
- **Bus reservation** — Book long-distance (10+ hours) or local travel
- **Smart filtering** — Buses are suggested based on departure date, city, and budget
- **Payment flow** — Select a bus, enter card details and PIN, and confirm booking
- **Boarding pass** — Ticket shows route, bus, fare, seat, and passenger details
- **Browse info** — View the full list of available buses and supported cities anytime

## Getting Started

### Prerequisites

- A C compiler (`gcc`, `clang`, or MSVC)

### Compile & Run

```bash
cd code
gcc bus.c -o bus
./bus        # Linux / macOS
bus.exe      # Windows
```

## Usage

After login, the main menu offers five options:

| Option | Action |
|--------|--------|
| 1 | Bus Reservation — choose long or local travel, enter trip details, pick a bus, and pay |
| 2 | View all available buses and their registration numbers |
| 3 | View supported cities and route hubs |
| 4 | View your saved profile |
| 5 | Exit the application |

### Booking a trip

1. Select **Bus Reservation** → **Long travel** or **Local travel**
2. Enter departure day, city (exact name, e.g. `Mumbai`), budget (`500`–`10000` or `any`), and preferred time (`AM` / `PM`)
3. Pick a bus from the listed options and complete payment
4. Your boarding pass is printed to the console

### Supported cities

Mumbai, Pune, Ahmedabad, Goa, Delhi, Jaipur, Chandigarh, Bengaluru, Hyderabad, Chennai, Kolkata

## Project Structure

```
bus-ticket-management-system/
├── code/
│   └── bus.c          # Main application source
├── LICENSE
└── README.md
```

## Tech Stack

- **Language:** C
- **Libraries:** `stdio.h`, `string.h`, `stdlib.h`, `stdbool.h`

## License

This project is licensed under the [MIT License](LICENSE).
