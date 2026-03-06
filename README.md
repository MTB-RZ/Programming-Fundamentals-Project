# Hospital Management System (C++)

This was a pretty basic Programming Fundamentals semester project that I made in C++. The goal was to build a simple hospital management system that stores patient records in a file and allows basic operations on them.

The program uses dynamic memory allocation and file handling to load, edit, and update patient records stored in a text file (Hospital.txt).

Each record stores some basic information about a patient:

- Patient Name

- Address

- Blood Group

The data is stored in the file using tab separated values, and the program reads the file, loads the data into dynamic arrays, and then performs operations on it.

# Core Functionalities

The system provides a simple console menu with the following options:

1. View All Patients

Displays all the patient records currently stored in the system.

2. Search for a Specific Patient

Allows searching records in two ways:

- by full name

- by blood group

If a match is found, the patient information is displayed.

3. Admit a New Patient

Adds a new patient record to the system by taking input from the user and appending it to the Hospital.txt file.

4. Discharge a Patient

Removes a patient from the system by entering their full name.
The program updates the file by removing the record and rewriting the updated data.

5. Exit

Closes the system.

# Concepts Used

This project was mainly made to practice Programming Fundamentals concepts, including:

- Dynamic Memory Allocation (new / delete)

- Double pointers (char**)

- File handling (ifstream, ofstream)

- Manual string handling using character arrays

- Searching records using character comparison

- Input validation

- Modular programming using functions

- We were not allowed to use the string class or built-in string functions, so everything was done using character arrays and manual loops.
