import re

tc = int(input())
for t in range(1, tc+1):
    print('Case ', t, ':', sep='')
    n, q = map(int, input().split())
    a = []
    for i in range(n):
        s = input()
        s = s.replace(' ','.')
        a.append('.' + s + '.')
    for i in range(q):
        s = input()
        s = '.' + s.replace(' ','.') + '.'
        cnt = 0
        for j in a:
            print(s, j, re.search(r'\b' + s + r'\b', j))
            if re.search(r'\b' + s + r'\b', j):
                cnt = cnt + 1
        print(cnt)

# import re
# t = int(input())
# for yey in range(t):
#     print("Case " + str(yey + 1) + ":")
#     n, q = map(int, input().split())

#     a = ""
#     for b in range(n):
#         a += ". "
#         a += input()
#         a += " ."

#     for c in range(q):
#         te = input()

#         regex = re.findall(" " + te + " ", a)
#         print(len(regex))