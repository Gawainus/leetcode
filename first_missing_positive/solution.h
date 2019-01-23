#define once

#include <vector>
#include <queue>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {

        std::priority_queue<int, std::vector<int>, std::greater<>> heap;
        for (auto n: nums) {
            if (n > 0) {
                heap.push(n);
            }
        }

        if (heap.empty()) {
            return 1;
        }

        int smallest = heap.top();

        int best = {1};
        while(!heap.empty()) {
            int n = heap.top();
            heap.pop();

            if (n <= best) {
                best = n + 1;
            }
            else {
                break;
            }

        }

        return best;
    }
};
