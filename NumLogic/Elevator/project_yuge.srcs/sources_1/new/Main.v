`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/27 13:24:32
// Design Name: 
// Module Name: Main
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

module Main(OpenButton,CloseButton,
            UpButton1,UpButton3,UpButton5,UpButton7,
            DownButton2,DownButton4,DownButton6,DownButton8,
            StairButton1,StairButton3,StairButton5,StairButton8,
            StairLamp1,StairLamp3,StairLamp5,StairLamp8,
            Reset,T,OpenLamp,CloseLamp,UpLamp,DownLamp,RunLamp,
            ResetLamp,select,result);
    input UpButton1,UpButton3,UpButton5,UpButton7;
    input DownButton2,DownButton4,DownButton6,DownButton8;
    input StairButton1,StairButton3,StairButton5,StairButton8;  
    input OpenButton,CloseButton;//�????门按钮，关门按钮
    input T,Reset;//复位，时�????(100MHz)
    output OpenLamp,CloseLamp,ResetLamp; //�????门指示灯，关门指示灯
    output UpLamp,DownLamp,RunLamp;//上升指示灯，下降指示灯，运行指示�????
    output StairLamp1,StairLamp3,StairLamp5,StairLamp8;
    output [7:0]select,result;
    wire [7:0]StairLamp;
    wire [3:0]CurrentStair,CountDown;//当前楼层，�?�计�????
    wire [7:0]UpButton_b;//外部上楼按钮�????1-7楼）
    wire [7:0]DownButton_b;//外部下楼按钮�????2-8）楼
    wire [7:0]StairButton_b;//内部楼层按钮
    assign StairLamp1 = StairLamp[0];
    assign StairLamp3 = StairLamp[2];
    assign StairLamp5 = StairLamp[4];
    assign StairLamp8 = StairLamp[7];
    assign UpButton_b = {1'b0,UpButton7,1'b0,UpButton5,1'b0,UpButton3,1'b0,UpButton1};
    assign DownButton_b = {DownButton8,1'b0,DownButton6,1'b0,DownButton4,1'b0,DownButton2,1'b0};
    assign StairButton_b = {StairButton8,1'b0,1'b0,StairButton5,1'b0,StairButton3,1'b0,StairButton1};
//输入输出定义结束
    wire clk_1s; //秒频
    wire [3:0]CountDown0,CountDown1;
    wire [3:0]CurrentStair0,CurrentStair1;
    assign CountDown0 = CountDown / 10;
    assign CountDown1 = CountDown % 10;
    assign CurrentStair0 = CurrentStair / 10;
    assign CurrentStair1 = CurrentStair % 10;
//常量的定�????
    parameter Time = 50000000;//设置时间分频的频率，此�?�代表分出的为秒�????
//模块调用
    DLCK_1s #(Time) uDk(T,clk_1s,RunLamp,Reset,ResetLamp);//调用分频模块
//ChangeState(UpButton_b,DownButton_b,StairButton_b,
//                        OpenButton,CloseButton,clk,OpenLamp,
//                        CloseLamp,UpLamp,DownLamp,CurrentStair,
//                        CountDown,StairLamp);
    ChangeState uCe(UpButton_b,DownButton_b,StairButton_b,OpenButton,
                    CloseButton,clk_1s,OpenLamp,CloseLamp,UpLamp,
                    DownLamp,CurrentStair,CountDown,StairLamp,Reset,ResetLamp);
    Print uPt(T,CurrentStair0,CurrentStair1,CountDown0,CountDown1,select,result,Reset,ResetLamp);
endmodule
