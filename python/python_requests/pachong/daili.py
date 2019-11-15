from urllib import request

# 没有使用代理ip
url = 'http://httpbin.org/ip'
resp = request.urlopen(url)
print(resp.read())

# 使用代理的 ip 
url = 'http://httpbin.org/ip'
# 1. 代理的原理：在请求某个目的网站时,先请求代理服务器，然后
#    在让代理服务器去请求目的网站,代理服务器拿到目的网站的数据
#    后再转发到我们的服务器上的
# 2. http://httpbin.org 这个网站可以方便的查看 http 参数
# 3. 在代码中使用代理
#    (a)urllib.request.ProxyHandler 传入一个字典类型的代理
#    (b)使用上一步骤创建的 handler 以及 build_opener 创建一个opener对象
#    (c)使用上一步骤创建的opener,调用open函数发起调用
handler = request.ProxyHandler({'http':'118.212.106.7:9999'})
opener = request.build_opener(handler)
resp = opener.open(url)
print(resp.read().decode('utf-8'))
#"origin": "111.18.97.50, 111.18.97.50"

