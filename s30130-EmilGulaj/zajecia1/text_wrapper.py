import textwrap
import os

print(os.path.exists('s30130-EmilGulaj\zajecia1\instalacja_debian_linux.txt'))


with open('s30130-EmilGulaj\zajecia1\instalacja_debian_linux.txt', 'r+') as file:
    lines = file.readlines()
    i = 0
    for line in lines:
        
            
        print(textwrap.fill(line, width=80))
        