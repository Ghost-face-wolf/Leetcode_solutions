#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<int> bit;
    vector<int> node_mask;
    string s;

    void dfs(int u, int p, int d) {
        tin[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < 20; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
        tout[u] = timer;
    }

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] ^= val;
    }

    int query_bit(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res ^= bit[idx];
        return res;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = 19; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n_nodes, vector<vector<int>>& edges, string initial_s, vector<string>& queries) {
        n = n_nodes;
        s = initial_s;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(20, 0));
        bit.assign(n + 1, 0);
        node_mask.resize(n);
        timer = 0;

        dfs(0, 0, 0);

        for (int i = 0; i < n; ++i) {
            node_mask[i] = (1 << (s[i] - 'a'));
            add(tin[i], node_mask[i]);
            add(tout[i] + 1, node_mask[i]);
        }

        vector<bool> answer;
        for (auto& q : queries) {
            if (q[0] == 'u') {
                int space_idx = q.find(' ', 7);
                int u = stoi(q.substr(7, space_idx - 7));
                char c = q.back();

                int old_mask = node_mask[u];
                int new_mask = (1 << (c - 'a'));
                if (old_mask != new_mask) {
                    node_mask[u] = new_mask;
                    int diff = old_mask ^ new_mask;
                    add(tin[u], diff);
                    add(tout[u] + 1, diff);
                }
            } else {
                int space_idx = q.find(' ', 6);
                int space_idx2 = q.find(' ', space_idx + 1);
                int u = stoi(q.substr(6, space_idx - 6));
                int v = stoi(q.substr(space_idx + 1));

                int lca = get_lca(u, v);
                int mask_u = query_bit(tin[u]);
                int mask_v = query_bit(tin[v]);
                int mask_lca = node_mask[lca];

                int path_mask = mask_u ^ mask_v ^ mask_lca;
                
                // Check if at most one bit is set
                if (path_mask == 0 || (path_mask & (path_mask - 1)) == 0) {
                    answer.push_back(true);
                } else {
                    answer.push_back(false);
                }
            }
        }

        return answer;
    }
};