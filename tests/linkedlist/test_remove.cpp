#include <gtest/gtest.h>
#include "SinglyList.h"
#include <stdexcept>

class SinglyListRemoveTest : public ::testing::Test
{
protected:
    SinglyList<int> list;

    void SetUp() override
    {
        for(int i=1;i<=5;i++)
            list.append(i);
    }
};

// ==========================================
// REMOVE()
// ==========================================

// Remove first element
TEST_F(SinglyListRemoveTest, RemoveFirstElement)
{
    list.remove(0);

    EXPECT_EQ(list.size(),4);

    EXPECT_EQ(list[0],2);
    EXPECT_EQ(list[1],3);
    EXPECT_EQ(list[2],4);
    EXPECT_EQ(list[3],5);
}

// Remove middle element
TEST_F(SinglyListRemoveTest, RemoveMiddleElement)
{
    list.remove(2);

    EXPECT_EQ(list.size(),4);

    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],4);
    EXPECT_EQ(list[3],5);
}

// Remove last element
TEST_F(SinglyListRemoveTest, RemoveLastElement)
{
    list.remove(list.size()-1);

    EXPECT_EQ(list.size(),4);

    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],3);
    EXPECT_EQ(list[3],4);
}

// Remove only element
TEST(SinglyListRemove, RemoveOnlyElement)
{
    SinglyList<int> list;

    list.append(10);

    list.remove(0);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

// Remove all elements
TEST(SinglyListRemove, RemoveAllElements)
{
    SinglyList<int> list;

    for(int i=0;i<5;i++)
        list.append(i);

    while(!list.isEmpty())
        list.remove(0);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

// Remove from empty list
TEST(SinglyListRemove, RemoveFromEmptyThrows)
{
    SinglyList<int> list;

    EXPECT_THROW(list.remove(0),std::out_of_range);
}

// Remove negative index
TEST(SinglyListRemove, RemoveNegativeIndexThrows)
{
    SinglyList<int> list;

    list.append(1);

    EXPECT_THROW(list.remove(-1),std::out_of_range);
}

// Remove index past end
TEST(SinglyListRemove, RemovePastEndThrows)
{
    SinglyList<int> list;

    list.append(1);

    EXPECT_THROW(list.remove(1),std::out_of_range);
}

// Remove from large dataset
TEST(SinglyListRemove, RemoveLargeDataset)
{
    SinglyList<int> list;

    for(int i=0;i<1000;i++)
        list.append(i);

    list.remove(500);

    EXPECT_EQ(list.size(),999);

    for(int i=0;i<500;i++)
        EXPECT_EQ(list[i],i);

    for(int i=500;i<999;i++)
        EXPECT_EQ(list[i],i+1);
}

// Multiple removals
TEST(SinglyListRemove, MultipleRemovals)
{
    SinglyList<int> list;

    for(int i=1;i<=5;i++)
        list.append(i);

    list.remove(0);
    list.remove(1);
    list.remove(2);

    EXPECT_EQ(list.size(),2);

    EXPECT_EQ(list[0],2);
    EXPECT_EQ(list[1],4);
}

// ==========================================
// REMOVE FRONT()
// ==========================================

// Remove front
TEST_F(SinglyListRemoveTest, RemoveFront)
{
    list.removeFront();

    EXPECT_EQ(list.size(),4);

    EXPECT_EQ(list[0],2);
    EXPECT_EQ(list[1],3);
    EXPECT_EQ(list[2],4);
    EXPECT_EQ(list[3],5);
}

// Remove front from single element list
TEST(SinglyListRemoveFront, RemoveFrontSingleElement)
{
    SinglyList<int> list;

    list.append(100);

    list.removeFront();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

// Remove front until empty
TEST(SinglyListRemoveFront, RemoveFrontRepeatedly)
{
    SinglyList<int> list;

    for(int i=1;i<=5;i++)
        list.append(i);

    while(!list.isEmpty())
        list.removeFront();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

// Remove front from empty list
TEST(SinglyListRemoveFront, RemoveFrontEmptyThrows)
{
    SinglyList<int> list;

    EXPECT_THROW(list.removeFront(),std::out_of_range);
}