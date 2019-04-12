#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void build(vector<int>& slope, int idx, int l, bool asc){
	if(!asc){
		for(int i = 0 ;i < l ; i++)
			slope[idx+i] = 1;
	}
	else{
		for(int i = 1 ; i <= l; i++)
			slope[idx-i] = 1;
	}
}

bool isbuilt(vector<int> slope, int idx, int l){
	for(int i = 1 ; i <= l ; i++){
		if(slope[idx-i] == 1)
			return true;
	}
	return false;
}

bool rowequal(vector<int> v, int idx, int l, bool asc){
	if(!asc){
		for(int i = 0 ; i < l ; i++)
			if(v[idx] != v[idx+i]) return false;
	}
	else{
		for(int i = 1; i <= l ; i++)
			if(v[idx-1] != v[idx-i]) return false;
	}
	return true;
}

bool colequal(vector<vector<int>> v, int row, int col, int l, bool asc){
	if(!asc){
		for(int i = 0 ; i < l ; i++)
			if(v[row][col] != v[row+i][col]) return false;
	}
	else{
		for(int i = 1 ; i <=l ; i++)
			if(v[row-1][col] != v[row-i][col]) return false;
	}
	return true;
}



bool rowok(int n, int l, vector<int> v){
	int prev = v[0];
	vector<int> slope(n, 0);
	//급경사 있는 곳 탈락
	for(int i = 0 ; i < n ; i++){
		if(i) prev = v[i-1];
		if(abs(prev-v[i]) >1) return false;
	}
	
	prev = v[0];
	for(int i = 0; i < n ; i++){
		if(i) prev = v[i-1];
		// descending
		if(prev > v[i]){
			if(i + l -1< n){
				if(rowequal(v, i, l, false)){
					build(slope, i, l, false);
					i+=(l-1);
					continue;
				}
				else return false;
			}
			else return false;
		}	
		// ascending
		else if(prev < v[i]){
			if(i >= l){
				if(!isbuilt(slope, i, l) && rowequal(v, i, l, true)){
					build(slope, i, l, true);
					continue;
				}
				else return false;
			}
			else return false;
		}
		else continue;
	}
	return true;
		
}

bool colok(int n, int l, vector<vector<int>> v, int idx){
	int prev = v[0][idx];
	vector<int> slope(n, 0);
	//급경사 있는 곳 탈락
	for(int i = 0 ; i < n ; i++){
		if(i) prev = v[i-1][idx];
		if(abs(prev-v[i][idx]) >1) return false;
	}
	
	prev = v[0][idx];
	for(int i = 0; i < n ; i++){
		if(i) prev = v[i-1][idx];
		// descending
		if(prev > v[i][idx]){
			if(i+l -1< n){
				if(colequal(v, i, idx, l, false)){
					build(slope, i, l, false);
					i+=(l-1);
					continue;
				}
				else return false;
			}
			else return false;
		}	
		// ascending
		else if(prev < v[i][idx]){
			if(i >= l){
				if(!isbuilt(slope, i, l) && colequal(v, i, idx, l, true)){
					build(slope, i, l, true);
					continue;
				}
				else return false;
			}
			else return false;
		}
		else continue;
	}
	return true;
		
}
int main(){
	int n, l;
	
	cin >> n >> l; // n*n 크기 지도, l은 경사로의 길이

	vector<vector<int>> mat(n, vector<int>(n));

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> mat[i][j];
	
	int cnt = 0;
	for(int i = 0 ; i < n ; i++)
		if(rowok(n, l, mat[i]))
			cnt++;
	for(int j = 0 ; j < n ; j++)
		if(colok(n, l, mat, j)) 
			cnt++;
	cout <<  cnt;

}

