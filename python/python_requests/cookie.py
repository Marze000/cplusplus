from urllib import request
 
# 博客园主页 https://home.cnblogs.com/u/maze652/
# 不使用cookie登录博客园主页
homeurl = 'https://home.cnblogs.com/u/maze652/'

# 手动添加 cookie
header = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36',
    'Cookie':'_ga=GA1.2.1067517402.1555945975; __gads=ID=49717804966376d6:T=1555945975:S=ALNI_MbnjyAHZpuD-fkPYnWE0GlwjMYL9g; UM_distinctid=16aaa298bc791a-0a31e5cd4bced-3a614f0b-e1000-16aaa298bc98a1; gr_user_id=f925e923-075c-4fe5-98d3-233918795951; grwng_uid=d3401d2b-3296-4cc4-b243-546fcec8bd81; __utma=226521935.1067517402.1555945975.1568867197.1568867197.1; __utmz=226521935.1568867197.1.1.utmcsr=baidu|utmccn=(organic)|utmcmd=organic; .Cnblogs.AspNetCore.Cookies=CfDJ8DeHXSeUWr9KtnvAGu7_dX-DQpnl06qW5imjeS65CtETj2O-_rBLvwrQq0PfveZpv8NN7KAb5mm9TGXh7RhD9SUpcY5Y5if7brLcjtm5E1pd8nyGuYKLyzNaws4xv0EwOXyg4snhtgtd4106QMDQuKLEI7_AnvEf0c-5H0W8yuihMMh1kdVngx8xoV_KABARWqor6ikcMpud2djlYI6c71QI-cVYdVDC1exDCne0VL95MKdBTZgAuzGLJCy5BW4YeWFj8vsIq4BF2FVuB5UK9J8ZhV5N-0UFEA5AoHWEC2XvBt9nTdpav21PnsyhQ6sTdQmwI66clBk4_2jcWlRAH_esSBE9hGioses_GWUgdXLDe_PvfHshvRLNy-ZEXFOz_KSvoSZDeJMnVKy5DGZRQ-LEQE1vw1Z53ZNutaZOwhW922XY4-A3SVdj8JboqTB2YCQTLlVC021IalfIsce8K4g; _gid=GA1.2.44413705.1570261158; .CNBlogsCookie=8D58C1430DC5E16BA52449A9F6C59436A11EFE1DA2B68DBD31483E0DE4118A391FB6C83B8BFC0572FEAEFFF9BE9797393FFC4C61EE8F7037332525B044349A35663CB7F1BC916B45260B18080E37CD61592AF16C; _gat=1'
}

req = request.Request(url = homeurl,headers=header)
resp = request.urlopen(req)
# 将需要访问的网页返回到一个文件中
# write 必须写入的是一个 str 类型的
# resp.read() 读出来的是一个bytes的类型
# bytes -> deconde == str
# str -> enconde == bytes
with open('bokeyuan.html','w',encoding='utf-8') as fp:
    fp.write(resp.read().decode('utf-8'))