class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list: node -> vector of {neighbor, price}
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        // Queue stores {current_node, current_total_cost}
        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;

        // Explore level-by-level up to k stops (k + 1 edge steps)
        while (!q.empty() && stops <= k) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, cost] = q.front();
                q.pop();

                for (const auto& [neighbor, price] : adj[node]) {
                    if (cost + price < prices[neighbor]) {
                        prices[neighbor] = cost + price;
                        q.push({neighbor, cost + price});
                    }
                }
            }
            stops++;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};