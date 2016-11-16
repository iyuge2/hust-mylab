`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:26:49
// Design Name: 
// Module Name: DCLK_05
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


module DCLK_05(T,CLK);
    input T;
    output reg CLK;
    integer k;
    parameter CYC = 25000000;//0.5s
 //   parameter CYC = 5;//0.5s
    initial begin
        k = 0;
        CLK = 0;
        end    
    always
        @(posedge T) begin
             if(k != CYC) begin
                 k = k + 1;
             end
             else begin
                 k = 0;
                 CLK = ~CLK;
             end
        end
endmodule
