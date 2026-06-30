#include <gtest/gtest.h>
#include "HashMap.h"

// INSERT TESTS

// Insert single key-value pair
TEST(HashMapInsert, InsertSingleElement)
{
    HashMap<int,int> map;

    map.insert(1,100);

    EXPECT_EQ(map.size(),1);

    int value;
    EXPECT_TRUE(map.get(1,value));
    EXPECT_EQ(value,100);
}

// Insert multiple elements
TEST(HashMapInsert, InsertMultipleElements)
{
    HashMap<int,int> map;

    for(int i=0;i<10;i++)
        map.insert(i,i*10);

    EXPECT_EQ(map.size(),10);

    int value;

    for(int i=0;i<10;i++)
    {
        EXPECT_TRUE(map.get(i,value));
        EXPECT_EQ(value,i*10);
    }
}

// Insert duplicate key should update value
TEST(HashMapInsert, UpdateExistingKey)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(1,20);

    EXPECT_EQ(map.size(),1);

    int value;

    EXPECT_TRUE(map.get(1,value));
    EXPECT_EQ(value,20);
}

// Insert negative keys
TEST(HashMapInsert, InsertNegativeKeys)
{
    HashMap<int,int> map;

    map.insert(-1,100);
    map.insert(-5,500);

    int value;

    EXPECT_TRUE(map.get(-1,value));
    EXPECT_EQ(value,100);

    EXPECT_TRUE(map.get(-5,value));
    EXPECT_EQ(value,500);
}

// Insert zero key
TEST(HashMapInsert, InsertZeroKey)
{
    HashMap<int,int> map;

    map.insert(0,999);

    int value;

    EXPECT_TRUE(map.get(0,value));
    EXPECT_EQ(value,999);
}

// Insert many elements
TEST(HashMapInsert, InsertLargeDataset)
{
    HashMap<int,int> map;

    for(int i=0;i<1000;i++)
        map.insert(i,i);

    EXPECT_EQ(map.size(),1000);

    int value;

    for(int i=0;i<1000;i++)
    {
        EXPECT_TRUE(map.get(i,value));
        EXPECT_EQ(value,i);
    }
}

// Insert string keys
TEST(HashMapInsert, InsertStringKeys)
{
    HashMap<std::string,int> map;

    map.insert("Garv",10);
    map.insert("Rahul",20);

    int value;

    EXPECT_TRUE(map.get("Garv",value));
    EXPECT_EQ(value,10);

    EXPECT_TRUE(map.get("Rahul",value));
    EXPECT_EQ(value,20);
}

// Insert after remove
TEST(HashMapInsert, InsertAfterRemove)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.remove(1);

    map.insert(1,50);

    int value;

    EXPECT_TRUE(map.get(1,value));
    EXPECT_EQ(value,50);

    EXPECT_EQ(map.size(),1);
}

// Insert duplicate multiple times
TEST(HashMapInsert, MultipleUpdatesSameKey)
{
    HashMap<int,int> map;

    map.insert(5,10);
    map.insert(5,20);
    map.insert(5,30);
    map.insert(5,40);

    EXPECT_EQ(map.size(),1);

    int value;

    EXPECT_TRUE(map.get(5,value));
    EXPECT_EQ(value,40);
}