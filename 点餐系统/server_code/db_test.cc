#include "db.hpp"

void TestDishTable(){
  MYSQL* mysql = order_system::MYSQLInit();
  order_system::DishTable dish_table(mysql);
  
  Json::StyledWriter writer;
  //插入数据
  // Json::Value dish;
  // dish["name"] = "烧鸡扒饭";
  // dish["price"] = 1000;
  // bool ret = dish_table.Insert(dish);
  // printf("ret = %d\n",ret);

  //查找所有数据
  // Json::Value dishes;
  // int ret = dish_table.SelectAll(&dishes);
  // printf("ret = %d\n",ret);
  // Json::StyledWriter writer;
  // printf("%s\n",writer.write(dishes).c_str());

  //查找指定数据
  // Json::Value dish;
  // int ret = dish_table.SelectOne(1,&dish);
  // printf("ret = %d\n",ret);
  // printf("%s\n",writer.write(dish).c_str());

  //修改指定数据
  // Json::Value dish;
  // dish["dish_id"] = 1;
  // dish["name"] = "宫保鸡丁";
  // dish["price"] = 1600;
  // int ret = dish_table.Update(dish);
  // printf("ret = %d\n",ret); 


  //删除指定数据
  int ret = dish_table.Delete(9);
  printf("ret = %d\n",ret);
  
  //释放句柄
  order_system::MYSQLRelease(mysql);
}

void TestOrderTable(){
  MYSQL* mysql = order_system::MYSQLInit();
  order_system::OrderTable order_table(mysql);
  Json::StyledWriter writer;

  //插入
  //Json::Value order;
  //order["table_id"] = "牡丹亭";
  //order["time"] = "2019-01-02 12:00";
  //order["dishes"] = "[1,2,5]";
  //order["status"] = 1;
  //int ret = order_table.Insert(order);
  //printf("ret = %d\n",ret);


  //查看所有订单
  // Json::Value orders;
  // int ret = order_table.SelectAll(&orders);
  // printf("ret = %d\n",ret);
  // printf("%s\n",writer.write(orders).c_str());

  //修改状态
  // Json::Value order;
  // order["order_id"] = 5;
  // order["status"] = 1;
  // int ret = order_table.ChangeState(order);
  // printf("ret = %d\n",ret);
  
  //释放
  order_system::MYSQLRelease(mysql);
}


int main(){
  //TestOrderTable();

  //TestDishTable();
  
  return 0;
}
