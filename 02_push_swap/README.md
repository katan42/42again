📦 `push_swap` is a sorting project using **two stacks** (`a` and `b`) and a **limited instruction set**  
(`sa`, `pb`, `ra`, `rra`, …) to sort integers in as few moves as possible.

---

This implementation uses:

- 🧮 **Normalisation** (convert values → ranks `0..n-1`)
- ⚙️ **Binary Radix Sort** for `n > 5`
- 🎯 **Hand-crafted small sorts** for `≤ 5` elements
---
## 1️⃣ Overview of the Approach

1. **Input parsing & validation** 🧱  
   - Check integers (no overflow, no junk chars).  
   - Reject duplicates, empty / space-only strings.  
   - On error → print `Error\n` to `stderr` and exit.

2. **Shell behaviour (bash vs zsh)** 🐚  
   - I **do not** use `ft_split` on a single quoted string.  
   - I rely on the shell to expand `ARG="1 2 3"; ./push_swap $ARG` into separate args.  
   - In **bash**, `$ARG` is split on spaces ✅  
   - In **zsh**, `$ARG` stays as one argument unless special options are set ❌  
   ➜ To match the 42 checker behaviour, I run the tester with **bash**.

3. **Data structure** 📚  
   - Two stacks `a` and `b`, each as a **struct with an array + size**.  
   - All ops (`sa`, `pb`, `ra`, `rra`, …) mutate the arrays and **print** the matching instruction.

4. **Sorting strategy** 🧠  
   - `0–1` element → already sorted.  
   - `2–5` elements → **hand-crafted small sort** (swap / rotate / reverse-rotate).  
   - `>5` elements → **LSD binary radix** on **normalised indices**.

---

## 2️⃣ Normalisation 🧮

Raw input can be large/small, negative, and in any order.  
Radix works best on a **dense, non-negative** range, so we:

1. Copy values to a temp array and sort it.
2. Replace each original value with its **position** in the sorted array:
   - smallest → `0`, next → `1`, … largest → `n - 1`.

We then keep only these ranks in stack `a`.

**Why it’s nice:**

- All values lie in `[0, n - 1]`.  
- Needed bits: `bits = floor(log2(n - 1)) + 1`.  
- Number of radix passes depends **only on `n`**, not on the actual values.  
- For fixed `n`, the move count becomes **predictable and almost fixed**.

---

## 3️⃣ Radix Sort (for n > 5) ⚙️

### 🧩 Idea

We apply **LSD binary radix** to the normalised indices.

For each bit `bit` from `0` to `bits - 1`:

1. Repeat `size_a` times:  
   - Check `bit` of the top of `a`:  
     - `0` → `pb` to `b`  
     - `1` → `ra` on `a`
2. After the pass, `pa` all elements back from `b` to `a`.

After the last bit: `a` is sorted, `b` is empty.

### 📏 Fixed number of moves (for fixed n)

Because of normalisation:

- `bits` is fixed for a given `n`.  
- For each bit:
  - ~`n` operations (`pb` / `ra`),
  - ≤`n` `pa` to restore.  
- Rough bound: **`moves ≤ 2n × bits`**.

So for a fixed `n`, radix has a **deterministic upper bound** and is very **input-agnostic**: bad shuffles don’t blow up the complexity.

---

## 4️⃣ Why Small n (≤ 5) is Hard-coded 🎯

Radix has setup overhead:

- Even for `3` or `4` elements, it still runs full bit passes.  
- But small stacks can be solved in **very few moves** with simple logic.
Eg: `3 elements` can be sorted with `sa`, `ra`, `rra` in **2–3 moves**.  

So:
- `n ≤ 5` is hardcoded and `n > 5` → use **radix on normalised indices**.

---

## 5️⃣ Limitations of Radix sort🏁

The subject’s top scores require roughly:
- **100 numbers** → `< 700` moves  
- **500 numbers** → `≤ 5500` moves  

A plain binary radix on `[0..n-1]` often lands around:
- `n = 100` → ~900–1400 moves  
- `n = 500` → ~7000–9000 moves  

To reach 100%, people often use:

- 🧱 **Chunk-based** strategies  
- 🧠 **LIS (Longest Increasing Subsequence)** approaches  
- 🎛️ Hybrids combining chunking + greedy insertion


---

## 6️⃣ How to Build and Run ▶️

```bash
# Build
make

# Run
./push_swap <list of integers>

# Example
./push_swap 2 1 3 6 5 8
```

to randomly generate integers between 0 to INT_MAX with n=500
```bash
# Example
./push_swap `shuf -r -i 0-2147483647 -n 500
to run checker
```
to run the checker in bash shell
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

## Reflection: First Steps into Complexity 🤓

This project was my **first real dive** into algorithmic complexity and comparing different sorts:
- I started from the “school classics” like **bubble sort**, where each pair gets compared again and again → **O(n²)** and quickly too slow as `n` grows.  
- Then I discovered how **radix sort** works on digits/bits instead of comparisons, and why its cost is **O(n × k)** instead of `O(n²)`.  
- In `push_swap`, `k` (number of bits) is tiny and bounded, so radix behaves almost **linearly in `n`** – a big shift in thinking compared to quadratic algorithms.

On top of that, I also learned that:
- Algorithm design is not just “math”;  
- It’s also about **practical trade-offs** (hard-coding ≤5, accepting that pure radix won’t hit full marks),  
- And even about tools around it, like how **different shells (bash vs zsh)** handle arguments and can completely change how my program is tested.