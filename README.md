# Unix Client/Server Scenario - Named Pipes and Signals

This repository contains a university project that implements a Unix client-server scenario using named pipes and signals. The project includes a server and a client component, along with utilities for building, testing, and error handling.

## Project Components

### Server
- [server.c](server.c) - The server implementation.
- [serv_cli_fifo.h](includes/serv_cli_fifo.h) - Header file for server-client communication via named pipes.
- [Handlers_Serv.h](includes/Handlers_Serv.h) - Header file containing server signal handlers.
- [utils.h](includes/utils.h) - Header file for utility functions used in the server.

### Client
- [client.c](client.c) - The client implementation.
- [serv_cli_fifo.h](includes/serv_cli_fifo.h) - Header file for server-client communication via named pipes.
- [Handlers_Serv.h](includes/Handlers_Serv.h) - Header file containing server signal handlers.
- [utils.h](includes/utils.h) - Header file for utility functions used in the client.

### Error Handling
- [errors.c](errors.c) - Error handling functions for the server and client.
- [errors.h](includes/errors.h) - Header file for error handling functions.

### Utilities
- [utils.c](utils.c) - Utility functions used in both the server and client.
- [utils.h](includes/utils.h) - Header file for utility functions.

## Build the Project

To build the project, you can use the provided Makefile. Run the following commands in your terminal:

- To build the project in debug mode:
  ```bash
  make debug
  ```
- To clean generated files:
  ```bash
  make clean
  ```

## testing
A Python script, testing.py, is provided for testing the project. It can start both the server and multiple client instances for testing the client-server interaction. You can configure the script in the config dictionary to specify whether to run the server and client during testing.  

To run the testing script, use the following command:
```
python3 testing.py
```  

## Conclusion

In this project, we've implemented a Unix client-server scenario using named pipes and signals. The server and client components communicate with each other through these named pipes, providing a practical example of inter-process communication in a Unix environment. Additionally, signal handling mechanisms have been employed to manage communication and control the flow of the server and client processes,enabling concurrency for competing clients.

This project serves as a valuable learning experience, showcasing the following key elements:

- The use of named pipes (FIFOs) for communication between processes.
- Signal handling for communication and process control.
- Error handling to gracefully manage unexpected scenarios.