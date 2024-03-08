# Red neuronal para obtener los números primos

Este repositorio cuenta con una neurona hecha en python para obtener los pesos y el sesgo 
para que un display de 7 segmentos encienda los leds correspondientes a los nueros primos 
en el rango de 0 a 9.

## config.h
Contiene la configuración necesaria para el PIC16F873A

## lcd
Contiene la configuración para un modulo LCD de 16x2

## main
Contiene la configuracion del puerto C del PIC y mediante los pesos y sesgo obtenidos con el programa de python 
se conprueba si un número es primo, sí lo es el diplay de 7 segmentos se iluminara mostrando el número, el modulo
lcd mustra el mensaje muestra un mensaje si es primo.

## Extras
Para hacer los archivos *.c* y *.h* y compilar se utilizó MPLAB y se puede utilizar algun software de similación de
circuitos para ver el funcionamiento como Proteus
