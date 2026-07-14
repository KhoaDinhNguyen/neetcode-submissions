class KthLargest {
public:
    int K = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;

        for (int i = 0; i < nums.size(); ++i) {
            // If min-heap store k values then top value is kth largest
            if (pq.size() >= K) {
                if (nums[i] > pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else {
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if (pq.size() >= K) {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        else {
            pq.push(val);
        }

        return pq.top();
    }
};
