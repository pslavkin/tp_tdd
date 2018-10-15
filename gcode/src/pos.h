#ifndef _POS_H
#define _POS_H


#define MIN_PARAM_VALUE -1000
#define MAX_PARAM_VALUE +1000



typedef struct {
   float X;
   float Y;
   float Z;
} Pos_t;

void     Reset_Pos    ( Pos_t* Pos );
bool     Validate_XYZ ( Pos_t* Pos );

#endif // _POS_H
