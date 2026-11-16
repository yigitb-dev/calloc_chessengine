#ifndef CHESSRULES_H
#define CHESSRULES_H

#include "board.h"
#include "movegen.h"
#include "precalc.h"

int king_is_in_check(BitBoard *bb,enum Square square,int colour);

#endif