import random
import subprocess
from IPython import embed

no = 0

cont = True
while cont:
    no += 1
    print("case {}".format(no))

    with open('f.in', 'w') as f:
        n = random.randint(1, 8)
        m = random.randint(1, 8)

        print("{} {}".format(n, m), file = f)
        for i in range(1, m + 1):
            a = random.randint(0, n + 1)
            print(a, end = '\n' if i == m else ' ', file = f)
    
    # print('generation finished')

    # embed()
    inf = open('f.in', 'r')
    sof = open('std.out', 'w')
    subprocess.run(["./std.exe"], stdin = inf, stdout = sof)
    inf.close()
    sof.close()

    # print('std finished')

    inf = open('f.in', 'r')
    dof = open('dfs.out', 'w')
    subprocess.run(["./dfs.exe"], stdin = inf, stdout = dof)
    inf.close()
    dof.close()

    # print('dfs finished')

    cont = True

    sif = open('std.out', 'r')
    sre = sif.readline()
    dif = open('dfs.out', 'r')
    dre = dif.readline()

    if sre != dre:
        print("std.exe outputs {}, but dfs.exe outputs {}".format(dre, sre))
        cont = False
    
    def check_board(f, p):
        board = []
        for i in range(n):
            line = f.readline()
            board.append(line)

        print('check_board:\n', board, sep = '')
        
        for i in range(n):
            for j in range(1, m):
                if board[i][j - 1] == '1' and board[i][j] == '1':
                    cont = False
                    print('Adjacent chesses at ({}, {}) and ({}, {})'.format(i, j - 1, i, j))
        for i in range(1, n):
            for j in range(m):
                if board[i - 1][j] == '1' and board[i][j] == '1':
                    cont = False
                    print('Adjacent chesses at ({}, {}) and ({}, {})'.format(i - 1, j, i, j))

    if sre == dre and sre.startswith('Yes'):
        check_board(sif, 'std.exe')
        check_board(dif, 'dfs.exe')

    sif.close()
    dif.close()