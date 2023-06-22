class Solution {
  public:
    void cs(vector<int>& a ,vector<vector<int>>& ans, vector<int>& per_sub , int index , int sum) 
    {
        if(sum==0)
        {
            ans.push_back(per_sub);
            return;
        }
        if(sum<0) return;
        if(index>=a.size())
        {
            if(sum==0) ans.push_back(per_sub);
            return;
        }
        
        per_sub.push_back(a[index]);
        cs(a,ans,per_sub,index,sum-a[index]);
        per_sub.pop_back();
        
        cs(a,ans,per_sub,index+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int> &A, int B) 
    {
        vector<vector<int>> ans;
        vector<int> per_sub;
        set<int> st;
        vector<int> v;
        
        for(auto it: A)
        {
            st.insert(it);
        }
        
        for(auto it: st)
        {
            v.push_back(it);
        }
        
        cs(v,ans,per_sub,0,B);
        return ans;
    }
};
