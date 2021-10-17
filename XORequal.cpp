#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x,p;
		cin >> n >> x;
		unordered_map<int,int> mp;			// frequence of each number in given array
		unordered_map<int,int> present;	 	// to check whether given number is present in array or not

		for(int i=0; i<n; i++){
			cin >> p;
			mp[p]++;
			present[p] = 1;
		}
		if(n==1){
			cout << 1 << " " << 0 << endl;
			continue;
		}
		int ans =0;
		int changes =0;

		for(auto it: mp){
			if(it.second == n){
				ans = n;
				break;
			}
			if(it.second >= ans){
				ans= it.second;
			}
		}

		if(x==0){
			cout << ans << " " << changes << endl;
			continue;
		}

		for(auto it: mp){
			if(present[(it.first)^x] ==1){
				if(it.second + mp[(it.first)^x] > ans){
					ans = it.second + mp[(it.first)^x];
					changes = min(it.second, mp[(it.first)^x]);
				}
				else if(it.second + mp[(it.first)^x] == ans){
					if(min(it.second, mp[(it.first)^x]) < changes){
						changes = min(it.second, mp[(it.first)^x]);
					}
				}
			}
		}

		cout << ans << " " << changes << endl;


		
	}
	return 0;
}