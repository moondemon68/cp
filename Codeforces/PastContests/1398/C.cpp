#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n;
        cin >> n;
        string s;
        cin >> s;
        LL a[n+5];
        memset (a,0,sizeof(a));
        for (LL i=0;i<s.size();i++) {
            a[i] = s[i]-'0'-1;
        }
        unordered_map<LL, LL> prevSum; 
  
        LL res = 0; 
    
        // Sum of elements so far. 
        LL currsum = 0; 
    
        for (LL i = 0; i < n; i++) { 
    
            // Add current element to sum so far. 
            currsum += a[i]; 
    
            // If currsum is equal to desired sum, 
            // then a new subarray is found. So 
            // increase count of subarrays. 
            if (currsum == 0)  
                res++;         
    
            // currsum exceeds given sum by currsum  
            //  - sum. Find number of subarrays having  
            // this sum and exclude those subarrays 
            // from currsum by increasing count by  
            // same amount. 
            if (prevSum.find(currsum - 0) !=  
                                    prevSum.end())  
                res += (prevSum[currsum - 0]); 
            
    
            // Add currsum value to count of  
            // different values of sum. 
            prevSum[currsum]++; 
        } 
    
        cout << res << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}