class Solution {
public:
    vector<int> parent;
    vector<int> rank_;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);   
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank_[px] < rank_[py]) {
            parent[px] = py;
        }
        else if (rank_[px] > rank_[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank_[px]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }

        parent.resize(n);
        rank_.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int cables = connections.size();

        for(auto& it : connections){
            Union(it[0],it[1]);
        }

        int components = 0;

        for(int i = 0 ; i < n ; i++){
            if(find(i)==i){
                components++;
            }
        }

        return components - 1;

    }
};