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
