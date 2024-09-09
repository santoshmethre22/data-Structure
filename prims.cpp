 int spanningTree(int V, vector<vector<int>> adj[])
    {
       
       *************************************************************************
        this is primes algorithm
        
        priority_queue< pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>pq;
        
        vector<bool>vis(V,false);
        
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto i=pq.top();
            int wt=i.first;
            int node =i.second;
            
            pq.pop();
            if(vis[node]==true) continue;
            vis[node]=true;
            sum+=wt;
            for(auto it:adj[node]){
                int adjN=it[0];
                int wt=it[1];
                if(vis[adjN]!=true)
                pq.push({wt,adjN});
            }
            
        }
        return sum;
        
        
        
    }