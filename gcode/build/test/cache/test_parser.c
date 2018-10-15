#include "build/temp/_test_parser.c"
#include "parser.h"
#include "mock_uart.h"
#include "unity.h"
#include "cmock.h"


void setUp(void)

{

    char* Test_Line="G1 X12 Y34 Z56.78";

    Give_Next_Line_CMockExpectAndReturn(13, Test_Line);

}



void tearDown(void)

{

}



void test_Extract_Commands(void)

{

   Codes_t C;

   

  _Bool 

       Ans;

   Ans=Extract_Commands(&C);

   UnityAssertEqualString((const char*)(("G1")), (const char*)((C.Codes[0])), (

  ((void *)0)

  ), (UNITY_UINT)(25));

   UnityAssertEqualString((const char*)(("X12")), (const char*)((C.Codes[1])), (

  ((void *)0)

  ), (UNITY_UINT)(26));

   UnityAssertEqualString((const char*)(("Y34")), (const char*)((C.Codes[2])), (

  ((void *)0)

  ), (UNITY_UINT)(27));

   UnityAssertEqualString((const char*)(("Z56.79")), (const char*)((C.Codes[3])), (("falla adrede parametro z")), (UNITY_UINT)(28));

}
