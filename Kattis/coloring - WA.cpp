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
    vector<int> adj[15];
    int c[15];
    memset (c,0,sizeof(c));
    cin.ignore();
    for (int i=0;i<n;i++) {
        string s;
        getline(cin,s);
        s+=' ';
        int num=0;
        for (int j=0;j<s.size();j++) {
            if (s[j]==' ') {
                adj[i].pb(num/10);
                num=0;
            }
            else {
                num+=s[j]-'0';
                num*=10;
            }
        }
    }   
    int realans=INT_MAX; 
    for (int i=0;i<n;i++) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur=q.front();
            q.pop();
            set<int> a;
            for (int j=0;j<adj[cur].size();j++) {
                a.insert(c[adj[cur][j]]);
                if (c[adj[cur][j]]==0) q.push(adj[cur][j]);
            }
            for (int k=1;k<=15;k++) {
                if (a.count(k)==0) {
                    c[cur]=k;
                    break;
                }
            }
        }
        int ans=0;
        for (int j=0;j<n;j++) ans=max(ans,c[j]);
        realans=min(realans,ans);
    }
    
    int ans=0;
    for (int i=0;i<n;i++) {
        //cout << c[i] << " ";
        ans=max(ans,c[i]);
    }
    cout << ans << endl;
    return 0;
}
