`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/24 10:24:49
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


//module Main(T,clear,OFF,stop,loud,loud_day,
//            sup,sdown,mup,mdown,hup,hdown,select,result,CLOCK,ON,loud_clock);
module Main(T,clear,stop,loud,sup,sdown,mup,mdown,hup,stemp,mtemp,htemp,hdown);
    input T;      //100MHz��ϵͳʱ��
    input clear;    //����͹ر�ʱ��
    input stop;     //��ͣʱ��
//    input CLOCK,ON; //CLOCK�����������ӣ�ON���ڿ�������
    input sup,sdown;
    input mup,mdown;
    input hup,hdown;
//    output loud_clock;   //���ӱ�ʱ
    output loud;
    wire loud_day;    //loud---���㱨ʱ  loud_day---���챨ʱ
//    output [0:7]select;
//    output [0:7]result; //������Ҫ�������ʾ���Ͻ��
    wire [0:3]s0,s1; //��
    wire [0:3]m0,m1; //��
    wire [0:3]h0,h1; //ʱ
//    wire [0:7]CLOCKS,CLOCKM,CLOCKH; //�ݴ����ӵ�ʱ���֡���
    output [0:7]stemp,mtemp,htemp;
    wire clk_change,cls,clm,clh; //1Hz��2Hz�����λ���ֽ�λ��ʱ��λ
    assign stemp = {s0,s1};
    assign mtemp = {m0,m1};
    assign htemp = {h0,h1};
    //���÷�Ƶģ��ֳ�1Hz��2Hz��ʱ��Ƶ��
//    DCLK_1 L6(T,clk); //T,CLK----1s
//    DCLK_05 L5(T,clk_change);//----0.5s
    //����ģ24��ģ60ģ����м���
    CLOCK_S L7(T,T,sup,sdown,clear,stop,s0,s1,cls);//clk,clk_change,up,down,clear,stop,v_6,v_10,co_s
    CLOCK_M L8(cls,T,mup,mdown,clear,stop,m0,m1,clm);
    CLOCK_H L9(clm,T,hup,hdown,clear,stop,h0,h1,clh);
    //�������㱨ʱģ��
    RING L10(T,stemp,mtemp,htemp,loud,loud_day);
    //������ʾģ��
//    Print uPt(T,s0,s1,m0,m1,h0,h1,select,result,OFF);
    //��������ģ��
//    Clock_loud uCd(clk,CLOCKS,CLOCKM,CLOCKH,stemp,mtemp,htemp,CLOCK,ON,loud_clock);
endmodule
