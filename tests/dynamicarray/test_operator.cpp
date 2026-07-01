#include <gtest/gtest.h>
#include "DynamicArray.h"
#include <stdexcept>

// NON-CONST OPERATOR[]

// Read first element
TEST(DynamicArrayOperator, ReadFirstElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    EXPECT_EQ(arr[0],10);
}

// Read last element
TEST(DynamicArrayOperator, ReadLastElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    EXPECT_EQ(arr[2],30);
}

// Modify first element
TEST(DynamicArrayOperator, ModifyFirstElement)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(2);

    arr[0]=100;

    EXPECT_EQ(arr[0],100);
    EXPECT_EQ(arr[1],2);
}

// Modify middle element
TEST(DynamicArrayOperator, ModifyMiddleElement)
{
    DynamicArray<int> arr;

    for(int i=1;i<=5;i++)
        arr.append(i);

    arr[2]=999;

    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],999);
    EXPECT_EQ(arr[3],4);
    EXPECT_EQ(arr[4],5);
}

// Modify last element
TEST(DynamicArrayOperator, ModifyLastElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    arr[1]=500;

    EXPECT_EQ(arr[1],500);
}

// CONST OPERATOR[]

TEST(DynamicArrayOperator, ConstRead)
{
    DynamicArray<int> temp;

    temp.append(10);
    temp.append(20);
    temp.append(30);

    const DynamicArray<int>& arr=temp;

    EXPECT_EQ(arr[0],10);
    EXPECT_EQ(arr[1],20);
    EXPECT_EQ(arr[2],30);
}

// STRESS TEST

TEST(DynamicArrayOperator, LargeDatasetAccess)
{
    DynamicArray<int> arr;

    for(int i=0;i<1000;i++)
        arr.append(i);

    for(int i=0;i<1000;i++)
        EXPECT_EQ(arr[i],i);
}

// EXPRESSION TEST

TEST(DynamicArrayOperator, ArithmeticExpression)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    int sum=arr[0]+arr[1];

    EXPECT_EQ(sum,30);
}