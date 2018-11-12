#include <bits/stdc++.h>

using namespace std;

int main () {
	int score[30];
	bool prob[30];
	memset (prob,0,sizeof(prob));
	memset (score,0,sizeof(score));
	int n;
	char p;
	string v;			//time, problem, verdict
	while (1>0) {
		cin >> n;
		if (n==-1) break;
		cin >> p >> v;
		if (v=="right") {
			if (prob[p-'A'+1]) continue;
			prob[p-'A'+1]=1;
			score[p-'A'+1]+=n;
		} else {
			score[p-'A'+1]+=20;
		}
	}
	int cnt=0,ans=0;
	for (int i=1;i<=26;i++) {
		if (prob[i]) {
			cnt++;
			ans+=score[i];
		}
	}
	cout << cnt << " " << ans << endl;
	return 0;
}
