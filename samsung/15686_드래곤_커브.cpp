#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> hist;
vector<int> stack;
vector<vector<int>> visit(101, vector<int>(101, 0));

int check(){
	int cnt = 0;
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			if(visit[i][j] && visit[i+1][j+1] && 
					visit[i+1][j] && visit[i][j+1]) 
				cnt++;
		}
	}
	return cnt;
}

void curve(int& x, int& y, int& d, int g){	
	visit[x][y] = 1;
	hist.push_back(d);
	x += dx[d];
	y += dy[d];
	
	visit[x][y] = 1;

	for(int i = 1 ; i <= g ; i++){
		stack = hist;
		int temp = stack.size();
		for(int j = 0; j <temp ; j++){	
			d = (stack.back()+1)%4;
			stack.pop_back();
		
			x += dx[d];
			y += dy[d];

			visit[x][y] = 1;
			hist.push_back(d);
		}
	}
	hist = {};
	stack = {};
}



int main(){
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	vector<int> d(n);
	vector<int> g(n);
	

	for(int i= 0 ; i < n; i++)
		cin >> x[i] >> y[i] >> d[i] >> g[i];

	for(int i = 0 ; i < n ; i++)
		curve(x[i], y[i], d[i], g[i]);
	
	cout << check();
	
}
