#include <gtest/gtest.h>
#include "DynamicArray.h"

// DEFAULT CONSTRUCTOR

TEST(DynamicArrayConstructor, DefaultConstructor)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(),0);
    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.capacity(),0);
}

// CAPACITY CONSTRUCTOR

TEST(DynamicArrayConstructor, CapacityConstructor)
{
    DynamicArray<int> arr(10);

    EXPECT_EQ(arr.size(),0);
    EXPECT_GE(arr.capacity(),10);
}

TEST(DynamicArrayConstructor, ZeroCapacityConstructor)
{
    DynamicArray<int> arr(0);

    EXPECT_EQ(arr.size(),0);
    EXPECT_TRUE(arr.capacity()>=0);
}

TEST(DynamicArrayConstructor, CapacityConstructorAppend)
{
    DynamicArray<int> arr(5);

    arr.append(1);
    arr.append(2);
    arr.append(3);

    EXPECT_EQ(arr.size(),3);
    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],3);
}

// FILL CONSTRUCTOR

TEST(DynamicArrayConstructor, FillConstructor)
{
    DynamicArray<int> arr(5,100);

    EXPECT_EQ(arr.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],100);
}

TEST(DynamicArrayConstructor, FillConstructorSingleElement)
{
    DynamicArray<int> arr(1,25);

    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],25);
}

TEST(DynamicArrayConstructor, FillConstructorZeroElements)
{
    DynamicArray<int> arr(0,99);

    EXPECT_EQ(arr.size(),0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(DynamicArrayConstructor, FillConstructorNegativeValues)
{
    DynamicArray<int> arr(4,-10);

    EXPECT_EQ(arr.size(),4);

    for(int i=0;i<4;i++)
        EXPECT_EQ(arr[i],-10);
}

// COPY CONSTRUCTOR

TEST(DynamicArrayCopyConstructor, DeepCopy)
{
    DynamicArray<int> original;

    original.append(1);
    original.append(2);
    original.append(3);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.size(),3);

    for(int i=0;i<3;i++)
        EXPECT_EQ(copy[i],original[i]);

    original[0]=100;

    EXPECT_EQ(copy[0],1);
    EXPECT_EQ(original[0],100);
}

TEST(DynamicArrayCopyConstructor, CopyEmptyArray)
{
    DynamicArray<int> original;

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.size(),0);
    EXPECT_TRUE(copy.isEmpty());
}

TEST(DynamicArrayCopyConstructor, CopyLargeArray)
{
    DynamicArray<int> original;

    for(int i=0;i<1000;i++)
        original.append(i);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.size(),1000);

    for(int i=0;i<1000;i++)
        EXPECT_EQ(copy[i],i);
}

TEST(DynamicArrayCopyConstructor, CopyIndependence)
{
    DynamicArray<int> original;

    original.append(10);
    original.append(20);

    DynamicArray<int> copy(original);

    copy[1]=500;

    EXPECT_EQ(original[1],20);
    EXPECT_EQ(copy[1],500);
}

// ASSIGNMENT OPERATOR

TEST(DynamicArrayAssignment, NormalAssignment)
{
    DynamicArray<int> arr1;

    arr1.append(10);
    arr1.append(20);

    DynamicArray<int> arr2;

    arr2.append(1);

    arr2=arr1;

    EXPECT_EQ(arr2.size(),2);
    EXPECT_EQ(arr2[0],10);
    EXPECT_EQ(arr2[1],20);

    arr1[0]=500;

    EXPECT_EQ(arr2[0],10);
}

TEST(DynamicArrayAssignment, SelfAssignment)
{
    DynamicArray<int> arr;

    arr.append(5);
    arr.append(10);

    arr=arr;

    EXPECT_EQ(arr.size(),2);
    EXPECT_EQ(arr[0],5);
    EXPECT_EQ(arr[1],10);
}

TEST(DynamicArrayAssignment, AssignEmptyToNonEmpty)
{
    DynamicArray<int> source;

    DynamicArray<int> destination;

    destination.append(1);
    destination.append(2);

    destination=source;

    EXPECT_EQ(destination.size(),0);
    EXPECT_TRUE(destination.isEmpty());
}

TEST(DynamicArrayAssignment, AssignNonEmptyToEmpty)
{
    DynamicArray<int> source;

    source.append(11);
    source.append(22);

    DynamicArray<int> destination;

    destination=source;

    EXPECT_EQ(destination.size(),2);
    EXPECT_EQ(destination[0],11);
    EXPECT_EQ(destination[1],22);
}

TEST(DynamicArrayAssignment, AssignmentDeepCopy)
{
    DynamicArray<int> source;

    source.append(100);
    source.append(200);

    DynamicArray<int> destination;

    destination=source;

    source[0]=999;

    EXPECT_EQ(destination[0],100);
    EXPECT_EQ(source[0],999);
}