#define once

#include <string>
#include <array>
#include <assert.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        auto len = s.size();
        int best = 0;

        for (size_t i = 0; i < len; i++) {
            std::array<bool, 128> char_array;
            char_array.fill(false);

            int sub_string_len {0};

            for (size_t j = i; j < len; j++) {
                int c = s[j];

                if (char_array.at(c))
                    break;

                char_array.at(c) = true;
                sub_string_len++;
            }

            best = std::max(best, sub_string_len);
        }
        return best;
    }
};