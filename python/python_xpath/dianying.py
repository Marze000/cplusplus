import requests
from lxml import etree

# 电影天堂网页
BASE_DOMAIN = 'https://dytt8.net/'
HEADERS = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36'
}
url = 'https://dytt8.net/html/gndy/dyzz/list_23_2.html'

def get_detail_ulrs(url):
    response = requests.get(url, headers=HEADERS)
    texts = response.text

    html = etree.HTML(texts)
    detail_urls = html.xpath("//table[@class='tbspan']//a/@href")
    map(lambda url: BASE_DOMAIN+url,detail_urls)
    # 匿名函数 datail_urls 作为参数传递进去 等价于20到26行
    '''
    def Noname(url):
        return BASE_DOMAIN+url
    dex = 0
    for detail_url in detail_urls:
        detail_url = Noname(detail_url)
        detail_urls[dex] = datail_url
        dex+=1
    '''
    return detail_urls

# 某一个页面的详细信息
def parse_detail_page(url):
    resp = requests.get(url,headers=HEADERS)

    text = resp.content.decode('gbk')
    html = etree.HTML(text)
    title = html.xpath("//font[@class='#07519a']")
    print(title)

# 获取多个页面的url
def spider():
    base_url = 'https://dytt8.net/html/gndy/dyzz/list_23_{}.html'
    for x in range(2,8):
        url = base_url.format(x)
        detail_urls = get_detail_ulrs(url)
        #解析一个页面的详细信息
        for detail_url in detail_urls:
            movies = parse_detail_page(detail_url)
            break
        break
    
if __name__ == "__main__":
    spider()