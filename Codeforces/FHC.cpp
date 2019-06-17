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
ofstream fout("leapfrog3.out");
ifstream fin("leapfrog2.txt");
int main () {
    //clock_t start = clock();
    int tc;
    fin >> tc;
    for (int t=1;t<=tc;t++) {
        string s;
        fin >> s;
        int cnt=0;
        int p=s.size();
        for (int i=0;i<s.size();i++) {
            if (s[i]=='B') cnt++;
        }
        if (cnt+1<p&&cnt>=p/2) fout << "Case #" << t << ": " << "Y" << endl;
        else fout << "Case #" << t << ": " << "N" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}