#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "cmock.h"
#include "unity.h"
#include "mock_uart.h"
#include "parser.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_Extract_Commands_Vector(void)
{
   Codes_t  C;
   int8_t   Ans;
   uint16_t i;
   char* Vector[]= {
      "G1 X1 Y1 Z1 F1.2 - - -",
      "G1 X1 Y1 Z10.1 F1.2 - - - ",
      "G1 X1 Y1 Z1 F1.2 - - - ",
      "G1 X-10.2   Y-1000 Z10.01 F1.2 - - - ",
      "G1 X1 Y1 Z1 F1.2 - - - ",
      "G1 X1 Y1 Z1 F1.2 - - - ",
      "G1 X1.11 Y444441 Z1 F1.2 - - - ",
      "G1 X1 Y1 Z1 F1.2 - - - ",
   };
   char T[10][MAX_CODE_LENGTH+10];
   char Test_Line[MAX_LINE_LENGTH+10];

   for(i=0;i<(sizeof(Vector)/sizeof(Vector[0]));i++) {
      strcpy(Test_Line,Vector[i]);
      Give_Next_Line_ExpectAndReturn ( Test_Line );
      Ans=Extract_Commands(&C);
      sscanf(Vector[i],"%s %s %s %s %s %s %s %s",T[0],T[1],T[2],T[3],T[4],T[5],T[6],T[7]);
      TEST_ASSERT_EQUAL_STRING(T[0],C.Codes[0]);
      TEST_ASSERT_EQUAL_STRING(T[1],C.Codes[1]);
      TEST_ASSERT_EQUAL_STRING(T[2],C.Codes[2]);
      TEST_ASSERT_EQUAL_STRING(T[3],C.Codes[3]);
      TEST_ASSERT_EQUAL_STRING(T[4],C.Codes[4]);
      TEST_ASSERT_EQUAL_STRING(T[5],C.Codes[5]);
      TEST_ASSERT_EQUAL_STRING(T[6],C.Codes[6]);
      TEST_ASSERT_EQUAL_STRING(T[7],C.Codes[7]);
   }

}
void test_Extract_Commands_Max_Line_Length(void)
{
   Codes_t  C;
   int8_t     Ans;
   char Test_Line[MAX_LINE_LENGTH+100];

   strcpy(Test_Line,"linea de mas de max_line_length caracteres                                                                      ");
   Give_Next_Line_ExpectAndReturn ( Test_Line );

   Ans=Extract_Commands(&C);
   TEST_ASSERT_NOT_EQUAL_MESSAGE(TOO_MANY_CODES ,Ans ,"TOO_MANY_CODES");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(CODE_TOO_LONG  ,Ans ,"CODE_TOO_LONG");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(LINE_TOO_LONG  ,Ans ,"LINE_TOO_LONG");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(LINE_END       ,Ans ,"LINE_END");
}

void test_Extract_Commands_Max_Codes_Per_Line(void)
{
   Codes_t  C;
   int8_t     Ans;
   char Test_Line[MAX_LINE_LENGTH+100];

   strcpy(Test_Line,"linea con muchos codigos en una sola linea este codigo y este otro y uno mas");
   Give_Next_Line_ExpectAndReturn ( Test_Line );

   Ans=Extract_Commands(&C);
   TEST_ASSERT_NOT_EQUAL_MESSAGE(TOO_MANY_CODES ,Ans ,"TOO_MANY_CODES");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(CODE_TOO_LONG  ,Ans ,"CODE_TOO_LONG");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(LINE_TOO_LONG  ,Ans ,"LINE_TOO_LONG");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(LINE_END       ,Ans ,"LINE_END");
}

void test_Extract_Commands_Codes_Too_Long(void)
{
   Codes_t  C;
   int8_t     Ans;
   char Test_Line[MAX_LINE_LENGTH+100];

   strcpy(Test_Line,"codigo muyyyyyyyyyyyyyyyyyyyyyyyyyyyyy largo");
   Give_Next_Line_ExpectAndReturn ( Test_Line );

   Ans=Extract_Commands(&C);
   TEST_ASSERT_NOT_EQUAL_MESSAGE(TOO_MANY_CODES ,Ans ,"TOO_MANY_CODES");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(CODE_TOO_LONG  ,Ans ,"CODE_TOO_LONG");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(LINE_TOO_LONG  ,Ans ,"LINE_TOO_LONG");
   TEST_ASSERT_NOT_EQUAL_MESSAGE(LINE_END       ,Ans ,"LINE_END");
}
