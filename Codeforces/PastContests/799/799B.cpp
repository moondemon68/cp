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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int p[n+5],a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> p[i];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i]; 
    int m;
    cin >> m;
    priority_queue<int,vector<int>,greater<int>> pq1,pq2,pq3;
    for (int i=1;i<=n;i++) {
        if (a[i]==b[i]) {
            if (a[i]==1) pq1.push(p[i]);
            if (a[i]==2) pq2.push(p[i]);
            if (a[i]==3) pq3.push(p[i]);
        } else {
            if (a[i]==1) pq1.push(p[i]);
            if (a[i]==2) pq2.push(p[i]);
            if (a[i]==3) pq3.push(p[i]);
            if (b[i]==1) pq1.push(p[i]);
            if (b[i]==2) pq2.push(p[i]);
            if (b[i]==3) pq3.push(p[i]);
        }
    }   
    map<int,int> done;
    for (int i=1;i<=m;i++) {
        int x;
        cin >> x;
        if (x==1) {
            if (pq1.empty()) cout << -1 << " ";
            else {
                while (!pq1.empty()&&done[pq1.top()]>0) {
                    done[pq1.top()]--;
                    pq1.pop();
                }
                if (pq1.empty()) {
                    cout << -1 << " ";
                    continue;
                }
                cout << pq1.top() << " ";
                done[pq1.top()]++;
                pq1.pop();
            }
        }
        if (x==2) {
            if (pq2.empty()) cout << -1 << " ";
            else {
                while (!pq2.empty()&&done[pq2.top()]>0) {
                    done[pq2.top()]--;
                    pq2.pop();
                }
                if (pq2.empty()) {
                    cout << -1 << " ";
                    continue;
                }
                cout << pq2.top() << " ";
                done[pq2.top()]++;
                pq2.pop();
            }
        }
        if (x==3) {
            if (pq3.empty()) cout << -1 << " ";
            else {
                while (!pq3.empty()&&done[pq3.top()]>0) {
                    done[pq3.top()]--;
                    pq3.pop();
                }
                if (pq3.empty()) {
                    cout << -1 << " ";
                    continue;
                }
                cout << pq3.top() << " ";
                done[pq3.top()]++;
                pq3.pop();
            }
        }
    }
    return 0;
}
