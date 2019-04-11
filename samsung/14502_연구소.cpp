#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};


void dfs(int row, int col, vector<vector<int>>& mat){
	
	int rowsize = mat.size();
	int colsize = mat.front().size();
	
	for(int i = 0 ;i < 4 ; i++){
		if((row+dx[i]>=0) &&  (col+dy[i]>=0) && 
				(row+dx[i] < rowsize) && (col+dy[i] < colsize)){
			if(mat[row+dx[i]][col+dy[i]] == 0){
				mat[row+dx[i]][col+dy[i]] = 2;
				dfs(row+dx[i], col+dy[i], mat);
			}
			else continue;
		}
		else continue;
	}
}

int countzero(vector<vector<int>> mat){
	int cnt=0;
	for(int i = 0 ;i < mat.size() ; i++)
		for(int j = 0 ; j< mat.front().size() ; j++)
			if(mat[i][j] == 0 ) cnt++;
	return cnt;
}

int main(){
	int n, m;
	
	cin >> n >> m;
	
	vector<vector<int>> mat(n, vector<int>(m));
	
	vector<int> xpos;
	vector<int> ypos;

	vector<int> xwall;
	vector<int> ywall;
		
	for(int i = 0 ;i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 2){
				xpos.push_back(i);
				ypos.push_back(j);
			}
			if(mat[i][j] == 0){
				xwall.push_back(i);
				ywall.push_back(j);
			}

		}
	
	if(xwall.size() == 3){
		cout << 0;
		return 0;
	}


	vector<int> safe;

	for(int i = 0 ; i < xwall.size()-2; i++){
		for(int j = i+1; j < xwall.size()-1; j++){
			for(int k = j+1 ; k < xwall.size(); k++){
				vector<vector<int>> temp;
				temp = mat;
				temp[xwall[i]][ywall[i]] = 1;
				temp[xwall[j]][ywall[j]] = 1;
				temp[xwall[k]][ywall[k]] = 1;
				
				for(int l = 0 ; l < xpos.size() ;l++)
					dfs(xpos[l], ypos[l], temp);
				safe.push_back(countzero(temp));

			}
		}
	}


	sort(safe.begin(), safe.end(), greater<int>());
	
	cout << safe.front();

	return 0;

}

