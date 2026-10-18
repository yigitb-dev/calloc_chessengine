#include "movegen.h"
#include "precalc.c"
#include "board.h"
#include <stdint.h>

//3 funcs: 
//uint54_t get_rook_moves() #To avoid copying logic that is unisome with both colours
//rook_movegen get_white_rook_moves() 
//rook_movegen get_black_rook_moves()
uint64_t get_rook_moves(const BitBoard *bb,enum Square square)
{
    int rank = get_rank(square);
    int i;
    uint64_t vertical_moves = 0x0000000000000000;
    for(i = rank;rank<8;rank++)
    {
        enum File file = get_file(square);
        if(square_is_occupied(bb->all_pieces, square) ==0)
        {
            enum Square new_square = get_square(file, i);
            vertical_moves |= (1ULL << new_square);
        }
    }
}
