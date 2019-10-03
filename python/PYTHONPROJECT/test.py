import os.path as path
import os

p = 'd:/qq'
for base,_,file in os.walk(p):
    for f in file:
        print(base + f)