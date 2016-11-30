`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:33:53
// Design Name: 
// Module Name: SevenSeg
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


module SevenSegNumIndic(A,P);
    input [0:3]A;
    output reg [0:7]P;
    initial
        P = 0;
    always
        @(A) begin
            case(A)  //è¾“å‡º0ï½?9
                4'b0000 : P = 8'b00000010;
                4'b0001 : P = 8'b10011110;
                4'b0010 : P = 8'b00100100;
                4'b0011 : P = 8'b00001100;
                4'b0100 : P = 8'b10011000;
                4'b0101 : P = 8'b01001000;
                4'b0110 : P = 8'b01000000;
                4'b0111 : P = 8'b00011110;
                4'b1000 : P = 8'b00000000;
                4'b1001 : P = 8'b00011000;
                4'b1010 : P = 8'b11111101;
                default : P = 8'b11111111; //µÆÃð
            endcase
        end
endmodule
