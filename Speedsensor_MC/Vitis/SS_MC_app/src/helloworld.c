#include "xparameters.h"
#include "xtmrctr.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "xil_printf.h"
#include "sleep.h"
#include "platform.h"
#include "SpeedSensor.h"

// Device IDs
#define TIMER1_DEVICE_ID XPAR_AXI_TIMER_0_DEVICE_ID
#define TIMER2_DEVICE_ID XPAR_AXI_TIMER_1_DEVICE_ID

// PWM config
#define PWM_PERIOD_US        10000
#define PWM_HIGH_TIME_US     15000

// Timer instances
XTmrCtr Timer1;
XTmrCtr Timer2;

// Interrupt controller (optioneel indien interrupt gebruikt)
XScuGic xScuGic_Inst;

// Helper functies
u32 US_to_RegValue(u32 us) {
    return 0xFFFFFFFF - (50 * us); // 50 MHz klok
}

u32 US_to_NS(u32 us) {
    return us * 1000;
}

// PWM setup voor 1 timer
int Setup_PWM(XTmrCtr *Timer, u32 DeviceID, u32 Period_us, u32 HighTime_us) {
    int Status;

    Status = XTmrCtr_Initialize(Timer, DeviceID);
    if (Status != XST_SUCCESS) return XST_FAILURE;

    Status = XTmrCtr_SelfTest(Timer, 0);
    if (Status != XST_SUCCESS) return XST_FAILURE;

    XTmrCtr_SetResetValue(Timer, 0, US_to_RegValue(Period_us));
    XTmrCtr_SetOptions(Timer, 0, XTC_INT_MODE_OPTION | XTC_AUTO_RELOAD_OPTION);

    int DutyCycle = XTmrCtr_PwmConfigure(Timer, US_to_NS(Period_us), US_to_NS(HighTime_us));
    xil_printf("PWM @ Timer %d: DutyCycle = %d%%\n", DeviceID, DutyCycle);

    XTmrCtr_PwmEnable(Timer);
    XTmrCtr_Start(Timer, 0);

    return XST_SUCCESS;
}

int main() {
    int Status;
    u32 speedValue = 0;

    init_platform();
    xil_printf("Start Dual PWM & Speed Sensor\n");

    // PWM Timer 1 (motor 1)
    Status = Setup_PWM(&Timer1, TIMER1_DEVICE_ID, PWM_PERIOD_US, PWM_HIGH_TIME_US);
    if (Status != XST_SUCCESS) {
        xil_printf("FOUT bij Timer 1 init\n");
        return XST_FAILURE;
    }

    // PWM Timer 2 (motor 2)
    Status = Setup_PWM(&Timer2, TIMER2_DEVICE_ID, PWM_PERIOD_US, PWM_HIGH_TIME_US);
    if (Status != XST_SUCCESS) {
        xil_printf("FOUT bij Timer 2 init\n");
        return XST_FAILURE;
    }

    // Zet speed sensor aan
    SPEEDSENSOR_mWriteReg(XPAR_SPEEDSENSOR_0_S00_AXI_BASEADDR,
                          SPEEDSENSOR_S00_AXI_SLV_REG1_OFFSET,
                          0b1111);

    // Main loop
    while (1) {
        sleep_A9(1);
        speedValue = SPEEDSENSOR_mReadReg(XPAR_SPEEDSENSOR_0_S00_AXI_BASEADDR,
                                          SPEEDSENSOR_S00_AXI_SLV_REG2_OFFSET);
        xil_printf("Pulsen: [%u]\n\r", speedValue);
    }

    cleanup_platform();
    return 0;
}
