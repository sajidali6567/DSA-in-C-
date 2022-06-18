class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nge;
        stack<int> st;
        for(int i=0;i<nums2.size();i++) {
            while(!st.empty() and nums2[st.top()] < nums2[i]) {
                nge[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            nge[nums2[st.top()]] = -1;
            st.pop();
        }
        vector<int> res;
        for(int i=0;i<nums1.size();i++) {
            res.push_back(nge[nums1[i]]);
        }
        return res;
    }
};