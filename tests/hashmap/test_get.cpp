#include <gtest/gtest.h>
#include "HashMap.h"

// GET TESTS

// Get existing key
TEST(HashMapGet, GetExistingKey)
{
    HashMap<int,int> map;

    map.insert(1,100);

    int value;

    EXPECT_TRUE(map.get(1,value));
    EXPECT_EQ(value,100);
}

// Get multiple existing keys
TEST(HashMapGet, GetMultipleKeys)
{
    HashMap<int,int> map;

    for(int i=0;i<10;i++)
        map.insert(i,i*100);

    int value;

    for(int i=0;i<10;i++)
    {
        EXPECT_TRUE(map.get(i,value));
        EXPECT_EQ(value,i*100);
    }
}

// Get missing key
TEST(HashMapGet, GetMissingKey)
{
    HashMap<int,int> map;

    map.insert(1,10);

    int value=-1;

    EXPECT_FALSE(map.get(100,value));
}

// Get from empty map
TEST(HashMapGet, GetFromEmptyMap)
{
    HashMap<int,int> map;

    int value=-1;

    EXPECT_FALSE(map.get(1,value));
}

// Get after updating existing key
TEST(HashMapGet, GetUpdatedValue)
{
    HashMap<int,int> map;

    map.insert(5,10);
    map.insert(5,50);

    int value;

    EXPECT_TRUE(map.get(5,value));
    EXPECT_EQ(value,50);
}

// Get after remove
TEST(HashMapGet, GetRemovedKey)
{
    HashMap<int,int> map;

    map.insert(10,100);

    map.remove(10);

    int value;

    EXPECT_FALSE(map.get(10,value));
}

// Get after clear
TEST(HashMapGet, GetAfterClear)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    map.clear();

    int value;

    EXPECT_FALSE(map.get(1,value));
    EXPECT_FALSE(map.get(2,value));
}

// Get negative key
TEST(HashMapGet, GetNegativeKey)
{
    HashMap<int,int> map;

    map.insert(-10,500);

    int value;

    EXPECT_TRUE(map.get(-10,value));
    EXPECT_EQ(value,500);
}

// Get string keys
TEST(HashMapGet, GetStringKey)
{
    HashMap<std::string,int> map;

    map.insert("Garv",100);
    map.insert("Rahul",200);

    int value;

    EXPECT_TRUE(map.get("Garv",value));
    EXPECT_EQ(value,100);

    EXPECT_TRUE(map.get("Rahul",value));
    EXPECT_EQ(value,200);
}

// Get after rehash
TEST(HashMapGet, GetAfterRehash)
{
    HashMap<int,int> map(4);

    for(int i=0;i<100;i++)
        map.insert(i,i*10);

    int value;

    for(int i=0;i<100;i++)
    {
        EXPECT_TRUE(map.get(i,value));
        EXPECT_EQ(value,i*10);
    }
}