#include "movegen.h"
#include "precalc.h"  
#include "board.h"
#include <stdint.h>

uint64_t get_rook_moves(const BitBoard *bb, enum Square square) {
    int rank = get_rank(square);
    enum File file = get_file(square);
    
    uint64_t rook_moves = 0x0000000000000000ULL;

    //Ray Up (Rank + 1 to 7)
    for (int r = rank + 1; r < 8; r++) {
        enum Square target_sq = (enum Square)get_square(file, r);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            rook_moves |= (1ULL << target_sq);
            break; 
        }
        rook_moves |= (1ULL << target_sq);
    }

    //Ray Down (Rank - 1 down to 0)
    for (int r = rank - 1; r >= 0; r--) {
        enum Square target_sq = (enum Square)get_square(file, r);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            rook_moves |= (1ULL << target_sq);
            break;         }
        rook_moves |= (1ULL << target_sq);
    }

    //Ray Right (File + 1 to 7)
    for (int f = file + 1; f < 8; f++) {
        enum Square target_sq = (enum Square)get_square((enum File)f, rank);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            rook_moves |= (1ULL << target_sq);
            break;         }
        rook_moves |= (1ULL << target_sq);
    }

    //Ray Left (File - 1 down to 0)
    for (int f = file - 1; f >= 0; f--) {
        enum Square target_sq = (enum Square)get_square((enum File)f, rank);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            rook_moves |= (1ULL << target_sq);
            break;         }
        rook_moves |= (1ULL << target_sq);
    }

    return rook_moves;
}
