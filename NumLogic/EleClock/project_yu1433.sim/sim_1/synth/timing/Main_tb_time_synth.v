// Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
// Date        : Sat Sep 24 12:19:52 2016
// Host        : iyuge2PC running 64-bit Ubuntu 16.04.1 LTS
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               /home/iyuge2/Study/NumLogicWork/EleClock_update/EleClock_update.sim/sim_1/synth/timing/Main_tb_time_synth.v
// Design      : Main
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xa7a100tcsg324-1I
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

module CLOCK_H
   (h1,
    h0,
    \result[0] ,
    \result[0]_0 ,
    stop_IBUF,
    hup_IBUF,
    hdown_IBUF,
    clear_IBUF,
    CLK);
  output [0:3]h1;
  output [1:0]h0;
  output \result[0] ;
  output \result[0]_0 ;
  input stop_IBUF;
  input hup_IBUF;
  input hdown_IBUF;
  input clear_IBUF;
  input CLK;

  wire CLK;
  wire clear_IBUF;
  wire [1:0]h0;
  wire [0:3]h1;
  wire hdown_IBUF;
  wire hup_IBUF;
  wire \result[0] ;
  wire \result[0]_0 ;
  wire stop_IBUF;

  Count__parameterized0 uCt_s
       (.CLK(CLK),
        .clear_IBUF(clear_IBUF),
        .h0(h0[0]),
        .h1(h1),
        .hdown_IBUF(hdown_IBUF),
        .hup_IBUF(hup_IBUF),
        .\result[0] (h0[1]),
        .\result[0]_0 (\result[0] ),
        .\result[0]_1 (\result[0]_0 ),
        .stop_IBUF(stop_IBUF));
endmodule

module CLOCK_M
   (clm,
    \result[0] ,
    m0,
    \k_reg[31] ,
    m1,
    \result[0]_0 ,
    \result[0]_1 ,
    \result[0]_2 ,
    CLK,
    out,
    h1,
    s1_OBUF,
    stop_IBUF,
    mup_IBUF,
    mdown_IBUF,
    clear_IBUF);
  output clm;
  output \result[0] ;
  output [0:0]m0;
  output \k_reg[31] ;
  output [2:0]m1;
  output \result[0]_0 ;
  output \result[0]_1 ;
  output \result[0]_2 ;
  input CLK;
  input [1:0]out;
  input [0:0]h1;
  input [0:0]s1_OBUF;
  input stop_IBUF;
  input mup_IBUF;
  input mdown_IBUF;
  input clear_IBUF;

  wire CLK;
  wire clear_IBUF;
  wire clm;
  wire [0:0]h1;
  wire \k_reg[31] ;
  wire [0:0]m0;
  wire [2:0]m1;
  wire mdown_IBUF;
  wire mup_IBUF;
  wire [1:0]out;
  wire \result[0] ;
  wire \result[0]_0 ;
  wire \result[0]_1 ;
  wire \result[0]_2 ;
  wire [0:0]s1_OBUF;
  wire stop_IBUF;

  Count uCt_s
       (.CLK(CLK),
        .clear_IBUF(clear_IBUF),
        .clm(clm),
        .h1(h1),
        .\k_reg[31] (\k_reg[31] ),
        .m0(m0),
        .m1(m1),
        .mdown_IBUF(mdown_IBUF),
        .mup_IBUF(mup_IBUF),
        .out(out),
        .\result[0] (\result[0] ),
        .\result[0]_0 (\result[0]_0 ),
        .\result[0]_1 (\result[0]_1 ),
        .\result[0]_2 (\result[0]_2 ),
        .s1_OBUF(s1_OBUF),
        .stop_IBUF(stop_IBUF));
endmodule

module CLOCK_S
   (cls,
    s1_OBUF,
    s0_OBUF,
    CLK,
    stop_IBUF,
    sup_IBUF,
    sdown_IBUF,
    clear_IBUF);
  output cls;
  output [0:3]s1_OBUF;
  output [0:3]s0_OBUF;
  input CLK;
  input stop_IBUF;
  input sup_IBUF;
  input sdown_IBUF;
  input clear_IBUF;

  wire CLK;
  wire clear_IBUF;
  wire cls;
  wire [0:3]s0_OBUF;
  wire [0:3]s1_OBUF;
  wire sdown_IBUF;
  wire stop_IBUF;
  wire sup_IBUF;

  Count_0 uCt_s
       (.CLK(CLK),
        .clear_IBUF(clear_IBUF),
        .cls(cls),
        .\result[0] (s0_OBUF[1]),
        .\result[0]_0 (s0_OBUF[2]),
        .s0_OBUF({s0_OBUF[0],s0_OBUF[3]}),
        .s1_OBUF(s1_OBUF),
        .sdown_IBUF(sdown_IBUF),
        .stop_IBUF(stop_IBUF),
        .sup_IBUF(sup_IBUF));
endmodule

