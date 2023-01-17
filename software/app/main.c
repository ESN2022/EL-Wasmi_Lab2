
#include "sys/alt_stdio.h"
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

int int_to_bcd(int int_value);
int main()
{
    alt_putstr("main du compteur !\n");
    /////on teste les differentes valeur pour etre sur que on afiche la meme valeur dans 7 segments
    while (1) {
        for (int i = 0; i < 999; i++) {

            IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE, int_to_bcd(i));
            printf("count: %d\n", i, 0);
            usleep(1000000);
        }
    }
    return 0;
}

int int_to_bcd(int int_value)
{
    char bcd_value[4];
    bcd_value[0] = int_value % 10;
    bcd_value[1] = int_value / 10 % 10;
    bcd_value[2] = int_value / 100 % 10;
    return (bcd_value[2] << 8) + (bcd_value[1] << 4) + bcd_value[0];
}
