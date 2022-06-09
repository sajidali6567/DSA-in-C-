class Solution {
public:
    // Time Complexity O(nlogn)
    // Space Complexity O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++) {
            int idx = -1;
            /* check if target-numbers[i] exists in numbers, (equal sign is imp)                                           *
             * because if target-numbers[i] is equal to numbers[i] and if it exists it will always exist on the right side */
            if(target-numbers[i] >= numbers[i]) { // check in right side
                idx = binary_search(numbers, i+1, numbers.size()-1, target-numbers[i]);
                if(idx != -1) {
                    return {i+1, idx+1};
                }
            } else { // check left side
                idx = binary_search(numbers, 0, i+1, target-numbers[i]);
                if(idx != -1) {
                    return {idx+1, i+1};
                }
            }
        }
        return {};
    }
    // binary search returns index of the element
    int binary_search(vector<int>& numbers, int low, int high, int key) {
        while(low <= high) {
            int mid = (low+high)>>1;
            if(numbers[mid] == key) {
                return mid;
            } else if (numbers[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};