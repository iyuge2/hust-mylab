`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:24:49
// Design Name: 
// Module Name: Main
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


//module Main(T,clear,OFF,stop,loud,loud_day,
//            sup,sdown,mup,mdown,hup,hdown,select,result,CLOCK,ON,loud_clock);
module Main(T,clear,stop,loud,sup,sdown,mup,mdown,hup,stemp,mtemp,htemp,hdown);
    input T;      //100MHz的系统时钟
    input clear;    //清零和关闭时钟
    input stop;     //暂停时钟
//    input CLOCK,ON; //CLOCK用于设置闹钟，ON用于开启闹钟
    input sup,sdown;
    input mup,mdown;
    input hup,hdown;
//    output loud_clock;   //闹钟报时
    output loud;
    wire loud_day;    //loud---整点报时  loud_day---整天报时
//    output [0:7]select;
//    output [0:7]result; //保存需要输出到显示管上结果
    wire [0:3]s0,s1; //秒
    wire [0:3]m0,m1; //分
    wire [0:3]h0,h1; //时
//    wire [0:7]CLOCKS,CLOCKM,CLOCKH; //暂存闹钟的时、分、秒
    output [0:7]stemp,mtemp,htemp;
    wire clk_change,cls,clm,clh; //1Hz、2Hz、秒进位、分进位、时进位
    assign stemp = {s0,s1};
    assign mtemp = {m0,m1};
    assign htemp = {h0,h1};
    //调用分频模块分出1Hz和2Hz的时钟频率
//    DCLK_1 L6(T,clk); //T,CLK----1s
//    DCLK_05 L5(T,clk_change);//----0.5s
    //调用模24和模60模块进行计数
    CLOCK_S L7(T,T,sup,sdown,clear,stop,s0,s1,cls);//clk,clk_change,up,down,clear,stop,v_6,v_10,co_s
    CLOCK_M L8(cls,T,mup,mdown,clear,stop,m0,m1,clm);
    CLOCK_H L9(clm,T,hup,hdown,clear,stop,h0,h1,clh);
    //调用整点报时模块
    RING L10(T,stemp,mtemp,htemp,loud,loud_day);
    //调用显示模块
//    Print uPt(T,s0,s1,m0,m1,h0,h1,select,result,OFF);
    //调用闹钟模块
//    Clock_loud uCd(clk,CLOCKS,CLOCKM,CLOCKH,stemp,mtemp,htemp,CLOCK,ON,loud_clock);
endmodule
