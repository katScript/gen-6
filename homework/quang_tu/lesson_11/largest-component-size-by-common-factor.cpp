class Solution {
public:
    bool isValid(int a, int b) {
        int x = max(a,b),
            y = min(a,b);
        
        while(y != 0) {
            int t = x % y;
            x = y;
            y = t;
        }
        
        return x != 1;
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, vector<int>> nodesMap;
    
    int dfs(int node) {
        visited[node] = true;
        int totalNode = 1;
        
        for (auto n: nodesMap[node]) {
            if (!visited[n])
                totalNode += dfs(n);
        }
        
        return totalNode;
    }
    
    int largestComponentSize(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (isValid(nums[i], nums[j])) {
                    nodesMap[nums[i]].push_back(nums[j]);
                    nodesMap[nums[j]].push_back(nums[i]);
                }
            }
            visited[nums[i]] = false;
        }
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[nums[i]]) 
                res = max(res, dfs(nums[i]));
        }
        
        return res;
    }
};