# Unix Client/Server Scenario - Named Pipes and Signals

**Table of Contents**

- [Introduction](#introduction)
- [Project Overview](#project-overview)
- [Project Structure](#project-structure)
- [Signal Handling](#signal-handling)
- [Makefile](#makefile)
- [Error Handling](#error-handling)
- [Debug Mode](#debug-mode)
- [Usage](#usage)
- [Conclusion](#conclusion)

## Introduction

This project involves the creation of a client-server system using named pipes (FIFOs) and signals in C. The client sends questions to the server, and the server processes these requests and sends back answers. Signals, particularly SIGUSR1, are employed to coordinate communication between the client and the server.

## Project Overview

In this project, we have two main components: the client and the server. The client generates random questions and sends them to the server via a named pipe (FIFO1). It then waits for a response signal (SIGUSR1) from the server and reads the answer from another named pipe (FIFO2). The server, on the other hand, listens for incoming client requests via FIFO1. It processes the received questions, generates responses, and sends them back to clients via FIFO2. Signal handlers are used to handle signals between the client and server.

## Project Structure

The project is organized into several C source files and header files, which include:

- `client.c`: Contains the client-side code for generating questions, sending them to the server, and receiving and processing answers.

- `server.c`: Contains the server-side code for listening to client requests, generating responses, and sending them back to clients.

- `errors.c`: Provides error-handling functions for both the client and server to handle various error scenarios.

- `utils.c`: Contains utility functions, including a `debugMessage` function for debugging the application. Debug messages can be printed to the console when compiled in debug mode.

Header files include:

- `serv_cli_fifo.h`: Contains declarations for data structures and constants used by both the client and server.

- `Handlers_Serv.h`: Declares functions related to signal handling, with one handling signals from the server and the other from clients.

- `errors.h`: Declares error handling functions for both the client and server.

- `utils.h`: Declares utility functions, primarily the `debugMessage` function.

## Signal Handling

- In the client code, the `hand_response` function is a signal handler that processes signals from the server. It is responsible for receiving and processing the server's response.

- In the server code, the `fin_serveur` function handles signals from clients and acknowledges their requests.

## Makefile

A Makefile is provided to facilitate the compilation of both the client and server programs. It offers options for building both debugging and production versions of each program:

- `make all`: Builds both the client and server in production mode.
- `make debug`: Builds both the client and server with debugging enabled.
- `make clean`: Removes compiled binaries and object files.

## Error Handling

The code includes error handling for various scenarios, such as failing to create, open, read, or write to named pipes (FIFOs). Errors are reported using the `perror` function, and the program exits with the corresponding error code.

## Debug Mode

The code can be compiled in debug mode by defining the `DEBUG` flag. In debug mode, additional debug messages are printed to the console, providing information about the program's execution.

## Usage

To use the project:

1. Compile the client and server using the provided Makefile.
2. Start the server, which will listen for client requests.
3. Launch one or more client instances to send questions to the server.
4. Observe the communication between clients and the server using named pipes and signals.

These steps are automated through `testing.py`, running the command.
```python
testing.py
```

## Conclusion

This project demonstrates a basic client-server communication model using named pipes and signals in C. It provides a solid foundation for further exploration and development of client-server applications with interprocess communication.
