#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int main() {
    int tc;
    cin >> tc;
    int dy1[]={0,-1,0,1};
    int dx1[]={1,0,-1,0};
    int dy2[]={-1,-1,1,1};
    int dx2[]={1,-1,-1,1};
    int dy3[]={0,-1,-1,-1,0,1,1,1};
    int dx3[]={1,1,0,-1,-1,-1,0,1};
    while (tc--) {
        int r,c;
        cin >> c >> r;
        bool a[r+5][c+5];
        for (int i=1;i<=r;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=c;j++) {
                a[i][j]=s[j-1]-'0';
            }
        }
        bool b[r+5][c+5];
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                b[i][j]=a[i][j];
            }
        }
        int ans=0;
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                if (b[i][j]) {
                    ans++;
                    stack<pii> s;
                    s.push(mp(i,j));
                    b[i][j]=0;
                    while (!s.empty()) {
                        pii cur = s.top();
                        s.pop();
                        for (int k=0;k<4;k++) {
                            pii next = mp(cur.fi+dx1[k],cur.se+dy1[k]);
                            if (next.fi>=1 && next.fi<=r && next.se >=1 && next.se <=c && b[next.fi][next.se]) {
                                b[next.fi][next.se]=0;
                                s.push(next);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << " ";
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                b[i][j]=a[i][j];
            }
        }
        ans=0;
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                if (b[i][j]) {
                    ans++;
                    stack<pii> s;
                    s.push(mp(i,j));
                    b[i][j]=0;
                    while (!s.empty()) {
                        pii cur = s.top();
                        s.pop();
                        for (int k=0;k<4;k++) {
                            pii next = mp(cur.fi+dx2[k],cur.se+dy2[k]);
                            if (next.fi>=1 && next.fi<=r && next.se >=1 && next.se <=c && b[next.fi][next.se]) {
                                b[next.fi][next.se]=0;
                                s.push(next);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << " ";
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                b[i][j]=a[i][j];
            }
        }
        ans=0;
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                if (b[i][j]) {
                    ans++;
                    stack<pii> s;
                    s.push(mp(i,j));
                    b[i][j]=0;
                    while (!s.empty()) {
                        pii cur = s.top();
                        s.pop();
                        for (int k=0;k<8;k++) {
                            pii next = mp(cur.fi+dx3[k],cur.se+dy3[k]);
                            if (next.fi>=1 && next.fi<=r && next.se >=1 && next.se <=c && b[next.fi][next.se]) {
                                b[next.fi][next.se]=0;
                                s.push(next);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}