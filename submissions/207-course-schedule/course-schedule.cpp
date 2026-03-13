class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        vis.assign(numCourses,0);
        for(auto& pre:prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i))
                {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool dfs(int node){
        
        vis[node]=1;
        for (auto it :adj[node])
        {
            if(vis[it]==1)
            {
                return true;
            }
            if(vis[it]==0)
            {
                if(dfs(it))
                {
                    return true;
                }
            }
           
        } 
        vis[node]=2;
        return false;
    }
};