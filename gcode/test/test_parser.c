#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "cmock.h"
#include "unity.h"
#include "mock_uart.h"
#include "parser.h"

void setUp(void)
{
    char* Test_Line="G1 X12 Y34 Z56.78";
    Give_Next_Line_ExpectAndReturn ( Test_Line );
}

void tearDown(void)
{
}

void test_Extract_Commands(void)
{
   Codes_t C;
   bool Ans;
   Ans=Extract_Commands(&C);
   TEST_ASSERT_EQUAL_STRING("G1"             ,C.Codes[0]);
   TEST_ASSERT_EQUAL_STRING("X12"            ,C.Codes[1]);
   TEST_ASSERT_EQUAL_STRING("Y34"            ,C.Codes[2]);
   TEST_ASSERT_EQUAL_STRING_MESSAGE("Z56.79" ,C.Codes[3] ,"falla adrede parametro z");
}

