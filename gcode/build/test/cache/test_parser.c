#include "build/temp/_test_parser.c"
#include "parser.h"
#include "pos.h"
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

      Give_Next_Line_CMockExpectAndReturn(42, Test_Line);

      Ans=Extract_Commands(&C);

      sscanf(Vector[i],"%s %s %s %s %s %s %s %s",T[0],T[1],T[2],T[3],T[4],T[5],T[6],T[7]);

      UnityAssertEqualString((const char*)((T[0])), (const char*)((C.Codes[0])), (

     ((void *)0)

     ), (UNITY_UINT)(45));

      UnityAssertEqualString((const char*)((T[1])), (const char*)((C.Codes[1])), (

     ((void *)0)

     ), (UNITY_UINT)(46));

      UnityAssertEqualString((const char*)((T[2])), (const char*)((C.Codes[2])), (

     ((void *)0)

     ), (UNITY_UINT)(47));

      UnityAssertEqualString((const char*)((T[3])), (const char*)((C.Codes[3])), (

     ((void *)0)

     ), (UNITY_UINT)(48));

      UnityAssertEqualString((const char*)((T[4])), (const char*)((C.Codes[4])), (

     ((void *)0)

     ), (UNITY_UINT)(49));

      UnityAssertEqualString((const char*)((T[5])), (const char*)((C.Codes[5])), (

     ((void *)0)

     ), (UNITY_UINT)(50));

      UnityAssertEqualString((const char*)((T[6])), (const char*)((C.Codes[6])), (

     ((void *)0)

     ), (UNITY_UINT)(51));

      UnityAssertEqualString((const char*)((T[7])), (const char*)((C.Codes[7])), (

     ((void *)0)

     ), (UNITY_UINT)(52));

   }



}

void test_Extract_Commands_Max_Line_Length(void)

{

   Codes_t C;

   int8_t Ans;

   char Test_Line[]="linea de mas de max_line_length caracteres                                                                      ";

   Give_Next_Line_CMockExpectAndReturn(61, Test_Line);

   Ans=Extract_Commands ( &C );

   UnityAssertEqualNumber((UNITY_INT)((LINE_TOO_LONG)), (UNITY_INT)((Ans)), (("LINE_TOO_LONG")), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}



void test_Extract_Commands_Max_Codes_Per_Line(void)

{

   Codes_t C;

   int8_t Ans;

   char Test_Line[]="linea con muchos codigos en una sola linea este codigo y este otro y uno mas";

   Give_Next_Line_CMockExpectAndReturn(71, Test_Line);

   Ans=Extract_Commands ( &C );

   UnityAssertEqualNumber((UNITY_INT)((TOO_MANY_CODES)), (UNITY_INT)((Ans)), (("TOO_MANY_CODES")), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

}



void test_Extract_Commands_Codes_Too_Long(void)

{

   Codes_t C;

   int8_t Ans;

   char Test_Line[]="codigo muyyyyyyyyyyyyyyyyyyyyyyyyyyyyy largo";

   Give_Next_Line_CMockExpectAndReturn(81, Test_Line);

   Ans=Extract_Commands ( &C );

   UnityAssertEqualNumber((UNITY_INT)((CODE_TOO_LONG)), (UNITY_INT)((Ans)), (("CODE_TOO_LONG")), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

}



void test_Info_Parser_Valid_Codes(void)

{

   Codes_t C;

   int8_t Ans,i;

   struct Test_t {

      char* Line;

      int Expected_Ans;

      char* Error_Msg;

   } Test_Cases[] = {

      {"G0 X1 Y1 Z1" ,G0_COMMAND ,"Error probando G0"},

      {"G1 X1 Y1 Z1" ,G1_COMMAND ,"Error probando G1"},

      {"G2 X1 Y1 Z1" ,INVALID_COMMAND ,"Error probando Invalid command"}

   };



   for(i=0;i<(sizeof(Test_Cases)/sizeof(Test_Cases[0]));i++) {

      Give_Next_Line_CMockExpectAndReturn(101, Test_Cases[i].Line);

      Ans=Extract_Commands ( &C );

      Init_Info_Parser ( &C );

      Ans=Info_Parser ( &C );

      UnityAssertEqualNumber((UNITY_INT)((Test_Cases[i].Expected_Ans)), (UNITY_INT)((Ans)), ((Test_Cases[i].Error_Msg)), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_INT);

   }



}



void test_Extract_Info(void)

{

   Codes_t C;

   int8_t Ans,i;

   struct Test_t {

      char* Line;

      int Expected_Ans;

      char* Error_Msg;

   } Test_Cases[] = {

      {"G0 X1.1 Y2.1 K-4.1234" ,INVALID_XYZ ,"INVALID_XYZ"} ,

      {"G0 X1.1 Y2000.1 Z-4.1234" ,XYZ_NUMBERS_INVALID ,"XYZ_NUMBERS_INVALID"},

      {"G0 X1.1 Y2.1 Z-4.1234" ,XYZ_NUMBERS_VALID ,"XYZ_NUMBERS_VALID"}

   };



   for(i=0;i<(sizeof(Test_Cases)/sizeof(Test_Cases[0]));i++) {

      Give_Next_Line_CMockExpectAndReturn(125, Test_Cases[i].Line);

      Ans=Extract_Commands ( &C );

      Ans=Extract_Info ( &C );

      UnityAssertEqualNumber((UNITY_INT)((Test_Cases[i].Expected_Ans)), (UNITY_INT)((Ans)), ((Test_Cases[i].Error_Msg)), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_INT);

   }



   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((1.1)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((1.1))), (UNITY_FLOAT)((UNITY_FLOAT)((C.Pos.X))), ((("Conversion X"))), (UNITY_UINT)((UNITY_UINT)(131)));

   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((2.1)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((2.1))), (UNITY_FLOAT)((UNITY_FLOAT)((C.Pos.Y))), ((("Conversion X"))), (UNITY_UINT)((UNITY_UINT)(132)));

   UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((-4.1234)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((-4.1234))), (UNITY_FLOAT)((UNITY_FLOAT)((C.Pos.Z))), ((("Conversion X"))), (UNITY_UINT)((UNITY_UINT)(133)));

}
