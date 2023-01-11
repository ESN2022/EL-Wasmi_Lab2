#include "sys/alt_stdio.h"
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
int main()
{ 
	alt_putstr("main du compteur !\n");
	/////on teste les differentes valeur pour etre sur que on afiche la meme valeur dans 7 segments
	IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE, 7);
	return 0;
}

