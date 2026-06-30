#include <gtest/gtest.h>
#include "SinglyList.h"
#include <stdexcept>

// OPERATOR[]

// Read first element
TEST(SinglyListOperator, ReadFirstElement)
{
    SinglyList<int> list;

    list.append(10);
    list.append(20);

    EXPECT_EQ(list[0],10);
}

// Read middle element
TEST(SinglyListOperator, ReadMiddleElement)
{
    SinglyList<int> list;

    for(int i=1;i<=5;i++)
        list.append(i);

    EXPECT_EQ(list[2],3);
}

// Read last element
TEST(SinglyListOperator, ReadLastElement)
{
    SinglyList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    EXPECT_EQ(list[2],30);
}

// Modify first element
TEST(SinglyListOperator, ModifyFirstElement)
{
    SinglyList<int> list;

    list.append(1);
    list.append(2);

    list[0]=100;

    EXPECT_EQ(list[0],100);
    EXPECT_EQ(list[1],2);
}

// Modify middle element
TEST(SinglyListOperator, ModifyMiddleElement)
{
    SinglyList<int> list;

    for(int i=1;i<=5;i++)
        list.append(i);

    list[2]=999;

    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],999);
    EXPECT_EQ(list[3],4);
    EXPECT_EQ(list[4],5);
}

// Modify last element
TEST(SinglyListOperator, ModifyLastElement)
{
    SinglyList<int> list;

    list.append(10);
    list.append(20);

    list[1]=500;

    EXPECT_EQ(list[1],500);
}

// Const operator[]
TEST(SinglyListOperator, ConstOperatorRead)
{
    SinglyList<int> temp;

    temp.append(10);
    temp.append(20);
    temp.append(30);

    const SinglyList<int>& list=temp;

    EXPECT_EQ(list[0],10);
    EXPECT_EQ(list[1],20);
    EXPECT_EQ(list[2],30);
}

// Empty list
TEST(SinglyListOperator, EmptyListThrows)
{
    SinglyList<int> list;

    EXPECT_THROW(list[0],std::out_of_range);
}

// Negative index
TEST(SinglyListOperator, NegativeIndexThrows)
{
    SinglyList<int> list;

    list.append(1);

    EXPECT_THROW(list[-1],std::out_of_range);
}

// Past end
TEST(SinglyListOperator, PastEndThrows)
{
    SinglyList<int> list;

    list.append(1);

    EXPECT_THROW(list[1],std::out_of_range);
}

// Large dataset
TEST(SinglyListOperator, LargeDatasetAccess)
{
    SinglyList<int> list;

    for(int i=0;i<1000;i++)
        list.append(i);

    for(int i=0;i<1000;i++)
        EXPECT_EQ(list[i],i);
}

// Arithmetic expressions
TEST(SinglyListOperator, ArithmeticExpression)
{
    SinglyList<int> list;

    list.append(5);
    list.append(10);

    int sum=list[0]+list[1];

    EXPECT_EQ(sum,15);
}