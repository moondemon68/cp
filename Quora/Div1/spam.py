train, test = map(int, input().split())
X = []
y = []
TX = []
maxlen = 200
for i in range(train):
    x = input().split(' ')
    tx = []
    for j in range(len(x)):
        x[j] = x[j].split(':')
        tx.append(int(x[j][1]))
        x[j] = int(x[j][0])
    X.append(x)
    TX.append(tx)
    maxlen = max(maxlen, len(x))
for i in range(train):
    y.append(int(input()))

# padding
for i in range(train):
    while len(X[i]) < maxlen:
        X[i].append(X[i][-1])
        TX[i].append(TX[i][-1])

# for i in range(train):
#     print(X[i], TX[i])

from sklearn import tree

clf = tree.DecisionTreeClassifier()
clf = clf.fit(X, y)
clf2 = tree.DecisionTreeClassifier(random_state=12413)
clf2 = clf2.fit(TX, y)
# print(tree.plot_tree(clf))

test_X = []
test_TX = []

for i in range(test):
    x = input().split(' ')
    tx = []
    for j in range(len(x)):
        x[j] = x[j].split(':')
        tx.append(int(x[j][1]))
        x[j] = int(x[j][0])
    while len(x) < maxlen:
        x.append(0)
        tx.append(tx[-1])
    test_X.append(x)
    test_TX.append(tx)

ans = clf.predict(test_X)
# for x in ans:
#     print(x)

ans2 = clf2.predict(test_TX)
for i in range(len(ans)):
    if ans2[i] > 0:
        print(1)
    else:
        print(0)