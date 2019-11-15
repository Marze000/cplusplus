import requests

kw = {'wd':'??'}

headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36'
}

response = requests.get('http://www.baidu.com/s',params=kw,headers=headers)
with open('baidu.html','w',encoding='utf-8')as fp:
    fp.write(response.content.decode('utf-8'))
print(response.url)
# ??????Uniconde?? 
# print(response.text)

# ???????????????? bytes
# print(response.content)

# ????? url ??
# print(response.url)

# ??????????
# print(response.encoding)

# ?????
# print(response.status_code)

