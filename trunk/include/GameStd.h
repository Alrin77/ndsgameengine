#pragma once

#include <nds.h>
#include "GameServices.h"
#include "IGameEngine.h"
#include "IGameStateManager.h"
#include "IGameObjectManager.h"

static inline void pixel(int x, int y, int clr)
{   VRAM_A[y*256+x] = clr;    }