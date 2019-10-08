from lxml import etree

parser = etree.HTMLParser(encoding='utf8')
html = etree.parse('F:/c_exercise/python/python_xpath/tenxun.html',parser=parser)

# 获取所有的 span 标签
#spans = html.xpath("//span")
#for span in spans:
#    print(etree.tostring(span,encoding='utf-8').decode('utf-8'))

# 获取第二个的 span 标签
#span = html.xpath("//span[2]")[0]
#print(span)

# 获取所有 class 等于even 的tr标签

# 获取所有 a 标签的herf 属性
#aList = html.xpath("//a/@href")
#for a in aList:
#    print(a)

# 获取所有 class 等于 container 的 div 标签
#aList = html.xpath("//div[@class='container']")
#for a in aList:
#    print(a)


# 获取所有的职位信息(纯文本)
divs = html.xpath("//div[position()>1]")
positions = []
for div in divs:
    title = div.xpath(".//h4[1]//text()")
    adress = div.xpath(".//span[2]//text()")
    time = div.xpath(".//span[4]//text()")[0]
    capacity = div.xpath(".//p[2]//text()")[0]
    position = {
        "职位名称":title,
        "地址":adress,
        "公布时间":time,
        "能力":capacity
    }
    positions.append(position)
print(positions)