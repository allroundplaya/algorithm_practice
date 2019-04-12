#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


vector<int> temp;

void comb(int size, int idx, int k, 
		vector<vector<int>>& t1, vector<vector<int>>& t2, vector<int> s){
	
	if(k == 0){
		vector<int> diff;
		t1.push_back(temp);
		set_difference(s.begin(), s.end(), temp.begin(), temp.end(),
				inserter(diff, diff.begin()));
		t2.push_back(diff);
		return;
	}
	
	for(int i = idx ; i <= size - k ; i++){
		temp.push_back(i);
		comb(size, i+1, k-1, t1, t2, s);
		temp.pop_back();
	}
	
}



int main (){
	int n;
	cin >> n;
	
	vector<vector<int>> mat(n, vector<int>(n));
	

	for(int i = 0 ; i < n ; i ++){
		for (int j = 0 ; j < n ; j++){
			cin >> mat[i][j];
		}
	}
	
	vector<vector<int>> t1;
	vector<vector<int>> t2;
	
	vector<int> s;
	
	for(int i = 0 ; i < n; i++) s.push_back(i);

	comb(n, 0, n/2, t1, t2, s);
	
	vector<int> score;
	for(int i = 0 ; i < t1.size() ; i++){
		int stemp = 0;
		for(int row= 0; row < n/2 ; row++)
			for(int col= 0 ; col < n/2 ; col++){
				stemp += (mat[t1[i][row]][t1[i][col]] - mat[t2[i][row]][t2[i][col]]);
			}
		score.push_back(abs(stemp));
	}

	sort(score.begin(), score.end());
	cout << score.front();

				


}


