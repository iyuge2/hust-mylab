`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/28 14:56:24
// Design Name: 
// Module Name: Clock_loud
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


module Clock_loud(clk,CLOCKS,CLOCKM,CLOCKH,stemp,mtemp,htemp,CLOCK,ON,clock_loud);   
    input clk;
    input [0:7]stemp,mtemp,htemp;
    input CLOCK,ON;
    output reg clock_loud;
    output reg[0:7]CLOCKS,CLOCKM,CLOCKH;
    reg temp;
    initial
    begin
        temp = 0;clock_loud = 0;
        CLOCKS = 0;CLOCKM = 0;CLOCKH = 0;
    end
    always
        @(posedge clk)
    begin
        if(CLOCK)
        begin
            CLOCKS = stemp;
            CLOCKM = mtemp;
            CLOCKH = htemp;
        end
        else temp = 1;
        if(ON && (stemp >= CLOCKS) && (stemp - CLOCKS < 10) && CLOCKM == mtemp && CLOCKH == htemp) //ÅÐ¶ÏÊÇ·ñ±¨Ê±
        begin
            clock_loud = ~clock_loud; //ÐÅºÅµÆÉÁË¸10s
        end
        else clock_loud = 0;
    end
endmodule
