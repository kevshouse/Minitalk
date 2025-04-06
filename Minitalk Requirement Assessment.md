User

Please review the Minitalk project requirements and explain them in plain English.

## Assistant

The Minitalk project at School 42 is designed to help students understand inter-process communication (IPC) using signals in a Unix-like operating system. Here’s a breakdown of the project requirements in plain English:

### Project Overview

1. **Objective**: The goal of the Minitalk project is to create a simple communication system between two processes (a client and a server) using signals. This will help you learn about how processes can communicate with each other in a Unix environment.

### Requirements

1. **Server**:
    
    - You need to create a server program that runs continuously and listens for incoming messages from clients.
    - The server should be able to handle multiple clients, meaning it should be able to receive messages from different clients without crashing or losing messages.
    - The server must respond to the client to confirm that it has received the message.
2. **Client**:
    
    - You need to create a client program that sends messages to the server.
    - The client should be able to send messages of any length, and it should be able to send multiple messages in succession.
    - After sending a message, the client should wait for a confirmation from the server before sending the next message.
3. **Communication**:
    
    - The communication between the client and server should be done using Unix signals (SIGUSR1 and SIGUSR2).
    - You will need to encode the messages in a way that allows the server to understand them when they are received.
    - The server should be able to decode the messages and print them to the console.
4. **Signal Handling**:
    
    - You must implement proper signal handling to ensure that the server can receive and process signals correctly.
    - The server should be able to handle signals in a non-blocking way, meaning it should not freeze or crash if it receives signals while processing other tasks.
5. **Error Handling**:
    
    - Your programs should handle errors gracefully. For example, if the server cannot be started or if the client cannot connect to the server, appropriate error messages should be displayed.
    - You should also handle cases where messages are not sent or received correctly.
6. **Documentation**:
    
    - You should provide clear documentation for your code, explaining how it works and how to use it.
    - Comments in the code should help others (and yourself) understand the logic and flow of the program.
7. **Makefile**:
    
    - You need to create a Makefile to compile your programs easily. This should include rules for building both the server and client.

### Additional Considerations

- **Testing**: You should test your programs thoroughly to ensure they work as expected under various conditions.
- **Code Quality**: Your code should be clean, well-organized, and follow good programming practices. This includes using meaningful variable names, proper indentation, and avoiding code duplication.

### Conclusion

The Minitalk project is a practical exercise in understanding how processes communicate in a Unix environment using signals. By completing this project, you will gain valuable experience in IPC, signal handling, and error management, which are essential skills for any software developer working in systems programming or networked applications.

## User

What are the differences between the Mandatory section and the Bonus parts of the project?

## Assistant

The Mandatory section of the Minitalk project focuses on creating a basic client-server communication system using Unix signals, ensuring proper signal handling and error management. The Bonus parts typically involve additional features or enhancements, such as implementing message acknowledgments or supporting more complex message formats, which go beyond the core requirements. ### Mandatory Section

- **Basic Functionality**: The mandatory part requires the implementation of a simple client-server model where the client sends messages to the server using signals.
    
- **Signal Handling**: It focuses on using `SIGUSR1` and `SIGUSR2` to represent binary data (1's and 0's) and requires proper handling of these signals to ensure messages are received correctly.
    
- **Message Transmission**: The client must convert each character into 8 bits and send them sequentially, while the server must decode these bits and display the received message.
    
- **Error Management**: Basic error handling is required to manage issues like server startup failures or message transmission errors.
    

### Bonus Parts

- **Enhanced Features**: The bonus section introduces additional functionalities, such as sending back read receipts to the client, which confirms that the server has received each bit.
    
- **User Feedback**: The client can provide visual feedback by displaying messages for each bit sent, enhancing the user experience during communication.
    
- **Unicode Support**: The bonus part may include support for Unicode characters, allowing for a broader range of messages beyond standard ASCII.
    
- **Improved Acknowledgment Mechanism**: The server can send acknowledgment signals back to the client after receiving each bit, improving the reliability of the communication process.
    
- **Use of `sigaction`**: The bonus section may require the use of the `sigaction` structure to manage signal handling more effectively, providing access to metadata about signal transmission.
    

### Summary

In summary, the Mandatory section establishes the foundational aspects of the client-server communication system, while the Bonus parts enhance functionality, interactivity, and robustness, allowing for a more comprehensive understanding of inter-process communication.