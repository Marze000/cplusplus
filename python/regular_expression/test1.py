import re

pattern = re.compile(ur'^[0-9]*$')
str = u''
print(pattern.search(str))