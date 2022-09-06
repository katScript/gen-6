class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
    
    void dfs(vector<string>& account, string &email) {
        visited.insert(email);
        
        account.push_back(email);
        
        for (auto &neighbor : adjacent[email]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(account, neighbor);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        for (auto &acc: accountList) {
            string fMail = acc[1];
            
            for (int i = 2; i < acc.size(); ++i) {
                adjacent[fMail].push_back(acc[i]);
                adjacent[acc[i]].push_back(fMail);
            }
        }
        
        vector<vector<string>> result;
        for (auto &acc: accountList) {
            string user = acc[0],
                   fMail = acc[1];
            
            if (visited.find(fMail) == visited.end()) {
                vector<string> mergedAccount;
                
                mergedAccount.push_back(user);
                dfs(mergedAccount, fMail);
                
                sort(mergedAccount.begin() + 1, mergedAccount.end());
                result.push_back(mergedAccount);
            }
        }
        
        return result;
    }
};