#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n) {
        int s=1,pq=1,q=1,g=1;
        stack<int> st;
        priority_queue<int> p;
        queue<int> qu;
        for (int i=1;i<=n;i++) {
            int x,y;
            cin >> x >> y;
            if (x==1) {
                st.push(y);
                p.push(y);
                qu.push(y);
            } else {
                if (st.empty()||p.empty()||qu.empty()||g==0) {
                    g=0;
                    continue;
                }
                if (st.top()!=y) s=0;
                if (p.top()!=y) pq=0;
                if (qu.front()!=y) q=0;
                st.pop();
                p.pop();
                qu.pop();
            }
        }
        if (g==0) cout << "impossible"; 
        else if (s+pq+q>1) cout << "not sure";
        else if (s+pq+q==0) cout << "impossible";
        else if (s==1) cout << "stack";
        else if (q==1) cout << "queue";
        else cout << "priority queue";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}