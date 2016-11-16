`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:32:59
// Design Name: 
// Module Name: segTime
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


module segTime(T,CLK);
    input T;
    output reg CLK;
    integer k=0;
    localparam CYC = 100000;//0.01s
  //  localparam CYC = 10;//0.01s
    initial
        CLK = 0;
    always
        @(posedge T) begin
             if(k == CYC) begin
                 k = 0;
                 CLK = ~CLK;
             end
             else begin
                 k = k + 1;
             end
        end
endmodule

