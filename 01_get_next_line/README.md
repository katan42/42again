# 📚 get_next_line – Read a File Line by Line (42 Project)

`get_next_line` is a function that returns **one line at a time** from a file descriptor, no matter how long the line is. It teaches **buffered I/O**, **static variables**, **memory management**, and (bonus) **multi-FD handling**.

---

## 🧠 What This Project Teaches

### 🔹 1. File Descriptors
A *file descriptor (FD)* is an integer referring to an open file or input source.

| FD | Meaning |
|----|---------|
| 0  | stdin   |
| 1  | stdout  |
| 2  | stderr  |
| ≥3 | files opened with `open()` |

---

### 🔹 2. Buffered Reading (`read`)
We only read in chunks of `BUFFER_SIZE`.

`read()` does not:
- stop at newline
- guarantee full `BUFFER_SIZE`
- guarantee reading an entire line

So we got to **accumulate** buffer chunks until one full line appears.

---

### 🔹 3. Static Variables
A `static char *leftover` remembers leftover text across function calls.

Example:
```
[read chunk] → "Hello\nWor"
returned: "Hello\n"
leftover: "Wor"
```
---

### 🔹 4. Memory Management
Checking for this was.. painful
Avoid leaks, double frees, and returning freed pointers.
#### ✔️ Memory leaks?
Use:
```
valgrind --leak-check=full ./gnl
```
---

### 🔹 5. Bonus – Multi-FD Support
The bonus requires:
```
get_next_line(fd1)
get_next_line(fd2)
get_next_line(fd1)
```
without mixing leftovers. Usually done with:
```
static char *leftover[OPEN_MAX];
```
Instead of storing leftover text in a single variable, we store it in an array, where each index corresponds directly to the file descriptor number. Since every open file has its own FD (3, 4, 5, ...), each FD automatically gets its own memory space. This ensures that reading from fd1 and fd2 will not interfere with each other. **NEAT**

---

# 🚀 How to Compile & Run

## ▶️ Mandatory Version
### Compile
```
cc -Wall -Wextra -Werror \
    get_next_line.c get_next_line_utils.c main.c \
    -D BUFFER_SIZE=42 -o gnl
```
### Run
```
./gnl test.txt
```

---

## ▶️ Bonus Version
### Compile
```
cc -Wall -Wextra -Werror \
    get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c \
    -D BUFFER_SIZE=42 -o gnl_bonus
```
### Run
```
./gnl_bonus file1.txt file2.txt
```



