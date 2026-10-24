#ifndef MOVEGEN_H
#define MOVEGEN_H
#include <stdint.h>


typedef struct{
  int file_direction;
  int rank_direction;
}diagonal_direction;





typedef struct
{
 //We will use captures_bb further in the project to detect immediate blunders earlier with alfa beta pruning
    uint64_t captures_bb;
    uint64_t quiet_moves_bb;
}movegen_return;




#endif
