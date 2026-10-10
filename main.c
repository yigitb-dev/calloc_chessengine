#include "board.h"

// ~(1ULL << E2) creates a bitmask where only E2 is 0
// (1ULL << E2) creates a bitmask where only E2 is 1 and the rest is 0
// & is the AND operator | is the OR operator
// Combining ~(1ULL << E2) and the bitboard itself makes E2 0 if it was already
// 1

int main() { return 0; }
