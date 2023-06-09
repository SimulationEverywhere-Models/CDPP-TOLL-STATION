TRABAJO PRACTICO N 1

GRUPO 1

IMPLEMENTACION "CARRIL" FORMALISMO DEVS


ARCHIVOS DE LA IMPLEMENTACION

barrera.h: header C++ del modelo atómico BARRERA
barrera.cpp: código fuente en C++ del modelo atómico BARRERA
sensor.h: header C++ del modelo atómico SENSOR
sensor.cpp: código fuente en C++ del modelo atómico SENSOR
cajero.h: header C++ del modelo atómico CAJERO
cajero.cpp: código fuente en C++ del modelo atómico CAJERO
timer.h: header C++ del modelo atómico TIMER
timer.cpp: código fuente en C++ del modelo atómico TIMER
genautos.h: header C++ del modelo atómico GENAUTOS
genautos.cpp: código fuente en C++ del modelo atómico GENAUTOS
genpago.h: header C++ del modelo atómico GENPAGO
genpago.cpp: código fuente en C++ del modelo atómico GENPAGO
control.h: header C++ del modelo atómico CONTROL
control.cpp: código fuente en C++ del modelo atómico CONTROL
cola.h: header C++ del modelo atómico COLA
cola.cpp: código fuente en C++ del modelo atómico COLA
lector.h: header C++ del modelo atómico LECTOR
lector.cpp: código fuente en C++ del modelo atómico LECTOR


ARCHIVOS DE LA HERRAMIENTA CD++

register.cpp: archivo que registra los modelos atómicos en el simulador
makefile: directivas de compilación


ARCHIVOS DE PRUEBA

barrera.ma: definición del modelo acoplado conformado unicamente por BARRERA para el ejemplo 1 de BARRERA
sensor.ma: definición del modelo acoplado conformado unicamente por SENSOR para el ejemplo 1 de SENSOR
cajero1.ma. definición de modelos acoplados conformado unicamente por CAJERO para el ejemplo 1 de CAJERO
cajero2.ma: definición de modelos acoplados conformado unicamente por CAJERO para el ejemplo 2 de CAJERO
timer.ma: definición del modelo acoplado conformado unicamente por TIMER para el ejemplo 1 de TIMER
genautos.ma: definición del modelo acoplado conformado unicamente por GENAUTOS para el ejemplo 1 de GENAUTOS
genpago.ma: definición del modelo acoplado conformado unicamente por GENPAGO para el ejemplo 1 de GENPAGO
control.ma: definición del modelo acoplado conformado unicamente por CONTROL para el ejemplo 1 de CONTROL
cola.ma: definición del modelo acoplado conformado unicamente por COLA para el ejemplo 1 de COLA
lector.ma: definición del modelo acoplado conformado unicamente por LECTOR para el ejemplo 1 de LECTOR
carril1.ma: definición del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 1 de CARRIL
carril2.ma: definición del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 2 de CARRIL
carril3.ma: definición del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 3 de CARRIL
carril4.ma: definición del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 4 de CARRIL
carril5.ma: definición del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 5 de CARRIL

barrera.dat: archivo de eventos de entrada para el ejemplo 1 de BARRERA
sensor.dat: archivo de eventos de entrada para el ejemplo 1 de SENSOR
cajero1.dat: archivo de eventos de entrada para el ejemplo 1 de CAJERO
cajero2.dat: archivo de eventos de entrada para el ejemplo 2 de CAJERO
genpago.dat: archivo de eventos de entrada para el ejemplo 1 de GENPAGO
control.dat: archivo de eventos de entrada para el ejemplo 1 de CONTROL
cola1.dat: archivo de eventos de entrada para el ejemplo 1 de COLA
cola2.dat: archivo de eventos de entrada para el ejemplo 2 de COLA
lector.dat: archivo de eventos de entrada para el ejemplo 1 de LECTOR
carril1.dat: archivo de eventos de entrada para el ejemplo 1 de CARRIL
carril2.dat: archivo de eventos de entrada para el ejemplo 2 de CARRIL
carril3.dat: archivo de eventos de entrada para el ejemplo 3 de CARRIL

