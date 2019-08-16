create database if not exists order_system;
use order_system;

create table if not exists dish_table(
  dish_id int unsigned not null primary key auto_increment,
  name varchar(50),
  price int);

insert into dish_table values(null, '宫保鸡丁', 1500);
insert into dish_table values(null, '广东白切鸡', 1600);
insert into dish_table values(null, '上海白斩鸡', 1700);
insert into dish_table values(null, '得州扒鸡', 1800);
insert into dish_table values(null, '河南道口烧鸡', 1900);
insert into dish_table values(null, '梁宁狗包子鸡', 2800);
insert into dish_table values(null, '新疆大盘鸡', 1800);
insert into dish_table values(null, '糖醋鸡块', 1800);
insert into dish_table values(null, '川味棒棒鸡', 1800);

create table if not exists order_table(
  order_id int unsigned not null primary key auto_increment,
  table_id varchar(50),
  time varchar(50),
  dishes varchar(1024),
  status int
); 

insert into order_table values(null, '梅花厅', '2019-05-10 12:00', '1,2,3', 1);
insert into order_table values(null, '杏花莲', '2019-05-15 13:00', '1,3,4,5', 0);
insert into order_table values(null, '菊花坛', '2019-05-15 14:00', '1,3,6', 0);
insert into order_table values(null, '桃花源', '2019-05-15 15:00', '1,3,6,7', 0);
insert into order_table values(null, '荷花池', '2019-05-15 16:00', '1,3,4', 0);
insert into order_table values(null, '牡丹盆', '2019-05-15 17:00', '1,3', 0);

