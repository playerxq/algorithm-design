class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        auto flag = (1<<n)-1;
        auto tmp = flag;
        for(auto i = 0;i<=tmp;i++)
        {
            temp.clear();
            auto next = flag&i;
            for(auto j = 0;j<n;j++)
            {
                if((1<<j)&next)
                {
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};