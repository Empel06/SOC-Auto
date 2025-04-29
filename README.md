# SOC-Auto

## Overzicht
De wagen moet autonoom rijden binnen een parcours en aantonen dat alle deelopdrachten correct werken.  
**Totaal:** 60 punten  

## Deelopdrachten

### 1. Ultrasoon sensoren (15 punten)
- Custom AXI IP blok(ken) voor ultrasoon sensoren
- **Moet klaar zijn:** SoC hardware platform, C code
- **Opleveren:** PDF blokdesign, GitHub commit, YouTube demo
[Ultrasoon Video](https://youtu.be/_wWzT27MwKY)
[Blokdesign](https://github.com/Empel06/SOC-Auto/blob/main/Ultrasoon/BD-Ultrasoon.pdf)

### 2. Snelheidssensoren & Motor Control (10 punten)
- Custom AXI IP blok voor snelheidssensoren, motor control via AXI/Timer blok
- **Moet klaar zijn:** SoC hardware platform, C code (sensordata + PWM motorsturing)
- **Opleveren:** PDF blokdesign, GitHub commit, YouTube demo
[Snelheidssensoren & Motor Control Video](https://youtu.be/CrCh2be9bAA)
[Blokdesign](https://github.com/Empel06/SOC-Auto/blob/main/Speedsensor_MC/BD-SS_MC.pdf)
- **Referenties:**  
  - [SEN-Speed Manual](https://joy-it.net/files/files/Produkte/SEN-Speed/SEN-Speed-Manual-20201015.pdf)  
  - [TI LM393](https://www.ti.com/product/LM393)
  - **[Arduino demo code](#)**

### 3. IMU uitlezen (10 punten)
- AXI IP of PS-gebaseerde uitlezing van MPU-6050 IMU
- **Moet klaar zijn:** SoC hardware platform, C code
- **Opleveren:** PDF blokdesign, GitHub commit, YouTube demo

[Blokdesign](https://github.com/Empel06/SOC-Auto/blob/main/IMU/BD-IMU.pdf)
- **Referenties:**  
  - [MPU-6050 Info](https://www.amazon.de/dp/B07NP2WF7J/)  
  - [MiniZED I2C PL](https://github.com/cteqeu/SoC/tree/master/MiniZED/eFPGA_I2C_PL)  
  - [MiniZED I2C PS](https://github.com/cteqeu/SoC/tree/master/MiniZED/eFPGA_I2C_PS)  
  - **[MPU-6050 voorbeeldcode](https://electrosome.com/interfacing-mpu-6050-gy-521-arduino-uno/)**

### 4. Autonoom rijden (25 punten)
- De wagen moet autonoom rijden binnen een parcours
- **Moet klaar zijn:** SoC hardware platform, C code
- **Opleveren:** PDF blokdesign, GitHub commit, YouTube demo

