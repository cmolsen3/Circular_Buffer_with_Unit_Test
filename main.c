//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include "CircBuff.h"
#include "utest.h"

void configure_ports();

void main(void)
{
	
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    configure_ports();
    CircBuf test;
    InitializeBuffer(&test,8);
    Success rv;
    rv = overempty(&test);
    int i;
    //Flash LED 1.0 on ERROR
    if(rv == FAIL){
    	while(1){
    		for(i = 0;i < 20000;i++);
    		P1OUT ^= BIT0;
    		for(i = 0;i < 20000;i++);

    	}
    }
    DeleteBuffer(&test);

    while(1);

	
}

void configure_ports(){
	P1DIR |= BIT0;
	P1OUT &= ~BIT0;
}
