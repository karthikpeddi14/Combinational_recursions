class Solution {

  public:
    void takenottake_pro (vector<vector<int>>& ans, vector<int> &a, vector<int>& ds,  int index)
    {
        if(index == a.size())
        {
            return;
        }
        
        for(int i=index; i<a.size() ; i++)
        {
            if(index<i && a[i]==a[i-1]) continue;
            ds.push_back(a[i]);
            ans.push_back(ds);
            takenottake_pro(ans,a,ds,i+1);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        ans.push_back(ds);
        takenottake_pro(ans,nums,ds,0);
        return ans;
    }
};
