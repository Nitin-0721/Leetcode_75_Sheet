class Solution {
public:
    double dfs(string curr, string target, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited) {
         if (curr == target) return 1.0;
        
        visited.insert(curr);
        
        for (auto& neighbor : adj[curr]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;
            
            if (visited.find(nextNode) == visited.end()) {
                double res = dfs(nextNode, target, adj, visited);
                if (res != -1.0) {
                    return res * weight; // Chain the multiplication
                }
            }
        }
        
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        
         for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }
        
        vector<double> results;
        for (auto& q : queries) {
            string src = q[0];
            string dst = q[1];
            
             if (adj.find(src) == adj.end() || adj.find(dst) == adj.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(src, dst, adj, visited));
            }
        }
        
        return results;
    }
};