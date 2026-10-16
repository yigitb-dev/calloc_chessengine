#include "chesslogic.h"
#include "board.h"
#include <stdint.h>


static const Offset knight_attack_patterns[] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                         {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

uint64_t knight_possible_moves[64];
void init_knight_moves() {
  int i;
  for (i = 0; i < 64; i++) {
    uint64_t possible_moves_from_square = 0x0000000000000000ULL; 
    enum Square current_square = i;
    enum File current_file = get_file(current_square);
    int current_rank = get_rank(current_square);
    int k;
    for(k=0;k<8;k++)
    {
      if(current_file + knight_attack_patterns[k].file_offset>=0 && current_file + knight_attack_patterns[k].file_offset <8 && current_rank +knight_attack_patterns[k].rank_offset >=0 && current_rank+knight_attack_patterns[k].rank_offset<8)
      {
        enum Square target_square = get_square(current_file+knight_attack_patterns[k].file_offset,current_rank+knight_attack_patterns[k].rank_offset)
        possible_moves_from_square |= (1ULL << target_square)
      }
    }

    knight_possible_moves[i] = possible_moves_from_square; 
  }
}
