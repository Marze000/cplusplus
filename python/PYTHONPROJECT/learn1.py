import sys  # 引入 sys 模块
list=[1,2,3,4]
it = iter(list) # 创建迭代器对象
 
while True:
    try:
        print (next(it))
    # 迭代器到了最后面的时候会引发错误，会被捕获到
    except StopIteration:
        sys.exit(0)