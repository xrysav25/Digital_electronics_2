# Lab 5: Michaela Ryšavá

Link to your `Digital-electronics-2` GitHub repository:

[https://github.com/xrysav25/Digital_electronics_2](https://github.com/xrysav25/Digital_electronics_2)


### 7-segment library

1. In your words, describe the difference between Common Cathode and Common Anode 7-segment display.
   * CC SSD - all catodes are connected together, leds are controlled as "high-active"
   * CA SSD - all anodes are connected together, leds are controlled as "low-active"

2. Code listing with syntax highlighting of two interrupt service routines (`TIMER1_OVF_vect`, `TIMER0_OVF_vect`) from counter application with at least two digits, ie. values from 00 to 59:

```c
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/

 uint_8 x = 0;
 uint_8 y = 0;
ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
    x++; // increment units
    for (y, y<6, y++){
        for (x, x<10, x++){
            
        }
    }
}
```

```c
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect)
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

    // WRITE YOUR CODE HERE

}
```

3. Flowchart figure for function `SEG_clk_2us()` which generates one clock period on `SEG_CLK` pin with a duration of 2&nbsp;us. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![schema5_1.png](schema5_1.png)


### Kitchen alarm

Consider a kitchen alarm with a 7-segment display, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![schema5_2.png](schema5_2.png)
