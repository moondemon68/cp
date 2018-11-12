#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		cout << n << " ";
		int x,y;
		scanf("%d/%d",&x,&y);
		string ans="";
		while (x!=1||y!=1) {
			int s=max(x,y);
			if (s==x) {
				ans+="R";
				x-=min(x,y);
			} else {
				ans+="L";
				y-=min(x,y);
			}
		}
		int a=1;
		if (ans=="") {
			cout << 1 << endl;
			continue;
		} else {
			for (int i=ans.size()-1;i>=0;i--) {
				if (ans[i]=='L') a*=2; else a=a*2+1;
			}
		}
		cout << a << endl;
	}
	return 0;
}
