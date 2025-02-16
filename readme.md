# minitalk

**minitalk** is a project that involves creating a simple communication system between two programs using signals in C. The project aims to teach you about inter-process communication, signal handling, and creating efficient systems using signals in a Linux environment. It is part of the 42 School curriculum.

---

## About

The **minitalk** project consists of implementing a communication system where a server and a client can send and receive messages using UNIX signals.

### Server:
- The server listens for signals sent by the client.
- It decodes the signals into characters and prints the message received.

### Client:
- The client sends messages to the server using signals, encoding each character as a series of signals.
  
This project teaches you how to manage signals and build a communication system without the need for sockets or files.

---

## Installation

To install **minitalk**, follow these steps:

1. Clone this repository:
    ```bash
    git clone https://github.com/ahmedelbahri/minitalk.git
    cd minitalk
    ```

2. Compile the project:
    ```bash
    make
    ```

3. Optionally, to remove all compiled objects:
    ```bash
    make clean
    ```

4. To remove the executable:
    ```bash
    make fclean
    ```

5. To recompile the project after cleaning:
    ```bash
    make re
    ```

---

## Usage

You can use **minitalk** by first running the server and then sending messages from the client. Example:

1. **Run the server**:
    ```bash
    ./server
    ```

    The server will start listening for incoming messages.

2. **Run the client** to send a message to the server:
    ```bash
    ./client <server_pid> "Your message here"
    ```

    Replace `<server_pid>` with the process ID of the running server.

---

## Bonus

In the **bonus** section, the following additional features are implemented:

- **Message Acknowledgment**: The server sends an acknowledgment back to the client once it successfully receives a message, ensuring that the client knows the message was processed correctly.
- **Multithreading**: If required, the server can handle multiple clients simultaneously, allowing for concurrent communication with several clients.
- **Handling Special Characters**: The client and server are enhanced to handle a broader range of characters, including special characters and non-printable characters.

These bonus features enhance the functionality of the basic signal-based communication system, making it more robust and versatile.

