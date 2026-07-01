#include <gtest/gtest.h>
#include "SinglyList.h"
#include <sstream>
#include <iostream>

// CLEAR()

// Clear a non-empty list
TEST(SinglyListUtility, ClearNonEmptyList)
{
    SinglyList<int> list;

    for(int i=1;i<=5;i++)
        list.append(i);

    list.clear();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

// Clear an empty list
TEST(SinglyListUtility, ClearEmptyList)
{
    SinglyList<int> list;

    list.clear();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

// Append after clear
TEST(SinglyListUtility, AppendAfterClear)
{
    SinglyList<int> list;

    list.append(1);
    list.append(2);

    list.clear();

    list.append(100);

    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list[0],100);
}

// Clear multiple times
TEST(SinglyListUtility, ClearMultipleTimes)
{
    SinglyList<int> list;

    list.append(10);

    list.clear();
    list.clear();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(),0);
}

// SIZE()

// Initial size
TEST(SinglyListUtility, InitialSize)
{
    SinglyList<int> list;

    EXPECT_EQ(list.size(),0);
}

// Size after append
TEST(SinglyListUtility, SizeAfterAppend)
{
    SinglyList<int> list;

    for(int i=0;i<10;i++)
        list.append(i);

    EXPECT_EQ(list.size(),10);
}

// Size after insert
TEST(SinglyListUtility, SizeAfterInsert)
{
    SinglyList<int> list;

    list.append(1);
    list.append(3);

    list.insert(1,2);

    EXPECT_EQ(list.size(),3);
}

// Size after remove
TEST(SinglyListUtility, SizeAfterRemove)
{
    SinglyList<int> list;

    for(int i=0;i<5;i++)
        list.append(i);

    list.remove(2);

    EXPECT_EQ(list.size(),4);
}

// ISEMPTY()

// Empty initially
TEST(SinglyListUtility, IsEmptyInitially)
{
    SinglyList<int> list;

    EXPECT_TRUE(list.isEmpty());
}

// Not empty after append
TEST(SinglyListUtility, IsEmptyAfterAppend)
{
    SinglyList<int> list;

    list.append(1);

    EXPECT_FALSE(list.isEmpty());
}

// Empty after clear
TEST(SinglyListUtility, IsEmptyAfterClear)
{
    SinglyList<int> list;

    list.append(1);

    list.clear();

    EXPECT_TRUE(list.isEmpty());
}

// Empty after removing last element
TEST(SinglyListUtility, IsEmptyAfterRemovingLastElement)
{
    SinglyList<int> list;

    list.append(10);

    list.remove(0);

    EXPECT_TRUE(list.isEmpty());
}

// PRINT()

// Print empty list
TEST(SinglyListUtility, PrintEmptyList)
{
    SinglyList<int> list;

    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    list.print();

    std::cout.rdbuf(old);

    EXPECT_EQ(output.str(),"\n");
}

// Print single element
TEST(SinglyListUtility, PrintSingleElement)
{
    SinglyList<int> list;

    list.append(10);

    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    list.print();

    std::cout.rdbuf(old);

    EXPECT_EQ(output.str(),"10 \n");
}

// Print multiple elements
TEST(SinglyListUtility, PrintMultipleElements)
{
    SinglyList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    list.print();

    std::cout.rdbuf(old);

    EXPECT_EQ(output.str(),"1 2 3 \n");
}