#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "ultrasoon.h"
#include "sleep.h"

int main()
{
    init_platform();
    unsigned int distance0;
    unsigned int distance1;
    print("HC_SR04 Test code in centimeters:\n");
    print("=======================\n\r");

    for(;;){
    	sleep_A9(1);
    	distance0 = ULTRASOON_mReadReg(XPAR_ULTRASOON_0_S00_AXI_BASEADDR,ULTRASOON_S00_AXI_SLV_REG2_OFFSET);
    	distance1 = ULTRASOON_mReadReg(XPAR_ULTRASOON_1_S00_AXI_BASEADDR,ULTRASOON_S00_AXI_SLV_REG2_OFFSET);
    	printf("Distance 1 = %d cm\n\r",distance0);
    	printf("Distance 2 = %d cm\n\r",distance1);
    	printf("\n\r");
    }


    cleanup_platform();
    return 0;
}
