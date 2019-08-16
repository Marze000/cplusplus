#include "httplib.h"
#include "db.hpp"
#include <signal.h>
#include "util.hpp"

MYSQL* mysql = NULL;
const char* CONTENT_TYPR = "application/json";

int main(){
  using namespace httplib; 
  using namespace order_system;
  Server server;
  mysql = MYSQLInit ();
  signal(SIGINT, [](int) { 
      order_system::MYSQLRelease (mysql); 
      exit(0);}
  );

  DishTable dish_table(mysql);
  OrderTable order_table(mysql);

  //新增菜品 请求
  server.Post("/dish",[&dish_table](const Request& req,
        Response& resp){

      printf("新增菜品\n");
      Json::Reader reader;
      Json::FastWriter writer;
      Json::Value req_json;
      Json::Value resp_json;
      // 1. 将请求解析成 Json 格式
      bool ret = reader.parse(req.body, req_json);
      if (!ret) {
        // 请求解析出错, 返回一个400响应
        printf("parse body failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "parse Request failed!";
        resp.status = 400;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }
      // 2. 进行参数校验
      if (req_json["name"].empty() || req_json["price"].empty()) {
        printf("Request json error format!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "Request has no name or price field!\n";
        resp.status = 400;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }
      // 3. 调用数据库接口进行操作数据
      ret = dish_table.Insert(req_json);
      if (!ret) {
        resp_json["ok"] = false;
        resp_json["reason"] = "Insert failed!\n";
        resp.status = 500;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }

      // 4. 封装正确的返回结果
      resp_json["ok"] = true;
      resp.set_content(writer.write(resp_json), CONTENT_TYPR);
      resp.status = 200;
      return;
    });


  //Get 获取所有菜品接口
  server.Get("/dish",[&dish_table](const Request& req,
        Response& resp){

      printf("查看所有菜品\n");
      (void)req;
      Json::Value resp_json;
      Json::FastWriter writer;
      bool ret = dish_table.SelectAll(&resp_json);
      if (!ret) {
        resp_json["ok"] = false;
        resp_json["reason"] = "SelectAll failed!\n";
        resp.status = 500;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }
      // 2. 构造响应结果
      resp.status = 200;
      resp.set_content(writer.write(resp_json), CONTENT_TYPR);
      return;
    });

  //正则表达式 带有特殊符号的字符串:描述了字符串的特性
  // \d+ 匹配阿拉伯数字
  server.Get(R"(/dish/(\d+))",[&dish_table](const Request& req,
        Response& resp){

      Json::FastWriter writer;
      Json::Value resp_json;
      // std::stoi 将字符串转为 数字
      // std::to_string 数字转为字符串
      int32_t dish_id = std::stoi(req.matches[1]);
      printf("获取到编号为 %d 的菜名\n",dish_id);
      // 对于查看菜品来说 API 没有请求参数, 
      // 不需要解析参数和校验了, 直接构造结果即可
      // 1. 调用数据库接口查询数据
      bool ret = dish_table.SelectOne(dish_id,&resp_json);
      if (!ret) {
        printf("dish_table select one failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "SelectOne failed!\n";
        resp.status = 500;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }
      // 2. 构造响应结果
      resp.status = 200;
      resp.set_content(writer.write(resp_json), CONTENT_TYPR);
      return;
    });


  //修改菜品
  server.Put(R"(/dish/(\d+))",[&dish_table](const Request& req,
        Response& resp){

      Json::Reader reader;
      Json::FastWriter writer;
      Json::Value req_json;
      Json::Value resp_json;
      //获取到 dish_id
      int32_t dish_id = std::stoi(req.matches[1]);
      printf("修改编号为 %d 菜品\n",dish_id);

      // 1. 将请求解析成 Json 格式
      bool ret = reader.parse(req.body, req_json);
      if (!ret) {
        // 请求解析出错, 返回一个400响应
        printf("parse body failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "parse Request failed!";
        resp.status = 400;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }
      // 2. 进行参数校验
      if (req_json["name"].empty() || req_json["price"].empty()) {
        printf("Request json error format!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "Request has no name or price field!\n";
        resp.status = 400;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }
      // 3. 调用数据库接口进行操作数据
      req_json["dish_id"] = dish_id;
      ret = dish_table.Update(req_json);
      if (!ret) {
        printf("DishTable Update failed\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "Update failed!\n";
        resp.status = 500;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }

      // 4. 封装正确的返回结果
      resp_json["ok"] = true;
      resp.status = 200;
      resp.set_content(writer.write(resp_json), CONTENT_TYPR);
      return;
    });

  //删除菜品
  server.Delete(R"(/dish/(\d+))",[&dish_table](const Request& req,
        Response& resp){

      Json::Value resp_json;
      Json::FastWriter writer;
      //获取到 dish_id 
      int32_t dish_id = std::stoi(req.matches[1]);
      printf("删除编号为 %d 的菜品\n",dish_id);
      
      //执行操作
      bool ret = dish_table.Delete(dish_id);
      if (!ret) {
        printf("DishTable Delete failed\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "Delete failed!\n";
        resp.status = 500;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;
      }
      // 4. 封装正确的返回结果
      resp_json["ok"] = true;
      resp.status = 200;
      resp.set_content(writer.write(resp_json), CONTENT_TYPR);
      return;
    });

  /////////////////////////////////////////
  //订单的相关操作
  /////////////////////////////////////////
  //新增订单
  server.Post("/order",[&order_table](const Request& req,
        Response& resp){

      Json::Value req_json;
      Json::Value resp_json;
      Json::Reader reader;
      Json::FastWriter writer;
      printf("新增一个订单\n");
      //1 获取到body 数据并解析
      bool ret = reader.parse(req.body,req_json);
      if(!ret){
        printf("order_table parse failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "order parse failed!";
        resp.status = 400;
        resp.set_content(writer.write(resp_json),CONTENT_TYPR);
        return;
      }
      // 校验body 中的数据是否符合要求
      if(req_json["table_id"].empty() ||
              req_json["time"].empty()||
          req_json["dish_ids"].empty()){

        printf("order_table format failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "order format failed!";
        resp.status = 400;
        resp.set_content(writer.write(resp_json),CONTENT_TYPR);
        return;
      }
      //构造其他需要的字段
      req_json["status"] = 1;
      //把 dish_ids 转换为 dishes
      const Json::Value& dish_ids = req_json["dish_ids"];
      req_json["dishes"] = writer.write(dish_ids);
      // 调用数据库操作
      ret = order_table.Insert(req_json);
      if(!ret){
        printf("order_table Insert failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "order Insert failed!";
        resp.status = 500;
        resp.set_content(writer.write(resp_json),CONTENT_TYPR);
        return;
      }
      //构造正确响应
      resp_json["ok"] = true;
      resp.status = 200;
      resp.set_content(writer.write(resp_json), CONTENT_TYPR);
      return;     
    });

  // 查看订单
  server.Get("/order",[&order_table](const Request& req,
        Response& resp){

        printf("获取所有订单\n");
        Json::Value resp_json;
        Json::FastWriter writer;
        bool ret = order_table.SelectAll(&resp_json);
        if(!ret){
          printf("order_table SelectAll failed!\n");
          resp_json["ok"] = false;
          resp_json["reason"] = "order SelectAll failed!";
          resp.status = 500;
          resp.set_content(writer.write(resp_json),CONTENT_TYPR);
          return;
        }
        //构造正确响应
        resp_json["ok"] = true;
        resp.status = 200;
        resp.set_content(writer.write(resp_json), CONTENT_TYPR);
        return;     
    });


  //修改订单
  server.Put(R"(/order/(\d+))",[&order_table](const Request& req,
        Response& resp){

      Json::Value req_json;
      Json::Value resp_json;
      Json::Reader reader;
      Json::FastWriter writer;

      //获取到 order_id 
      int32_t order_id = std::stoi(req.matches[1]);
      printf("修改编号为 %d 的订单状态\n",order_id);
      //  解析请求中的status
      bool ret = reader.parse(req.body,req_json);
      if(!ret){
          printf("order_table parse failed!\n");
          resp_json["ok"] = false;
          resp_json["reason"] = "order parse failed!";
          resp.status = 400;
          resp.set_content(writer.write(resp_json),CONTENT_TYPR);
          return;
      }
      //校验参数
      if(req_json["status"].empty()){
        printf("order_table format failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "order format failed!";
        resp.status = 400;
        resp.set_content(writer.write(resp_json),CONTENT_TYPR);
        return;
      }
      //执行数据库操作
      req_json["order_id"] = order_id;
      ret = order_table.ChangeState(req_json);
      if(!ret){
        printf("order_table ChangeState failed!\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "order ChangeState failed!";
        resp.status = 500;
        resp.set_content(writer.write(resp_json),CONTENT_TYPR);
        return;
      }
      //构造正确响应
      resp_json["ok"] = true;
      resp.status = 200;
      resp.set_content(writer.write(resp_json), CONTENT_TYPR);
      return;     
  });
  server.Get("/table",[](const Request& req,Response& resp){
        const std::string& table_id = req.get_param_value("table_id");
        printf("table_id = %s\n",table_id.c_str());
        std::string html;
        FileUtil::ReadFile("./wwwroot/tables.html",&html);
        std::string html_out;
        StringUtil::Replace(html,"{{table_id}}",table_id,&html_out);
        resp.set_content(html_out,"text/html");
    });
  server.set_base_dir("./wwwroot");
  server.listen("0.0.0.0",9094);
  
  return 0;
}
