# 📣 ft_printf – Reimplementing the Standard C `printf`

Individual project from 42 Singapore, where we recreate a simplified version of the standard C `printf` function.

---

## 📋 Project Description

The `ft_printf` project challenges us to rebuild `printf` from scratch, learning to handle:

- 🔣 Format parsing  
- 🧩 Variadic functions (`...`)  
- 🧵 String and character printing  
- 🔢 Number formatting (decimal, unsigned, hexadecimal)  
- 🧠 Pointer formatting and memory representation  
- ✅ Supported Format Specifiers (cspdiuxX% —covering characters, strings, pointers, signed/unsigned integers, hex formatting and percent symbol)

---

## 🎯 Learning Objectives

- 🧠 Deepen understanding of how variadic functions work using `va_start`, `va_arg`, and `va_end`
- 🔍 Learn how `printf` parses format strings character by character
- 🔧 Practice converting integers and addresses to string representations manually

---

## 💡 Reflections & Lessons Learned

🚫 Mismatched types can cause undefined behavior
I learned the hard way that using the wrong type when reading from va_arg—such as treating an unsigned int (4 bytes) as an unsigned long (8 bytes)—can break formatting and produce garbage output. This happened when I reused the pointer-printing logic for hexadecimal formatting. Since va_arg reads based on the expected type size, it fetched 8 bytes instead of 4, leading to corrupted values. This helped me solidify my understanding of how variadic functions truly behave at the memory level.

🛠️ Smarter Makefile with header dependencies
From the previous project evaluation, I learned the importance of tracking header file changes in the Makefile. By adding automatic dependency generation (e.g., using the -MMD flag), I ensured that object files are recompiled whenever the corresponding header files are modified. This made my build process more reliable and saved time debugging inconsistencies caused by stale .o files.

---

## 🛠️ How to Compile and Use

To build the library:

```bash
make
```

To compile libftprintf.a with main.c:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -Iinclude -o test
./test

