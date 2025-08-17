class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int> d(n,INT_MAX);
        using T = pair<int,int> ; 
        priority_queue<T, vector<T>,greater<T>> pq ;
        pq.push({0,0});
        d[0]=0;
             while (!pq.empty()) {
        auto [dis,u] = pq.top() ;
        pq.pop() ;
        if (dis != d[u]) continue ;
        if (u == n - 1) return dis ;
        for (auto &[v,w] : adj[u]) {
          if (dis + w < d[v]) {
            d[v] = dis + w ;
            pq.push({d[v],v}) ;
          }
        }
      }
return -1;
    }
};