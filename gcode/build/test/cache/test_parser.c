#include "build/temp/_test_parser.c"
#include "parser.h"
#include "mock_uart.h"
#include "unity.h"
#include "cmock.h"


void setUp(void)

{

}



void tearDown(void)

{

}





void test_Extract_Commands_Vector(void)

{

   Codes_t C;

   int8_t Ans;

   uint16_t i;

   char* Vector[]= {

      "G1 X1 Y1 Z1 F1.2 - - -",

      "G1 X1 Y1 Z10.1 F1.2 - - - ",

      "G1 X1 Y1 Z1 F1.2 - - - ",

      "G1 X-10.2   Y-1000 Z10.01 F1.2 - - - ",

      "G1 X1 Y1 Z1 F1.2 - - - ",

      "G1 X1 Y1 Z1 F1.2 - - - ",

      "G1 X1.11 Y444441 Z1 F1.2 - - - ",

      "G1 X1 Y1 Z1 F1.2 - - - ",

   };

   char T[10][20 +10];

   char Test_Line[100 +10];



   for(i=0;i<(sizeof(Vector)/sizeof(Vector[0]));i++) {

      strcpy(Test_Line,Vector[i]);

      Give_Next_Line_CMockExpectAndReturn(40, Test_Line);

      Ans=Extract_Commands(&C);

      sscanf(Vector[i],"%s %s %s %s %s %s %s %s",T[0],T[1],T[2],T[3],T[4],T[5],T[6],T[7]);

      UnityAssertEqualString((const char*)((T[0])), (const char*)((C.Codes[0])), (

     ((void *)0)

     ), (UNITY_UINT)(43));

      UnityAssertEqualString((const char*)((T[1])), (const char*)((C.Codes[1])), (

     ((void *)0)

     ), (UNITY_UINT)(44));

      UnityAssertEqualString((const char*)((T[2])), (const char*)((C.Codes[2])), (

     ((void *)0)

     ), (UNITY_UINT)(45));

      UnityAssertEqualString((const char*)((T[3])), (const char*)((C.Codes[3])), (

     ((void *)0)

     ), (UNITY_UINT)(46));

      UnityAssertEqualString((const char*)((T[4])), (const char*)((C.Codes[4])), (

     ((void *)0)

     ), (UNITY_UINT)(47));

      UnityAssertEqualString((const char*)((T[5])), (const char*)((C.Codes[5])), (

     ((void *)0)

     ), (UNITY_UINT)(48));

      UnityAssertEqualString((const char*)((T[6])), (const char*)((C.Codes[6])), (

     ((void *)0)

     ), (UNITY_UINT)(49));

      UnityAssertEqualString((const char*)((T[7])), (const char*)((C.Codes[7])), (

     ((void *)0)

     ), (UNITY_UINT)(50));

   }



}

void test_Extract_Commands_Max_Line_Length(void)

{

   Codes_t C;

   int8_t Ans;

   char Test_Line[100 +100];



   strcpy(Test_Line,"linea de mas de max_line_length caracteres                                                                      ");

   Give_Next_Line_CMockExpectAndReturn(61, Test_Line);



   Ans=Extract_Commands(&C);

   if (((TOO_MANY_CODES) != (Ans))) {} else {UnityFail( ((("TOO_MANY_CODES"))), (UNITY_UINT)((UNITY_UINT)(64)));};

   if (((CODE_TOO_LONG) != (Ans))) {} else {UnityFail( ((("CODE_TOO_LONG"))), (UNITY_UINT)((UNITY_UINT)(65)));};

   if (((LINE_TOO_LONG) != (Ans))) {} else {UnityFail( ((("LINE_TOO_LONG"))), (UNITY_UINT)((UNITY_UINT)(66)));};

   if (((LINE_END) != (Ans))) {} else {UnityFail( ((("LINE_END"))), (UNITY_UINT)((UNITY_UINT)(67)));};

}



void test_Extract_Commands_Max_Codes_Per_Line(void)

{

   Codes_t C;

   int8_t Ans;

   char Test_Line[100 +100];



   strcpy(Test_Line,"linea con muchos codigos en una sola linea este codigo y este otro y uno mas");

   Give_Next_Line_CMockExpectAndReturn(77, Test_Line);



   Ans=Extract_Commands(&C);

   if (((TOO_MANY_CODES) != (Ans))) {} else {UnityFail( ((("TOO_MANY_CODES"))), (UNITY_UINT)((UNITY_UINT)(80)));};

   if (((CODE_TOO_LONG) != (Ans))) {} else {UnityFail( ((("CODE_TOO_LONG"))), (UNITY_UINT)((UNITY_UINT)(81)));};

   if (((LINE_TOO_LONG) != (Ans))) {} else {UnityFail( ((("LINE_TOO_LONG"))), (UNITY_UINT)((UNITY_UINT)(82)));};

   if (((LINE_END) != (Ans))) {} else {UnityFail( ((("LINE_END"))), (UNITY_UINT)((UNITY_UINT)(83)));};

}



void test_Extract_Commands_Codes_Too_Long(void)

{

   Codes_t C;

   int8_t Ans;

   char Test_Line[100 +100];



   strcpy(Test_Line,"codigo muyyyyyyyyyyyyyyyyyyyyyyyyyyyyy largo");

   Give_Next_Line_CMockExpectAndReturn(93, Test_Line);



   Ans=Extract_Commands(&C);

   if (((TOO_MANY_CODES) != (Ans))) {} else {UnityFail( ((("TOO_MANY_CODES"))), (UNITY_UINT)((UNITY_UINT)(96)));};

   if (((CODE_TOO_LONG) != (Ans))) {} else {UnityFail( ((("CODE_TOO_LONG"))), (UNITY_UINT)((UNITY_UINT)(97)));};

   if (((LINE_TOO_LONG) != (Ans))) {} else {UnityFail( ((("LINE_TOO_LONG"))), (UNITY_UINT)((UNITY_UINT)(98)));};

   if (((LINE_END) != (Ans))) {} else {UnityFail( ((("LINE_END"))), (UNITY_UINT)((UNITY_UINT)(99)));};

}
