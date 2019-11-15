from urllib import request
from http.cookiejar import MozillaCookieJar

# 将百度的cookie 信息保存到本地
cookiejar = MozillaCookieJar('cookie.txt')
# cookiejar.load(ignore_discard=True)
handler = request.HTTPCookieProcessor(cookiejar)
opener = request.build_opener(handler)

resp = opener.open('http://www.baidu.com/')
cookiejar.save()


# 保存 cookie 信息到cookie.txt 文件中
cookiejar = MozillaCookieJar('cookie.txt')

# 加载 cookie 信息
cookiejar.load(ignore_discard=True)

handler = request.HTTPCookieProcessor(cookiejar)
opener = request.build_opener(handler)

resp = opener.open('http://httpbin.org/cookies/set?course=abc')
# 保存即将过期的 cookie信息
cookiejar.save(ignore_discard=True)

for cookie in cookiejar:
    print(cookie)

