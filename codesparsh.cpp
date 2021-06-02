#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,h,x;
	cin>>n>>h>>x;
	vector<int> hotspot(h);
	for(int i=0;i<h;i++)
		cin>>hotspot[i];
	vector<int> graph[n+1];
	int xx,yy;
	for(int i=0;i<n-1;i++){
		cin>>xx>>yy;
		graph[xx].push_back(yy);
		graph[yy].push_back(xx);
	}
	int epicenter=0;
	for(int i=1;i<=n;i++){
		vector<int> dist(n+1,-1); //using -1 as not visited
		queue<int> q;
		dist[i]=0;
		q.push(i);
		while(!q.empty()){
			int curr=q.front();
			q.pop();
			for(int nb: graph[curr]){
				if(dist[nb]==-1){
					dist[nb]=dist[curr]+1;
					q.push(nb);
				}
			}
		}
		int maxdist = 0;
		for(auto i: hotspot)
			maxdist= max(maxdist, dist[i]);
		epicenter+=(maxdist<=x);
	}
	cout<<epicenter;
}