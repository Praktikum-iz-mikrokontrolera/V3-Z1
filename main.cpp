#include "mbed.h"

#define SDA PB_14
#define SCL PB_13

I2C magistrala(SDA, SCL);

void scanI2C() {
	for(int addr = 0; addr < 127; addr++){
		int add_read = addr << 1;
		char zaSlanje[2] = {0x1, 0x2};
		int odgovor = magistrala.write(add_read, zaSlanje, 1);
		if(odgovor == 0) {
			printf("Odgovor na adresi %d i real adresi: %x\n", addr, add_read);
		}
		ThisThread::sleep_for(10ms);
	}
}

int main()
{
	ThisThread::sleep_for(3s);
	printf("Pocetak! \n");
	scanI2C();
	printf("Gotovo skeniranje");
	while(1);
}
