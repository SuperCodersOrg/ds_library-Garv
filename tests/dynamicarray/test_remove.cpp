#include <gtest/gtest.h>
#include "DynamicArray.h"
#include <stdexcept>

class DynamicArrayRemoveTest : public ::testing::Test
{
protected:
    DynamicArray<int> arr;

    void SetUp() override
    {
        for(int i=1;i<=5;i++)
            arr.append(i);
    }
};

// REMOVE TESTS

// Remove first element
TEST_F(DynamicArrayRemoveTest, RemoveFirstElement)
{
    arr.remove(0);

    EXPECT_EQ(arr.size(),4);

    EXPECT_EQ(arr[0],2);
    EXPECT_EQ(arr[1],3);
    EXPECT_EQ(arr[2],4);
    EXPECT_EQ(arr[3],5);
}

// Remove middle element
TEST_F(DynamicArrayRemoveTest, RemoveMiddleElement)
{
    arr.remove(2);

    EXPECT_EQ(arr.size(),4);

    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],4);
    EXPECT_EQ(arr[3],5);
}

// Remove last element
TEST_F(DynamicArrayRemoveTest, RemoveLastElement)
{
    arr.remove(arr.size()-1);

    EXPECT_EQ(arr.size(),4);

    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],3);
    EXPECT_EQ(arr[3],4);
}

// Remove only element
TEST(DynamicArrayRemove, RemoveOnlyElement)
{
    DynamicArray<int> arr;

    arr.append(10);

    arr.remove(0);

    EXPECT_EQ(arr.size(),0);
    EXPECT_TRUE(arr.isEmpty());
}

// Remove from empty array
TEST(DynamicArrayRemove, RemoveFromEmptyThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.remove(0),std::out_of_range);
}

// Remove negative index
TEST(DynamicArrayRemove, RemoveNegativeIndexThrows)
{
    DynamicArray<int> arr;

    arr.append(1);

    EXPECT_THROW(arr.remove(-1),std::out_of_range);
}

// Remove index greater than size
TEST(DynamicArrayRemove, RemovePastEndThrows)
{
    DynamicArray<int> arr;

    arr.append(1);

    EXPECT_THROW(arr.remove(1),std::out_of_range);
}

// Remove multiple elements
TEST(DynamicArrayRemove, MultipleRemovals)
{
    DynamicArray<int> arr;

    for(int i=1;i<=5;i++)
        arr.append(i);

    arr.remove(0);
    arr.remove(1);
    arr.remove(2);

    EXPECT_EQ(arr.size(),2);

    EXPECT_EQ(arr[0],2);
    EXPECT_EQ(arr[1],4);
}

// Remove all elements one by one
TEST(DynamicArrayRemove, RemoveAllElements)
{
    DynamicArray<int> arr;

    for(int i=0;i<5;i++)
        arr.append(i);

    while(!arr.isEmpty())
        arr.remove(0);

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(),0);
}

// Remove from large dataset
TEST(DynamicArrayRemove, RemoveLargeDataset)
{
    DynamicArray<int> arr;

    for(int i=0;i<1000;i++)
        arr.append(i);

    arr.remove(500);

    EXPECT_EQ(arr.size(),999);

    for(int i=0;i<500;i++)
        EXPECT_EQ(arr[i],i);

    for(int i=500;i<999;i++)
        EXPECT_EQ(arr[i],i+1);
}

// Remove after resize
TEST(DynamicArrayRemove, RemoveAfterResize)
{
    DynamicArray<int> arr;

    for(int i=0;i<100;i++)
        arr.append(i);

    arr.remove(50);

    EXPECT_EQ(arr.size(),99);

    EXPECT_EQ(arr[49],49);
    EXPECT_EQ(arr[50],51);
}