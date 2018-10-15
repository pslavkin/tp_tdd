#include "build/temp/_test_pos.c"
#include "pos.h"
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

  )), (UNITY_UINT)((UNITY_UINT)(20)));

   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.Y)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.Y))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

  ((void *)0)

  )), (UNITY_UINT)((UNITY_UINT)(21)));

   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.Z)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.Z))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

  ((void *)0)

  )), (UNITY_UINT)((UNITY_UINT)(22)));

}





void test_Validate_XYZ(void)

{

   

  _Bool 

       Ans;

   Pos_t Pos;



   Reset_Pos(&Pos);

   Pos.X = +1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((Ans)), (UNITY_INT)((

  0

  )), (

  ((void *)0)

  ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Y = +1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((Ans)), (UNITY_INT)((

  0

  )), (

  ((void *)0)

  ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Z = +1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((Ans)), (UNITY_INT)((

  0

  )), (

  ((void *)0)

  ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.X = -1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((Ans)), (UNITY_INT)((

  0

  )), (

  ((void *)0)

  ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Y = -1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((Ans)), (UNITY_INT)((

  0

  )), (

  ((void *)0)

  ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);



   Reset_Pos(&Pos);

   Pos.Z = -1000;

   Ans = Validate_XYZ ( &Pos );

   UnityAssertEqualNumber((UNITY_INT)((Ans)), (UNITY_INT)((

  0

  )), (

  ((void *)0)

  ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);



}
