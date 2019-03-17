// Manacher Algorithm
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
    string s;
    while (cin >> s) {
        string t="";
        int d1[100005],d2[100005];
        int l=0,r=-1;
        for (int i=0;i<(int)s.size();i++) {
            int k=0;
            if (i>r) k=1; else k=min(d1[l+r-i],r-i);
            while (i-k>=0&&i+k<(int)s.size()&&s[i-k]==s[i+k]) k++;
            d1[i]=k--;
            if (i+k>r) {
                l=i-k;
                r=i+k;
            }
        }
        l=0,r=-1;
        for (int i=0;i<(int)s.size();i++) {
            int k=0;
            if (i>r) k=0; else k=min(d2[l+r-i+1],r-i+1);
            while (i-k-1>=0&&i+k<(int)s.size()&&s[i-k-1]==s[i+k]) k++;
            d2[i]=k--;
            if (i+k>r) {
                l=i-k-1;
                r=i+k;
            }
        }
        for (int i=0;i<(int)s.size();i++) {
            d1[i]=2*d1[i]-1;
            d2[i]=2*d2[i];
        }
        //for (int i=0;i<(int)s.size();i++) cout << d1[i] << " ";
        //cout << endl;
        //for (int i=0;i<(int)s.size();i++) cout << d2[i] << " ";
        //cout << endl;
        int maxodd=0,add=INT_MAX;
        for (int i=(int)s.size()-1;i>=0;i--) {
            if (d1[i]>maxodd&&(int)s.size()-d1[i]/2-1==i) maxodd=d1[i];
        }
        int maxeven=0;
        for (int i=(int)s.size()-1;i>=0;i--) {
            if (d2[i]>maxeven&&(int)s.size()-d2[i]/2==i) maxeven=d2[i];
        }
        //cout << maxodd << maxeven << endl;
        if (maxodd>maxeven) {
            cout << s;
            for (int i=(int)s.size()-maxodd-1;i>=0;i--) cout << s[i];
            cout << endl;
        } else {
            cout << s;
            for (int i=(int)s.size()-maxeven-1;i>=0;i--) cout << s[i];
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}