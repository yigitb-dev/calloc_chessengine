# CHESS BITBOARD DESIGN SYNOPSIS

## 1. Board Mapping (LERF Convention)
* A 64-bit integer (`uint64_t`) maps sequentially from square a1 to h8.
* Bit 0 (LSB) = a1, Bit 7 = h7, Bit 8 = a2, ..., Bit 63 (MSB) = h8.
* Formula: Index = (Rank * 8) + File  [where Rank/File are 0-7]

   Rank 8 | 56 57 58 59 60 61 62 63 (MSB)
   Rank 2 |  8  9 10 11 12 13 14 15
   Rank 1 |  0  1  2  3  4  5  6  7 (LSB)
   ---------------------------------
             a  b  c  d  e  f  g  h

## 2. Core Structures
* Maintain an array of 12 distinct bitboards (one per piece type/color):
  `enum { P, N, B, R, Q, K, p, n, b, r, q, k };`
  `uint64_t pieces[12];`
* Separate pieces are combined using bitwise OR (`|`) into 3 tracking states:
  * White occupancy (P OR N OR B OR R OR Q OR K)
  * Black occupancy (p OR n OR b OR r OR q OR k)
  * Total occupancy (White OR Black)

## 3. Core C Macros
* Get bit:   `#define get_bit(bb, sq) (((bb) >> (sq)) & 1ULL)`
* Set bit:   `#define set_bit(bb, sq) ((bb) |= (1ULL << (sq)))`
* Clear bit: `#define pop_bit(bb, sq) ((bb) &= ~(1ULL << (sq)))`
*(Always use 1ULL suffix to ensure 64-bit shifting operations)*
