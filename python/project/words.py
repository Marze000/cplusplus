p = '''
I heard the echo, from the valleys and the heart
Open to the lonely soul of sickle harvesting
Repeat outrightly, but also repeat the well-being of
Eventually swaying in the desert oasis
I believe I am Born as the bright summer flowers
Do not withered undefeated fiery demon rule
Heart rate and breathing to bear the load of the cumbersome
Bored
'''

# 统计一段文章中出现的单词个数
lines = p.strip().split('\n')
words_cnt = {}
for line in lines:
    line = line.replace(',', '').lower()
    words = line.split(' ')
    for word in words:
        words_cnt[word] = words_cnt.get(word, 0) + 1

words_lst = list(zip(words_cnt.values(), words_cnt.keys()))
words_lst.sort()
words_lst.reverse()
for word in words_lst:
    print(word[1], words_cnt[word[1]])
