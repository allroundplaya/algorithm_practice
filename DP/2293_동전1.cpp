#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	
	cin >> n >> k;

	int* dp = (int*)malloc(sizeof(int)*(k+1));
	
	vector<int> coin;
	
	while(n--){
		int temp;
		cin >> temp;
		coin.push_back(temp);
		
	}
	
	sort(coin.begin(), coin.end());

	for(int i = 0 ; i< k+1 ; i++) dp[i] = 0;
	
	for(auto it = coin.begin() ; it!= coin.end(); it++){
		for (int i = 0 ; i < k+1 ; i++){
			if ( i == *it) dp[i] += 1;
			else if ( i < *it) continue; 
			dp[i] += dp[i-*it];
			
		}
	
	}

	cout << dp[k];
	free(dp);
	
}
