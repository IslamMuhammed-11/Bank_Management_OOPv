# OOP Bank System

## Overview

OOP Bank System is a C++14 console application that simulates a simple banking and currency management system.
It demonstrates object-oriented programming concepts such as encapsulation, inheritance, and modular design. 
The system allows users to manage clients, perform transactions, handle user authentication, and manage multiple currencies with real-time rate updates.

## Features

- **User Authentication:** Secure login system for users.
- **Client Management:** Add, update, delete, and search for bank clients.
- **Transactions:** Perform banking transactions for clients.
- **User Management:** Manage system users and their permissions.
- **Currency Management:** 
  - List available currencies.
  - Find currencies by code or country.
  - Update currency exchange rates.
  - Currency conversion calculator.

## Project Structure

- `OOP_BankSystem.cpp` - Entry point of the application.
- `clsMainScreen.h` - Main menu and navigation logic.
- `clsLoginScreen.h` - Handles user login.
- `clsCurrency.h` - Currency class and related operations.
- `clsUpdateRateScreen.h` - UI for updating currency rates.
- `clsCurrencyMainScreen.h`, `clsCurrencyCalculatorScreen.h`, `clsFindCurrency.h`, `clsListCurrenciesScreen.h` - Currency-related screens.
- `clsShowClientsScreen.h` - Displays client list.
- `clsScreen.h` - Base class for screen UI.
- `clsInputValidate.h` - Input validation utilities.

## Getting Started

### Prerequisites

- Visual Studio 2022 or compatible C++14 compiler.

### Building and Running

1. Open the solution in Visual Studio 2022.
2. Build the solution (`Ctrl+Shift+B`).
3. Run the application (`F5`).

### Usage

- On startup, the login screen will prompt for user credentials.
- After successful login, the main menu provides options for client management, transactions, user management, and currency operations.
- Follow on-screen instructions to navigate and perform actions.

## Data Storage

- Currency and client data are stored in plain text files (e.g., `Currencies.txt`).

## Notes

- All input is validated for correctness.
- The application is designed for educational purposes and does not implement advanced security or error handling.

## License

This project is provided for educational use only.
