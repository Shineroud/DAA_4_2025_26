class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        long long lo = 0;
        long long hi = 0;
        for (int x : arr) {
            if (x > lo) lo = x; 
            hi += x;           \
        }
        long long ans = hi;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;      
                hi = mid - 1;
            } else {
                lo = mid + 1; 
            }
        }
        return (int)ans;
    }
private:
    bool isPossible(const vector<int>& arr, int k, long long max_workload) {
        int painters_count = 1;
        long long current_sum = 0;
        for (int board : arr) {
            if (current_sum+board<= max_workload){
                current_sum += board;
            }else{
                painters_count++;
                current_sum=board;
                if (painters_count > k) return false;
            }
        }
        return true;
    }
};