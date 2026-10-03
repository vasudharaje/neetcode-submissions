#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Map source airport to a min-heap of destination airports
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        
        // Build the adjacency graph
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        
        vector<string> itinerary;
        
        // DFS function to traverse using Hierholzer's Algorithm
        auto dfs = [&](auto& self, string airport) -> void {
            auto& dests = adj[airport];
            while (!dests.empty()) {
                string next = dests.top();
                dests.pop(); // Remove the edge (ticket) after using it
                self(self, next);
            }
            itinerary.push_back(airport); // Post-order traversal
        };
        
        // Start traversal from "JFK"
        dfs(dfs, "JFK");
        
        // The path is built in reverse order, so reverse it
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
