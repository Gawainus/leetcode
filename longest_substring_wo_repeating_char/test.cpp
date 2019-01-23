#include "solution.h"

#include <benchmark/benchmark.h>
#include <gtest/gtest.h>


namespace {

// The fixture for testing class Foo.
class LongestSubStringWORepeatingCharTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

    LongestSubStringWORepeatingCharTest() {
     // You can do set-up work for each test here.
  }

  ~LongestSubStringWORepeatingCharTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};


TEST_F(LongestSubStringWORepeatingCharTest, Trivial_1) {
    Solution sln;
    std::string test;
    int res = sln.lengthOfLongestSubstring(test);

    EXPECT_EQ(res, 0);
}

TEST_F(LongestSubStringWORepeatingCharTest, Test_1) {
    Solution sln;
    std::string test{"pwwkew"};
    int res = sln.lengthOfLongestSubstring(test);

    EXPECT_EQ(res, 3);
}

TEST_F(LongestSubStringWORepeatingCharTest, Test_2) {
    Solution sln;
    std::string test{" "};
    int res = sln.lengthOfLongestSubstring(test);

    EXPECT_EQ(res, 1);
}



}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
