import requests

url = 'http://www.renren.com/PLogin.do'
data = {
    'email':'18729502326',
    'password':'mz5781966'
}
headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36'
}

# 登录
session = requests.session()
def login():
    session.post(url,data=data,headers=headers)

# 访问个人主页
def profile():
    resp = session.get('http://www.renren.com/972414811')
    # 如果要访问一个不被信任的网站
    # 则在网址后面再加一个参数 verify=False
    with open('renren.html','w',encoding='utf-8')as fp:
        fp.write(resp.text)

if __name__ == "__main__":
    login()
    profile()

'''
resp = requests.get('http://www.baidu.com/')
# 获取 cookie 信息
print(resp.cookies)
print(resp.cookies.get_dict())
'''