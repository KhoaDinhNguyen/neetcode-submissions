struct SortTaskVector {
    bool operator()(const vector<int>&i, const vector<int>&j) const {
        if (i[0] == j[0] && i[1] == j[1]) return i[2] < j[2];
        else if (i[0] == j[0]) return i[1] < j[1];
        return i[0] < j[0];       
    }
};

struct SortTaskHeap {
    bool operator()(const vector<int>&i, const vector<int>&j) const {
        if (i[1] == j[1]) return i[2] > j[2];
        return i[1] > j[1];    
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int N = tasks.size();

        for (int i = 0; i < N; ++i) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end(), SortTaskVector());
        priority_queue<vector<int>, vector<vector<int>>, SortTaskHeap> heap;

        int currTime = 0, currTask = 0, i = 0;

        vector<int> ans;

        while (currTask < N) {
            while (i < N && tasks[i][0] <= currTime) {
                heap.push(tasks[i]);
                i++;
            }

            if (!heap.empty()) {
                vector<int> task = heap.top();
                heap.pop();
                ans.push_back(task[2]);
                currTime += task[1];
                currTask++;
            }
            else {
                currTime = tasks[i][0];
            }
        }


        return ans;
    }

    // Time O(nlogn)
    // Space O(n)
};