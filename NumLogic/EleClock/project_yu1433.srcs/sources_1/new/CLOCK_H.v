`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:29:19
// Design Name: 
// Module Name: CLOCK_H
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


module CLOCK_H(clk,clk_change,up,down,clear,stop,v_6,v_10,co_s);
    parameter COUNT = 23;
    input clk,clk_change,clear,stop;
    input up,down;
    output [0:3]v_10;
    output [0:3]v_6;
    output co_s; //进位
    wire [0:7]temp;
    Count #(COUNT) uCt_s(stop,clear,clk,clk_change,up,down,temp,co_s); //stop,clear,clk,clk_change,Add,Sub,res,co,CLOCK,REM
    assign v_6 = temp / 10;
    assign v_10 = temp % 10;
endmodule