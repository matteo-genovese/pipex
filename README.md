# pipex

## Description
pipex is a 42 School project that aims to recreate the functionality of the shell pipe (`|`) command in C. It handles the redirection of standard input and output between processes, allowing commands to communicate with each other just like in the shell.

## Installation

Clone the repository and compile the program:

```bash
git clone https://github.com/matteo-genovese/pipex.git
cd pipex
make
```

To compile with bonus features:
```bash
make bonus
```

Additional Makefile commands:
```bash
make clean     # Remove object files
make fclean    # Remove object files and executables
make re        # Recompile everything
```

## Usage

### Basic usage (mandatory part)
```bash
./pipex infile cmd1 cmd2 outfile
```

This is equivalent to the shell command:
```bash
< infile cmd1 | cmd2 > outfile
```

Example:
```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```
This would count the number of lines containing "hello" in input.txt and write the result to output.txt.

### Bonus usage (multiple pipes)
```bash
./pipex_bonus infile cmd1 cmd2 cmd3 ... cmdn outfile
```

This is equivalent to:
```bash
< infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile
```

## Features

- Handles input and output file redirection
- Executes commands with proper path resolution
- Manages pipes between processes
- Error handling for file access, command validation, etc.
- Proper memory management
- Bonus: Supports multiple commands/pipes

## Implementation

The pipex project implements several key Unix concepts:

- **Processes**: Uses `fork()` to create child processes for each command
- **Pipes**: Creates pipes using `pipe()` to allow communication between processes
- **File Descriptors**: Manipulates file descriptors with `dup2()` for redirection
- **Command Execution**: Executes commands using `execve()`
- **Path Resolution**: Searches for commands in the PATH environment variable
- **Error Handling**: Checks for errors and provides appropriate messages

## Bonus Part

The bonus part includes:
- Multiple pipe handling (more than 2 commands)

## File Structure

- **Source Files**
  - `src/main.c`: Entry point of the program
  - `src/check_cmd.c`: Command checking and validation
  - `src/utils_stack.c`: Utility functions for memory management
  - `src/pipex.c`: Core pipe implementation

- **Bonus Files**
  - `bonus/main_bonus.c`: Entry point for bonus features
  - `bonus/check_cmd_bonus.c`: Command validation for bonus
  - `bonus/utils_stack_bonus.c`: Bonus utility functions
  - `bonus/pipex_bonus.c`: Extended pipe implementation

- **Headers**
  - `h/pipex.h`: Main project header
  - `h/libft.h`: Library header

- **Library**
  - `libft/`: Custom implementation of various standard C library functions

- **Testing**
  - `pipex_tester_42/`: Testing suite for the project

## Author
[mgenoves](https://profile-v3.intra.42.fr/users/mgenoves)

![image](https://github.com/user-attachments/assets/753ba04e-51ad-42d6-b433-01880902c627)
