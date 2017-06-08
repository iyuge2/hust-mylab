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
        Acn float(2),
        Ide char(1)
    )COMMENT='用户表';
Create table Worker(
        Wname Varchar(20), 
        Wnum Varchar(12) primary key,
        Wcode Varchar(20),
        Sex char(1),
        Age int(4),
        Tnum int(4),
        Ctime DATETIME,
        Ftime DATETIME,
        Ide Char(1)
    )COMMENT='员工信息表';
Create table WorkerSal(
        Wnum Varchar(12) primary key,
        Bsal float(2),
        Pride float(2),
        Sal float(2),
        foreign key (Wnum) references Worker(Wnum)
    )COMMENT='员工工资表';
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
