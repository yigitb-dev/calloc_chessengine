#include "movegen.h"
#include "precalc.h"  
#include "board.h"


diagonal_direction diagonal_directions_array[] = {{1,1},{1,-1},{-1,1},{-1,-1}};


movegen_return get_straight_moves(const BitBoard *bb, enum Square square) {
    int rank = get_rank(square);
    enum File file = get_file(square);
    
    uint64_t quiet_moves = 0x0000000000000000ULL;
    uint64_t capture_moves = 0x0000000000000000ULL;
 

    //Ray Up (Rank + 1 to 7)
    for (int r = rank + 1; r < 8; r++) {
        enum Square target_sq = (enum Square)get_square(file, r);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            capture_moves |= (1ULL << target_sq);
            break; 
        }
        quiet_moves |= (1ULL << target_sq);
    }

    //Ray Down (Rank - 1 down to 0)
    for (int r = rank - 1; r >= 0; r--) {
        enum Square target_sq = (enum Square)get_square(file, r);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            capture_moves |= (1ULL << target_sq);
            break;         }
        quiet_moves |= (1ULL << target_sq);
    }

    //Ray Right (File + 1 to 7)
    for (int f = file + 1; f < 8; f++) {
        enum Square target_sq = (enum Square)get_square((enum File)f, rank);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            capture_moves |= (1ULL << target_sq);
            break;         }
        quiet_moves |= (1ULL << target_sq);
    }

    //Ray Left (File - 1 down to 0)
    for (int f = file - 1; f >= 0; f--) {
        enum Square target_sq = (enum Square)get_square((enum File)f, rank);
        if (square_is_occupied(bb->all_pieces, target_sq)) {
            capture_moves |= (1ULL << target_sq);
            break;         }
        quiet_moves |= (1ULL << target_sq);
    }
    movegen_return return_value =  {capture_moves,quiet_moves};  
    return return_value;
}


movegen_return get_diagonal_moves(const BitBoard *bb, enum Square square) {
    uint64_t quiet_moves = 0x0000000000000000ULL;
    uint64_t capture_moves = 0x0000000000000000ULL;
    int i;
    
    for (i = 0; i < 4; i++) {
        int rank = get_rank(square);
        int file = get_file(square);

        int next_rank = rank + diagonal_directions_array[i].rank_direction;
        int next_file = file + diagonal_directions_array[i].file_direction;

        while (next_rank < 8 && next_rank >= 0 && 
               next_file < 8 && next_file >= 0 && 
               square_is_occupied(bb->all_pieces, get_square(next_file, next_rank)) == 0) 
        {
            rank = next_rank;
            file = next_file;
            enum Square target_sq = (enum Square)get_square(file, rank);
            quiet_moves |= (1ULL << target_sq);

            next_rank = rank + diagonal_directions_array[i].rank_direction;
            next_file = file + diagonal_directions_array[i].file_direction;
        }
        
        if (next_rank < 8 && next_rank >= 0 && 
            next_file < 8 && next_file >= 0 && 
            square_is_occupied(bb->all_pieces, get_square(next_file, next_rank)) == 1) 
        {
            rank = next_rank;
            file = next_file;
            enum Square target_sq = (enum Square)get_square(file, rank);
            capture_moves |= (1ULL << target_sq);
        }
    }

    movegen_return return_value = {capture_moves, quiet_moves}; 
    return return_value;
}


movegen_return generate_white_pawn_moves(const BitBoard *bb,enum Square square)
{
  uint64_t capture_moves = 0x0000000000000000ULL; 
  uint64_t quiet_moves = 0x0000000000000000ULL;

  capture_moves = white_pawn_possible_attacks[square] & bb->black_pieces;
  capture_moves |= bb->en_passant_mask;
  

  int rank = get_rank(square);
  int file = get_file(square);
  enum Square first_square = get_square(file,rank+1);
  enum Square second_square = get_square(file,rank+2);

  
  if(square_is_occupied(bb->all_pieces,first_square) ==0)
  {
    quiet_moves |= (1ULL << first_square);
  }

  if(rank ==2)
  {
    if(square_is_occupied(bb->all_pieces, second_square) ==0)
    {
      quiet_moves |= (1ULL << second_square);
    }
  }

  movegen_return return_value = {capture_moves,quiet_moves};
  return return_value;
}
