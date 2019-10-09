from urllib import request
from http.cookiejar import CookieJar
from urllib import parse

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36'
}

# 创建一个 opener
def get_opener():
    # (a)创建一个 cookiejar 对象
    cookiejar = CookieJar()
    # (b)使用 cookiejar 创建一个HTTPCookieProcessor 对象
    handler = request.HTTPCookieProcessor(cookiejar)
    # (c)使用 上一步创建的 handler 创建一个opener
    opener = request.build_opener(handler)
    return opener

# 使用 opener 发送登录的请求(登录和密码)
def login_renren(opener):
    data = {
        'email': '18729502326',
        'password': 'mz5781966'
    }
    homeurl = 'http://www.renren.com/PLogin.do'
    req = request.Request(homeurl, headers=headers,data=parse.urlencode(data).encode('utf-8'))
    opener.open(req)

# 访问个人主页
def visit_profile(opener):
    majorUrl = 'http://www.renren.com/972414811'
    # 获取个人主页的时候直接使用之前的 opener
    req = request.Request(majorUrl,headers=headers)
    resp = opener.open(req)
    # 把数据写入 renren.html 文件中
    with open('renren.html','w',encoding='utf-8') as fp:
        fp.write(resp.read().decode('utf-8'))

if __name__ == "__main__":
    opener = get_opener()
    login_renren(opener)
    visit_profile(opener)
