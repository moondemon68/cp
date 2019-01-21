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
    //ofstream cout ("test.out");
    int n;
    while (cin >> n) {
        if (n==0) return 0;
        vector<int> a;
        for (int i=1;i<=n;i++) {    
            char s;
            int h,m;
            scanf("%d:%d %c.m.",&h,&m,&s);
            int x=h*60+m;
            if (s=='p') x+=720;
            if (h==12&&m==0&&s=='a') x=0;
            if (h==12&&m==0&&s=='p') x=720;
            a.pb(x);
        }
        sort (a.begin(),a.end());
        for (int i=1;i<=n;i++) {
            int x=a[i-1];
            if (x==0) cout << "12:00 a.m.";
            else if (x==720) cout << "12:00 p.m.";
            else if (x>720) {
                x-=720;
                cout << x/60 << ":";
                if (x%60<10) cout  << "0" << x%60 << " p.m.";
                else cout << x%60 << " p.m.";
            } else {
                cout << x/60 << ":";
                if (x%60<10) cout  << "0" << x%60 << " a.m.";
                else cout << x%60 << " a.m.";
            }
            cout << endl;
        }
        cout << endl;
    }    
    cout << endl;
    return 0;
}
