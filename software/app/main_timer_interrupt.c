#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include "sys/alt_sys_init.h"

int time = 0;
int int_to_bcd(int int_value);
static void timer_interrupt(void *Context, alt_u32 id);
int main()
{
	alt_putstr("main du compteur !\n");

	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
	alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ, (void*) timer_interrupt, NULL, 0);
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0x07);
	while (1);
	return 0;
}

static void timer_interrupt(void *Context, alt_u32 id)
{
	alt_printf("%x\n", int_to_bcd(time));
	IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE, int_to_bcd(time++));
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}

int int_to_bcd(int int_value)
{
	char bcd_value[4];
	bcd_value[0] = int_value % 10;
	bcd_value[1] = int_value / 10 % 10;
	bcd_value[2] = int_value / 100 % 10;
	return (bcd_value[2] << 8) + (bcd_value[1] << 4) + bcd_value[0];
}
