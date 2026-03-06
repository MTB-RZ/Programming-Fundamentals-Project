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

# Data Storage

Patient records are stored in a text file called:

- Hospital.txt


Each record is stored in this format:

Name    Address    BloodGroup

Hospital.txt:

Ali Khan    Lahore    B+
Ahmed Raza  Karachi   O+
Sara Malik  Islamabad A+


The program reads this file when it starts and loads the records into dynamic arrays.

# Some Additional Things Implemented

While building this project I also added a few small things to make the program a bit cleaner.

- Menu Input Validation

- - The program checks if the user enters a valid option between 1 and 5.

- Blood Group Validation

- - When admitting a patient, the program checks if the blood group is valid.
    Accepted types are:

    A+, A-, B+, B-, O+, O-, AB+, AB-

- Name Formatting

- - Patient names are automatically formatted so the first letter of each word is capitalized.

    Example:

    ali khan -> Ali Khan
    AHMAD RAZA -> Ahmad Raza

- Manual Record Deletion

- - When a patient is discharged, the program removes the record by shifting the array data and then rewriting the file.

- Dynamic Memory Cleanup

- - All dynamically allocated memory is properly released using delete[] before the program exits.

# Purpose of the Project

This project was mainly made as part of a Programming Fundamentals course to practice:

- working with arrays and pointers

- dynamic memory allocation

- file processing

- writing modular C++ programs

It’s a simple console program but it helped in understanding how data can be stored, searched, modified, and persisted using files.
