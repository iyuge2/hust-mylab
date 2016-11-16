`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:38:36
// Design Name: 
// Module Name: Main_tb
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


module Main_tb();
//    reg T;      //输入100MHz的时钟脉�??
//    reg clear;    //清零信号
//    reg stop;     //�??/停控制信�??
//    reg sup,sdown;
//    reg mup,mdown;
//    reg hup,hdown;
//    wire loud;    //响铃
//    wire [0:7]stemp,mtemp,htemp;
//    Main uMn(T,clear,stop,loud,sup,sdown,mup,mdown,hup,stemp,mtemp,htemp,hdown);
//    initial
//    begin
//        stop = 0;clear = 0;
//        sup = 0;sdown = 0;
//        mup = 0;mdown = 0;
//        hup = 0;hdown = 0;
//        T = 0;
//        #100 stop = 1;
//        #20 sup = 1;hup = 1;mup = 1;
//        #20 sup = 0;hup = 0;mup = 0;sdown = 1;mdown = 1;hdown = 1;
//        #20 clear = 1;
//        #40 clear = 0;
//        #20 sdown = 0;mdown = 0;hdown = 0;mup = 1;
//        #590 stop = 0;mup = 0;
//    end
//    always
//        #5 T = ~T;
    reg T;
    wire CLK;
    DCLK_1 uDk(T,CLK);
    initial 
        T = 0;
    always
        #5 T = ~T;
endmodule
