TRABAJO PRACTICO N 1

GRUPO 1

IMPLEMENTACION "CARRIL" FORMALISMO DEVS


ARCHIVOS DE LA IMPLEMENTACION

barrera.h: header C++ del modelo at�mico BARRERA
barrera.cpp: c�digo fuente en C++ del modelo at�mico BARRERA
sensor.h: header C++ del modelo at�mico SENSOR
sensor.cpp: c�digo fuente en C++ del modelo at�mico SENSOR
cajero.h: header C++ del modelo at�mico CAJERO
cajero.cpp: c�digo fuente en C++ del modelo at�mico CAJERO
timer.h: header C++ del modelo at�mico TIMER
timer.cpp: c�digo fuente en C++ del modelo at�mico TIMER
genautos.h: header C++ del modelo at�mico GENAUTOS
genautos.cpp: c�digo fuente en C++ del modelo at�mico GENAUTOS
genpago.h: header C++ del modelo at�mico GENPAGO
genpago.cpp: c�digo fuente en C++ del modelo at�mico GENPAGO
control.h: header C++ del modelo at�mico CONTROL
control.cpp: c�digo fuente en C++ del modelo at�mico CONTROL
cola.h: header C++ del modelo at�mico COLA
cola.cpp: c�digo fuente en C++ del modelo at�mico COLA
lector.h: header C++ del modelo at�mico LECTOR
lector.cpp: c�digo fuente en C++ del modelo at�mico LECTOR


ARCHIVOS DE LA HERRAMIENTA CD++

register.cpp: archivo que registra los modelos at�micos en el simulador
makefile: directivas de compilaci�n


ARCHIVOS DE PRUEBA

barrera.ma: definici�n del modelo acoplado conformado unicamente por BARRERA para el ejemplo 1 de BARRERA
sensor.ma: definici�n del modelo acoplado conformado unicamente por SENSOR para el ejemplo 1 de SENSOR
cajero1.ma. definici�n de modelos acoplados conformado unicamente por CAJERO para el ejemplo 1 de CAJERO
cajero2.ma: definici�n de modelos acoplados conformado unicamente por CAJERO para el ejemplo 2 de CAJERO
timer.ma: definici�n del modelo acoplado conformado unicamente por TIMER para el ejemplo 1 de TIMER
genautos.ma: definici�n del modelo acoplado conformado unicamente por GENAUTOS para el ejemplo 1 de GENAUTOS
genpago.ma: definici�n del modelo acoplado conformado unicamente por GENPAGO para el ejemplo 1 de GENPAGO
control.ma: definici�n del modelo acoplado conformado unicamente por CONTROL para el ejemplo 1 de CONTROL
cola.ma: definici�n del modelo acoplado conformado unicamente por COLA para el ejemplo 1 de COLA
lector.ma: definici�n del modelo acoplado conformado unicamente por LECTOR para el ejemplo 1 de LECTOR
carril1.ma: definici�n del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 1 de CARRIL
carril2.ma: definici�n del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 2 de CARRIL
carril3.ma: definici�n del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 3 de CARRIL
carril4.ma: definici�n del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 4 de CARRIL
carril5.ma: definici�n del modelo acoplado conformado por BARERA, SENSOR, CAJERO, TIMER, GENAUTOS, GENPAGO, CONTROL, COLA y LECTOR para el ejemplo 5 de CARRIL

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

barrera.out: archivo de salida de la simulaci�n del ejemplo 1 de BARRERA
sensor.out: archivo de salida de la simulaci�n del ejemplo 1 de SENSOR
cajero1.out: archivo de salida de la simulaci�n del ejemplo 1 de CAJERO
cajero2.out: archivo de salida de la simulaci�n del ejemplo 2 de CAJERO
timer.out: archivo de salida de la simulaci�n del ejemplo 1 de TIMER
genautos.out: archivo de salida de la simulaci�n del ejemplo 1 de GENAUTOS
genpago.out: archivo de salida de la simulaci�n del ejemplo 1 de GENPAGO
control.out: archivo de salida de la simulaci�n del ejemplo 1 de CONTROL
cola1.out: archivo de salida de la simulaci�n del ejemplo 1 de COLA
cola2.out: archivo de salida de la simulaci�n del ejemplo 2 de COLA
lector.out: archivo de salida de la simulaci�n del ejemplo 1 de LECTOR
carril1.out: archivo de salida de la simulaci�n del ejemplo 1 de CARRIL
carril2.out: archivo de salida de la simulaci�n del ejemplo 2 de CARRIL
carril3.out: archivo de salida de la simulaci�n del ejemplo 3 de CARRIL
carril4.out: archivo de salida de la simulaci�n del ejemplo 4 de CARRIL
carril5.out: archivo de salida de la simulaci�n del ejemplo 5 de CARRIL

loginfo1.txt: log generado por la simulaci�n del ejemplo 1 de CARRIL
loginfo2.txt: log generado por la simulaci�n del ejemplo 2 de CARRIL
loginfo3.txt: log generado por la simulaci�n del ejemplo 3 de CARRIL
loginfo4.txt: log generado por la simulaci�n del ejemplo 4 de CARRIL
loginfo5.txt: log generado por la simulaci�n del ejemplo 5 de CARRIL

monedas.txt: archivo con las posibles secuencias de monedas


ARCHIVOS ADICIONALES:

informe.doc: informe del trabajo pr�ctico

modelo acoplado carril.pps: presentaci�n con gr�fico del modelo acoplado CARRIL


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








