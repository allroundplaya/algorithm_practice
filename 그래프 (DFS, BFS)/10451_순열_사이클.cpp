#include <iostream>

using namespace std;

int arr[1000];
bool visit[1000];

void dfs(int node){
	if(visit[node]) return;
	visit[node] = true;
	dfs(arr[node]);
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for (int i = 0 ; i < n ; i++){
			cin >> arr[i+1];
			visit[i+1] = false;
		}
		int cnt = 0;
		for (int i = 0 ; i < n ; i++){
			if(!visit[i+1]){
				cnt++;
				dfs(i+1);
			}
		}
		cout << cnt << '\n';
	}
}
