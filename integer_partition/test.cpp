#include "solution.h"

#include <benchmark/benchmark.h>
#include <gtest/gtest.h>


namespace {

// The fixture for testing class Foo.
class IntegerPartitionTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  IntegerPartitionTest() {
     // You can do set-up work for each test here.
  }

  ~IntegerPartitionTest() override {
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


TEST_F(IntegerPartitionTest, Trivial1) {
    Solution sln;

    int res = sln.integerPartition(1);
    EXPECT_EQ(res, 1);

    res = sln.integerPartition(2);
    EXPECT_EQ(res, 2);

    res = sln.integerPartition(3);
    EXPECT_EQ(res, 3);

    res = sln.integerPartition(4);
    EXPECT_EQ(res, 5);

    res = sln.integerPartition(5);
    EXPECT_EQ(res, 7);

    res = sln.integerPartition(6);
    EXPECT_EQ(res, 11);

    res = sln.integerPartition(7);
    EXPECT_EQ(res, 15);

    res = sln.integerPartition(8);
    EXPECT_EQ(res, 22);

    res = sln.integerPartition(9);
    EXPECT_EQ(res, 30);

    res = sln.integerPartition(10);
    EXPECT_EQ(res, 42);

    res = sln.integerPartition(11);
    EXPECT_EQ(res, 56);

    res = sln.integerPartition(12);
    EXPECT_EQ(res, 77);

    res = sln.integerPartition(13);
    EXPECT_EQ(res, 101);

    res = sln.integerPartition(14);
    EXPECT_EQ(res, 135);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
