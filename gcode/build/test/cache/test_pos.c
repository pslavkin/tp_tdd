#include "build/temp/_test_pos.c"
#include "pos.h"
#include "parser.h"
#include "mock_uart.h"
#include "unity.h"


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

   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.X)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.X))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

  ((void *)0)

  )), (UNITY_UINT)((UNITY_UINT)(22)));

   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.Y)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.Y))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

  ((void *)0)

  )), (UNITY_UINT)((UNITY_UINT)(23)));

   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.Z)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.Z))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

  ((void *)0)

  )), (UNITY_UINT)((UNITY_UINT)(24)));

}





void test_Validate_XYZ(void)

{

   uint8_t Ans;

   Pos_t Pos;



   Reset_Pos(&Pos);

   Pos.X = +1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((XYZ_NUMBERS_INVALID)), (UNITY_INT)((Ans)), (

  ((void *)0)

  ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Y = +1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((XYZ_NUMBERS_INVALID)), (UNITY_INT)((Ans)), (

  ((void *)0)

  ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Z = +1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((XYZ_NUMBERS_INVALID)), (UNITY_INT)((Ans)), (

  ((void *)0)

  ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.X = -1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((XYZ_NUMBERS_INVALID)), (UNITY_INT)((Ans)), (

  ((void *)0)

  ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Y = -1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((XYZ_NUMBERS_INVALID)), (UNITY_INT)((Ans)), (

  ((void *)0)

  ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Z = -1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((XYZ_NUMBERS_INVALID)), (UNITY_INT)((Ans)), (

  ((void *)0)

  ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);



}
