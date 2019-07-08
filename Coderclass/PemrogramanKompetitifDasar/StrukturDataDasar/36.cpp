//Menghitung Median
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    priority_queue<LL,vector<LL>,greater<LL>> p;
    priority_queue<LL> q;
    p.push(12345678900);
    q.push(-12345678900);
    for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        if (x>=p.top()) p.push(x); else q.push(x);
        if (p.size()==q.size()+2) {
            q.push(p.top());
            p.pop();
        } else if (p.size()+2==q.size()) {
            p.push(q.top());
            q.pop();
        }
        if (p.size()==q.size()) {
            LL y=p.top()+q.top();
            if (y%2==0) cout << y/2 << endl;
            else cout << y/2 << ".5" << endl;
        }
        else if (p.size()>q.size()) cout << p.top() << endl;
        else cout << q.top() << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}