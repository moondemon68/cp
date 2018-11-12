#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	double sum=0,avg=0;
	int cnt=0;
	for (int i=a;i<=b;i++) {
		for (int j=c;j<=d;j++) {
			sum+=i+j;
			cnt++;
		}
	}
	avg=sum/cnt;
	int a1,b1,c1,d1;
	cin >> a1 >> b1 >> c1 >> d1;
	double sum1=0,avg1=0;
	int cnt1=0;
	for (int i=a1;i<=b1;i++) {
		for (int j=c1;j<=d1;j++) {
			sum1+=i+j;
			cnt1++;
		}
	}
	avg1=sum1/cnt1;
	if (avg==avg1) cout << "Tie" << endl; else if (avg>avg1) cout << "Gunnar" << endl; else cout << "Emma" << endl;
	return 0;
}
