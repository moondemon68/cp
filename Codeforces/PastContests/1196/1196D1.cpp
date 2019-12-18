#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        string m = "RGB";
        string l = "GBR";
        string t = "BRG";
        string res1="", res2="", res3="";
        int g = k/3;
        for(int i=1;i<=g;i++){
            res1 += m;
            res2 += l;
            res3 += t;
        }
        int yey = k%3;
            res1 = m.substr(0, yey);
            res2 = l.substr(0, yey);
            res3 = t.substr(0, yey);

        int cost= 200000;
        for(int i=0;i<n-k+1;i++){
            int cs1=0;
            for(int j=i;j<i+k;j++){
                if(s[j]!=res1[j-i]){
                    cs1++;
                }
            }
            int cs2=0;
            for(int j=i;j<i+k;j++){
                if(s[j]!=res2[j-i]){
                    cs2++;
                }
            }
            int cs3=0;
            for(int j=i;j<i+k;j++){
                if(s[j]!=res3[j-i]){
                    cs3++;
                }
            }
            cost = min(cost, min(cs1, min(cs2, cs3)));
        }
        cout << cost << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}