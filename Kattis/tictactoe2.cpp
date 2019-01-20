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
    int tc;
    cin >> tc;
    while (tc--) {
        char a[4][4];
        for (int i=1;i<=3;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=3;j++) {
                a[i][j]=s[j-1];
            }
        }
        int o=0,x=0;
        for (int i=1;i<=3;i++) {
            for (int j=1;j<=3;j++) {
                if (a[i][j]=='O') o++;
                if (a[i][j]=='X') x++;
            }
        }
        if (!((x-o)>=0&&(x-o)<=1)) {
            cout << "no" << endl; 
            continue;
        }
        int wins=0,xwin=0,owin=0;
        if (a[1][1]==a[1][2]&&a[1][2]==a[1][3]&&a[1][1]!='.') {
            wins++;
            if (a[1][1]=='X') xwin=1; else owin=1;
        }
        if (a[2][1]==a[2][2]&&a[2][2]==a[2][3]&&a[2][1]!='.') {
            wins++;
            if (a[2][1]=='X') xwin=1; else owin=1;
        }
        if (a[3][1]==a[3][2]&&a[3][2]==a[3][3]&&a[3][1]!='.') {
            wins++;
            if (a[3][1]=='X') xwin=1; else owin=1;
        }
        for (int i=1;i<=3;i++) {
            if (a[1][i]==a[2][i]&&a[2][i]==a[3][i]&&a[1][i]!='.') {
                wins++;
                if (a[1][i]=='X') xwin=1; else owin=1;
            }
        }
        if (a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[1][1]!='.') {
            wins++;
            if (a[1][1]=='X') xwin=1; else owin=1;
        }
        if (a[3][1]==a[2][2]&&a[2][2]==a[1][3]&&a[3][1]!='.') {
            wins++;
            if (a[3][1]=='X') xwin=1; else owin=1;
        }
        if (xwin==1&&owin==1) {
            cout << "no" << endl;
            continue;
        }
        if (owin==1&&x!=o) {
            cout << "no" << endl;
            continue;
        }
        if (xwin==1&&x==o) {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
    }    
    return 0;
}
