/*
 * File:   mainAsm.s
 * Author: Paul Zwart
 *
 * Created on April 13, 2020, 8:53 PM
 */

  
.global _asmMain
    
_asmMain:
    RCALL _config
    
mainLoop:   
    CLRWDT
    BRA mainLoop
    


_config:
    ;Setup ports
    CLR ANSELB		;All port B pins are digital.
    SETM W0		;Sets reg. W0 to 0xFFFF
    MOV W0, TRISA	;Copies contents of W0 to TRISA, Make PORTA all inputs
    MOV W0, TRISB	;Copies contents of W0 to TRISB, Make PORTB all inputs
    BCLR 0xE11, #5	;RB8-15 are located at 0xE11; Make RB13 (bit #5) an output
    BCLR 0xE11, #4	;RB8-15 are located at 0xE11; Make RB12 (bit #4) an output


    ;Setup system clock
    ;Configure PLL prescaler, PLL postscaler, PLL divisor; FCY = 32MHz (31.25nsec/i)
    MOV #0x2E, W0	;Load W0 with 0x2E
    MOV W0, PLLFBD	;Copy 0x2E to PLLFBD, M=48

    ;N2=2 (PLLPOST = 0), N1=3 (PLLPRE = 1)
    MOV CLKDIV, W1	;Copy contents of CLKDIV to W1
    MOV #0xFF20, W0	;Put 0xFF20 in W0
    AND W1, W0, W0	;AND W1 and W0 and put result in W0; Clears PLLPRE and PLLPOST
    BSET W0, #0		;Set bit #0, PLLPRE = 1
    MOV W0, CLKDIV	;Copy the results to CLKDIV


    ;Setup Timers
    BCLR T1CON, #1	;Clear T1CON bit #1, Set to timer mode
    BCLR T1CON, #6	;Clear T1CON bit #6, Turn off Gated timer mode
    BCLR T1CON, #4	;Clear T1CON bit #4, Prescalar to 1:1 
    BCLR T1CON, #5	;Clear T1CON bit #5, Prescalar to 1:1 
    BSET T1CON, #15	;Set T1CON bit #15, Set Enable the timer
    
    
    ;Setup Interrupts
    BSET INTCON1, #15	;Set the INTCON1 bit #15, disable nested interrupts
    BCLR CORCON, #15	;Clear the CORCON bit #15, enable fixed 13 instruction cycle latency 
    BSET IPC0, #12	;Set the priority of Timer 1 interrupt vector to max (7)
    BSET IPC0, #13
    BSET IPC0, #14
    BCLR IFS0, #3	;Clear the flag for Timer 1 interrupt vector
    BSET IEC0, #3	;Set the IEC0 bit #3, enabling Timer 1 interrupt vector
    
    MOV #0x0200, W0	;Copy value 0x0200 to register W0
    MOV W0, 0x001A	;Copy register W0 to 0x001A
    RETURN

    
;Timer Interrupt Service Routine
 .section *,address(0x0200),code
 .global _timerInterrupt
_timerInterrupt:
    BCLR IFS0, #3	;Clear the flag for Timer 1 interrupt vector
    
    
    
    RETFIE		;Return from interrupt

    
.data
nxtLvl: .byte 0x00
 