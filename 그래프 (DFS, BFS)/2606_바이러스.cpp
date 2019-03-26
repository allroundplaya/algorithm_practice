#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[101];
short visit[101];

void dfs(int node){
	for(auto it = graph[node].begin(); it != graph[node].end(); it++){
		if(!visit[*it]){
			visit[*it] = 1;
			dfs(*it);
		}
	}	
}


int main(){
	int com, edge;
	
	cin >> com >> edge;
	
	int node, nextNode;

	while(edge--){
		cin >> node >> nextNode;
		graph[node].push_back(nextNode);
		graph[nextNode].push_back(node);
	}

	for(int i = 1 ; i < com + 1 ; i++) visit[i] = 0;

	dfs(1);
	
	int cnt = count(&visit[2], &visit[com+1], 1);			

	cout << cnt << '\n';
	
}
