#include "board.h"
#include "movegen.h"
#include "precalc.h"


int king_is_in_check(BitBoard *bb,enum Square square,int colour)
{
    //Check if colour is white
    if(colour ==0)
    {
        //King is a knight
        if((knight_possible_moves[square] & bb->black_knights) != 0ULL)
        {
            return 1;
        }
        
        //King is a rook or a queen
        if((get_straight_moves(bb, square).captures_bb & bb->black_rooks | bb->black_queens) != 0ULL)
        {
            return 1;
        }

        //King is a bischop or a queen
        if((get_diagonal_moves(bb, square).captures_bb & bb->black_bishops | bb->black_queens) != 0ULL)
        {
            return 1;
        }

        //King is a pawn
        if((white_pawn_possible_attacks[square] & bb->black_pawns) != 0ULL)
        {
            return 1;
        }

        //King is the enemy king
        if((king_possible_moves[square] & bb->black_king) != 0ULL)
        {
            return 1;
        }
        //Return 0 if king not in check
        return 0;
    }

    //Check if colour is black
    if(colour ==1)
    {
        //King is a knight
        if((knight_possible_moves[square] & bb->white_knights) != 0ULL)
        {
            return 1;
        }
        
        //King is a rook or a queen
        if((get_straight_moves(bb, square).captures_bb & bb->white_rooks | bb->white_queens) != 0ULL)
        {
            return 1;
        }

        //King is a bischop or a queen
        if((get_diagonal_moves(bb, square).captures_bb & bb->white_bishops | bb->white_queens) != 0ULL)
        {
            return 1;
        }

        //King is a pawn
        if((black_pawn_possible_attacks[square] & bb->white_pawns) != 0ULL)
        {
            return 1;
        }

        //King is the enemy king
        if((king_possible_moves[square] & bb->white_king) != 0ULL)
        {
            return 1;
        }
        //Return 0 if king not in check
        return 0;
    }
    
}