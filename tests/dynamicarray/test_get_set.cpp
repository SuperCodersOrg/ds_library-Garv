#include <gtest/gtest.h>
#include "DynamicArray.h"
#include <stdexcept>

class DynamicArrayGetSetTest : public ::testing::Test
{
protected:
    DynamicArray<int> arr;

    void SetUp() override
    {
        for(int i=1;i<=5;i++)
            arr.append(i);
    }
};

// GET TESTS

// Get first element
TEST_F(DynamicArrayGetSetTest, GetFirstElement)
{
    int value;

    EXPECT_TRUE(arr.get(0,value));
    EXPECT_EQ(value,1);
}

// Get middle element
TEST_F(DynamicArrayGetSetTest, GetMiddleElement)
{
    int value;

    EXPECT_TRUE(arr.get(2,value));
    EXPECT_EQ(value,3);
}

// Get last element
TEST_F(DynamicArrayGetSetTest, GetLastElement)
{
    int value;

    EXPECT_TRUE(arr.get(arr.size()-1,value));
    EXPECT_EQ(value,5);
}

// Get invalid negative index
TEST(DynamicArrayGet, GetNegativeIndex)
{
    DynamicArray<int> arr;
    int value = -1;

    EXPECT_FALSE(arr.get(-1,value));
}

// Get index beyond size
TEST(DynamicArrayGet, GetPastEnd)
{
    DynamicArray<int> arr;

    arr.append(10);

    int value = -1;

    EXPECT_FALSE(arr.get(5,value));
}

// Get from empty array
TEST(DynamicArrayGet, GetFromEmptyArray)
{
    DynamicArray<int> arr;

    int value = -1;

    EXPECT_FALSE(arr.get(0,value));
}

// Get after multiple operations
TEST(DynamicArrayGet, GetAfterInsertRemove)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(2);
    arr.append(4);

    arr.insert(2,3);
    arr.remove(0);

    int value;

    EXPECT_TRUE(arr.get(0,value));
    EXPECT_EQ(value,2);

    EXPECT_TRUE(arr.get(1,value));
    EXPECT_EQ(value,3);

    EXPECT_TRUE(arr.get(2,value));
    EXPECT_EQ(value,4);
}

// SET TESTS

// Set first element
TEST_F(DynamicArrayGetSetTest, SetFirstElement)
{
    arr.set(0,100);

    EXPECT_EQ(arr[0],100);
}

// Set middle element
TEST_F(DynamicArrayGetSetTest, SetMiddleElement)
{
    arr.set(2,200);

    EXPECT_EQ(arr[2],200);
}

// Set last element
TEST_F(DynamicArrayGetSetTest, SetLastElement)
{
    arr.set(arr.size()-1,300);

    EXPECT_EQ(arr[arr.size()-1],300);
}

// Set negative index
TEST(DynamicArraySet, SetNegativeIndexThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.set(-1,10),std::out_of_range);
}

// Set past end
TEST(DynamicArraySet, SetPastEndThrows)
{
    DynamicArray<int> arr;

    arr.append(10);

    EXPECT_THROW(arr.set(5,20),std::out_of_range);
}

// Set on empty array
TEST(DynamicArraySet, SetOnEmptyArrayThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.set(0,10),std::out_of_range);
}

// Set multiple elements
TEST(DynamicArraySet, SetMultipleValues)
{
    DynamicArray<int> arr;

    for(int i=0;i<5;i++)
        arr.append(i);

    for(int i=0;i<5;i++)
        arr.set(i,i*10);

    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],i*10);
}