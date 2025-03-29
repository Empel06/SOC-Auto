# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\devWorks\SS_MC_SOC\Vitis\Speed_sensor_Motor_control\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\devWorks\SS_MC_SOC\Vitis\Speed_sensor_Motor_control\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {Speed_sensor_Motor_control}\
-hw {C:\devWorks\SS_MC_SOC\Speed_sensor_Motor_control.xsa}\
-out {C:/devWorks/SS_MC_SOC/Vitis}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {hello_world}
platform generate -domains 
platform active {Speed_sensor_Motor_control}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
platform generate
