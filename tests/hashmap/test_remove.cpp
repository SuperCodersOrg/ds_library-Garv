#include <gtest/gtest.h>
#include "HashMap.h"

// REMOVE TESTS

// Remove existing key
TEST(HashMapRemove, RemoveExistingKey)
{
    HashMap<int,int> map;

    map.insert(1,100);

    map.remove(1);

    EXPECT_EQ(map.size(),0);
    EXPECT_FALSE(map.exists(1));
}

// Remove first of many keys
TEST(HashMapRemove, RemoveFirstInsertedKey)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);
    map.insert(3,30);

    map.remove(1);

    EXPECT_EQ(map.size(),2);

    int value;

    EXPECT_FALSE(map.get(1,value));
    EXPECT_TRUE(map.get(2,value));
    EXPECT_TRUE(map.get(3,value));
}

// Remove middle key
TEST(HashMapRemove, RemoveMiddleKey)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);
    map.insert(3,30);

    map.remove(2);

    EXPECT_EQ(map.size(),2);

    int value;

    EXPECT_FALSE(map.get(2,value));

    EXPECT_TRUE(map.get(1,value));
    EXPECT_EQ(value,10);

    EXPECT_TRUE(map.get(3,value));
    EXPECT_EQ(value,30);
}

// Remove last key
TEST(HashMapRemove, RemoveLastKey)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);
    map.insert(3,30);

    map.remove(3);

    EXPECT_EQ(map.size(),2);

    int value;

    EXPECT_FALSE(map.get(3,value));
    EXPECT_TRUE(map.get(1,value));
    EXPECT_TRUE(map.get(2,value));
}

// Remove non-existing key
TEST(HashMapRemove, RemoveMissingKey)
{
    HashMap<int,int> map;

    map.insert(1,10);

    map.remove(100);

    EXPECT_EQ(map.size(),1);

    int value;

    EXPECT_TRUE(map.get(1,value));
    EXPECT_EQ(value,10);
}

// Remove from empty map
TEST(HashMapRemove, RemoveFromEmptyMap)
{
    HashMap<int,int> map;

    map.remove(1);

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
}

// Remove same key twice
TEST(HashMapRemove, RemoveSameKeyTwice)
{
    HashMap<int,int> map;

    map.insert(5,50);

    map.remove(5);
    map.remove(5);

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
}

// Remove all keys
TEST(HashMapRemove, RemoveAllKeys)
{
    HashMap<int,int> map;

    for(int i=0;i<100;i++)
        map.insert(i,i);

    for(int i=0;i<100;i++)
        map.remove(i);

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
}

// Remove after rehash
TEST(HashMapRemove, RemoveAfterRehash)
{
    HashMap<int,int> map(4);

    for(int i=0;i<100;i++)
        map.insert(i,i);

    for(int i=0;i<50;i++)
        map.remove(i);

    EXPECT_EQ(map.size(),50);

    int value;

    for(int i=0;i<50;i++)
        EXPECT_FALSE(map.get(i,value));

    for(int i=50;i<100;i++)
    {
        EXPECT_TRUE(map.get(i,value));
        EXPECT_EQ(value,i);
    }
}

// Remove negative key
TEST(HashMapRemove, RemoveNegativeKey)
{
    HashMap<int,int> map;

    map.insert(-10,500);

    map.remove(-10);

    EXPECT_FALSE(map.exists(-10));
    EXPECT_EQ(map.size(),0);
}