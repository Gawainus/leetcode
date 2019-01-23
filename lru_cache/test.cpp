#include "solution.h"

#include <benchmark/benchmark.h>
#include <gtest/gtest.h>


namespace {

// The fixture for testing class Foo.
class LRUCacheTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  LRUCacheTest() {
     // You can do set-up work for each test here.
  }

  ~LRUCacheTest() override {
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


TEST_F(LRUCacheTest, Test_1) {

    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3,3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4,4);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

TEST_F(LRUCacheTest, Test_2) {

    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3,3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4,4);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}


TEST_F(LRUCacheTest, Test_Final) {

    LRUCache cache(10);
    cache.put(10,13);
    cache.put(3,17);
    cache.put(6,11);
    cache.put(10,5);
    cache.put(9,10);
    EXPECT_EQ(cache.get(13), -1);

    cache.put(2,19);
    EXPECT_EQ(cache.get(2), 19);
    EXPECT_EQ(cache.get(3), 17);

    cache.put(5,25);
    EXPECT_EQ(cache.get(8), -1);

    // [9,22],[5,5],[1,30],[11]
    cache.put(9,22);
    cache.put(5,5);
    cache.put(1,30);
    EXPECT_EQ(cache.get(11), -1);

    // [9,12],[7],[5],[8],[9],
    cache.put(9, 12);
    EXPECT_EQ(cache.get(7), -1);
    EXPECT_EQ(cache.get(5), 5);
    EXPECT_EQ(cache.get(8), -1);
    EXPECT_EQ(cache.get(9), 12);

    // [4,30],[9,3],[9],[10],[10]
    cache.put(4, 30);
    cache.put(9,3);
    EXPECT_EQ(cache.get(9), 3);
    EXPECT_EQ(cache.get(10), 5);
    EXPECT_EQ(cache.get(10), 5);

    // [6,14],[3,1],[3]
    cache.put(6, 14);
    cache.put(3, 1);
    EXPECT_EQ(cache.get(3), 1);

    // [10,11],[8]
    cache.put(10, 11);
    EXPECT_EQ(cache.get(8), -1);

    // [2,14],[1],[5],[4]
    cache.put(2, 14);
    EXPECT_EQ(cache.get(1), 30);
    EXPECT_EQ(cache.get(5), 5);
    EXPECT_EQ(cache.get(4), 30);

    // [11,4],[12,24],[5,18],[13]
    cache.put(11, 4);
    cache.put(12, 24);
    cache.put(5, 18);
    EXPECT_EQ(cache.get(13), -1);

    //[7,23],[8],[12]
    cache.put(7, 23);
    EXPECT_EQ(cache.get(8), -1);
    EXPECT_EQ(cache.get(12), 24);

    // [3,27],[2,12],[5]
    cache.put(3, 27);
    cache.put(2, 12);
    EXPECT_EQ(cache.get(5), 18);

    // [2,9],[13,4],[8,18],[1,7],[6]
    cache.put(2, 9);
    cache.put(13, 4);
    cache.put(8, 18);
    cache.put(1, 7);
    EXPECT_EQ(cache.get(6), -1);

    // [9,29],[8,21],[5]
    cache.put(9, 29);
    cache.put(8, 21);
    EXPECT_EQ(cache.get(5), 18);

    // [6,30],[1,12],[10]
    cache.put(6, 30);
    cache.put(1, 12);
    EXPECT_EQ(cache.get(10), -1);

    // [4,15],[7,22],[11,26],[8,17],[9,29],[5]
    cache.put(4, 15);
    cache.put(7, 22);
    cache.put(11, 26);
    cache.put(8, 17);
    cache.put(9, 29);
    EXPECT_EQ(cache.get(5), 18);

    // [3,4],[11,30],[12]
    cache.put(3, 4);
    cache.put(11, 30);
    EXPECT_EQ(cache.get(12), -1);

    // [4,29],[3],[9],[6]
    cache.put(4, 29);
    EXPECT_EQ(cache.get(3), 4);
    EXPECT_EQ(cache.get(9), 29);
    EXPECT_EQ(cache.get(6), 30);

    // [3,4],[1],[10]
    cache.put(3, 4);
    EXPECT_EQ(cache.get(1), 12);
    EXPECT_EQ(cache.get(10), -1);

    // [3,29],[10,28],[1,20],[11,13],[3]
    cache.put(3, 29);
    cache.put(10, 28);
    cache.put(1, 20);
    cache.put(11, 13);
    EXPECT_EQ(cache.get(3), 29);

    // [3,12],[3,8],[10,9],[3,26],[8],[7],[5]
    cache.put(3, 12);
    cache.put(3, 8);
    cache.put(10, 9);
    cache.put(3, 26);
    EXPECT_EQ(cache.get(8), 17);
    EXPECT_EQ(cache.get(7), 22);
    EXPECT_EQ(cache.get(5), 18);

    // [13,17],[2,27],[11,15],[12]
    cache.put(13, 17);
    cache.put(2, 27);
    cache.put(11, 15);
    EXPECT_EQ(cache.get(12), -1);

    // [9,19],[2,15],[3,16],[1]
    cache.put(9, 19);
    cache.put(2, 15);
    cache.put(3, 16);
    EXPECT_EQ(cache.get(1), 20);

    // [12,17],[9,1],[6,19],[4],[5],[5]
    cache.put(12, 17);
    cache.put(9, 1);
    cache.put(6, 19);
    EXPECT_EQ(cache.get(4), -1);
    EXPECT_EQ(cache.get(5), 18);
    EXPECT_EQ(cache.get(6), 19);

    // [8,1],[11,7],[5,2],[9,28],[1]
    cache.put(8, 1);
    cache.put(11, 7);
    cache.put(5, 2);
    cache.put(9, 28);
    EXPECT_EQ(cache.get(1), 20);

    // [2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]
    cache.put(2, 2);
    cache.put(7, 4);
    cache.put(4, 22);
    cache.put(7, 24);
    cache.put(9, 26);
    cache.put(13, 28);
    cache.put(11, 26);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
