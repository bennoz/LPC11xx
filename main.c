#include "LPC11xx.h"

#include <stdint.h>


int main(void)
{
    /*LPC_IOCON->PIO1_6 = (LPC_IOCON->PIO1_6 & ~0x7) | 0x1;
    LPC_IOCON->PIO1_7 = (LPC_IOCON->PIO1_7 & ~0x7) | 0x1;

    LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 12);
    LPC_SYSCON->UARTCLKDIV     = 0x00000001;

    for (char c = 'A'; c < 'Z'; ++c) {
        while(!(LPC_UART->LSR & 0x20)) {}

        LPC_UART->THR = (LPC_UART->THR & ~0xFF) | c;
    }

    //LPC_GPIO1->DIR  |= (1 << a); // Configure as output*/

    LPC_GPIO1->DIR |= (1 << 8);

    volatile uint32_t count;
    volatile const uint32_t count_max = 100000;


	while (1) {
        LPC_GPIO1->DATA |= (1 << 8); // Set level to high

        for (count = 0; count < count_max; count++);

        LPC_GPIO1->DATA &= ~(1 << 8); // Set level to low

        for (count = 0; count < count_max; count++);
    }

	return 0;
}
