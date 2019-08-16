//Json:Value 表示一个Json 对象
//Write:write 把Json 对象序列化成字符串(std::string)
//Reader:parse 把字符串反序列为 Json 对象

#include <cstdio>
#include <cstdlib>
#include <jsoncpp/json/json.h>

int main(){
  //定义 Json 对象
  Json::Value value;
  value["dish_id"] = 1;
  value["name"] = "红烧肉";
  value["price"] = 2000;

  //将字符串转换为 Json 对象
  Json::FastWriter writer;
  const std::string& str = writer.write(value);
  printf("%s\n",str.c_str());

  std::string str2 = R"({"name":"红烧肉","price":100})";//原始字符串
  Json::Reader reader;
  Json::Value output;
  //把字符串反序列化为Json 对象
  reader.parse(str2,output);
  //将 Json 对象转换为 c 分格字符串
  printf("%s,%d\n",output["name"].asCString(),
      output["price"].asInt());
  
  return 0;
}
// 编译
// g++ jsoncpp.cc -o jsoncpp -ljsoncpp
