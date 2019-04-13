#include <iostream>
#include <vector>

using namespace std;

int leftdx[4] = {0, -1, 0, 1};
int leftdy[4] = {-1, 0, 1, 0};
int backdx[4] = {1, 0, -1, 0}; 
int backdy[4] = {0, -1, 0, 1};

bool isblock(vector<vector<int>> mat, int r, int c){
	if(mat[r][c]) return true;
	else return false;
}

bool isclean(vector<vector<int>> clean, int r, int c){
	if(!clean[r][c]) return true;
	else return false;
}


bool leftcheck(vector<vector<int>> mat, vector<vector<int>> clean, int r, int c, int d){
	if(isclean(clean, r+leftdx[d], c+leftdy[d]) &&
			!isblock(mat, r+leftdx[d], c+leftdy[d])) return true;
	else return false;
}

bool backcheck(vector<vector<int>> mat, vector<vector<int>> clean, int r, int c, int d){
	if(!isblock(mat, r+backdx[d], c+backdy[d])) 
		return true;
	else return false;
}

bool go(vector<vector<int>> mat, vector<vector<int>>& clean, int& r, int& c , int& d, int& rotation){
	clean[r][c] = 1;
	if(leftcheck(mat, clean, r, c, d)){
		rotation = 4;
		r += leftdx[d];
		c += leftdy[d];
		d = (d+3)%4;
		return true;
	}
	else{
		if(rotation) {
			rotation--;
			d = (d+3)%4;
			return true;
		}
		else if(backcheck(mat, clean, r, c, d)){
			r += backdx[d];
			c += backdy[d];
			rotation = 4;
			return true;
		}
		else
			return false;
	}
}


int main (){
	int n, m;

	cin >> n >> m;
	
	int r, c, d; // (r, c) 청소기 좌표. d = {0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽}

	cin >> r >> c >> d;

	// matrix
	vector<vector<int>> mat(n, vector<int>(m));
	vector<vector<int>> clean(n, vector<int>(m, 0));
	// matrix 입력
	for( int i = 0 ; i < n ; i++){
		for(int j = 0 ;j < m ; j++){
			cin >> mat[i][j];
		}
	}

	int rotation = 4;
	while(go(mat, clean, r, c, d, rotation));
	
	int cnt = 0;
	for(int i = 0 ;i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(clean[i][j]) cnt++;
		}
	}
	cout << cnt;


}

