#pragma once

#include <cstdio>
#include <cstdlib>
#include <mysql/mysql.h>
#include <jsoncpp/json/json.h>


namespace order_system{
//创建MySQL 句柄并建立连接
static MYSQL* MYSQLInit(){
  MYSQL* mysql = mysql_init(NULL);
  if(mysql_real_connect(mysql,"127.0.0.1","root","5781966",
        "order_system",3306,NULL,0) == NULL){
    printf("mysql 连接失败 %s\n",mysql_error(mysql));
    return NULL;
  }
  mysql_set_character_set(mysql,"utf8");
  return mysql;
}

static void MYSQLRelease(MYSQL* mysql){
  mysql_close(mysql);
}

class DishTable{
public:
  DishTable(MYSQL* mysql):mysql_(mysql){
    
  }

  // 使用Json 作为函数参数
  // jsoncpp
  bool Insert(const Json::Value& dish){
    char sql[1024] = {0};
    sprintf(sql,"insert into dish_table values(null,'%s',%d)",
        dish["name"].asCString(),dish["price"].asInt());

    //执行SQL
    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("DishTable Insert failed! %s\n",mysql_error(mysql_));
      return false;
    }
    printf("DishTable Insert OK!\n");
    return true; 
  }

  //使用 Json 表示输出型参数 Json::Value* 
  //const & 表示输入型参数
  //* 表示输出型参数
  //& 表示输入输出型参数
  bool SelectAll(Json::Value* dishes){
    char sql[1024 * 4] = {0};
    sprintf(sql,"select* from dish_table");
    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("DishTable SelectAll failed! %s\n",mysql_error(mysql_));
    }
    printf("DishTable SelectAll Ok!\n");
    MYSQL_RES* result = mysql_store_result(mysql_);
    //获取行数
    int rows = mysql_num_rows(result);
    for(int i = 0;i < rows;++i){
      MYSQL_ROW row = mysql_fetch_row(result);
      Json::Value dish;
      //row 取出的是 C分格字符串
      dish["dish_id"] = atoi(row[0]);
      dish["name"] = row[1];
      dish["price"] = atoi(row[2]);
      //把信息插入到输出型参数中
      dishes->append(dish);
    }
    mysql_free_result(result);
    return true;
  }

  bool SelectOne(int32_t dish_id,Json::Value* dish){
    char sql[1024] = {0};
    sprintf(sql,"select* from dish_table where dish_id = %d",dish_id);
    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("DishTable SelectOne falied! %s\n",mysql_error(mysql_));
      return false; 
    }
    printf("DishTable SelectOne OK\n");
    //遍历结果集合
    MYSQL_RES* result = mysql_store_result(mysql_);
    int rows = mysql_num_rows(result);
    if(rows != 1){
      printf("DishTable SelectOne result rows not 1\n");
      mysql_free_result(result);
      return false;
    }
    //取出这一行数据
    MYSQL_ROW row = mysql_fetch_row(result);
    (*dish)["dish_id"] = dish_id;
    (*dish)["name"] = row[1];
    (*dish)["price"] = atoi(row[2]);
    mysql_free_result(result);
    return true;
  }

  bool Update(const Json::Value& dish){
    char sql[1024] = {0};
    sprintf(sql,"update dish_table set name = '%s',price = %d where dish_id = %d",
        dish["name"].asCString(),
        dish["price"].asInt(),
        dish["dish_id"].asInt());

    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("DishTable Update failed! %s\n",mysql_error(mysql_));
      return false;
    }
    printf("DishTable Update OK!\n");
    return true;
  }
  
  bool Delete(int32_t dish_id){
    char sql[1024] = {0};
    sprintf(sql,"delete from dish_table where dish_id = %d",dish_id);
    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("DishTable Delete failed! %s\n",mysql_error(mysql_));
      return false;
    }
    printf("DishTable Delete ok!\n");
    return true;
  }
private:
  MYSQL* mysql_;
};

class OrderTable{
public:
  OrderTable(MYSQL* mysql):mysql_(mysql){

  }

  bool Insert(const Json::Value& order){
    char sql[1024] = {0};
  sprintf(sql,"insert into order_table values(null,'%s','%s','%s','%d')",
        order["table_id"].asCString(),
        order["time"].asCString(),
        order["dishes"].asCString(),
        order["status"].asInt());

    //执行 SQL
    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("OrderTable Insert falied! %s\n",mysql_error(mysql_));
      return false;
    }
    printf("OrderTable Insert OK \n");
    return true;
  }

  bool SelectAll(Json::Value* orders){
    char sql[1024] = {0};
    sprintf(sql,"select order_id,table_id,time,dishes,status from order_table");

    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("OrderTable SelectAll failed! %s\n",mysql_error(mysql_));
    }
    printf("OrderTable SelectAll ok\n");
    // 拼装到输出型参数中
    MYSQL_RES* result = mysql_store_result(mysql_);
    int rows = mysql_num_rows(result);
    for(int i = 0; i < rows; ++i){
      MYSQL_ROW row = mysql_fetch_row(result);
      Json::Value order;
      order["order_id"] = atoi(row[0]);
      order["table_id"] = row[1];
      order["time"] = row[2];
      order["dishes"] = row[3];
      order["status"] = atoi(row[4]);
      orders->append(order);
    }
    mysql_free_result(result);
    return true;
  }

  bool ChangeState(const Json::Value& order){
    char sql[1024] = {0};
    sprintf(sql,"update order_table set status = %d where order_id = %d",
        order["status"].asInt(),
        order["order_id"].asInt());

    int ret = mysql_query(mysql_,sql);
    if(ret != 0){
      printf("OrderTable ChangeState failed! %s\n",mysql_error(mysql_));
      return false;
    }
    printf("OrderTable ChangeState OK!\n");
    return true;
  }
private:
  MYSQL* mysql_;
};

}//end order_system
