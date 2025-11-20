# 🗣️ Minitalk – Signal-Based Client/Server Communication (42 Project)

`minitalk` is a small communication program where a **client** sends a string message to a **server** using only **UNIX signals** (`SIGUSR1` and `SIGUSR2`).  
The project teaches low-level data manipulation, process signalling, and bitwise logic, synchronous/asynchronous communication and how the OS delivers signals to processes

---

## 📌 How my code Works

### Client
1. Takes a string and server PID  
2. Converts each character → 8 bits  
3. Sends SIGUSR1 for 0 and SIGUSR2 for 1  
4. Waits for server acknowledgment before sending next bit (bonus)

### Server
1. Receives bits asynchronously  
2. Rebuilds the byte using bitwise operations  
3. Prints the completed character  
4. Detects new client PID and resets state  
5. Sends acknowledgment back to the client (bonus)

This is basically a handshake protocol 🤝.
Originally, I just spammed signals to the server with no delay (and naturally, bits got lost).
I added usleep(), but later replaced it with a real acknowledgment system, which is far more reliable and teaches proper IPC.

---

## 🧠 Key Concepts Learned

### 🔢 1. Bitwise Operations
In C, bitwise operations let you manipulate data at the bit level — the smallest unit of information (0 or 1).
Every character is stored as 8 bits (1 byte):

```c
'A'  → 01000001
'B'  → 01000010
```
Extract bits:
```c
((c >> bit) & 1)
```
c >> bit moves the target bit to the rightmost position
& 1 isolates the last bit (result becomes 0 or 1)

---

### 📡 2. Signals & sigaction
In Unix, processes (programs) can communicate by sending signals with each other.
Using info in signal.h we are able to define how to 'handle' a signal, retrieve info like PID(unique process identifier), and send the signal.

Using <signal.h>, we can:
-define a signal handler
-choose how signals are processed (sigaction)
-access extra metadata (siginfo_t)
-block/unblock specific signals (masking)
-and send signals using kill(pid, signal)

> **Fun fact:**
> The kill() function name is historical — it originally sent only terminating signals. Today it can send any signal.

---

### 🌏 3. Unicode “Just Works”
A huge bonus was that I accidentally discovered that my minitalk code can send emoji(bonus part). Kekeke

UTF-8 characters are made of **multiple bytes**, and minitalk transmits **bytes**, not characters.  
Thus, emoji are sent correctly as long as all bytes are received (the terminal will reconstruct the emoji).

Minitalk supports Unicode automatically because UTF-8 is designed to be transmitted as bytes(of course each byte has a special pattern that computer will identify multi-byte character.
This is the beauty of UTF-8.
---

## ▶️ How to Use

### 1. Compile
```bash
make
```

### 2. Start server
```bash
./server
```

### 3. Send message
```bash
./client <server_pid> "Hello World!"
```

### 4. Send emoji
```bash
./client <pid> "42 🌈✨🙂"
```

