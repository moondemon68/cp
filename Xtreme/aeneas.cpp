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
    double r;
    cin >> r;
    double a[35];
    for (int i=1;i<=26;i++) {
        char c;
        cin >> c;
        double x;
        cin >> x;
        a[c-'A']=x;
    }
    string s;
    cin.ignore(256,'\n');
    getline(cin,s);
    double ans=0;
    char prev='0';
    for (int i=0;i<s.size();i++) {
        if (s[i]>='A' && s[i]<='Z') {
            if (ans==0) {
                ans+=r;
                prev = s[i];
                continue;
            }
            char now = s[i];
            double ang = a[now-'A']-a[prev-'A'];
            ans += sqrt(2*r*r*(1-cos(ang*acos(-1)/180)));
            prev = now;
        } else if (s[i]>='a' && s[i]<='z') {
            s[i]-=32;
            if (ans==0) {
                ans+=r;
                prev = s[i];
                continue;
            }
            char now = s[i];
            double ang = a[now-'A']-a[prev-'A'];
            ans += sqrt(2*r*r*(1-cos(ang*acos(-1)/180)));
            prev = now;
        }
    }
    cout << ceil(ans) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}