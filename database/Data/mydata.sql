use CarRentSys;
/*插入用户信息*/
insert into User values('user0','123456','M',20,'A',100);
insert into User values('user1','123456','M',20,'D',1000);
insert into User values('user2','123456','M',20,'B',50);
insert into User values('user3','123456','M',20,'C',300);

/*插入员工信息*/
insert into Worker values('worker1','W201714700','123456','M',20,0,'2017-1-1 08:00:00',0,1000);
insert into Worker values('worker2','W201714701','123456','M',20,0,'2017-1-1 08:00:00',0,1000);
insert into Worker values('worker3','W201714702','123456','M',20,0,'2017-1-1 08:00:00',0,1000);
insert into Worker values('worker4','W201714703','123456','M',20,0,'2017-1-1 08:00:00',0,1000);
insert into Worker values('worker5','W201714704','123456','M',20,0,'2017-1-1 08:00:00',0,1000);
insert into Worker values('worker6','W201714705','123456','M',20,0,'2017-1-1 08:00:00',0,1000);

/*插入员工奖金信息*/
insert into WorkerSal values('W201714701','100','2017-1-2 08:00:00');
insert into WorkerSal values('W201714705','100','2017-1-2 08:00:00');
insert into WorkerSal values('W201714702','100','2017-1-2 08:00:00');
insert into WorkerSal values('W201714704','100','2017-1-2 08:00:00');
insert into WorkerSal values('W201714700','100','2017-2-1 08:00:00');
insert into WorkerSal values('W201714701','100','2017-2-1 08:00:00');
insert into WorkerSal values('W201714702','200','2017-2-1 08:00:00');
insert into WorkerSal values('W201714703','100','2017-2-1 08:00:00');
insert into WorkerSal values('W201714704','400','2017-2-1 08:00:00');
insert into WorkerSal values('W201714702','100','2017-3-1 08:00:00');
insert into WorkerSal values('W201714704','100','2017-3-1 08:00:00');
insert into WorkerSal values('W201714702','800','2017-4-1 08:00:00');
insert into WorkerSal values('W201714703','100','2017-4-1 08:00:00');
insert into WorkerSal values('W201714705','700','2017-4-1 08:00:00');
insert into WorkerSal values('W201714701','100','2017-5-1 08:00:00');
insert into WorkerSal values('W201714705','200','2017-5-1 08:00:00');
insert into WorkerSal values('W201714701','100','2017-6-1 08:00:00');
insert into WorkerSal values('W201714705','100','2017-6-1 08:00:00');
insert into WorkerSal values('W201714702','1000','2017-6-1 08:00:00');
insert into WorkerSal values('W201714703','100','2017-6-1 08:00:00');
insert into WorkerSal values('W201714704','1000','2017-6-1 08:00:00');

/*插入车辆信息*/
insert into CarInfo values('C20170000','大众','黑色','A',80000,'2017-1-1 12:00:00',1000,40,'N');
insert into CarInfo values('C20170001','奔驰','红色','A',200000,'2017-2-1 12:00:00',2000,50,'Y');
insert into CarInfo values('C20170002','丰田','蓝色','C',98000,'2017-3-1 12:00:00',1000,40,'N');
insert into CarInfo values('C20170003','悍马','绿色','A',300000,'2017-4-1 12:00:00',3000,100,'Y');
insert into CarInfo values('C20170004','比亚迪','白色','C',80000,'2017-5-1 12:00:00',1000,40,'N');
insert into CarInfo values('C20170005','大众','黑色','A',80000,'2017-6-1 12:00:00',1000,40,'N');

