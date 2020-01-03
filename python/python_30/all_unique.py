import re
# print(re.match('www', 'www.runoob.com').group())
# print(re.search('tion', 'functions'))
# ret = re.sub('\d', '@', 'duiag2dau9hd81dhakl')
# 先按 @ 分割,再按 a 分割
# ret = re.split('[@a]', 'dkjas@dak@fa')
# print(ret)
'''
line = "Cats are smarter than dogs"


matchObj = re.match(r'(.*) are (.*?) than(.*)', line, re.M | re.I)

if matchObj:
    print('matchObj.group():', matchObj.group())
    print('matchObj.group(1):', matchObj.group(1))
    print('matchObj.group(2):', matchObj.group(2))
    print('matchObj.group(2):', matchObj.group(3))
else:
    print("No match!!")

'''


'''
匹配 '数字+a+数字'
print(re.match(r'(\d+)a(\d+)', '381a296').group(0))
print(re.match(r'\d+a\d+)', '381a296').group(1))
print(re.match(r'(\d+)a(\d+)', '381a296').group(2))
'''

'''
line = "Cats are smarter than dogs"
matchObj = re.match(r'dogs', line, re.M | re.I)

print(matchObj.group())
matchObj = re.search(r'dogs', line, re.M | re.I)
print(matchObj.group())
# pattern : 正则中的模式字符串。
# repl : 替换的字符串，也可为一个函数。
# string : 要被查找替换的原始字符串。
# count : 模式匹配后替换的最大次数，默认 0 表示替换所有的匹配。

phone = "2004-959-559 # 这是一个国外电话号码"
# 删除字符串中的 Python注释
num = re.sub(r'#.*$', "", phone)
print("电话号码是: ", num)

# 删除非数字(-)的字符串
num=re.sub(r'\D', "", phone)
print "电话号码是 : ", num
'''


string = 'saljh{da{39812}84}'
pattern = r'\{'
repl = '('
res = re.sub(pattern, repl, string)
pattern = r'\}'
repl = ')'
print(re.sub(pattern, repl, res))
