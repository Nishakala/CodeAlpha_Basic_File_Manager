# CodeAlpha_Basic_File_Manager
# File Management System

This C++ program provides basic file management functionalities such as listing files and directories in a given directory, creating a new directory, copying a file, and moving a file.

## Prerequisites

To compile and run this program, you need:

- A C++ compiler (e.g., g++)
- Standard C++ libraries
- UNIX-like operating system (for system calls like `mkdir`, `rename`, etc.)

## Usage

1. Compile the program using a C++ compiler. For example:

2. Run the compiled program:


## Functionality

The program performs the following tasks:

- Lists all files and directories in the current working directory.
- Creates a new directory named "new_directory" in the current working directory.
- Copies a file named "file.txt" to the newly created directory.
- Moves the original "file.txt" to the newly created directory.

## File Structure

- `file_management.cpp`: Contains the C++ source code for the file management program.
- `file.txt`: Sample file used for copying and moving operations.

## Notes

- This program assumes a UNIX-like operating system due to the usage of system calls like `mkdir` and `rename`. It may not work on Windows without modifications.
- Error handling is implemented for file operations, but additional error checks and robustness improvements can be made for production use.


