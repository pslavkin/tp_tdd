#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "cmock.h"
#include "unity.h"
#include "mock_uart.h"

void setUp(void)
{
    char* Test_Line="G1 X10 Y10 Z10";
    Give_Next_Line_ExpectAndReturn ( Test_Line );
}

void tearDown(void)
{
}

void test_Give_Next_Line(void)
{
    char* Line=NULL;
    Line=Give_Next_Line();
    TEST_ASSERT_EQUAL_STRING       ( "G1 X10 Y10 Z10",Line );
}
