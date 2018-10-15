#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "pos.h"


void Reset_Pos(Pos_t* Pos)
{
   Pos->X=0;
   Pos->Y=0;
   Pos->Z=0;
}

bool Validate(float N)
{
   if(N>MIN_PARAM_VALUE && N<MAX_PARAM_VALUE)
      return true;
   else
      return false;
}
bool Validate_XYZ(Pos_t* Pos)
{
   return Validate(Pos->X) && Validate(Pos->Y) && Validate(Pos->Z);
}





