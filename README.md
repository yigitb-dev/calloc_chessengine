# Calloc Chess Engine

A lightweight chess engine written from scratch in **100% pure C** (C99), completely free of C++ or Object-Oriented Programming abstractions. Built with a data-oriented architecture designed specifically for low-level bitboard manipulation, fast attack lookups, and future integration with minimax search and alpha-beta pruning.

## Project Structure

```
chess_engine/
├── board.h            # Core data structures, enums (Square, Piece), and bitwise inline helpers
├── board.c            # Board initialization, occupancy recalculation, and ASCII printing
├── precalc.h       # Prototypes for attack tables and piece movement rules
├── precalc.c       # Precomputation routines and move generation logic
├── evaluation.h       # Prototypes for board and position scoring
├── evaluation.c       # Material and positional evaluation metrics
└── main.c             # Engine entry point and testing loop

```

## Development Roadmap

1. **Phase 1: Board Representation & State**  *(Completed)*

   * Bitboard struct layout, individual piece boards, aggregate occupancies, and ASCII printing.

2. **Phase 2: Non-Sliding Piece Logic & Precomputation**  *(Completed)*

   * Coordinate-based precomputed attack generation for knights and kings.

3. **Phase 3: Pawn Movement & Captures** *(Active)*

   * Single/double pushes, color-specific directional shifts, and diagonal captures.

4. **Phase 4: Sliding Pieces & Move Execution** *(Upcoming)*

   * Dynamic move generation for rooks, bishops, and queens, paired with a robust `make_move()` / `unmake_move()` pipeline.

5. **Phase 5 and further: Search & Evaluation** *(Future)*

   * Material/positional evaluation, Minimax search trees, Alpha-Beta pruning and Universal chess interface(UCI) support.
   * All these things will probably have their own phase as they are complex concepts to implement.

## License

This project is open-source and available under the MIT License.
