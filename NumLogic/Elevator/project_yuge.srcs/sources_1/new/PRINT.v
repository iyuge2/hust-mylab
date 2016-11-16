`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:31:30
// Design Name: 
// Module Name: PRINT
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

module Print(clk,CurrentStair0,CurrentStair1,CountDown0,CountDown1,select,result,reset,resetlamp);
    input clk;
    input reset,resetlamp;
    input [3:0]CurrentStair0,CurrentStair1,CountDown0,CountDown1;
    output reg[7:0]select;
    output [7:0]result;
    reg [3:0]temp;
    wire clr;
    segTime usg(clk,clr);   
    initial begin
        temp = 4'b1000;
        select = 8'b11111110;
    end
    always
        @(posedge clr) begin
             case(select)
                 8'b11111110: select = 8'b11111101;
                 8'b11111101: select = 8'b11111011;
                 8'b11111011: select = 8'b11110111;
                 8'b11110111: select = 8'b11101111;
                 8'b11101111: select = 8'b11011111;
                 8'b11011111: select = 8'b10111111;
                 8'b10111111: select = 8'b01111111;
                 8'b01111111: select = 8'b11111110;
                 default: select = select;
             endcase
          end
    always
        @(select) begin
            if(reset && !resetlamp)
            begin
                temp = 4'b1111;
            end
            else 
            begin
            case(select)
                8'b11111110: temp = CountDown0;
                8'b11111101: temp = CountDown1;
                8'b11111011: temp = 4'b1010;
                8'b11110111: temp = 4'b1010;
                8'b11101111: temp = 4'b1010;
                8'b11011111: temp = 4'b1010;
                8'b10111111: temp = CurrentStair0;
                8'b01111111: temp = CurrentStair1;
                default: temp = temp;
           endcase
           end
        end
    SevenSegNumIndic uSn(temp,result);
endmodule
