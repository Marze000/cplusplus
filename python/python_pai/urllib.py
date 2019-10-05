from urllib import request
from urllib import parse
'''
# 爬取一张网页的源代码
resp = request.urlopen('http://www.baidu.com')
print(resp.getcode())
print(resp.read())

# 下载一张图片保存到 women.jpg文件中
resp = request.urlretrieve('https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1570286978006&di=0f1ee998d7d4582bca72ae7cf349a8ab&imgtype=0&src=http%3A%2F%2Fhbimg.b0.upaiyun.com%2F71ff69934501746b5655368f0e4fc84495e41f96de27-CIJh6T_fw658','women.jpg')

data = {'name':'爬虫基础','greet':'hello python','age':10}
qs = parse.urlencode(data)
print(qs)

# url 拼接
url = 'https://www.baidu.com/s'
parms = {'wd':'美女'}
qs = parse.urlencode(parms)
url = url + '?'+qs
print(url)

# 编码与解码
data = {'name':'爬虫基础','greet':'hello python','age':10}
qs = parse.urlencode(data)
result = parse.parse_qs(qs)
print(qs)
print(result)

# url 的 分割
url = 'http://www.baidu.com/s?wd=python&username=abc#1'
# 这个函数是 url 的解析分割
result = parse.urlsplit(url)
print(result)
# 每一部分的输出
print('scheme:',result.scheme)
print('netloc:',result.netloc)
print('path:',result.path)
print('query:',result.query)
print('fragment:',result.fragment)

url = 'http://www.baidu.com/s?wd=python&username=abc#1'
result = parse.urlsplit(url)
print(result)
'''

# 定制 User-Agent 构造一个反爬虫请求
url = 'https://www.lagou.com/jobs/positionAjax.json?px=default&city=%E5%8E%A6%E9%97%A8&needAddtionalResult=false'

Headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36',
    'Referer':'https://www.lagou.com/jobs/list_python%E5%90%8E%E7%AB%AF/p-city_129?px=default',
    'Host': 'www.lagou.com',
    'Origin': 'https://www.lagou.com',
    'X-Anit-Forge-Code': 0,
    'X-Anit-Forge-Token':'None',
    'X-Requested-With': 'XMLHttpRequest'
}

Data = {
   'first':'true',
   'pn':1,
   'kd':'python'
}

req = request.Request(url,headers=Headers,
                data=parse.urlencode(Data).encode('utf-8'),
                method='POST')

resp = request.urlopen(req)
print(resp.read().decode('utf-8'))

