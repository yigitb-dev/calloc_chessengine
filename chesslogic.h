#ifndef CHESSLOGIC_H
#define CHESSLOGIC_H

#include "board.h"
#include <stdint.h>

// All directions that a knight can jump to
const int knight_attack_patterns[] = {15, 17, 10, -6, -15, -17, 6, -8};

enum File { A, B, C, D, E, F, G, H };

static inline enum File get_file(enum Square square) {
  return (enum File)(square % 8);
}

static inline int get_rank(enum Square square) { return (int)(square / 8); }

static inline int get_square(enum File file, int rank)
{
  return (int)(8*rank+file);
}

#endif
