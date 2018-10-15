#ifndef _PARSER_H
#define _PARSER_H

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH    100
#define MAX_CODES_PER_LINE 10
#define MAX_CODE_LENGTH    10

enum ERROR_CODES
{
   TOO_MANY_CODES = -10 ,
   CODE_TOO_LONG        ,
   LINE_TOO_LONG        ,
   LINE_END
};
typedef enum {
   SKIPING=0,
   COPYING
} Parser_State_e;

typedef struct {
   char     Codes[MAX_CODES_PER_LINE][MAX_CODE_LENGTH];
   uint16_t C_Index   ;
   uint8_t  Code_Index;
   char*    L         ;
   uint16_t L_Index   ;
   Parser_State_e S;
} Codes_t;

bool     Extract_Commands ( Codes_t* C         );
int8_t   Init_Parser      ( Codes_t* C,char* L );
int8_t   Parse_Byte       ( Codes_t* C         );

#endif // _PARSER_H
