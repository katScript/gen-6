class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        vector<vector<pair<int,int>>> place (n);
        vector<int> listCost (n, INT_MAX);
        vector<int> stop (n, k);
        
        listCost[src] = 0;
        stop[src] = 0;
        stop[dst] = 0;
        
        pq.push({0, src, 0});
        
        for (auto fl: flights) 
            place[fl[0]].push_back({fl[1], fl[2]});
        
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            
            int cost = cur[0],
                curSrc = cur[1],
                curK = cur[2];
            
            for (auto next: place[curSrc]) {
                int nCost = cost + next.second,
                    nSrc = next.first,
                    b = 0;
                
                if (next.first != dst) 
                    b = 1;
                
                if (curK + b <= k) {
                    if (nCost < listCost[nSrc]) {
                        listCost[nSrc] = nCost;
                        stop[nSrc] = curK + b;
                        
                        pq.push({nCost, nSrc, stop[nSrc]});
                    } else if (curK < stop[nSrc]) {
                        stop[nSrc] = curK + b;
                        pq.push({nCost, nSrc, stop[nSrc]});
                    }
                }
                
            }
        }
        
        return listCost[dst] != INT_MAX ? listCost[dst] :-1;
    }
};