# 📚 libft – Reimplementing the C Standard Library

**Individual project** from 42 Singapore, where we rebuild a foundational subset of the **C standard library** from scratch.  

---

## 📋 Project Description

The `libft` project requires implementing a collection of essential C library functions such as:

- 🧵 String functions (`ft_strlen`, `ft_strchr`, `ft_strlcpy`, etc.)
- 🧠 Memory functions (`ft_memset`, `ft_memcpy`, `ft_bzero`, etc.)
- 🔢 Character classification (`ft_isalpha`, `ft_toupper`, etc.)
- 🧰 Utility functions (`ft_atoi`, `ft_calloc`, `ft_strdup`, etc.)
- 📦 Bonus: Singly linked list implementation (`ft_lstnew`, `ft_lstadd_front`, etc.)

---

## 🎯 Learning Objectives

- 🧠 Deepen understanding of **pointers**, **arrays**, and **memory layout**
- 🔁 Practice **reimplementing core C functions** manually
- 🧪 Write reusable, modular, and testable code

---

## 💡 Reflections & Lessons Learned

- ❗ **Fail fast over silent failure**  
  We discussed whether functions should check for `NULL`. Ultimately, we agreed that **silently accepting invalid pointers can hide bugs** in the caller’s code. Failing early (e.g., crashing on `NULL`) makes debugging easier and avoids introducing hidden bugs later.

- 🔣 **Type consistency matters**  
  I became more mindful of differences like `const char *` vs `char *`, and `size_t` vs `unsigned int`. Ensuring consistency avoids implicit casts and improves portability and correctness across different systems.

- 🛠️ **Smarter Makefile with header dependencies**  
  I learned to automatically **recompile object files when header files are updated**, using dependency generation with `-MMD`, improving build reliability.

- 🧪 > _Next time:
  Instead of commenting out test `main()` functions inside library files, maybe i should **write a separate `main.c`** for testing, so that its neater and i can compile main.c with libft.a directly


---

## 🛠️ How to Compile and Use

To compile with your own code:

```bash
make bonus to build the whole library including bonus files

cc -Wall -Wextra -Werror main.c libft.a -I.
