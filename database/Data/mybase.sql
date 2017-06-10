drop database IF EXISTS CarRentSys;
create database CarRentSys;
use CarRentSys;
/*建表*/
Create table User(
        Uname Varchar(20) primary key, 
        Ucode Varchar(20),
        Sex char(1),
        Age int(4),
        Cre Char(1),
        Acn float(2)
    )COMMENT='用户表';
Create table Worker(
        Wname Varchar(20), 
        Wnum Varchar(12) primary key,
        Wcode Varchar(20),
        Sex char(1),
        Age int(4),
        Tnum int(4),
        Ctime DATETIME,
        Ide Char(1),
        Bsal float(2)
    )COMMENT='员工信息表';
Create table WorkerSal(
        Wnum Varchar(12),
        Prize float(2),
        Gtime DATETIME,
        foreign key (Wnum) references Worker(Wnum)
    )COMMENT='员工奖金表';
Create table CarInfo(
        Cnum Varchar(12) primary key,
        Brand Varchar(12),
        Color Varchar(12),
        Sta char(1),
        Fee float(2),
        Btime DATETIME,
        Cash float(2),
        Ree float(2),
        Vip Char(1)
    )COMMENT='车辆信息表';
Create table RentInfo(
        Tnum Varchar(12) primary key,
        Wnum Varchar(12),
        Uname Varchar(20),
        Cnum Varchar(12),
        Stm DATETIME,
        Ftm DATETIME,
        Cash float(2),
        Fine float(2),
        Csta char(1),
        foreign key (Wnum) references Worker(Wnum),
        foreign key (Uname) references User(Uname),
        foreign key (Cnum) references CarInfo(Cnum)
    )COMMENT='租借信息表';
insert into Worker values('iyuge2','W201414775','960606','M',24,0,'2000-10-1 08:30:00',1,0);
insert into Worker values('sys1','W000000000','W000000000','M',24,0,'2000-10-1 08:30:00',1,0);
insert into Worker values('sys2','W000000001','W000000001','M',24,0,'2000-10-1 08:30:00',1,0);
insert into User values('U000000','U000000','M',0,'A',0);
