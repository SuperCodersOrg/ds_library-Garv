#include <gtest/gtest.h>
#include "HashMap.h"

// EXISTS TESTS

// Existing key
TEST(HashMapExists, ExistingKey)
{
    HashMap<int,int> map;

    map.insert(1,100);

    EXPECT_TRUE(map.exists(1));
}

// Missing key
TEST(HashMapExists, MissingKey)
{
    HashMap<int,int> map;

    map.insert(1,100);

    EXPECT_FALSE(map.exists(2));
}

// Empty map
TEST(HashMapExists, EmptyMap)
{
    HashMap<int,int> map;

    EXPECT_FALSE(map.exists(1));
}

// Exists after update
TEST(HashMapExists, ExistsAfterUpdate)
{
    HashMap<int,int> map;

    map.insert(10,50);
    map.insert(10,100);

    EXPECT_TRUE(map.exists(10));

    int value;
    EXPECT_TRUE(map.get(10,value));
    EXPECT_EQ(value,100);
}

// Exists after remove
TEST(HashMapExists, ExistsAfterRemove)
{
    HashMap<int,int> map;

    map.insert(5,50);

    map.remove(5);

    EXPECT_FALSE(map.exists(5));
}

// Exists after clear
TEST(HashMapExists, ExistsAfterClear)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    map.clear();

    EXPECT_FALSE(map.exists(1));
    EXPECT_FALSE(map.exists(2));
}

// Negative key
TEST(HashMapExists, NegativeKey)
{
    HashMap<int,int> map;

    map.insert(-5,100);

    EXPECT_TRUE(map.exists(-5));
}

// String keys
TEST(HashMapExists, StringKeys)
{
    HashMap<std::string,int> map;

    map.insert("Garv",1);
    map.insert("Rahul",2);

    EXPECT_TRUE(map.exists("Garv"));
    EXPECT_TRUE(map.exists("Rahul"));
    EXPECT_FALSE(map.exists("Ankit"));
}

// Exists after rehash
TEST(HashMapExists, ExistsAfterRehash)
{
    HashMap<int,int> map(4);

    for(int i=0;i<100;i++)
        map.insert(i,i);

    for(int i=0;i<100;i++)
        EXPECT_TRUE(map.exists(i));
}

// Remove some after rehash
TEST(HashMapExists, ExistsAfterRehashAndRemove)
{
    HashMap<int,int> map(4);

    for(int i=0;i<100;i++)
        map.insert(i,i);

    for(int i=0;i<50;i++)
        map.remove(i);

    for(int i=0;i<50;i++)
        EXPECT_FALSE(map.exists(i));

    for(int i=50;i<100;i++)
        EXPECT_TRUE(map.exists(i));
}