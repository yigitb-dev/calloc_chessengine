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
    int i;
    for(i=0;i<8;i++)
    {
        
    }
}
