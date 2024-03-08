/*
 * File:   main.c
 * Author: sasum
 *
 * Created on 21 de febrero de 2023, 12:35 PM
 */


#include "config.h"
#include "lcd.h"

int hardlim(float value){
    int n;
    if (value>0){
        n= 1;
    }
    else {
        n= 0;
    }
    return n;
}
void main (){
    ADCON1= 0B00000111; // DESHABILITAMOS EL ADC
    TRISB= 0X00; // CONFIGURAMOS PINES DIGITALES DE PUERTO B 
    TRISC= 0XFF; //CONFIGUTAMOS PINES DE PUERTO C COMO ENTRADAS
    
    lcd_init();
    lcd_clear();
    lcd_gotoxy(1,1);
    lcd_putc("Mayor que 5: ");
    
    float W[7] = {19.32406224, 1.23181204, 5.52789562, -17.25684751, 4.27815147, 3.70164668, 10.07996182};
    float b = -21.90102331;
    
    while (1){
        float sum = 0;
        int perceptron = 0;
        
        if (PORTCbits.RC0== 1){
            sum += W[0];
        }
        
        if(PORTCbits.RC1==1){
            sum += W[1];
        }
        
        if(PORTCbits.RC2==1){
            sum += W[2];
        }
        
        if(PORTCbits.RC3==1){
            sum += W[3];
        }
        
        if(PORTCbits.RC4==1){
            sum += W[4];
        }
        
        if(PORTCbits.RC5==1){
            sum += W[5];
        }
        
        if(PORTCbits.RC6==1){
            sum += W[6];
        }
        
        perceptron = hardlim(sum+b);
        
        if(perceptron == 1){
            lcd_gotoxy(2,1);
            lcd_putc("SI");
        }
        
        else{
            lcd_gotoxy(2,1);
            lcd_putc("NO");
        }
        //lcd_clear();
    }
}
