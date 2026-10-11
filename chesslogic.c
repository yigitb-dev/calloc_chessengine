#include "chesslogic.h"
#include "board.h"
#include <stdint.h>

// BUG: This doesnt work because the moves get off centered when you are at the
// edge of the board
uint64_t init_knight_moves(enum Square square) {
  int i;
  uint64_t possible_moves = 0x0000000000000000;
  for (i = 0; i < 8; i++) {
    int current_square = square + knight_attack_patterns[i];
    if (current_square >= 0 && current_square < 64) {
      possible_moves |= (1ULL << current_square);
    }
  }
  return possible_moves;
}
