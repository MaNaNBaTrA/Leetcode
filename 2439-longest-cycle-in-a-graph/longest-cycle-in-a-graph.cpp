class Solution {
public:
    int result = -1;

    void dfs(int u,vector<int>& edges,vector<bool> &vis,vector<bool>& inRecursion,vector<int>& count){
        if(u!=-1){
            vis[u] = true;
            inRecursion[u] = true;
            
            int v = edges[u];
            
            if(v != -1 && !vis[v]) {
                count[v] = count[u] + 1;
                dfs(v, edges, vis,inRecursion,count);

            } else if(v != -1 && inRecursion[v] == true) {
                result = max(result, count[u] - count[v] +1);
            }
        
            inRecursion[u] = false;
        }
    }

    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        vector<bool> vis(V,false);
        vector<bool> inRecursion(V,false);
        vector<int> count(V,1);


        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i,edges,vis,inRecursion,count);
            }
        }


        return result;
    }
};