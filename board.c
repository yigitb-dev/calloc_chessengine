#include "board.h"
#include <stdio.h>

// Because we also store our derived bb's like black_pieces white_pieces and
// all_pieces we must remember to update the struct manually
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

enum Piece get_piece(const BitBoard *bb, enum Square target_sq) {

  if (square_is_occupied(bb->all_pieces, target_sq)) {

    if (square_is_occupied(bb->white_pieces, target_sq)) {
      if (square_is_occupied(bb->white_pawns, target_sq))
        return W_PAWN;
      if (square_is_occupied(bb->white_knights, target_sq))
        return W_KNIGHT;
      if (square_is_occupied(bb->white_bishops, target_sq))
        return W_BISCHOP;
      if (square_is_occupied(bb->white_rooks, target_sq))
        return W_ROOK;
      if (square_is_occupied(bb->white_queens, target_sq))
        return W_QUEEN;
      if (square_is_occupied(bb->white_king, target_sq))
        return W_KING;
    }

    else {
      if (square_is_occupied(bb->black_pawns, target_sq))
        return B_PAWN;
      if (square_is_occupied(bb->black_knights, target_sq))
        return B_KNIGHT;
      if (square_is_occupied(bb->black_bishops, target_sq))
        return B_BISCHOP;
      if (square_is_occupied(bb->black_rooks, target_sq))
        return B_ROOK;
      if (square_is_occupied(bb->black_queens, target_sq))
        return B_QUEEN;
      if (square_is_occupied(bb->black_king, target_sq))
        return B_KING;
    }
  }

  return EMPTY;
}

void print_board(const BitBoard *bb) {
  const char *piece_symbols[] = {
      "WP", "WR", "WN", "WB", "WQ", "WK", // White pieces
      "BP", "BR", "BN", "BB", "BQ", "BK", // Black pieces
      "x"                                 // EMPTY square
  };

  printf("\n  +------------------------+\n");

  for (int rank = 7; rank >= 0; rank--) {
    printf("%d | ", rank + 1); // Print rank number (1-8)

    for (int file = 0; file < 8; file++) {
      enum Square sq = rank * 8 + file;
      enum Piece p = get_piece(bb, sq);

      printf("%s ", piece_symbols[p]);
    }
    printf("|\n");
  }

  printf("  +------------------------+\n");
  printf("    A  B  C  D  E  F  G  H  \n\n");
}
