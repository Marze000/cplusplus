import requests
from lxml import etree

#1.将目标网站上的信息抓取下来
headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36',
    'Referer': 'https://movie.douban.com/'
}
url = 'https://movie.douban.com/cinema/nowplaying/xian/'
response = requests.get(url,headers=headers)
text = response.text
# print(text)
# 返回的是一个解码的字符串
# print(response.text) 

#返回的是一个原生类型的数据,直接从网上获取到并没有处理的bytes类型
# print(response.content.decode('utf-8'))

html = etree.HTML(text)
ul = html.xpath("//ul[@class='lists']")[0]
lis  = ul.xpath("./li")
movies = []
for li in lis:
    title = li.xpath('@data-title')[0]
    score = li.xpath('@data-score')[0]
    duration =li.xpath('@data-duration')[0]
    region = li.xpath('@data-region')[0]
    director = li.xpath('@data-director')[0]
    actors = li.xpath('@data-actors')[0]
    thumbnail = li.xpath('.//img/@src')
    movie = {
        '标题':title,
        '评分':score,
        '时长':duration,
        '地点':region,
        '导演':director,
        '演员':actors,
        '海报':thumbnail
    }
    movies.append(movie)
print(movies)