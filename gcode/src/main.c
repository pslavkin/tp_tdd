#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "uart.h"
#include "parser.h"
#include "pos.h"

char* Uart_L;

int main(int argc, char** argv)
{
   uint16_t i;
   Codes_t C;
   for(i=1;i<argc;i++) {
      Uart_L =argv[i];
      Reset_Pos(&C.Pos);
      Extract_Commands ( &C );
      if(Extract_Info(&C)==XYZ_NUMBERS_VALID)
         printf("Line %d =%s\r\nCommand=%d X=%f Y=%f Z=%f \r\n",i,C.L,C.Command,C.Pos.X,C.Pos.Y,C.Pos.Z);
      else
         printf("Line %d invalid \r\n",i);
   }
}

