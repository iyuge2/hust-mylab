// Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
// Date        : Tue Sep 27 01:28:31 2016
// Host        : iyuge2PC running 64-bit Ubuntu 16.04.1 LTS
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               /home/iyuge2/Study/NumLogicWork/Elevator/Elevator.sim/sim_1/synth/timing/Main_tb_time_synth.v
// Design      : Main
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xa7a100tcsg324-1I
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

module ChangeState
   (OpenLamp_OBUF,
    CloseLamp_OBUF,
    UpLamp_OBUF,
    DownLamp_OBUF,
    Q,
    \result[0] ,
    CurrentStair_OBUF,
    \StairLamp_reg[7]_0 ,
    clk_1s_OBUF_BUFG,
    out,
    UpButton7_IBUF,
    UpButton5_IBUF,
    UpButton3_IBUF,
    UpButton1_IBUF,
    DownButton8_IBUF,
    DownButton6_IBUF,
    DownButton4_IBUF,
    DownButton2_IBUF,
    StairButton1_IBUF,
    OpenButton_IBUF,
    StairButton3_IBUF,
    StairButton5_IBUF,
    StairButton8_IBUF);
  output OpenLamp_OBUF;
  output CloseLamp_OBUF;
  output UpLamp_OBUF;
  output DownLamp_OBUF;
  output [3:0]Q;
  output \result[0] ;
  output [3:0]CurrentStair_OBUF;
  output [3:0]\StairLamp_reg[7]_0 ;
  input clk_1s_OBUF_BUFG;
  input [2:0]out;
  input UpButton7_IBUF;
  input UpButton5_IBUF;
  input UpButton3_IBUF;
  input UpButton1_IBUF;
  input DownButton8_IBUF;
  input DownButton6_IBUF;
  input DownButton4_IBUF;
  input DownButton2_IBUF;
  input StairButton1_IBUF;
  input OpenButton_IBUF;
  input StairButton3_IBUF;
  input StairButton5_IBUF;
  input StairButton8_IBUF;

  wire CloseLamp_OBUF;
  wire CloseLamp_i_1_n_0;
  wire CloseLamp_i_2_n_0;
  wire CloseLamp_i_3_n_0;
  wire \CountDown[0]_i_1_n_0 ;
  wire \CountDown[1]_i_1_n_0 ;
  wire \CountDown[1]_i_2_n_0 ;
  wire \CountDown[2]_i_1_n_0 ;
  wire \CountDown[3]_i_10_n_0 ;
  wire \CountDown[3]_i_1_n_0 ;
  wire \CountDown[3]_i_2_n_0 ;
  wire \CountDown[3]_i_4_n_0 ;
  wire \CountDown[3]_i_5_n_0 ;
  wire \CountDown[3]_i_6_n_0 ;
  wire \CountDown[3]_i_7_n_0 ;
  wire \CountDown[3]_i_8_n_0 ;
  wire \CountDown[3]_i_9_n_0 ;
  wire [3:0]CurrentStair_OBUF;
  wire \CurrentStair_OBUF[1]_inst_i_2_n_0 ;
  wire \CurrentStair_OBUF[3]_inst_i_2_n_0 ;
  wire \CurrentStair_OBUF[3]_inst_i_3_n_0 ;
  wire \CurrentStair_OBUF[3]_inst_i_4_n_0 ;
  wire \CurrentStair_OBUF[3]_inst_i_5_n_0 ;
  wire CurrentStair_b;
  wire \CurrentStair_b[0]_i_1_n_0 ;
  wire \CurrentStair_b[1]_i_1_n_0 ;
  wire \CurrentStair_b[2]_i_1_n_0 ;
  wire \CurrentStair_b[3]_i_1_n_0 ;
  wire \CurrentStair_b[4]_i_1_n_0 ;
  wire \CurrentStair_b[5]_i_1_n_0 ;
  wire \CurrentStair_b[6]_i_1_n_0 ;
  wire \CurrentStair_b[7]_i_2_n_0 ;
  wire DownButton2_IBUF;
  wire DownButton4_IBUF;
  wire DownButton6_IBUF;
  wire DownButton8_IBUF;
  wire DownLamp4_out;
  wire DownLamp_OBUF;
  wire DownLamp_i_1_n_0;
  wire DownLamp_i_2_n_0;
  wire DownLamp_i_3_n_0;
  wire DownLamp_i_6_n_0;
  wire [2:0]DownMax;
  wire \DownMax[1]_i_1_n_0 ;
  wire \DownMax[2]_i_10_n_0 ;
  wire \DownMax[2]_i_11_n_0 ;
  wire \DownMax[2]_i_12_n_0 ;
  wire \DownMax[2]_i_13_n_0 ;
  wire \DownMax[2]_i_14_n_0 ;
  wire \DownMax[2]_i_2_n_0 ;
  wire \DownMax[2]_i_3_n_0 ;
  wire \DownMax[2]_i_4_n_0 ;
  wire \DownMax[2]_i_5_n_0 ;
  wire \DownMax[2]_i_6_n_0 ;
  wire \DownMax[2]_i_7_n_0 ;
  wire \DownMax[2]_i_8_n_0 ;
  wire \DownMax[2]_i_9_n_0 ;
  wire \DownMax_reg_n_0_[0] ;
  wire \DownMax_reg_n_0_[1] ;
  wire \DownMax_reg_n_0_[2] ;
  wire \FSM_sequential_state[0]_i_1_n_0 ;
  wire \FSM_sequential_state[0]_i_3_n_0 ;
  wire \FSM_sequential_state[0]_i_4_n_0 ;
  wire \FSM_sequential_state[0]_i_5_n_0 ;
  wire \FSM_sequential_state[0]_i_6_n_0 ;
  wire \FSM_sequential_state[1]_i_10_n_0 ;
  wire \FSM_sequential_state[1]_i_11_n_0 ;
  wire \FSM_sequential_state[1]_i_12_n_0 ;
  wire \FSM_sequential_state[1]_i_1_n_0 ;
  wire \FSM_sequential_state[1]_i_2_n_0 ;
  wire \FSM_sequential_state[1]_i_3_n_0 ;
  wire \FSM_sequential_state[1]_i_4_n_0 ;
  wire \FSM_sequential_state[1]_i_5_n_0 ;
  wire \FSM_sequential_state[1]_i_6_n_0 ;
  wire \FSM_sequential_state[1]_i_7_n_0 ;
  wire \FSM_sequential_state[1]_i_8_n_0 ;
  wire \FSM_sequential_state[1]_i_9_n_0 ;
  wire \FSM_sequential_state[2]_i_1_n_0 ;
  wire \FSM_sequential_state[2]_i_2_n_0 ;
  wire \FSM_sequential_state[2]_i_4_n_0 ;
  wire \FSM_sequential_state[2]_i_5_n_0 ;
  wire \FSM_sequential_state_reg[0]_i_2_n_0 ;
  wire [31:0]K;
  wire [31:1]K0;
  wire K0_carry__0_n_0;
  wire K0_carry__0_n_1;
  wire K0_carry__0_n_2;
  wire K0_carry__0_n_3;
  wire K0_carry__1_n_0;
  wire K0_carry__1_n_1;
  wire K0_carry__1_n_2;
  wire K0_carry__1_n_3;
  wire K0_carry__2_n_0;
  wire K0_carry__2_n_1;
  wire K0_carry__2_n_2;
  wire K0_carry__2_n_3;
  wire K0_carry__3_n_0;
  wire K0_carry__3_n_1;
  wire K0_carry__3_n_2;
  wire K0_carry__3_n_3;
  wire K0_carry__4_n_0;
  wire K0_carry__4_n_1;
  wire K0_carry__4_n_2;
  wire K0_carry__4_n_3;
  wire K0_carry__5_n_0;
  wire K0_carry__5_n_1;
  wire K0_carry__5_n_2;
  wire K0_carry__5_n_3;
  wire K0_carry__6_n_2;
  wire K0_carry__6_n_3;
  wire K0_carry_n_0;
  wire K0_carry_n_1;
  wire K0_carry_n_2;
  wire K0_carry_n_3;
  wire \K[0]_i_1_n_0 ;
  wire \K[10]_i_1_n_0 ;
  wire \K[11]_i_1_n_0 ;
  wire \K[12]_i_1_n_0 ;
  wire \K[13]_i_1_n_0 ;
  wire \K[14]_i_1_n_0 ;
  wire \K[15]_i_1_n_0 ;
  wire \K[16]_i_1_n_0 ;
  wire \K[17]_i_1_n_0 ;
  wire \K[18]_i_1_n_0 ;
  wire \K[19]_i_1_n_0 ;
  wire \K[1]_i_1_n_0 ;
  wire \K[20]_i_1_n_0 ;
  wire \K[21]_i_1_n_0 ;
  wire \K[22]_i_1_n_0 ;
  wire \K[23]_i_1_n_0 ;
  wire \K[24]_i_1_n_0 ;
  wire \K[25]_i_1_n_0 ;
  wire \K[26]_i_1_n_0 ;
  wire \K[27]_i_1_n_0 ;
  wire \K[28]_i_1_n_0 ;
  wire \K[29]_i_1_n_0 ;
  wire \K[2]_i_1_n_0 ;
  wire \K[30]_i_1_n_0 ;
  wire \K[31]_i_1_n_0 ;
  wire \K[31]_i_3_n_0 ;
  wire \K[3]_i_1_n_0 ;
  wire \K[4]_i_1_n_0 ;
  wire \K[5]_i_1_n_0 ;
  wire \K[6]_i_1_n_0 ;
  wire \K[7]_i_1_n_0 ;
  wire \K[8]_i_1_n_0 ;
  wire \K[9]_i_1_n_0 ;
  wire K_0;
  wire OpenButton_IBUF;
  wire OpenLamp1;
  wire OpenLamp1_carry__0_i_1_n_0;
  wire OpenLamp1_carry__0_i_2_n_0;
  wire OpenLamp1_carry__0_i_3_n_0;
  wire OpenLamp1_carry__0_i_4_n_0;
  wire OpenLamp1_carry__0_i_5_n_0;
  wire OpenLamp1_carry__0_i_6_n_0;
  wire OpenLamp1_carry__0_i_7_n_0;
  wire OpenLamp1_carry__0_i_8_n_0;
  wire OpenLamp1_carry__0_n_0;
  wire OpenLamp1_carry__0_n_1;
  wire OpenLamp1_carry__0_n_2;
  wire OpenLamp1_carry__0_n_3;
  wire OpenLamp1_carry__1_i_1_n_0;
  wire OpenLamp1_carry__1_i_2_n_0;
  wire OpenLamp1_carry__1_i_3_n_0;
  wire OpenLamp1_carry__1_i_4_n_0;
  wire OpenLamp1_carry__1_i_5_n_0;
  wire OpenLamp1_carry__1_i_6_n_0;
  wire OpenLamp1_carry__1_i_7_n_0;
  wire OpenLamp1_carry__1_i_8_n_0;
  wire OpenLamp1_carry__1_n_0;
  wire OpenLamp1_carry__1_n_1;
  wire OpenLamp1_carry__1_n_2;
  wire OpenLamp1_carry__1_n_3;
  wire OpenLamp1_carry__2_i_1_n_0;
  wire OpenLamp1_carry__2_i_2_n_0;
  wire OpenLamp1_carry__2_i_3_n_0;
  wire OpenLamp1_carry__2_i_4_n_0;
  wire OpenLamp1_carry__2_i_5_n_0;
  wire OpenLamp1_carry__2_i_6_n_0;
  wire OpenLamp1_carry__2_i_7_n_0;
  wire OpenLamp1_carry__2_i_8_n_0;
  wire OpenLamp1_carry__2_n_1;
  wire OpenLamp1_carry__2_n_2;
  wire OpenLamp1_carry__2_n_3;
  wire OpenLamp1_carry_i_1_n_0;
  wire OpenLamp1_carry_i_2_n_0;
  wire OpenLamp1_carry_i_3_n_0;
  wire OpenLamp1_carry_i_4_n_0;
  wire OpenLamp1_carry_i_5_n_0;
  wire OpenLamp1_carry_i_6_n_0;
  wire OpenLamp1_carry_n_0;
  wire OpenLamp1_carry_n_1;
  wire OpenLamp1_carry_n_2;
  wire OpenLamp1_carry_n_3;
  wire OpenLamp_OBUF;
  wire OpenLamp_i_10_n_0;
  wire OpenLamp_i_11_n_0;
  wire OpenLamp_i_1_n_0;
  wire OpenLamp_i_2_n_0;
  wire OpenLamp_i_3_n_0;
  wire OpenLamp_i_4_n_0;
  wire OpenLamp_i_5_n_0;
  wire OpenLamp_i_6_n_0;
  wire OpenLamp_i_7_n_0;
  wire OpenLamp_i_8_n_0;
  wire OpenLamp_i_9_n_0;
  wire [3:0]Q;
  wire StairButton1_IBUF;
  wire StairButton3_IBUF;
  wire StairButton5_IBUF;
  wire StairButton8_IBUF;
  wire \StairLamp[0]_i_1_n_0 ;
  wire \StairLamp[3]_i_1_n_0 ;
  wire \StairLamp[5]_i_1_n_0 ;
  wire \StairLamp[7]_i_1_n_0 ;
  wire \StairLamp[7]_i_2_n_0 ;
  wire \StairLamp[7]_i_3_n_0 ;
  wire \StairLamp[7]_i_4_n_0 ;
  wire [3:0]\StairLamp_reg[7]_0 ;
  wire UpButton1_IBUF;
  wire UpButton3_IBUF;
  wire UpButton5_IBUF;
  wire UpButton7_IBUF;
  wire UpLamp_OBUF;
  wire UpLamp_i_1_n_0;
  wire UpLamp_i_2_n_0;
  wire UpLamp_i_3_n_0;
  wire [2:0]UpMax;
  wire \UpMax[0]_i_1_n_0 ;
  wire \UpMax[0]_i_2_n_0 ;
  wire \UpMax[0]_i_3_n_0 ;
  wire \UpMax[0]_i_4_n_0 ;
  wire \UpMax[1]_i_1_n_0 ;
  wire \UpMax[1]_i_2_n_0 ;
  wire \UpMax[1]_i_3_n_0 ;
  wire \UpMax[2]_i_1_n_0 ;
  wire \UpMax[2]_i_2_n_0 ;
  wire \UpMax[2]_i_3_n_0 ;
  wire \UpMax[2]_i_4_n_0 ;
  wire \UpMax[2]_i_5_n_0 ;
  wire \UpMax[2]_i_6_n_0 ;
  wire \UpMax[2]_i_7_n_0 ;
  wire \UpMax[2]_i_8_n_0 ;
  wire clk_1s_OBUF_BUFG;
  wire [2:0]out;
  wire \result[0] ;
  wire runstate;
  wire runstate0;
  wire runstate1;
  wire [6:0]runstate2;
  wire [1:1]runstate22_in;
  wire runstate9_out;
  wire runstate_i_11_n_0;
  wire runstate_i_12_n_0;
  wire runstate_i_13_n_0;
  wire runstate_i_14_n_0;
  wire runstate_i_15_n_0;
  wire runstate_i_16_n_0;
  wire runstate_i_17_n_0;
  wire runstate_i_18_n_0;
  wire runstate_i_19_n_0;
  wire runstate_i_1_n_0;
  wire runstate_i_20_n_0;
  wire runstate_i_21_n_0;
  wire runstate_i_22_n_0;
  wire runstate_i_23_n_0;
  wire runstate_i_24_n_0;
  wire runstate_i_2_n_0;
  wire runstate_i_3_n_0;
  wire runstate_i_5_n_0;
  wire runstate_i_6_n_0;
  wire runstate_i_7_n_0;
  wire runstate_i_8_n_0;
  wire runstate_i_9_n_0;
  wire runstate_reg_n_0;
  (* RTL_KEEP = "yes" *) wire [2:0]state;
  wire state1;
  wire state13_out;
  wire state21_in;
  wire state2_inferred__0_carry_i_1_n_0;
  wire state2_inferred__0_carry_i_2_n_0;
  wire state2_inferred__0_carry_i_3_n_0;
  wire state2_inferred__0_carry_i_4_n_0;
  wire state2_inferred__0_carry_i_5_n_0;
  wire state2_inferred__0_carry_i_6_n_0;
  wire state2_inferred__0_carry_n_1;
  wire state2_inferred__0_carry_n_2;
  wire state2_inferred__0_carry_n_3;
  wire state3_carry_i_1_n_0;
  wire state3_carry_i_2_n_0;
  wire state3_carry_i_3_n_0;
  wire state3_carry_i_4_n_0;
  wire state3_carry_i_5_n_0;
  wire state3_carry_i_6_n_0;
  wire state3_carry_n_0;
  wire state3_carry_n_1;
  wire state3_carry_n_2;
  wire state3_carry_n_3;
  wire [3:2]NLW_K0_carry__6_CO_UNCONNECTED;
  wire [3:3]NLW_K0_carry__6_O_UNCONNECTED;
  wire [3:0]NLW_OpenLamp1_carry_O_UNCONNECTED;
  wire [3:0]NLW_OpenLamp1_carry__0_O_UNCONNECTED;
  wire [3:0]NLW_OpenLamp1_carry__1_O_UNCONNECTED;
  wire [3:0]NLW_OpenLamp1_carry__2_O_UNCONNECTED;
  wire [3:0]NLW_state2_inferred__0_carry_O_UNCONNECTED;
  wire [3:0]NLW_state3_carry_O_UNCONNECTED;

  LUT5 #(
    .INIT(32'h45440000)) 
    CloseLamp_i_1
       (.I0(state[2]),
        .I1(state[0]),
        .I2(OpenButton_IBUF),
        .I3(OpenLamp1),
        .I4(state[1]),
        .O(CloseLamp_i_1_n_0));
  LUT6 #(
    .INIT(64'h000000002222222E)) 
    CloseLamp_i_2
       (.I0(OpenLamp1),
        .I1(state[0]),
        .I2(state1),
        .I3(state13_out),
        .I4(CloseLamp_i_3_n_0),
        .I5(state[2]),
        .O(CloseLamp_i_2_n_0));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT4 #(
    .INIT(16'h0001)) 
    CloseLamp_i_3
       (.I0(\StairLamp_reg[7]_0 [2]),
        .I1(\StairLamp_reg[7]_0 [3]),
        .I2(\StairLamp_reg[7]_0 [0]),
        .I3(\StairLamp_reg[7]_0 [1]),
        .O(CloseLamp_i_3_n_0));
  FDRE #(
    .INIT(1'b0)) 
    CloseLamp_reg
       (.C(clk_1s_OBUF_BUFG),
        .CE(CloseLamp_i_1_n_0),
        .D(CloseLamp_i_2_n_0),
        .Q(CloseLamp_OBUF),
        .R(1'b0));
  LUT4 #(
    .INIT(16'h0014)) 
    \CountDown[0]_i_1 
       (.I0(state[1]),
        .I1(state[0]),
        .I2(state[2]),
        .I3(Q[0]),
        .O(\CountDown[0]_i_1_n_0 ));
  LUT4 #(
    .INIT(16'h10FB)) 
    \CountDown[1]_i_1 
       (.I0(state[1]),
        .I1(state[0]),
        .I2(\CountDown[1]_i_2_n_0 ),
        .I3(state[2]),
        .O(\CountDown[1]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT4 #(
    .INIT(16'hF01F)) 
    \CountDown[1]_i_2 
       (.I0(Q[3]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .O(\CountDown[1]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h1400140014000014)) 
    \CountDown[2]_i_1 
       (.I0(state[1]),
        .I1(state[0]),
        .I2(state[2]),
        .I3(Q[2]),
        .I4(Q[0]),
        .I5(Q[1]),
        .O(\CountDown[2]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h00EE0000F0FFFFF0)) 
    \CountDown[3]_i_1 
       (.I0(state13_out),
        .I1(state1),
        .I2(\CountDown[3]_i_4_n_0 ),
        .I3(state[2]),
        .I4(state[0]),
        .I5(state[1]),
        .O(\CountDown[3]_i_1_n_0 ));
  LUT4 #(
    .INIT(16'hABA8)) 
    \CountDown[3]_i_10 
       (.I0(runstate2[5]),
        .I1(runstate22_in),
        .I2(\CurrentStair_OBUF[3]_inst_i_5_n_0 ),
        .I3(runstate2[6]),
        .O(\CountDown[3]_i_10_n_0 ));
  LUT6 #(
    .INIT(64'h11100110FFFBBFFB)) 
    \CountDown[3]_i_2 
       (.I0(state[1]),
        .I1(state[0]),
        .I2(\CountDown[3]_i_5_n_0 ),
        .I3(Q[3]),
        .I4(Q[0]),
        .I5(state[2]),
        .O(\CountDown[3]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hFFFFFFFFFF4D0000)) 
    \CountDown[3]_i_3 
       (.I0(\CountDown[3]_i_6_n_0 ),
        .I1(CurrentStair_OBUF[2]),
        .I2(\CountDown[3]_i_7_n_0 ),
        .I3(CurrentStair_OBUF[3]),
        .I4(runstate_reg_n_0),
        .I5(\CountDown[3]_i_8_n_0 ),
        .O(state1));
  LUT6 #(
    .INIT(64'h0000000033333332)) 
    \CountDown[3]_i_4 
       (.I0(runstate1),
        .I1(OpenLamp_i_5_n_0),
        .I2(\DownMax_reg_n_0_[1] ),
        .I3(\DownMax_reg_n_0_[2] ),
        .I4(\DownMax_reg_n_0_[0] ),
        .I5(state[2]),
        .O(\CountDown[3]_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h1)) 
    \CountDown[3]_i_5 
       (.I0(Q[2]),
        .I1(Q[1]),
        .O(\CountDown[3]_i_5_n_0 ));
  LUT6 #(
    .INIT(64'hAAFFAAFFFFAEBBAE)) 
    \CountDown[3]_i_6 
       (.I0(\CountDown[3]_i_9_n_0 ),
        .I1(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I2(\CurrentStair_OBUF[1]_inst_i_2_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I4(\CountDown[3]_i_10_n_0 ),
        .I5(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .O(\CountDown[3]_i_6_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT2 #(
    .INIT(4'h1)) 
    \CountDown[3]_i_7 
       (.I0(DownButton6_IBUF),
        .I1(DownButton8_IBUF),
        .O(\CountDown[3]_i_7_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT5 #(
    .INIT(32'hAAAAAAA8)) 
    \CountDown[3]_i_8 
       (.I0(state3_carry_n_0),
        .I1(\StairLamp_reg[7]_0 [1]),
        .I2(\StairLamp_reg[7]_0 [0]),
        .I3(\StairLamp_reg[7]_0 [3]),
        .I4(\StairLamp_reg[7]_0 [2]),
        .O(\CountDown[3]_i_8_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT3 #(
    .INIT(8'h45)) 
    \CountDown[3]_i_9 
       (.I0(DownButton8_IBUF),
        .I1(DownButton6_IBUF),
        .I2(DownButton4_IBUF),
        .O(\CountDown[3]_i_9_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \CountDown_reg[0] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(\CountDown[3]_i_1_n_0 ),
        .D(\CountDown[0]_i_1_n_0 ),
        .Q(Q[0]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b1)) 
    \CountDown_reg[1] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(\CountDown[3]_i_1_n_0 ),
        .D(\CountDown[1]_i_1_n_0 ),
        .Q(Q[1]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CountDown_reg[2] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(\CountDown[3]_i_1_n_0 ),
        .D(\CountDown[2]_i_1_n_0 ),
        .Q(Q[2]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b1)) 
    \CountDown_reg[3] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(\CountDown[3]_i_1_n_0 ),
        .D(\CountDown[3]_i_2_n_0 ),
        .Q(Q[3]),
        .R(1'b0));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'hBABFAAAA)) 
    \CurrentStair_OBUF[0]_inst_i_1 
       (.I0(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I1(runstate2[6]),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I3(\CurrentStair_OBUF[1]_inst_i_2_n_0 ),
        .I4(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .O(CurrentStair_OBUF[0]));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'hF0F00DAD)) 
    \CurrentStair_OBUF[1]_inst_i_1 
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(\CurrentStair_OBUF[1]_inst_i_2_n_0 ),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I3(runstate2[6]),
        .I4(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .O(CurrentStair_OBUF[1]));
  (* SOFT_HLUTNM = "soft_lutpair17" *) 
  LUT4 #(
    .INIT(16'hABA8)) 
    \CurrentStair_OBUF[1]_inst_i_2 
       (.I0(runstate2[3]),
        .I1(runstate22_in),
        .I2(\CurrentStair_OBUF[3]_inst_i_5_n_0 ),
        .I3(runstate2[4]),
        .O(\CurrentStair_OBUF[1]_inst_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT4 #(
    .INIT(16'hA7AA)) 
    \CurrentStair_OBUF[2]_inst_i_1 
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(runstate2[6]),
        .I2(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(CurrentStair_OBUF[2]));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT4 #(
    .INIT(16'h2000)) 
    \CurrentStair_OBUF[3]_inst_i_1 
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I2(runstate2[6]),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .O(CurrentStair_OBUF[3]));
  LUT6 #(
    .INIT(64'h1111111111110001)) 
    \CurrentStair_OBUF[3]_inst_i_2 
       (.I0(runstate22_in),
        .I1(runstate2[0]),
        .I2(runstate2[3]),
        .I3(runstate2[4]),
        .I4(runstate2[2]),
        .I5(runstate2[1]),
        .O(\CurrentStair_OBUF[3]_inst_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair17" *) 
  LUT2 #(
    .INIT(4'hE)) 
    \CurrentStair_OBUF[3]_inst_i_3 
       (.I0(runstate22_in),
        .I1(\CurrentStair_OBUF[3]_inst_i_5_n_0 ),
        .O(\CurrentStair_OBUF[3]_inst_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h0001)) 
    \CurrentStair_OBUF[3]_inst_i_4 
       (.I0(runstate22_in),
        .I1(runstate2[0]),
        .I2(runstate2[1]),
        .I3(runstate2[2]),
        .O(\CurrentStair_OBUF[3]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'h00000000FFFF00F2)) 
    \CurrentStair_OBUF[3]_inst_i_5 
       (.I0(runstate2[5]),
        .I1(runstate2[4]),
        .I2(runstate2[3]),
        .I3(runstate2[2]),
        .I4(runstate2[1]),
        .I5(runstate2[0]),
        .O(\CurrentStair_OBUF[3]_inst_i_5_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \CurrentStair_b[0]_i_1 
       (.I0(runstate2[0]),
        .I1(state[2]),
        .O(\CurrentStair_b[0]_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h222222F2)) 
    \CurrentStair_b[1]_i_1 
       (.I0(runstate2[1]),
        .I1(state[2]),
        .I2(runstate22_in),
        .I3(state[0]),
        .I4(state[1]),
        .O(\CurrentStair_b[1]_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h222222F2)) 
    \CurrentStair_b[2]_i_1 
       (.I0(runstate2[2]),
        .I1(state[2]),
        .I2(runstate2[0]),
        .I3(state[0]),
        .I4(state[1]),
        .O(\CurrentStair_b[2]_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h222222F2)) 
    \CurrentStair_b[3]_i_1 
       (.I0(runstate2[3]),
        .I1(state[2]),
        .I2(runstate2[1]),
        .I3(state[0]),
        .I4(state[1]),
        .O(\CurrentStair_b[3]_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h222222F2)) 
    \CurrentStair_b[4]_i_1 
       (.I0(runstate2[4]),
        .I1(state[2]),
        .I2(runstate2[2]),
        .I3(state[0]),
        .I4(state[1]),
        .O(\CurrentStair_b[4]_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h222222F2)) 
    \CurrentStair_b[5]_i_1 
       (.I0(runstate2[5]),
        .I1(state[2]),
        .I2(runstate2[3]),
        .I3(state[0]),
        .I4(state[1]),
        .O(\CurrentStair_b[5]_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h222222F2)) 
    \CurrentStair_b[6]_i_1 
       (.I0(runstate2[6]),
        .I1(state[2]),
        .I2(runstate2[4]),
        .I3(state[0]),
        .I4(state[1]),
        .O(\CurrentStair_b[6]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h0014000000000000)) 
    \CurrentStair_b[7]_i_1 
       (.I0(state[1]),
        .I1(state[0]),
        .I2(state[2]),
        .I3(Q[3]),
        .I4(\CountDown[3]_i_5_n_0 ),
        .I5(Q[0]),
        .O(CurrentStair_b));
  LUT3 #(
    .INIT(8'h04)) 
    \CurrentStair_b[7]_i_2 
       (.I0(state[0]),
        .I1(runstate2[5]),
        .I2(state[1]),
        .O(\CurrentStair_b[7]_i_2_n_0 ));
  FDRE #(
    .INIT(1'b1)) 
    \CurrentStair_b_reg[0] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[0]_i_1_n_0 ),
        .Q(runstate22_in),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CurrentStair_b_reg[1] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[1]_i_1_n_0 ),
        .Q(runstate2[0]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CurrentStair_b_reg[2] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[2]_i_1_n_0 ),
        .Q(runstate2[1]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CurrentStair_b_reg[3] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[3]_i_1_n_0 ),
        .Q(runstate2[2]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CurrentStair_b_reg[4] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[4]_i_1_n_0 ),
        .Q(runstate2[3]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CurrentStair_b_reg[5] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[5]_i_1_n_0 ),
        .Q(runstate2[4]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CurrentStair_b_reg[6] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[6]_i_1_n_0 ),
        .Q(runstate2[5]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \CurrentStair_b_reg[7] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(CurrentStair_b),
        .D(\CurrentStair_b[7]_i_2_n_0 ),
        .Q(runstate2[6]),
        .R(1'b0));
  LUT6 #(
    .INIT(64'h00000000F4A45404)) 
    DownLamp_i_1
       (.I0(state[1]),
        .I1(DownLamp_i_3_n_0),
        .I2(state[0]),
        .I3(OpenLamp_i_3_n_0),
        .I4(DownLamp4_out),
        .I5(state[2]),
        .O(DownLamp_i_1_n_0));
  LUT4 #(
    .INIT(16'hFF10)) 
    DownLamp_i_2
       (.I0(state[1]),
        .I1(state[0]),
        .I2(runstate0),
        .I3(DownLamp_i_6_n_0),
        .O(DownLamp_i_2_n_0));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT5 #(
    .INIT(32'h00005554)) 
    DownLamp_i_3
       (.I0(runstate1),
        .I1(\DownMax_reg_n_0_[1] ),
        .I2(\DownMax_reg_n_0_[2] ),
        .I3(\DownMax_reg_n_0_[0] ),
        .I4(OpenLamp_i_5_n_0),
        .O(DownLamp_i_3_n_0));
  LUT6 #(
    .INIT(64'h000000002F222F00)) 
    DownLamp_i_4
       (.I0(state3_carry_n_0),
        .I1(CloseLamp_i_3_n_0),
        .I2(\DownMax[2]_i_12_n_0 ),
        .I3(runstate_reg_n_0),
        .I4(\FSM_sequential_state[2]_i_5_n_0 ),
        .I5(state21_in),
        .O(DownLamp4_out));
  LUT6 #(
    .INIT(64'hB2BBBBBB2222B2BA)) 
    DownLamp_i_5
       (.I0(\DownMax_reg_n_0_[2] ),
        .I1(UpMax[2]),
        .I2(\DownMax_reg_n_0_[0] ),
        .I3(UpMax[0]),
        .I4(UpMax[1]),
        .I5(\DownMax_reg_n_0_[1] ),
        .O(runstate0));
  LUT6 #(
    .INIT(64'h0400444404000400)) 
    DownLamp_i_6
       (.I0(state[2]),
        .I1(state[1]),
        .I2(\DownMax[2]_i_12_n_0 ),
        .I3(runstate_reg_n_0),
        .I4(CloseLamp_i_3_n_0),
        .I5(state3_carry_n_0),
        .O(DownLamp_i_6_n_0));
  FDRE #(
    .INIT(1'b0)) 
    DownLamp_reg
       (.C(clk_1s_OBUF_BUFG),
        .CE(DownLamp_i_1_n_0),
        .D(DownLamp_i_2_n_0),
        .Q(DownLamp_OBUF),
        .R(1'b0));
  LUT2 #(
    .INIT(4'h6)) 
    \DownMax[0]_i_1 
       (.I0(\DownMax[2]_i_7_n_0 ),
        .I1(\DownMax[2]_i_6_n_0 ),
        .O(DownMax[0]));
  LUT6 #(
    .INIT(64'h0FF042B42D420FF0)) 
    \DownMax[1]_i_1 
       (.I0(\DownMax[2]_i_2_n_0 ),
        .I1(\DownMax[2]_i_3_n_0 ),
        .I2(\DownMax[2]_i_4_n_0 ),
        .I3(\DownMax[2]_i_5_n_0 ),
        .I4(\DownMax[2]_i_6_n_0 ),
        .I5(\DownMax[2]_i_7_n_0 ),
        .O(\DownMax[1]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h6426242244246426)) 
    \DownMax[2]_i_1 
       (.I0(\DownMax[2]_i_2_n_0 ),
        .I1(\DownMax[2]_i_3_n_0 ),
        .I2(\DownMax[2]_i_4_n_0 ),
        .I3(\DownMax[2]_i_5_n_0 ),
        .I4(\DownMax[2]_i_6_n_0 ),
        .I5(\DownMax[2]_i_7_n_0 ),
        .O(DownMax[2]));
  LUT6 #(
    .INIT(64'h99999999FFFF99F8)) 
    \DownMax[2]_i_10 
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(CurrentStair_OBUF[0]),
        .I2(UpButton1_IBUF),
        .I3(UpButton3_IBUF),
        .I4(UpButton5_IBUF),
        .I5(UpButton7_IBUF),
        .O(\DownMax[2]_i_10_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT4 #(
    .INIT(16'h5551)) 
    \DownMax[2]_i_11 
       (.I0(UpButton7_IBUF),
        .I1(UpButton1_IBUF),
        .I2(UpButton5_IBUF),
        .I3(UpButton3_IBUF),
        .O(\DownMax[2]_i_11_n_0 ));
  LUT6 #(
    .INIT(64'h003000F3003071FF)) 
    \DownMax[2]_i_12 
       (.I0(DownButton4_IBUF),
        .I1(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I2(CurrentStair_OBUF[0]),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I4(DownButton8_IBUF),
        .I5(DownButton6_IBUF),
        .O(\DownMax[2]_i_12_n_0 ));
  LUT6 #(
    .INIT(64'h999999996666996A)) 
    \DownMax[2]_i_13 
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(CurrentStair_OBUF[0]),
        .I2(UpButton1_IBUF),
        .I3(UpButton3_IBUF),
        .I4(UpButton5_IBUF),
        .I5(UpButton7_IBUF),
        .O(\DownMax[2]_i_13_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair9" *) 
  LUT5 #(
    .INIT(32'h55555556)) 
    \DownMax[2]_i_14 
       (.I0(CurrentStair_OBUF[0]),
        .I1(UpButton7_IBUF),
        .I2(UpButton5_IBUF),
        .I3(UpButton3_IBUF),
        .I4(UpButton1_IBUF),
        .O(\DownMax[2]_i_14_n_0 ));
  LUT6 #(
    .INIT(64'h00B23000F30000B2)) 
    \DownMax[2]_i_2 
       (.I0(\DownMax[2]_i_8_n_0 ),
        .I1(\DownMax[2]_i_9_n_0 ),
        .I2(CurrentStair_OBUF[3]),
        .I3(\DownMax[2]_i_10_n_0 ),
        .I4(CurrentStair_OBUF[2]),
        .I5(\DownMax[2]_i_11_n_0 ),
        .O(\DownMax[2]_i_2_n_0 ));
  LUT4 #(
    .INIT(16'hF800)) 
    \DownMax[2]_i_3 
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(DownButton6_IBUF),
        .I2(DownButton8_IBUF),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .O(\DownMax[2]_i_3_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT5 #(
    .INIT(32'hBEBBBEBE)) 
    \DownMax[2]_i_4 
       (.I0(\DownMax[2]_i_12_n_0 ),
        .I1(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I2(DownButton8_IBUF),
        .I3(DownButton6_IBUF),
        .I4(DownButton4_IBUF),
        .O(\DownMax[2]_i_4_n_0 ));
  LUT6 #(
    .INIT(64'hBAFBAAAAFFFFBAFB)) 
    \DownMax[2]_i_5 
       (.I0(\DownMax[2]_i_13_n_0 ),
        .I1(\DownMax[2]_i_8_n_0 ),
        .I2(\DownMax[2]_i_11_n_0 ),
        .I3(CurrentStair_OBUF[2]),
        .I4(\DownMax[2]_i_9_n_0 ),
        .I5(CurrentStair_OBUF[3]),
        .O(\DownMax[2]_i_5_n_0 ));
  LUT2 #(
    .INIT(4'h1)) 
    \DownMax[2]_i_6 
       (.I0(CurrentStair_OBUF[0]),
        .I1(\DownMax[2]_i_12_n_0 ),
        .O(\DownMax[2]_i_6_n_0 ));
  LUT6 #(
    .INIT(64'h00000000B2FF00B2)) 
    \DownMax[2]_i_7 
       (.I0(\DownMax[2]_i_8_n_0 ),
        .I1(\DownMax[2]_i_11_n_0 ),
        .I2(CurrentStair_OBUF[2]),
        .I3(\DownMax[2]_i_9_n_0 ),
        .I4(CurrentStair_OBUF[3]),
        .I5(\DownMax[2]_i_14_n_0 ),
        .O(\DownMax[2]_i_7_n_0 ));
  LUT6 #(
    .INIT(64'hFFFE000045444544)) 
    \DownMax[2]_i_8 
       (.I0(UpButton7_IBUF),
        .I1(UpButton5_IBUF),
        .I2(UpButton3_IBUF),
        .I3(UpButton1_IBUF),
        .I4(CurrentStair_OBUF[0]),
        .I5(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(\DownMax[2]_i_8_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair9" *) 
  LUT4 #(
    .INIT(16'h0002)) 
    \DownMax[2]_i_9 
       (.I0(UpButton1_IBUF),
        .I1(UpButton3_IBUF),
        .I2(UpButton5_IBUF),
        .I3(UpButton7_IBUF),
        .O(\DownMax[2]_i_9_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \DownMax_reg[0] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(DownMax[0]),
        .Q(\DownMax_reg_n_0_[0] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \DownMax_reg[1] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\DownMax[1]_i_1_n_0 ),
        .Q(\DownMax_reg_n_0_[1] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \DownMax_reg[2] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(DownMax[2]),
        .Q(\DownMax_reg_n_0_[2] ),
        .R(1'b0));
  LUT6 #(
    .INIT(64'hFFF0335500003355)) 
    \FSM_sequential_state[0]_i_1 
       (.I0(\FSM_sequential_state_reg[0]_i_2_n_0 ),
        .I1(\FSM_sequential_state[0]_i_3_n_0 ),
        .I2(state[0]),
        .I3(state[1]),
        .I4(state[2]),
        .I5(state[0]),
        .O(\FSM_sequential_state[0]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'hFFF0FFF0FFF022F0)) 
    \FSM_sequential_state[0]_i_3 
       (.I0(CloseLamp_i_3_n_0),
        .I1(state1),
        .I2(\FSM_sequential_state[0]_i_6_n_0 ),
        .I3(state[0]),
        .I4(\FSM_sequential_state[1]_i_8_n_0 ),
        .I5(state21_in),
        .O(\FSM_sequential_state[0]_i_3_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFF01)) 
    \FSM_sequential_state[0]_i_4 
       (.I0(\DownMax_reg_n_0_[0] ),
        .I1(\DownMax_reg_n_0_[2] ),
        .I2(\DownMax_reg_n_0_[1] ),
        .I3(runstate1),
        .I4(OpenLamp_i_5_n_0),
        .O(\FSM_sequential_state[0]_i_4_n_0 ));
  LUT5 #(
    .INIT(32'h00000002)) 
    \FSM_sequential_state[0]_i_5 
       (.I0(Q[0]),
        .I1(Q[1]),
        .I2(Q[3]),
        .I3(OpenLamp_i_8_n_0),
        .I4(Q[2]),
        .O(\FSM_sequential_state[0]_i_5_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair22" *) 
  LUT2 #(
    .INIT(4'hB)) 
    \FSM_sequential_state[0]_i_6 
       (.I0(OpenButton_IBUF),
        .I1(OpenLamp1),
        .O(\FSM_sequential_state[0]_i_6_n_0 ));
  LUT6 #(
    .INIT(64'hF0FFF8F8F000F8F8)) 
    \FSM_sequential_state[1]_i_1 
       (.I0(\FSM_sequential_state[1]_i_2_n_0 ),
        .I1(\FSM_sequential_state[1]_i_3_n_0 ),
        .I2(\FSM_sequential_state[1]_i_4_n_0 ),
        .I3(\FSM_sequential_state[1]_i_5_n_0 ),
        .I4(state[2]),
        .I5(state[1]),
        .O(\FSM_sequential_state[1]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair16" *) 
  LUT4 #(
    .INIT(16'hF888)) 
    \FSM_sequential_state[1]_i_10 
       (.I0(runstate2[4]),
        .I1(UpButton3_IBUF),
        .I2(runstate2[6]),
        .I3(UpButton1_IBUF),
        .O(\FSM_sequential_state[1]_i_10_n_0 ));
  LUT4 #(
    .INIT(16'hF888)) 
    \FSM_sequential_state[1]_i_11 
       (.I0(runstate2[5]),
        .I1(DownButton2_IBUF),
        .I2(runstate2[3]),
        .I3(DownButton4_IBUF),
        .O(\FSM_sequential_state[1]_i_11_n_0 ));
  LUT6 #(
    .INIT(64'h0F0FF25200000000)) 
    \FSM_sequential_state[1]_i_12 
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(\CurrentStair_OBUF[1]_inst_i_2_n_0 ),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I3(\CountDown[3]_i_10_n_0 ),
        .I4(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I5(\UpMax[2]_i_4_n_0 ),
        .O(\FSM_sequential_state[1]_i_12_n_0 ));
  LUT3 #(
    .INIT(8'hFE)) 
    \FSM_sequential_state[1]_i_2 
       (.I0(\FSM_sequential_state[1]_i_6_n_0 ),
        .I1(\FSM_sequential_state[1]_i_7_n_0 ),
        .I2(state[1]),
        .O(\FSM_sequential_state[1]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h5555555555555575)) 
    \FSM_sequential_state[1]_i_3 
       (.I0(state[0]),
        .I1(state1),
        .I2(state[1]),
        .I3(\FSM_sequential_state[1]_i_8_n_0 ),
        .I4(state21_in),
        .I5(CloseLamp_i_3_n_0),
        .O(\FSM_sequential_state[1]_i_3_n_0 ));
  LUT5 #(
    .INIT(32'h00000001)) 
    \FSM_sequential_state[1]_i_4 
       (.I0(state[1]),
        .I1(Q[3]),
        .I2(\FSM_sequential_state[1]_i_9_n_0 ),
        .I3(Q[1]),
        .I4(Q[2]),
        .O(\FSM_sequential_state[1]_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h1)) 
    \FSM_sequential_state[1]_i_5 
       (.I0(state[1]),
        .I1(state[0]),
        .O(\FSM_sequential_state[1]_i_5_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFF888)) 
    \FSM_sequential_state[1]_i_6 
       (.I0(UpButton5_IBUF),
        .I1(runstate2[2]),
        .I2(UpButton7_IBUF),
        .I3(runstate2[0]),
        .I4(\FSM_sequential_state[1]_i_10_n_0 ),
        .O(\FSM_sequential_state[1]_i_6_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFF888)) 
    \FSM_sequential_state[1]_i_7 
       (.I0(DownButton6_IBUF),
        .I1(runstate2[1]),
        .I2(DownButton8_IBUF),
        .I3(runstate22_in),
        .I4(\FSM_sequential_state[1]_i_11_n_0 ),
        .O(\FSM_sequential_state[1]_i_7_n_0 ));
  LUT6 #(
    .INIT(64'h5110515110105110)) 
    \FSM_sequential_state[1]_i_8 
       (.I0(runstate_reg_n_0),
        .I1(CurrentStair_OBUF[3]),
        .I2(UpButton1_IBUF),
        .I3(\UpMax[2]_i_5_n_0 ),
        .I4(CurrentStair_OBUF[2]),
        .I5(\FSM_sequential_state[1]_i_12_n_0 ),
        .O(\FSM_sequential_state[1]_i_8_n_0 ));
  LUT5 #(
    .INIT(32'hDD0DFFFF)) 
    \FSM_sequential_state[1]_i_9 
       (.I0(state[2]),
        .I1(OpenLamp_i_6_n_0),
        .I2(state[0]),
        .I3(OpenLamp_i_8_n_0),
        .I4(Q[0]),
        .O(\FSM_sequential_state[1]_i_9_n_0 ));
  LUT6 #(
    .INIT(64'hFFFAC00A000AC00A)) 
    \FSM_sequential_state[2]_i_1 
       (.I0(\FSM_sequential_state[2]_i_2_n_0 ),
        .I1(state13_out),
        .I2(state[0]),
        .I3(state[1]),
        .I4(state[2]),
        .I5(state[2]),
        .O(\FSM_sequential_state[2]_i_1_n_0 ));
  LUT4 #(
    .INIT(16'h88B8)) 
    \FSM_sequential_state[2]_i_2 
       (.I0(\FSM_sequential_state[2]_i_4_n_0 ),
        .I1(state[2]),
        .I2(runstate1),
        .I3(OpenLamp_i_5_n_0),
        .O(\FSM_sequential_state[2]_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair18" *) 
  LUT3 #(
    .INIT(8'hAB)) 
    \FSM_sequential_state[2]_i_3 
       (.I0(state21_in),
        .I1(\FSM_sequential_state[2]_i_5_n_0 ),
        .I2(runstate_reg_n_0),
        .O(state13_out));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT5 #(
    .INIT(32'hFFFFFFFD)) 
    \FSM_sequential_state[2]_i_4 
       (.I0(Q[0]),
        .I1(Q[1]),
        .I2(Q[3]),
        .I3(OpenLamp_i_6_n_0),
        .I4(Q[2]),
        .O(\FSM_sequential_state[2]_i_4_n_0 ));
  LUT6 #(
    .INIT(64'h00000400CD4CFFDF)) 
    \FSM_sequential_state[2]_i_5 
       (.I0(\UpMax[2]_i_4_n_0 ),
        .I1(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I2(CurrentStair_OBUF[0]),
        .I3(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I4(\UpMax[2]_i_5_n_0 ),
        .I5(UpButton1_IBUF),
        .O(\FSM_sequential_state[2]_i_5_n_0 ));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_state_reg[0] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\FSM_sequential_state[0]_i_1_n_0 ),
        .Q(state[0]),
        .R(1'b0));
  MUXF7 \FSM_sequential_state_reg[0]_i_2 
       (.I0(\FSM_sequential_state[0]_i_4_n_0 ),
        .I1(\FSM_sequential_state[0]_i_5_n_0 ),
        .O(\FSM_sequential_state_reg[0]_i_2_n_0 ),
        .S(state[0]));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_state_reg[1] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\FSM_sequential_state[1]_i_1_n_0 ),
        .Q(state[1]),
        .R(1'b0));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_state_reg[2] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\FSM_sequential_state[2]_i_1_n_0 ),
        .Q(state[2]),
        .R(1'b0));
  CARRY4 K0_carry
       (.CI(1'b0),
        .CO({K0_carry_n_0,K0_carry_n_1,K0_carry_n_2,K0_carry_n_3}),
        .CYINIT(K[0]),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(K0[4:1]),
        .S(K[4:1]));
  CARRY4 K0_carry__0
       (.CI(K0_carry_n_0),
        .CO({K0_carry__0_n_0,K0_carry__0_n_1,K0_carry__0_n_2,K0_carry__0_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(K0[8:5]),
        .S(K[8:5]));
  CARRY4 K0_carry__1
       (.CI(K0_carry__0_n_0),
        .CO({K0_carry__1_n_0,K0_carry__1_n_1,K0_carry__1_n_2,K0_carry__1_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(K0[12:9]),
        .S(K[12:9]));
  CARRY4 K0_carry__2
       (.CI(K0_carry__1_n_0),
        .CO({K0_carry__2_n_0,K0_carry__2_n_1,K0_carry__2_n_2,K0_carry__2_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(K0[16:13]),
        .S(K[16:13]));
  CARRY4 K0_carry__3
       (.CI(K0_carry__2_n_0),
        .CO({K0_carry__3_n_0,K0_carry__3_n_1,K0_carry__3_n_2,K0_carry__3_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(K0[20:17]),
        .S(K[20:17]));
  CARRY4 K0_carry__4
       (.CI(K0_carry__3_n_0),
        .CO({K0_carry__4_n_0,K0_carry__4_n_1,K0_carry__4_n_2,K0_carry__4_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(K0[24:21]),
        .S(K[24:21]));
  CARRY4 K0_carry__5
       (.CI(K0_carry__4_n_0),
        .CO({K0_carry__5_n_0,K0_carry__5_n_1,K0_carry__5_n_2,K0_carry__5_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(K0[28:25]),
        .S(K[28:25]));
  CARRY4 K0_carry__6
       (.CI(K0_carry__5_n_0),
        .CO({NLW_K0_carry__6_CO_UNCONNECTED[3:2],K0_carry__6_n_2,K0_carry__6_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({NLW_K0_carry__6_O_UNCONNECTED[3],K0[31:29]}),
        .S({1'b0,K[31:29]}));
  (* SOFT_HLUTNM = "soft_lutpair21" *) 
  LUT2 #(
    .INIT(4'h1)) 
    \K[0]_i_1 
       (.I0(K[0]),
        .I1(OpenButton_IBUF),
        .O(\K[0]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair28" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[10]_i_1 
       (.I0(K0[10]),
        .I1(OpenButton_IBUF),
        .O(\K[10]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair28" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[11]_i_1 
       (.I0(K0[11]),
        .I1(OpenButton_IBUF),
        .O(\K[11]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair29" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[12]_i_1 
       (.I0(K0[12]),
        .I1(OpenButton_IBUF),
        .O(\K[12]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair30" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[13]_i_1 
       (.I0(K0[13]),
        .I1(OpenButton_IBUF),
        .O(\K[13]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair31" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[14]_i_1 
       (.I0(K0[14]),
        .I1(OpenButton_IBUF),
        .O(\K[14]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair31" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[15]_i_1 
       (.I0(K0[15]),
        .I1(OpenButton_IBUF),
        .O(\K[15]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair32" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[16]_i_1 
       (.I0(K0[16]),
        .I1(OpenButton_IBUF),
        .O(\K[16]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair32" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[17]_i_1 
       (.I0(K0[17]),
        .I1(OpenButton_IBUF),
        .O(\K[17]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair33" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[18]_i_1 
       (.I0(K0[18]),
        .I1(OpenButton_IBUF),
        .O(\K[18]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair34" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[19]_i_1 
       (.I0(K0[19]),
        .I1(OpenButton_IBUF),
        .O(\K[19]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair23" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[1]_i_1 
       (.I0(K0[1]),
        .I1(OpenButton_IBUF),
        .O(\K[1]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair27" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[20]_i_1 
       (.I0(K0[20]),
        .I1(OpenButton_IBUF),
        .O(\K[20]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair35" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[21]_i_1 
       (.I0(K0[21]),
        .I1(OpenButton_IBUF),
        .O(\K[21]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair25" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[22]_i_1 
       (.I0(K0[22]),
        .I1(OpenButton_IBUF),
        .O(\K[22]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair35" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[23]_i_1 
       (.I0(K0[23]),
        .I1(OpenButton_IBUF),
        .O(\K[23]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair23" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[24]_i_1 
       (.I0(K0[24]),
        .I1(OpenButton_IBUF),
        .O(\K[24]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair36" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[25]_i_1 
       (.I0(K0[25]),
        .I1(OpenButton_IBUF),
        .O(\K[25]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair34" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[26]_i_1 
       (.I0(K0[26]),
        .I1(OpenButton_IBUF),
        .O(\K[26]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair29" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[27]_i_1 
       (.I0(K0[27]),
        .I1(OpenButton_IBUF),
        .O(\K[27]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair30" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[28]_i_1 
       (.I0(K0[28]),
        .I1(OpenButton_IBUF),
        .O(\K[28]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair33" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[29]_i_1 
       (.I0(K0[29]),
        .I1(OpenButton_IBUF),
        .O(\K[29]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair24" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[2]_i_1 
       (.I0(K0[2]),
        .I1(OpenButton_IBUF),
        .O(\K[2]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair36" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[30]_i_1 
       (.I0(K0[30]),
        .I1(OpenButton_IBUF),
        .O(\K[30]_i_1_n_0 ));
  LUT4 #(
    .INIT(16'h0200)) 
    \K[31]_i_1 
       (.I0(OpenLamp1),
        .I1(state[0]),
        .I2(state[2]),
        .I3(state[1]),
        .O(\K[31]_i_1_n_0 ));
  LUT3 #(
    .INIT(8'h02)) 
    \K[31]_i_2 
       (.I0(state[1]),
        .I1(state[2]),
        .I2(state[0]),
        .O(K_0));
  LUT2 #(
    .INIT(4'h2)) 
    \K[31]_i_3 
       (.I0(K0[31]),
        .I1(OpenButton_IBUF),
        .O(\K[31]_i_3_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair25" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[3]_i_1 
       (.I0(K0[3]),
        .I1(OpenButton_IBUF),
        .O(\K[3]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair26" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[4]_i_1 
       (.I0(K0[4]),
        .I1(OpenButton_IBUF),
        .O(\K[4]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair21" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[5]_i_1 
       (.I0(K0[5]),
        .I1(OpenButton_IBUF),
        .O(\K[5]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair22" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[6]_i_1 
       (.I0(K0[6]),
        .I1(OpenButton_IBUF),
        .O(\K[6]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair24" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[7]_i_1 
       (.I0(K0[7]),
        .I1(OpenButton_IBUF),
        .O(\K[7]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair26" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[8]_i_1 
       (.I0(K0[8]),
        .I1(OpenButton_IBUF),
        .O(\K[8]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair27" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \K[9]_i_1 
       (.I0(K0[9]),
        .I1(OpenButton_IBUF),
        .O(\K[9]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[0] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[0]_i_1_n_0 ),
        .Q(K[0]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[10] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[10]_i_1_n_0 ),
        .Q(K[10]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[11] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[11]_i_1_n_0 ),
        .Q(K[11]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[12] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[12]_i_1_n_0 ),
        .Q(K[12]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[13] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[13]_i_1_n_0 ),
        .Q(K[13]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[14] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[14]_i_1_n_0 ),
        .Q(K[14]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[15] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[15]_i_1_n_0 ),
        .Q(K[15]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[16] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[16]_i_1_n_0 ),
        .Q(K[16]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[17] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[17]_i_1_n_0 ),
        .Q(K[17]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[18] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[18]_i_1_n_0 ),
        .Q(K[18]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[19] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[19]_i_1_n_0 ),
        .Q(K[19]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[1] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[1]_i_1_n_0 ),
        .Q(K[1]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[20] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[20]_i_1_n_0 ),
        .Q(K[20]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[21] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[21]_i_1_n_0 ),
        .Q(K[21]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[22] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[22]_i_1_n_0 ),
        .Q(K[22]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[23] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[23]_i_1_n_0 ),
        .Q(K[23]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[24] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[24]_i_1_n_0 ),
        .Q(K[24]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[25] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[25]_i_1_n_0 ),
        .Q(K[25]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[26] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[26]_i_1_n_0 ),
        .Q(K[26]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[27] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[27]_i_1_n_0 ),
        .Q(K[27]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[28] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[28]_i_1_n_0 ),
        .Q(K[28]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[29] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[29]_i_1_n_0 ),
        .Q(K[29]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[2] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[2]_i_1_n_0 ),
        .Q(K[2]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[30] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[30]_i_1_n_0 ),
        .Q(K[30]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[31] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[31]_i_3_n_0 ),
        .Q(K[31]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[3] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[3]_i_1_n_0 ),
        .Q(K[3]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[4] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[4]_i_1_n_0 ),
        .Q(K[4]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[5] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[5]_i_1_n_0 ),
        .Q(K[5]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[6] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[6]_i_1_n_0 ),
        .Q(K[6]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[7] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[7]_i_1_n_0 ),
        .Q(K[7]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[8] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[8]_i_1_n_0 ),
        .Q(K[8]),
        .R(\K[31]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \K_reg[9] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(K_0),
        .D(\K[9]_i_1_n_0 ),
        .Q(K[9]),
        .R(\K[31]_i_1_n_0 ));
  CARRY4 OpenLamp1_carry
       (.CI(1'b0),
        .CO({OpenLamp1_carry_n_0,OpenLamp1_carry_n_1,OpenLamp1_carry_n_2,OpenLamp1_carry_n_3}),
        .CYINIT(1'b1),
        .DI({OpenLamp1_carry_i_1_n_0,OpenLamp1_carry_i_2_n_0,K[3],K[1]}),
        .O(NLW_OpenLamp1_carry_O_UNCONNECTED[3:0]),
        .S({OpenLamp1_carry_i_3_n_0,OpenLamp1_carry_i_4_n_0,OpenLamp1_carry_i_5_n_0,OpenLamp1_carry_i_6_n_0}));
  CARRY4 OpenLamp1_carry__0
       (.CI(OpenLamp1_carry_n_0),
        .CO({OpenLamp1_carry__0_n_0,OpenLamp1_carry__0_n_1,OpenLamp1_carry__0_n_2,OpenLamp1_carry__0_n_3}),
        .CYINIT(1'b0),
        .DI({OpenLamp1_carry__0_i_1_n_0,OpenLamp1_carry__0_i_2_n_0,OpenLamp1_carry__0_i_3_n_0,OpenLamp1_carry__0_i_4_n_0}),
        .O(NLW_OpenLamp1_carry__0_O_UNCONNECTED[3:0]),
        .S({OpenLamp1_carry__0_i_5_n_0,OpenLamp1_carry__0_i_6_n_0,OpenLamp1_carry__0_i_7_n_0,OpenLamp1_carry__0_i_8_n_0}));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__0_i_1
       (.I0(K[14]),
        .I1(K[15]),
        .O(OpenLamp1_carry__0_i_1_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__0_i_2
       (.I0(K[12]),
        .I1(K[13]),
        .O(OpenLamp1_carry__0_i_2_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__0_i_3
       (.I0(K[10]),
        .I1(K[11]),
        .O(OpenLamp1_carry__0_i_3_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__0_i_4
       (.I0(K[8]),
        .I1(K[9]),
        .O(OpenLamp1_carry__0_i_4_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__0_i_5
       (.I0(K[14]),
        .I1(K[15]),
        .O(OpenLamp1_carry__0_i_5_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__0_i_6
       (.I0(K[12]),
        .I1(K[13]),
        .O(OpenLamp1_carry__0_i_6_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__0_i_7
       (.I0(K[10]),
        .I1(K[11]),
        .O(OpenLamp1_carry__0_i_7_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__0_i_8
       (.I0(K[8]),
        .I1(K[9]),
        .O(OpenLamp1_carry__0_i_8_n_0));
  CARRY4 OpenLamp1_carry__1
       (.CI(OpenLamp1_carry__0_n_0),
        .CO({OpenLamp1_carry__1_n_0,OpenLamp1_carry__1_n_1,OpenLamp1_carry__1_n_2,OpenLamp1_carry__1_n_3}),
        .CYINIT(1'b0),
        .DI({OpenLamp1_carry__1_i_1_n_0,OpenLamp1_carry__1_i_2_n_0,OpenLamp1_carry__1_i_3_n_0,OpenLamp1_carry__1_i_4_n_0}),
        .O(NLW_OpenLamp1_carry__1_O_UNCONNECTED[3:0]),
        .S({OpenLamp1_carry__1_i_5_n_0,OpenLamp1_carry__1_i_6_n_0,OpenLamp1_carry__1_i_7_n_0,OpenLamp1_carry__1_i_8_n_0}));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__1_i_1
       (.I0(K[22]),
        .I1(K[23]),
        .O(OpenLamp1_carry__1_i_1_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__1_i_2
       (.I0(K[20]),
        .I1(K[21]),
        .O(OpenLamp1_carry__1_i_2_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__1_i_3
       (.I0(K[18]),
        .I1(K[19]),
        .O(OpenLamp1_carry__1_i_3_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__1_i_4
       (.I0(K[16]),
        .I1(K[17]),
        .O(OpenLamp1_carry__1_i_4_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__1_i_5
       (.I0(K[22]),
        .I1(K[23]),
        .O(OpenLamp1_carry__1_i_5_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__1_i_6
       (.I0(K[20]),
        .I1(K[21]),
        .O(OpenLamp1_carry__1_i_6_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__1_i_7
       (.I0(K[18]),
        .I1(K[19]),
        .O(OpenLamp1_carry__1_i_7_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__1_i_8
       (.I0(K[16]),
        .I1(K[17]),
        .O(OpenLamp1_carry__1_i_8_n_0));
  CARRY4 OpenLamp1_carry__2
       (.CI(OpenLamp1_carry__1_n_0),
        .CO({OpenLamp1,OpenLamp1_carry__2_n_1,OpenLamp1_carry__2_n_2,OpenLamp1_carry__2_n_3}),
        .CYINIT(1'b0),
        .DI({OpenLamp1_carry__2_i_1_n_0,OpenLamp1_carry__2_i_2_n_0,OpenLamp1_carry__2_i_3_n_0,OpenLamp1_carry__2_i_4_n_0}),
        .O(NLW_OpenLamp1_carry__2_O_UNCONNECTED[3:0]),
        .S({OpenLamp1_carry__2_i_5_n_0,OpenLamp1_carry__2_i_6_n_0,OpenLamp1_carry__2_i_7_n_0,OpenLamp1_carry__2_i_8_n_0}));
  LUT2 #(
    .INIT(4'h2)) 
    OpenLamp1_carry__2_i_1
       (.I0(K[30]),
        .I1(K[31]),
        .O(OpenLamp1_carry__2_i_1_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__2_i_2
       (.I0(K[28]),
        .I1(K[29]),
        .O(OpenLamp1_carry__2_i_2_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__2_i_3
       (.I0(K[26]),
        .I1(K[27]),
        .O(OpenLamp1_carry__2_i_3_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry__2_i_4
       (.I0(K[24]),
        .I1(K[25]),
        .O(OpenLamp1_carry__2_i_4_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__2_i_5
       (.I0(K[30]),
        .I1(K[31]),
        .O(OpenLamp1_carry__2_i_5_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__2_i_6
       (.I0(K[28]),
        .I1(K[29]),
        .O(OpenLamp1_carry__2_i_6_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__2_i_7
       (.I0(K[26]),
        .I1(K[27]),
        .O(OpenLamp1_carry__2_i_7_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry__2_i_8
       (.I0(K[24]),
        .I1(K[25]),
        .O(OpenLamp1_carry__2_i_8_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry_i_1
       (.I0(K[6]),
        .I1(K[7]),
        .O(OpenLamp1_carry_i_1_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp1_carry_i_2
       (.I0(K[4]),
        .I1(K[5]),
        .O(OpenLamp1_carry_i_2_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry_i_3
       (.I0(K[6]),
        .I1(K[7]),
        .O(OpenLamp1_carry_i_3_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    OpenLamp1_carry_i_4
       (.I0(K[4]),
        .I1(K[5]),
        .O(OpenLamp1_carry_i_4_n_0));
  LUT2 #(
    .INIT(4'h2)) 
    OpenLamp1_carry_i_5
       (.I0(K[2]),
        .I1(K[3]),
        .O(OpenLamp1_carry_i_5_n_0));
  LUT2 #(
    .INIT(4'h2)) 
    OpenLamp1_carry_i_6
       (.I0(K[0]),
        .I1(K[1]),
        .O(OpenLamp1_carry_i_6_n_0));
  LUT6 #(
    .INIT(64'h003330BB00333088)) 
    OpenLamp_i_1
       (.I0(OpenLamp_i_3_n_0),
        .I1(state[0]),
        .I2(OpenLamp_i_4_n_0),
        .I3(state[2]),
        .I4(state[1]),
        .I5(OpenLamp_i_5_n_0),
        .O(OpenLamp_i_1_n_0));
  (* SOFT_HLUTNM = "soft_lutpair14" *) 
  LUT4 #(
    .INIT(16'hF888)) 
    OpenLamp_i_10
       (.I0(DownButton2_IBUF),
        .I1(runstate2[6]),
        .I2(DownButton4_IBUF),
        .I3(runstate2[4]),
        .O(OpenLamp_i_10_n_0));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT5 #(
    .INIT(32'hFFE0E0E0)) 
    OpenLamp_i_11
       (.I0(\StairLamp_reg[7]_0 [0]),
        .I1(DownButton8_IBUF),
        .I2(runstate2[0]),
        .I3(DownButton6_IBUF),
        .I4(runstate2[2]),
        .O(OpenLamp_i_11_n_0));
  LUT5 #(
    .INIT(32'h01FF0100)) 
    OpenLamp_i_2
       (.I0(state[0]),
        .I1(state[1]),
        .I2(OpenLamp_i_6_n_0),
        .I3(state[2]),
        .I4(OpenLamp_i_7_n_0),
        .O(OpenLamp_i_2_n_0));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT5 #(
    .INIT(32'h00000002)) 
    OpenLamp_i_3
       (.I0(Q[0]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[3]),
        .I4(OpenLamp_i_8_n_0),
        .O(OpenLamp_i_3_n_0));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT5 #(
    .INIT(32'h00000002)) 
    OpenLamp_i_4
       (.I0(Q[0]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[3]),
        .I4(OpenLamp_i_6_n_0),
        .O(OpenLamp_i_4_n_0));
  LUT2 #(
    .INIT(4'hE)) 
    OpenLamp_i_5
       (.I0(\FSM_sequential_state[1]_i_7_n_0 ),
        .I1(\FSM_sequential_state[1]_i_6_n_0 ),
        .O(OpenLamp_i_5_n_0));
  LUT6 #(
    .INIT(64'h0000000000077777)) 
    OpenLamp_i_6
       (.I0(UpButton7_IBUF),
        .I1(runstate22_in),
        .I2(\StairLamp_reg[7]_0 [1]),
        .I3(UpButton5_IBUF),
        .I4(runstate2[1]),
        .I5(OpenLamp_i_9_n_0),
        .O(OpenLamp_i_6_n_0));
  LUT6 #(
    .INIT(64'hB0BFBFBFB0BFB0B0)) 
    OpenLamp_i_7
       (.I0(OpenButton_IBUF),
        .I1(OpenLamp1),
        .I2(state[1]),
        .I3(OpenLamp_i_8_n_0),
        .I4(state[0]),
        .I5(OpenLamp_i_5_n_0),
        .O(OpenLamp_i_7_n_0));
  LUT6 #(
    .INIT(64'h0000000000000777)) 
    OpenLamp_i_8
       (.I0(runstate2[5]),
        .I1(\StairLamp_reg[7]_0 [2]),
        .I2(runstate2[3]),
        .I3(\StairLamp_reg[7]_0 [1]),
        .I4(OpenLamp_i_10_n_0),
        .I5(OpenLamp_i_11_n_0),
        .O(OpenLamp_i_8_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFE0E0E0E0E0)) 
    OpenLamp_i_9
       (.I0(\StairLamp_reg[7]_0 [3]),
        .I1(UpButton1_IBUF),
        .I2(runstate2[5]),
        .I3(\StairLamp_reg[7]_0 [2]),
        .I4(UpButton3_IBUF),
        .I5(runstate2[3]),
        .O(OpenLamp_i_9_n_0));
  FDRE #(
    .INIT(1'b0)) 
    OpenLamp_reg
       (.C(clk_1s_OBUF_BUFG),
        .CE(OpenLamp_i_1_n_0),
        .D(OpenLamp_i_2_n_0),
        .Q(OpenLamp_OBUF),
        .R(1'b0));
  (* SOFT_HLUTNM = "soft_lutpair13" *) 
  LUT4 #(
    .INIT(16'hDDD0)) 
    \StairLamp[0]_i_1 
       (.I0(runstate22_in),
        .I1(\StairLamp[7]_i_2_n_0 ),
        .I2(StairButton8_IBUF),
        .I3(\StairLamp_reg[7]_0 [0]),
        .O(\StairLamp[0]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'hFFEFFFEFFFEF0000)) 
    \StairLamp[3]_i_1 
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(CurrentStair_OBUF[0]),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I3(\StairLamp[7]_i_2_n_0 ),
        .I4(StairButton5_IBUF),
        .I5(\StairLamp_reg[7]_0 [1]),
        .O(\StairLamp[3]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'hFFFDFFFDFFFD0000)) 
    \StairLamp[5]_i_1 
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I2(\StairLamp[7]_i_2_n_0 ),
        .I3(CurrentStair_OBUF[0]),
        .I4(StairButton3_IBUF),
        .I5(\StairLamp_reg[7]_0 [2]),
        .O(\StairLamp[5]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'hFDFFFDFFFDFF0000)) 
    \StairLamp[7]_i_1 
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(CurrentStair_OBUF[0]),
        .I2(\StairLamp[7]_i_2_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I4(StairButton1_IBUF),
        .I5(\StairLamp_reg[7]_0 [3]),
        .O(\StairLamp[7]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h0155000001550155)) 
    \StairLamp[7]_i_2 
       (.I0(\StairLamp[7]_i_3_n_0 ),
        .I1(\StairLamp_reg[7]_0 [3]),
        .I2(StairButton1_IBUF),
        .I3(runstate2[6]),
        .I4(\StairLamp[7]_i_4_n_0 ),
        .I5(runstate22_in),
        .O(\StairLamp[7]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hFFFFFFE0E0E0E0E0)) 
    \StairLamp[7]_i_3 
       (.I0(\StairLamp_reg[7]_0 [1]),
        .I1(StairButton5_IBUF),
        .I2(runstate2[2]),
        .I3(\StairLamp_reg[7]_0 [2]),
        .I4(StairButton3_IBUF),
        .I5(runstate2[4]),
        .O(\StairLamp[7]_i_3_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair13" *) 
  LUT2 #(
    .INIT(4'h1)) 
    \StairLamp[7]_i_4 
       (.I0(\StairLamp_reg[7]_0 [0]),
        .I1(StairButton8_IBUF),
        .O(\StairLamp[7]_i_4_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \StairLamp_reg[0] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\StairLamp[0]_i_1_n_0 ),
        .Q(\StairLamp_reg[7]_0 [0]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \StairLamp_reg[3] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\StairLamp[3]_i_1_n_0 ),
        .Q(\StairLamp_reg[7]_0 [1]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \StairLamp_reg[5] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\StairLamp[5]_i_1_n_0 ),
        .Q(\StairLamp_reg[7]_0 [2]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \StairLamp_reg[7] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\StairLamp[7]_i_1_n_0 ),
        .Q(\StairLamp_reg[7]_0 [3]),
        .R(1'b0));
  LUT6 #(
    .INIT(64'h0088008833300030)) 
    UpLamp_i_1
       (.I0(state13_out),
        .I1(state[0]),
        .I2(UpLamp_i_3_n_0),
        .I3(state[2]),
        .I4(OpenLamp_i_4_n_0),
        .I5(state[1]),
        .O(UpLamp_i_1_n_0));
  LUT4 #(
    .INIT(16'h00E2)) 
    UpLamp_i_2
       (.I0(runstate1),
        .I1(state[1]),
        .I2(state13_out),
        .I3(state[2]),
        .O(UpLamp_i_2_n_0));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT2 #(
    .INIT(4'h2)) 
    UpLamp_i_3
       (.I0(runstate1),
        .I1(OpenLamp_i_5_n_0),
        .O(UpLamp_i_3_n_0));
  LUT6 #(
    .INIT(64'h44D40000FFFF44D4)) 
    UpLamp_i_4
       (.I0(\DownMax_reg_n_0_[1] ),
        .I1(UpMax[1]),
        .I2(UpMax[0]),
        .I3(\DownMax_reg_n_0_[0] ),
        .I4(UpMax[2]),
        .I5(\DownMax_reg_n_0_[2] ),
        .O(runstate1));
  FDRE #(
    .INIT(1'b0)) 
    UpLamp_reg
       (.C(clk_1s_OBUF_BUFG),
        .CE(UpLamp_i_1_n_0),
        .D(UpLamp_i_2_n_0),
        .Q(UpLamp_OBUF),
        .R(1'b0));
  LUT6 #(
    .INIT(64'hFFFFB2BBDD4D0000)) 
    \UpMax[0]_i_1 
       (.I0(\UpMax[2]_i_3_n_0 ),
        .I1(\UpMax[2]_i_2_n_0 ),
        .I2(\UpMax[1]_i_2_n_0 ),
        .I3(\UpMax[1]_i_3_n_0 ),
        .I4(\UpMax[0]_i_2_n_0 ),
        .I5(\UpMax[0]_i_3_n_0 ),
        .O(\UpMax[0]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair18" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \UpMax[0]_i_2 
       (.I0(CurrentStair_OBUF[0]),
        .I1(\FSM_sequential_state[2]_i_5_n_0 ),
        .O(\UpMax[0]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h00000002AAAAAAA8)) 
    \UpMax[0]_i_3 
       (.I0(\UpMax[0]_i_4_n_0 ),
        .I1(DownButton8_IBUF),
        .I2(DownButton4_IBUF),
        .I3(DownButton2_IBUF),
        .I4(DownButton6_IBUF),
        .I5(CurrentStair_OBUF[0]),
        .O(\UpMax[0]_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h000F0007033F011F)) 
    \UpMax[0]_i_4 
       (.I0(\UpMax[2]_i_7_n_0 ),
        .I1(\UpMax[2]_i_6_n_0 ),
        .I2(\UpMax[2]_i_8_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I4(CurrentStair_OBUF[0]),
        .I5(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(\UpMax[0]_i_4_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT4 #(
    .INIT(16'hFDB0)) 
    \UpMax[1]_i_1 
       (.I0(\UpMax[2]_i_3_n_0 ),
        .I1(\UpMax[2]_i_2_n_0 ),
        .I2(\UpMax[1]_i_2_n_0 ),
        .I3(\UpMax[1]_i_3_n_0 ),
        .O(\UpMax[1]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h0100101110110700)) 
    \UpMax[1]_i_2 
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(\UpMax[2]_i_8_n_0 ),
        .I2(\UpMax[2]_i_7_n_0 ),
        .I3(CurrentStair_OBUF[0]),
        .I4(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I5(\UpMax[2]_i_6_n_0 ),
        .O(\UpMax[1]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h0000550455550051)) 
    \UpMax[1]_i_3 
       (.I0(\FSM_sequential_state[2]_i_5_n_0 ),
        .I1(UpButton7_IBUF),
        .I2(UpButton5_IBUF),
        .I3(UpButton3_IBUF),
        .I4(UpButton1_IBUF),
        .I5(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(\UpMax[1]_i_3_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT2 #(
    .INIT(4'hE)) 
    \UpMax[2]_i_1 
       (.I0(\UpMax[2]_i_2_n_0 ),
        .I1(\UpMax[2]_i_3_n_0 ),
        .O(\UpMax[2]_i_1_n_0 ));
  LUT5 #(
    .INIT(32'h8A30208A)) 
    \UpMax[2]_i_2 
       (.I0(UpButton1_IBUF),
        .I1(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I2(\UpMax[2]_i_4_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I4(\UpMax[2]_i_5_n_0 ),
        .O(\UpMax[2]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h0000100010000171)) 
    \UpMax[2]_i_3 
       (.I0(\UpMax[2]_i_6_n_0 ),
        .I1(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I2(CurrentStair_OBUF[0]),
        .I3(\UpMax[2]_i_7_n_0 ),
        .I4(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I5(\UpMax[2]_i_8_n_0 ),
        .O(\UpMax[2]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h00F2)) 
    \UpMax[2]_i_4 
       (.I0(UpButton7_IBUF),
        .I1(UpButton5_IBUF),
        .I2(UpButton3_IBUF),
        .I3(UpButton1_IBUF),
        .O(\UpMax[2]_i_4_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair16" *) 
  LUT3 #(
    .INIT(8'h54)) 
    \UpMax[2]_i_5 
       (.I0(UpButton1_IBUF),
        .I1(UpButton3_IBUF),
        .I2(UpButton5_IBUF),
        .O(\UpMax[2]_i_5_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair15" *) 
  LUT3 #(
    .INIT(8'h45)) 
    \UpMax[2]_i_6 
       (.I0(DownButton2_IBUF),
        .I1(DownButton4_IBUF),
        .I2(DownButton6_IBUF),
        .O(\UpMax[2]_i_6_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair15" *) 
  LUT4 #(
    .INIT(16'h0001)) 
    \UpMax[2]_i_7 
       (.I0(DownButton8_IBUF),
        .I1(DownButton4_IBUF),
        .I2(DownButton2_IBUF),
        .I3(DownButton6_IBUF),
        .O(\UpMax[2]_i_7_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair14" *) 
  LUT2 #(
    .INIT(4'h1)) 
    \UpMax[2]_i_8 
       (.I0(DownButton4_IBUF),
        .I1(DownButton2_IBUF),
        .O(\UpMax[2]_i_8_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \UpMax_reg[0] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\UpMax[0]_i_1_n_0 ),
        .Q(UpMax[0]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \UpMax_reg[1] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\UpMax[1]_i_1_n_0 ),
        .Q(UpMax[1]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \UpMax_reg[2] 
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(\UpMax[2]_i_1_n_0 ),
        .Q(UpMax[2]),
        .R(1'b0));
  LUT6 #(
    .INIT(64'h00000000000022E2)) 
    \result_OBUF[7]_inst_i_2 
       (.I0(Q[0]),
        .I1(out[0]),
        .I2(Q[3]),
        .I3(\CountDown[3]_i_5_n_0 ),
        .I4(out[2]),
        .I5(out[1]),
        .O(\result[0] ));
  LUT6 #(
    .INIT(64'h2F20FFFF2F200000)) 
    runstate_i_1
       (.I0(runstate_i_2_n_0),
        .I1(state[2]),
        .I2(state[0]),
        .I3(runstate_i_3_n_0),
        .I4(runstate),
        .I5(runstate_reg_n_0),
        .O(runstate_i_1_n_0));
  LUT6 #(
    .INIT(64'h4444444455555554)) 
    runstate_i_10
       (.I0(\FSM_sequential_state[1]_i_6_n_0 ),
        .I1(\FSM_sequential_state[1]_i_7_n_0 ),
        .I2(\DownMax_reg_n_0_[0] ),
        .I3(\DownMax_reg_n_0_[2] ),
        .I4(\DownMax_reg_n_0_[1] ),
        .I5(runstate1),
        .O(runstate9_out));
  LUT6 #(
    .INIT(64'hBBBABBBABBBABAAA)) 
    runstate_i_11
       (.I0(runstate_i_19_n_0),
        .I1(runstate_i_20_n_0),
        .I2(runstate_i_21_n_0),
        .I3(CurrentStair_OBUF[1]),
        .I4(runstate_i_22_n_0),
        .I5(CloseLamp_i_3_n_0),
        .O(runstate_i_11_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    runstate_i_12
       (.I0(state[2]),
        .I1(\DownMax_reg_n_0_[0] ),
        .I2(\DownMax_reg_n_0_[2] ),
        .I3(\DownMax_reg_n_0_[1] ),
        .I4(runstate1),
        .I5(OpenLamp_i_5_n_0),
        .O(runstate_i_12_n_0));
  (* SOFT_HLUTNM = "soft_lutpair19" *) 
  LUT2 #(
    .INIT(4'h1)) 
    runstate_i_13
       (.I0(\StairLamp_reg[7]_0 [1]),
        .I1(\StairLamp_reg[7]_0 [0]),
        .O(runstate_i_13_n_0));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT4 #(
    .INIT(16'h3332)) 
    runstate_i_14
       (.I0(\StairLamp_reg[7]_0 [1]),
        .I1(\StairLamp_reg[7]_0 [0]),
        .I2(\StairLamp_reg[7]_0 [3]),
        .I3(\StairLamp_reg[7]_0 [2]),
        .O(runstate_i_14_n_0));
  (* SOFT_HLUTNM = "soft_lutpair19" *) 
  LUT3 #(
    .INIT(8'h51)) 
    runstate_i_15
       (.I0(\StairLamp_reg[7]_0 [0]),
        .I1(\StairLamp_reg[7]_0 [2]),
        .I2(\StairLamp_reg[7]_0 [1]),
        .O(runstate_i_15_n_0));
  LUT6 #(
    .INIT(64'hAAAAAAAAFFFBBBFB)) 
    runstate_i_16
       (.I0(runstate_i_23_n_0),
        .I1(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I2(\CurrentStair_OBUF[1]_inst_i_2_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I4(\CountDown[3]_i_10_n_0 ),
        .I5(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .O(runstate_i_16_n_0));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT4 #(
    .INIT(16'h4544)) 
    runstate_i_17
       (.I0(UpButton7_IBUF),
        .I1(UpButton5_IBUF),
        .I2(UpButton3_IBUF),
        .I3(UpButton1_IBUF),
        .O(runstate_i_17_n_0));
  LUT5 #(
    .INIT(32'hAA2AAAAA)) 
    runstate_i_18
       (.I0(\DownMax[2]_i_9_n_0 ),
        .I1(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I2(\CountDown[3]_i_10_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I4(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(runstate_i_18_n_0));
  LUT6 #(
    .INIT(64'h1010F11110101010)) 
    runstate_i_19
       (.I0(\StairLamp_reg[7]_0 [3]),
        .I1(\StairLamp_reg[7]_0 [2]),
        .I2(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I3(\CountDown[3]_i_10_n_0 ),
        .I4(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I5(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(runstate_i_19_n_0));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFD0FF)) 
    runstate_i_2
       (.I0(runstate_i_5_n_0),
        .I1(runstate_i_6_n_0),
        .I2(runstate_i_7_n_0),
        .I3(\DownMax[2]_i_12_n_0 ),
        .I4(runstate_i_8_n_0),
        .I5(runstate_i_9_n_0),
        .O(runstate_i_2_n_0));
  LUT6 #(
    .INIT(64'h00E00000EE0EEE0E)) 
    runstate_i_20
       (.I0(\StairLamp_reg[7]_0 [3]),
        .I1(\StairLamp_reg[7]_0 [2]),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I3(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I4(\CountDown[3]_i_10_n_0 ),
        .I5(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .O(runstate_i_20_n_0));
  (* SOFT_HLUTNM = "soft_lutpair20" *) 
  LUT3 #(
    .INIT(8'h51)) 
    runstate_i_21
       (.I0(\StairLamp_reg[7]_0 [3]),
        .I1(\StairLamp_reg[7]_0 [1]),
        .I2(\StairLamp_reg[7]_0 [2]),
        .O(runstate_i_21_n_0));
  LUT6 #(
    .INIT(64'h00000000FFFF02A2)) 
    runstate_i_22
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(\CurrentStair_OBUF[1]_inst_i_2_n_0 ),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I3(\CountDown[3]_i_10_n_0 ),
        .I4(\CurrentStair_OBUF[3]_inst_i_3_n_0 ),
        .I5(runstate_i_24_n_0),
        .O(runstate_i_22_n_0));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT4 #(
    .INIT(16'h0001)) 
    runstate_i_23
       (.I0(UpButton1_IBUF),
        .I1(UpButton3_IBUF),
        .I2(UpButton5_IBUF),
        .I3(UpButton7_IBUF),
        .O(runstate_i_23_n_0));
  (* SOFT_HLUTNM = "soft_lutpair20" *) 
  LUT3 #(
    .INIT(8'hFE)) 
    runstate_i_24
       (.I0(\StairLamp_reg[7]_0 [3]),
        .I1(\StairLamp_reg[7]_0 [1]),
        .I2(\StairLamp_reg[7]_0 [2]),
        .O(runstate_i_24_n_0));
  LUT6 #(
    .INIT(64'h000000002E222222)) 
    runstate_i_3
       (.I0(runstate9_out),
        .I1(state[2]),
        .I2(\UpMax[0]_i_4_n_0 ),
        .I3(\FSM_sequential_state[2]_i_5_n_0 ),
        .I4(runstate_i_11_n_0),
        .I5(state[1]),
        .O(runstate_i_3_n_0));
  LUT6 #(
    .INIT(64'h0020333000200030)) 
    runstate_i_4
       (.I0(OpenLamp_i_4_n_0),
        .I1(state[1]),
        .I2(runstate_i_12_n_0),
        .I3(state[0]),
        .I4(state[2]),
        .I5(OpenLamp_i_3_n_0),
        .O(runstate));
  LUT6 #(
    .INIT(64'h3075FFFF7F3F7D3C)) 
    runstate_i_5
       (.I0(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I1(CurrentStair_OBUF[0]),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I3(runstate_i_13_n_0),
        .I4(runstate_i_14_n_0),
        .I5(runstate_i_15_n_0),
        .O(runstate_i_5_n_0));
  LUT6 #(
    .INIT(64'hFAFAFBFAAAAAA8AA)) 
    runstate_i_6
       (.I0(CurrentStair_OBUF[3]),
        .I1(\StairLamp_reg[7]_0 [1]),
        .I2(\StairLamp_reg[7]_0 [0]),
        .I3(\StairLamp_reg[7]_0 [3]),
        .I4(\StairLamp_reg[7]_0 [2]),
        .I5(CurrentStair_OBUF[2]),
        .O(runstate_i_6_n_0));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT5 #(
    .INIT(32'hFFFFFFEF)) 
    runstate_i_7
       (.I0(CurrentStair_OBUF[3]),
        .I1(\StairLamp_reg[7]_0 [2]),
        .I2(\StairLamp_reg[7]_0 [3]),
        .I3(\StairLamp_reg[7]_0 [0]),
        .I4(\StairLamp_reg[7]_0 [1]),
        .O(runstate_i_7_n_0));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT5 #(
    .INIT(32'hAAA8AAAA)) 
    runstate_i_8
       (.I0(CurrentStair_OBUF[3]),
        .I1(UpButton7_IBUF),
        .I2(UpButton5_IBUF),
        .I3(UpButton3_IBUF),
        .I4(UpButton1_IBUF),
        .O(runstate_i_8_n_0));
  LUT6 #(
    .INIT(64'h00000000D4FF00D4)) 
    runstate_i_9
       (.I0(runstate_i_16_n_0),
        .I1(CurrentStair_OBUF[1]),
        .I2(runstate_i_17_n_0),
        .I3(\DownMax[2]_i_11_n_0 ),
        .I4(CurrentStair_OBUF[2]),
        .I5(runstate_i_18_n_0),
        .O(runstate_i_9_n_0));
  FDRE #(
    .INIT(1'b0)) 
    runstate_reg
       (.C(clk_1s_OBUF_BUFG),
        .CE(1'b1),
        .D(runstate_i_1_n_0),
        .Q(runstate_reg_n_0),
        .R(1'b0));
  CARRY4 state2_inferred__0_carry
       (.CI(1'b0),
        .CO({state21_in,state2_inferred__0_carry_n_1,state2_inferred__0_carry_n_2,state2_inferred__0_carry_n_3}),
        .CYINIT(1'b0),
        .DI({\StairLamp_reg[7]_0 [3:2],state2_inferred__0_carry_i_1_n_0,state2_inferred__0_carry_i_2_n_0}),
        .O(NLW_state2_inferred__0_carry_O_UNCONNECTED[3:0]),
        .S({state2_inferred__0_carry_i_3_n_0,state2_inferred__0_carry_i_4_n_0,state2_inferred__0_carry_i_5_n_0,state2_inferred__0_carry_i_6_n_0}));
  LUT2 #(
    .INIT(4'h2)) 
    state2_inferred__0_carry_i_1
       (.I0(\StairLamp_reg[7]_0 [1]),
        .I1(CurrentStair_OBUF[3]),
        .O(state2_inferred__0_carry_i_1_n_0));
  LUT3 #(
    .INIT(8'h08)) 
    state2_inferred__0_carry_i_2
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(\StairLamp_reg[7]_0 [0]),
        .I2(CurrentStair_OBUF[0]),
        .O(state2_inferred__0_carry_i_2_n_0));
  LUT1 #(
    .INIT(2'h1)) 
    state2_inferred__0_carry_i_3
       (.I0(\StairLamp_reg[7]_0 [3]),
        .O(state2_inferred__0_carry_i_3_n_0));
  LUT1 #(
    .INIT(2'h1)) 
    state2_inferred__0_carry_i_4
       (.I0(\StairLamp_reg[7]_0 [2]),
        .O(state2_inferred__0_carry_i_4_n_0));
  LUT4 #(
    .INIT(16'h0851)) 
    state2_inferred__0_carry_i_5
       (.I0(\StairLamp_reg[7]_0 [1]),
        .I1(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I2(CurrentStair_OBUF[0]),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .O(state2_inferred__0_carry_i_5_n_0));
  LUT3 #(
    .INIT(8'h42)) 
    state2_inferred__0_carry_i_6
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(\StairLamp_reg[7]_0 [0]),
        .I2(CurrentStair_OBUF[0]),
        .O(state2_inferred__0_carry_i_6_n_0));
  CARRY4 state3_carry
       (.CI(1'b0),
        .CO({state3_carry_n_0,state3_carry_n_1,state3_carry_n_2,state3_carry_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,state3_carry_i_1_n_0,state3_carry_i_2_n_0}),
        .O(NLW_state3_carry_O_UNCONNECTED[3:0]),
        .S({state3_carry_i_3_n_0,state3_carry_i_4_n_0,state3_carry_i_5_n_0,state3_carry_i_6_n_0}));
  LUT4 #(
    .INIT(16'h4544)) 
    state3_carry_i_1
       (.I0(\StairLamp_reg[7]_0 [1]),
        .I1(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .I2(CurrentStair_OBUF[0]),
        .I3(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(state3_carry_i_1_n_0));
  LUT3 #(
    .INIT(8'hA7)) 
    state3_carry_i_2
       (.I0(CurrentStair_OBUF[0]),
        .I1(\StairLamp_reg[7]_0 [0]),
        .I2(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .O(state3_carry_i_2_n_0));
  LUT1 #(
    .INIT(2'h1)) 
    state3_carry_i_3
       (.I0(\StairLamp_reg[7]_0 [3]),
        .O(state3_carry_i_3_n_0));
  LUT1 #(
    .INIT(2'h1)) 
    state3_carry_i_4
       (.I0(\StairLamp_reg[7]_0 [2]),
        .O(state3_carry_i_4_n_0));
  LUT4 #(
    .INIT(16'h0851)) 
    state3_carry_i_5
       (.I0(\StairLamp_reg[7]_0 [1]),
        .I1(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I2(CurrentStair_OBUF[0]),
        .I3(\CurrentStair_OBUF[3]_inst_i_4_n_0 ),
        .O(state3_carry_i_5_n_0));
  LUT3 #(
    .INIT(8'h42)) 
    state3_carry_i_6
       (.I0(\CurrentStair_OBUF[3]_inst_i_2_n_0 ),
        .I1(\StairLamp_reg[7]_0 [0]),
        .I2(CurrentStair_OBUF[0]),
        .O(state3_carry_i_6_n_0));
endmodule

module DLCK_1s
   (RunLamp_OBUF,
    clk_1s_OBUF,
    SR,
    T_IBUF_BUFG);
  output RunLamp_OBUF;
  output clk_1s_OBUF;
  input [0:0]SR;
  input T_IBUF_BUFG;

  wire RunLamp_OBUF;
  wire [0:0]SR;
  wire T_IBUF_BUFG;
  wire clk_1s_OBUF;
  wire clk_1s_i_1_n_0;
  wire [31:1]data0;
  wire [31:0]k;
  wire k0_carry__0_n_0;
  wire k0_carry__0_n_1;
  wire k0_carry__0_n_2;
  wire k0_carry__0_n_3;
  wire k0_carry__1_n_0;
  wire k0_carry__1_n_1;
  wire k0_carry__1_n_2;
  wire k0_carry__1_n_3;
  wire k0_carry__2_n_0;
  wire k0_carry__2_n_1;
  wire k0_carry__2_n_2;
  wire k0_carry__2_n_3;
  wire k0_carry__3_n_0;
  wire k0_carry__3_n_1;
  wire k0_carry__3_n_2;
  wire k0_carry__3_n_3;
  wire k0_carry__4_n_0;
  wire k0_carry__4_n_1;
  wire k0_carry__4_n_2;
  wire k0_carry__4_n_3;
  wire k0_carry__5_n_0;
  wire k0_carry__5_n_1;
  wire k0_carry__5_n_2;
  wire k0_carry__5_n_3;
  wire k0_carry__6_n_2;
  wire k0_carry__6_n_3;
  wire k0_carry_n_0;
  wire k0_carry_n_1;
  wire k0_carry_n_2;
  wire k0_carry_n_3;
  wire \k[31]_i_2_n_0 ;
  wire \k[31]_i_3_n_0 ;
  wire \k[31]_i_4_n_0 ;
  wire \k[31]_i_5_n_0 ;
  wire \k[31]_i_6_n_0 ;
  wire \k[31]_i_7_n_0 ;
  wire \k[31]_i_8_n_0 ;
  wire \k[31]_i_9_n_0 ;
  wire [31:0]k_0;
  wire run;
  wire [3:2]NLW_k0_carry__6_CO_UNCONNECTED;
  wire [3:3]NLW_k0_carry__6_O_UNCONNECTED;

  (* SOFT_HLUTNM = "soft_lutpair52" *) 
  LUT3 #(
    .INIT(8'hE1)) 
    clk_1s_i_1
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(clk_1s_OBUF),
        .O(clk_1s_i_1_n_0));
  FDRE #(
    .INIT(1'b0)) 
    clk_1s_reg
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(clk_1s_i_1_n_0),
        .Q(clk_1s_OBUF),
        .R(SR));
  CARRY4 k0_carry
       (.CI(1'b0),
        .CO({k0_carry_n_0,k0_carry_n_1,k0_carry_n_2,k0_carry_n_3}),
        .CYINIT(k[0]),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[4:1]),
        .S(k[4:1]));
  CARRY4 k0_carry__0
       (.CI(k0_carry_n_0),
        .CO({k0_carry__0_n_0,k0_carry__0_n_1,k0_carry__0_n_2,k0_carry__0_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[8:5]),
        .S(k[8:5]));
  CARRY4 k0_carry__1
       (.CI(k0_carry__0_n_0),
        .CO({k0_carry__1_n_0,k0_carry__1_n_1,k0_carry__1_n_2,k0_carry__1_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[12:9]),
        .S(k[12:9]));
  CARRY4 k0_carry__2
       (.CI(k0_carry__1_n_0),
        .CO({k0_carry__2_n_0,k0_carry__2_n_1,k0_carry__2_n_2,k0_carry__2_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[16:13]),
        .S(k[16:13]));
  CARRY4 k0_carry__3
       (.CI(k0_carry__2_n_0),
        .CO({k0_carry__3_n_0,k0_carry__3_n_1,k0_carry__3_n_2,k0_carry__3_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[20:17]),
        .S(k[20:17]));
  CARRY4 k0_carry__4
       (.CI(k0_carry__3_n_0),
        .CO({k0_carry__4_n_0,k0_carry__4_n_1,k0_carry__4_n_2,k0_carry__4_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[24:21]),
        .S(k[24:21]));
  CARRY4 k0_carry__5
       (.CI(k0_carry__4_n_0),
        .CO({k0_carry__5_n_0,k0_carry__5_n_1,k0_carry__5_n_2,k0_carry__5_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[28:25]),
        .S(k[28:25]));
  CARRY4 k0_carry__6
       (.CI(k0_carry__5_n_0),
        .CO({NLW_k0_carry__6_CO_UNCONNECTED[3:2],k0_carry__6_n_2,k0_carry__6_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({NLW_k0_carry__6_O_UNCONNECTED[3],data0[31:29]}),
        .S({1'b0,k[31:29]}));
  LUT2 #(
    .INIT(4'h2)) 
    \k[0]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .O(k_0[0]));
  (* SOFT_HLUTNM = "soft_lutpair46" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[10]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[10]),
        .O(k_0[10]));
  (* SOFT_HLUTNM = "soft_lutpair48" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[11]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[11]),
        .O(k_0[11]));
  (* SOFT_HLUTNM = "soft_lutpair47" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[12]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[12]),
        .O(k_0[12]));
  (* SOFT_HLUTNM = "soft_lutpair46" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[13]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[13]),
        .O(k_0[13]));
  (* SOFT_HLUTNM = "soft_lutpair45" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[14]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[14]),
        .O(k_0[14]));
  (* SOFT_HLUTNM = "soft_lutpair45" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[15]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[15]),
        .O(k_0[15]));
  (* SOFT_HLUTNM = "soft_lutpair44" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[16]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[16]),
        .O(k_0[16]));
  (* SOFT_HLUTNM = "soft_lutpair44" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[17]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[17]),
        .O(k_0[17]));
  (* SOFT_HLUTNM = "soft_lutpair43" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[18]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[18]),
        .O(k_0[18]));
  (* SOFT_HLUTNM = "soft_lutpair42" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[19]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[19]),
        .O(k_0[19]));
  (* SOFT_HLUTNM = "soft_lutpair52" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[1]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[1]),
        .O(k_0[1]));
  (* SOFT_HLUTNM = "soft_lutpair41" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[20]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[20]),
        .O(k_0[20]));
  (* SOFT_HLUTNM = "soft_lutpair40" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[21]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[21]),
        .O(k_0[21]));
  (* SOFT_HLUTNM = "soft_lutpair39" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[22]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[22]),
        .O(k_0[22]));
  (* SOFT_HLUTNM = "soft_lutpair38" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[23]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[23]),
        .O(k_0[23]));
  (* SOFT_HLUTNM = "soft_lutpair37" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[24]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[24]),
        .O(k_0[24]));
  (* SOFT_HLUTNM = "soft_lutpair43" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[25]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[25]),
        .O(k_0[25]));
  (* SOFT_HLUTNM = "soft_lutpair42" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[26]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[26]),
        .O(k_0[26]));
  (* SOFT_HLUTNM = "soft_lutpair41" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[27]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[27]),
        .O(k_0[27]));
  (* SOFT_HLUTNM = "soft_lutpair40" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[28]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[28]),
        .O(k_0[28]));
  (* SOFT_HLUTNM = "soft_lutpair39" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[29]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[29]),
        .O(k_0[29]));
  (* SOFT_HLUTNM = "soft_lutpair51" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[2]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[2]),
        .O(k_0[2]));
  (* SOFT_HLUTNM = "soft_lutpair38" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[30]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[30]),
        .O(k_0[30]));
  (* SOFT_HLUTNM = "soft_lutpair37" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[31]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[31]),
        .O(k_0[31]));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFEF)) 
    \k[31]_i_2 
       (.I0(\k[31]_i_3_n_0 ),
        .I1(\k[31]_i_4_n_0 ),
        .I2(k[1]),
        .I3(k[30]),
        .I4(k[31]),
        .I5(\k[31]_i_5_n_0 ),
        .O(\k[31]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFFFFFE)) 
    \k[31]_i_3 
       (.I0(\k[31]_i_6_n_0 ),
        .I1(k[3]),
        .I2(k[2]),
        .I3(k[5]),
        .I4(k[4]),
        .I5(\k[31]_i_7_n_0 ),
        .O(\k[31]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_4 
       (.I0(k[27]),
        .I1(k[26]),
        .I2(k[29]),
        .I3(k[28]),
        .O(\k[31]_i_4_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFFFE)) 
    \k[31]_i_5 
       (.I0(k[20]),
        .I1(k[21]),
        .I2(k[18]),
        .I3(k[19]),
        .I4(\k[31]_i_8_n_0 ),
        .O(\k[31]_i_5_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_6 
       (.I0(k[7]),
        .I1(k[6]),
        .I2(k[9]),
        .I3(k[8]),
        .O(\k[31]_i_6_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFFFE)) 
    \k[31]_i_7 
       (.I0(k[12]),
        .I1(k[13]),
        .I2(k[10]),
        .I3(k[11]),
        .I4(\k[31]_i_9_n_0 ),
        .O(\k[31]_i_7_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_8 
       (.I0(k[23]),
        .I1(k[22]),
        .I2(k[25]),
        .I3(k[24]),
        .O(\k[31]_i_8_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_9 
       (.I0(k[15]),
        .I1(k[14]),
        .I2(k[17]),
        .I3(k[16]),
        .O(\k[31]_i_9_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair51" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[3]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[3]),
        .O(k_0[3]));
  (* SOFT_HLUTNM = "soft_lutpair50" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[4]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[4]),
        .O(k_0[4]));
  (* SOFT_HLUTNM = "soft_lutpair50" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[5]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[5]),
        .O(k_0[5]));
  (* SOFT_HLUTNM = "soft_lutpair49" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[6]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[6]),
        .O(k_0[6]));
  (* SOFT_HLUTNM = "soft_lutpair49" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[7]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[7]),
        .O(k_0[7]));
  (* SOFT_HLUTNM = "soft_lutpair48" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[8]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[8]),
        .O(k_0[8]));
  (* SOFT_HLUTNM = "soft_lutpair47" *) 
  LUT3 #(
    .INIT(8'hE0)) 
    \k[9]_i_1 
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .I2(data0[9]),
        .O(k_0[9]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[0] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[0]),
        .Q(k[0]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[10] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[10]),
        .Q(k[10]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[11] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[11]),
        .Q(k[11]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[12] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[12]),
        .Q(k[12]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[13] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[13]),
        .Q(k[13]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[14] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[14]),
        .Q(k[14]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[15] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[15]),
        .Q(k[15]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[16] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[16]),
        .Q(k[16]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[17] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[17]),
        .Q(k[17]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[18] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[18]),
        .Q(k[18]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[19] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[19]),
        .Q(k[19]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[1] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[1]),
        .Q(k[1]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[20] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[20]),
        .Q(k[20]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[21] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[21]),
        .Q(k[21]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[22] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[22]),
        .Q(k[22]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[23] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[23]),
        .Q(k[23]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[24] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[24]),
        .Q(k[24]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[25] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[25]),
        .Q(k[25]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[26] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[26]),
        .Q(k[26]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[27] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[27]),
        .Q(k[27]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[28] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[28]),
        .Q(k[28]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[29] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[29]),
        .Q(k[29]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[2] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[2]),
        .Q(k[2]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[30] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[30]),
        .Q(k[30]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[31] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[31]),
        .Q(k[31]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[3] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[3]),
        .Q(k[3]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[4] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[4]),
        .Q(k[4]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[5] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[5]),
        .Q(k[5]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[6] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[6]),
        .Q(k[6]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[7] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[7]),
        .Q(k[7]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[8] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[8]),
        .Q(k[8]),
        .R(SR));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[9] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_0[9]),
        .Q(k[9]),
        .R(SR));
  LUT2 #(
    .INIT(4'h1)) 
    run_i_1
       (.I0(\k[31]_i_2_n_0 ),
        .I1(k[0]),
        .O(run));
  FDRE #(
    .INIT(1'b0)) 
    run_reg
       (.C(T_IBUF_BUFG),
        .CE(run),
        .D(run),
        .Q(RunLamp_OBUF),
        .R(SR));
endmodule

(* Time = "2" *) 
(* NotValidForBitStream *)
module Main
   (OpenButton,
    CloseButton,
    UpButton1,
    UpButton3,
    UpButton5,
    UpButton7,
    DownButton2,
    DownButton4,
    DownButton6,
    DownButton8,
    StairButton1,
    StairButton3,
    StairButton5,
    StairButton8,
    Reset,
    T,
    OpenLamp,
    CloseLamp,
    UpLamp,
    DownLamp,
    RunLamp,
    StairLamp,
    select,
    result,
    clk_1s,
    CurrentStair,
    CountDown);
  input OpenButton;
  input CloseButton;
  input UpButton1;
  input UpButton3;
  input UpButton5;
  input UpButton7;
  input DownButton2;
  input DownButton4;
  input DownButton6;
  input DownButton8;
  input StairButton1;
  input StairButton3;
  input StairButton5;
  input StairButton8;
  input Reset;
  input T;
  output OpenLamp;
  output CloseLamp;
  output UpLamp;
  output DownLamp;
  output RunLamp;
  output [8:1]StairLamp;
  output [7:0]select;
  output [7:0]result;
  output clk_1s;
  output [3:0]CurrentStair;
  output [3:0]CountDown;

  wire CloseLamp;
  wire CloseLamp_OBUF;
  wire [3:0]CountDown;
  wire [3:0]CountDown_OBUF;
  wire [3:0]CurrentStair;
  wire [3:0]CurrentStair_OBUF;
  wire DownButton2;
  wire DownButton2_IBUF;
  wire DownButton4;
  wire DownButton4_IBUF;
  wire DownButton6;
  wire DownButton6_IBUF;
  wire DownButton8;
  wire DownButton8_IBUF;
  wire DownLamp;
  wire DownLamp_OBUF;
  wire OpenButton;
  wire OpenButton_IBUF;
  wire OpenLamp;
  wire OpenLamp_OBUF;
  wire Reset;
  wire Reset_IBUF;
  wire RunLamp;
  wire RunLamp_OBUF;
  wire StairButton1;
  wire StairButton1_IBUF;
  wire StairButton3;
  wire StairButton3_IBUF;
  wire StairButton5;
  wire StairButton5_IBUF;
  wire StairButton8;
  wire StairButton8_IBUF;
  wire [8:1]StairLamp;
  wire [8:1]StairLamp_OBUF;
  wire T;
  wire T_IBUF;
  wire T_IBUF_BUFG;
  wire UpButton1;
  wire UpButton1_IBUF;
  wire UpButton3;
  wire UpButton3_IBUF;
  wire UpButton5;
  wire UpButton5_IBUF;
  wire UpButton7;
  wire UpButton7_IBUF;
  wire UpLamp;
  wire UpLamp_OBUF;
  wire clk_1s;
  wire clk_1s_OBUF;
  wire clk_1s_OBUF_BUFG;
  wire [7:0]result;
  wire [7:0]result_OBUF;
  wire [7:0]select;
  wire [7:0]select_OBUF;
  wire uCe_n_8;
  wire uPt_n_10;
  wire uPt_n_8;
  wire uPt_n_9;

initial begin
 $sdf_annotate("Main_tb_time_synth.sdf",,,,"tool_control");
end
  OBUF CloseLamp_OBUF_inst
       (.I(CloseLamp_OBUF),
        .O(CloseLamp));
  OBUF \CountDown_OBUF[0]_inst 
       (.I(CountDown_OBUF[0]),
        .O(CountDown[0]));
  OBUF \CountDown_OBUF[1]_inst 
       (.I(CountDown_OBUF[1]),
        .O(CountDown[1]));
  OBUF \CountDown_OBUF[2]_inst 
       (.I(CountDown_OBUF[2]),
        .O(CountDown[2]));
  OBUF \CountDown_OBUF[3]_inst 
       (.I(CountDown_OBUF[3]),
        .O(CountDown[3]));
  OBUF \CurrentStair_OBUF[0]_inst 
       (.I(CurrentStair_OBUF[0]),
        .O(CurrentStair[0]));
  OBUF \CurrentStair_OBUF[1]_inst 
       (.I(CurrentStair_OBUF[1]),
        .O(CurrentStair[1]));
  OBUF \CurrentStair_OBUF[2]_inst 
       (.I(CurrentStair_OBUF[2]),
        .O(CurrentStair[2]));
  OBUF \CurrentStair_OBUF[3]_inst 
       (.I(CurrentStair_OBUF[3]),
        .O(CurrentStair[3]));
  IBUF DownButton2_IBUF_inst
       (.I(DownButton2),
        .O(DownButton2_IBUF));
  IBUF DownButton4_IBUF_inst
       (.I(DownButton4),
        .O(DownButton4_IBUF));
  IBUF DownButton6_IBUF_inst
       (.I(DownButton6),
        .O(DownButton6_IBUF));
  IBUF DownButton8_IBUF_inst
       (.I(DownButton8),
        .O(DownButton8_IBUF));
  OBUF DownLamp_OBUF_inst
       (.I(DownLamp_OBUF),
        .O(DownLamp));
  IBUF OpenButton_IBUF_inst
       (.I(OpenButton),
        .O(OpenButton_IBUF));
  OBUF OpenLamp_OBUF_inst
       (.I(OpenLamp_OBUF),
        .O(OpenLamp));
  IBUF Reset_IBUF_inst
       (.I(Reset),
        .O(Reset_IBUF));
  OBUF RunLamp_OBUF_inst
       (.I(RunLamp_OBUF),
        .O(RunLamp));
  IBUF StairButton1_IBUF_inst
       (.I(StairButton1),
        .O(StairButton1_IBUF));
  IBUF StairButton3_IBUF_inst
       (.I(StairButton3),
        .O(StairButton3_IBUF));
  IBUF StairButton5_IBUF_inst
       (.I(StairButton5),
        .O(StairButton5_IBUF));
  IBUF StairButton8_IBUF_inst
       (.I(StairButton8),
        .O(StairButton8_IBUF));
  OBUF \StairLamp_OBUF[1]_inst 
       (.I(StairLamp_OBUF[1]),
        .O(StairLamp[1]));
  OBUF \StairLamp_OBUF[2]_inst 
       (.I(1'b0),
        .O(StairLamp[2]));
  OBUF \StairLamp_OBUF[3]_inst 
       (.I(1'b0),
        .O(StairLamp[3]));
  OBUF \StairLamp_OBUF[4]_inst 
       (.I(StairLamp_OBUF[4]),
        .O(StairLamp[4]));
  OBUF \StairLamp_OBUF[5]_inst 
       (.I(1'b0),
        .O(StairLamp[5]));
  OBUF \StairLamp_OBUF[6]_inst 
       (.I(StairLamp_OBUF[6]),
        .O(StairLamp[6]));
  OBUF \StairLamp_OBUF[7]_inst 
       (.I(1'b0),
        .O(StairLamp[7]));
  OBUF \StairLamp_OBUF[8]_inst 
       (.I(StairLamp_OBUF[8]),
        .O(StairLamp[8]));
  BUFG T_IBUF_BUFG_inst
       (.I(T_IBUF),
        .O(T_IBUF_BUFG));
  IBUF T_IBUF_inst
       (.I(T),
        .O(T_IBUF));
  IBUF UpButton1_IBUF_inst
       (.I(UpButton1),
        .O(UpButton1_IBUF));
  IBUF UpButton3_IBUF_inst
       (.I(UpButton3),
        .O(UpButton3_IBUF));
  IBUF UpButton5_IBUF_inst
       (.I(UpButton5),
        .O(UpButton5_IBUF));
  IBUF UpButton7_IBUF_inst
       (.I(UpButton7),
        .O(UpButton7_IBUF));
  OBUF UpLamp_OBUF_inst
       (.I(UpLamp_OBUF),
        .O(UpLamp));
  BUFG clk_1s_OBUF_BUFG_inst
       (.I(clk_1s_OBUF),
        .O(clk_1s_OBUF_BUFG));
  OBUF clk_1s_OBUF_inst
       (.I(clk_1s_OBUF_BUFG),
        .O(clk_1s));
  OBUF \result_OBUF[0]_inst 
       (.I(result_OBUF[0]),
        .O(result[0]));
  OBUF \result_OBUF[1]_inst 
       (.I(result_OBUF[1]),
        .O(result[1]));
  OBUF \result_OBUF[2]_inst 
       (.I(result_OBUF[2]),
        .O(result[2]));
  OBUF \result_OBUF[3]_inst 
       (.I(result_OBUF[3]),
        .O(result[3]));
  OBUF \result_OBUF[4]_inst 
       (.I(result_OBUF[4]),
        .O(result[4]));
  OBUF \result_OBUF[5]_inst 
       (.I(result_OBUF[5]),
        .O(result[5]));
  OBUF \result_OBUF[6]_inst 
       (.I(result_OBUF[6]),
        .O(result[6]));
  OBUF \result_OBUF[7]_inst 
       (.I(result_OBUF[7]),
        .O(result[7]));
  OBUF \select_OBUF[0]_inst 
       (.I(select_OBUF[0]),
        .O(select[0]));
  OBUF \select_OBUF[1]_inst 
       (.I(select_OBUF[1]),
        .O(select[1]));
  OBUF \select_OBUF[2]_inst 
       (.I(select_OBUF[2]),
        .O(select[2]));
  OBUF \select_OBUF[3]_inst 
       (.I(select_OBUF[3]),
        .O(select[3]));
  OBUF \select_OBUF[4]_inst 
       (.I(select_OBUF[4]),
        .O(select[4]));
  OBUF \select_OBUF[5]_inst 
       (.I(select_OBUF[5]),
        .O(select[5]));
  OBUF \select_OBUF[6]_inst 
       (.I(select_OBUF[6]),
        .O(select[6]));
  OBUF \select_OBUF[7]_inst 
       (.I(select_OBUF[7]),
        .O(select[7]));
  ChangeState uCe
       (.CloseLamp_OBUF(CloseLamp_OBUF),
        .CurrentStair_OBUF(CurrentStair_OBUF),
        .DownButton2_IBUF(DownButton2_IBUF),
        .DownButton4_IBUF(DownButton4_IBUF),
        .DownButton6_IBUF(DownButton6_IBUF),
        .DownButton8_IBUF(DownButton8_IBUF),
        .DownLamp_OBUF(DownLamp_OBUF),
        .OpenButton_IBUF(OpenButton_IBUF),
        .OpenLamp_OBUF(OpenLamp_OBUF),
        .Q(CountDown_OBUF),
        .StairButton1_IBUF(StairButton1_IBUF),
        .StairButton3_IBUF(StairButton3_IBUF),
        .StairButton5_IBUF(StairButton5_IBUF),
        .StairButton8_IBUF(StairButton8_IBUF),
        .\StairLamp_reg[7]_0 ({StairLamp_OBUF[8],StairLamp_OBUF[6],StairLamp_OBUF[4],StairLamp_OBUF[1]}),
        .UpButton1_IBUF(UpButton1_IBUF),
        .UpButton3_IBUF(UpButton3_IBUF),
        .UpButton5_IBUF(UpButton5_IBUF),
        .UpButton7_IBUF(UpButton7_IBUF),
        .UpLamp_OBUF(UpLamp_OBUF),
        .clk_1s_OBUF_BUFG(clk_1s_OBUF_BUFG),
        .out({uPt_n_8,uPt_n_9,uPt_n_10}),
        .\result[0] (uCe_n_8));
  DLCK_1s uDk
       (.RunLamp_OBUF(RunLamp_OBUF),
        .SR(Reset_IBUF),
        .T_IBUF_BUFG(T_IBUF_BUFG),
        .clk_1s_OBUF(clk_1s_OBUF));
  Print uPt
       (.\CountDown_reg[0] (uCe_n_8),
        .Q(CountDown_OBUF[3:1]),
        .out({uPt_n_8,uPt_n_9,uPt_n_10}),
        .result_OBUF(result_OBUF),
        .select_OBUF(select_OBUF));
endmodule

module Print
   (result_OBUF,
    out,
    select_OBUF,
    \CountDown_reg[0] ,
    Q);
  output [7:0]result_OBUF;
  output [2:0]out;
  output [7:0]select_OBUF;
  input \CountDown_reg[0] ;
  input [2:0]Q;

  wire \CountDown_reg[0] ;
  wire \FSM_sequential_select[0]_i_1_n_0 ;
  wire \FSM_sequential_select[1]_i_1_n_0 ;
  wire \FSM_sequential_select[2]_i_1_n_0 ;
  wire [2:0]Q;
  (* RTL_KEEP = "yes" *) wire [2:0]out;
  wire [7:0]result_OBUF;
  wire \result_OBUF[7]_inst_i_3_n_0 ;
  wire \result_OBUF[7]_inst_i_5_n_0 ;
  wire [7:0]select_OBUF;
  wire uSn_n_0;

  LUT1 #(
    .INIT(2'h1)) 
    \FSM_sequential_select[0]_i_1 
       (.I0(out[0]),
        .O(\FSM_sequential_select[0]_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \FSM_sequential_select[1]_i_1 
       (.I0(out[0]),
        .I1(out[1]),
        .O(\FSM_sequential_select[1]_i_1_n_0 ));
  LUT3 #(
    .INIT(8'h78)) 
    \FSM_sequential_select[2]_i_1 
       (.I0(out[1]),
        .I1(out[0]),
        .I2(out[2]),
        .O(\FSM_sequential_select[2]_i_1_n_0 ));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_select_reg[0] 
       (.C(1'b0),
        .CE(1'b1),
        .D(\FSM_sequential_select[0]_i_1_n_0 ),
        .Q(out[0]),
        .R(1'b0));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_select_reg[1] 
       (.C(1'b0),
        .CE(1'b1),
        .D(\FSM_sequential_select[1]_i_1_n_0 ),
        .Q(out[1]),
        .R(1'b0));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_select_reg[2] 
       (.C(1'b0),
        .CE(1'b1),
        .D(\FSM_sequential_select[2]_i_1_n_0 ),
        .Q(out[2]),
        .R(1'b0));
  LUT4 #(
    .INIT(16'h1000)) 
    \result_OBUF[0]_inst_i_1 
       (.I0(\CountDown_reg[0] ),
        .I1(uSn_n_0),
        .I2(\result_OBUF[7]_inst_i_5_n_0 ),
        .I3(\result_OBUF[7]_inst_i_3_n_0 ),
        .O(result_OBUF[0]));
  LUT6 #(
    .INIT(64'h55555555ABBAABAA)) 
    \result_OBUF[7]_inst_i_3 
       (.I0(out[2]),
        .I1(out[0]),
        .I2(Q[2]),
        .I3(Q[0]),
        .I4(Q[1]),
        .I5(out[1]),
        .O(\result_OBUF[7]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h55555555AAAAABAA)) 
    \result_OBUF[7]_inst_i_5 
       (.I0(out[2]),
        .I1(out[0]),
        .I2(Q[1]),
        .I3(Q[2]),
        .I4(Q[0]),
        .I5(out[1]),
        .O(\result_OBUF[7]_inst_i_5_n_0 ));
  LUT3 #(
    .INIT(8'hFE)) 
    \select_OBUF[0]_inst_i_1 
       (.I0(out[1]),
        .I1(out[2]),
        .I2(out[0]),
        .O(select_OBUF[0]));
  LUT3 #(
    .INIT(8'hEF)) 
    \select_OBUF[1]_inst_i_1 
       (.I0(out[1]),
        .I1(out[2]),
        .I2(out[0]),
        .O(select_OBUF[1]));
  LUT3 #(
    .INIT(8'hEF)) 
    \select_OBUF[2]_inst_i_1 
       (.I0(out[2]),
        .I1(out[0]),
        .I2(out[1]),
        .O(select_OBUF[2]));
  LUT3 #(
    .INIT(8'hF7)) 
    \select_OBUF[3]_inst_i_1 
       (.I0(out[1]),
        .I1(out[0]),
        .I2(out[2]),
        .O(select_OBUF[3]));
  LUT3 #(
    .INIT(8'hEF)) 
    \select_OBUF[4]_inst_i_1 
       (.I0(out[1]),
        .I1(out[0]),
        .I2(out[2]),
        .O(select_OBUF[4]));
  LUT3 #(
    .INIT(8'hF7)) 
    \select_OBUF[5]_inst_i_1 
       (.I0(out[2]),
        .I1(out[0]),
        .I2(out[1]),
        .O(select_OBUF[5]));
  LUT3 #(
    .INIT(8'hF7)) 
    \select_OBUF[6]_inst_i_1 
       (.I0(out[1]),
        .I1(out[2]),
        .I2(out[0]),
        .O(select_OBUF[6]));
  LUT3 #(
    .INIT(8'h7F)) 
    \select_OBUF[7]_inst_i_1 
       (.I0(out[2]),
        .I1(out[0]),
        .I2(out[1]),
        .O(select_OBUF[7]));
  SevenSegNumIndic uSn
       (.\CountDown_reg[0] (\CountDown_reg[0] ),
        .\FSM_sequential_select_reg[2] (\result_OBUF[7]_inst_i_3_n_0 ),
        .\FSM_sequential_select_reg[2]_0 (\result_OBUF[7]_inst_i_5_n_0 ),
        .Q(Q),
        .out(out),
        .\result[0] (uSn_n_0),
        .result_OBUF(result_OBUF[7:1]));
endmodule

module SevenSegNumIndic
   (\result[0] ,
    result_OBUF,
    out,
    Q,
    \CountDown_reg[0] ,
    \FSM_sequential_select_reg[2] ,
    \FSM_sequential_select_reg[2]_0 );
  output \result[0] ;
  output [6:0]result_OBUF;
  input [2:0]out;
  input [2:0]Q;
  input \CountDown_reg[0] ;
  input \FSM_sequential_select_reg[2] ;
  input \FSM_sequential_select_reg[2]_0 ;

  wire \CountDown_reg[0] ;
  wire \FSM_sequential_select_reg[2] ;
  wire \FSM_sequential_select_reg[2]_0 ;
  wire [2:0]Q;
  wire [2:0]out;
  wire \result[0] ;
  wire [6:0]result_OBUF;

  LUT4 #(
    .INIT(16'h4101)) 
    \result_OBUF[1]_inst_i_1 
       (.I0(\FSM_sequential_select_reg[2]_0 ),
        .I1(\result[0] ),
        .I2(\FSM_sequential_select_reg[2] ),
        .I3(\CountDown_reg[0] ),
        .O(result_OBUF[0]));
  (* SOFT_HLUTNM = "soft_lutpair55" *) 
  LUT4 #(
    .INIT(16'h4074)) 
    \result_OBUF[2]_inst_i_1 
       (.I0(\FSM_sequential_select_reg[2]_0 ),
        .I1(\CountDown_reg[0] ),
        .I2(\FSM_sequential_select_reg[2] ),
        .I3(\result[0] ),
        .O(result_OBUF[1]));
  (* SOFT_HLUTNM = "soft_lutpair54" *) 
  LUT4 #(
    .INIT(16'h5718)) 
    \result_OBUF[3]_inst_i_1 
       (.I0(\FSM_sequential_select_reg[2]_0 ),
        .I1(\FSM_sequential_select_reg[2] ),
        .I2(\result[0] ),
        .I3(\CountDown_reg[0] ),
        .O(result_OBUF[2]));
  (* SOFT_HLUTNM = "soft_lutpair55" *) 
  LUT4 #(
    .INIT(16'h1924)) 
    \result_OBUF[4]_inst_i_1 
       (.I0(\FSM_sequential_select_reg[2] ),
        .I1(\result[0] ),
        .I2(\FSM_sequential_select_reg[2]_0 ),
        .I3(\CountDown_reg[0] ),
        .O(result_OBUF[3]));
  (* SOFT_HLUTNM = "soft_lutpair54" *) 
  LUT4 #(
    .INIT(16'hCCD0)) 
    \result_OBUF[5]_inst_i_1 
       (.I0(\CountDown_reg[0] ),
        .I1(\FSM_sequential_select_reg[2]_0 ),
        .I2(\FSM_sequential_select_reg[2] ),
        .I3(\result[0] ),
        .O(result_OBUF[4]));
  (* SOFT_HLUTNM = "soft_lutpair53" *) 
  LUT4 #(
    .INIT(16'hBE88)) 
    \result_OBUF[6]_inst_i_1 
       (.I0(\FSM_sequential_select_reg[2]_0 ),
        .I1(\FSM_sequential_select_reg[2] ),
        .I2(\CountDown_reg[0] ),
        .I3(\result[0] ),
        .O(result_OBUF[5]));
  (* SOFT_HLUTNM = "soft_lutpair53" *) 
  LUT4 #(
    .INIT(16'h0412)) 
    \result_OBUF[7]_inst_i_1 
       (.I0(\CountDown_reg[0] ),
        .I1(\FSM_sequential_select_reg[2] ),
        .I2(\result[0] ),
        .I3(\FSM_sequential_select_reg[2]_0 ),
        .O(result_OBUF[6]));
  LUT6 #(
    .INIT(64'h0000000000005100)) 
    \result_OBUF[7]_inst_i_4 
       (.I0(out[0]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(out[2]),
        .I5(out[1]),
        .O(\result[0] ));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif
