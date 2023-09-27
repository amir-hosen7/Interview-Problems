//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job &a, Job &b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) { 
        // your code here
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        set<int> slot;
        for (int i = 1; i <= maxDeadline; i++) {
            slot.insert(i);
        }
        sort(arr, arr + n, cmp);
        int cnt = 0, maxProfit = 0;
        for (int i = 0; i < n; i++) {
            if (slot.size() == 0 or arr[i].dead < *slot.begin()) continue;
            cnt++;
            maxProfit += arr[i].profit;
            auto it = slot.upper_bound(arr[i].dead);
            --it;
            slot.erase(it);
        }
        return {cnt, maxProfit};
    } 
};
