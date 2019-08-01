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

int tc;
int n,k;

void add(int x, int val, vector<int> bit[]){
    for(;x<=n;x+=x&-x){
        bit[x].push_back(val);
    }
}

int query(int x, int val, vector<int> bit[]){
    for(;x>0;x-=x&-x){

    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        vector<int> bit[n+3];
        vector<int> a(n+3);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            add(i,a[i],bit);
        }
        for(int i=1;i<=n;i++)sort(bit[i].begin(),bit[i].end()); 
        for(int i=1;i<=n;i++){
            cout << i << '\n';
            for(auto e:bit[i]){
                cout << e << " ";
            }cout << '\n';
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}