#include <gtest/gtest.h>
#include "SinglyList.h"
#include <stdexcept>

class SinglyListInsertTest : public ::testing::Test
{
protected:
    SinglyList<int> list;

    void SetUp() override
    {
        for(int i=1;i<=5;i++)
            list.append(i);
    }
};

// INSERT()

// Insert at beginning
TEST_F(SinglyListInsertTest, InsertAtBeginning)
{
    list.insert(0,100);

    EXPECT_EQ(list.size(),6);

    EXPECT_EQ(list[0],100);
    EXPECT_EQ(list[1],1);
    EXPECT_EQ(list[2],2);
    EXPECT_EQ(list[3],3);
    EXPECT_EQ(list[4],4);
    EXPECT_EQ(list[5],5);
}

// Insert in middle
TEST_F(SinglyListInsertTest, InsertAtMiddle)
{
    list.insert(2,99);

    EXPECT_EQ(list.size(),6);

    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],99);
    EXPECT_EQ(list[3],3);
    EXPECT_EQ(list[4],4);
    EXPECT_EQ(list[5],5);
}

// Insert at end
TEST_F(SinglyListInsertTest, InsertAtEnd)
{
    list.insert(list.size(),200);

    EXPECT_EQ(list.size(),6);
    EXPECT_EQ(list[5],200);
}

// Insert into empty list
TEST(SinglyListInsert, InsertIntoEmptyList)
{
    SinglyList<int> list;

    list.insert(0,10);

    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list[0],10);
}

// Insert into single element list
TEST(SinglyListInsert, InsertIntoSingleElementList)
{
    SinglyList<int> list;

    list.append(5);

    list.insert(1,10);

    EXPECT_EQ(list.size(),2);

    EXPECT_EQ(list[0],5);
    EXPECT_EQ(list[1],10);
}

// Invalid negative index
TEST(SinglyListInsert, InsertNegativeIndexThrows)
{
    SinglyList<int> list;

    EXPECT_THROW(list.insert(-1,10),std::out_of_range);
}

// Invalid index greater than size
TEST(SinglyListInsert, InsertPastEndThrows)
{
    SinglyList<int> list;

    list.append(1);

    EXPECT_THROW(list.insert(2,10),std::out_of_range);
}

// Large dataset
TEST(SinglyListInsert, InsertLargeDataset)
{
    SinglyList<int> list;

    for(int i=0;i<1000;i++)
        list.append(i);

    list.insert(500,-1);

    EXPECT_EQ(list.size(),1001);
    EXPECT_EQ(list[500],-1);

    for(int i=0;i<500;i++)
        EXPECT_EQ(list[i],i);

    for(int i=501;i<1001;i++)
        EXPECT_EQ(list[i],i-1);
}

// Multiple insertions
TEST(SinglyListInsert, MultipleInsertions)
{
    SinglyList<int> list;

    list.append(1);
    list.append(3);

    list.insert(1,2);
    list.insert(3,4);
    list.insert(4,5);

    EXPECT_EQ(list.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(list[i],i+1);
}

// INSERT FRONT()

// Insert front on empty list
TEST(SinglyListInsertFront, InsertFrontEmpty)
{
    SinglyList<int> list;

    list.insertFront(10);

    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list[0],10);
}

// Insert front on non-empty list
TEST(SinglyListInsertFront, InsertFrontNonEmpty)
{
    SinglyList<int> list;

    list.append(20);
    list.append(30);

    list.insertFront(10);

    EXPECT_EQ(list.size(),3);

    EXPECT_EQ(list[0],10);
    EXPECT_EQ(list[1],20);
    EXPECT_EQ(list[2],30);
}

// Multiple insertFront operations
TEST(SinglyListInsertFront, MultipleInsertFront)
{
    SinglyList<int> list;

    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);

    EXPECT_EQ(list.size(),3);

    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],3);
}

// InsertFront after append
TEST(SinglyListInsertFront, InsertFrontAfterAppend)
{
    SinglyList<int> list;

    list.append(2);
    list.append(3);

    list.insertFront(1);

    EXPECT_EQ(list.size(),3);

    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],3);
}