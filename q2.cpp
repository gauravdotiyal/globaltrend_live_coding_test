#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int root,vector<vector<pair<int,int>>> &adj){
    int n=adj.size();
    vector<int> distance(n,numeric_limits<int>::max());
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;



    distance[root]=0;
    pq.push({0,root});

    while(!pq.empty()){
       int dist=pq.top().first;
       int u=pq.top().second;
       pq.pop();

       if(dist>distance[u]){
        continue;
       }

       for(auto &edge:adj[u]){
          int v=edge.first;
          int weight=edge.second;
          if(distance[u]+weight<distance[v]){
            distance[v]=distance[u]+weight;
            pq.push({distance[v],v});
          }
       }
    }
   
   return distance;
}
int main(){

    int n=4;
    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1,4});
    adj[0].push_back({2,1});
    adj[1].push_back({3,1});
    adj[2].push_back({1,2});
    adj[2].push_back({3,5});
  
    
    int root=0;
    vector<int> distance=dijkstra(root,adj);

    cout<<"shortest distance from source is "<<root<<endl;

    for(int i=0;i<n;++i){
        cout<<i<<" "<<distance[i]<<endl;
    }


    return 0;
}