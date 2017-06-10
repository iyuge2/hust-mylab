use CarRentSys;
drop trigger DeleteUser;
delimiter $$
create trigger DeleteUser before delete on User
for each row
begin
    update RentInfo set Uname='U000000' where RentInfo.Uname = old.Uname;
end
$$
delimiter ;

drop trigger DeleteWorker;
delimiter $$
create trigger DeleteWorker before delete on Worker
for each row
begin
    update RentInfo set Wnum='W000000001' where Wnum=old.Wnum;
    delete from WorkerSal where WorkerSal.Wnum=old.Wnum;
end
$$
delimiter ;
