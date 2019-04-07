    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    #define ff first
    #define ss second
    #define pii pair<int, int>
    #define pll pair<long long, long long>
     
    long long poss[5], mini, dp[200005];
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);	
    	cout.tie(NULL);
     
    	for(int i=0; i<=4; ++i) poss[i]=-1;
    	mini = -1;
    	string s,s1;
    	cin >> s;
     
    	for(int i=0; i<s.length(); ++i){
    		if(s[i]=='a') poss[0]=i; 
    		if(s[i]=='e') poss[1]=i; 
    		if(s[i]=='i') poss[2]=i; 
    		if(s[i]=='o') poss[3]=i; 
    		if(s[i]=='u') poss[4]=i; 
     
    		mini = min(poss[0],min(poss[1],min(poss[2],min(poss[3],poss[4]))));
     
    		dp[i] = dp[i-1]+mini+1;
     
    	}
     
    	cout << dp[s.length()-1];
     
     
    }