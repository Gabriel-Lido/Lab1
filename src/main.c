/*Gabriel Lido Amaral*/

#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/timer.h"

#define CLOCK_24MHZ 24000000
#define CLOCK_120MHZ 120000000

/*
 * Delay de um segundo aproximadamente
 */
void delay_one_second(){
    SysCtlDelay(8000000);               //Delay de 1 segundo
} 

void main(void){
  
  /*SETUP*/
  uint32_t freq = SysCtlClockFreqSet(SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | 
                                     SYSCTL_CFG_VCO_480 | SYSCTL_XTAL_25MHZ, CLOCK_24MHZ);
    
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D3 = PF4, LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
    
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4); // LEDs D3 e D4 como saída
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, 0); // LEDs D3 e D4 apagados
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

//SysCtlDelay - Laço com 3 instruções
//  1/24Mhz = 40,1nS, 40,1*3= 125nS. 125ns*x = 1  seconds               x = 8M
    
  /*LAÇO*/
  while(1){
 
    delay_one_second();
 
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0); // Acende LED D4
    
    delay_one_second();
    
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0); // Apaga LED D4
  } 
} 