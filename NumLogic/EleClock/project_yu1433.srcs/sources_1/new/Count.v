`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:34:28
// Design Name: 
// Module Name: Count
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


module Count
    #(parameter COUNTNUM = 59)
    (stop,clear,clk,clk_change,Add,Sub,res,co);
    input stop,clear;
    input clk,clk_change;
    input Add,Sub;
    output reg[0:7]res;
    output reg co;
    wire clk_temp; 
    assign clk_temp = (clear || (stop && (Add || Sub))) ? clk_change : clk; //按照优先级排序将异步信号同步化处理
    initial begin
        res = 0;
        co = 0;
    end
    always
        @(posedge clk_temp) begin
            if(clear) begin
              res = 0; 
              co = 0; 
            end
            else if(!stop)begin
                if(res >= COUNTNUM) begin
                     co = 1;
                     res = 0;
                end
                else begin
                    co = 0;
                    res = res + 1;
                end
            end
            else if(stop) begin
                if(Add) begin
                    if(res >= COUNTNUM) begin
                        co = 1;
                        res = 0;
                    end
                    else begin
                        co = 0;
                        res = res + 1;
                    end
                end
                else if(Sub) begin
                    if(res == 0) begin
                        res = COUNTNUM;
                    end
                    else begin
                        res = res - 1;
                    end
                end
            end
        end
endmodule
