#include <gtest/gtest.h>
#include "DynamicArray.h"

// CLEAR

TEST(DynamicArrayUtility, ClearNonEmptyArray)
{
    DynamicArray<int> arr;

    for(int i=0;i<5;i++)
        arr.append(i);

    int oldCap = arr.capacity();

    arr.clear();

    EXPECT_EQ(arr.size(),0);
    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.capacity(),oldCap);
}

TEST(DynamicArrayUtility, ClearEmptyArray)
{
    DynamicArray<int> arr;

    arr.clear();

    EXPECT_EQ(arr.size(),0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(DynamicArrayUtility, AppendAfterClear)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(2);

    arr.clear();

    arr.append(100);

    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],100);
}

TEST(DynamicArrayUtility, ClearMultipleTimes)
{
    DynamicArray<int> arr;

    arr.append(10);

    arr.clear();
    arr.clear();

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(),0);
}

// RESERVE

TEST(DynamicArrayUtility, ReserveIncreaseCapacity)
{
    DynamicArray<int> arr;

    arr.reserve(100);

    EXPECT_GE(arr.capacity(),100);
    EXPECT_EQ(arr.size(),0);
}

TEST(DynamicArrayUtility, ReserveSmallerCapacity)
{
    DynamicArray<int> arr;

    arr.reserve(20);

    int oldCap = arr.capacity();

    arr.reserve(10);

    EXPECT_EQ(arr.capacity(),oldCap);
}

TEST(DynamicArrayUtility, ReserveEqualCapacity)
{
    DynamicArray<int> arr;

    arr.reserve(30);

    int oldCap = arr.capacity();

    arr.reserve(oldCap);

    EXPECT_EQ(arr.capacity(),oldCap);
}

TEST(DynamicArrayUtility, ReserveDoesNotChangeElements)
{
    DynamicArray<int> arr;

    for(int i=0;i<5;i++)
        arr.append(i);

    arr.reserve(100);

    EXPECT_EQ(arr.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],i);
}

// SHRINK TO SIZE

TEST(DynamicArrayUtility, ShrinkToSize)
{
    DynamicArray<int> arr;

    arr.reserve(100);

    arr.append(1);
    arr.append(2);

    arr.shrinktosize();

    EXPECT_EQ(arr.capacity(),2);
    EXPECT_EQ(arr.size(),2);
}

TEST(DynamicArrayUtility, ShrinkAlreadyExact)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(2);

    arr.shrinktosize();

    EXPECT_EQ(arr.capacity(),arr.size());
}

TEST(DynamicArrayUtility, ShrinkEmptyArray)
{
    DynamicArray<int> arr;

    arr.reserve(50);

    arr.shrinktosize();

    EXPECT_EQ(arr.size(),0);
    EXPECT_EQ(arr.capacity(),0);
}

TEST(DynamicArrayUtility, ShrinkPreservesData)
{
    DynamicArray<int> arr;

    arr.reserve(50);

    for(int i=0;i<10;i++)
        arr.append(i);

    arr.shrinktosize();

    EXPECT_EQ(arr.size(),10);
    EXPECT_EQ(arr.capacity(),10);

    for(int i=0;i<10;i++)
        EXPECT_EQ(arr[i],i);
}

// ISEMPTY

TEST(DynamicArrayUtility, IsEmptyInitially)
{
    DynamicArray<int> arr;

    EXPECT_TRUE(arr.isEmpty());
}

TEST(DynamicArrayUtility, IsEmptyAfterAppend)
{
    DynamicArray<int> arr;

    arr.append(1);

    EXPECT_FALSE(arr.isEmpty());
}

TEST(DynamicArrayUtility, IsEmptyAfterClear)
{
    DynamicArray<int> arr;

    arr.append(1);

    arr.clear();

    EXPECT_TRUE(arr.isEmpty());
}

// SIZE

TEST(DynamicArrayUtility, SizeInitially)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(),0);
}

TEST(DynamicArrayUtility, SizeAfterAppend)
{
    DynamicArray<int> arr;

    for(int i=0;i<10;i++)
        arr.append(i);

    EXPECT_EQ(arr.size(),10);
}

TEST(DynamicArrayUtility, SizeAfterRemove)
{
    DynamicArray<int> arr;

    for(int i=0;i<5;i++)
        arr.append(i);

    arr.remove(2);

    EXPECT_EQ(arr.size(),4);
}

// CAPACITY

TEST(DynamicArrayUtility, CapacityInitially)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.capacity(),0);
}

TEST(DynamicArrayUtility, CapacityAfterReserve)
{
    DynamicArray<int> arr;

    arr.reserve(50);

    EXPECT_GE(arr.capacity(),50);
}

TEST(DynamicArrayUtility, CapacityAfterShrink)
{
    DynamicArray<int> arr;

    arr.reserve(100);

    for(int i=0;i<5;i++)
        arr.append(i);

    arr.shrinktosize();

    EXPECT_EQ(arr.capacity(),5);
}