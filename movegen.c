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
    enum File file = get_file(square);
    int i;
    int j;
    int k;
    int l;
    uint64_t vertical_moves = 0x0000000000000000;
    uint64_t horizontal_moves = 0x0000000000000000;
    for(i = rank;rank<8;rank++)
    {
        
        enum Square new_square = get_square(file, i);
        if(square_is_occupied(bb->all_pieces, new_square) ==0)
        {
            vertical_moves |= (1ULL << new_square);
        }

        else {
        break;
        }
    }

    for(j=rank;rank<8;rank--)
    {
        enum Square new_square = get_square(file, j);
        if(square_is_occupied(bb->all_pieces, new_square) ==0)
        {
            vertical_moves |= (1ULL << new_square);
        }

        else {
        break;
        }
    }

    for(k=file;file<8;file++)
    {
        enum Square new_square = get_square(k, rank);
        if(square_is_occupied(bb->all_pieces,new_square) ==0)
        {
            horizontal_moves |= (1ULL << new_square);
        }

        else {
        break;
        }
    }

    return vertical_moves | horizontal_moves;
}
