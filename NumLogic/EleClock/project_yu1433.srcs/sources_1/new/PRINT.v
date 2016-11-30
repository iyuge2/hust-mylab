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

module Print(clk,s0,s1,m0,m1,h0,h1,select,result,OFF);
    input clk,OFF;
    input [0:3]s0,s1;  //绉掗挓
    input [0:3]m0,m1;  //鍒嗛挓
    input [0:3]h0,h1;  //鏃堕挓
    output reg[0:7]select;
    output [0:7]result;
    reg [0:3]temp;
    wire clr;
    segTime usg(clk,clr);   
    initial begin
        temp = s1;
        select = 8'b11111110; //初始化为右边第一个灯亮
    end
//    always
//        @(posedge clr) begin
//            case(select)
//                8'b11111110:begin temp = s1;select = 8'b11111101; end
//                8'b11111101:begin temp = s0;select = 8'b11111011; end
//                8'b11111011:begin temp = m1;select = 8'b11110111; end
//                8'b11110111:begin temp = m0;select = 8'b11101111; end
//                8'b11101111:begin temp = h1;select = 8'b11011111; end
//                8'b11011111:begin temp = h0;select = 8'b11111110; end
//           endcase
//        end
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
            endcase
          end
    always
        @(select) begin
            if(OFF)
            begin
               temp = 4'b1111; //灯灭
            end
            else
            begin
                case(select)
                    8'b11111110: temp = s1;
                    8'b11111101: temp = s0;
                    8'b11111011: temp = 4'b1010; //用于输出一条中间线
                    8'b11110111: temp = m1;
                    8'b11101111: temp = m0;
                    8'b11011111: temp = 4'b1010;
                    8'b10111111: temp = h1;
                    8'b01111111: temp = h0;
               endcase
           end
        end
    SevenSegNumIndic uSn(temp,result);
endmodule
