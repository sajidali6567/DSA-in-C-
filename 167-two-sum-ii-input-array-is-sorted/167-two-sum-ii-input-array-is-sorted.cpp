class Solution {
public:
    // Time Complexity O(nlogn)
    // Space Complexity O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size()-1;
        while(p1 <= p2) {
            if(numbers[p1] + numbers[p2] == target) {
                return {p1+1, p2+1};
            } else if (numbers[p1] + numbers[p2] < target) {
                // increase smaller index
                p1++;
            } else {
                // decrease larger index
                p2--;
            }
        }
        return {};
    }
};