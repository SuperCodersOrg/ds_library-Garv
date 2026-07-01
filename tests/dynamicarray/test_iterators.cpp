#include <gtest/gtest.h>
#include "DynamicArray.h"

// BEGIN / END

TEST(DynamicArrayIterator, BeginPointsToFirstElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    EXPECT_EQ(*arr.begin(),10);
}

TEST(DynamicArrayIterator, EndMinusBeginEqualsSize)
{
    DynamicArray<int> arr;

    for(int i=0;i<10;i++)
        arr.append(i);

    EXPECT_EQ(arr.end()-arr.begin(),arr.size());
}

TEST(DynamicArrayIterator, IterateUsingPointers)
{
    DynamicArray<int> arr;

    for(int i=1;i<=5;i++)
        arr.append(i);

    int expected=1;

    for(auto it=arr.begin();it!=arr.end();++it)
    {
        EXPECT_EQ(*it,expected);
        expected++;
    }
}

TEST(DynamicArrayIterator, EmptyArrayBeginEqualsEnd)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.begin(),arr.end());
}

// RANGE BASED FOR LOOP

TEST(DynamicArrayIterator, RangeBasedForLoop)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);

    int sum=0;

    for(int value:arr)
        sum+=value;

    EXPECT_EQ(sum,6);
}

TEST(DynamicArrayIterator, ModifyUsingIterator)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);

    for(auto it=arr.begin();it!=arr.end();++it)
        *it*=2;

    EXPECT_EQ(arr[0],2);
    EXPECT_EQ(arr[1],4);
    EXPECT_EQ(arr[2],6);
}

// ITERATOR CONSTRUCTOR

TEST(DynamicArrayIteratorConstructor, ConstructFromArray)
{
    int data[]={1,2,3,4,5};

    DynamicArray<int> arr(data,data+5);

    EXPECT_EQ(arr.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],i+1);
}

TEST(DynamicArrayIteratorConstructor, ConstructSingleElement)
{
    int data[]={100};

    DynamicArray<int> arr(data,data+1);

    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],100);
}

TEST(DynamicArrayIteratorConstructor, ConstructEmptyRange)
{
    int data[]={1,2,3};

    DynamicArray<int> arr(data,data);

    EXPECT_EQ(arr.size(),0);
    EXPECT_TRUE(arr.isEmpty());
}

// GENERIC DS CONSTRUCTOR

TEST(DynamicArrayDSConstructor, ConstructFromDynamicArray)
{
    DynamicArray<int> original;

    for(int i=1;i<=5;i++)
        original.append(i);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(copy[i],i+1);
}

TEST(DynamicArrayDSConstructor, IndependentCopy)
{
    DynamicArray<int> original;
    original.append(10);
    original.append(20);
    DynamicArray<int> copy(original);
    copy[0]=100;
    EXPECT_EQ(original[0],10);
    EXPECT_EQ(copy[0],100);
}

TEST(DynamicArrayDSConstructor, ConstructFromEmptyDynamicArray)
{
    DynamicArray<int> original;
    DynamicArray<int> copy(original);
    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(),0);
}