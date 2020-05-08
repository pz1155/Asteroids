/*
 * File:   asteroids_main.c
 * Author: Paul Zwart
 *
 * Created on March 15, 2020, 6:03 PM
 */



// PIC24EP256GP202 Configuration Bit Settings

// 'C' source line config statements

// FICD
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)

// FPOR
#pragma config ALTI2C1 = OFF            // Alternate I2C1 pins (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = OFF            // Alternate I2C2 pins (I2C2 mapped to SDA2/SCL2 pins)
#pragma config WDTWIN = WIN25           // Watchdog Window Select bits (WDT Window is 25% of WDT period)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler bits (1:32,768)
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler bit (1:128)
#pragma config PLLKEN = ON              // PLL Lock Enable bit (Clock switch to PLL source will wait until the PLL lock signal is valid.)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable bit (Watchdog timer always enabled)

// FOSC
#pragma config POSCMD = EC              // Primary Oscillator Mode Select bits (EC (External Clock) Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = ON             // Peripheral pin select configuration (Allow only one reconfiguration)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)

// FOSCSEL
#pragma config FNOSC = PRIPLL           // Oscillator Source Selection (Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL))
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FGS
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GCP = OFF                // General Segment Code-Protect bit (General Segment Code protect is Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

int main(void) {
    int i;
    
    
    config();
    
    /*
    0x0000 = 0V 
    0x1000 = 0.714V
    0x2000 = 0.054V
    0x3000 = -0.286V
     */
    
    while(1) {
        for (i = 0; i < 6; i++) {
            TMR1 = 0;
            PORTB = 0x3000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 913) {
            ClrWdt();
            }
        }
        
        for (i = 0; i < 6; i++) {
            TMR1 = 0;
            PORTB = 0x3000;     
            while (TMR1 < 913) {}
            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 62) {
            ClrWdt();
            }
        }
        
        for (i = 0; i < 6; i++) {
            TMR1 = 0;
            PORTB = 0x3000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 913) {
            ClrWdt();
            }
        }
        
        
        for (i = 0; i < 11; i++) {
            ClrWdt();

            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x3000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x0000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x0000;
            while (TMR1 < 1600) {
            ClrWdt();
            }
            ClrWdt();
        }
            
        for (i = 0; i < 242; i++) {
            ClrWdt();

            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x3000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x0000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x2000;
            while (TMR1 < 1600) {
            ClrWdt();
            }
            
           ClrWdt();
        }
             
        TMR1 = 0;
        PORTB = 0x0000;     
        while (TMR1 < 62) {}
        TMR1 = 0;
        PORTB = 0x3000;
        while (TMR1 < 144) {}
        TMR1 = 0;
        PORTB = 0x0000;
        while (TMR1 < 144) {}
        TMR1 = 0;
        PORTB = 0x2000;
        while (TMR1 < 625) {
        ClrWdt();
        }

    ///////////////////////////
    
    for (i = 0; i < 6; i++) {
            TMR1 = 0;
            PORTB = 0x3000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 913) {
            ClrWdt();
            }
        }
        
        for (i = 0; i < 6; i++) {
            TMR1 = 0;
            PORTB = 0x3000;     
            while (TMR1 < 913) {}
            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 62) {
            ClrWdt();
            }
        }
        
        for (i = 0; i < 6; i++) {
            TMR1 = 0;
            PORTB = 0x3000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 913) {
            ClrWdt();
            }
        }
        
        TMR1 = 0;
        PORTB = 0x0000;
        while (TMR1 < 975) {
        ClrWdt();
        }
        
        for (i = 0; i < 10; i++) {
            ClrWdt();

            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x3000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x0000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x0000;
            while (TMR1 < 1600) {
            ClrWdt();
            }
            ClrWdt();
        }
        
        TMR1 = 0;
        PORTB = 0x0000;     
        while (TMR1 < 62) {}
        TMR1 = 0;
        PORTB = 0x3000;
        while (TMR1 < 144) {}
        TMR1 = 0;
        PORTB = 0x0000;
        while (TMR1 < 144) {}
        TMR1 = 0;
        PORTB = 0x0000;
        while (TMR1 < 625) {
        ClrWdt();
        }

        TMR1 = 0;
        PORTB = 0x2000;
        while (TMR1 < 975) {
        ClrWdt();
        }
        
        for (i = 0; i < 242; i++) {
            ClrWdt();

            TMR1 = 0;
            PORTB = 0x0000;     
            while (TMR1 < 62) {}
            TMR1 = 0;
            PORTB = 0x3000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x0000;
            while (TMR1 < 144) {}
            TMR1 = 0;
            PORTB = 0x2000;
            while (TMR1 < 1600) {
            ClrWdt();
            }
            
           ClrWdt();
        }
             
    }
    
    return 0;
}


int config(void) {
    
    ANSELB = 0; // All port B pins are digital.
    
    TRISA = 0xFFFF; // Make PORTA all inputs
    TRISB = 0xFFFF; // Make PORTA all inputs
    
    TRISBbits.TRISB13 = 0; //Make RB11 and output
    TRISBbits.TRISB12 = 0; //Make RB12 and output
    
    // Configure PLL prescaler, PLL postscaler, PLL divisor; FCY = 32MHz (31.25nsec/i)
    PLLFBD = 44;            // M=46
    CLKDIVbits.PLLPOST = 0; // N2=2
    CLKDIVbits.PLLPRE = 1;  // N1=3    
    
    // Timer control
    T1CONbits.TCS = 0; // Set to timer mode
    T1CONbits.TGATE = 0; // Turn off Gated timer mode
    T1CONbits.TCKPS = 0b00; // Prescalar to 1:1 
    T1CONbits.TON = 1; // Enable the timer (timer 1 is used for the water sensor and checking for network)
    
    
    return 0;
}