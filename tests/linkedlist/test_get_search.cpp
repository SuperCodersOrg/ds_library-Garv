#include <gtest/gtest.h>
#include "SinglyList.h"
#include <stdexcept>

class SinglyListGetSearchTest : public ::testing::Test
{
protected:
    SinglyList<int> list;

    void SetUp() override
    {
        for(int i=1;i<=5;i++)
            list.append(i);
    }
};

// GET()

// Get first element
TEST_F(SinglyListGetSearchTest, GetFirstElement)
{
    int value;

    EXPECT_TRUE(list.get(0,value));
    EXPECT_EQ(value,1);
}

// Get middle element
TEST_F(SinglyListGetSearchTest, GetMiddleElement)
{
    int value;

    EXPECT_TRUE(list.get(2,value));
    EXPECT_EQ(value,3);
}

// Get last element
TEST_F(SinglyListGetSearchTest, GetLastElement)
{
    int value;

    EXPECT_TRUE(list.get(list.size()-1,value));
    EXPECT_EQ(value,5);
}

// Get from empty list
TEST(SinglyListGet, GetFromEmptyList)
{
    SinglyList<int> list;

    int value=-1;

    EXPECT_FALSE(list.get(0,value));
}

// Negative index
TEST(SinglyListGet, GetNegativeIndex)
{
    SinglyList<int> list;

    list.append(10);

    int value=-1;

    EXPECT_FALSE(list.get(-1,value));
}

// Index past end
TEST(SinglyListGet, GetPastEnd)
{
    SinglyList<int> list;

    list.append(10);

    int value=-1;

    EXPECT_FALSE(list.get(2,value));
}

// Get after insert/remove operations
TEST(SinglyListGet, GetAfterModifications)
{
    SinglyList<int> list;

    list.append(1);
    list.append(2);
    list.append(4);

    list.insert(2,3);
    list.remove(0);

    int value;

    EXPECT_TRUE(list.get(0,value));
    EXPECT_EQ(value,2);

    EXPECT_TRUE(list.get(1,value));
    EXPECT_EQ(value,3);

    EXPECT_TRUE(list.get(2,value));
    EXPECT_EQ(value,4);
}

// SEARCH()t

// Search first element
TEST_F(SinglyListGetSearchTest, SearchFirstElement)
{
    EXPECT_EQ(list.search(1),0);
}

// Search middle element
TEST_F(SinglyListGetSearchTest, SearchMiddleElement)
{
    EXPECT_EQ(list.search(3),2);
}

// Search last element
TEST_F(SinglyListGetSearchTest, SearchLastElement)
{
    EXPECT_EQ(list.search(5),4);
}

// Search missing element
TEST_F(SinglyListGetSearchTest, SearchMissingElement)
{
    EXPECT_EQ(list.search(100),-1);
}

// Search duplicate values
TEST(SinglyListSearch, SearchDuplicateValues)
{
    SinglyList<int> list;

    list.append(10);
    list.append(20);
    list.append(10);
    list.append(30);

    EXPECT_EQ(list.search(10),0);
}

// Search in empty list
TEST(SinglyListSearch, SearchEmptyList)
{
    SinglyList<int> list;

    EXPECT_EQ(list.search(10),-1);
}

// Search after removals
TEST(SinglyListSearch, SearchAfterRemove)
{
    SinglyList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(1);

    EXPECT_EQ(list.search(2),-1);
    EXPECT_EQ(list.search(3),1);
}