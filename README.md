# Minitalk

The **Minitalk** project from [42 School](https://42.fr) is a small client/server application where the communication is performed **only using Unix signals**.  
The purpose is to understand **inter-process communication (IPC)** at a low level by encoding messages with `SIGUSR1` and `SIGUSR2`.

---

## 📌 Project Overview

- The project consists of a **server** and a **client**.
- The **server** prints every message it receives from the client.
- The **client** sends a string message to the server, bit by bit, using signals.
- Uses **only `SIGUSR1` and `SIGUSR2`** for data transfer.

---

## ⚙️ Compilation

```sh
make        # builds server and client
make clean  # removes object files
make fclean # removes executables and objects
make re     # full rebuild
After compilation, you will have two executables:

server

client

🚀 Usage
Start the server:

sh
Copy code
./server
This will display the server PID (Process ID).

Example output:

yaml
Copy code
Server PID: 4242
Open another terminal and run the client with the server PID and a message:

sh
Copy code
./client 4242 "Hello from Minitalk!"
The server will output:

csharp
Copy code
Hello from Minitalk!
📊 Project Structure
arduino
Copy code
minitalk/
│── server.c     # server implementation
│── client.c     # client implementation
│── minitalk.h   # header file
│── utils.c      # helper functions
│── Makefile
│── README.md
✅ Features
Fully compliant with 42 Norm.

Client can send any string message to the server.

Server correctly receives and prints characters one by one.

Works reliably with longer messages.

Proper error handling (invalid PID, empty string, etc).

🔧 Implementation Details
Each character is sent bit by bit from client to server.

SIGUSR1 and SIGUSR2 represent binary 0 and 1.

The server reconstructs characters from received bits.

Communication is synchronous (client waits for server acknowledgment before sending next bit).

📝 Author
👤 Vache Zohrabyan
42 Yerevan — GitHub

yaml
Copy code

---

⚡ Do you want me to also add a **bonus section** in the README (Unicode/multiple clients handling), like in the 42 subject, so it looks even stronger?
