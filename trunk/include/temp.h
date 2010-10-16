#include <nds.h>

static inline void pixel(int x, int y, int clr)
{   VRAM_A[y*256+x] = clr;    }