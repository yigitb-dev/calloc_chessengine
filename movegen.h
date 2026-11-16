#ifndef MOVEGEN_H
#define MOVEGEN_H

#include <stdint.h>
#include "board.h"

typedef struct {
    int file_direction;
    int rank_direction;
} diagonal_direction;

typedef struct {
    // We will use captures_bb further in the project to detect immediate blunders earlier with alpha-beta pruning
    uint64_t captures_bb;
    uint64_t quiet_moves_bb;
} movegen_return;

movegen_return get_straight_moves(const BitBoard *bb, enum Square square);
movegen_return get_diagonal_moves(const BitBoard *bb, enum Square square);
movegen_return generate_black_pawn_moves(const BitBoard *bb, enum Square square);
movegen_return generate_white_pawn_moves(const BitBoard *bb, enum Square square);

static inline movegen_return get_queen_moves(const BitBoard *bb, enum Square square)
{
    movegen_return straight = get_straight_moves(bb, square);
    movegen_return diagonal = get_diagonal_moves(bb, square);

    return (movegen_return){
        straight.captures_bb | diagonal.captures_bb,
        straight.quiet_moves_bb | diagonal.quiet_moves_bb
    };
}


#endif