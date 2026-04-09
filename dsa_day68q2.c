class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Step 1: Initialize indegree for all unique chars
        for (auto word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Step 2: Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            // Edge case: prefix invalid
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        // Step 3: Kahn's BFS
        queue<char> q;
        for (auto it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        string result = "";

        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check cycle
        if (result.size() != indegree.size()) {
            return "";
        }

        return result;
    }
};
