#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "uart.h"
#include "parser.h"


bool Extract_Commands(Codes_t* C)
{
   int8_t   Ans;
   char*    L;
   L=Give_Next_Line ( );
   Init_Parser ( C,L );
   while((Ans=Parse_Byte(C))==0)
      ;
   return Ans;
}

int8_t Init_Parser(Codes_t* C,char* L)
{
   C->Code_Index = 0;
   C->S          = SKIPING;
   C->L          = L;
   C->L_Index    = 0;
}

bool Inc_L_Index(Codes_t* C)
{
   bool Ans;
   if(C->L_Index<MAX_LINE_LENGTH) {
      C->L_Index++;
      Ans=true;
   }
   else Ans=false;
   return Ans;
}
bool Inc_C_Index(Codes_t* C)
{
   bool Ans;
   if(C->C_Index<MAX_CODE_LENGTH) {
      C->C_Index++;
      Ans=true;
   }
   else Ans=false;
   return Ans;
}
bool Inc_Codes_Index(Codes_t* C)
{
   bool Ans;
   if(C->Code_Index<MAX_CODES_PER_LINE) {
      C->Code_Index++;
      Ans=true;
   }
   else Ans=false;
   return Ans;
}

int8_t Parse_Byte(Codes_t* C)
{
   int8_t Ans=0;
   char B=C->L[C->L_Index];
   switch(C->S) {
      case SKIPING:
         switch(B) {
            case '\0':
               Ans=LINE_END;
               break;
            case ' ':
               if(Inc_L_Index(C)==false)
                  Ans=LINE_TOO_LONG;
               break;
            default:
               C->S       = COPYING;
               C->C_Index = 0;
               if(Inc_Codes_Index(C)==false)
                  Ans=TOO_MANY_CODES;
               break;
         }
         break;
      case COPYING:
         switch(B) {
            case '\0':
               Ans=LINE_END;
               C->Codes[C->Code_Index-1][C->C_Index]='\0';
               break;
            case ' ':
               C->Codes[C->Code_Index-1][C->C_Index]='\0';
               if(Inc_L_Index(C)==false)
                  Ans=LINE_TOO_LONG;
               C->S=SKIPING;
               break;
            default:
               C->Codes[C->Code_Index-1][C->C_Index]=B;
               if(Inc_L_Index(C)==false)
                  Ans=LINE_TOO_LONG;
               if(Inc_C_Index(C)==false)
                  Ans=CODE_TOO_LONG;
               break;
         }
   }
   return Ans;
}

