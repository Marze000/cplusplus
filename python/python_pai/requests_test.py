import requests
from urllib import parse,request

kw = {'wd':'??'}
headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36'
}

response = requests.get("http://www.baidu.com/",params=kw,headers=headers)

# print(response.text)

# print(response.content)

# print(response.url)

# print(response.encoding)

print(response.status_code)