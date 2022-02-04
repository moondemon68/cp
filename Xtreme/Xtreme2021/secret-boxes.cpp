#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

map<pii,int> m;
map<pair<pii,pii>, char> cache;
set<pii> sudah;
int tc, n;
int query = 0;

void tanya(int i, int j) {
    int x = 0;
    for (int k=1;k<=n;k++) {
        for (int l=k+1;l<=n;l++) {
            if (i == k || i == l || j == k || j == l) continue;
            char c;
            if (cache.count({{min(i, j), max(i, j)}, {min(k, l), max(k, l)}})) c = cache[{{min(i, j), max(i, j)}, {min(k, l), max(k, l)}}];
            else {
                query++;
                cout << "? " << i << " " << j << " " << k << " " << l << endl;
                cin >> c;
                // TESTING, ASUMSI 12345...N
                // if ((i+j) > (k+l)) c = '>';
                // if ((i+j) == (k+l)) c = '=';
                // if ((i+j) < (k+l)) c = '<';
                cache[{{min(i, j), max(i, j)}, {min(k, l), max(k, l)}}] = c;
                if (c == '>') cache[{{min(k, l), max(k, l)}, {min(i, j), max(i, j)}}] = '<';
                if (c == '=') cache[{{min(k, l), max(k, l)}, {min(i, j), max(i, j)}}] = '=';
                if (c == '<') cache[{{min(k, l), max(k, l)}, {min(i, j), max(i, j)}}] = '>';
            }
            if (c == '>') x++;
            else if (c == '<') x--;
        }
    }
    m[{i, j}] = x;
    m[{j, i}] = x;
    sudah.insert({i, j});
    sudah.insert({j, i});
}

bool tanya2(int a, int i, int b) {
    for (int k=1;k<=n;k++) {
        for (int l=k+1;l<=n;l++) {
            if (a == k || a == l || b == k || b == l || i == k || i == l) continue;
            // cout << k << " " << l << endl;
            char c1, c2;
            cout << "? " << a << " " << i << " " << k << " " << l << endl;
            // if ((a+i) > (k+l)) c1 = '>';
            // if ((a+i) == (k+l)) c1 = '=';
            // if ((a+i) < (k+l)) c1 = '<';
            cin >> c1;
            cout << "? " << i << " " << b << " " << k << " " << l << endl;
            // if ((i+b) > (k+l)) c2 = '>';
            // if ((i+b) == (k+l)) c2 = '=';
            // if ((i+b) < (k+l)) c2 = '<';
            cin >> c2;
            int x1 = 0;
            int x2 = 0;
            if (c1 == '>') x1 = 1;
            if (c1 == '=') x1 = 0;
            if (c1 == '<') x1 = -1;
            if (c2 == '>') x2 = 1;
            if (c2 == '=') x2 = 0;
            if (c2 == '<') x2 = -1;
            query += 2;
            // cout << "EUY " << x1 << " " << x2 << " " << (x1 == x2) << endl;
            if (x1 == x2) continue;
            else {
                // cout << a << " " << i << " " << b << " " << k << " " << l << " " << query << endl;
                return x1 < x2;
            }
        }
    }
    // cout << a << " " << i << " " << b << " " << query << endl;
    return 0;
}

bool tanya3(int a, int i, int b) {
    while (true) {
        int k = rand() % n + 1;
        int l = rand() % n + 1;
        if (a == k || a == l || b == k || b == l || i == k || i == l) continue;
        // cout << k << " " << l << endl;
        char c1, c2;
        cout << "? " << a << " " << i << " " << k << " " << l << endl;
        // if ((a+i) > (k+l)) c1 = '>';
        // if ((a+i) == (k+l)) c1 = '=';
        // if ((a+i) < (k+l)) c1 = '<';
        cin >> c1;
        cout << "? " << i << " " << b << " " << k << " " << l << endl;
        // if ((i+b) > (k+l)) c2 = '>';
        // if ((i+b) == (k+l)) c2 = '=';
        // if ((i+b) < (k+l)) c2 = '<';
        cin >> c2;
        int x1 = 0;
        int x2 = 0;
        if (c1 == '>') x1 = 1;
        if (c1 == '=') x1 = 0;
        if (c1 == '<') x1 = -1;
        if (c2 == '>') x2 = 1;
        if (c2 == '=') x2 = 0;
        if (c2 == '<') x2 = -1;
        query += 2;
        // cout << "EUY " << x1 << " " << x2 << " " << (x1 == x2) << endl;
        if (x1 == x2) continue;
        else return x1 < x2;
    }
    return 0;
}

bool cmp(int a, int b) {
    // cout << a << ' ' << b << endl;
    if (n < 40) {
        for (int i=1;i<=n;i++) {
            if (a != i && b != i) {
                if (sudah.find({a, i}) == sudah.end()) tanya(a, i);
                if (sudah.find({i, b}) == sudah.end()) tanya(i, b);
                if (m[{a, i}] == m[{i, b}]) continue;
                // cout << i << " " << a << " " << b << " " << m[{a, i}] << " " << m[{i, b}] << " " << (m[{a, i}] < m[{i, b}]) << endl;
                return m[{a, i}] < m[{i, b}];
            }
        }
    } else if (n == 40) {
        for (int i=1;i<=n;i++) {
            if (a != i && b != i) {
                return tanya2(a, i, b);
            }
        }
    } else {
        return tanya3(a, b);
    }
}

int main () {
    //clock_t start = clock();
    srand(time(NULL));
    cin >> tc >> n;
    while (tc--) {
        m.clear();
        sudah.clear();
        cache.clear();
        int a[n+5];
        for (int i=1;i<=n;i++) a[i] = i;
        sort(a+1, a+n+1, cmp);

        int ans[n+5];
        for (int i=1;i<=n;i++) {
            ans[a[i]] = i;
        }
        cout << "! ";
        for (int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << endl;
        string verdict;
        cin >> verdict;
        cerr << query << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}