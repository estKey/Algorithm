class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rslt;
        sort(nums.begin(), nums.end());
        rslt.push_back(nums[0]);
        rslt.push_back(nums[1]);
        for(int i = 0; i < nums.size(); i++)
            cout << nums[i] << endl;
        return rslt;
    }
};