class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        long long lo = 0;
        long long hi = 0;
        
        for (int x : arr) {
            if (x > lo) lo = x;
            hi += x;
        }
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            
            if (canPaint(arr, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return (int)lo;
    }

private:
    bool canPaint(const vector<int>& arr, int k, long long limit) {
        int count = 1;
        long long current_sum = 0;
        
        for (int x : arr) {
            if (current_sum + x <= limit) {
                current_sum += x;
            } else {
                count++;
                current_sum = x;
                if (count > k) return false;
            }
        }
        return true;
    }
};