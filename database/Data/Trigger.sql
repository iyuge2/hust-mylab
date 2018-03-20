use CarRentSys;
drop trigger DeleteUser;
delimiter $$
create trigger DeleteUser before delete on User
for each row
begin
    /*在删除用户前将租借信息表中的用户名改为U000000*/
    update RentInfo set Uname='U000000' where RentInfo.Uname = old.Uname;
end
$$
delimiter ;

drop trigger DeleteWorker;
delimiter $$
create trigger DeleteWorker before delete on Worker
for each row
begin
    /*在删除员工前将租借信息表中经手员工编号改为W000000001*/
    update RentInfo set Wnum='W000000001' where Wnum=old.Wnum;
    /*同步删除该员工的奖金信息*/
    delete from WorkerSal where WorkerSal.Wnum=old.Wnum;
end
$$
delimiter ;
