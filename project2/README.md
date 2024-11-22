AUTHOR: Merary Murillo

RECORDING <https://youtu.be/bLlXjAI_chs?si=Fd0nMulxLRxgNcQT>

Project Objective: This project is a simple console-based menu system 
for a coffee shop called Roast Bean Cafe. The program displays a menu 
of drinks (hot and cold) and desserts, allows the user to place an 
order, calculates the total cost, and processes payment. The project 
utilizes C++ features such as smart pointers, dynamic memory 
allocation, classes, structs, and enumerations.



FEATURES

 - Dynamic Menu: Displays a menu with various categories: Hot Drinks, Cold Drinks, and Desserts.
 
- Smart Pointers: Utilizes std::unique_ptr for dynamic memory management.

- Order Processing: Allows the customer to select menu items and enter quantities for each selection.

- Price Calculation: Computes the total price based on the user's selections.

- Payment System: Accepts the payment amount from the user and calculates any change to be returned.

- Closing Message: Thanks the customer for their visit once the transaction is completed.



PROJECT STRUCTURE

  main.cpp:
This is the entry point of the program.
It contains the main logic of the program, including the menu display, order taking, price calculation, and payment processing.


  project2.cpp:
This file contains the implementation of the functions declared in project2.hpp.
It includes functions like displayMenu(), takeOrder(), processPayment(), and closingMessage().


  project2.hpp:
This is the header file that contains the declarations of the MenuItem structure and DrinkType enumeration.
It also declares all the functions used in the project.
