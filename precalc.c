#include "precalc.h"
#include "board.h"
#include <stdint.h>
#include <sys/types.h>



uint64_t knight_possible_moves[64];
void init_knight_moves() {
  
  static const Offset knight_attack_patterns[] = {
  {1, 2},
  {1, -2},
  {-1, 2},
  {-1, -2},
  {2, 1},
  {2, -1},
  {-2, 1},
  {-2, -1}};

  int i;
  for (i = 0; i < 64; i++) {
    uint64_t possible_moves_from_square = 0x0000000000000000ULL;
    enum Square current_square = i;
    enum File current_file = get_file(current_square);
    int current_rank = get_rank(current_square);
    int k;
    for (k = 0; k < 8; k++) {
      if (current_file + knight_attack_patterns[k].file_offset >= 0 &&
          current_file + knight_attack_patterns[k].file_offset < 8 &&
          current_rank + knight_attack_patterns[k].rank_offset >= 0 &&
          current_rank + knight_attack_patterns[k].rank_offset < 8) {
        enum Square target_square = get_square(current_file + knight_attack_patterns[k].file_offset, current_rank + knight_attack_patterns[k].rank_offset);
        possible_moves_from_square |= (1ULL << target_square);
      }
    }
    knight_possible_moves[i] = possible_moves_from_square;
  }
}

uint64_t king_possible_moves[64];
void init_king_moves() 
{
  static const Offset king_attack_patterns[] = {
  {1,-1},
  {1,0},
  {1,1},
  {0,-1},
  {0,1},
  {-1,-1},
  {-1,0},
  {-1,1}
  };


  int i;
  for(i=0;i<64;i++)
  {
    uint64_t possible_moves_from_square = 0x0000000000000000ULL;
    enum Square current_square = i;
    enum File current_file= get_file(current_square);
    int current_rank = get_rank(current_square);

    int k;
    for(k=0;k<8;k++)
    {
      if (current_file + king_attack_patterns[k].file_offset >= 0 &&
          current_file + king_attack_patterns[k].file_offset < 8 &&
          current_rank + king_attack_patterns[k].rank_offset >= 0 &&
          current_rank + king_attack_patterns[k].rank_offset < 8) {
        enum Square target_square = get_square(current_file + king_attack_patterns[k].file_offset, current_rank + king_attack_patterns[k].rank_offset);
        possible_moves_from_square |= (1ULL << target_square);

    }
    king_possible_moves[i] = possible_moves_from_square;
    }
  }
}

//Because pawn pushes act like sliding pieces they cant be precalculated
//Pawn attacks however can be precalculated as they are always the same no matter diffrent occupation cases
uint64_t white_pawn_possible_attacks[64];
void init_white_pawn_attacks()
{
  //                      RULES OF PAWN MOVES                             
  // If rank +1 and File +1 is occupied by opposite colour capture possible
  // If rank -1 and File +1 is occupied by opposite colour capture possible
  static const Offset white_pawn_attack_patterns[] = {{1,1},{1,-1}};
  int i;
  for(i=0;i<64;i++)
  {
    uint64_t possible_moves_from_square = 0x0000000000000000ULL;

    enum Square current_square = i;
    enum File current_file = get_file(current_square);
    int current_rank = get_rank(current_square);
    
    int j;
    for(j=0;j<2;j++)
    {
      enum File target_file = current_file + white_pawn_attack_patterns[j].file_offset;
      int target_rank = current_rank + white_pawn_attack_patterns[j].rank_offset;
      if(target_file>=0 && target_file<8 && target_rank>=0 && target_rank<8)
      {
        enum Square valid_square = get_square(target_file,target_rank);
        possible_moves_from_square |= (1ULL << valid_square);
      }
    }
    white_pawn_possible_attacks[i] = possible_moves_from_square;
  }
}




uint64_t black_pawn_possible_attacks[64];
void init_black_pawn_attacks()
{
  //                      RULES OF PAWN MOVES                             
  // If rank +1 and File -1 is occupied by opposite colour capture possible
  // If rank -1 and File -1 is occupied by opposite colour capture possible
  static const Offset black_pawn_attack_patterns[] = {{-1, 1}, {-1, -1}};
  int i;
  
  for (i = 0; i < 64; i++) {
      uint64_t possible_moves_from_square = 0x0000000000000000ULL;

      enum Square current_square = i;
      enum File current_file = get_file(current_square);
      int current_rank = get_rank(current_square);
      
      int j;
      for (j = 0; j < 2; j++) {
          enum File target_file = current_file + black_pawn_attack_patterns[j].file_offset;
          int target_rank = current_rank + black_pawn_attack_patterns[j].rank_offset;
          
          if (target_file >= 0 && target_file < 8 && target_rank >= 0 && target_rank < 8) {
              enum Square valid_square = (enum Square)get_square(target_file, target_rank);
              possible_moves_from_square |= (1ULL << valid_square);
          }
      }
      black_pawn_possible_attacks[i] = possible_moves_from_square;
  }

}


