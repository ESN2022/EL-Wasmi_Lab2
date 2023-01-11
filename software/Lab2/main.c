#include "sys/alt_stdio.h"
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

void int_to_bcd(int int_value, char* bcd_value) {
    bcd_value[0] = int_value % 10;
    bcd_value[1] = int_value / 10 % 10;
    bcd_value[2] = int_value / 100 % 10;
    bcd_value[3] = int_value / 1000 % 10;
}


int main()
{
	alt_putstr("main du compteur !\n");
	/////on teste les differentes valeur pour etre sur que on afiche la meme valeur dans 7 segments
	while(1){
		for (int i = 0; i < 300; i++) {
			 char bcd_value[4];
					int_to_bcd(i,bcd_value);
					 int bcd_output = (bcd_value[2] << 8)+(bcd_value[1] << 4)+bcd_value[0];
			                IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE, bcd_output);
			                alt_printf("count: %d\n", bcd_output);
		        usleep(100000);
	}}
	return 0;
}

