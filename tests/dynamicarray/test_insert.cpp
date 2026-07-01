#include <gtest/gtest.h>
#include "DynamicArray.h"
#include <stdexcept>

class DynamicArrayInsertTest : public ::testing::Test
{
protected:
    DynamicArray<int> arr;

    void SetUp() override
    {
        for(int i=1;i<=5;i++)
            arr.append(i);
    }
};

// INSERT TESTS

// Insert at beginning
TEST_F(DynamicArrayInsertTest, InsertAtBeginning)
{
    arr.insert(0,100);

    EXPECT_EQ(arr.size(),6);

    EXPECT_EQ(arr[0],100);
    EXPECT_EQ(arr[1],1);
    EXPECT_EQ(arr[2],2);
    EXPECT_EQ(arr[3],3);
    EXPECT_EQ(arr[4],4);
    EXPECT_EQ(arr[5],5);
}

// Insert in middle
TEST_F(DynamicArrayInsertTest, InsertAtMiddle)
{
    arr.insert(2,99);

    EXPECT_EQ(arr.size(),6);

    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],99);
    EXPECT_EQ(arr[3],3);
    EXPECT_EQ(arr[4],4);
    EXPECT_EQ(arr[5],5);
}

// Insert at end
TEST_F(DynamicArrayInsertTest, InsertAtEnd)
{
    arr.insert(arr.size(),200);

    EXPECT_EQ(arr.size(),6);
    EXPECT_EQ(arr[5],200);
}

// Insert into empty array
TEST(DynamicArrayInsert, InsertIntoEmptyArray)
{
    DynamicArray<int> arr;

    arr.insert(0,10);

    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],10);
}

// Insert at index 0 in single element array
TEST(DynamicArrayInsert, InsertBeginningSingleElement)
{
    DynamicArray<int> arr;

    arr.append(5);

    arr.insert(0,10);

    EXPECT_EQ(arr.size(),2);
    EXPECT_EQ(arr[0],10);
    EXPECT_EQ(arr[1],5);
}

// Insert at end in single element array
TEST(DynamicArrayInsert, InsertEndSingleElement)
{
    DynamicArray<int> arr;

    arr.append(5);

    arr.insert(1,10);

    EXPECT_EQ(arr.size(),2);
    EXPECT_EQ(arr[0],5);
    EXPECT_EQ(arr[1],10);
}

// Insert triggers resize
TEST(DynamicArrayInsert, InsertTriggersResize)
{
    DynamicArray<int> arr;

    arr.reserve(2);

    arr.append(1);
    arr.append(2);

    int oldCap=arr.capacity();

    arr.insert(1,99);

    EXPECT_GT(arr.capacity(),oldCap);

    EXPECT_EQ(arr.size(),3);

    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],99);
    EXPECT_EQ(arr[2],2);
}

// Insert negative index
TEST(DynamicArrayInsert, InsertNegativeIndexThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.insert(-1,5),std::out_of_range);
}

// Insert past end
TEST(DynamicArrayInsert, InsertPastEndThrows)
{
    DynamicArray<int> arr;

    arr.append(1);

    EXPECT_THROW(arr.insert(2,5),std::out_of_range);
}

// Insert into large dataset
TEST(DynamicArrayInsert, InsertLargeDataset)
{
    DynamicArray<int> arr;

    for(int i=0;i<1000;i++)
        arr.append(i);

    arr.insert(500,-1);

    EXPECT_EQ(arr.size(),1001);
    EXPECT_EQ(arr[500],-1);

    for(int i=0;i<500;i++)
        EXPECT_EQ(arr[i],i);

    for(int i=501;i<1001;i++)
        EXPECT_EQ(arr[i],i-1);
}

// Insert multiple times
TEST(DynamicArrayInsert, MultipleInsertions)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(3);

    arr.insert(1,2);
    arr.insert(3,4);
    arr.insert(4,5);

    EXPECT_EQ(arr.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],i+1);
}

// Insert duplicate values
TEST(DynamicArrayInsert, InsertDuplicateValues)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    arr.insert(1,20);

    EXPECT_EQ(arr.size(),3);

    EXPECT_EQ(arr[0],10);
    EXPECT_EQ(arr[1],20);
    EXPECT_EQ(arr[2],20);
}