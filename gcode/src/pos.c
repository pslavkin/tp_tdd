#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "pos.h"


Pos_t Pos;

void Reset_Pos(void)
{
   Pos.X=0;
   Pos.Y=0;
   Pos.Z=0;
}

