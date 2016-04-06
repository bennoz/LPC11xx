#include "timer.h"

#include <LPC11xx.h>

void timer_init(void)
{
    // Enable TMR32B0
    LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 9);

    // Enable the counter
    LPC_TMR32B0->TCR |= (1 << 0);

    // TC increments every PR+1 (12 MHz / 12 = 1 MHz = 1 tick per microsecond)
    LPC_TMR32B0->PR = 12 - 1;
}
uint32_t timer_get(void)
{
    return LPC_TMR32B0->TC;
}
