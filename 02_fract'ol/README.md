# 🗣️ Minitalk – Signal-Based Client/Server Communication (42 Project)

# fract'ol – Interactive Fractals in C 🌌

## 1. Objectives 🎯

`Fract'ol`is about creating a small interactive fractal explorer in C using the MiniLibX graphics library, as specified in the 42 fract’ol subject. The goals are:

🔢 Work with complex numbers to implement:
The Mandelbrot set, the Julia set and a third fractal (Newton’s method for root finding) as a bonus

🖼 Learn basic computer graphics:
Open a window, Create and draw images pixel-by-pixel, Handle keyboard and mouse events smoothly

---

## 2. Concepts Learned 🧠

### 2.1 Fractals & Complex Numbers

Each pixel is mapped to a complex number and iterated:

- **Mandelbrot**
  - `z_{n+1} = z_n^2 + c`
  - `z_0 = 0`, `c` comes from the pixel coordinate.
  - If `|z|` never escapes beyond radius 2 within `max_iter`, the point is considered inside.
  - The Mandelbrot set is like a map of all possible Julia sets.
	- A point c belongs to the Mandelbrot set if the corresponding Julia set is connected (one whole piece).
	- If c is outside the Mandelbrot set, the Julia set for that c is disconnected (dust-like or fragmented).
- **Julia**
  - Same formula, but:
    - `z_0` = pixel coordinate
    - `c` = fixed complex constant from the command line.
  - Different `c` → very different shapes.
  - Mapping pixels to the complex plane
For each pixel (x, y) on the screen, I map it to a complex number:
```bash
real = (x / width  - 0.5) * zoom + offset_x
imag = (y / height - 0.5) * zoom + offset_y
```
A key detail I fixed for Julia:
On the mathematical plane, positive imaginary is up.
In graphics, increasing y goes down.

So I apply a -y style correction (`invert the y-mapping`) to avoid the Julia set appearing vertically flipped compared to online generators.

- **Newton fractal (bonus)**
  - Based on Newton’s method (e.g. `z^3 - 1`):
    - Points are coloured by:
      - Which root they converge to
      - How fast they converge

### 2.2 Graphics & MiniLibX

Core graphics steps:

✅ Initialise the graphics context with MiniLibX
- mlx_init() – set up connection to the display
- mlx_new_window() – create a window
- mlx_new_image() / mlx_get_data_addr() – create an image and get access to its pixel buffer

🎨 Draw pixels:
- Convert (x, y) and iteration counts into a colour
- Write the colour directly into the image buffer
- Display it with mlx_put_image_to_window()

🧵 Handle events:
- Keyboard hooks (for ESC, arrow keys, ‘c’)
- Mouse hooks (scroll up/down for zoom)
- Window close event (clicking the red cross)

🧼 Clean exit:
- Destroy images and window
- Free allocated memory
- Call exit() only after everything is properly cleaned up

This gave me a practical introduction to event-driven programming: instead of a linear “main”, the program waits in mlx_loop() and reacts to user actions via callbacks.

---

## 3. How to Run 🚀

```bash
make bonus
```
(bonus compiles all the mandatory and bonus section)

to run:
```bash fractal
# Mandelbrot
./fractol_bonus mandelbrot
```
<video src="eg_fractol_mandelbrot+arrow+zoom.mp4" width="600" autoplay loop muted></video>

```bash
# Julia fractal
./fractol_bonus julia <real> <imaginary>
# Example:
./fractol_bonus julia -0.4 0.6
```
<video src="eg_fractol_julia_-0.8_0.156+zoom" width="600" autoplay loop muted></video>

```bash
# Newton fractal
./fractol_bonus newton
```
<video src="eg_fractol_newton_+_colour_range_shift+zoom.mp4" width="600" autoplay loop muted></video>

---

## 4. Controls 🎮

Inside the fractal window:

- `ESC` – Quit the program.
- Arrow keys `↑ ↓ ← →` – Pan around the fractal.
- Mouse scroll – Zoom in / out at the mouse position.
- `c` – Change / shift colour scheme.

----
## 5. Design Details & Tweaks 🔧

- **Zoom limits**  
  Based on feedback from peers, I added minimum and maximum zoom values so you can’t zoom so far out that the fractal becomes a blob, or so far in that floating-point precision breaks the image. This keeps navigation stable and user-friendly.

  <video src="eg_fractol_mandelbrot+zoom_limit.mp4" width="600" autoplay loop muted></video>

- **Max iterations vs performance**  
  The `max iteration` count (max_iter) controls:
  - How detailed the fractal boundary looks.
  - How smooth colour gradients and transitions appear.
	If max_iter is higher:
	✅ More detailed boundaries and more distinct escape patterns.
	✅ Less misclassification near the edge of the set.
	❌ More work per pixel → slower rendering.
	❌ Zooming and panning feel less smooth because each redraw takes longer.

So there is a trade-off between visual detail and interactive responsiveness.
I chose values that balance detailed patterns with reasonably smooth zoom and movement.

---

## 6. Reflections & Applications 🌱

This project helped me connect:

- **Complex numbers** → visual, interactive fractal patterns.
- **Fractals in real life** → trees, ferns, coastlines, and models of irregular growth (e.g. cancer growth, blood vessels).
- **C programming** → structs, pointers, memory, plus graphics and event-driven programming.

Fractals turned abstract maths into something visual, interactive, and surprisingly close to patterns we see in nature. ✨
