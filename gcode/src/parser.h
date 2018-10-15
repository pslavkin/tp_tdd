#ifndef _PARSER_H
#define _PARSER_H

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include "pos.h"

#define MAX_LINE_LENGTH    100
#define MAX_CODES_PER_LINE 10
#define MAX_CODE_LENGTH    20

enum COMMAND_CODES
{
   G0_COMMAND    = 0 ,
   G1_COMMAND        ,
   INVALID_XYZ,
   VALID_XYZ,
   INVALID_COMMAND
};
enum ERROR_CODES
{
   TOO_MANY_CODES = -10 ,
   CODE_TOO_LONG        ,
   LINE_TOO_LONG        ,
   LINE_END             ,
};
typedef enum {
   SKIPING=0,
   COPYING
} Parser_State_e;

typedef struct {
   char                    Codes[MAX_CODES_PER_LINE][MAX_CODE_LENGTH];
   uint16_t                C_Index   ;
   uint8_t                 Code_Index;
   uint8_t                 Code_Count;
   char*                   L         ;
   uint16_t                L_Index   ;
   enum COMMAND_CODES      Command   ;
   Pos_t                   Pos       ;
   Parser_State_e          S         ;
} Codes_t;

int8_t   Extract_Commands ( Codes_t* C         );
int8_t   Init_Parser      ( Codes_t* C,char* L );
int8_t   Parse_Byte       ( Codes_t* C         );
int8_t   Extract_Info     ( Codes_t* C         );
void     Init_Info_Parser ( Codes_t* C         );
int8_t   Info_Parser      ( Codes_t* C         );
int8_t   XYZ_Parser       ( Codes_t* C         );

#endif // _PARSER_H
