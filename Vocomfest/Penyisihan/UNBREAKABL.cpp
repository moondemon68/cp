#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long, long long>
    
ll A[105], B[105];
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
    cout.tie(NULL);
    
    ll T,N,x,maks;
    bool may, fix;
    cin >> T;
    ll banyak = T;
    while(T--){
        may = false;
        fix = false;
        maks = 0;
    
        for(int i=0; i<=100; ++i){
            A[i]=0; B[i]=0;
        }
    
        cin >> N;
        for(int i=1; i<=N; ++i){
            cin >> x;
            ++A[x];
        }
        for(int i=1; i<=N; ++i){
            cin >> x;
            ++B[x];
        }
    
        for(int i=0; i<=100; ++i){
            if(A[i]+B[i] > maks) maks = A[i]+B[i];
            if(A[i]>0 && B[i]>0) may = true;
        }
    
        if(maks > N) fix = true;
    
        if (fix) {cout << "Case #" << banyak-T << ": EXIST" <<"\n";}
        else if (may) {cout << "Case #" << banyak-T << ": MAY EXIST" <<"\n";}
        else {cout << "Case #" << banyak-T << ": NOT EXIST" <<"\n";}
    
    }
}