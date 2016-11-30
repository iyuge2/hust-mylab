`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/27 13:16:31
// Design Name: 
// Module Name: ChangeState
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

module ChangeState(UpButton_b,DownButton_b,StairButton_b,
                    OpenButton,CloseButton,clk,OpenLamp,
                    CloseLamp,UpLamp,DownLamp,CurrentStair,
                    CountDown,StairLamp,reset,resetLamp);
    input [7:0]UpButton_b,DownButton_b;//外部上升和下降按键位
    input [7:0]StairButton_b;//内部楼层�???
    input OpenButton,CloseButton;//�???门和关门按钮
    input clk;//时钟输入
    input reset;
    output resetLamp;
    output reg OpenLamp,CloseLamp;//�???门与关门指示�???
    output reg UpLamp,DownLamp;//上升指示灯，下降指示灯，运行指示�???
    output reg[7:0]StairLamp;
    output [3:0]CurrentStair;//当前楼层(数�??)
    output reg[3:0]CountDown;//倒计�???
    wire [3:0]UpButtonMax,UpButtonMin,DownButtonMax,DownButtonMin;//外部上升和下�???(数�??)
//    wire [3:0]UpMaxT,DnMinT;
    wire [3:0]StairButton_Min;//内部楼层�???小�??(数�??)
    wire [3:0]StairButton_Max;//内部楼层�???大�??(数�??)
    reg [7:0]CurrentStair_b;//当前楼层，用移位来进行当前楼层的增加和减�???
    reg runstate;//0代表上行�???1代表下行
    reg [3:0]state;
    reg [3:0]UpMax,Uptemp1,Uptemp2;
    reg [3:0]DownMax,Downtemp1,Downtemp2;
    reg unuse;
    integer i;
    parameter M0 = 0,M1 = 1;
    parameter INIT = 3'b0000,OPEND = 3'b0001,CLOSED = 3'b0010,
                UPS = 3'b0011,DOWNS = 3'b0100; //状�?�参数常量的定义
    parameter STOPTIME = 4;
//调用�???->数�?�转换模�???
    BitsToNum #(M0) uB0(clk,UpButton_b,UpButtonMax);
    BitsToNum #(M1) uB1(clk,UpButton_b,UpButtonMin);
    BitsToNum #(M0) uB2(clk,DownButton_b,DownButtonMax);
    BitsToNum #(M1) uB3(clk,DownButton_b,DownButtonMin);
    BitsToNum #(M1) uB4(clk,CurrentStair_b,CurrentStair);
    BitsToNum #(M0) uB5(clk,StairLamp,StairButton_Max);
    BitsToNum #(M1) uB6(clk,StairLamp,StairButton_Min);
//状�?�转�???
    assign resetLamp = (CurrentStair == 1 && CloseLamp) ? 0 : reset;
//    assign DnMinT = (UpButtonMin > DownButtonMin) ? DownButtonMin : UpButtonMin;
//    assign UpMaxT = (UpButtonMax > DownButtonMax) ? UpButtonMax : DownButtonMax;
    initial
    begin
        UpMax = 0;Uptemp1 = 0;Uptemp2 = 0;
        DownMax = 0;Downtemp1 = 0;Downtemp2 = 0;
        runstate = 0;
        unuse = 0;
        state = INIT;
        CurrentStair_b = 8'b00000001;
        StairLamp = 0;
        OpenLamp = 0;
        CloseLamp = 0;
        UpLamp = 0;
        DownLamp = 0;
        CountDown = 10;
    end
    always //求楼层间�????
        @(posedge clk)
    begin
        if(UpButtonMax > CurrentStair)
            Uptemp1 = UpButtonMax - CurrentStair;
        else
            Uptemp1 = 0;
        if(DownButtonMax > CurrentStair)
            Uptemp2 = DownButtonMax - CurrentStair;
        else
            Uptemp2 = 0;
        if(Uptemp1 > Uptemp2)
            UpMax = Uptemp1;
        else
            UpMax = Uptemp2;
        if(UpButtonMin && CurrentStair > UpButtonMin)
            Downtemp1 = CurrentStair - UpButtonMin;
        else
            Downtemp1 = 0;
        if(DownButtonMin && CurrentStair > DownButtonMin)
            Downtemp2 = CurrentStair - DownButtonMin;
        else
            Downtemp2 = 0;
        if(Downtemp1 > Downtemp2)
            DownMax = Downtemp1;
        else
            DownMax = Downtemp2;
    end
    always  //楼层内部灯控制块
        @(posedge clk)
        begin
            if(reset)
            begin
                if(CurrentStair > 1)
                begin
                    StairLamp[CurrentStair-2] = 1;
                end
                else if(CurrentStair == 1 )
                begin
                    StairLamp = 0;
                end
            end
            else 
            begin
                for(i = 0;i <= 7;i = i + 1)
                begin
                    if(StairButton_b[i])
                        StairLamp[i] = StairButton_b[i];
                    else unuse = 0;
                end 
            end
            if(CurrentStair_b & StairLamp)
            begin
                StairLamp[CurrentStair-1] = 0;
            end
            else unuse = 1;
        end
    always
        @(posedge clk)
            begin
                if(reset && !resetLamp)
                begin
                    UpLamp = 0;DownLamp = 0;state = INIT;
                    OpenLamp = 0; CloseLamp = 0;
                end
                else begin
                case(state)
                    INIT: begin
                        if(UpButton_b & CurrentStair_b || OpenButton)
                        begin
                            runstate = 0;
                            CountDown = 5;
                            OpenLamp = 1;
                            state = OPEND;
                        end
                        else if(DownButton_b & CurrentStair_b)
                        begin
                            runstate = 1;
                            CountDown = 5;
                            OpenLamp = 1;
                            state = OPEND;
                        end
                        else if(UpMax > DownMax || StairButton_Max > CurrentStair)
//                        else if(UpMax > DownMax)
                        begin
                            runstate = 0;
                            CountDown = 10;
                            UpLamp = 1;
                            state = UPS;
                        end
                        else if((DownMax && DownMax >= UpMax) ||(StairButton_Min && StairButton_Min < CurrentStair))
//                        else if(DownMax && DownMax >= UpMax)
                        begin
                            runstate = 1;
                            CountDown = 10;
                            DownLamp = 1;
                            state = DOWNS;
                        end
                        else state = INIT;
                    end
                    OPEND: begin
                        if(!OpenButton)
                        begin
                            if(CountDown == 1)
                            begin
                                OpenLamp = 0;
                                CloseLamp = 1;
                                state = CLOSED;
                            end
                            else
                            begin
                                CountDown = CountDown - 1;
                                state = OPEND;
                            end
                        end
                        else
                        begin
                            CountDown = 5;
                            OpenLamp = 1;
                            state = OPEND;
                        end
                    end
                    CLOSED: begin
                        if((runstate==0) && (UpButtonMax > CurrentStair || StairButton_Max > CurrentStair))
                        begin
                            CloseLamp = 0;
                            UpLamp = 1;
                            CountDown = 10;
                            state = UPS;
                        end
                        else if(runstate && ((DownButtonMin && DownButtonMin < CurrentStair) || (StairButton_Min && StairButton_Min < CurrentStair)))
                        begin
                            CloseLamp = 0;
                            DownLamp = 1;
                            CountDown = 10;
                            state = DOWNS;
                        end
        //                else if(!UpLamp && !DownLamp && (CurrentStair_b & StairLamp))
        //                begin
        //                    StairLamp[CurrentStair] = 0;
        //                    CloseLamp = 0;
        //                    OpenLamp = 1;
        //                    state = OPEND;
        //                end
//                        else if(!StairLamp)//没有考虑按本层楼的内部开�????
                        else
                        begin
                            CloseLamp = 0;
                            state = INIT;
                        end
//                        else
//                        begin
//                            CloseLamp = 1;
//                            state = CLOSED;
//                        end
                    end
                    UPS:begin
                        if(CountDown == 1)
                        begin
                            CurrentStair_b = CurrentStair_b * 2;
                            CountDown = 10;
                            if((CurrentStair_b == 8'b10000000) || (!StairLamp && !DownButton_b && !UpButton_b))
                            begin
                                UpLamp = 0;
                                OpenLamp = 1;
                                CountDown = 5;
                                state = OPEND;
                            end
                            else if(StairLamp & CurrentStair_b || UpButton_b & CurrentStair_b ||
//                                    (!StairLamp && UpMaxT && CurrentStair == UpMaxT))
                                    (!StairLamp && (DownButtonMax >  UpButtonMax) && (DownButtonMax == (CurrentStair + 1))))
                            begin
                                OpenLamp = 1;
                                UpLamp = 0;
                                CountDown = 5;
                                state = OPEND;
                            end
                            else if(StairButton_Max > CurrentStair || UpButtonMax > CurrentStair
                                    || DownButtonMax > CurrentStair)
                            begin
                                    runstate = 0;
                            end
                            else 
                            begin
                                runstate = 1;
                                UpLamp = 0;
                                state = INIT;
                            end
                        end
                        else begin
                            CountDown = CountDown - 1;
                        end
                    end
                    DOWNS:begin
                        if(CountDown == 1)
                        begin
                            CurrentStair_b = CurrentStair_b / 2;
                            CountDown = 10;
                            if((CurrentStair_b == 1) || (!StairLamp && !DownButton_b && !UpButton_b))
                            begin
                                DownLamp = 0;
                                OpenLamp = 1;
                                CountDown = 5;
                                state = OPEND;
                            end
                            else if(StairLamp & CurrentStair_b || DownButton_b & CurrentStair_b || 
//                                    (!StairLamp && DnMinT && CurrentStair == DnMinT))
                                       (!StairLamp && (UpButtonMin <  DownButtonMin) && (UpButtonMin == (CurrentStair - 1))))
                            begin
                                OpenLamp = 1;
                                DownLamp = 0;
                                CountDown = 5;
                                state = OPEND;
                            end
                            else if((StairButton_Min && StairButton_Min < CurrentStair) || 
                                    (UpButtonMin && UpButtonMin < CurrentStair) ||
                                    (DownButtonMin && DownButtonMin < CurrentStair))
                            begin
                                    runstate = 1;
                            end
                            else 
                            begin
                                runstate = 0;
                                DownLamp = 0;
                                state = INIT;
                            end
                        end
                        else begin
                            CountDown = CountDown - 1;
                        end
                    end
                    default: unuse = 0;
                endcase
                end
            end
endmodule

