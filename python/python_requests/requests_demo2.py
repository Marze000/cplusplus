import requests

# https://www.lagou.com/jobs/positionAjax.json?gj=10%E5%B9%B4%E4%BB%A5%E4%B8%8A&px=default&city=%E5%8C%97%E4%BA%AC&needAddtionalResult=false
headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36',
    'Referer': 'https://www.lagou.com/jobs/list_Python/p-city_2?px=default&gj=10%E5%B9%B4%E4%BB%A5%E4%B8%8A',
}
data = {
    'first': 'true',
    'pn': 1,
    'kd': 'Python'
}
response = requests.post('https://www.lagou.com/jobs/positionAjax.json?gj=10%E5%B9%B4%E4%BB%A5%E4%B8%8A&px=default&city=%E5%8C%97%E4%BA%AC&needAddtionalResult=false',
    headers=headers,data = data)

print(response.json())