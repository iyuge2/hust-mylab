`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/27 13:17:30
// Design Name: 
// Module Name: Main_tb
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


module Main_tb();
    reg UpButton1,UpButton3,UpButton5,UpButton7;
    reg DownButton2,DownButton4,DownButton6,DownButton8;
    reg StairButton1,StairButton3,StairButton5,StairButton8;
    reg OpenButton,CloseButton;//�???门按钮，关门按钮
    reg Reset,T;//复位，时�???(100MHz)
    wire ResetLamp;
    wire OpenLamp,CloseLamp; //�???门指示灯，关门指示灯
    wire UpLamp,DownLamp,RunLamp;//上升指示灯，下降指示灯，运行指示�???
    wire StairLamp1,StairLamp3,StairLamp5,StairLamp8;
    wire [7:0]select,result;
//    wire clk;
//    wire [0:3]CurrentStair,CountDown;
//    reg [7:0]UpButton_b;//外部上楼按钮�???1-7楼）
//        reg [7:0]DownButton_b;//外部下楼按钮�???2-8）楼
//        reg [8:1]StairButton_b;//内部楼层按钮
     Main uMn(OpenButton,CloseButton,
            UpButton1,UpButton3,UpButton5,UpButton7,
            DownButton2,DownButton4,DownButton6,DownButton8,
            StairButton1,StairButton3,StairButton5,StairButton8,
            StairLamp1,StairLamp3,StairLamp5,StairLamp8,
            Reset,T,OpenLamp,CloseLamp,UpLamp,DownLamp,RunLamp,
            ResetLamp,select,result);
    initial
        begin
            UpButton1 = 0;UpButton3 = 0;UpButton5 = 0;UpButton7 = 0;
            DownButton2 = 0;DownButton4=0;DownButton6=0;DownButton8=0;
            StairButton1=0;StairButton3=0;StairButton5=0;StairButton8=0;
            OpenButton=0;CloseButton=0;
            Reset = 1;T = 0;
            #40 Reset = 0;
            #1000 UpButton3 = 1;UpButton5 = 1;UpButton7 = 1;DownButton2 = 1;DownButton4=1;DownButton6=1;DownButton8=0;
            #60 StairButton1=1;StairButton3=1;StairButton5=1;StairButton8=1;
            #500 StairButton1=0;StairButton3=0;StairButton5=0;StairButton8=0;
            #6000 Reset = 1;
        end
     always
        #5 T = ~T;
endmodule
