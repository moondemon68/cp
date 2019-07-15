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
    ifstream fin("rekreasi_4.in");
    ofstream fout("rekreasi_4.ou");
    int r,c;
    fin >> r >> c;
    fout << r << " " << c << endl;
    string s;
    fin >> s;
    char a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        string str;
        fin >> str;
        for (int j=1;j<=c;j++) {
            a[i][j]=str[j-1];
        }
    }
    bool vis[r+5][c+5];
    memset (vis,0,sizeof(vis));
    vis[1][1]=1;
    stack<pii> st;
    st.push(mp(1,1));
    while (!st.empty()) {
        pii cur=st.top();
        st.pop();
        pii next1=mp(cur.fi+1,cur.se),next2=mp(cur.fi,cur.se+1);
        if (next1.fi<=r&&next1.se<=c&&!vis[next1.fi][next1.se]&&a[next1.fi][next1.se]!='#'&&a[next1.fi][next1.se]!='x') {
            vis[next1.fi][next1.se]=1;
            a[next1.fi][next1.se]='o';
            st.push(next1);
        }
        if (next2.fi<=r&&next2.se<=c&&!vis[next2.fi][next2.se]&&a[next2.fi][next2.se]!='#'&&a[next2.fi][next2.se]!='x') {
            vis[next2.fi][next2.se]=1;
            a[next2.fi][next2.se]='o';
            st.push(next2);
        }
    }
    int p=1,q=1;
    a[1][1]='_';
    for (int i=0;i<s.size();i++) {
        if (s[i]=='v') p++; else q++;
        a[p][q]='_';
    }
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (a[i][j]=='_') {
                if (a[i-1][j]=='.') a[i-1][j]='x';
                if (a[i+1][j]=='.') a[i+1][j]='x';
            }
        }
    }
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (a[i][j]=='x') {
                if (a[i+1][j]=='#') a[i][j]='.';
            }
        }
    }
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            fout << a[i][j];
        }
        fout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}