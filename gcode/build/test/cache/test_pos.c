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

    Reset_Pos();

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.X)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.X))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(15)));

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.Y)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.Y))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(16)));

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((Pos.Z)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((Pos.Z))), (UNITY_FLOAT)((UNITY_FLOAT)((0))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(17)));

}
