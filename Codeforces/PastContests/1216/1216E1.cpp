#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> d;

string s="";

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // vector<int> k;
    // for (int i=1;i<=35000;i++) {
    //     for (int j=1;j<=i;j++) {
    //         k.pb(j);
    //     }
    // }
    d.pb(0);
    for (int i=1;i<=30000;i++) d.pb(d[i-1]+floor(log10(10*i)));
    // int maxi=0;
    // for (int i=0;i<k.size();i++) {
    //     if (k[i]<10) maxi++;
    //     else if (k[i]<100) maxi+=2;
    //     else if (k[i]<1000) maxi+=3;
    //     else if (k[i]<10000) maxi+=4;
    // }
    // for (int i=1;i<=30000;i++) maxi+=d[i];
    // cout << maxi << endl;
    for (int i=1;i<=30000;i++) d[i]+=d[i-1];
    for (int i=1;i<=30000;i++) {
        string t="";
        int x=i;
        while (x>0) {
            t+=(x%10)+'0';
            x/=10;
        }
        reverse(t.begin(),t.end());
        s+=t;
    }
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
        int x;
        cin >> x;
        int p=0;
        for (int j=0;j<=30000;j++) {
            if (x>=d[j]) p=j; else break;
        }
        //cout << p << " ";
        int h = x-d[p];
        if (h == 0) h=d[p]-d[p-1];
        //cout << h << " ";
        cout << s[h-1] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}