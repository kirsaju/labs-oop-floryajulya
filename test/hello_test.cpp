#include <gtest/gtest.h>
#include <lib.h>

TEST(HelloTest, BasicAssertions) {
  // arrange 
  std::string str = "(())";

  // act
  bool result = checkBracesValidity(str);
  // assert
  EXPECT_EQ(result, true);
}

TEST(HelloTest2, BasicAssertions) {
  // arrange 
  std::string str = ")(()))";

  // act
  bool result = checkBracesValidity(str);
  // assert
  EXPECT_EQ(result, false);
}

TEST(HelloTest3, BasicAssertions) {
  // arrange 
  std::string str = "";

  // act
  bool result = checkBracesValidity(str);
  // assert
  EXPECT_EQ(result, true);
}

TEST(HelloTest4, BasicAssertions) {
  // arrange
  std::string str = "(()))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))";

  try {
    // act
    bool result = checkBracesValidity(str);
  }
  catch (std::invalid_argument ex) {
    // assert
    EXPECT_STREQ("String limit", ex.what());
  }
}