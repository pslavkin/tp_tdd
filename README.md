# tp_tdd
test driven developmen tp para CESE2018 testing de software embebido

PARSER G-CODE
---------------

Lista de requerimientos a probar:

|_| 1) Al iniciar el sistema de coordenadas estara en (0,0,0)
|_| 2) Se recibirán lineas de Gcode de no mas de MAX_LINE_LENGTH terminadas en NULL
|_| 3) Cada código dentro de la linea estará separado por uno o mas espacios
|_| 4) El largo de los códigos no podrá superar MAX_CODE_LENGTH
|_| 5) Una linea no podrá tener mas de MAX_CODES_PER_LINE códigos.
|_| 6) Los comandos posibles serán G0 y G1
|_| 7) Los codigos posibles serán X, Y y Z
|_| 8) Los valores numéricos recibidos como parámetros deberán estar en el rango de MIN_PARAM_VALUE a MAX_PARAM_VALUE pudiendo ser enteros o de punto flotante
|_| 9) Aquella linea invalidada por alguna causa, será descartada y no se tendrá en cuenta.

Ejemplos:

G0 X10 Y10 Z10
G1 X10 Y10
G1 X10.12   Z-0.893



