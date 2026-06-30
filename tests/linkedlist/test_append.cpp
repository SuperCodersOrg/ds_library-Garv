#include <gtest/gtest.h>
#include "SinglyList.h"

// APPEND TESTS

// Append into an empty list
TEST(SinglyListAppend, AppendSingleElement)
{
    SinglyList<int> list;

    list.append(10);

    EXPECT_EQ(list.size(),1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list[0],10);
}

// Append multiple elements
TEST(SinglyListAppend, AppendMultipleElements)
{
    SinglyList<int> list;

    for(int i=1;i<=5;i++)
        list.append(i);

    EXPECT_EQ(list.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(list[i],i+1);
}

// Order should be preserved
TEST(SinglyListAppend, OrderPreserved)
{
    SinglyList<int> list;

    list.append(5);
    list.append(10);
    list.append(15);
    list.append(20);

    EXPECT_EQ(list[0],5);
    EXPECT_EQ(list[1],10);
    EXPECT_EQ(list[2],15);
    EXPECT_EQ(list[3],20);
}

// Append duplicate values
TEST(SinglyListAppend, AppendDuplicateValues)
{
    SinglyList<int> list;

    list.append(10);
    list.append(10);
    list.append(10);

    EXPECT_EQ(list.size(),3);

    EXPECT_EQ(list[0],10);
    EXPECT_EQ(list[1],10);
    EXPECT_EQ(list[2],10);
}

// Append negative and zero values
TEST(SinglyListAppend, AppendNegativeValues)
{
    SinglyList<int> list;

    list.append(-5);
    list.append(0);
    list.append(25);

    EXPECT_EQ(list.size(),3);

    EXPECT_EQ(list[0],-5);
    EXPECT_EQ(list[1],0);
    EXPECT_EQ(list[2],25);
}

// Append after clear
TEST(SinglyListAppend, AppendAfterClear)
{
    SinglyList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    list.clear();

    list.append(100);

    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list[0],100);
}

// Large dataset
TEST(SinglyListAppend, AppendLargeDataset)
{
    SinglyList<int> list;

    for(int i=0;i<1000;i++)
        list.append(i);

    EXPECT_EQ(list.size(),1000);

    EXPECT_EQ(list[0],0);
    EXPECT_EQ(list[499],499);
    EXPECT_EQ(list[999],999);
}

// Multiple appends after many operations
TEST(SinglyListAppend, MultipleAppendOperations)
{
    SinglyList<int> list;

    for(int i=0;i<100;i++)
        list.append(i);

    for(int i=100;i<200;i++)
        list.append(i);

    EXPECT_EQ(list.size(),200);

    EXPECT_EQ(list[0],0);
    EXPECT_EQ(list[99],99);
    EXPECT_EQ(list[100],100);
    EXPECT_EQ(list[199],199);
}