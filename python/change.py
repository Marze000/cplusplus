def ChangeInt( a ):
    a = 10
 
b = 2
ChangeInt(b)
print( b ) # 结果是 2

def changeme( mylist ):
    "修改传入的列表"
    mylist.append([1,2,3,4])
    print ("函数内取值: ", mylist)
    return
 
# 调用changeme函数
mylist = [10,20,30]
changeme( mylist )
print ("函数外取值: ", mylist)
def printinfo(name='maze',age = 22):
    print('姓名:',name,end=" ")
    print('年龄:',age)
    return

printinfo(age=50,name='hehe')
printinfo(name='hehe')
printinfo(age=50)
# 如果参数过多，则*代表以元组的形式接受参数
def printinfo(arg1,*vartuilas):
    print(arg1)
    print(vartuilas)

printinfo(10,20,30,40)

# 如果是 ** 代表的是以字典的形式导入
def printinfo( arg1, **vardict ):
   "打印任何传入的参数"
   print ("输出: ")
   print (arg1)
   print (vardict)
 
# 调用printinfo 函数
# printinfo(1, a=2,b=3)

# 如果参数中 '*' 是以单独出现的，则后面的参数必须用关键字传入
def f(a,b,*,c):
    return a+b+c

a = f(10,20,c =30)
print(a)

# lambda 表达式
# ambda 只是一个表达式，函数体比 def 简单很多。
# lambda的主体是一个表达式，而不是一个代码块。
# 仅仅能在lambda表达式中封装有限的逻辑进去。
# lambda 函数拥有自己的命名空间，
# 且不能访问自己参数列表之外或全局命名空间里的参数。
# 虽然lambda函数看起来只能写一行，
# 却不等同于C或C++的内联函数，
# 后者的目的是调用小函数时不占用栈内存从而增加运行效率。
sum = lambda arg1, arg2:arg1 + arg2
 
# 调用sum函数
print ("相加后的值为 : ", sum( 10, 20 ))
print ("相加后的值为 : ", sum( 20, 20 ))

list.append(7)
print(list)

a = [1,2,3]
list.extend(a)
print(list)

list.insert(0,100)
list.insert(len(list),900)
print(list)

list.remove(1)
print(list)
list = [1,2,3,4,5,6]
print(list)
a = list.pop(0) # 弹出下标为 0 的元素
print(a)
list.clear() # 清空列表所有元素 del list[:]
print(list)
'''

list = [1,2,3,4,5,3,4,5,6,7,8,4,3,2,3,4,6]
list.reverse()
ll = list.copy()
for x in ll:
    print(x,end=" ")
for x in list:
    print(x,end=" ")
print('\n')
ll = list.sort()
for x in list:
    print(x ,end=" ")

print('\n')
x = 0
maxsum = max(list)
ll = set(list)
for x in ll:  
    if x < maxsum:
        print(x,'出现了',list.count(x),'次')

'''