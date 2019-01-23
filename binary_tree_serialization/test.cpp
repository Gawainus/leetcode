#include "solution.h"

#include <benchmark/benchmark.h>
#include <gtest/gtest.h>


namespace {

// The fixture for testing class Foo.
class BinaryTreeSerialTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  BinaryTreeSerialTest() {
     // You can do set-up work for each test here.
  }

  ~BinaryTreeSerialTest() override {
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


TEST_F(BinaryTreeSerialTest, Serialization_1) {
    Codec sln;

    TreeNode root(1);
    TreeNode two(2);
    TreeNode three(3);
    TreeNode four(4);
    TreeNode five(5);

    root.left = &two;
    root.right = &three;
    three.left = &four;
    three.right = &five;

    const auto res = sln.serialize(&root);
    const std::string ans("1,2,~,~,3,4,~,~,5,~,~,");
    EXPECT_EQ(res, ans);

    const auto deserialized = sln.deserialize(res);
    EXPECT_EQ(deserialized->val, 1);
}

TEST_F(BinaryTreeSerialTest, Serialization_2) {
    Codec sln;

    TreeNode root(1);
    TreeNode two(2);
    TreeNode three(3);
    TreeNode four(4);
    TreeNode five(5);
    TreeNode six(6);

    root.left = &two;
    root.right = &three;
    three.left = &four;
    three.right = &five;
    four.right = &six;

    const auto res = sln.serialize(&root);
    const std::string ans("1,2,~,~,3,4,~,6,~,~,5,~,~,");
    EXPECT_EQ(res, ans);

}

TEST_F(BinaryTreeSerialTest, Serialization_3) {
    Codec sln;

    TreeNode twenty(20);
    TreeNode eight(8);
    TreeNode four(4);
    TreeNode twelve(12);
    TreeNode ten(10);
    TreeNode fourteen(14);

    twenty.left = &eight;
    eight.left = &four;
    eight.right = &twelve;
    twelve.left = &ten;
    twelve.right = &fourteen;

    const auto res = sln.serialize(&twenty);
    const std::string ans("20,8,4,~,~,12,10,~,~,14,~,~,~,");
    EXPECT_EQ(res, ans);

}


TEST_F(BinaryTreeSerialTest, Serialization_4) {
    Codec sln;

    TreeNode minus_one(-1);
    TreeNode zero(0);
    TreeNode one(1);

    minus_one.left = &zero;
    minus_one.right = &one;

    const auto res = sln.serialize(&minus_one);
    const std::string ans("-1,0,~,~,1,~,~,");
    EXPECT_EQ(res, ans);

    const auto deserialized = sln.deserialize(res);
    EXPECT_EQ(deserialized->val, -1);

}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
