# Calloc Chess Engine

A high-performance, lightweight chess engine written from scratch in **100% pure C** (C99), completely free of C++ or Object-Oriented Programming abstractions. Built with a data-oriented architecture designed specifically for low-level bitboard manipulation, fast attack lookups, and future integration with minimax search and alpha-beta pruning.

## Key Architectural Principles

* **100% Pure C Codebase:** Designed to maintain a pristine, clean language overview on GitHub without C++ or mixed-paradigm pollution.

* **Data-Oriented Bitboard Design:** Utilizes `uint64_t` bitmasks to represent piece sets and board states, enabling ultra-fast bulk operations and shift logic.

* **Strict Separation of Concerns:**

  * **State & Storage (`board.c` / `board.h`):** Handles core bitboards, aggregate occupancy updates (`all_pieces`, `white_pieces`, `black_pieces`), and ASCII board visualization.

  * **Rules & Logic (`chesslogic.c` / `chesslogic.h`):** Precomputes and evaluates piece attack tables and move generation.

  * **Evaluation (`evaluation.c` / `evaluation.h`):** Dedicated future space for material counting and board scoring.

* **Precomputed Attack Tables:** Employs coordinate-safe startup initialization loops for non-sliding pieces (knights, kings) to completely eliminate board-wrapping bugs and runtime overhead.

## Project Structure

```
chess_engine/
├── board.h            # Core data structures, enums (Square, Piece), and bitwise inline helpers
├── board.c            # Board initialization, occupancy recalculation, and ASCII printing
├── chesslogic.h       # Prototypes for attack tables and piece movement rules
├── chesslogic.c       # Precomputation routines and move generation logic
├── evaluation.h       # Prototypes for board and position scoring
├── evaluation.c       # Material and positional evaluation metrics
└── main.c             # Engine entry point and testing loop

```

##  Compilation and Execution

To compile the engine together with all modular `.c` source files using GCC or Clang:

```
gcc main.c board.c chesslogic.c evaluation.c -o chess_engine

```

> **Note:** Do not pass header (`.h`) files directly to the compiler command; they are automatically linked via `#include` directives.

### Running the Executable:

* **Linux / macOS:**

  ```
  ./chess_engine
  
  ```

* **Windows (Command Prompt / PowerShell):**

  ```
  .\chess_engine.exe
  
  ```

## Development Roadmap

1. **Phase 1: Board Representation & State**  *(Completed)*

   * Bitboard struct layout, individual piece boards, aggregate occupancies, and ASCII printing.

2. **Phase 2: Non-Sliding Piece Logic & Precomputation**  *(Active)*

   * Coordinate-based precomputed attack generation for knights and kings.

3. **Phase 3: Pawn Movement & Captures** *(Upcoming)*

   * Single/double pushes, color-specific directional shifts, and diagonal captures.

4. **Phase 4: Sliding Pieces & Move Execution** *(Planned)*

   * Dynamic move generation for rooks, bishops, and queens, paired with a robust `make_move()` / `unmake_move()` pipeline.

5. **Phase 5: Search & Evaluation** *(Future)*

   * Material/positional evaluation, Minimax search trees, and Alpha-Beta pruning.

## License

This project is open-source and available under the MIT License.
