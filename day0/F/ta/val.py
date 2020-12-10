for i in range(1, 21):
    with open('data/' + str(i) + '.in', 'r') as f:
        n, m = list(map(lambda s: int(s), f.readline().split(' ')))
        assert n >= 1 and n <= 300
        assert m >= 1 and m <= 300

        a = list(map(lambda s: int(s), f.readline().split(' ')))
        assert len(a) == m
        for j in range(len(a)):
            assert a[j] >= 0 and a[j] <= n
