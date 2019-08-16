#include <cstdio>
#include <cstdlib>
#include <mysql/mysql.h>

int main(){
  //创建一个句柄
  MYSQL* mysql = mysql_init(NULL);

  //建立连接
  if(mysql_real_connect(mysql,"127.0.0.1","root","5781966",
        "order_system",3306,NULL,0) == NULL){
    printf("connect failed! %s\n",mysql_error(mysql));
    mysql_close(mysql);
    return 1;
  }

  //设置编码格式 使服务器的编码格式和客户端相同
  mysql_set_character_set(mysql,"utf8");
  
  //拼装一个 SQL语句
  char sql[1024] = {0};
  int price = 2000;
  sprintf(sql,"insert into dish_table values(null,'炸鸡煲饭',%d)",price);

  //执行 SQL 语句
  int ret = mysql_query(mysql,sql);
  if(ret != 0){
    printf("sql 执行失败 %s\n",mysql_error(mysql));
    mysql_close(mysql);
    return 1;
  }

  mysql_close(mysql);
  return 0;
}
