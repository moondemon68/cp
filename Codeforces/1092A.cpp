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
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int a[26];
        for (int i=0;i<k;i++) a[i]=n/k;
        for (int i=0;i<k;i++) {
            for (int j=1;j<=a[i];j++) {    
                char x=i+'a';
                cout << x;   
            }
        }
        int rem=n%k;
        for (int i=rem;i>0;i--) {
            char x=k-1+'a';
            cout << x;
        } 
        cout << endl;
    }
    return 0;
}