/*插入订单信息表*/
insert into RentInfo values('T000001','W201714700','User0','C20170001','2017-1-2 16:24:56','2017-1-2 19:50:30',130.67,0,'A');
insert into RentInfo values('T000002','W201714701','User2','C20170003','2017-1-4 16:24:56','2017-1-4 19:50:30',250.67,0,'B');
insert into RentInfo values('T000003','W201714702','User1','C20170002','2017-1-4 16:24:56','2017-1-4 19:50:30',194.67,0,'B');
insert into RentInfo values('T000004','W201714703','User0','C20170003','2017-1-3 16:24:56','2017-1-3 19:50:30',153.67,0,'A');
insert into RentInfo values('T000005','W201714704','User2','C20170002','2017-1-3 16:24:56','2017-1-3 19:50:30',150.67,0,'A');
insert into RentInfo values('T000006','W201714703','User0','C20170001','2017-1-5 16:24:56','2017-1-5 19:50:30',250.67,0,'D');
insert into RentInfo values('T000007','W201714700','User3','C20170005','2017-1-6 16:24:56','2017-1-6 19:50:30',123.67,0,'A');
insert into RentInfo values('T000008','W201714701','User0','C20170004','2017-1-9 16:24:56','2017-1-9 19:50:30',134.67,0,'A');
insert into RentInfo values('T000009','W201714702','User2','C20170001','2017-1-10 16:24:56','2017-1-10 19:50:30',190.67,0,'B');
insert into RentInfo values('T000010','W201714703','User0','C20170001','2017-1-12 16:24:56','2017-1-12 19:50:30',130.67,0,'A');
insert into RentInfo values('T000011','W201714704','User2','C20170003','2017-1-13 16:24:56','2017-1-13 19:50:30',120.67,0,'A');
insert into RentInfo values('T000012','W201714705','User0','C20170001','2017-1-15 16:24:56','2017-1-15 19:50:30',130.67,0,'A');
insert into RentInfo values('T000013','W201714702','User3','C20170002','2017-1-16 16:24:56','2017-1-16 19:50:30',120.67,0,'A');
insert into RentInfo values('T000014','W201714701','User0','C20170003','2017-1-17 16:24:56','2017-1-17 19:50:30',130.67,0,'A');
insert into RentInfo values('T000015','W201714703','User2','C20170004','2017-1-17 16:24:56','2017-1-17 19:50:30',140.67,0,'A');
insert into RentInfo values('T000016','W201714705','User0','C20170005','2017-1-18 16:24:56','2017-1-18 19:50:30',130.67,0,'A');
insert into RentInfo values('T000017','W201714700','User3','C20170001','2017-1-19 16:24:56','2017-1-19 19:50:30',120.67,0,'A');
insert into RentInfo values('T000018','W201714705','User0','C20170004','2017-1-19 16:24:56','2017-1-19 19:50:30',110.67,0,'A');
insert into RentInfo values('T000019','W201714701','User0','C20170003','2017-1-21 16:24:56','2017-1-21 19:50:30',190.67,0,'C');
insert into RentInfo values('T000020','W201714702','User3','C20170002','2017-1-22 16:24:56','2017-1-22 19:50:30',180.67,0,'A');
insert into RentInfo values('T000021','W201714703','User1','C20170001','2017-1-22 16:24:56','2017-1-22 19:50:30',140.67,0,'A');
insert into RentInfo values('T000022','W201714700','User2','C20170003','2017-1-24 16:24:56','2017-1-24 19:50:30',120.67,0,'A');
insert into RentInfo values('T000023','W201714704','User0','C20170005','2017-2-24 16:34:56','2017-2-24 19:50:30',130.67,0,'A');
insert into RentInfo values('T000024','W201714704','User2','C20170005','2017-2-28 16:24:56','2017-2-28 19:50:30',120.67,0,'A');
insert into RentInfo values('T000025','W201714703','User3','C20170005','2017-3-22 16:24:56','2017-3-22 19:50:30',110.67,0,'A');
insert into RentInfo values('T000026','W201714705','User1','C20170001','2017-3-23 16:34:56','2017-3-23 19:50:30',190.67,0,'C');
insert into RentInfo values('T000027','W201714702','User2','C20170003','2017-4-22 16:44:56','2017-4-22 18:50:30',180.67,0,'B');
insert into RentInfo values('T000028','W201714704','User3','C20170005','2017-4-25 16:24:56','2017-4-25 19:50:30',140.67,0,'A');
insert into RentInfo values('T000029','W201714702','User2','C20170004','2017-5-23 16:24:56','2017-5-23 19:50:30',130.67,0,'A');
insert into RentInfo values('T000030','W201714703','User0','C20170003','2017-5-28 16:24:56','2017-5-28 19:50:30',120.67,0,'A');
