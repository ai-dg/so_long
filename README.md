# so_long - A Simple 2D Game

![Score](https://img.shields.io/badge/Score-100%25-brightgreen)  
📌 **42 School - MiniLibX & Game Development Project**  

## ▌ Description
**so_long** is a **basic 2D game** built using the **MiniLibX** graphics library.  
The objective is to **collect all items on the map and reach the exit**, while navigating obstacles.

<img src="https://github.com/user-attachments/assets/3ebba97c-388f-4b25-8056-6c97e52cc90a" width="500">

This project provided hands-on experience with **window management, textures, event handling, and pathfinding algorithms**.

## ▌ Key Features
▸ **Loads and validates a `.ber` map file**  
▸ **Displays a game world using MiniLibX**  
▸ **Implements keyboard controls (WASD / arrow keys)**  
▸ **Counts and displays the number of moves**  
▸ **Ensures a valid path exists before starting the game**  
▸ **Handles window events (ESC key, closing button, etc.)**  

## ▌ Result: **100% Score**
The project was successfully validated with a **100% score**, meeting all evaluation criteria. 🎉

## ▌ Files
- `so_long.h` → Contains function prototypes and required macros  
- `so_long.c` → Main game loop and event handling  
- `map_parser.c` → Parses and validates the `.ber` map file  
- `graphics.c` → Loads textures and manages MiniLibX display  
- `movement.c` → Handles player movement logic  
- `Makefile` → Automates compilation (`all`, `clean`, `fclean`, `re`, `bonus`)  

## ▌ **Game Mechanics**
1. The player starts at a designated position (`P`) on the map.
2. The goal is to collect all items (`C`).
3. Once all items are collected, the player can reach the exit (`E`).
4. The number of moves is displayed in the **terminal**.
5. The game ensures that a **valid path exists** between `P`, all `C`, and `E`.

### ■ **Map Format (`.ber` files)**
A valid `.ber` map must:
- Be **rectangular**.
- Be **surrounded by walls (`1`)**.
- Contain **at least one**:
  - `P` (Player start position)
  - `C` (Collectible item)
  - `E` (Exit point)
- Use only the following characters:
  - `0` → Empty space
  - `1` → Wall
  - `C` → Collectible
  - `E` → Exit
  - `P` → Player start position

**Example valid map:**
```txt
11111111111111111111111
1111111 1P0C0E1 1111111
11111111111111111111111
```

## ▌ **Graphical & Input Handling**
- The game **opens a window** and displays the map.
- The **W, A, S, D** (or arrow keys) are used for movement.
- **ESC key or closing the window** properly exits the game.
- The **number of moves is displayed in the terminal**.

## ▌ **Dependencies**
Before compiling the game, install the required dependencies:

### **On Debian/Ubuntu**
```sh
sudo apt update  
sudo apt install libbsd-dev  
```

### **On Fedora**
```sh
sudo dnf install libbsd-devel  
```

**MiniLibX** (https://github.com/42Paris/minilibx-linux) is included in the folder /minilibx-linux and inside of the Makefile.

## ▌ **Bonus Features**
| Feature | Description |
|---------|-------------|
| ▸ **Animated Sprites** | Adds movement animations for smoother gameplay |
| ▸ **Enemy Patrols** | Introduces an enemy that moves around the map |
| ▸ **On-Screen Move Counter** | Displays the number of moves directly on the game screen |

## ▌ Compilation & Usage
### ■ **Compile the Program**
```sh
make
``` 

### ■ **Run so_long**
```sh
./so_long maps/map1.ber  
```

### ■ **Run with a Custom Map**
```sh
./so_long maps/map2.ber  
```

## 📜 License
This project was completed as part of the **42 School** curriculum.  
It is intended for **academic purposes only** and follows the evaluation requirements set by 42.  

Unauthorized public sharing or direct copying for **grading purposes** is discouraged.  
If you wish to use or study this code, please ensure it complies with **your school's policies**.  

