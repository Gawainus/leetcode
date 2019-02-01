#include "solution.h"

#include <benchmark/benchmark.h>
#include <gtest/gtest.h>


namespace {

// The fixture for testing class Foo.
class NumIslandsTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  NumIslandsTest() {
     // You can do set-up work for each test here.
  }

  ~NumIslandsTest() override {
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


TEST_F(NumIslandsTest, Trivial1) {
    Solution sln;
    std::vector<std::vector<char>> test = {{}};
    int res = sln.numIslands(test);

    EXPECT_EQ(res, 0);
}


TEST_F(NumIslandsTest, Trivia2) {
    Solution sln;
    std::vector<std::vector<char>> test = {{1},{1},{1}};
    int res = sln.numIslands(test);

    EXPECT_EQ(res, 1);
}

TEST_F(NumIslandsTest, Test1) {
    Solution sln;
    std::vector<std::vector<char>> test = {{1,1,1},{0,1,0},{1,1,1}};
    int res = sln.numIslands(test);

    EXPECT_EQ(res, 1);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
