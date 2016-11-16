`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/27 13:20:42
// Design Name: 
// Module Name: BitsToNum
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


module BitsToNum #(parameter M = 0)(clk,bits,Num);
   input clk;
   input [8:1]bits;
   output reg [3:0]Num;
   reg [3:0]k;
   reg temp;
   initial
   begin
       Num = 0;
       k = 0;
       temp = 0;
   end
   always
       @(bits)
   begin
       if(M == 0) begin
           for(k = 8;(!bits[k] && k != 1);k = k - 1)
               temp = 1;
       end
       else begin
           for(k = 1;(!bits[k] && k != 8);k = k + 1)
               temp = 1;
       end
       if(bits[k])
           Num = k;
       else
           Num = 0;
      k = 0;
      temp = 0;
   end
endmodule

