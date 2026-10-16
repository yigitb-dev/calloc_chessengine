#include "board.h"
#include "precalc.h"

// ~(1ULL << E2) creates a bitmask where only E2 is 0
// (1ULL << E2) creates a bitmask where only E2 is 1 and the rest is 0
// & is the AND operator | is the OR operator
// Combining ~(1ULL << E2) and the bitboard itself makes E2 0 if it was already
// 1

int main() {
  BitBoard bb;

  init_board(&bb);
  print_board(&bb);

  // Precalculate non-sliding pieces' moves for maximum efficiency
  init_knight_moves();
  init_king_moves();
  init_white_pawn_attacks();
  init_black_pawn_attacks();

  return 0;
}
