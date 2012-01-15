#include <p24fxxxx.h>
#include "lcd/lcd.h"

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1 & FWDTEN_OFF)
_CONFIG2( FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF)

int main()
{
    LCDInit();

    for (;;)
    {
        __asm__("nop");
    }
    return 0;
}
