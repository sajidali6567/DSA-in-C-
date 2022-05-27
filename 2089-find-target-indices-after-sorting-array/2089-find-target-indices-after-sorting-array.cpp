class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int start = 0, end = nums.size()-1;
        while(start < end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) end = mid;
            else if (target > nums[mid]) start=mid+1;
            else end=mid-1;
        }
        // cout << "end = " << end << endl;
        if(end == -1) return {};
        int lower = nums[end]==target?end:-1;
        // cout << "lower = " << lower << endl;
        if(lower == -1) return {};
        
        vector<int> res;
        while(lower < nums.size() && nums[lower] == target) {
            res.push_back(lower);
            lower++;
        }
        return res;
    }
};