#include "unity.h"
#include "pos.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Pos_Reset_At_Init(void)
{
    Reset_Pos();
    TEST_ASSERT_EQUAL_FLOAT(Pos.X,0);
    TEST_ASSERT_EQUAL_FLOAT(Pos.Y,0);
    TEST_ASSERT_EQUAL_FLOAT(Pos.Z,0);
}
