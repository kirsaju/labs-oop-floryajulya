#include <gtest/gtest.h>
#include <lib.h>

TEST(Test1, BasicAssertions) {
  // arrange 
  std::string str = "(())";

  // act
  bool result = checkBracesValidity(str);
  // assert
  EXPECT_EQ(result, true);
}

TEST(Test2, BasicAssertions) {
  // arrange 
  std::string str = ")(()))";

  // act
  bool result = checkBracesValidity(str);
  // assert
  EXPECT_EQ(result, false);
}

TEST(Test3, BasicAssertions) {
  // arrange 
  std::string str = "";

  // act
  bool result = checkBracesValidity(str);
  // assert
  EXPECT_EQ(result, true);
}

TEST(Test4, BasicAssertions) {
  // arrange
  std::string str = "(()))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))";
  // act assert
  ASSERT_THROW(checkBracesValidity(str), std::invalid_argument);
  }