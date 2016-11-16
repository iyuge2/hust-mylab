`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:30:20
// Design Name: 
// Module Name: RING
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


module RING(clk,stemp,mtemp,htemp,loud,loud_day);
    input clk;
    input [0:7]stemp,mtemp,htemp;
    output reg loud,loud_day;
    initial
    begin
        loud = 0;
    end
    always
        @(posedge clk) begin
            if(mtemp == 0 && stemp < 5) begin
                    loud = 1;
            end
            else begin
                    loud = 0;
             end
        end
     always
         @(posedge clk) begin
             if(htemp == 0 && mtemp ==0 && stemp < 10) begin
                     loud_day = 1;
             end
             else begin
                     loud_day = 0;
             end
        end
endmodule
