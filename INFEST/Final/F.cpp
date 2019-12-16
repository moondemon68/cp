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

int dp[55][5005][55];

int waysutil(int index, int sum, int count, vector<int>& arr, int K) { 
    if (index < 0) return 0; 
    if (index == 0) { 
        if (count == 0) return 0; 
        int remainder = sum % count; 
        if (remainder != 0) return 0; 
        int average = sum / count; 
        if (average == K) return 1; 
    } 
    if (dp[index][sum][count] != -1) return dp[index][sum][count]; 
    int dontpick = waysutil(index - 1, sum, count, arr, K); 
  
    int pick = waysutil(index - 1,  sum + arr[index], count + 1, arr, K); 
    int total = pick + dontpick; 
    dp[index][sum][count] = total; 
    return total; 
} 
   
int ways(int N, int K, int* arr) 
{ 
    vector<int> Arr; 
    Arr.push_back(-1); 
    for (int i = 0; i < N; ++i) { 
        Arr.push_back(arr[i]); 
    } 
  
    memset(dp, -1, sizeof dp); 
  
    int answer = waysutil(N, 0, 0, Arr, K); 
    return answer; 
} 
  
// Driver code 
int main() 
{ 
    int n, x;
    cin >> n >> x;
    int a[n+5];
    for (int i=0;i<n;i++) cin >> a[i];
    cout << ways(n, x, a) << endl; 
  
    return 0; 
} 