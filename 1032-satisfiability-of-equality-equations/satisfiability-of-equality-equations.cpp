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

    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);
        rank_.resize(26, 0);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (auto &eq : equations) {
            if (eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                Union(x, y);
            }
        }

        for (auto &eq : equations) {
            if (eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                if (find(x) == find(y)) {
                    return false;
                }
            }
        }

        return true;
    }
};