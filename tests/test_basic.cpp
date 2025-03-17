#include <gtest/gtest.h>
#include "library.hpp"

#include <gtest/gtest.h>

TEST(LongestDuplicateSubarrayTest, BasicCases) {
    // Простой случай
    EXPECT_EQ(template_library::longest_duplicate_subarray({1,2,3,4,2,3,4,5}), 3);

    // Все элементы одинаковые
    EXPECT_EQ(template_library::longest_duplicate_subarray({5,5,5,5}), 3);

    // Дубликаты перекрываются
    EXPECT_EQ(template_library::longest_duplicate_subarray({1,2,1,2,1,2}), 4);
}

TEST(LongestDuplicateSubarrayTest, EdgeCases) {
    // Минимальная длина массива
    EXPECT_EQ(template_library::longest_duplicate_subarray({1}), 0);
    EXPECT_EQ(template_library::longest_duplicate_subarray({1,1}), 1);

    // Нет дубликатов
    EXPECT_EQ(template_library::longest_duplicate_subarray({1,2,3,4,5}), 0);

    // Максимальный дубликат в конце
    EXPECT_EQ(template_library::longest_duplicate_subarray({1,2,3,1,2,3}), 3);
}

TEST(LongestDuplicateSubarrayTest, SpecialCases) {
    // Чередование элементов
    EXPECT_EQ(template_library::longest_duplicate_subarray({1,2,1,2,3,1,2}), 3);

    // Дубликаты из одного элемента
    EXPECT_EQ(template_library::longest_duplicate_subarray({1,2,2,3,3,4}), 1);

    // Дубликаты с отрицательными числами
    EXPECT_EQ(template_library::longest_duplicate_subarray({-1,0,-1,0}), 2);
}

TEST(LongestDuplicateSubarrayTest, PerformanceCases) {
    // Большой массив (10^5 элементов) - для проверки O(n log n)
    std::vector<int> big_array(100000, 7); // Все элементы 7
    EXPECT_EQ(template_library::longest_duplicate_subarray(big_array), 99999);

    // Паттерн: 1,2,3,4 повторяется 25000 раз
    std::vector<int> pattern;
    for (int i = 0; i < 25000; ++i) {
        pattern.insert(pattern.end(), {1,2,3,4});
    }
    EXPECT_EQ(template_library::longest_duplicate_subarray(pattern), 3);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
