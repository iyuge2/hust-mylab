`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:25:51
// Design Name: 
// Module Name: DCLK_1
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


module DCLK_1(T,CLK);
    input T;
    output reg CLK;
    integer k;
//    parameter CYC = 50000000;//1s
    parameter CYC = 5;//0.5s
    initial
    begin
        k = 0;
        CLK = 0;
    end
    always
        @(posedge T) begin
             if(k == CYC) begin
                 k = 0;
                 CLK = ~CLK; //Ê±ÖÓÐÅºÅ·­×ª
             end
             else begin
                 k = k + 1;
             end
        end
endmodule
