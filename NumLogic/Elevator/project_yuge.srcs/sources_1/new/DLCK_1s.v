`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/25 21:17:11
// Design Name: 
// Module Name: DLCK_1s
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


module DLCK_1s #(parameter M = 5000000)
        (clk,clk_1s,run,reset,resetlamp);
    input clk,reset,resetlamp;//输入100MHz的时频，关电�??
    output reg clk_1s,run;//输出的时�????
    integer k;//计数变量
    initial
    begin
        clk_1s = 0;
        run = 0;
        k = 0;
    end
    always
        @(posedge clk)
    begin
        if(reset && !resetlamp)
        begin
            run = 0;
            clk_1s = 0;
        end
        else if(k == M) 
        begin
            run = 1;
            clk_1s = ~clk_1s;
            k = 0;
        end
        else 
        begin
            k = k + 1;
        end
    end
endmodule
