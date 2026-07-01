#include <gtest/gtest.h>
#include "SinglyList.h"

// DEFAULT CONSTRUCTOR

TEST(SinglyListConstructor, DefaultConstructor)
{
    SinglyList<int> list;

    EXPECT_EQ(list.size(),0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(SinglyListConstructor, DefaultConstructorAppend)
{
    SinglyList<int> list;

    list.append(10);

    EXPECT_EQ(list.size(),1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list[0],10);
}

// COPY CONSTRUCTOR

TEST(SinglyListCopyConstructor, DeepCopy)
{
    SinglyList<int> original;

    original.append(10);
    original.append(20);
    original.append(30);

    SinglyList<int> copy(original);

    EXPECT_EQ(copy.size(),3);

    EXPECT_EQ(copy[0],10);
    EXPECT_EQ(copy[1],20);
    EXPECT_EQ(copy[2],30);

    original[0]=100;

    EXPECT_EQ(copy[0],10);
    EXPECT_EQ(original[0],100);
}

TEST(SinglyListCopyConstructor, CopyEmptyList)
{
    SinglyList<int> original;

    SinglyList<int> copy(original);

    EXPECT_EQ(copy.size(),0);
    EXPECT_TRUE(copy.isEmpty());
}

TEST(SinglyListCopyConstructor, CopyLargeList)
{
    SinglyList<int> original;

    for(int i=0;i<1000;i++)
        original.append(i);

    SinglyList<int> copy(original);

    EXPECT_EQ(copy.size(),1000);

    for(int i=0;i<1000;i++)
        EXPECT_EQ(copy[i],i);
}

TEST(SinglyListCopyConstructor, CopyIndependence)
{
    SinglyList<int> original;

    original.append(1);
    original.append(2);

    SinglyList<int> copy(original);

    copy[1]=500;

    EXPECT_EQ(original[1],2);
    EXPECT_EQ(copy[1],500);
}

// ASSIGNMENT OPERATOR

TEST(SinglyListAssignment, NormalAssignment)
{
    SinglyList<int> list1;

    list1.append(1);
    list1.append(2);
    list1.append(3);

    SinglyList<int> list2;

    list2.append(100);

    list2=list1;

    EXPECT_EQ(list2.size(),3);

    EXPECT_EQ(list2[0],1);
    EXPECT_EQ(list2[1],2);
    EXPECT_EQ(list2[2],3);

    list1[0]=999;

    EXPECT_EQ(list2[0],1);
}

TEST(SinglyListAssignment, SelfAssignment)
{
    SinglyList<int> list;

    list.append(10);
    list.append(20);

    list=list;

    EXPECT_EQ(list.size(),2);
    EXPECT_EQ(list[0],10);
    EXPECT_EQ(list[1],20);
}

TEST(SinglyListAssignment, AssignEmptyToNonEmpty)
{
    SinglyList<int> source;

    SinglyList<int> destination;

    destination.append(1);
    destination.append(2);

    destination=source;

    EXPECT_TRUE(destination.isEmpty());
    EXPECT_EQ(destination.size(),0);
}

TEST(SinglyListAssignment, AssignNonEmptyToEmpty)
{
    SinglyList<int> source;

    source.append(10);
    source.append(20);

    SinglyList<int> destination;

    destination=source;

    EXPECT_EQ(destination.size(),2);

    EXPECT_EQ(destination[0],10);
    EXPECT_EQ(destination[1],20);
}

TEST(SinglyListAssignment, AssignmentDeepCopy)
{
    SinglyList<int> source;

    source.append(5);
    source.append(10);

    SinglyList<int> destination;

    destination=source;

    source[1]=100;

    EXPECT_EQ(destination[1],10);
}

// ITERATOR CONSTRUCTOR

TEST(SinglyListIteratorConstructor, ConstructFromArray)
{
    int data[]={1,2,3,4,5};

    SinglyList<int> list(data,data+5);

    EXPECT_EQ(list.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(list[i],i+1);
}

TEST(SinglyListIteratorConstructor, ConstructSingleElement)
{
    int data[]={100};

    SinglyList<int> list(data,data+1);

    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list[0],100);
}

TEST(SinglyListIteratorConstructor, ConstructEmptyRange)
{
    int data[]={1,2,3};

    SinglyList<int> list(data,data);

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

TEST(SinglyListIteratorConstructor, ConstructLargeRange)
{
    int data[1000];

    for(int i=0;i<1000;i++)
        data[i]=i;

    SinglyList<int> list(data,data+1000);

    EXPECT_EQ(list.size(),1000);

    for(int i=0;i<1000;i++)
        EXPECT_EQ(list[i],i);
}