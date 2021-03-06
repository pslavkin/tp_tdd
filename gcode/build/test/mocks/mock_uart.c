/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_uart.h"

static const char* CMockString_Give_Next_Line = "Give_Next_Line";

typedef struct _CMOCK_Give_Next_Line_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char* ReturnVal;
  int CallOrder;

} CMOCK_Give_Next_Line_CALL_INSTANCE;

static struct mock_uartInstance
{
  int Give_Next_Line_IgnoreBool;
  char* Give_Next_Line_FinalReturn;
  CMOCK_Give_Next_Line_CALLBACK Give_Next_Line_CallbackFunctionPointer;
  int Give_Next_Line_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Give_Next_Line_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_uart_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.Give_Next_Line_IgnoreBool)
    Mock.Give_Next_Line_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Give_Next_Line);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Give_Next_Line_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Give_Next_Line_CallbackFunctionPointer != NULL)
    Mock.Give_Next_Line_CallInstance = CMOCK_GUTS_NONE;
}

void mock_uart_Init(void)
{
  mock_uart_Destroy();
}

void mock_uart_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.Give_Next_Line_CallbackFunctionPointer = NULL;
  Mock.Give_Next_Line_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

char* Give_Next_Line(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Give_Next_Line_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Give_Next_Line);
  cmock_call_instance = (CMOCK_Give_Next_Line_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Give_Next_Line_CallInstance);
  Mock.Give_Next_Line_CallInstance = CMock_Guts_MemNext(Mock.Give_Next_Line_CallInstance);
  if (Mock.Give_Next_Line_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.Give_Next_Line_FinalReturn;
    Mock.Give_Next_Line_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.Give_Next_Line_CallbackFunctionPointer != NULL)
  {
    return Mock.Give_Next_Line_CallbackFunctionPointer(Mock.Give_Next_Line_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void Give_Next_Line_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, char* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Give_Next_Line_CALL_INSTANCE));
  CMOCK_Give_Next_Line_CALL_INSTANCE* cmock_call_instance = (CMOCK_Give_Next_Line_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Give_Next_Line_CallInstance = CMock_Guts_MemChain(Mock.Give_Next_Line_CallInstance, cmock_guts_index);
  Mock.Give_Next_Line_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.Give_Next_Line_IgnoreBool = (int)1;
}

void Give_Next_Line_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, char* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Give_Next_Line_CALL_INSTANCE));
  CMOCK_Give_Next_Line_CALL_INSTANCE* cmock_call_instance = (CMOCK_Give_Next_Line_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Give_Next_Line_CallInstance = CMock_Guts_MemChain(Mock.Give_Next_Line_CallInstance, cmock_guts_index);
  Mock.Give_Next_Line_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void Give_Next_Line_StubWithCallback(CMOCK_Give_Next_Line_CALLBACK Callback)
{
  Mock.Give_Next_Line_IgnoreBool = (int)0;
  Mock.Give_Next_Line_CallbackFunctionPointer = Callback;
}

