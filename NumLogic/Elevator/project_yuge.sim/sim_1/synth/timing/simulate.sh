#!/bin/bash -f
xv_path="/home/iyuge2/software/Xilinx/Vivado/2016.2"
ExecStep()
{
"$@"
RETVAL=$?
if [ $RETVAL -ne 0 ]
then
exit $RETVAL
fi
}
ExecStep $xv_path/bin/xsim Main_tb_time_synth -key {Post-Synthesis:sim_1:Timing:Main_tb} -tclbatch Main_tb.tcl -log simulate.log
