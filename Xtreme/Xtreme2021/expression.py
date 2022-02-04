MOD = 1000000007
art = "+-*"
bart = "()+-*"
tc = int(input())
for t in range(tc):
    s = input()
    try:
        if not ((s[0] >= '0' and s[0] <= '9') or s[0] == '(' or s[0] == ')'):
            print(1/0)
        for i in range(0, len(s) - 1):
            if s[i] in art and s[i+1] in art:
                print(1/0)
            if s[i] == '(' and s[i+1] in art:
                print(1/0)
        ans = eval(s)
        ans %= MOD
        ans += MOD
        ans %= MOD
        print(ans)
    except:
        print("invalid")