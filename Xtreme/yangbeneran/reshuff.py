from itertools import permutations


def construct(cnt, arr):
    s = ""
    for a in arr:
        s += cnt[a] * a
    return s


def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)


n = int(input())
for _ in range(n):
    string = input()
    mn = len(string)
    cnt = {}
    for s in string:
        try:
            cnt[s] += 1
        except KeyError:
            cnt[s] = 1
    arrange = permutations(cnt.keys())
    x = len(cnt)
    found = False
    for i in range(fact(x - 1)):
        arr = next(arrange)
        test = construct(cnt, arr)
        #print(test)
        y = len(test)
        dd = 123456789
        for shift in range(y):
            wrong = 0
            for i in range(y):
                if(test[(i + shift) % y] != string[i]):
                    wrong += 1
                if wrong >= mn:
                    break
            
            dd = min(dd, wrong)
            mn = min(mn, wrong)
            if mn == 0:
                found = True
                break
        #print(dd)
        if found:
            break
        
        for shift in range(y):
            wrong = 0
            for i in range(y):
                if(test[(i + shift) % y] != string[i]):
                    wrong += 1
                if wrong >= mn:
                    break
            
            dd = min(dd, wrong)
            if (wrong<=mn):
                print(shift)
            mn = min(mn, wrong)
    print(mn)
