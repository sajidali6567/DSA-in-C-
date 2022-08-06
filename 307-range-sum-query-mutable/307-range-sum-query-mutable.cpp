class NumArray {
public:
    vector<int> seg;
    vector<int> arr;
    map<int, int> mp;
    void build(int index, int low, int high) {
        if(low == high) {
            mp[low] = index;
            seg[index] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*index+1, low, mid);
        build(2*index+2, mid+1, high);
        seg[index] = seg[2*index+1] + seg[2*index+2];
    }
    NumArray(vector<int>& nums) {
        arr = nums;
        seg.resize(4*arr.size());
        // build Segment tree out of arr
        build(0, 0, arr.size()-1);
    }
    
    void update(int arrIndex, int val) {
        int segIndex = mp[arrIndex];
        seg[segIndex] = val;
        while(segIndex != 0) {
            int parentIndex = (segIndex-1)/2;
            seg[parentIndex] = seg[2*parentIndex+1] + seg[2*parentIndex+2];
            segIndex = parentIndex;
        }
    }
    int query(int index, int low, int high, int l, int r) {
        if(low >= l && high <= r) {
            return seg[index];
        }
        if(l > high || r < low) {
            return 0;
        }
        int mid = (low+high)/2;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);
        return left + right;
    }
    int sumRange(int left, int right) {
        return query(0, 0, arr.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */