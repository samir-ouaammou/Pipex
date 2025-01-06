# 🛠️ Pipex - 1337 School Project

Welcome to my **Pipex** repository! 🚀  
The **Pipex** project is an essential part of the **1337 School** curriculum, where I implemented a pipeline mechanism in C to manage multiple processes, pipes, and redirection. This project focuses on system-level programming, process management, and the usage of system calls like `fork()`, `execve()`, and `pipe()`.

---

## 📊 Project Overview

The **Pipex** project involves creating a program that simulates the behavior of a shell pipeline. The task is to execute two commands in sequence, with the output of the first command being passed as the input to the second command using a pipe. It is a great way to deepen understanding of **process management**, **inter-process communication (IPC)**, and **file descriptors**.

---

## 🔧 Key Features

- **Pipe Management:** Creates pipes to connect two processes.
- **Process Creation:** Uses `fork()` to create child processes.
- **Redirection:** Handles standard input/output redirection for commands.
- **Command Execution:** Uses `execve()` to execute external commands.

---

## 📋 Project Structure

The project is structured as follows:

```
pipex/
├── src/         # Source files for the project
├── include/     # Header files
|   └── pipex.h  # Header file with function prototypes
├── Makefile     # Makefile to compile the project
└── README.md    # Project documentation
```

---

## 📂 Usage

To use the program, compile it and run it with the following syntax:

```bash
./pipex <file1> <cmd1> <cmd2> ... <cmdN> <file2>

<file1>:            The input file for the first command.
<cmd1>:             The first command to be executed.
<cmd2> to <cmdN>:   The intermediate commands to be executed in sequence.
<file2>:            The output file where the result of the last command will be written.
```
Example usage:
```bash
./pipex input.txt "cat" "grep search_term" "sort" "uniq -c" output.txt
```
Single Pipe (Two Commands):
```bash
./pipex input.txt "cat" "wc -l" output.txt
```
- This reads from input.txt, passes the content through cat, then pipes it to wc -l (to count the number of lines), and writes the result to output.txt.

Multiple Pipes (Multiple Commands):
```bash
./pipex input.txt "cat" "grep error" "sort" "wc -l" output.txt
```
- This reads from input.txt, processes it through the following steps:
1. Passes the content through cat.
2. Pipes the output to grep error (to filter lines containing the word "error").
3. Pipes the result to sort (to sort the filtered lines alphabetically).
4. Pipes the final result to wc -l (to count the number of sorted lines).
- Writes the final processed result to output.txt.


## 🛠️ Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/samir-ouaammou/1337-Pipex
   ```

2. Navigate to the project directory:
   ```bash
   cd 1337-Pipex
   ```

3. Compile the source files using `make`:
   ```bash
   make
   ```

4. Clean up compiled files:
   ```bash
   make clean
   ```

5. To remove all object files and the executable:
   ```bash
   make fclean
   ```

6. To recompile the project from scratch:
   ```bash
   make re
   ```


## 🎯 Challenges Overcome
Throughout this project, I encountered and overcame challenges such as:
- Understanding process creation and management with fork().
- Handling pipe communication and file descriptors.
- Dealing with input/output redirection and the complexities of file handling.



## 🏆 Key Achievements
- Gained a deep understanding of process management in Unix-like systems.
- Implemented an efficient pipe mechanism for inter-process communication.
- Learned how to manage file descriptors and redirection in a shell-like environment.



## 🚀 Next Steps
With Pipex completed, I am now focused on:
- Expanding my knowledge of advanced system programming and Linux internals.
- Exploring other concepts in inter-process communication (IPC) and system calls.



🌟 Reflection
The Pipex project was a challenging but rewarding experience. It helped me solidify my understanding of process management, pipes, and file handling in Unix-like systems. I am excited to apply these skills to more complex projects and continue my journey in system-level programming.

---

Thank you for checking out my Pipex project! 🚀
Stay tuned for more updates as I continue to enhance my skills and tackle new challenges.
