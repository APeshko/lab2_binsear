#include "library.hpp"
#include <sstream>

namespace template_library {
    // Функция для генерации хэшируемого строкового представления подмассива
    std::string get_subarray_hash(const std::vector<int>& nums, int start, int length) {
        std::ostringstream oss;
        for (int i = start; i < start + length; ++i) {
            oss << nums[i] << ",";
        }
        return oss.str();
    }

    int longest_duplicate_subarray(const std::vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        int max_length = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            std::unordered_set<std::string> seen_subarrays;
            bool duplicate_found = false;

            for (int i = 0; i <= static_cast<int>(nums.size()) - mid; ++i) {
                std::string subarray_str = get_subarray_hash(nums, i, mid);
                
                if (seen_subarrays.find(subarray_str) != seen_subarrays.end()) {
                    duplicate_found = true;
                    break;
                }
                seen_subarrays.insert(subarray_str);
            }

            if (duplicate_found) {
                max_length = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return max_length;
    }
}
