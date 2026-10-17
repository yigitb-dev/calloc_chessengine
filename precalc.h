#ifndef PRECALC_H
#define PRECALC_H

#include "board.h"
#include <stdint.h>

// All directions that a knight can jump to
typedef struct {
  int file_offset;
  int rank_offset;
} Offset;

extern uint64_t knight_possible_moves[64];
extern uint64_t king_possible_moves[64];
extern uint64_t white_pawn_possible_attacks[64];
extern uint64_t black_pawn_possible_attacks[64];


void init_knight_moves();
void init_king_moves();
void init_white_pawn_attacks();
void init_black_pawn_attacks();

#endif
