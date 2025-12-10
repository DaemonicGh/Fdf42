*This project has been created as part of the 42 curriculum by rprieur*

# FdF — Isometric Wireframe Renderer

## Description

**FdF** renders an **isometric wireframe** representation of a heightmap grid.
This version includes the full feature set along with all bonus requirements.

The program loads `.fdf` files containing a grid of integers (heights) and displays a fully interactive 3D isometric scene.

---

## Instructions

The program should work out of the box:

```bash
./fdf path/to/map.fdf
```

If it doesn't, try rebuilding everything:

1. Go to `nacho/Macrolibx-x.x.x` and run:

   ```bash
   make
   ```
2. Go back to `nacho/` and run:

   ```bash
   make
   ```
3. Return to the main directory and run:

   ```bash
   make re
   ```

This rebuilds all dependencies and the program itself.

---

## Resources

* **MacroLibX** (rendering backend)
  [https://github.com/seekrs/MacroLibX](https://github.com/seekrs/MacroLibX)

* **Nacho**
  A custom helper layer used for various MacroLibX operations.

* **Line rendering**
  Uses a modified Bresenham line algorithm:
  [https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

* **Projection references**
  [https://en.wikipedia.org/wiki/Isometric_projection](https://en.wikipedia.org/wiki/Isometric_projection)
  [https://en.wikipedia.org/wiki/3D_projection](https://en.wikipedia.org/wiki/3D_projection)

> *AI (ChatGPT 5) was used only for documentation and this README.
> No AI-generated code appears in this project.*

---

## Features

#### General Interaction

* All relevant inputs are *continuous* (updated every frame).
* Most actions are scaled to framerate for consistent responsiveness.

#### Camera & Rotation

* Rotate the model freely using the mouse.
* **Left mouse button** → lock vertical rotation to the nearest 45°
* **Right mouse button** → lock horizontal rotation to the nearest 45°
* Background color changes based on camera angle (helps distinguish top/bottom).
* Mouse is confined to the window during rotation mode.
  Press **Space** to toggle grabbing/locking.

#### Zoom & Focus Point

* Zoom with the **mouse wheel**.
* The model uses a **focus point**:

  * All rotation, translation, and zoom are centered on it.
  * Always remains centered on-screen and auto-adjusts to ground height.
* Move focus with **WASD** or **Arrow Keys**.
* Movement direction depends on camera rotation.
* Move faster while holding **Shift**.

#### Height and Line Control

* Height amplitude: **R** (increase), **F** (decrease)
* Line thickness: **T** (increase), **G** (decrease)
* Auto-coloring by height can be toggled with **C**

#### Editing the Model

Modify the height of the focused point:

* **Alt + Scroll** → adjust by 1
* **Ctrl + Scroll** → adjust by 10
* **Alt + Ctrl + Scroll** → adjust by 100

Save modifications by pressing **Enter**.

#### Heightmap Mode

Toggle with **Tab**:

* Shows a 2D heightmap (white = highest, black = lowest)
* Move with **WASD** or **middle mouse drag**
* Zoom with the scroll wheel

Edit heightmap values with:

* **Left click** → +1
* **Right click** → –1
* Add **Alt**, **Ctrl**, or both for ×10, ×100, ×1000 increments.

#### Window & System

* Toggle fullscreen with **F11**
* Recenter the window with **F10**
  *(Note: thoses actions can crash the program)*

### Monitoring Overlay

Displayed at the top of the screen:

* Focus position
* Camera rotation (projetion mode)
* Zoom level (projection mode)
* FPS (approximate and tends to overestimate)

#### Configurable Parameters

Additional constants and configuration options can be found in:
`includes/fdf_constants.h`
