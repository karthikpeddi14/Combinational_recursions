class Solution {
  public:
    void takenottake(vector<vector<int>> &ans, vector<int>& per_sub , vector<int> candidates , int sum, int index)
    {
        if(sum==0)
        {
            ans.push_back(per_sub);
            return;
        }
        
        for(int i=index ; i<candidates.size() ; i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>sum) break;
            per_sub.push_back(candidates[i]);
            takenottake(ans,per_sub,candidates,sum-candidates[i],i+1);
            per_sub.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) 
    {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> per_sub ; 
        takenottake(ans,per_sub,candidates,target,0);
        
        
        return ans;
    }
};
