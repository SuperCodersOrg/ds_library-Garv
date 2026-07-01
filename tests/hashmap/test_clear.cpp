#include <gtest/gtest.h>
#include "HashMap.h"
// CLEAR TESTS

// Clear a non-empty map
TEST(HashMapClear, ClearNonEmptyMap)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);
    map.insert(3,30);

    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
}

// Clear an already empty map
TEST(HashMapClear, ClearEmptyMap)
{
    HashMap<int,int> map;

    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
}

// Clear after rehash
TEST(HashMapClear, ClearAfterRehash)
{
    HashMap<int,int> map(4);

    for(int i=0;i<100;i++)
        map.insert(i,i);

    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);

    int value;

    for(int i=0;i<100;i++)
        EXPECT_FALSE(map.get(i,value));
}

// Insert after clear
TEST(HashMapClear, InsertAfterClear)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    map.clear();

    map.insert(100,500);

    EXPECT_EQ(map.size(),1);

    int value;

    EXPECT_TRUE(map.get(100,value));
    EXPECT_EQ(value,500);
}

// Clear multiple times
TEST(HashMapClear, ClearMultipleTimes)
{
    HashMap<int,int> map;

    map.insert(1,10);

    map.clear();
    map.clear();
    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
}

// Clear preserves bucket count
TEST(HashMapClear, BucketCountUnchanged)
{
    HashMap<int,int> map(32);

    map.insert(1,10);
    map.insert(2,20);

    int oldBuckets = map.bucketCount();

    map.clear();

    EXPECT_EQ(map.bucketCount(),oldBuckets);
}

// Clear removes exists()
TEST(HashMapClear, ExistsAfterClear)
{
    HashMap<int,int> map;

    map.insert(10,100);

    map.clear();

    EXPECT_FALSE(map.exists(10));
}

// Clear string keys
TEST(HashMapClear, ClearStringKeys)
{
    HashMap<std::string,int> map;

    map.insert("Garv",1);
    map.insert("Rahul",2);

    map.clear();

    EXPECT_TRUE(map.isEmpty());

    int value;

    EXPECT_FALSE(map.get("Garv",value));
    EXPECT_FALSE(map.get("Rahul",value));
}