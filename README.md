# Tarea 3: Simulador Gráfico en C++ de Alarma Domiciliaria
En esta tarea buscamos como objetivo principalmente programar en c++ una nueva extensión de la tarea 1 y 2,
el cual simularemos y programaremos las tareas previas pero con varias simplificaciones.

## Compilación y ejecución:

Para cada etapa de Qt se tiene un Code.pro 

### STAGE 1
    Stage1HelpCode.pro
	
### STAGE 2
       Stage2HelpCode.pro
### STAGE 3
        Stage3HelpCode.pro

### STAGE 4
        Stage4HelpCode.pro

### TODAS LAS STAGES

NOTA: 


Para compilar y ejecutar es necesario pasar por parametro ruta de .txt 
"C:/Users/
En caso de hacer la ejecucion sin el _makefile_ se pueden eliminar los archivos _.class_ usando el comando por consola `rm -r *.class` en la carpeta donde se requieran eliminar los archivos.

---
Detalle de las clases:
======================



Clases que se usan en todas las etapas:

-Window.cpp \
-Sensor.cpp\
-Door.cpp


Clases Etapa 1:

-Magneticsensor.cpp 
	
Clases Etapa 2:

-Central.cpp \
-Magneticsensor.cpp 



Clases Etapa 3:

-central.cpp \
-doorview.cpp \
-house.cpp \
-housewindow.cpp \
-Magneticsensor.cpp \
-magneticsensorview.cpp 


Clases Etapa 4:

central.cpp \
door.cpp \
doorview.cpp \
housewindow.cpp \
Magneticsensor.cpp \
Magneticsensorview.cpp \
Windowview.cpp 
