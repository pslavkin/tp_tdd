#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "cmock.h"
#include "unity.h"
#include "mock_uart.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Give_Next_Line(void)
{
    char* Line=NULL;
    char* Test_Line_Uart="G1 X10 Y10 Z10";
    Give_Next_Line_ExpectAndReturn ( Test_Line_Uart );

    Line=Give_Next_Line();
    TEST_ASSERT_EQUAL_STRING       ( "G1 X10 Y10 Z10",Line );
}
