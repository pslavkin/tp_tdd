#include "build/temp/_test_uart.c"
#include "mock_uart.h"
#include "unity.h"
#include "cmock.h"


void setUp(void)

{

    char* Test_Line="G1 X10 Y10 Z10";

    Give_Next_Line_CMockExpectAndReturn(12, Test_Line);

}



void tearDown(void)

{

}



void test_Give_Next_Line(void)

{

    char* Line=

              ((void *)0)

                  ;

    Line=Give_Next_Line();

    UnityAssertEqualString((const char*)(("G1 X10 Y10 Z10")), (const char*)((Line)), (

   ((void *)0)

   ), (UNITY_UINT)(23));

}
