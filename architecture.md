# Calloc Chess Engine — Architecture Documentation

Welcome to the **calloc_chessengine** codebase! This project is a 100% pure C chess engine built from scratch using low-level bitboards, entirely free of C++ or object-oriented abstractions.

---

## File-by-File Technical Guide

### 1. State & Core Representation

#### `board.h`
- **Role:** Header file defining the fundamental data structures, board state representation, coordinate types, and inline bit-manipulation primitives.

- **Key Contents:**
  * `BitBoard` struct: Holds individual 64-bit bitmasks for each piece type and color, along with aggregate occupancies (`white_pieces`, `black_pieces`, `all_pieces`). It also holds an `en_passant_mask` bitmask to store pawns that moved 2 squares during that turn.  
  * `Square` enum: Sequentially maps board coordinates from `A1` (0) to `H8` (63).
  * `Piece` enum: Defines all piece types for both colors plus an `EMPTY` designation.
  * `File` enum: Represents board files (`A` through `H`).
  * **Inline Utilities:** Bitwise primitives (`set_bit`, `clear_bit`, `square_is_occupied`) and `update_boards()` for recalculating aggregate occupancies.
  * **Coordinate Helpers:** `get_file()`, `get_rank()`, and `get_square()` for converting between 0–63 indices and rank/file pairs.

#### `board.c`
- **Role:** Implements board state initialization, square-by-square piece detection, and board printing.

- **Key Functions:**
  * `init_board(BitBoard *bb)`: Sets up standard starting bitboard layouts for all pieces and invokes `update_boards()`.
  * `get_piece(const BitBoard *bb, enum Square target_sq)`: Inspects bitboards to identify which piece type occupies a given square.
  * `print_board(const BitBoard *bb)`: Renders a clean ASCII grid representation of the board complete with rank and file labels.

---

### 2. Precomputation & Non-Sliding Logic

#### `precalc.h`
- **Role:** Declares data types, global lookup tables, and initialization function prototypes for precalculated piece attack masks.

- **Key Contents:**
  * `Offset` struct: Defines directional delta pairs (`file_offset`, `rank_offset`).
  * **Global Lookup Tables:** `extern uint64_t` arrays for `knight_possible_moves[64]`, `king_possible_moves[64]`, `white_pawn_possible_attacks[64]`, and `black_pawn_possible_attacks[64]`.
  * **Prototypes:** Exposes `init_knight_moves()`, `init_king_moves()`, `init_white_pawn_attacks()`, and `init_black_pawn_attacks()`.

#### `precalc.c`
- **Role:** Generates wrap-free attack bitmasks at application startup using coordinate bounds checking.

- **Key Functions:**
  * `init_knight_moves()`: Computes knight attack bitmasks for all 64 squares using coordinate-safe offsets.
  * `init_king_moves()`: Computes single-step king attack bitmasks across all 64 squares.
  * `init_white_pawn_attacks()` / `init_black_pawn_attacks()`: Precomputes diagonal capture masks for white and black pawns.

---

### 3. Dynamic Move Generation

#### `movegen.h`
<<<<<<< HEAD
- **Role:** Defines structures for categorizing generated moves to assist with search optimization and move ordering.

- **Key Structures:**
  * `diagonal_direction` struct: Models diagonal directions by assigning step deltas (`file_direction`, `rank_direction`) of `1` or `-1`.
  * `movegen_return` struct: Splits moves into `captures_bb` and `quiet_moves_bb` bitmasks to facilitate alpha-beta pruning and early blunder detection.

#### `movegen.c`
- **Role:** Implements dynamic sliding-piece ray-casters and pawn attack/push calculators that depend on live piece occupancies.

- **Key Functions:**
  * `get_straight_moves(const BitBoard *bb, enum Square square)`: Calculates orthogonal sliding rays (Up, Down, Right, Left) from a given square. Iterates step-by-step, appending empty squares to `quiet_moves` and the first blocking piece's square to `capture_moves` before terminating the ray via `break`.
  * `get_diagonal_moves(const BitBoard *bb, enum Square square)`: Calculates diagonal sliding rays across all four cardinal-diagonal vectors (`{{1,1},{1,-1},{-1,1},{-1,-1}}`). Uses boundary-safe `while` loops to advance through empty spaces (`quiet_moves`) and checks the terminal blocking square for potential captures (`capture_moves`).
  * `generate_white_pawn_moves(const BitBoard *bb, enum Square square)`: Generates pseudo-legal moves for a white pawn. Intersects precomputed diagonal attack maps with `bb->black_pieces` and unions them with `bb->en_passant_mask`. Evaluates single-step quiet pushes against `bb->all_pieces` and handles conditional double-pushes from rank 2.
  * Returns a fully populated `movegen_return` struct containing both capture and quiet move bitmasks.

---
=======
* **Role:** Defines structures for categorizing generated moves to assist with search optimization and move ordering.
* **Key Structures:**
  * `diagonal_direction` struct: Models the diagonal direction by assigning `1` or `-1` as values in to its `file_direction` and `rank_direction` in order to represent a diagonal direction.
  * `movegen_return` struct: Splits moves into `captures_bb` and `quiet_moves_bb` bitmasks to facilitate alpha-beta pruning and early blunder detection.

#### `movegen.c`
* **Role:** Implements dynamic sliding-piece attack calculators that depend on live piece occupancies.
* **Key Functions:**
  * `get_straight_moves()`: Generates vertical and horizontal sliding rays, checking for blocking pieces along each file and rank. Returns a `movegen_return` struct.  
  * `get_diagonal_moves()`: Generates diagonal sliding rays in directions accesed from the `diagonal_directions_array` which contains `4` `diagonal_direction` structs inside of it representing all 4 diagonal directions. It also checks for pieces blocking the path and returns a `movegen_return` struct.
>>>>>>> ddd14b31b50e2d65fda27c2e1c037dc97bd8f354

### 4. The Main Function

#### `main.c`
- **Role:** Entry point for execution.

- **Key Logic:**
  * Instantiates the main `BitBoard` struct.
  * Invokes `init_board()` and `print_board()`.
  * Calls all precomputation functions (`init_knight_moves()`, `init_king_moves()`, etc.) to fill global lookup tables before entering the main loop.

---

## Build & Run Instructions

To compile the full project with standard GCC/Clang options:

```bash
gcc -Wall -Wextra main.c board.c precalc.c movegen.c -o chess_engine
./chess_engine
