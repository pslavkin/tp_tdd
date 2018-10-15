#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "uart.h"
#include "main.h"

char* Give_Next_Line(void)
{
   //esta funcion esta mockeada pero aqui iran las funciones de lectura de
   //linea completa terminada en null desde una cola circular o desde donde sea
   //
   return Uart_L;
}
