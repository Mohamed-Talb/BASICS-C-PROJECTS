# ABOUT
SO_LONG is a basic computer graphics project written in C as part of the 42 curriculum. The goal of this project is to create a small 2D top-down game while learning the fundamentals of WINDOW MANAGEMENT, EVENT HANDLING, TEXTURES, and RENDERING.

This project utilizes the school's internal graphical library, **MiniLibX**, to open windows, handle keyboard events, and load graphical sprites. The game requires parsing a valid `.ber` map format, ensuring valid routing via pathfinding algorithms (like flood fill), and rendering a fully interactive gameplay loop where the player collects items and reaches an exit without leaking memory. The implementation follows the official SUBJECT and respects THE NORM coding standard.

# REFERENCES
The project follows the official SUBJECT and respects THE NORM coding standard.

* **SUBJECT**:  [subject.pdf](./so_long.pdf)
* **MINILIBX DOCS**: [42Docs - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)

# SETUP & USAGE
### 1. Setup MiniLibX
Before compiling the game, you must extract and build the graphical library. move `minilibx.tgz` into SoLong folder , extract it, navigate inside, and compile it:

```bash
# Extract the compressed archive
tar -xf minilibx.tgz
# Navigate into the extracted directory
cd minilibx

# Compile the library
make

# Return to the root project directory
cd ..

```

### 2. Build and Run the Game

Once the MiniLibX library is compiled, build the main project using `make`:

```bash
make

```

Run the program by providing a valid `.ber` map file as an argument:

```bash
./so_long maps/map.ber

```

### Gameplay Controls:

* **`W` / `A` / `S` / `D**` (or `Z` / `Q` / `S` / `D` / Arrow Keys): Move the main character (Up, Left, Down, Right).
* **`ESC`** (or clicking the window's `X` button): Cleanly close the window and exit the game.

# GAME & MAP REQUIREMENTS

### 1. Gameplay Mechanics

* The player must collect **ALL** collectibles on the map before escaping through the exit.
* The player cannot move through walls.
* At every step, the current **movement count** must be displayed cleanly in the terminal shell.
* Window management must remain smooth (e.g., handling minimizing, switching windows) without crashing.

### 2. Map Rules (`.ber`)

The map must be constructed using strictly the following **5 characters**:

* **`0`**: Empty space
* **`1`**: Wall
* **`C`**: Collectible
* **`E`**: Map exit
* **`P`**: Player starting position

**Validation Constraints:**

* Must contain exactly **1 exit (`E`)**, exactly **1 start (`P`)**, and **at least 1 collectible (`C`)**. Duplicate `E` or `P` characters will throw an error.
* Must be perfectly **rectangular**.
* Must be entirely **surrounded by walls (`1`)**.
* Must contain a **valid path** verified programmatically (e.g., ensuring the player can reach all `C`s and the `E` without getting trapped).

### Example Valid Map:

```text
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

```

# ERROR HANDLING

If any misconfiguration, missing file, or invalid character is encountered in the `.ber` map, the program must exit cleanly without leaking memory and output exactly:

```text
Error
<Your explicit error message here>

```

*(e.g., `Error\nMap is not surrounded by walls` or `Error\nInvalid character detected`)*. All heap-allocated memory (map arrays, images, window contexts) must be properly freed upon both successful escapes and error exits.