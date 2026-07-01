#include <gtest/gtest.h>
#include "DynamicArray.h"
#include <stdexcept>

// APPEND TESTS

// Append into an empty array.
TEST(DynamicArrayAppend, AppendSingleElement)
{
    DynamicArray<int> arr;
    arr.append(10);
    EXPECT_EQ(arr.size(),1);
    EXPECT_FALSE(arr.isEmpty());
    EXPECT_EQ(arr[0],10);
}

// Append multiple elements and verify order.
TEST(DynamicArrayAppend, AppendMultipleElements)
{
    DynamicArray<int> arr;
    for(int i=1;i<=5;i++)
        arr.append(i);
    EXPECT_EQ(arr.size(),5);
    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],i+1);
}

// Append should automatically resize when capacity is full.
TEST(DynamicArrayAppend, AppendTriggersResize)
{
    DynamicArray<int> arr;
    arr.reserve(2);
    arr.append(1);
    arr.append(2);
    int oldCap=arr.capacity();
    arr.append(3);
    EXPECT_GT(arr.capacity(),oldCap);
    EXPECT_EQ(arr.size(),3);
    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],3);
}

// Append a large number of elements.
TEST(DynamicArrayAppend, AppendLargeDataset)
{
    DynamicArray<int> arr;
    for(int i=0;i<1000;i++)
        arr.append(i);
    EXPECT_EQ(arr.size(),1000);
    for(int i=0;i<1000;i++)
        EXPECT_EQ(arr[i],i);
}

// Verify order is preserved after multiple resizes.
TEST(DynamicArrayAppend, MultipleResizesMaintainOrder)
{
    DynamicArray<int> arr;
    for(int i=0;i<5000;i++)
        arr.append(i);
    EXPECT_EQ(arr.size(),5000);
    EXPECT_EQ(arr[0],0);
    EXPECT_EQ(arr[100],100);
    EXPECT_EQ(arr[999],999);
    EXPECT_EQ(arr[2500],2500);
    EXPECT_EQ(arr[4999],4999);
}

// Append after clearing the array.
TEST(DynamicArrayAppend, AppendAfterClear)
{
    DynamicArray<int> arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.clear();
    arr.append(100);
    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],100);
}

// Append different values including negatives.
TEST(DynamicArrayAppend, AppendNegativeAndZeroValues)
{
    DynamicArray<int> arr;
    arr.append(-10);
    arr.append(0);
    arr.append(20);
    EXPECT_EQ(arr.size(),3);
    EXPECT_EQ(arr[0],-10);
    EXPECT_EQ(arr[1],0);
    EXPECT_EQ(arr[2],20);
}