#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
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
   Pos_t Pos;
   Reset_Pos(&Pos);
   TEST_ASSERT_EQUAL_FLOAT(Pos.X,0);
   TEST_ASSERT_EQUAL_FLOAT(Pos.Y,0);
   TEST_ASSERT_EQUAL_FLOAT(Pos.Z,0);
}


void test_Validate_XYZ(void)
{
   bool Ans;
   Pos_t Pos;

   Reset_Pos(&Pos);
   Pos.X = MAX_PARAM_VALUE;
   Ans   = Validate_XYZ ( &Pos      );
   TEST_ASSERT_EQUAL    ( Ans,false );

   Reset_Pos(&Pos);
   Pos.Y = MAX_PARAM_VALUE;
   Ans   = Validate_XYZ ( &Pos      );
   TEST_ASSERT_EQUAL    ( Ans,false );

   Reset_Pos(&Pos);
   Pos.Z = MAX_PARAM_VALUE;
   Ans   = Validate_XYZ ( &Pos      );
   TEST_ASSERT_EQUAL    ( Ans,false );

   Reset_Pos(&Pos);
   Pos.X = MIN_PARAM_VALUE;
   Ans   = Validate_XYZ ( &Pos      );
   TEST_ASSERT_EQUAL    ( Ans,false );

   Reset_Pos(&Pos);
   Pos.Y = MIN_PARAM_VALUE;
   Ans   = Validate_XYZ ( &Pos      );
   TEST_ASSERT_EQUAL    ( Ans,false );

   Reset_Pos(&Pos);
   Pos.Z = MIN_PARAM_VALUE;
   Ans   = Validate_XYZ ( &Pos      );
   TEST_ASSERT_EQUAL    ( Ans,false );

}
