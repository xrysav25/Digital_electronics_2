/***********************************************************************
 * 
 * Decimal counter with 7-segment output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "segment.h"        // Seven-segment display library for AVR-GCC

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Display decimal counter values on SSD (Seven-segment 
 *           display) when 16-bit Timer/Counter1 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Configure SSD signals
    SEG_init();
    int cnt = 0;
    // Test of SSD: display number '3' at position 0
    SEG_update_shift_regs(0b00001101, 0b00100000);

    // Configure 16-bit Timer/Counter1 for Decimal counter
    // Set the overflow prescaler to 262 ms and enable interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();
    TIM0_overflow_4ms();
    TIM0_overflow_interrupt_enable();


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
        /*switch (cnt)
        {
            case 0:
                SEG_update_shift_regs(0b00000011, 0b00100000);
                break;
            case 1:
                SEG_update_shift_regs(0b10011111, 0b00100000);
                break;
            case 2:
                SEG_update_shift_regs(0b00100101, 0b00100000);
                break;
            case 3:
                SEG_update_shift_regs(0b00001101, 0b00100000);
                break;
            case 4:
                SEG_update_shift_regs(0b10011001, 0b00100000);
                break;
            case 5:
                SEG_update_shift_regs(0b01001001, 0b00100000);
                break;
            case 6:
                SEG_update_shift_regs(0b01000001, 0b00100000);
                break;
            case 7:
                SEG_update_shift_regs(0b00011111, 0b00100000);
                break;
            case 8:
                SEG_update_shift_regs(0b00000001, 0b00100000);
                break;
            case 9:
                SEG_update_shift_regs(0b00011001, 0b00100000);
                break;
        }
        cnt = (cnt+1)%10;
    }*/

    // Will never reach this
    return 0;
}
    
    
/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
 uint_8 x = 0;
 uint_8 y = 0;
 
 ISR(TIMER1_OVF_vect){
    x++; // increment units
    for (y, y<6, y++){
        for (x, x<10, x++){
            
        }
    }    
}   
    
    
/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment decimal counter value and display it on SSD.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    static uint8_t pos = 0;
    if (pos == 0){ 
        SEG_update_shift_regs(x,0;
    }
    else{ 
        SEG_update_shift_regs(y,1); 
    }

    pos++;
    if (pos == 4) pos = 0;
    
}
