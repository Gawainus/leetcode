#define once


#include <vector>

class Solution {

    using Row = std::vector<size_t>;
    using Sol = std::vector<Row>;
public:
    size_t integerPartition(size_t n) {

        if (n < 4)
            return n;

        Sol sol(n, Row(n, 1));
        for (size_t i = 3; i < n; i++) {
            for (size_t j = 1; j < i - 1; j++) {
                sol[i][j] = fetch(i, j+1, sol);
            }
        }

        size_t res {0};
        for (size_t i = 0; i < n; i++)
            res += sol[n-1][i];

        return res;
    }

    /*
     * for integer n return the number of partitions starting with the max part k
     * n is the row, n + 1 is the curr number
     * k is the k is the max of the biggest part
     */
    size_t fetch(size_t n, size_t k, const Sol & sol) const {

        size_t res {0};

        size_t remainder_row = n - k;
        size_t target_column = std::min(k, remainder_row+1);
        for (size_t i = 0; i < target_column; i++) {
            res += sol[remainder_row][i];
        }

        return res;
    }
};
