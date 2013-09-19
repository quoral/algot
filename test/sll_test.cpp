#include "include/SLLNode.h"
#include "include/SLL.h"
#include "gtest/gtest.h"

class SLLTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    sl0 = new algot::SLL();
    sl1 = new algot::SLL();
    sl2 = new algot::SLL();
  }
  virtual void TearDown(){
    delete sl0;
    delete sl1;
    delete sl2;
  }
  algot::SLL *sl0;
  algot::SLL *sl1;
  algot::SLL *sl2;
};

TEST_F(SLLTest, IsEmpty){
  EXPECT_TRUE(sl0->isEmpty());
  EXPECT_TRUE(sl1->isEmpty());
  EXPECT_TRUE(sl2->isEmpty());
}

TEST_F(SLLTest, AddElementIdentical){
  EXPECT_TRUE(sl0->addElement(1));
  EXPECT_FALSE(sl0->addElement(1));
}

TEST_F(SLLTest, AddElementSeries){
  EXPECT_TRUE(sl1->addElement(1));
  EXPECT_TRUE(sl1->addElement(2));
  for(int i = 0; i < 100; i++){
    EXPECT_TRUE(sl2->addElement(i));
  }
}

TEST_F(SLLTest, DeleteElementIdentical){
  sl0->addElement(1);
  EXPECT_TRUE(sl0->deleteElement(1));
  EXPECT_FALSE(sl0->deleteElement(1));
}

TEST_F(SLLTest, DeleteElementSeries){
  for(int i = 0; i < 100; i++){
    sl1->addElement(i);
  }
  for(int i = 0; i < 100; i++){
    EXPECT_TRUE(sl1->deleteElement(i));
  }
}

TEST_F(SLLTest, AddSize){
  for(int i = 0; i < 100; i++){
    EXPECT_TRUE(sl2->addElement(i));
    EXPECT_EQ(i+1, sl2->size());
  }
}

TEST_F(SLLTest, SubtractSize){
  int count = 100;
  for(int i = 0; i <= count; i++){
    sl2->addElement(i);
  }
  for(int i = 0; i <= count; i++){
    sl2->deleteElement(i);
    EXPECT_EQ(count-i, sl2->size());
  }
}

TEST_F(SLLTest, ToArray){
  int count = 100;
  int* array = new int[count];
  for(int i = 0; i < count; i++){
    array[i] = i;
    sl0->addElement(i);
  }
  int countCompare;
  int* compareArray = sl0->toArray(countCompare);
  ASSERT_EQ(count, countCompare);
  for(int i = 0; i < count; i++){
    ASSERT_EQ(array[i], compareArray[i]);
  }
}


