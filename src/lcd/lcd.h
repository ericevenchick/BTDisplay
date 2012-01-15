#ifndef lcd_h
#define lcd_h

#include <p24fxxxx.h>

// LCD pins
#define RS 		LATBbits.LATB11
#define RSTRIS 	TRISBbits.TRISB11
#define E 		LATBbits.LATB10
#define ETRIS 	TRISBbits.TRISB10
#define D4 		LATBbits.LATB9
#define D4TRIS 	TRISBbits.TRISB9
#define D5 		LATBbits.LATB8
#define D5TRIS	TRISBbits.TRISB8
#define D6 		LATBbits.LATB7
#define D6TRIS 	TRISBbits.TRISB7
#define D7 		LATBbits.LATB5
#define D7TRIS 	TRISBbits.TRISB5

// LCD Function Prototypes
int LCDInit();
int LCDSendCommand(int cmd);
int LCDSendData(int data);
int LCDPuts(char *str);
int LCDCls();


#endif // lcd_h
