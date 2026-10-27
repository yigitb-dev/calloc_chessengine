#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <stdint.h>

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


  uint64_t en_passant_mask; //Is generated per half-move contains pawns that moved 2 squares that turn.
                           //Points to the square behind the pawn in order to make it capturable

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

enum Piece {
  W_PAWN,
  W_ROOK,
  W_KNIGHT,
  W_BISCHOP,
  W_QUEEN,
  W_KING,
  B_PAWN,
  B_ROOK,
  B_KNIGHT,
  B_BISCHOP,
  B_QUEEN,
  B_KING,
  EMPTY
};

enum File { A, B, C, D, E, F, G, H };

static inline void set_bit(uint64_t *bb, enum Square target_sq) {
  *bb |= (1ULL << target_sq);
}

static inline void clear_bit(uint64_t *bb, enum Square target_sq) {
  *bb &= ~(1ULL << target_sq);
}

static inline int square_is_occupied(uint64_t bm, enum Square target_sq) {
  if (((1ULL << target_sq) & (bm)) != 0) {
    return 1;
  }
  return 0;
}

static inline void update_boards(BitBoard *bb) {
  bb->white_pieces = bb->white_pawns | bb->white_rooks | bb->white_knights |
                     bb->white_bishops | bb->white_queens | bb->white_king;
  bb->black_pieces = bb->black_pawns | bb->black_rooks | bb->black_knights |
                     bb->black_bishops | bb->black_queens | bb->black_king;
  bb->all_pieces = bb->white_pieces | bb->black_pieces;
}


static inline enum File get_file(enum Square square) {return (enum File)(square % 8);}
static inline int get_rank(enum Square square) { return (int)(square / 8); }
static inline int get_square(enum File file, int rank) {return (int)(8 * rank + file);}


void init_board(BitBoard *bb);
enum Piece get_piece(const BitBoard *bb, enum Square target_sq);
void print_board(const BitBoard *bb);

#endif
