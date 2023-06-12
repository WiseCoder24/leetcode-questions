/*
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
//Approach 1
vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;//to get unique triplets
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp;
        temp.resize(3);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(binary_search(nums.begin()+j+1,nums.end(),-nums[i]-nums[j])){
                     temp[0]=nums[i],temp[1]=nums[j],temp[2]=-nums[i]-nums[j];
                    sort(temp.begin(),temp.end());
                    //to get triplet in an order, will be easy to check if 
                    //duplicate exists or not
                    s.insert(temp);
                    }
            }
        vector<vector<int>> ans;
        for(auto triplet: s)
            ans.push_back(triplet);
        return ans;
}
//Approach 2
vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n; i++)
        {
            int j=i+1,k=n-1;//two pointers
            while(j<n && j<k)
            {
                if(nums[j]+nums[k] == -nums[i])
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(k!=0 && nums[k]==nums[k-1]) k--;//to avoid duplicates 
                    while(j!=n-1 && nums[j]==nums[j+1]) j++;
                    j++,k--;
                }
                else if(nums[j]+nums[k] > -nums[i]) 
                {
                    while(k!=0 && nums[k]==nums[k-1]) k--;
                    k--;
                }
                else
                {
                    while(j!=n-1 && nums[j]==nums[j+1]) j++;
                    j++;
                }
            }
            while(i!=n-1 && nums[i]==nums[i+1]) i++;
        }
        for(auto triplet : ans)
            sort(triplet.begin(),triplet.end());
        return ans;