barrera.out: archivo de salida de la simulación del ejemplo 1 de BARRERA
sensor.out: archivo de salida de la simulación del ejemplo 1 de SENSOR
cajero1.out: archivo de salida de la simulación del ejemplo 1 de CAJERO
cajero2.out: archivo de salida de la simulación del ejemplo 2 de CAJERO
timer.out: archivo de salida de la simulación del ejemplo 1 de TIMER
genautos.out: archivo de salida de la simulación del ejemplo 1 de GENAUTOS
genpago.out: archivo de salida de la simulación del ejemplo 1 de GENPAGO
control.out: archivo de salida de la simulación del ejemplo 1 de CONTROL
cola1.out: archivo de salida de la simulación del ejemplo 1 de COLA
cola2.out: archivo de salida de la simulación del ejemplo 2 de COLA
lector.out: archivo de salida de la simulación del ejemplo 1 de LECTOR
carril1.out: archivo de salida de la simulación del ejemplo 1 de CARRIL
carril2.out: archivo de salida de la simulación del ejemplo 2 de CARRIL
carril3.out: archivo de salida de la simulación del ejemplo 3 de CARRIL
carril4.out: archivo de salida de la simulación del ejemplo 4 de CARRIL
carril5.out: archivo de salida de la simulación del ejemplo 5 de CARRIL

loginfo1.txt: log generado por la simulación del ejemplo 1 de CARRIL
loginfo2.txt: log generado por la simulación del ejemplo 2 de CARRIL
loginfo3.txt: log generado por la simulación del ejemplo 3 de CARRIL
loginfo4.txt: log generado por la simulación del ejemplo 4 de CARRIL
loginfo5.txt: log generado por la simulación del ejemplo 5 de CARRIL

monedas.txt: archivo con las posibles secuencias de monedas


ARCHIVOS ADICIONALES:

informe.doc: informe del trabajo práctico

modelo acoplado carril.pps: presentación con gráfico del modelo acoplado CARRIL


LINEA DE COMANDOS PARA LA EJECUCION DE LOS EJEMPLOS

Ejemplo 1 de BARRERA:   ./simu -mbarrera.ma -ebarrera.dat -obarrera.out
Ejemplo 1 de SENSOR:    ./simu -msensor.ma -esensor.dat -osensor.out
Ejemplo 1 de CAJERO:    ./simu -mcajero1.ma -ecajero1.dat -ocajero1.out
Ejemplo 2 de CAJERO:    ./simu -mcajero2.ma -ecajero2.dat -ocajero2.out
Ejemplo 1 de TIMER:     ./simu -mtimer.ma -otimer.out -t10:00:00:00
Ejemplo 1 de GENAUTOS:  ./simu -mgenautos.ma -ogenautos.out -t10:00:00:00
Ejemplo 1 de GENPAGO:   ./simu -mgenpago.ma -egenpago.dat -ogenpago.out
Ejemplo 1 de CONTROL:   ./simu -mcontrol.ma -econtrol.dat -ocontrol.out
Ejemplo 1 de COLA:      ./simu -mcola.ma -ecola1.dat -ocola1.out
Ejemplo 2 de COLA:      ./simu -mcola.ma -ecola2.dat -ocola2.out
Ejemplo 1 de LECTOR:    ./simu -mlector.ma -elector.dat -olector.out
Ejemplo 1 de CARRIL:    ./simu -mcarril1.ma -ecarril1.dat -ocarril1.out -t01:00:00:00
Ejemplo 2 de CARRIL:    ./simu -mcarril2.ma -ecarril2.dat -ocarril2.out -t01:00:00:00
Ejemplo 3 de CARRIL:    ./simu -mcarril3.ma -ecarril3.dat -ocarril3.out -t01:00:00:00
Ejemplo 4 de CARRIL:    ./simu -mcarril4.ma -ocarril4.out -t05:00:00:00
Ejemplo 5 de CARRIL:    ./simu -mcarril5.ma -ocarril5.out -t05:00:00:00








