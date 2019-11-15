import requests

response = requests.get('http://www.baidu.com/')
# print(type(response.text)) # str 类型
# print(response.text.)
''' response.text 和 response.content的区别？'''
# 1.text 是将 content 进行解码后的字符串类型,不过他的解码方式
#   自己猜测的，所以有很大的概率导致出错乱码的情况
# 这个时候就应该使用 content.decode('utf-8')进行手动的解码
# 2. content 这是直接从网络上抓取到的数据类型，没有经过任何的
#     解码，所有是一个 bytes类型
# print(response.content.decode('utf-8'))
# print(type(response.content)) # bytes 类型

print(response.url)
print(response.encoding)
print(response.status_code)
