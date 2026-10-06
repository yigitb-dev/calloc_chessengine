#include <stdint.h>
#include <string.h>

typedef struct {
  uint64_t white_pawns;
  uint64_t white_knights;
  uint64_t white_bishops;
  uint64_t white_rooks;
  uint64_t white_queens;
  uint64_t white_king;

  uint64_t black_pawns;
  uint64_t black_knights;
  uint64_t black_bishops;
  uint64_t black_rooks;
  uint64_t black_queens;
  uint64_t black_king;

  uint64_t white_pieces;
  uint64_t black_pieces;
  uint64_t all_pieces;

} BitBoard;

enum Square {
  A1,
  B1,
  C1,
  D1,
  E1,
  F1,
  G1,
  H1,
  A2,
  B2,
  C2,
  D2,
  E2,
  F2,
  G2,
  H2,
  A3,
  B3,
  C3,
  D3,
  E3,
  F3,
  G3,
  H3,
  A4,
  B4,
  C4,
  D4,
  E4,
  F4,
  G4,
  H4,
  A5,
  B5,
  C5,
  D5,
  E5,
  F5,
  G5,
  H5,
  A6,
  B6,
  C6,
  D6,
  E6,
  F6,
  G6,
  H6,
  A7,
  B7,
  C7,
  D7,
  E7,
  F7,
  G7,
  H7,
  A8,
  B8,
  C8,
  D8,
  E8,
  F8,
  G8,
  H8
};

void init_board(BitBoard *bb) {
  bb->white_pawns = 0x000000000000FF00ULL;
  bb->white_rooks = (1ULL << A1) | (1ULL << H1);
  bb->white_knights = (1ULL << B1) | (1ULL << G1);
  bb->white_bishops = (1ULL << C1) | (1ULL << F1);
  bb->white_queens = (1ULL << D1);
  bb->white_king = (1ULL << E1);

  bb->black_pawns = 0x00FF000000000000ULL;
  bb->black_rooks = (1ULL << A8) | (1ULL << H8);
  bb->black_knights = (1ULL << B8) | (1ULL << G8);
  bb->black_bishops = (1ULL << C8) | (1ULL << F8);
  bb->black_queens = (1ULL << D8);
  bb->black_king = (1ULL << E8);
}
static inline void set_bit(uint64_t *bb, enum Square target_sq) {
  *bb |= (1ULL << target_sq);
}

static inline void clear_bit(uint64_t *bb, enum Square target_sq) {
  *bb &= ~(1ULL << target_sq);
}

static inline int check_square(BitBoard *bb, enum Square target_sq) {
  if (((1ULL << target_sq) & (bb->all_pieces)) != 0) {
    return 1;
  }
  return 0;
}

// ~(1ULL << E2) creates a bitmask where only E2 is 0
// (1ULL << E2) creates a bitmask where only E2 is 1 and the rest is 0
// & is the AND operator | is the OR operator
// Combining ~(1ULL << E2) and the bitboard itself makes E2 0 if it was already
// 1

int main() { return 0; }
