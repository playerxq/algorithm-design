class Solution {
public:
    void dfs(int cur, int k, int st, int n, vector<int>&temp, vector<vector<int>>& res)
    {
        if(cur==k)
        {
            res.push_back(temp);
            return;
        }
        for(auto i = st;i<=n;i++)
        {
            temp.push_back(i);
            dfs(cur+1,k,i+1,n,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0,k,1,n,temp,res);
        return res;
    }
};