from os import system
from time import time
from random import randint

def run(s):
    t0=time()
    if system(s):
        print('error!')
        exit(1)
    t0=time()-t0
    print(f'{t0} s')
    '''
    if t0>1:
        print('continue?')
        input()'''

def gen(fn):
    with open(fn,'w') as f:
        n=randint(1,2000)
        m=randint(1,2000)
        n=m=10000
        C=randint(1,200000)
        B=1
        for i in range(1,n+1):
            if i*i<=n:B=i
        f.write(f'{n}\n')
        f.write(' '.join(str(randint(1,C)) for i in range(n)))
        f.write(f'\n{m}\n')
        for i in range(m):
            d=randint(1,B)
            p1=randint(1,n-d*d+1)
            p2=randint(1,n-d*d+1)
            f.write(f'{d} {p1} {p2}\n')

run('make')
for T in range(100000):
    gen('1.in')
    print(f'--{T}--')
    gen('1.in')
    run('std.exe < 1.in > o1.txt 2>log1.txt')
    run('bf.exe < 1.in > o2.txt  2>log2.txt')
    run('fc o1.txt o2.txt')

