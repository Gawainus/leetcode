#include "solution.h"

#include <benchmark/benchmark.h>
#include <gtest/gtest.h>


namespace {

// The fixture for testing class Foo.
class FirstMissingPositiveTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  FirstMissingPositiveTest() {
     // You can do set-up work for each test here.
  }

  ~FirstMissingPositiveTest() override {
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


TEST_F(FirstMissingPositiveTest, Trivial_1) {
    Solution sln;
    int res;

    std::vector<int> data{1, 2, 0};
    res = sln.firstMissingPositive(data);
    EXPECT_EQ(res, 3);
}

TEST_F(FirstMissingPositiveTest, Trivial_2) {
    Solution sln;
    int res;

    std::vector<int> data{0};
    res = sln.firstMissingPositive(data);
    EXPECT_EQ(res, 1);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
