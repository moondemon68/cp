#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

ofstream fout("output.out");
ifstream fin("input.in");

int r,c;
string a[105];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,-1,-1,-1,0,1,1,1};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    fin >> tc;
    for (int t=1;t<=tc;t++) {
        fin >> r >> c;
        for (int i=0;i<r;i++) {
            string s;
            fin >> s;
            a[i]=s;
        }
        string s;
        fin >> s;
        int ans=0;
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                for (int p=0;p<8;p++) {
                    for (int k=0;k<s.size();k++) {
                        int nx=i+dx[p]*k,ny=j+dy[p]*k;
                        if (nx<0||nx>=r||ny<0||ny>=c) break;
                        if (a[nx][ny]!=s[k]) break;
                        if (k==s.size()-1) ans++;
                    }
                }
            }
        }
        fout << "Case " << t <<": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}