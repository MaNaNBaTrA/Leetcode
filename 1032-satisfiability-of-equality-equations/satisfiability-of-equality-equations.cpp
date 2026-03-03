class Solution {
public:
    map<char, char> parent;
    map<char, int> rank_;
    char find(char x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  
        }
        return parent[x];
    }

    void Union(char x, char y) {
        char px = find(x);
        char py = find(y);

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
        for (auto &eq : equations) {
            parent[eq[0]] = eq[0];
            parent[eq[3]] = eq[3];
            rank_[eq[0]] = 0;
            rank_[eq[3]] = 0;
        }

        for (auto &eq : equations) {
            if (eq[1] == '=') {
                Union(eq[0], eq[3]);
            }
        }

        for (auto &eq : equations) {
            if (eq[1] == '!') {
                if (find(eq[0]) == find(eq[3])) {
                    return false;
                }
            }
        }

        return true;
    }
};