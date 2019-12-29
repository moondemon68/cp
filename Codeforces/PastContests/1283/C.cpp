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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    bool b[n+5];
    memset (b,0,sizeof(b));
    int cnt[n+5];
    memset (cnt,0,sizeof(cnt));
    queue<int> q;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        if (a[i] != 0) b[a[i]] = 1;
        else {
            q.push(i);
            // cout << i << " ";
            cnt[i]++;
        }
    }
    // cout << endl;
    queue<int> p;
    for (int i=1;i<=n;i++) {
        if (!b[i]) {
            p.push(i);
            // cout << i << " ";
            cnt[i]++;
        }
    }
    // cout << endl;
    queue<int> onep, two, oneq;
    while (!q.empty()) {
        if (cnt[q.front()] == 1) oneq.push(q.front());
        else if (cnt[q.front()] == 2) two.push(q.front());
        q.pop();
    }
    while (!p.empty()) {
        if (cnt[p.front()] == 1) onep.push(p.front());
        p.pop();
    }
    if (two.size() != 1) {
        vector<int> p;
        while (!two.empty()) {
            p.pb(two.front());
            two.pop();
        }
        for (int i=0;i<p.size();i++) {
            a[p[i]] = p[(i+1)%p.size()];
        }
        while (!oneq.empty()) {
            a[oneq.front()] = onep.front();
            oneq.pop();
            onep.pop();
        }
    } else {
        a[oneq.front()] = two.front();
        oneq.pop();
        while (!oneq.empty()) {
            a[oneq.front()] = onep.front();
            oneq.pop();
            onep.pop();
        }
        a[two.front()] = onep.front();
    }
    
    // for (int i=1;i<=n;i++) cout << cnt[i] << " ";
    // cout << endl;
    for (int i=1;i<=n;i++) cout << a[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}