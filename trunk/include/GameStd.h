#pragma once

#include <nds.h>
#include "GameServices.h"
#include "IGameEngine.h"
#include "IGameStateManager.h"
#include "IGameObjectManager.h"
#include "IInputManager.h"

#define STATE_INTRO 0
#define STATE_OPTIONS 1
#define STATE_SETUP 2
#define STATE_PLAY 3
#define STATE_CREDIT 4
#define STATE_PAUSE 5

static inline void pixel(int x, int y, int clr)
{   VRAM_A[y*256+x] = clr;    }