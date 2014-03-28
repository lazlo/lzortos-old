#include "debug.h"
#include "pins.h"
#include "chip.h"
#include "avr_usart.h"
#include "board.h"
#include "fs.h"
#include "sched.h"

#include <avr/interrupt.h>

void hw_init(void)
{
	chip_init();
	board_init();
	dbg("hw: ready!\r\n");
}

void os_start(void)
{
	fs_init();
	sched_init();
	dbg("os: ready!\r\n");
}

int main(void)
{
	hw_init();
	os_start();

	sei();

	while (1)
		;
}

ISR(TIMER1_COMPA_vect)
{
	static int i = 0;

	if (i < 100) {
		i++;
	} else {
		i = 0;
		if (LED1_PORT & (1 << LED1_OFFSET)) {
			LED1_PORT &= ~(1 << LED1_OFFSET);
			LED2_PORT &= ~(1 << LED2_OFFSET);
			LED3_PORT &= ~(1 << LED3_OFFSET);
		} else {
			LED1_PORT |= (1 << LED1_OFFSET);
			LED2_PORT |= (1 << LED2_OFFSET);
			LED3_PORT |= (1 << LED3_OFFSET);
		}
	}
}