module Count
   (clm,
    \result[0] ,
    m0,
    \k_reg[31] ,
    m1,
    \result[0]_0 ,
    \result[0]_1 ,
    \result[0]_2 ,
    CLK,
    out,
    h1,
    s1_OBUF,
    stop_IBUF,
    mup_IBUF,
    mdown_IBUF,
    clear_IBUF);
  output clm;
  output \result[0] ;
  output [0:0]m0;
  output \k_reg[31] ;
  output [2:0]m1;
  output \result[0]_0 ;
  output \result[0]_1 ;
  output \result[0]_2 ;
  input CLK;
  input [1:0]out;
  input [0:0]h1;
  input [0:0]s1_OBUF;
  input stop_IBUF;
  input mup_IBUF;
  input mdown_IBUF;
  input clear_IBUF;

  wire CLK;
  wire clear_IBUF;
  wire clm;
  wire co;
  wire co_i_1__0_n_0;
  wire [0:0]h1;
  wire \k_reg[31] ;
  wire [0:0]m0;
  wire [2:0]m1;
  wire mdown_IBUF;
  wire mup_IBUF;
  wire [1:0]out;
  wire \res[0]_i_1__0_n_0 ;
  wire \res[0]_i_2__0_n_0 ;
  wire \res[0]_i_4__0_n_0 ;
  wire \res[0]_i_5__0_n_0 ;
  wire \res[1]_i_1__0_n_0 ;
  wire \res[2]_i_1__0_n_0 ;
  wire \res[2]_i_2__0_n_0 ;
  wire \res[2]_i_4__0_n_0 ;
  wire \res[2]_i_5_n_0 ;
  wire \res[2]_i_6__0_n_0 ;
  wire \res[3]_i_1__0_n_0 ;
  wire \res[3]_i_2__1_n_0 ;
  wire \res[3]_i_3_n_0 ;
  wire \res[4]_i_1__0_n_0 ;
  wire \res[4]_i_2__0_n_0 ;
  wire \res[5]_i_1__0_n_0 ;
  wire \res[5]_i_2__0_n_0 ;
  wire \res[6]_i_1__0_n_0 ;
  wire \res[7]_i_1__0_n_0 ;
  wire \res_reg_n_0_[0] ;
  wire \res_reg_n_0_[1] ;
  wire \res_reg_n_0_[2] ;
  wire \res_reg_n_0_[3] ;
  wire \res_reg_n_0_[4] ;
  wire \res_reg_n_0_[5] ;
  wire \res_reg_n_0_[6] ;
  wire \result[0] ;
  wire \result[0]_0 ;
  wire \result[0]_1 ;
  wire \result[0]_2 ;
  wire [0:0]s1_OBUF;
  wire stop_IBUF;
  wire \temp_reg[0]_i_9_n_0 ;

  (* SOFT_HLUTNM = "soft_lutpair9" *) 
  LUT5 #(
    .INIT(32'hFFFFBA8A)) 
    co_i_1__0
       (.I0(co),
        .I1(mup_IBUF),
        .I2(stop_IBUF),
        .I3(clm),
        .I4(clear_IBUF),
        .O(co_i_1__0_n_0));
  FDRE #(
    .INIT(1'b0)) 
    co_reg
       (.C(CLK),
        .CE(1'b1),
        .D(co_i_1__0_n_0),
        .Q(clm),
        .R(1'b0));
  LUT1 #(
    .INIT(2'h1)) 
    loud_i_1
       (.I0(clm),
        .O(\k_reg[31] ));
  LUT3 #(
    .INIT(8'hEF)) 
    \res[0]_i_1__0 
       (.I0(mdown_IBUF),
        .I1(mup_IBUF),
        .I2(stop_IBUF),
        .O(\res[0]_i_1__0_n_0 ));
  LUT6 #(
    .INIT(64'h0CF3F700FF00F700)) 
    \res[0]_i_2__0 
       (.I0(\res[0]_i_4__0_n_0 ),
        .I1(stop_IBUF),
        .I2(mup_IBUF),
        .I3(\res_reg_n_0_[0] ),
        .I4(\res_reg_n_0_[1] ),
        .I5(\res[0]_i_5__0_n_0 ),
        .O(\res[0]_i_2__0_n_0 ));
  LUT6 #(
    .INIT(64'h0000000000000001)) 
    \res[0]_i_4__0 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\res_reg_n_0_[6] ),
        .I3(m1[0]),
        .I4(\res_reg_n_0_[3] ),
        .I5(\res_reg_n_0_[2] ),
        .O(\res[0]_i_4__0_n_0 ));
  LUT6 #(
    .INIT(64'h8000000000000000)) 
    \res[0]_i_5__0 
       (.I0(\res_reg_n_0_[3] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\res_reg_n_0_[6] ),
        .I3(m1[0]),
        .I4(\res_reg_n_0_[4] ),
        .I5(\res_reg_n_0_[2] ),
        .O(\res[0]_i_5__0_n_0 ));
  LUT6 #(
    .INIT(64'h0030FF8FFF3F0080)) 
    \res[1]_i_1__0 
       (.I0(\res_reg_n_0_[0] ),
        .I1(\res[0]_i_4__0_n_0 ),
        .I2(stop_IBUF),
        .I3(mup_IBUF),
        .I4(\res_reg_n_0_[1] ),
        .I5(\res[0]_i_5__0_n_0 ),
        .O(\res[1]_i_1__0_n_0 ));
  LUT6 #(
    .INIT(64'h040404F708FB0808)) 
    \res[2]_i_1__0 
       (.I0(\res[2]_i_2__0_n_0 ),
        .I1(stop_IBUF),
        .I2(mup_IBUF),
        .I3(co),
        .I4(\res[2]_i_4__0_n_0 ),
        .I5(\res_reg_n_0_[2] ),
        .O(\res[2]_i_1__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT5 #(
    .INIT(32'h00000001)) 
    \res[2]_i_2__0 
       (.I0(\res_reg_n_0_[3] ),
        .I1(m1[0]),
        .I2(\res_reg_n_0_[6] ),
        .I3(\res_reg_n_0_[5] ),
        .I4(\res_reg_n_0_[4] ),
        .O(\res[2]_i_2__0_n_0 ));
  LUT6 #(
    .INIT(64'h0040000000000000)) 
    \res[2]_i_3 
       (.I0(\res_reg_n_0_[1] ),
        .I1(\res_reg_n_0_[3] ),
        .I2(\res_reg_n_0_[2] ),
        .I3(\res_reg_n_0_[0] ),
        .I4(\res[2]_i_5_n_0 ),
        .I5(\res[2]_i_6__0_n_0 ),
        .O(co));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT5 #(
    .INIT(32'h80000000)) 
    \res[2]_i_4__0 
       (.I0(\res_reg_n_0_[4] ),
        .I1(m1[0]),
        .I2(\res_reg_n_0_[6] ),
        .I3(\res_reg_n_0_[5] ),
        .I4(\res_reg_n_0_[3] ),
        .O(\res[2]_i_4__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \res[2]_i_5 
       (.I0(\res_reg_n_0_[6] ),
        .I1(m1[0]),
        .O(\res[2]_i_5_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \res[2]_i_6__0 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .O(\res[2]_i_6__0_n_0 ));
  LUT6 #(
    .INIT(64'h080808FB04F70404)) 
    \res[3]_i_1__0 
       (.I0(\res[3]_i_2__1_n_0 ),
        .I1(stop_IBUF),
        .I2(mup_IBUF),
        .I3(co),
        .I4(\res[3]_i_3_n_0 ),
        .I5(\res_reg_n_0_[3] ),
        .O(\res[3]_i_1__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT4 #(
    .INIT(16'hFFFE)) 
    \res[3]_i_2__1 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\res_reg_n_0_[6] ),
        .I3(m1[0]),
        .O(\res[3]_i_2__1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT4 #(
    .INIT(16'h8000)) 
    \res[3]_i_3 
       (.I0(\res_reg_n_0_[5] ),
        .I1(\res_reg_n_0_[6] ),
        .I2(m1[0]),
        .I3(\res_reg_n_0_[4] ),
        .O(\res[3]_i_3_n_0 ));
  LUT6 #(
    .INIT(64'hAAA80002BFFD4002)) 
    \res[4]_i_1__0 
       (.I0(\res[4]_i_2__0_n_0 ),
        .I1(m1[0]),
        .I2(\res_reg_n_0_[6] ),
        .I3(\res_reg_n_0_[5] ),
        .I4(\res_reg_n_0_[4] ),
        .I5(co),
        .O(\res[4]_i_1__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair9" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \res[4]_i_2__0 
       (.I0(stop_IBUF),
        .I1(mup_IBUF),
        .O(\res[4]_i_2__0_n_0 ));
  LUT6 #(
    .INIT(64'h888000088BB33008)) 
    \res[5]_i_1__0 
       (.I0(\res[5]_i_2__0_n_0 ),
        .I1(\res[4]_i_2__0_n_0 ),
        .I2(\res_reg_n_0_[6] ),
        .I3(m1[0]),
        .I4(\res_reg_n_0_[5] ),
        .I5(co),
        .O(\res[5]_i_1__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT3 #(
    .INIT(8'hEF)) 
    \res[5]_i_2__0 
       (.I0(\res_reg_n_0_[0] ),
        .I1(\res_reg_n_0_[1] ),
        .I2(\res[0]_i_4__0_n_0 ),
        .O(\res[5]_i_2__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT4 #(
    .INIT(16'h4BB4)) 
    \res[6]_i_1__0 
       (.I0(mup_IBUF),
        .I1(stop_IBUF),
        .I2(m1[0]),
        .I3(\res_reg_n_0_[6] ),
        .O(\res[6]_i_1__0_n_0 ));
  LUT1 #(
    .INIT(2'h1)) 
    \res[7]_i_1__0 
       (.I0(m1[0]),
        .O(\res[7]_i_1__0_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[0] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[0]_i_2__0_n_0 ),
        .Q(\res_reg_n_0_[0] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[1] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[1]_i_1__0_n_0 ),
        .Q(\res_reg_n_0_[1] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[2] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[2]_i_1__0_n_0 ),
        .Q(\res_reg_n_0_[2] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[3] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[3]_i_1__0_n_0 ),
        .Q(\res_reg_n_0_[3] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[4] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[4]_i_1__0_n_0 ),
        .Q(\res_reg_n_0_[4] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[5] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[5]_i_1__0_n_0 ),
        .Q(\res_reg_n_0_[5] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[6] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[6]_i_1__0_n_0 ),
        .Q(\res_reg_n_0_[6] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[7] 
       (.C(CLK),
        .CE(\res[0]_i_1__0_n_0 ),
        .D(\res[7]_i_1__0_n_0 ),
        .Q(m1[0]),
        .R(clear_IBUF));
  LUT6 #(
    .INIT(64'h1A0724902A15A854)) 
    \temp_reg[0]_i_5 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\temp_reg[0]_i_9_n_0 ),
        .I3(\result[0]_0 ),
        .I4(\result[0]_1 ),
        .I5(\res_reg_n_0_[6] ),
        .O(m1[2]));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT4 #(
    .INIT(16'h71CF)) 
    \temp_reg[0]_i_7 
       (.I0(\res_reg_n_0_[3] ),
        .I1(\res_reg_n_0_[2] ),
        .I2(\res_reg_n_0_[0] ),
        .I3(\res_reg_n_0_[1] ),
        .O(\result[0]_2 ));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT5 #(
    .INIT(32'hDB65249A)) 
    \temp_reg[0]_i_9 
       (.I0(\res_reg_n_0_[3] ),
        .I1(\res_reg_n_0_[2] ),
        .I2(\res_reg_n_0_[0] ),
        .I3(\res_reg_n_0_[1] ),
        .I4(\res_reg_n_0_[4] ),
        .O(\temp_reg[0]_i_9_n_0 ));
  LUT6 #(
    .INIT(64'hCCCC33335C8E86C1)) 
    \temp_reg[1]_i_4 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\temp_reg[0]_i_9_n_0 ),
        .I3(\result[0]_0 ),
        .I4(\result[0]_1 ),
        .I5(\res_reg_n_0_[6] ),
        .O(m1[1]));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT5 #(
    .INIT(32'hC17CF01F)) 
    \temp_reg[1]_i_6 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[3] ),
        .I2(\res_reg_n_0_[2] ),
        .I3(\res_reg_n_0_[0] ),
        .I4(\res_reg_n_0_[1] ),
        .O(\result[0]_0 ));
  LUT6 #(
    .INIT(64'h0F006F6F0F006060)) 
    \temp_reg[2]_i_2 
       (.I0(m0),
        .I1(\res_reg_n_0_[6] ),
        .I2(out[0]),
        .I3(h1),
        .I4(out[1]),
        .I5(s1_OBUF),
        .O(\result[0] ));
  LUT6 #(
    .INIT(64'hB052BDF69042B5F2)) 
    \temp_reg[2]_i_4 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\temp_reg[0]_i_9_n_0 ),
        .I3(\result[0]_0 ),
        .I4(\result[0]_1 ),
        .I5(\res_reg_n_0_[6] ),
        .O(m0));
  LUT6 #(
    .INIT(64'hC68C3163CE9C73E7)) 
    \temp_reg[2]_i_6 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[3] ),
        .I2(\res_reg_n_0_[2] ),
        .I3(\res_reg_n_0_[0] ),
        .I4(\res_reg_n_0_[1] ),
        .I5(\res_reg_n_0_[5] ),
        .O(\result[0]_1 ));
endmodule

(* ORIG_REF_NAME = "Count" *) 
module Count_0
   (cls,
    s1_OBUF,
    \result[0] ,
    \result[0]_0 ,
    s0_OBUF,
    CLK,
    stop_IBUF,
    sup_IBUF,
    sdown_IBUF,
    clear_IBUF);
  output cls;
  output [0:3]s1_OBUF;
  output \result[0] ;
  output \result[0]_0 ;
  output [1:0]s0_OBUF;
  input CLK;
  input stop_IBUF;
  input sup_IBUF;
  input sdown_IBUF;
  input clear_IBUF;

  wire CLK;
  wire clear_IBUF;
  wire cls;
  wire co;
  wire co_i_1_n_0;
  wire [0:6]res;
  wire \res[0]_i_1_n_0 ;
  wire \res[0]_i_2_n_0 ;
  wire \res[0]_i_4_n_0 ;
  wire \res[0]_i_5_n_0 ;
  wire \res[1]_i_1_n_0 ;
  wire \res[2]_i_1_n_0 ;
  wire \res[2]_i_2_n_0 ;
  wire \res[2]_i_3__0_n_0 ;
  wire \res[2]_i_4_n_0 ;
  wire \res[2]_i_5__0_n_0 ;
  wire \res[2]_i_6_n_0 ;
  wire \res[2]_i_7_n_0 ;
  wire \res[3]_i_1_n_0 ;
  wire \res[3]_i_2__0_n_0 ;
  wire \res[4]_i_1_n_0 ;
  wire \res[5]_i_1_n_0 ;
  wire \res[5]_i_2_n_0 ;
  wire \res[6]_i_1_n_0 ;
  wire \res[7]_i_1_n_0 ;
  wire \result[0] ;
  wire \result[0]_0 ;
  wire [1:0]s0_OBUF;
  wire \s0_OBUF[3]_inst_i_2_n_0 ;
  wire [0:3]s1_OBUF;
  wire sdown_IBUF;
  wire stop_IBUF;
  wire sup_IBUF;

  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT5 #(
    .INIT(32'hFFFFBA8A)) 
    co_i_1
       (.I0(co),
        .I1(sup_IBUF),
        .I2(stop_IBUF),
        .I3(cls),
        .I4(clear_IBUF),
        .O(co_i_1_n_0));
  LUT6 #(
    .INIT(64'h0040000000000000)) 
    co_i_2
       (.I0(res[1]),
        .I1(res[3]),
        .I2(res[2]),
        .I3(res[0]),
        .I4(\res[2]_i_7_n_0 ),
        .I5(\res[2]_i_6_n_0 ),
        .O(co));
  FDRE #(
    .INIT(1'b0)) 
    co_reg
       (.C(CLK),
        .CE(1'b1),
        .D(co_i_1_n_0),
        .Q(cls),
        .R(1'b0));
  LUT3 #(
    .INIT(8'hEF)) 
    \res[0]_i_1 
       (.I0(sdown_IBUF),
        .I1(sup_IBUF),
        .I2(stop_IBUF),
        .O(\res[0]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h0CF3F700FF00F700)) 
    \res[0]_i_2 
       (.I0(\res[0]_i_4_n_0 ),
        .I1(stop_IBUF),
        .I2(sup_IBUF),
        .I3(res[0]),
        .I4(res[1]),
        .I5(\res[0]_i_5_n_0 ),
        .O(\res[0]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h0000000000000001)) 
    \res[0]_i_4 
       (.I0(res[4]),
        .I1(res[5]),
        .I2(res[6]),
        .I3(s1_OBUF[3]),
        .I4(res[3]),
        .I5(res[2]),
        .O(\res[0]_i_4_n_0 ));
  LUT6 #(
    .INIT(64'h8000000000000000)) 
    \res[0]_i_5 
       (.I0(res[4]),
        .I1(s1_OBUF[3]),
        .I2(res[6]),
        .I3(res[5]),
        .I4(res[3]),
        .I5(res[2]),
        .O(\res[0]_i_5_n_0 ));
  LUT6 #(
    .INIT(64'h0030FF8FFF3F0080)) 
    \res[1]_i_1 
       (.I0(res[0]),
        .I1(\res[0]_i_4_n_0 ),
        .I2(stop_IBUF),
        .I3(sup_IBUF),
        .I4(res[1]),
        .I5(\res[0]_i_5_n_0 ),
        .O(\res[1]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h44747474B8888888)) 
    \res[2]_i_1 
       (.I0(\res[2]_i_2_n_0 ),
        .I1(\res[2]_i_3__0_n_0 ),
        .I2(\res[2]_i_4_n_0 ),
        .I3(\res[2]_i_5__0_n_0 ),
        .I4(res[3]),
        .I5(res[2]),
        .O(\res[2]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT5 #(
    .INIT(32'h00000001)) 
    \res[2]_i_2 
       (.I0(res[3]),
        .I1(s1_OBUF[3]),
        .I2(res[6]),
        .I3(res[5]),
        .I4(res[4]),
        .O(\res[2]_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \res[2]_i_3__0 
       (.I0(stop_IBUF),
        .I1(sup_IBUF),
        .O(\res[2]_i_3__0_n_0 ));
  LUT6 #(
    .INIT(64'hFDFFFFFFFFFFFFFF)) 
    \res[2]_i_4 
       (.I0(\res[2]_i_6_n_0 ),
        .I1(res[0]),
        .I2(res[1]),
        .I3(\res[2]_i_7_n_0 ),
        .I4(res[2]),
        .I5(res[3]),
        .O(\res[2]_i_4_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT4 #(
    .INIT(16'h8000)) 
    \res[2]_i_5__0 
       (.I0(res[5]),
        .I1(res[6]),
        .I2(s1_OBUF[3]),
        .I3(res[4]),
        .O(\res[2]_i_5__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \res[2]_i_6 
       (.I0(res[4]),
        .I1(res[5]),
        .O(\res[2]_i_6_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT2 #(
    .INIT(4'h8)) 
    \res[2]_i_7 
       (.I0(res[6]),
        .I1(s1_OBUF[3]),
        .O(\res[2]_i_7_n_0 ));
  LUT6 #(
    .INIT(64'h0808FB08F7040404)) 
    \res[3]_i_1 
       (.I0(\res[3]_i_2__0_n_0 ),
        .I1(stop_IBUF),
        .I2(sup_IBUF),
        .I3(\res[2]_i_4_n_0 ),
        .I4(\res[2]_i_5__0_n_0 ),
        .I5(res[3]),
        .O(\res[3]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT4 #(
    .INIT(16'hFFFE)) 
    \res[3]_i_2__0 
       (.I0(res[4]),
        .I1(res[5]),
        .I2(res[6]),
        .I3(s1_OBUF[3]),
        .O(\res[3]_i_2__0_n_0 ));
  LUT6 #(
    .INIT(64'hAEEEEEE44000000A)) 
    \res[4]_i_1 
       (.I0(\res[2]_i_3__0_n_0 ),
        .I1(\res[2]_i_4_n_0 ),
        .I2(s1_OBUF[3]),
        .I3(res[6]),
        .I4(res[5]),
        .I5(res[4]),
        .O(\res[4]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h88B8B83030000088)) 
    \res[5]_i_1 
       (.I0(\res[5]_i_2_n_0 ),
        .I1(\res[2]_i_3__0_n_0 ),
        .I2(\res[2]_i_4_n_0 ),
        .I3(res[6]),
        .I4(s1_OBUF[3]),
        .I5(res[5]),
        .O(\res[5]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT3 #(
    .INIT(8'hEF)) 
    \res[5]_i_2 
       (.I0(res[0]),
        .I1(res[1]),
        .I2(\res[0]_i_4_n_0 ),
        .O(\res[5]_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT4 #(
    .INIT(16'h4BB4)) 
    \res[6]_i_1 
       (.I0(sup_IBUF),
        .I1(stop_IBUF),
        .I2(s1_OBUF[3]),
        .I3(res[6]),
        .O(\res[6]_i_1_n_0 ));
  LUT1 #(
    .INIT(2'h1)) 
    \res[7]_i_1 
       (.I0(s1_OBUF[3]),
        .O(\res[7]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[0] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[0]_i_2_n_0 ),
        .Q(res[0]),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[1] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[1]_i_1_n_0 ),
        .Q(res[1]),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[2] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[2]_i_1_n_0 ),
        .Q(res[2]),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[3] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[3]_i_1_n_0 ),
        .Q(res[3]),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[4] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[4]_i_1_n_0 ),
        .Q(res[4]),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[5] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[5]_i_1_n_0 ),
        .Q(res[5]),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[6] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[6]_i_1_n_0 ),
        .Q(res[6]),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[7] 
       (.C(CLK),
        .CE(\res[0]_i_1_n_0 ),
        .D(\res[7]_i_1_n_0 ),
        .Q(s1_OBUF[3]),
        .R(clear_IBUF));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT4 #(
    .INIT(16'hA624)) 
    \s0_OBUF[0]_inst_i_1 
       (.I0(res[1]),
        .I1(res[0]),
        .I2(res[2]),
        .I3(res[3]),
        .O(s0_OBUF[1]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT5 #(
    .INIT(32'h3C9E1C86)) 
    \s0_OBUF[1]_inst_i_1 
       (.I0(res[1]),
        .I1(res[0]),
        .I2(res[2]),
        .I3(res[3]),
        .I4(res[4]),
        .O(\result[0] ));
  LUT6 #(
    .INIT(64'h3973CE9C31638C18)) 
    \s0_OBUF[2]_inst_i_1 
       (.I0(res[4]),
        .I1(res[3]),
        .I2(res[2]),
        .I3(res[0]),
        .I4(res[1]),
        .I5(res[5]),
        .O(\result[0]_0 ));
  LUT6 #(
    .INIT(64'hF6BD52B0F2B54290)) 
    \s0_OBUF[3]_inst_i_1 
       (.I0(res[4]),
        .I1(res[5]),
        .I2(\s0_OBUF[3]_inst_i_2_n_0 ),
        .I3(\result[0] ),
        .I4(\result[0]_0 ),
        .I5(res[6]),
        .O(s0_OBUF[0]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT5 #(
    .INIT(32'hA6DB5924)) 
    \s0_OBUF[3]_inst_i_2 
       (.I0(res[1]),
        .I1(res[0]),
        .I2(res[2]),
        .I3(res[3]),
        .I4(res[4]),
        .O(\s0_OBUF[3]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h9024071A54A8152A)) 
    \s1_OBUF[0]_inst_i_1 
       (.I0(res[4]),
        .I1(res[5]),
        .I2(\s0_OBUF[3]_inst_i_2_n_0 ),
        .I3(\result[0] ),
        .I4(\result[0]_0 ),
        .I5(res[6]),
        .O(s1_OBUF[0]));
  LUT6 #(
    .INIT(64'h3333CCCCC1868E5C)) 
    \s1_OBUF[1]_inst_i_1 
       (.I0(res[4]),
        .I1(res[5]),
        .I2(\s0_OBUF[3]_inst_i_2_n_0 ),
        .I3(\result[0] ),
        .I4(\result[0]_0 ),
        .I5(res[6]),
        .O(s1_OBUF[1]));
  LUT6 #(
    .INIT(64'h65A2645A5A2645A6)) 
    \s1_OBUF[2]_inst_i_1 
       (.I0(res[6]),
        .I1(\result[0]_0 ),
        .I2(\result[0] ),
        .I3(\s0_OBUF[3]_inst_i_2_n_0 ),
        .I4(res[5]),
        .I5(res[4]),
        .O(s1_OBUF[2]));
endmodule

(* ORIG_REF_NAME = "Count" *) 
module Count__parameterized0
   (h1,
    \result[0] ,
    \result[0]_0 ,
    h0,
    \result[0]_1 ,
    stop_IBUF,
    hup_IBUF,
    hdown_IBUF,
    clear_IBUF,
    CLK);
  output [0:3]h1;
  output \result[0] ;
  output \result[0]_0 ;
  output [0:0]h0;
  output \result[0]_1 ;
  input stop_IBUF;
  input hup_IBUF;
  input hdown_IBUF;
  input clear_IBUF;
  input CLK;

  wire CLK;
  wire clear_IBUF;
  wire [0:0]h0;
  wire [0:3]h1;
  wire hdown_IBUF;
  wire hup_IBUF;
  wire \res[0]_i_1__1_n_0 ;
  wire \res[0]_i_2__1_n_0 ;
  wire \res[0]_i_4__1_n_0 ;
  wire \res[0]_i_5__1_n_0 ;
  wire \res[1]_i_1__1_n_0 ;
  wire \res[2]_i_1__1_n_0 ;
  wire \res[2]_i_2__1_n_0 ;
  wire \res[2]_i_3__1_n_0 ;
  wire \res[2]_i_4__1_n_0 ;
  wire \res[3]_i_2_n_0 ;
  wire \res[3]_i_3__0_n_0 ;
  wire \res[3]_i_4_n_0 ;
  wire \res[4]_i_2_n_0 ;
  wire \res[4]_i_3_n_0 ;
  wire \res[4]_i_4_n_0 ;
  wire \res[5]_i_1__1_n_0 ;
  wire \res[6]_i_1__1_n_0 ;
  wire \res[7]_i_1__1_n_0 ;
  wire \res_reg[3]_i_1_n_0 ;
  wire \res_reg[4]_i_1_n_0 ;
  wire \res_reg_n_0_[0] ;
  wire \res_reg_n_0_[1] ;
  wire \res_reg_n_0_[2] ;
  wire \res_reg_n_0_[3] ;
  wire \res_reg_n_0_[4] ;
  wire \res_reg_n_0_[5] ;
  wire \res_reg_n_0_[6] ;
  wire \result[0] ;
  wire \result[0]_0 ;
  wire \result[0]_1 ;
  wire stop_IBUF;
  wire \temp_reg[0]_i_10_n_0 ;

  LUT3 #(
    .INIT(8'hEF)) 
    \res[0]_i_1__1 
       (.I0(hdown_IBUF),
        .I1(hup_IBUF),
        .I2(stop_IBUF),
        .O(\res[0]_i_1__1_n_0 ));
  LUT6 #(
    .INIT(64'h0CF3F700FF00F700)) 
    \res[0]_i_2__1 
       (.I0(\res[0]_i_4__1_n_0 ),
        .I1(stop_IBUF),
        .I2(hup_IBUF),
        .I3(\res_reg_n_0_[0] ),
        .I4(\res_reg_n_0_[1] ),
        .I5(\res[0]_i_5__1_n_0 ),
        .O(\res[0]_i_2__1_n_0 ));
  LUT6 #(
    .INIT(64'h0000000000000001)) 
    \res[0]_i_4__1 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\res_reg_n_0_[6] ),
        .I3(h1[3]),
        .I4(\res_reg_n_0_[3] ),
        .I5(\res_reg_n_0_[2] ),
        .O(\res[0]_i_4__1_n_0 ));
  LUT6 #(
    .INIT(64'h8000000000000000)) 
    \res[0]_i_5__1 
       (.I0(\res_reg_n_0_[3] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\res_reg_n_0_[6] ),
        .I3(h1[3]),
        .I4(\res_reg_n_0_[4] ),
        .I5(\res_reg_n_0_[2] ),
        .O(\res[0]_i_5__1_n_0 ));
  LUT6 #(
    .INIT(64'h0030FF8FFF3F0080)) 
    \res[1]_i_1__1 
       (.I0(\res_reg_n_0_[0] ),
        .I1(\res[0]_i_4__1_n_0 ),
        .I2(stop_IBUF),
        .I3(hup_IBUF),
        .I4(\res_reg_n_0_[1] ),
        .I5(\res[0]_i_5__1_n_0 ),
        .O(\res[1]_i_1__1_n_0 ));
  LUT6 #(
    .INIT(64'h0F00E0FF0FFFE000)) 
    \res[2]_i_1__1 
       (.I0(\res_reg_n_0_[1] ),
        .I1(\res_reg_n_0_[0] ),
        .I2(\res[2]_i_2__1_n_0 ),
        .I3(\res[2]_i_3__1_n_0 ),
        .I4(\res_reg_n_0_[2] ),
        .I5(\res[2]_i_4__1_n_0 ),
        .O(\res[2]_i_1__1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair15" *) 
  LUT5 #(
    .INIT(32'h00000001)) 
    \res[2]_i_2__1 
       (.I0(\res_reg_n_0_[3] ),
        .I1(h1[3]),
        .I2(\res_reg_n_0_[6] ),
        .I3(\res_reg_n_0_[5] ),
        .I4(\res_reg_n_0_[4] ),
        .O(\res[2]_i_2__1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \res[2]_i_3__1 
       (.I0(stop_IBUF),
        .I1(hup_IBUF),
        .O(\res[2]_i_3__1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair15" *) 
  LUT5 #(
    .INIT(32'h80000000)) 
    \res[2]_i_4__1 
       (.I0(\res_reg_n_0_[4] ),
        .I1(h1[3]),
        .I2(\res_reg_n_0_[6] ),
        .I3(\res_reg_n_0_[5] ),
        .I4(\res_reg_n_0_[3] ),
        .O(\res[2]_i_4__1_n_0 ));
  LUT6 #(
    .INIT(64'h00FFFEFFFF000000)) 
    \res[3]_i_2 
       (.I0(\res_reg_n_0_[1] ),
        .I1(\res_reg_n_0_[0] ),
        .I2(\res_reg_n_0_[2] ),
        .I3(\res[3]_i_4_n_0 ),
        .I4(\res_reg_n_0_[4] ),
        .I5(\res_reg_n_0_[3] ),
        .O(\res[3]_i_2_n_0 ));
  LUT5 #(
    .INIT(32'hAAAAAAA9)) 
    \res[3]_i_3__0 
       (.I0(\res_reg_n_0_[3] ),
        .I1(h1[3]),
        .I2(\res_reg_n_0_[6] ),
        .I3(\res_reg_n_0_[5] ),
        .I4(\res_reg_n_0_[4] ),
        .O(\res[3]_i_3__0_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair16" *) 
  LUT3 #(
    .INIT(8'h80)) 
    \res[3]_i_4 
       (.I0(h1[3]),
        .I1(\res_reg_n_0_[6] ),
        .I2(\res_reg_n_0_[5] ),
        .O(\res[3]_i_4_n_0 ));
  LUT6 #(
    .INIT(64'h0000FFFFFFEF0000)) 
    \res[4]_i_2 
       (.I0(\res_reg_n_0_[1] ),
        .I1(\res_reg_n_0_[0] ),
        .I2(\res_reg_n_0_[3] ),
        .I3(\res_reg_n_0_[2] ),
        .I4(\res[3]_i_4_n_0 ),
        .I5(\res_reg_n_0_[4] ),
        .O(\res[4]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h0000FFFFFFFE0000)) 
    \res[4]_i_3 
       (.I0(\res_reg_n_0_[2] ),
        .I1(\res_reg_n_0_[3] ),
        .I2(\res_reg_n_0_[1] ),
        .I3(\res_reg_n_0_[0] ),
        .I4(\res[4]_i_4_n_0 ),
        .I5(\res_reg_n_0_[4] ),
        .O(\res[4]_i_3_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair16" *) 
  LUT3 #(
    .INIT(8'h01)) 
    \res[4]_i_4 
       (.I0(h1[3]),
        .I1(\res_reg_n_0_[6] ),
        .I2(\res_reg_n_0_[5] ),
        .O(\res[4]_i_4_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair13" *) 
  LUT5 #(
    .INIT(32'h2DF0F0D2)) 
    \res[5]_i_1__1 
       (.I0(stop_IBUF),
        .I1(hup_IBUF),
        .I2(\res_reg_n_0_[5] ),
        .I3(h1[3]),
        .I4(\res_reg_n_0_[6] ),
        .O(\res[5]_i_1__1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair13" *) 
  LUT4 #(
    .INIT(16'h4BB4)) 
    \res[6]_i_1__1 
       (.I0(hup_IBUF),
        .I1(stop_IBUF),
        .I2(h1[3]),
        .I3(\res_reg_n_0_[6] ),
        .O(\res[6]_i_1__1_n_0 ));
  LUT1 #(
    .INIT(2'h1)) 
    \res[7]_i_1__1 
       (.I0(h1[3]),
        .O(\res[7]_i_1__1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[0] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res[0]_i_2__1_n_0 ),
        .Q(\res_reg_n_0_[0] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[1] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res[1]_i_1__1_n_0 ),
        .Q(\res_reg_n_0_[1] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[2] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res[2]_i_1__1_n_0 ),
        .Q(\res_reg_n_0_[2] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[3] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res_reg[3]_i_1_n_0 ),
        .Q(\res_reg_n_0_[3] ),
        .R(clear_IBUF));
  MUXF7 \res_reg[3]_i_1 
       (.I0(\res[3]_i_2_n_0 ),
        .I1(\res[3]_i_3__0_n_0 ),
        .O(\res_reg[3]_i_1_n_0 ),
        .S(\res[2]_i_3__1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[4] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res_reg[4]_i_1_n_0 ),
        .Q(\res_reg_n_0_[4] ),
        .R(clear_IBUF));
  MUXF7 \res_reg[4]_i_1 
       (.I0(\res[4]_i_2_n_0 ),
        .I1(\res[4]_i_3_n_0 ),
        .O(\res_reg[4]_i_1_n_0 ),
        .S(\res[2]_i_3__1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[5] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res[5]_i_1__1_n_0 ),
        .Q(\res_reg_n_0_[5] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[6] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res[6]_i_1__1_n_0 ),
        .Q(\res_reg_n_0_[6] ),
        .R(clear_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \res_reg[7] 
       (.C(CLK),
        .CE(\res[0]_i_1__1_n_0 ),
        .D(\res[7]_i_1__1_n_0 ),
        .Q(h1[3]),
        .R(clear_IBUF));
  (* SOFT_HLUTNM = "soft_lutpair14" *) 
  LUT5 #(
    .INIT(32'hDB65249A)) 
    \temp_reg[0]_i_10 
       (.I0(\res_reg_n_0_[3] ),
        .I1(\res_reg_n_0_[2] ),
        .I2(\res_reg_n_0_[0] ),
        .I3(\res_reg_n_0_[1] ),
        .I4(\res_reg_n_0_[4] ),
        .O(\temp_reg[0]_i_10_n_0 ));
  LUT6 #(
    .INIT(64'h071A152A902454A8)) 
    \temp_reg[0]_i_6 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\temp_reg[0]_i_10_n_0 ),
        .I3(\result[0] ),
        .I4(\res_reg_n_0_[6] ),
        .I5(\result[0]_0 ),
        .O(h1[0]));
  LUT4 #(
    .INIT(16'h71CF)) 
    \temp_reg[0]_i_8 
       (.I0(\res_reg_n_0_[3] ),
        .I1(\res_reg_n_0_[2] ),
        .I2(\res_reg_n_0_[0] ),
        .I3(\res_reg_n_0_[1] ),
        .O(\result[0]_1 ));
  LUT6 #(
    .INIT(64'hCCCC8E5C3333C186)) 
    \temp_reg[1]_i_5 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\temp_reg[0]_i_10_n_0 ),
        .I3(\result[0] ),
        .I4(\res_reg_n_0_[6] ),
        .I5(\result[0]_0 ),
        .O(h1[1]));
  (* SOFT_HLUTNM = "soft_lutpair14" *) 
  LUT5 #(
    .INIT(32'h3C9E1C86)) 
    \temp_reg[1]_i_7 
       (.I0(\res_reg_n_0_[1] ),
        .I1(\res_reg_n_0_[0] ),
        .I2(\res_reg_n_0_[2] ),
        .I3(\res_reg_n_0_[3] ),
        .I4(\res_reg_n_0_[4] ),
        .O(\result[0] ));
  LUT6 #(
    .INIT(64'h93C8913C3C8913C9)) 
    \temp_reg[2]_i_5 
       (.I0(\result[0]_0 ),
        .I1(\res_reg_n_0_[6] ),
        .I2(\result[0] ),
        .I3(\temp_reg[0]_i_10_n_0 ),
        .I4(\res_reg_n_0_[5] ),
        .I5(\res_reg_n_0_[4] ),
        .O(h1[2]));
  LUT6 #(
    .INIT(64'hF1C770F10F1CC70F)) 
    \temp_reg[2]_i_7 
       (.I0(\res_reg_n_0_[5] ),
        .I1(\res_reg_n_0_[4] ),
        .I2(\res_reg_n_0_[1] ),
        .I3(\res_reg_n_0_[0] ),
        .I4(\res_reg_n_0_[2] ),
        .I5(\res_reg_n_0_[3] ),
        .O(\result[0]_0 ));
  LUT6 #(
    .INIT(64'h52B04290F6BDF2B5)) 
    \temp_reg[3]_i_4 
       (.I0(\res_reg_n_0_[4] ),
        .I1(\res_reg_n_0_[5] ),
        .I2(\temp_reg[0]_i_10_n_0 ),
        .I3(\result[0] ),
        .I4(\res_reg_n_0_[6] ),
        .I5(\result[0]_0 ),
        .O(h0));
endmodule

module DCLK_05
   (clk_change,
    CLK,
    \res_reg[0] ,
    T_IBUF_BUFG,
    clear_IBUF,
    mdown_IBUF,
    mup_IBUF,
    stop_IBUF,
    cls,
    hdown_IBUF,
    hup_IBUF,
    clm);
  output clk_change;
  output CLK;
  output \res_reg[0] ;
  input T_IBUF_BUFG;
  input clear_IBUF;
  input mdown_IBUF;
  input mup_IBUF;
  input stop_IBUF;
  input cls;
  input hdown_IBUF;
  input hup_IBUF;
  input clm;

  wire CLK;
  wire CLK_i_1__1_n_0;
  wire T_IBUF_BUFG;
  wire clear_IBUF;
  wire clk_change;
  wire clm;
  wire cls;
  wire hdown_IBUF;
  wire hup_IBUF;
  wire k1;
  wire k1_carry__0_i_1_n_0;
  wire k1_carry__0_i_2_n_0;
  wire k1_carry__0_i_3_n_0;
  wire k1_carry__0_i_4_n_0;
  wire k1_carry__0_n_0;
  wire k1_carry__0_n_1;
  wire k1_carry__0_n_2;
  wire k1_carry__0_n_3;
  wire k1_carry__1_i_1_n_0;
  wire k1_carry__1_i_2_n_0;
  wire k1_carry__1_i_3_n_0;
  wire k1_carry__1_n_2;
  wire k1_carry__1_n_3;
  wire k1_carry__1_n_4;
  wire k1_carry_i_1_n_0;
  wire k1_carry_i_2_n_0;
  wire k1_carry_i_3_n_0;
  wire k1_carry_i_4_n_0;
  wire k1_carry_n_0;
  wire k1_carry_n_1;
  wire k1_carry_n_2;
  wire k1_carry_n_3;
  wire \k[0]_i_5__0_n_0 ;
  wire [31:0]k_reg;
  wire \k_reg[0]_i_1__0_n_0 ;
  wire \k_reg[0]_i_1__0_n_1 ;
  wire \k_reg[0]_i_1__0_n_2 ;
  wire \k_reg[0]_i_1__0_n_3 ;
  wire \k_reg[0]_i_1__0_n_4 ;
  wire \k_reg[0]_i_1__0_n_5 ;
  wire \k_reg[0]_i_1__0_n_6 ;
  wire \k_reg[0]_i_1__0_n_7 ;
  wire \k_reg[12]_i_1__1_n_0 ;
  wire \k_reg[12]_i_1__1_n_1 ;
  wire \k_reg[12]_i_1__1_n_2 ;
  wire \k_reg[12]_i_1__1_n_3 ;
  wire \k_reg[12]_i_1__1_n_4 ;
  wire \k_reg[12]_i_1__1_n_5 ;
  wire \k_reg[12]_i_1__1_n_6 ;
  wire \k_reg[12]_i_1__1_n_7 ;
  wire \k_reg[16]_i_1__1_n_0 ;
  wire \k_reg[16]_i_1__1_n_1 ;
  wire \k_reg[16]_i_1__1_n_2 ;
  wire \k_reg[16]_i_1__1_n_3 ;
  wire \k_reg[16]_i_1__1_n_4 ;
  wire \k_reg[16]_i_1__1_n_5 ;
  wire \k_reg[16]_i_1__1_n_6 ;
  wire \k_reg[16]_i_1__1_n_7 ;
  wire \k_reg[20]_i_1__1_n_0 ;
  wire \k_reg[20]_i_1__1_n_1 ;
  wire \k_reg[20]_i_1__1_n_2 ;
  wire \k_reg[20]_i_1__1_n_3 ;
  wire \k_reg[20]_i_1__1_n_4 ;
  wire \k_reg[20]_i_1__1_n_5 ;
  wire \k_reg[20]_i_1__1_n_6 ;
  wire \k_reg[20]_i_1__1_n_7 ;
  wire \k_reg[24]_i_1__1_n_0 ;
  wire \k_reg[24]_i_1__1_n_1 ;
  wire \k_reg[24]_i_1__1_n_2 ;
  wire \k_reg[24]_i_1__1_n_3 ;
  wire \k_reg[24]_i_1__1_n_4 ;
  wire \k_reg[24]_i_1__1_n_5 ;
  wire \k_reg[24]_i_1__1_n_6 ;
  wire \k_reg[24]_i_1__1_n_7 ;
  wire \k_reg[28]_i_1__1_n_1 ;
  wire \k_reg[28]_i_1__1_n_2 ;
  wire \k_reg[28]_i_1__1_n_3 ;
  wire \k_reg[28]_i_1__1_n_4 ;
  wire \k_reg[28]_i_1__1_n_5 ;
  wire \k_reg[28]_i_1__1_n_6 ;
  wire \k_reg[28]_i_1__1_n_7 ;
  wire \k_reg[4]_i_1__1_n_0 ;
  wire \k_reg[4]_i_1__1_n_1 ;
  wire \k_reg[4]_i_1__1_n_2 ;
  wire \k_reg[4]_i_1__1_n_3 ;
  wire \k_reg[4]_i_1__1_n_4 ;
  wire \k_reg[4]_i_1__1_n_5 ;
  wire \k_reg[4]_i_1__1_n_6 ;
  wire \k_reg[4]_i_1__1_n_7 ;
  wire \k_reg[8]_i_1__1_n_0 ;
  wire \k_reg[8]_i_1__1_n_1 ;
  wire \k_reg[8]_i_1__1_n_2 ;
  wire \k_reg[8]_i_1__1_n_3 ;
  wire \k_reg[8]_i_1__1_n_4 ;
  wire \k_reg[8]_i_1__1_n_5 ;
  wire \k_reg[8]_i_1__1_n_6 ;
  wire \k_reg[8]_i_1__1_n_7 ;
  wire mdown_IBUF;
  wire mup_IBUF;
  wire \res_reg[0] ;
  wire stop_IBUF;
  wire [3:0]NLW_k1_carry_O_UNCONNECTED;
  wire [3:0]NLW_k1_carry__0_O_UNCONNECTED;
  wire [3:3]NLW_k1_carry__1_CO_UNCONNECTED;
  wire [2:0]NLW_k1_carry__1_O_UNCONNECTED;
  wire [3:3]\NLW_k_reg[28]_i_1__1_CO_UNCONNECTED ;

  LUT2 #(
    .INIT(4'h6)) 
    CLK_i_1__1
       (.I0(k1_carry__1_n_4),
        .I1(clk_change),
        .O(CLK_i_1__1_n_0));
  FDRE #(
    .INIT(1'b0)) 
    CLK_reg
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(CLK_i_1__1_n_0),
        .Q(clk_change),
        .R(1'b0));
  CARRY4 k1_carry
       (.CI(1'b0),
        .CO({k1_carry_n_0,k1_carry_n_1,k1_carry_n_2,k1_carry_n_3}),
        .CYINIT(1'b0),
        .DI({1'b1,1'b1,1'b1,1'b1}),
        .O(NLW_k1_carry_O_UNCONNECTED[3:0]),
        .S({k1_carry_i_1_n_0,k1_carry_i_2_n_0,k1_carry_i_3_n_0,k1_carry_i_4_n_0}));
  CARRY4 k1_carry__0
       (.CI(k1_carry_n_0),
        .CO({k1_carry__0_n_0,k1_carry__0_n_1,k1_carry__0_n_2,k1_carry__0_n_3}),
        .CYINIT(1'b0),
        .DI({1'b1,1'b1,1'b1,1'b1}),
        .O(NLW_k1_carry__0_O_UNCONNECTED[3:0]),
        .S({k1_carry__0_i_1_n_0,k1_carry__0_i_2_n_0,k1_carry__0_i_3_n_0,k1_carry__0_i_4_n_0}));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry__0_i_1
       (.I0(k_reg[23]),
        .I1(k_reg[22]),
        .I2(k_reg[21]),
        .O(k1_carry__0_i_1_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry__0_i_2
       (.I0(k_reg[20]),
        .I1(k_reg[19]),
        .I2(k_reg[18]),
        .O(k1_carry__0_i_2_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry__0_i_3
       (.I0(k_reg[17]),
        .I1(k_reg[16]),
        .I2(k_reg[15]),
        .O(k1_carry__0_i_3_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry__0_i_4
       (.I0(k_reg[14]),
        .I1(k_reg[13]),
        .I2(k_reg[12]),
        .O(k1_carry__0_i_4_n_0));
  CARRY4 k1_carry__1
       (.CI(k1_carry__0_n_0),
        .CO({NLW_k1_carry__1_CO_UNCONNECTED[3],k1,k1_carry__1_n_2,k1_carry__1_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b1,1'b1,1'b1}),
        .O({k1_carry__1_n_4,NLW_k1_carry__1_O_UNCONNECTED[2:0]}),
        .S({1'b1,k1_carry__1_i_1_n_0,k1_carry__1_i_2_n_0,k1_carry__1_i_3_n_0}));
  LUT2 #(
    .INIT(4'h1)) 
    k1_carry__1_i_1
       (.I0(k_reg[30]),
        .I1(k_reg[31]),
        .O(k1_carry__1_i_1_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry__1_i_2
       (.I0(k_reg[29]),
        .I1(k_reg[28]),
        .I2(k_reg[27]),
        .O(k1_carry__1_i_2_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry__1_i_3
       (.I0(k_reg[26]),
        .I1(k_reg[25]),
        .I2(k_reg[24]),
        .O(k1_carry__1_i_3_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry_i_1
       (.I0(k_reg[11]),
        .I1(k_reg[10]),
        .I2(k_reg[9]),
        .O(k1_carry_i_1_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry_i_2
       (.I0(k_reg[8]),
        .I1(k_reg[7]),
        .I2(k_reg[6]),
        .O(k1_carry_i_2_n_0));
  LUT3 #(
    .INIT(8'h01)) 
    k1_carry_i_3
       (.I0(k_reg[5]),
        .I1(k_reg[4]),
        .I2(k_reg[3]),
        .O(k1_carry_i_3_n_0));
  LUT3 #(
    .INIT(8'h20)) 
    k1_carry_i_4
       (.I0(k_reg[0]),
        .I1(k_reg[1]),
        .I2(k_reg[2]),
        .O(k1_carry_i_4_n_0));
  LUT1 #(
    .INIT(2'h1)) 
    \k[0]_i_5__0 
       (.I0(k_reg[0]),
        .O(\k[0]_i_5__0_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[0] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[0]_i_1__0_n_7 ),
        .Q(k_reg[0]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[0]_i_1__0 
       (.CI(1'b0),
        .CO({\k_reg[0]_i_1__0_n_0 ,\k_reg[0]_i_1__0_n_1 ,\k_reg[0]_i_1__0_n_2 ,\k_reg[0]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b1}),
        .O({\k_reg[0]_i_1__0_n_4 ,\k_reg[0]_i_1__0_n_5 ,\k_reg[0]_i_1__0_n_6 ,\k_reg[0]_i_1__0_n_7 }),
        .S({k_reg[3:1],\k[0]_i_5__0_n_0 }));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[10] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[8]_i_1__1_n_5 ),
        .Q(k_reg[10]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[11] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[8]_i_1__1_n_4 ),
        .Q(k_reg[11]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[12] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[12]_i_1__1_n_7 ),
        .Q(k_reg[12]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[12]_i_1__1 
       (.CI(\k_reg[8]_i_1__1_n_0 ),
        .CO({\k_reg[12]_i_1__1_n_0 ,\k_reg[12]_i_1__1_n_1 ,\k_reg[12]_i_1__1_n_2 ,\k_reg[12]_i_1__1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[12]_i_1__1_n_4 ,\k_reg[12]_i_1__1_n_5 ,\k_reg[12]_i_1__1_n_6 ,\k_reg[12]_i_1__1_n_7 }),
        .S(k_reg[15:12]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[13] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[12]_i_1__1_n_6 ),
        .Q(k_reg[13]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[14] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[12]_i_1__1_n_5 ),
        .Q(k_reg[14]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[15] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[12]_i_1__1_n_4 ),
        .Q(k_reg[15]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[16] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[16]_i_1__1_n_7 ),
        .Q(k_reg[16]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[16]_i_1__1 
       (.CI(\k_reg[12]_i_1__1_n_0 ),
        .CO({\k_reg[16]_i_1__1_n_0 ,\k_reg[16]_i_1__1_n_1 ,\k_reg[16]_i_1__1_n_2 ,\k_reg[16]_i_1__1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[16]_i_1__1_n_4 ,\k_reg[16]_i_1__1_n_5 ,\k_reg[16]_i_1__1_n_6 ,\k_reg[16]_i_1__1_n_7 }),
        .S(k_reg[19:16]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[17] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[16]_i_1__1_n_6 ),
        .Q(k_reg[17]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[18] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[16]_i_1__1_n_5 ),
        .Q(k_reg[18]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[19] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[16]_i_1__1_n_4 ),
        .Q(k_reg[19]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[1] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[0]_i_1__0_n_6 ),
        .Q(k_reg[1]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[20] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[20]_i_1__1_n_7 ),
        .Q(k_reg[20]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[20]_i_1__1 
       (.CI(\k_reg[16]_i_1__1_n_0 ),
        .CO({\k_reg[20]_i_1__1_n_0 ,\k_reg[20]_i_1__1_n_1 ,\k_reg[20]_i_1__1_n_2 ,\k_reg[20]_i_1__1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[20]_i_1__1_n_4 ,\k_reg[20]_i_1__1_n_5 ,\k_reg[20]_i_1__1_n_6 ,\k_reg[20]_i_1__1_n_7 }),
        .S(k_reg[23:20]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[21] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[20]_i_1__1_n_6 ),
        .Q(k_reg[21]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[22] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[20]_i_1__1_n_5 ),
        .Q(k_reg[22]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[23] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[20]_i_1__1_n_4 ),
        .Q(k_reg[23]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[24] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[24]_i_1__1_n_7 ),
        .Q(k_reg[24]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[24]_i_1__1 
       (.CI(\k_reg[20]_i_1__1_n_0 ),
        .CO({\k_reg[24]_i_1__1_n_0 ,\k_reg[24]_i_1__1_n_1 ,\k_reg[24]_i_1__1_n_2 ,\k_reg[24]_i_1__1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[24]_i_1__1_n_4 ,\k_reg[24]_i_1__1_n_5 ,\k_reg[24]_i_1__1_n_6 ,\k_reg[24]_i_1__1_n_7 }),
        .S(k_reg[27:24]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[25] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[24]_i_1__1_n_6 ),
        .Q(k_reg[25]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[26] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[24]_i_1__1_n_5 ),
        .Q(k_reg[26]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[27] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[24]_i_1__1_n_4 ),
        .Q(k_reg[27]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[28] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[28]_i_1__1_n_7 ),
        .Q(k_reg[28]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[28]_i_1__1 
       (.CI(\k_reg[24]_i_1__1_n_0 ),
        .CO({\NLW_k_reg[28]_i_1__1_CO_UNCONNECTED [3],\k_reg[28]_i_1__1_n_1 ,\k_reg[28]_i_1__1_n_2 ,\k_reg[28]_i_1__1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[28]_i_1__1_n_4 ,\k_reg[28]_i_1__1_n_5 ,\k_reg[28]_i_1__1_n_6 ,\k_reg[28]_i_1__1_n_7 }),
        .S(k_reg[31:28]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[29] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[28]_i_1__1_n_6 ),
        .Q(k_reg[29]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[2] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[0]_i_1__0_n_5 ),
        .Q(k_reg[2]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[30] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[28]_i_1__1_n_5 ),
        .Q(k_reg[30]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[31] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[28]_i_1__1_n_4 ),
        .Q(k_reg[31]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[3] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[0]_i_1__0_n_4 ),
        .Q(k_reg[3]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[4] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[4]_i_1__1_n_7 ),
        .Q(k_reg[4]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[4]_i_1__1 
       (.CI(\k_reg[0]_i_1__0_n_0 ),
        .CO({\k_reg[4]_i_1__1_n_0 ,\k_reg[4]_i_1__1_n_1 ,\k_reg[4]_i_1__1_n_2 ,\k_reg[4]_i_1__1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[4]_i_1__1_n_4 ,\k_reg[4]_i_1__1_n_5 ,\k_reg[4]_i_1__1_n_6 ,\k_reg[4]_i_1__1_n_7 }),
        .S(k_reg[7:4]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[5] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[4]_i_1__1_n_6 ),
        .Q(k_reg[5]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[6] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[4]_i_1__1_n_5 ),
        .Q(k_reg[6]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[7] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[4]_i_1__1_n_4 ),
        .Q(k_reg[7]),
        .R(k1_carry__1_n_4));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[8] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[8]_i_1__1_n_7 ),
        .Q(k_reg[8]),
        .R(k1_carry__1_n_4));
  CARRY4 \k_reg[8]_i_1__1 
       (.CI(\k_reg[4]_i_1__1_n_0 ),
        .CO({\k_reg[8]_i_1__1_n_0 ,\k_reg[8]_i_1__1_n_1 ,\k_reg[8]_i_1__1_n_2 ,\k_reg[8]_i_1__1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[8]_i_1__1_n_4 ,\k_reg[8]_i_1__1_n_5 ,\k_reg[8]_i_1__1_n_6 ,\k_reg[8]_i_1__1_n_7 }),
        .S(k_reg[11:8]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[9] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(\k_reg[8]_i_1__1_n_6 ),
        .Q(k_reg[9]),
        .R(k1_carry__1_n_4));
  LUT6 #(
    .INIT(64'hAAABBBBBAAA88888)) 
    \res[0]_i_3__0 
       (.I0(clk_change),
        .I1(clear_IBUF),
        .I2(mdown_IBUF),
        .I3(mup_IBUF),
        .I4(stop_IBUF),
        .I5(cls),
        .O(CLK));
  LUT6 #(
    .INIT(64'hAAABBBBBAAA88888)) 
    \res[0]_i_3__1 
       (.I0(clk_change),
        .I1(clear_IBUF),
        .I2(hdown_IBUF),
        .I3(hup_IBUF),
        .I4(stop_IBUF),
        .I5(clm),
        .O(\res_reg[0] ));
endmodule

module DCLK_1
   (clk_OBUF,
    CLK,
    T_IBUF_BUFG,
    stop_IBUF,
    sdown_IBUF,
    sup_IBUF,
    clear_IBUF,
    clk_change);
  output clk_OBUF;
  output CLK;
  input T_IBUF_BUFG;
  input stop_IBUF;
  input sdown_IBUF;
  input sup_IBUF;
  input clear_IBUF;
  input clk_change;

  wire CLK;
  wire CLK_0;
  wire CLK_i_1_n_0;
  wire T_IBUF_BUFG;
  wire clear_IBUF;
  wire clk_OBUF;
  wire clk_change;
  wire [31:1]data0;
  wire [31:0]k;
  wire \k[31]_i_10_n_0 ;
  wire \k[31]_i_11_n_0 ;
  wire \k[31]_i_12_n_0 ;
  wire \k[31]_i_13_n_0 ;
  wire \k[31]_i_3_n_0 ;
  wire \k[31]_i_4_n_0 ;
  wire \k[31]_i_5_n_0 ;
  wire \k[31]_i_6_n_0 ;
  wire [0:0]k_1;
  wire \k_reg[12]_i_1__0_n_0 ;
  wire \k_reg[12]_i_1__0_n_1 ;
  wire \k_reg[12]_i_1__0_n_2 ;
  wire \k_reg[12]_i_1__0_n_3 ;
  wire \k_reg[16]_i_1__0_n_0 ;
  wire \k_reg[16]_i_1__0_n_1 ;
  wire \k_reg[16]_i_1__0_n_2 ;
  wire \k_reg[16]_i_1__0_n_3 ;
  wire \k_reg[20]_i_1__0_n_0 ;
  wire \k_reg[20]_i_1__0_n_1 ;
  wire \k_reg[20]_i_1__0_n_2 ;
  wire \k_reg[20]_i_1__0_n_3 ;
  wire \k_reg[24]_i_1__0_n_0 ;
  wire \k_reg[24]_i_1__0_n_1 ;
  wire \k_reg[24]_i_1__0_n_2 ;
  wire \k_reg[24]_i_1__0_n_3 ;
  wire \k_reg[28]_i_1__0_n_0 ;
  wire \k_reg[28]_i_1__0_n_1 ;
  wire \k_reg[28]_i_1__0_n_2 ;
  wire \k_reg[28]_i_1__0_n_3 ;
  wire \k_reg[31]_i_2_n_2 ;
  wire \k_reg[31]_i_2_n_3 ;
  wire \k_reg[4]_i_1__0_n_0 ;
  wire \k_reg[4]_i_1__0_n_1 ;
  wire \k_reg[4]_i_1__0_n_2 ;
  wire \k_reg[4]_i_1__0_n_3 ;
  wire \k_reg[8]_i_1__0_n_0 ;
  wire \k_reg[8]_i_1__0_n_1 ;
  wire \k_reg[8]_i_1__0_n_2 ;
  wire \k_reg[8]_i_1__0_n_3 ;
  wire sdown_IBUF;
  wire stop_IBUF;
  wire sup_IBUF;
  wire [3:2]\NLW_k_reg[31]_i_2_CO_UNCONNECTED ;
  wire [3:3]\NLW_k_reg[31]_i_2_O_UNCONNECTED ;

  LUT5 #(
    .INIT(32'hFFFE0001)) 
    CLK_i_1
       (.I0(\k[31]_i_3_n_0 ),
        .I1(\k[31]_i_4_n_0 ),
        .I2(\k[31]_i_5_n_0 ),
        .I3(\k[31]_i_6_n_0 ),
        .I4(clk_OBUF),
        .O(CLK_i_1_n_0));
  FDRE #(
    .INIT(1'b0)) 
    CLK_reg
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(CLK_i_1_n_0),
        .Q(clk_OBUF),
        .R(1'b0));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT1 #(
    .INIT(2'h1)) 
    \k[0]_i_1 
       (.I0(k[0]),
        .O(k_1));
  LUT4 #(
    .INIT(16'h0001)) 
    \k[31]_i_1 
       (.I0(\k[31]_i_3_n_0 ),
        .I1(\k[31]_i_4_n_0 ),
        .I2(\k[31]_i_5_n_0 ),
        .I3(\k[31]_i_6_n_0 ),
        .O(CLK_0));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_10 
       (.I0(k[21]),
        .I1(k[20]),
        .I2(k[23]),
        .I3(k[22]),
        .O(\k[31]_i_10_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_11 
       (.I0(k[29]),
        .I1(k[28]),
        .I2(k[31]),
        .I3(k[30]),
        .O(\k[31]_i_11_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_12 
       (.I0(k[5]),
        .I1(k[4]),
        .I2(k[7]),
        .I3(k[6]),
        .O(\k[31]_i_12_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[31]_i_13 
       (.I0(k[13]),
        .I1(k[12]),
        .I2(k[15]),
        .I3(k[14]),
        .O(\k[31]_i_13_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFFFE)) 
    \k[31]_i_3 
       (.I0(k[18]),
        .I1(k[19]),
        .I2(k[16]),
        .I3(k[17]),
        .I4(\k[31]_i_10_n_0 ),
        .O(\k[31]_i_3_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFFFE)) 
    \k[31]_i_4 
       (.I0(k[26]),
        .I1(k[27]),
        .I2(k[24]),
        .I3(k[25]),
        .I4(\k[31]_i_11_n_0 ),
        .O(\k[31]_i_4_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'hFFFFFBFF)) 
    \k[31]_i_5 
       (.I0(k[3]),
        .I1(k[2]),
        .I2(k[1]),
        .I3(k[0]),
        .I4(\k[31]_i_12_n_0 ),
        .O(\k[31]_i_5_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFFFE)) 
    \k[31]_i_6 
       (.I0(k[10]),
        .I1(k[11]),
        .I2(k[8]),
        .I3(k[9]),
        .I4(\k[31]_i_13_n_0 ),
        .O(\k[31]_i_6_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[0] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k_1),
        .Q(k[0]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[10] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[10]),
        .Q(k[10]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[11] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[11]),
        .Q(k[11]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[12] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[12]),
        .Q(k[12]),
        .R(CLK_0));
  CARRY4 \k_reg[12]_i_1__0 
       (.CI(\k_reg[8]_i_1__0_n_0 ),
        .CO({\k_reg[12]_i_1__0_n_0 ,\k_reg[12]_i_1__0_n_1 ,\k_reg[12]_i_1__0_n_2 ,\k_reg[12]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[12:9]),
        .S(k[12:9]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[13] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[13]),
        .Q(k[13]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[14] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[14]),
        .Q(k[14]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[15] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[15]),
        .Q(k[15]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[16] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[16]),
        .Q(k[16]),
        .R(CLK_0));
  CARRY4 \k_reg[16]_i_1__0 
       (.CI(\k_reg[12]_i_1__0_n_0 ),
        .CO({\k_reg[16]_i_1__0_n_0 ,\k_reg[16]_i_1__0_n_1 ,\k_reg[16]_i_1__0_n_2 ,\k_reg[16]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[16:13]),
        .S(k[16:13]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[17] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[17]),
        .Q(k[17]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[18] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[18]),
        .Q(k[18]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[19] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[19]),
        .Q(k[19]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[1] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[1]),
        .Q(k[1]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[20] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[20]),
        .Q(k[20]),
        .R(CLK_0));
  CARRY4 \k_reg[20]_i_1__0 
       (.CI(\k_reg[16]_i_1__0_n_0 ),
        .CO({\k_reg[20]_i_1__0_n_0 ,\k_reg[20]_i_1__0_n_1 ,\k_reg[20]_i_1__0_n_2 ,\k_reg[20]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[20:17]),
        .S(k[20:17]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[21] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[21]),
        .Q(k[21]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[22] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[22]),
        .Q(k[22]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[23] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[23]),
        .Q(k[23]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[24] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[24]),
        .Q(k[24]),
        .R(CLK_0));
  CARRY4 \k_reg[24]_i_1__0 
       (.CI(\k_reg[20]_i_1__0_n_0 ),
        .CO({\k_reg[24]_i_1__0_n_0 ,\k_reg[24]_i_1__0_n_1 ,\k_reg[24]_i_1__0_n_2 ,\k_reg[24]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[24:21]),
        .S(k[24:21]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[25] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[25]),
        .Q(k[25]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[26] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[26]),
        .Q(k[26]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[27] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[27]),
        .Q(k[27]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[28] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[28]),
        .Q(k[28]),
        .R(CLK_0));
  CARRY4 \k_reg[28]_i_1__0 
       (.CI(\k_reg[24]_i_1__0_n_0 ),
        .CO({\k_reg[28]_i_1__0_n_0 ,\k_reg[28]_i_1__0_n_1 ,\k_reg[28]_i_1__0_n_2 ,\k_reg[28]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[28:25]),
        .S(k[28:25]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[29] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[29]),
        .Q(k[29]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[2] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[2]),
        .Q(k[2]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[30] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[30]),
        .Q(k[30]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[31] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[31]),
        .Q(k[31]),
        .R(CLK_0));
  CARRY4 \k_reg[31]_i_2 
       (.CI(\k_reg[28]_i_1__0_n_0 ),
        .CO({\NLW_k_reg[31]_i_2_CO_UNCONNECTED [3:2],\k_reg[31]_i_2_n_2 ,\k_reg[31]_i_2_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\NLW_k_reg[31]_i_2_O_UNCONNECTED [3],data0[31:29]}),
        .S({1'b0,k[31:29]}));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[3] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[3]),
        .Q(k[3]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[4] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[4]),
        .Q(k[4]),
        .R(CLK_0));
  CARRY4 \k_reg[4]_i_1__0 
       (.CI(1'b0),
        .CO({\k_reg[4]_i_1__0_n_0 ,\k_reg[4]_i_1__0_n_1 ,\k_reg[4]_i_1__0_n_2 ,\k_reg[4]_i_1__0_n_3 }),
        .CYINIT(k[0]),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[4:1]),
        .S(k[4:1]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[5] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[5]),
        .Q(k[5]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[6] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[6]),
        .Q(k[6]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[7] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[7]),
        .Q(k[7]),
        .R(CLK_0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[8] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[8]),
        .Q(k[8]),
        .R(CLK_0));
  CARRY4 \k_reg[8]_i_1__0 
       (.CI(\k_reg[4]_i_1__0_n_0 ),
        .CO({\k_reg[8]_i_1__0_n_0 ,\k_reg[8]_i_1__0_n_1 ,\k_reg[8]_i_1__0_n_2 ,\k_reg[8]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[8:5]),
        .S(k[8:5]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[9] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[9]),
        .Q(k[9]),
        .R(CLK_0));
  LUT6 #(
    .INIT(64'hFFFFEEEA0000222A)) 
    \res[0]_i_3 
       (.I0(clk_OBUF),
        .I1(stop_IBUF),
        .I2(sdown_IBUF),
        .I3(sup_IBUF),
        .I4(clear_IBUF),
        .I5(clk_change),
        .O(CLK));
endmodule

(* NotValidForBitStream *)
module Main
   (T,
    clear,
    stop,
    loud,
    clk,
    sup,
    sdown,
    mup,
    mdown,
    hup,
    hdown,
    select,
    result,
    s0,
    s1);
  input T;
  input clear;
  input stop;
  output loud;
  output clk;
  input sup;
  input sdown;
  input mup;
  input mdown;
  input hup;
  input hdown;
  output [0:7]select;
  output [0:7]result;
  output [0:3]s0;
  output [0:3]s1;

  wire L8_n_1;
  wire L8_n_3;
  wire L8_n_7;
  wire L8_n_8;
  wire L8_n_9;
  wire L9_n_6;
  wire L9_n_7;
  wire T;
  wire T_IBUF;
  wire T_IBUF_BUFG;
  wire clear;
  wire clear_IBUF;
  wire clk;
  wire clk_OBUF;
  wire clk_OBUF_BUFG;
  wire clk_change;
  wire clm;
  wire cls;
  wire [1:3]h0;
  wire [0:3]h1;
  wire hdown;
  wire hdown_IBUF;
  wire hup;
  wire hup_IBUF;
  wire loud;
  wire loud_OBUF;
  wire [3:3]m0;
  wire [0:3]m1;
  wire mdown;
  wire mdown_IBUF;
  wire mup;
  wire mup_IBUF;
  wire [0:7]result;
  wire [0:6]result_OBUF;
  wire [0:3]s0;
  wire [0:3]s0_OBUF;
  wire [0:3]s1;
  wire [0:3]s1_OBUF;
  wire sdown;
  wire sdown_IBUF;
  wire [0:7]select;
  wire [1:7]select_OBUF;
  wire stop;
  wire stop_IBUF;
  wire sup;
  wire sup_IBUF;
  wire \uCt_s/clk_temp ;
  wire \uCt_s/clk_temp_0 ;
  wire \uCt_s/clk_temp_1 ;
  wire uPt_n_0;
  wire uPt_n_1;

initial begin
 $sdf_annotate("Main_tb_time_synth.sdf",,,,"tool_control");
end
  RING L10
       (.clk_OBUF_BUFG(clk_OBUF_BUFG),
        .co_reg(L8_n_3),
        .loud_OBUF(loud_OBUF));
  DCLK_05 L5
       (.CLK(\uCt_s/clk_temp_0 ),
        .T_IBUF_BUFG(T_IBUF_BUFG),
        .clear_IBUF(clear_IBUF),
        .clk_change(clk_change),
        .clm(clm),
        .cls(cls),
        .hdown_IBUF(hdown_IBUF),
        .hup_IBUF(hup_IBUF),
        .mdown_IBUF(mdown_IBUF),
        .mup_IBUF(mup_IBUF),
        .\res_reg[0] (\uCt_s/clk_temp ),
        .stop_IBUF(stop_IBUF));
  DCLK_1 L6
       (.CLK(\uCt_s/clk_temp_1 ),
        .T_IBUF_BUFG(T_IBUF_BUFG),
        .clear_IBUF(clear_IBUF),
        .clk_OBUF(clk_OBUF),
        .clk_change(clk_change),
        .sdown_IBUF(sdown_IBUF),
        .stop_IBUF(stop_IBUF),
        .sup_IBUF(sup_IBUF));
  CLOCK_S L7
       (.CLK(\uCt_s/clk_temp_1 ),
        .clear_IBUF(clear_IBUF),
        .cls(cls),
        .s0_OBUF(s0_OBUF),
        .s1_OBUF(s1_OBUF),
        .sdown_IBUF(sdown_IBUF),
        .stop_IBUF(stop_IBUF),
        .sup_IBUF(sup_IBUF));
  CLOCK_M L8
       (.CLK(\uCt_s/clk_temp_0 ),
        .clear_IBUF(clear_IBUF),
        .clm(clm),
        .h1(h1[2]),
        .\k_reg[31] (L8_n_3),
        .m0(m0),
        .m1({m1[0],m1[1],m1[3]}),
        .mdown_IBUF(mdown_IBUF),
        .mup_IBUF(mup_IBUF),
        .out({uPt_n_0,uPt_n_1}),
        .\result[0] (L8_n_1),
        .\result[0]_0 (L8_n_7),
        .\result[0]_1 (L8_n_8),
        .\result[0]_2 (L8_n_9),
        .s1_OBUF(s1_OBUF[2]),
        .stop_IBUF(stop_IBUF));
  CLOCK_H L9
       (.CLK(\uCt_s/clk_temp ),
        .clear_IBUF(clear_IBUF),
        .h0({h0[1],h0[3]}),
        .h1(h1),
        .hdown_IBUF(hdown_IBUF),
        .hup_IBUF(hup_IBUF),
        .\result[0] (L9_n_6),
        .\result[0]_0 (L9_n_7),
        .stop_IBUF(stop_IBUF));
  BUFG T_IBUF_BUFG_inst
       (.I(T_IBUF),
        .O(T_IBUF_BUFG));
  IBUF T_IBUF_inst
       (.I(T),
        .O(T_IBUF));
  IBUF clear_IBUF_inst
       (.I(clear),
        .O(clear_IBUF));
  BUFG clk_OBUF_BUFG_inst
       (.I(clk_OBUF),
        .O(clk_OBUF_BUFG));
  OBUF clk_OBUF_inst
       (.I(clk_OBUF_BUFG),
        .O(clk));
  IBUF hdown_IBUF_inst
       (.I(hdown),
        .O(hdown_IBUF));
  IBUF hup_IBUF_inst
       (.I(hup),
        .O(hup_IBUF));
  OBUF loud_OBUF_inst
       (.I(loud_OBUF),
        .O(loud));
  IBUF mdown_IBUF_inst
       (.I(mdown),
        .O(mdown_IBUF));
  IBUF mup_IBUF_inst
       (.I(mup),
        .O(mup_IBUF));
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
       (.I(1'b0),
        .O(result[7]));
  OBUF \s0_OBUF[0]_inst 
       (.I(s0_OBUF[0]),
        .O(s0[0]));
  OBUF \s0_OBUF[1]_inst 
       (.I(s0_OBUF[1]),
        .O(s0[1]));
  OBUF \s0_OBUF[2]_inst 
       (.I(s0_OBUF[2]),
        .O(s0[2]));
  OBUF \s0_OBUF[3]_inst 
       (.I(s0_OBUF[3]),
        .O(s0[3]));
  OBUF \s1_OBUF[0]_inst 
       (.I(s1_OBUF[0]),
        .O(s1[0]));
  OBUF \s1_OBUF[1]_inst 
       (.I(s1_OBUF[1]),
        .O(s1[1]));
  OBUF \s1_OBUF[2]_inst 
       (.I(s1_OBUF[2]),
        .O(s1[2]));
  OBUF \s1_OBUF[3]_inst 
       (.I(s1_OBUF[3]),
        .O(s1[3]));
  IBUF sdown_IBUF_inst
       (.I(sdown),
        .O(sdown_IBUF));
  OBUF \select_OBUF[0]_inst 
       (.I(select_OBUF[1]),
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
  IBUF stop_IBUF_inst
       (.I(stop),
        .O(stop_IBUF));
  IBUF sup_IBUF_inst
       (.I(sup),
        .O(sup_IBUF));
  Print uPt
       (.T_IBUF_BUFG(T_IBUF_BUFG),
        .h0({h0[1],h0[3]}),
        .h1({h1[0],h1[1],h1[3]}),
        .m0(m0),
        .m1({m1[0],m1[1],m1[3]}),
        .out({uPt_n_0,uPt_n_1}),
        .\res_reg[3] (L8_n_9),
        .\res_reg[3]_0 (L9_n_7),
        .\res_reg[4] (L8_n_8),
        .\res_reg[4]_0 (L8_n_7),
        .\res_reg[5] (L9_n_6),
        .\res_reg[6] (L8_n_1),
        .result_OBUF({result_OBUF[0],result_OBUF[1],result_OBUF[2],result_OBUF[3],result_OBUF[4],result_OBUF[5],result_OBUF[6]}),
        .s0_OBUF(s0_OBUF),
        .s1_OBUF({s1_OBUF[0],s1_OBUF[1],s1_OBUF[3]}),
        .select_OBUF({select_OBUF[1],select_OBUF[2],select_OBUF[3],select_OBUF[4],select_OBUF[5],select_OBUF[6],select_OBUF[7]}));
endmodule

module Print
   (out,
    select_OBUF,
    result_OBUF,
    T_IBUF_BUFG,
    m1,
    h1,
    s1_OBUF,
    m0,
    h0,
    s0_OBUF,
    \res_reg[6] ,
    \res_reg[4] ,
    \res_reg[5] ,
    \res_reg[4]_0 ,
    \res_reg[3] ,
    \res_reg[3]_0 );
  output [1:0]out;
  output [6:0]select_OBUF;
  output [6:0]result_OBUF;
  input T_IBUF_BUFG;
  input [2:0]m1;
  input [2:0]h1;
  input [2:0]s1_OBUF;
  input [0:0]m0;
  input [1:0]h0;
  input [0:3]s0_OBUF;
  input \res_reg[6] ;
  input \res_reg[4] ;
  input \res_reg[5] ;
  input \res_reg[4]_0 ;
  input \res_reg[3] ;
  input \res_reg[3]_0 ;

  wire \FSM_sequential_select[0]_i_1_n_0 ;
  wire \FSM_sequential_select[1]_i_1_n_0 ;
  wire \FSM_sequential_select[2]_i_1_n_0 ;
  wire T_IBUF_BUFG;
  wire clr;
  wire [1:0]h0;
  wire [2:0]h1;
  wire [0:0]m0;
  wire [2:0]m1;
  (* RTL_KEEP = "yes" *) wire [1:0]out;
  wire \res_reg[3] ;
  wire \res_reg[3]_0 ;
  wire \res_reg[4] ;
  wire \res_reg[4]_0 ;
  wire \res_reg[5] ;
  wire \res_reg[6] ;
  wire [6:0]result_OBUF;
  wire [0:3]s0_OBUF;
  wire [2:0]s1_OBUF;
  (* RTL_KEEP = "yes" *) wire [0:0]select;
  wire [6:0]select_OBUF;
  wire [0:3]temp;
  wire \temp_reg[0]_i_1_n_0 ;
  wire \temp_reg[0]_i_2_n_0 ;
  wire \temp_reg[0]_i_3_n_0 ;
  wire \temp_reg[0]_i_4_n_0 ;
  wire \temp_reg[1]_i_1_n_0 ;
  wire \temp_reg[1]_i_2_n_0 ;
  wire \temp_reg[1]_i_3_n_0 ;
  wire \temp_reg[2]_i_1_n_0 ;
  wire \temp_reg[2]_i_3_n_0 ;
  wire \temp_reg[3]_i_1_n_0 ;
  wire \temp_reg[3]_i_2_n_0 ;
  wire \temp_reg[3]_i_3_n_0 ;

  LUT4 #(
    .INIT(16'hD515)) 
    \FSM_sequential_select[0]_i_1 
       (.I0(select),
        .I1(out[0]),
        .I2(out[1]),
        .I3(select),
        .O(\FSM_sequential_select[0]_i_1_n_0 ));
  LUT4 #(
    .INIT(16'hC606)) 
    \FSM_sequential_select[1]_i_1 
       (.I0(select),
        .I1(out[0]),
        .I2(out[1]),
        .I3(out[0]),
        .O(\FSM_sequential_select[1]_i_1_n_0 ));
  LUT4 #(
    .INIT(16'hD818)) 
    \FSM_sequential_select[2]_i_1 
       (.I0(select),
        .I1(out[0]),
        .I2(out[1]),
        .I3(out[1]),
        .O(\FSM_sequential_select[2]_i_1_n_0 ));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_select_reg[0] 
       (.C(clr),
        .CE(1'b1),
        .D(\FSM_sequential_select[0]_i_1_n_0 ),
        .Q(select),
        .R(1'b0));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_select_reg[1] 
       (.C(clr),
        .CE(1'b1),
        .D(\FSM_sequential_select[1]_i_1_n_0 ),
        .Q(out[0]),
        .R(1'b0));
  (* KEEP = "yes" *) 
  FDRE #(
    .INIT(1'b0)) 
    \FSM_sequential_select_reg[2] 
       (.C(clr),
        .CE(1'b1),
        .D(\FSM_sequential_select[2]_i_1_n_0 ),
        .Q(out[1]),
        .R(1'b0));
  LUT2 #(
    .INIT(4'h7)) 
    \select_OBUF[0]_inst_i_1 
       (.I0(out[1]),
        .I1(out[0]),
        .O(select_OBUF[6]));
  LUT3 #(
    .INIT(8'h57)) 
    \select_OBUF[2]_inst_i_1 
       (.I0(out[1]),
        .I1(select),
        .I2(out[0]),
        .O(select_OBUF[5]));
  LUT3 #(
    .INIT(8'h5D)) 
    \select_OBUF[3]_inst_i_1 
       (.I0(out[1]),
        .I1(select),
        .I2(out[0]),
        .O(select_OBUF[4]));
  LUT3 #(
    .INIT(8'h57)) 
    \select_OBUF[4]_inst_i_1 
       (.I0(out[0]),
        .I1(select),
        .I2(out[1]),
        .O(select_OBUF[3]));
  LUT3 #(
    .INIT(8'h5D)) 
    \select_OBUF[5]_inst_i_1 
       (.I0(out[0]),
        .I1(select),
        .I2(out[1]),
        .O(select_OBUF[2]));
  LUT3 #(
    .INIT(8'h5B)) 
    \select_OBUF[6]_inst_i_1 
       (.I0(out[1]),
        .I1(select),
        .I2(out[0]),
        .O(select_OBUF[1]));
  LUT3 #(
    .INIT(8'h5E)) 
    \select_OBUF[7]_inst_i_1 
       (.I0(out[1]),
        .I1(select),
        .I2(out[0]),
        .O(select_OBUF[0]));
  (* XILINX_LEGACY_PRIM = "LD" *) 
  LDCE #(
    .INIT(1'b0)) 
    \temp_reg[0] 
       (.CLR(1'b0),
        .D(\temp_reg[0]_i_1_n_0 ),
        .G(\temp_reg[0]_i_2_n_0 ),
        .GE(1'b1),
        .Q(temp[0]));
  MUXF7 \temp_reg[0]_i_1 
       (.I0(\temp_reg[0]_i_3_n_0 ),
        .I1(\temp_reg[0]_i_4_n_0 ),
        .O(\temp_reg[0]_i_1_n_0 ),
        .S(select));
  LUT2 #(
    .INIT(4'h7)) 
    \temp_reg[0]_i_2 
       (.I0(out[0]),
        .I1(out[1]),
        .O(\temp_reg[0]_i_2_n_0 ));
  LUT5 #(
    .INIT(32'h30BB3088)) 
    \temp_reg[0]_i_3 
       (.I0(m1[2]),
        .I1(out[0]),
        .I2(h1[2]),
        .I3(out[1]),
        .I4(s1_OBUF[2]),
        .O(\temp_reg[0]_i_3_n_0 ));
  LUT5 #(
    .INIT(32'h03770344)) 
    \temp_reg[0]_i_4 
       (.I0(\res_reg[3] ),
        .I1(out[0]),
        .I2(\res_reg[3]_0 ),
        .I3(out[1]),
        .I4(s0_OBUF[0]),
        .O(\temp_reg[0]_i_4_n_0 ));
  (* XILINX_LEGACY_PRIM = "LD" *) 
  LDCE #(
    .INIT(1'b0)) 
    \temp_reg[1] 
       (.CLR(1'b0),
        .D(\temp_reg[1]_i_1_n_0 ),
        .G(\temp_reg[0]_i_2_n_0 ),
        .GE(1'b1),
        .Q(temp[1]));
  MUXF7 \temp_reg[1]_i_1 
       (.I0(\temp_reg[1]_i_2_n_0 ),
        .I1(\temp_reg[1]_i_3_n_0 ),
        .O(\temp_reg[1]_i_1_n_0 ),
        .S(select));
  LUT5 #(
    .INIT(32'h30BB3088)) 
    \temp_reg[1]_i_2 
       (.I0(m1[1]),
        .I1(out[0]),
        .I2(h1[1]),
        .I3(out[1]),
        .I4(s1_OBUF[1]),
        .O(\temp_reg[1]_i_2_n_0 ));
  LUT5 #(
    .INIT(32'h30773044)) 
    \temp_reg[1]_i_3 
       (.I0(\res_reg[4]_0 ),
        .I1(out[0]),
        .I2(h0[1]),
        .I3(out[1]),
        .I4(s0_OBUF[1]),
        .O(\temp_reg[1]_i_3_n_0 ));
  (* XILINX_LEGACY_PRIM = "LD" *) 
  LDCE #(
    .INIT(1'b0)) 
    \temp_reg[2] 
       (.CLR(1'b0),
        .D(\temp_reg[2]_i_1_n_0 ),
        .G(\temp_reg[0]_i_2_n_0 ),
        .GE(1'b1),
        .Q(temp[2]));
  MUXF7 \temp_reg[2]_i_1 
       (.I0(\res_reg[6] ),
        .I1(\temp_reg[2]_i_3_n_0 ),
        .O(\temp_reg[2]_i_1_n_0 ),
        .S(select));
  LUT5 #(
    .INIT(32'h03770344)) 
    \temp_reg[2]_i_3 
       (.I0(\res_reg[4] ),
        .I1(out[0]),
        .I2(\res_reg[5] ),
        .I3(out[1]),
        .I4(s0_OBUF[2]),
        .O(\temp_reg[2]_i_3_n_0 ));
  (* XILINX_LEGACY_PRIM = "LD" *) 
  LDCE #(
    .INIT(1'b0)) 
    \temp_reg[3] 
       (.CLR(1'b0),
        .D(\temp_reg[3]_i_1_n_0 ),
        .G(\temp_reg[0]_i_2_n_0 ),
        .GE(1'b1),
        .Q(temp[3]));
  MUXF7 \temp_reg[3]_i_1 
       (.I0(\temp_reg[3]_i_2_n_0 ),
        .I1(\temp_reg[3]_i_3_n_0 ),
        .O(\temp_reg[3]_i_1_n_0 ),
        .S(select));
  LUT5 #(
    .INIT(32'h30BB3088)) 
    \temp_reg[3]_i_2 
       (.I0(m1[0]),
        .I1(out[0]),
        .I2(h1[0]),
        .I3(out[1]),
        .I4(s1_OBUF[0]),
        .O(\temp_reg[3]_i_2_n_0 ));
  LUT5 #(
    .INIT(32'h30BB3088)) 
    \temp_reg[3]_i_3 
       (.I0(m0),
        .I1(out[0]),
        .I2(h0[0]),
        .I3(out[1]),
        .I4(s0_OBUF[3]),
        .O(\temp_reg[3]_i_3_n_0 ));
  SevenSegNumIndic uSn
       (.Q({temp[0],temp[1],temp[2],temp[3]}),
        .result_OBUF(result_OBUF));
  segTime usg
       (.T_IBUF_BUFG(T_IBUF_BUFG),
        .clr(clr));
endmodule

module RING
   (loud_OBUF,
    co_reg,
    clk_OBUF_BUFG);
  output loud_OBUF;
  input co_reg;
  input clk_OBUF_BUFG;

  wire clk_OBUF_BUFG;
  wire co_reg;
  wire \k[0]_i_5_n_0 ;
  wire [31:0]k_reg;
  wire \k_reg[0]_i_1_n_0 ;
  wire \k_reg[0]_i_1_n_1 ;
  wire \k_reg[0]_i_1_n_2 ;
  wire \k_reg[0]_i_1_n_3 ;
  wire \k_reg[0]_i_1_n_4 ;
  wire \k_reg[0]_i_1_n_5 ;
  wire \k_reg[0]_i_1_n_6 ;
  wire \k_reg[0]_i_1_n_7 ;
  wire \k_reg[12]_i_1_n_0 ;
  wire \k_reg[12]_i_1_n_1 ;
  wire \k_reg[12]_i_1_n_2 ;
  wire \k_reg[12]_i_1_n_3 ;
  wire \k_reg[12]_i_1_n_4 ;
  wire \k_reg[12]_i_1_n_5 ;
  wire \k_reg[12]_i_1_n_6 ;
  wire \k_reg[12]_i_1_n_7 ;
  wire \k_reg[16]_i_1_n_0 ;
  wire \k_reg[16]_i_1_n_1 ;
  wire \k_reg[16]_i_1_n_2 ;
  wire \k_reg[16]_i_1_n_3 ;
  wire \k_reg[16]_i_1_n_4 ;
  wire \k_reg[16]_i_1_n_5 ;
  wire \k_reg[16]_i_1_n_6 ;
  wire \k_reg[16]_i_1_n_7 ;
  wire \k_reg[20]_i_1_n_0 ;
  wire \k_reg[20]_i_1_n_1 ;
  wire \k_reg[20]_i_1_n_2 ;
  wire \k_reg[20]_i_1_n_3 ;
  wire \k_reg[20]_i_1_n_4 ;
  wire \k_reg[20]_i_1_n_5 ;
  wire \k_reg[20]_i_1_n_6 ;
  wire \k_reg[20]_i_1_n_7 ;
  wire \k_reg[24]_i_1_n_0 ;
  wire \k_reg[24]_i_1_n_1 ;
  wire \k_reg[24]_i_1_n_2 ;
  wire \k_reg[24]_i_1_n_3 ;
  wire \k_reg[24]_i_1_n_4 ;
  wire \k_reg[24]_i_1_n_5 ;
  wire \k_reg[24]_i_1_n_6 ;
  wire \k_reg[24]_i_1_n_7 ;
  wire \k_reg[28]_i_1_n_1 ;
  wire \k_reg[28]_i_1_n_2 ;
  wire \k_reg[28]_i_1_n_3 ;
  wire \k_reg[28]_i_1_n_4 ;
  wire \k_reg[28]_i_1_n_5 ;
  wire \k_reg[28]_i_1_n_6 ;
  wire \k_reg[28]_i_1_n_7 ;
  wire \k_reg[4]_i_1_n_0 ;
  wire \k_reg[4]_i_1_n_1 ;
  wire \k_reg[4]_i_1_n_2 ;
  wire \k_reg[4]_i_1_n_3 ;
  wire \k_reg[4]_i_1_n_4 ;
  wire \k_reg[4]_i_1_n_5 ;
  wire \k_reg[4]_i_1_n_6 ;
  wire \k_reg[4]_i_1_n_7 ;
  wire \k_reg[8]_i_1_n_0 ;
  wire \k_reg[8]_i_1_n_1 ;
  wire \k_reg[8]_i_1_n_2 ;
  wire \k_reg[8]_i_1_n_3 ;
  wire \k_reg[8]_i_1_n_4 ;
  wire \k_reg[8]_i_1_n_5 ;
  wire \k_reg[8]_i_1_n_6 ;
  wire \k_reg[8]_i_1_n_7 ;
  wire loud0_carry__0_i_1_n_0;
  wire loud0_carry__0_i_2_n_0;
  wire loud0_carry__0_i_3_n_0;
  wire loud0_carry__0_i_4_n_0;
  wire loud0_carry__0_n_0;
  wire loud0_carry__0_n_1;
  wire loud0_carry__0_n_2;
  wire loud0_carry__0_n_3;
  wire loud0_carry__1_i_1_n_0;
  wire loud0_carry__1_i_2_n_0;
  wire loud0_carry__1_i_3_n_0;
  wire loud0_carry__1_i_4_n_0;
  wire loud0_carry__1_n_0;
  wire loud0_carry__1_n_1;
  wire loud0_carry__1_n_2;
  wire loud0_carry__1_n_3;
  wire loud0_carry__2_i_1_n_0;
  wire loud0_carry__2_i_2_n_0;
  wire loud0_carry__2_i_3_n_0;
  wire loud0_carry__2_i_4_n_0;
  wire loud0_carry__2_n_1;
  wire loud0_carry__2_n_2;
  wire loud0_carry__2_n_3;
  wire loud0_carry_i_1_n_0;
  wire loud0_carry_i_2_n_0;
  wire loud0_carry_i_3_n_0;
  wire loud0_carry_i_4_n_0;
  wire loud0_carry_i_5_n_0;
  wire loud0_carry_i_6_n_0;
  wire loud0_carry_n_0;
  wire loud0_carry_n_1;
  wire loud0_carry_n_2;
  wire loud0_carry_n_3;
  wire loud_OBUF;
  wire sel;
  wire [3:3]\NLW_k_reg[28]_i_1_CO_UNCONNECTED ;
  wire [3:0]NLW_loud0_carry_O_UNCONNECTED;
  wire [3:0]NLW_loud0_carry__0_O_UNCONNECTED;
  wire [3:0]NLW_loud0_carry__1_O_UNCONNECTED;
  wire [3:0]NLW_loud0_carry__2_O_UNCONNECTED;

  LUT1 #(
    .INIT(2'h1)) 
    \k[0]_i_5 
       (.I0(k_reg[0]),
        .O(\k[0]_i_5_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[0] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[0]_i_1_n_7 ),
        .Q(k_reg[0]),
        .R(co_reg));
  CARRY4 \k_reg[0]_i_1 
       (.CI(1'b0),
        .CO({\k_reg[0]_i_1_n_0 ,\k_reg[0]_i_1_n_1 ,\k_reg[0]_i_1_n_2 ,\k_reg[0]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b1}),
        .O({\k_reg[0]_i_1_n_4 ,\k_reg[0]_i_1_n_5 ,\k_reg[0]_i_1_n_6 ,\k_reg[0]_i_1_n_7 }),
        .S({k_reg[3:1],\k[0]_i_5_n_0 }));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[10] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[8]_i_1_n_5 ),
        .Q(k_reg[10]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[11] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[8]_i_1_n_4 ),
        .Q(k_reg[11]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[12] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[12]_i_1_n_7 ),
        .Q(k_reg[12]),
        .R(co_reg));
  CARRY4 \k_reg[12]_i_1 
       (.CI(\k_reg[8]_i_1_n_0 ),
        .CO({\k_reg[12]_i_1_n_0 ,\k_reg[12]_i_1_n_1 ,\k_reg[12]_i_1_n_2 ,\k_reg[12]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[12]_i_1_n_4 ,\k_reg[12]_i_1_n_5 ,\k_reg[12]_i_1_n_6 ,\k_reg[12]_i_1_n_7 }),
        .S(k_reg[15:12]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[13] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[12]_i_1_n_6 ),
        .Q(k_reg[13]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[14] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[12]_i_1_n_5 ),
        .Q(k_reg[14]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[15] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[12]_i_1_n_4 ),
        .Q(k_reg[15]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[16] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[16]_i_1_n_7 ),
        .Q(k_reg[16]),
        .R(co_reg));
  CARRY4 \k_reg[16]_i_1 
       (.CI(\k_reg[12]_i_1_n_0 ),
        .CO({\k_reg[16]_i_1_n_0 ,\k_reg[16]_i_1_n_1 ,\k_reg[16]_i_1_n_2 ,\k_reg[16]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[16]_i_1_n_4 ,\k_reg[16]_i_1_n_5 ,\k_reg[16]_i_1_n_6 ,\k_reg[16]_i_1_n_7 }),
        .S(k_reg[19:16]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[17] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[16]_i_1_n_6 ),
        .Q(k_reg[17]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[18] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[16]_i_1_n_5 ),
        .Q(k_reg[18]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[19] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[16]_i_1_n_4 ),
        .Q(k_reg[19]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[1] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[0]_i_1_n_6 ),
        .Q(k_reg[1]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[20] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[20]_i_1_n_7 ),
        .Q(k_reg[20]),
        .R(co_reg));
  CARRY4 \k_reg[20]_i_1 
       (.CI(\k_reg[16]_i_1_n_0 ),
        .CO({\k_reg[20]_i_1_n_0 ,\k_reg[20]_i_1_n_1 ,\k_reg[20]_i_1_n_2 ,\k_reg[20]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[20]_i_1_n_4 ,\k_reg[20]_i_1_n_5 ,\k_reg[20]_i_1_n_6 ,\k_reg[20]_i_1_n_7 }),
        .S(k_reg[23:20]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[21] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[20]_i_1_n_6 ),
        .Q(k_reg[21]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[22] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[20]_i_1_n_5 ),
        .Q(k_reg[22]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[23] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[20]_i_1_n_4 ),
        .Q(k_reg[23]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[24] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[24]_i_1_n_7 ),
        .Q(k_reg[24]),
        .R(co_reg));
  CARRY4 \k_reg[24]_i_1 
       (.CI(\k_reg[20]_i_1_n_0 ),
        .CO({\k_reg[24]_i_1_n_0 ,\k_reg[24]_i_1_n_1 ,\k_reg[24]_i_1_n_2 ,\k_reg[24]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[24]_i_1_n_4 ,\k_reg[24]_i_1_n_5 ,\k_reg[24]_i_1_n_6 ,\k_reg[24]_i_1_n_7 }),
        .S(k_reg[27:24]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[25] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[24]_i_1_n_6 ),
        .Q(k_reg[25]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[26] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[24]_i_1_n_5 ),
        .Q(k_reg[26]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[27] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[24]_i_1_n_4 ),
        .Q(k_reg[27]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[28] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[28]_i_1_n_7 ),
        .Q(k_reg[28]),
        .R(co_reg));
  CARRY4 \k_reg[28]_i_1 
       (.CI(\k_reg[24]_i_1_n_0 ),
        .CO({\NLW_k_reg[28]_i_1_CO_UNCONNECTED [3],\k_reg[28]_i_1_n_1 ,\k_reg[28]_i_1_n_2 ,\k_reg[28]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[28]_i_1_n_4 ,\k_reg[28]_i_1_n_5 ,\k_reg[28]_i_1_n_6 ,\k_reg[28]_i_1_n_7 }),
        .S(k_reg[31:28]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[29] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[28]_i_1_n_6 ),
        .Q(k_reg[29]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[2] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[0]_i_1_n_5 ),
        .Q(k_reg[2]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[30] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[28]_i_1_n_5 ),
        .Q(k_reg[30]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[31] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[28]_i_1_n_4 ),
        .Q(k_reg[31]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[3] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[0]_i_1_n_4 ),
        .Q(k_reg[3]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[4] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[4]_i_1_n_7 ),
        .Q(k_reg[4]),
        .R(co_reg));
  CARRY4 \k_reg[4]_i_1 
       (.CI(\k_reg[0]_i_1_n_0 ),
        .CO({\k_reg[4]_i_1_n_0 ,\k_reg[4]_i_1_n_1 ,\k_reg[4]_i_1_n_2 ,\k_reg[4]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[4]_i_1_n_4 ,\k_reg[4]_i_1_n_5 ,\k_reg[4]_i_1_n_6 ,\k_reg[4]_i_1_n_7 }),
        .S(k_reg[7:4]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[5] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[4]_i_1_n_6 ),
        .Q(k_reg[5]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[6] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[4]_i_1_n_5 ),
        .Q(k_reg[6]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[7] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[4]_i_1_n_4 ),
        .Q(k_reg[7]),
        .R(co_reg));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[8] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[8]_i_1_n_7 ),
        .Q(k_reg[8]),
        .R(co_reg));
  CARRY4 \k_reg[8]_i_1 
       (.CI(\k_reg[4]_i_1_n_0 ),
        .CO({\k_reg[8]_i_1_n_0 ,\k_reg[8]_i_1_n_1 ,\k_reg[8]_i_1_n_2 ,\k_reg[8]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\k_reg[8]_i_1_n_4 ,\k_reg[8]_i_1_n_5 ,\k_reg[8]_i_1_n_6 ,\k_reg[8]_i_1_n_7 }),
        .S(k_reg[11:8]));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[9] 
       (.C(clk_OBUF_BUFG),
        .CE(sel),
        .D(\k_reg[8]_i_1_n_6 ),
        .Q(k_reg[9]),
        .R(co_reg));
  CARRY4 loud0_carry
       (.CI(1'b0),
        .CO({loud0_carry_n_0,loud0_carry_n_1,loud0_carry_n_2,loud0_carry_n_3}),
        .CYINIT(1'b1),
        .DI({1'b0,1'b0,loud0_carry_i_1_n_0,loud0_carry_i_2_n_0}),
        .O(NLW_loud0_carry_O_UNCONNECTED[3:0]),
        .S({loud0_carry_i_3_n_0,loud0_carry_i_4_n_0,loud0_carry_i_5_n_0,loud0_carry_i_6_n_0}));
  CARRY4 loud0_carry__0
       (.CI(loud0_carry_n_0),
        .CO({loud0_carry__0_n_0,loud0_carry__0_n_1,loud0_carry__0_n_2,loud0_carry__0_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(NLW_loud0_carry__0_O_UNCONNECTED[3:0]),
        .S({loud0_carry__0_i_1_n_0,loud0_carry__0_i_2_n_0,loud0_carry__0_i_3_n_0,loud0_carry__0_i_4_n_0}));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__0_i_1
       (.I0(k_reg[15]),
        .I1(k_reg[14]),
        .O(loud0_carry__0_i_1_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__0_i_2
       (.I0(k_reg[13]),
        .I1(k_reg[12]),
        .O(loud0_carry__0_i_2_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__0_i_3
       (.I0(k_reg[11]),
        .I1(k_reg[10]),
        .O(loud0_carry__0_i_3_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__0_i_4
       (.I0(k_reg[9]),
        .I1(k_reg[8]),
        .O(loud0_carry__0_i_4_n_0));
  CARRY4 loud0_carry__1
       (.CI(loud0_carry__0_n_0),
        .CO({loud0_carry__1_n_0,loud0_carry__1_n_1,loud0_carry__1_n_2,loud0_carry__1_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(NLW_loud0_carry__1_O_UNCONNECTED[3:0]),
        .S({loud0_carry__1_i_1_n_0,loud0_carry__1_i_2_n_0,loud0_carry__1_i_3_n_0,loud0_carry__1_i_4_n_0}));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__1_i_1
       (.I0(k_reg[23]),
        .I1(k_reg[22]),
        .O(loud0_carry__1_i_1_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__1_i_2
       (.I0(k_reg[21]),
        .I1(k_reg[20]),
        .O(loud0_carry__1_i_2_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__1_i_3
       (.I0(k_reg[19]),
        .I1(k_reg[18]),
        .O(loud0_carry__1_i_3_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__1_i_4
       (.I0(k_reg[17]),
        .I1(k_reg[16]),
        .O(loud0_carry__1_i_4_n_0));
  CARRY4 loud0_carry__2
       (.CI(loud0_carry__1_n_0),
        .CO({sel,loud0_carry__2_n_1,loud0_carry__2_n_2,loud0_carry__2_n_3}),
        .CYINIT(1'b0),
        .DI({k_reg[31],1'b0,1'b0,1'b0}),
        .O(NLW_loud0_carry__2_O_UNCONNECTED[3:0]),
        .S({loud0_carry__2_i_1_n_0,loud0_carry__2_i_2_n_0,loud0_carry__2_i_3_n_0,loud0_carry__2_i_4_n_0}));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__2_i_1
       (.I0(k_reg[31]),
        .I1(k_reg[30]),
        .O(loud0_carry__2_i_1_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__2_i_2
       (.I0(k_reg[29]),
        .I1(k_reg[28]),
        .O(loud0_carry__2_i_2_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__2_i_3
       (.I0(k_reg[27]),
        .I1(k_reg[26]),
        .O(loud0_carry__2_i_3_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry__2_i_4
       (.I0(k_reg[25]),
        .I1(k_reg[24]),
        .O(loud0_carry__2_i_4_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry_i_1
       (.I0(k_reg[2]),
        .I1(k_reg[3]),
        .O(loud0_carry_i_1_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry_i_2
       (.I0(k_reg[0]),
        .I1(k_reg[1]),
        .O(loud0_carry_i_2_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry_i_3
       (.I0(k_reg[7]),
        .I1(k_reg[6]),
        .O(loud0_carry_i_3_n_0));
  LUT2 #(
    .INIT(4'h1)) 
    loud0_carry_i_4
       (.I0(k_reg[5]),
        .I1(k_reg[4]),
        .O(loud0_carry_i_4_n_0));
  LUT2 #(
    .INIT(4'h2)) 
    loud0_carry_i_5
       (.I0(k_reg[2]),
        .I1(k_reg[3]),
        .O(loud0_carry_i_5_n_0));
  LUT2 #(
    .INIT(4'h2)) 
    loud0_carry_i_6
       (.I0(k_reg[0]),
        .I1(k_reg[1]),
        .O(loud0_carry_i_6_n_0));
  FDRE #(
    .INIT(1'b0)) 
    loud_reg
       (.C(clk_OBUF_BUFG),
        .CE(1'b1),
        .D(sel),
        .Q(loud_OBUF),
        .R(co_reg));
endmodule

module SevenSegNumIndic
   (result_OBUF,
    Q);
  output [6:0]result_OBUF;
  input [3:0]Q;

  wire [3:0]Q;
  wire [6:0]result_OBUF;

  LUT4 #(
    .INIT(16'h0014)) 
    \result_OBUF[0]_inst_i_1 
       (.I0(Q[3]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .O(result_OBUF[6]));
  (* SOFT_HLUTNM = "soft_lutpair19" *) 
  LUT4 #(
    .INIT(16'hBE88)) 
    \result_OBUF[1]_inst_i_1 
       (.I0(Q[3]),
        .I1(Q[1]),
        .I2(Q[0]),
        .I3(Q[2]),
        .O(result_OBUF[5]));
  (* SOFT_HLUTNM = "soft_lutpair19" *) 
  LUT4 #(
    .INIT(16'hCCD0)) 
    \result_OBUF[2]_inst_i_1 
       (.I0(Q[0]),
        .I1(Q[3]),
        .I2(Q[1]),
        .I3(Q[2]),
        .O(result_OBUF[4]));
  (* SOFT_HLUTNM = "soft_lutpair18" *) 
  LUT4 #(
    .INIT(16'h201A)) 
    \result_OBUF[3]_inst_i_1 
       (.I0(Q[0]),
        .I1(Q[3]),
        .I2(Q[2]),
        .I3(Q[1]),
        .O(result_OBUF[3]));
  (* SOFT_HLUTNM = "soft_lutpair18" *) 
  LUT4 #(
    .INIT(16'h445C)) 
    \result_OBUF[4]_inst_i_1 
       (.I0(Q[3]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .O(result_OBUF[2]));
  (* SOFT_HLUTNM = "soft_lutpair17" *) 
  LUT4 #(
    .INIT(16'h00B2)) 
    \result_OBUF[5]_inst_i_1 
       (.I0(Q[0]),
        .I1(Q[2]),
        .I2(Q[1]),
        .I3(Q[3]),
        .O(result_OBUF[1]));
  (* SOFT_HLUTNM = "soft_lutpair17" *) 
  LUT4 #(
    .INIT(16'h4101)) 
    \result_OBUF[6]_inst_i_1 
       (.I0(Q[3]),
        .I1(Q[2]),
        .I2(Q[1]),
        .I3(Q[0]),
        .O(result_OBUF[0]));
endmodule

module segTime
   (clr,
    T_IBUF_BUFG);
  output clr;
  input T_IBUF_BUFG;

  wire CLK;
  wire CLK_i_1__0_n_0;
  wire T_IBUF_BUFG;
  wire clr;
  wire [0:0]k;
  wire k0_carry__0_n_0;
  wire k0_carry__0_n_1;
  wire k0_carry__0_n_2;
  wire k0_carry__0_n_3;
  wire k0_carry__0_n_4;
  wire k0_carry__0_n_5;
  wire k0_carry__0_n_6;
  wire k0_carry__0_n_7;
  wire k0_carry__1_n_0;
  wire k0_carry__1_n_1;
  wire k0_carry__1_n_2;
  wire k0_carry__1_n_3;
  wire k0_carry__1_n_4;
  wire k0_carry__1_n_5;
  wire k0_carry__1_n_6;
  wire k0_carry__1_n_7;
  wire k0_carry__2_n_0;
  wire k0_carry__2_n_1;
  wire k0_carry__2_n_2;
  wire k0_carry__2_n_3;
  wire k0_carry__2_n_4;
  wire k0_carry__2_n_5;
  wire k0_carry__2_n_6;
  wire k0_carry__2_n_7;
  wire k0_carry__3_n_0;
  wire k0_carry__3_n_1;
  wire k0_carry__3_n_2;
  wire k0_carry__3_n_3;
  wire k0_carry__3_n_4;
  wire k0_carry__3_n_5;
  wire k0_carry__3_n_6;
  wire k0_carry__3_n_7;
  wire k0_carry__4_n_0;
  wire k0_carry__4_n_1;
  wire k0_carry__4_n_2;
  wire k0_carry__4_n_3;
  wire k0_carry__4_n_4;
  wire k0_carry__4_n_5;
  wire k0_carry__4_n_6;
  wire k0_carry__4_n_7;
  wire k0_carry__5_n_0;
  wire k0_carry__5_n_1;
  wire k0_carry__5_n_2;
  wire k0_carry__5_n_3;
  wire k0_carry__5_n_4;
  wire k0_carry__5_n_5;
  wire k0_carry__5_n_6;
  wire k0_carry__5_n_7;
  wire k0_carry__6_n_2;
  wire k0_carry__6_n_3;
  wire k0_carry__6_n_5;
  wire k0_carry__6_n_6;
  wire k0_carry__6_n_7;
  wire k0_carry_n_0;
  wire k0_carry_n_1;
  wire k0_carry_n_2;
  wire k0_carry_n_3;
  wire k0_carry_n_4;
  wire k0_carry_n_5;
  wire k0_carry_n_6;
  wire k0_carry_n_7;
  wire \k[0]_i_2_n_0 ;
  wire \k[0]_i_3_n_0 ;
  wire \k[0]_i_4_n_0 ;
  wire \k[0]_i_5__1_n_0 ;
  wire \k[0]_i_6_n_0 ;
  wire \k[0]_i_7_n_0 ;
  wire \k[0]_i_8_n_0 ;
  wire \k[0]_i_9_n_0 ;
  wire \k_reg_n_0_[0] ;
  wire \k_reg_n_0_[10] ;
  wire \k_reg_n_0_[11] ;
  wire \k_reg_n_0_[12] ;
  wire \k_reg_n_0_[13] ;
  wire \k_reg_n_0_[14] ;
  wire \k_reg_n_0_[15] ;
  wire \k_reg_n_0_[16] ;
  wire \k_reg_n_0_[17] ;
  wire \k_reg_n_0_[18] ;
  wire \k_reg_n_0_[19] ;
  wire \k_reg_n_0_[1] ;
  wire \k_reg_n_0_[20] ;
  wire \k_reg_n_0_[21] ;
  wire \k_reg_n_0_[22] ;
  wire \k_reg_n_0_[23] ;
  wire \k_reg_n_0_[24] ;
  wire \k_reg_n_0_[25] ;
  wire \k_reg_n_0_[26] ;
  wire \k_reg_n_0_[27] ;
  wire \k_reg_n_0_[28] ;
  wire \k_reg_n_0_[29] ;
  wire \k_reg_n_0_[2] ;
  wire \k_reg_n_0_[30] ;
  wire \k_reg_n_0_[31] ;
  wire \k_reg_n_0_[3] ;
  wire \k_reg_n_0_[4] ;
  wire \k_reg_n_0_[5] ;
  wire \k_reg_n_0_[6] ;
  wire \k_reg_n_0_[7] ;
  wire \k_reg_n_0_[8] ;
  wire \k_reg_n_0_[9] ;
  wire [3:2]NLW_k0_carry__6_CO_UNCONNECTED;
  wire [3:3]NLW_k0_carry__6_O_UNCONNECTED;

  (* SOFT_HLUTNM = "soft_lutpair20" *) 
  LUT5 #(
    .INIT(32'hFFFE0001)) 
    CLK_i_1__0
       (.I0(\k_reg_n_0_[0] ),
        .I1(\k[0]_i_4_n_0 ),
        .I2(\k[0]_i_3_n_0 ),
        .I3(\k[0]_i_2_n_0 ),
        .I4(clr),
        .O(CLK_i_1__0_n_0));
  FDRE #(
    .INIT(1'b0)) 
    CLK_reg
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(CLK_i_1__0_n_0),
        .Q(clr),
        .R(1'b0));
  CARRY4 k0_carry
       (.CI(1'b0),
        .CO({k0_carry_n_0,k0_carry_n_1,k0_carry_n_2,k0_carry_n_3}),
        .CYINIT(\k_reg_n_0_[0] ),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({k0_carry_n_4,k0_carry_n_5,k0_carry_n_6,k0_carry_n_7}),
        .S({\k_reg_n_0_[4] ,\k_reg_n_0_[3] ,\k_reg_n_0_[2] ,\k_reg_n_0_[1] }));
  CARRY4 k0_carry__0
       (.CI(k0_carry_n_0),
        .CO({k0_carry__0_n_0,k0_carry__0_n_1,k0_carry__0_n_2,k0_carry__0_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({k0_carry__0_n_4,k0_carry__0_n_5,k0_carry__0_n_6,k0_carry__0_n_7}),
        .S({\k_reg_n_0_[8] ,\k_reg_n_0_[7] ,\k_reg_n_0_[6] ,\k_reg_n_0_[5] }));
  CARRY4 k0_carry__1
       (.CI(k0_carry__0_n_0),
        .CO({k0_carry__1_n_0,k0_carry__1_n_1,k0_carry__1_n_2,k0_carry__1_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({k0_carry__1_n_4,k0_carry__1_n_5,k0_carry__1_n_6,k0_carry__1_n_7}),
        .S({\k_reg_n_0_[12] ,\k_reg_n_0_[11] ,\k_reg_n_0_[10] ,\k_reg_n_0_[9] }));
  CARRY4 k0_carry__2
       (.CI(k0_carry__1_n_0),
        .CO({k0_carry__2_n_0,k0_carry__2_n_1,k0_carry__2_n_2,k0_carry__2_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({k0_carry__2_n_4,k0_carry__2_n_5,k0_carry__2_n_6,k0_carry__2_n_7}),
        .S({\k_reg_n_0_[16] ,\k_reg_n_0_[15] ,\k_reg_n_0_[14] ,\k_reg_n_0_[13] }));
  CARRY4 k0_carry__3
       (.CI(k0_carry__2_n_0),
        .CO({k0_carry__3_n_0,k0_carry__3_n_1,k0_carry__3_n_2,k0_carry__3_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({k0_carry__3_n_4,k0_carry__3_n_5,k0_carry__3_n_6,k0_carry__3_n_7}),
        .S({\k_reg_n_0_[20] ,\k_reg_n_0_[19] ,\k_reg_n_0_[18] ,\k_reg_n_0_[17] }));
  CARRY4 k0_carry__4
       (.CI(k0_carry__3_n_0),
        .CO({k0_carry__4_n_0,k0_carry__4_n_1,k0_carry__4_n_2,k0_carry__4_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({k0_carry__4_n_4,k0_carry__4_n_5,k0_carry__4_n_6,k0_carry__4_n_7}),
        .S({\k_reg_n_0_[24] ,\k_reg_n_0_[23] ,\k_reg_n_0_[22] ,\k_reg_n_0_[21] }));
  CARRY4 k0_carry__5
       (.CI(k0_carry__4_n_0),
        .CO({k0_carry__5_n_0,k0_carry__5_n_1,k0_carry__5_n_2,k0_carry__5_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({k0_carry__5_n_4,k0_carry__5_n_5,k0_carry__5_n_6,k0_carry__5_n_7}),
        .S({\k_reg_n_0_[28] ,\k_reg_n_0_[27] ,\k_reg_n_0_[26] ,\k_reg_n_0_[25] }));
  CARRY4 k0_carry__6
       (.CI(k0_carry__5_n_0),
        .CO({NLW_k0_carry__6_CO_UNCONNECTED[3:2],k0_carry__6_n_2,k0_carry__6_n_3}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({NLW_k0_carry__6_O_UNCONNECTED[3],k0_carry__6_n_5,k0_carry__6_n_6,k0_carry__6_n_7}),
        .S({1'b0,\k_reg_n_0_[31] ,\k_reg_n_0_[30] ,\k_reg_n_0_[29] }));
  (* SOFT_HLUTNM = "soft_lutpair20" *) 
  LUT4 #(
    .INIT(16'h00FE)) 
    \k[0]_i_1__0 
       (.I0(\k[0]_i_2_n_0 ),
        .I1(\k[0]_i_3_n_0 ),
        .I2(\k[0]_i_4_n_0 ),
        .I3(\k_reg_n_0_[0] ),
        .O(k));
  LUT6 #(
    .INIT(64'hFFFFFFFFFFFEFFFF)) 
    \k[0]_i_2 
       (.I0(\k[0]_i_5__1_n_0 ),
        .I1(\k[0]_i_6_n_0 ),
        .I2(\k_reg_n_0_[31] ),
        .I3(\k_reg_n_0_[30] ),
        .I4(\k_reg_n_0_[1] ),
        .I5(\k[0]_i_7_n_0 ),
        .O(\k[0]_i_2_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFEFF)) 
    \k[0]_i_3 
       (.I0(\k_reg_n_0_[4] ),
        .I1(\k_reg_n_0_[5] ),
        .I2(\k_reg_n_0_[2] ),
        .I3(\k_reg_n_0_[3] ),
        .I4(\k[0]_i_8_n_0 ),
        .O(\k[0]_i_3_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFFFE)) 
    \k[0]_i_4 
       (.I0(\k_reg_n_0_[12] ),
        .I1(\k_reg_n_0_[13] ),
        .I2(\k_reg_n_0_[10] ),
        .I3(\k_reg_n_0_[11] ),
        .I4(\k[0]_i_9_n_0 ),
        .O(\k[0]_i_4_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[0]_i_5__1 
       (.I0(\k_reg_n_0_[23] ),
        .I1(\k_reg_n_0_[22] ),
        .I2(\k_reg_n_0_[25] ),
        .I3(\k_reg_n_0_[24] ),
        .O(\k[0]_i_5__1_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[0]_i_6 
       (.I0(\k_reg_n_0_[19] ),
        .I1(\k_reg_n_0_[18] ),
        .I2(\k_reg_n_0_[21] ),
        .I3(\k_reg_n_0_[20] ),
        .O(\k[0]_i_6_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[0]_i_7 
       (.I0(\k_reg_n_0_[27] ),
        .I1(\k_reg_n_0_[26] ),
        .I2(\k_reg_n_0_[29] ),
        .I3(\k_reg_n_0_[28] ),
        .O(\k[0]_i_7_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[0]_i_8 
       (.I0(\k_reg_n_0_[7] ),
        .I1(\k_reg_n_0_[6] ),
        .I2(\k_reg_n_0_[9] ),
        .I3(\k_reg_n_0_[8] ),
        .O(\k[0]_i_8_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \k[0]_i_9 
       (.I0(\k_reg_n_0_[15] ),
        .I1(\k_reg_n_0_[14] ),
        .I2(\k_reg_n_0_[17] ),
        .I3(\k_reg_n_0_[16] ),
        .O(\k[0]_i_9_n_0 ));
  LUT4 #(
    .INIT(16'h0001)) 
    \k[31]_i_1__0 
       (.I0(\k_reg_n_0_[0] ),
        .I1(\k[0]_i_4_n_0 ),
        .I2(\k[0]_i_3_n_0 ),
        .I3(\k[0]_i_2_n_0 ),
        .O(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[0] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k),
        .Q(\k_reg_n_0_[0] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[10] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__1_n_6),
        .Q(\k_reg_n_0_[10] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[11] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__1_n_5),
        .Q(\k_reg_n_0_[11] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[12] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__1_n_4),
        .Q(\k_reg_n_0_[12] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[13] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__2_n_7),
        .Q(\k_reg_n_0_[13] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[14] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__2_n_6),
        .Q(\k_reg_n_0_[14] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[15] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__2_n_5),
        .Q(\k_reg_n_0_[15] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[16] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__2_n_4),
        .Q(\k_reg_n_0_[16] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[17] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__3_n_7),
        .Q(\k_reg_n_0_[17] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[18] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__3_n_6),
        .Q(\k_reg_n_0_[18] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[19] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__3_n_5),
        .Q(\k_reg_n_0_[19] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[1] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry_n_7),
        .Q(\k_reg_n_0_[1] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[20] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__3_n_4),
        .Q(\k_reg_n_0_[20] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[21] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__4_n_7),
        .Q(\k_reg_n_0_[21] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[22] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__4_n_6),
        .Q(\k_reg_n_0_[22] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[23] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__4_n_5),
        .Q(\k_reg_n_0_[23] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[24] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__4_n_4),
        .Q(\k_reg_n_0_[24] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[25] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__5_n_7),
        .Q(\k_reg_n_0_[25] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[26] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__5_n_6),
        .Q(\k_reg_n_0_[26] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[27] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__5_n_5),
        .Q(\k_reg_n_0_[27] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[28] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__5_n_4),
        .Q(\k_reg_n_0_[28] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[29] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__6_n_7),
        .Q(\k_reg_n_0_[29] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[2] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry_n_6),
        .Q(\k_reg_n_0_[2] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[30] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__6_n_6),
        .Q(\k_reg_n_0_[30] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[31] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__6_n_5),
        .Q(\k_reg_n_0_[31] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[3] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry_n_5),
        .Q(\k_reg_n_0_[3] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[4] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry_n_4),
        .Q(\k_reg_n_0_[4] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[5] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__0_n_7),
        .Q(\k_reg_n_0_[5] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[6] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__0_n_6),
        .Q(\k_reg_n_0_[6] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[7] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__0_n_5),
        .Q(\k_reg_n_0_[7] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[8] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__0_n_4),
        .Q(\k_reg_n_0_[8] ),
        .R(CLK));
  FDRE #(
    .INIT(1'b0)) 
    \k_reg[9] 
       (.C(T_IBUF_BUFG),
        .CE(1'b1),
        .D(k0_carry__1_n_7),
        .Q(\k_reg_n_0_[9] ),
        .R(CLK));
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
