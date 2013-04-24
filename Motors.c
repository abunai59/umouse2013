// contains functions for configuration
// and initialization

#include <p33FJ128MC802.h>
#include "main.h"
#include "motors.h"

// Use timer 1 for right motor
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    //  T1CONbits.TON = 0;   // turn off TMR1
    if(DIR == FORWARD || DIR == LEFT)
    {	
        // pulse right motor forward
		R_IND += 1;	
        R_IND %= 4;
        PORTB = (PORTB & RS_AND) + R_SEQ[R_IND];
		if(DIR == LEFT)
		{	
			ST_COUNT ++;   // increment turn steps
			if(ST_COUNT == L_STEP)  // when enough steps are taken
			{
				DIR = STOP;		// stop turning
				ST_COUNT=0;		// reset turn count
			}
		}
    }
	else if(DIR == BACKWARD || DIR == RIGHT || DIR == TURN)
	{
		// pulse right motor reverse direction
        R_IND += 3;	
        R_IND %= 4;
        PORTB = (PORTB & RS_AND) + R_SEQ[R_IND];
		if(DIR == RIGHT || DIR == TURN)
		{	
			ST_COUNT ++;   // increment turn steps
			// when enough steps are taken
			if(DIR == RIGHT && ST_COUNT == R_STEP) 
			{		
				DIR = STOP;		// stop turning
				ST_COUNT=0;		// reset turn count
			}
			if(DIR == TURN && ST_COUNT == T_STEP)
			{
				DIR = STOP;		// stop turning
				ST_COUNT=0;		// reset turn count
			}
		}
	}
	// stop
    else	{
        PORTB = (PORTB & RS_AND);
    }

    IFS0bits.T1IF = 0; // turn off TMR1 flag
    //	T1CONbits.TON = 1;

}

// Use timer 2 for left motor
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{
    //  T2CONbits.TON = 0;   // turn off TMR1
    if(DIR == FORWARD  || DIR == RIGHT || DIR == TURN)
    {		
        // pulse left motor forward
        L_IND += 1;	
        L_IND %= 4;
        PORTB = (PORTB & LS_AND) + L_SEQ[L_IND];
    }
	else if(DIR == BACKWARD || DIR == LEFT)
	{	
        // pulse left motor reverse direction
        L_IND += 3;	
        L_IND %= 4;
        PORTB = (PORTB & LS_AND) + L_SEQ[L_IND];
    }
	// stop
    else	{
        PORTB = (PORTB & LS_AND);
    }

    IFS0bits.T2IF = 0; // turn off TMR2 flag
    //	T2CONbits.TON = 1;

}
