#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
int n,m;
bool valid(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}

int a[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset (a,-1,sizeof (a));
    int p;
    cin >> n >> m >> p;
    int speed[10];
    for (int i=1;i<=p;i++) cin >> speed[i];    
    queue<pii> q[10];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            if (s[j-1]>='0'&&s[j-1]<='9') a[i][j]=s[j-1]-'0'; 
            else if (s[j-1]=='.') a[i][j]=0; 
            else if (s[j-1]=='#') {
                a[i][j]--;
            }
            if (a[i][j]>0) {
                q[a[i][j]].push(mp(i,j));
            }
            //cerr << a[i][j];
        }
    }
    
    for (int i=1;i<=p;i++) q[i].push(mp(-1,-1));
    set<int> done;
    int turn=0;
    while (done.size()<p) {
        turn++;
        if (turn>p) turn-=p;
        if (q[turn].empty()) continue;
        //cerr << turn << endl;
        bool y=1;
        while (y) {
            pii cur=q[turn].front();
            q[turn].pop();
            if (cur.fi==-1) break;
            for (int i=cur.fi+1;i<=cur.fi+speed[turn];i++) {
                if (a[i][cur.se]==0&&valid(i,cur.se)) {
                    a[i][cur.se]=turn;
                    q[turn].push(mp(i,cur.se));
                } else break;
            }
            for (int i=cur.fi-1;i>=cur.fi-speed[turn];i--) {
                if (a[i][cur.se]==0&&valid(i,cur.se)) {
                    a[i][cur.se]=turn;
                    q[turn].push(mp(i,cur.se));
                } else break;
            }

            for (int i=cur.se+1;i<=cur.se+speed[turn];i++) {
                if (a[cur.fi][i]==0&&valid(cur.fi,i)) {
                    a[cur.fi][i]=turn;
                    q[turn].push(mp(cur.fi,i));
                } else break;
            }
            for (int i=cur.se-1;i>=cur.se-speed[turn];i--) {
                if (a[cur.fi][i]==0&&valid(cur.fi,i)) {
                    a[cur.fi][i]=turn;
                    q[turn].push(mp(cur.fi,i));
                } else break;
            }
            q[turn].push(mp(-1,-1));
        }
        //cerr << q[turn].size() << endl;
        if (q[turn].size()==0) done.insert(turn);
        /*
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                cerr << a[i][j];
                if (a[i][j]!=-1) cerr << ' ';
            }
            cerr << endl;
        }
        */
    }
    int cnt[10];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cnt[a[i][j]]++;
    }
    for (int i=1;i<=p;i++) cout << cnt[i] << ' ';
    cout << endl;
    return 0;
}
