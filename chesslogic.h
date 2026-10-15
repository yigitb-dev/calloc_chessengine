#ifndef CHESSLOGIC_H
#define CHESSLOGIC_H

#include "board.h"
#include <stdint.h>

// All directions that a knight can jump to
typedef struct {
  int file_offset;
  int rank_offset;
} Offset;
const Offset knight_attack_patterns[] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                         {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

enum File { A, B, C, D, E, F, G, H };

static inline enum File get_file(enum Square square) {
  return (enum File)(square % 8);
}

static inline int get_rank(enum Square square) { return (int)(square / 8); }

static inline int get_square(enum File file, int rank) {
  return (int)(8 * rank + file);
}

#endif
