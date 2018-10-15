# tp_tdd
test driven developmen tp para CESE2018 testing de software embebido

PARSER G-CODE
---------------

Lista de requerimientos a probar:

|X| 1) Al iniciar el sistema de coordenadas estara en (0,0,0)
|X| 2) Se recibirán lineas de Gcode de no mas de MAX_LINE_LENGTH terminadas en NULL
|X| 3) Cada código dentro de la linea estará separado por uno o mas espacios
|X| 4) El largo de los códigos no podrá superar MAX_CODE_LENGTH
|X| 5) Una linea no podrá tener mas de MAX_CODES_PER_LINE códigos.
|X| 6) Los comandos posibles serán G0 y G1
|X| 7) Los codigos posibles serán X, Y y Z
|X| 8) Los valores numéricos recibidos como parámetros deberán estar en el rango de MIN_PARAM_VALUE a MAX_PARAM_VALUE pudiendo ser enteros o de punto flotante
|X| 9) Aquella linea invalidada por alguna causa, será descartada y no se tendrá en cuenta.

Ejemplos:

G0 X10 Y10 Z10
G1 X10 Y10
G1 X10.12   Z-0.893


Se agrega un main para probar tambien. Se deja un ejemplo de ejecucion en donde
se esperan n lineas de Gcode como parametros a la linea de comandos:

./exe/tdd "G0 X21 Y32 Z41" "G1 X1.1 Y2.2 Z.3" "G1 Y10000" "G1 Y1.1"

y el restultado es:

   Line 1 =G0 X21 Y32 Z41
   Command=0 X=21.000000 Y=32.000000 Z=41.000000 
   Line 2 =G1 X1.1 Y2.2 Z.3
   Command=1 X=1.100000 Y=2.200000 Z=0.300000 
   Line 3 invalid 
   Line 4 =G1 Y1.1
   Command=1 X=0.000000 Y=1.100000 Z=0.000000 





