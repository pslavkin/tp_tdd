#ifndef _POS_H
#define _POS_H


typedef struct {
   float X;
   float Y;
   float Z;
} Pos_t;

extern Pos_t Pos;
void Reset_Pos(void);

#endif // _POS_H
