#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[node] = true;
        for (int neighbor : adj[node]) {
            if (!suspicious[neighbor]) {
                dfs(neighbor, adj, suspicious);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& invocation : invocations) {
            adj[invocation[0]].push_back(invocation[1]);
        }

        vector<bool> suspicious(n, false);
        dfs(k, adj, suspicious);

        bool canRemove = true;
        for (const auto& invocation : invocations) {
            int u = invocation[0];
            int v = invocation[1];
            if (!suspicious[u] && suspicious[v]) {
                canRemove = false;
                break;
            }
        }
        vector<int> result;
        if (canRemove) {
            for (int i = 0; i < n; ++i) {
                if (!suspicious[i]) {
                    result.push_back(i);
                }
            }
        } else {
            result.resize(n);
            iota(result.begin(), result.end(), 0);
        }
        return result;
    }
};
