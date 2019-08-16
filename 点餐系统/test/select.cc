#include <cstdio>
#include <cstdlib>
#include <mysql/mysql.h>

int main(){
  MYSQL* mysql = mysql_init(NULL);
  if(mysql_real_connect(mysql,"127.0.0.1","root","5781966",
        "order_system",3306,NULL,0) == NULL){
    printf("mysql 连接失败%s\n",mysql_error(mysql));
    mysql_close(mysql);
    return 1;
  }

  mysql_set_character_set(mysql,"utf8");

  char sql[1024] = {0};
  sprintf(sql,"select* from dish_table");

  int ret = mysql_query(mysql,sql);
  if(ret != 0){
    printf("SQL 执行失败%s\n",mysql_error(mysql));
    mysql_close(mysql);
    return 1;
  }

  //获取并遍历结果集合
  MYSQL_RES* result = mysql_store_result(mysql);
  //获取结果有几行
  int rows = mysql_num_rows(result);
  int cols = mysql_num_fields(result);
  //根据行遍历结果
  for(int row = 0;row < rows; ++row){
    MYSQL_ROW mysql_row = mysql_fetch_row(result);
    //使用[]取下标获取每一列
    for(int col = 0; col < cols;++col){
      printf("%s\t",mysql_row[col]);
    }
    printf("\n");
  }

  //释放结果集合 和 数据库句柄
  mysql_free_result(result);
  mysql_close(mysql);

  return 0;
}
