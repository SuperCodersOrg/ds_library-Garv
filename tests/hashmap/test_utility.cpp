#include <gtest/gtest.h>
#include "HashMap.h"
#include <sstream>
#include <iostream>

// SIZE()

TEST(HashMapUtility, InitialSize)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.size(),0);
}

TEST(HashMapUtility, SizeAfterInsert)
{
    HashMap<int,int> map;

    for(int i=0;i<10;i++)
        map.insert(i,i);

    EXPECT_EQ(map.size(),10);
}

TEST(HashMapUtility, SizeAfterRemove)
{
    HashMap<int,int> map;

    for(int i=0;i<10;i++)
        map.insert(i,i);

    map.remove(5);

    EXPECT_EQ(map.size(),9);
}

TEST(HashMapUtility, SizeAfterClear)
{
    HashMap<int,int> map;

    map.insert(1,1);
    map.insert(2,2);

    map.clear();

    EXPECT_EQ(map.size(),0);
}

// BUCKET COUNT

TEST(HashMapUtility, DefaultBucketCount)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.bucketCount(),16);
}

TEST(HashMapUtility, CustomBucketCount)
{
    HashMap<int,int> map(32);

    EXPECT_EQ(map.bucketCount(),32);
}

TEST(HashMapUtility, BucketCountAfterRehash)
{
    HashMap<int,int> map(4);

    int oldBuckets = map.bucketCount();

    for(int i=0;i<100;i++)
        map.insert(i,i);

    EXPECT_GT(map.bucketCount(),oldBuckets);
}

// LOAD FACTOR

TEST(HashMapUtility, InitialLoadFactor)
{
    HashMap<int,int> map(10);

    EXPECT_DOUBLE_EQ(map.loadFactor(),0.0);
}

TEST(HashMapUtility, LoadFactorAfterInsert)
{
    HashMap<int,int> map(10);

    map.insert(1,1);
    map.insert(2,2);
    map.insert(3,3);

    EXPECT_DOUBLE_EQ(map.loadFactor(),0.3);
}

TEST(HashMapUtility, LoadFactorAfterRemove)
{
    HashMap<int,int> map(10);

    map.insert(1,1);
    map.insert(2,2);

    map.remove(1);

    EXPECT_DOUBLE_EQ(map.loadFactor(),0.1);
}

// ISEMPTY()

TEST(HashMapUtility, InitiallyEmpty)
{
    HashMap<int,int> map;

    EXPECT_TRUE(map.isEmpty());
}

TEST(HashMapUtility, NotEmptyAfterInsert)
{
    HashMap<int,int> map;

    map.insert(1,1);

    EXPECT_FALSE(map.isEmpty());
}

TEST(HashMapUtility, EmptyAfterClear)
{
    HashMap<int,int> map;

    map.insert(1,1);

    map.clear();

    EXPECT_TRUE(map.isEmpty());
}

// COLLISIONS

struct BadHash
{
    size_t operator()(int) const
    {
        return 0;
    }
};

TEST(HashMapUtility, NoCollisionInitially)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.collisions(),0);
}

TEST(HashMapUtility, CollisionCount)
{
    HashMap<int,int,BadHash> map(10);

    map.insert(1,1);
    map.insert(2,2);
    map.insert(3,3);

    EXPECT_EQ(map.collisions(),2);
}

TEST(HashMapUtility, CollisionAfterRemove)
{
    HashMap<int,int,BadHash> map(10);

    map.insert(1,1);
    map.insert(2,2);
    map.insert(3,3);

    map.remove(2);

    EXPECT_EQ(map.collisions(),1);
}

// DEBUG PRINT

TEST(HashMapUtility, DebugPrint)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    map.debugPrint();

    std::cout.rdbuf(old);

    EXPECT_FALSE(output.str().empty());
}

// PRINT

TEST(HashMapUtility, PrintEmptyMap)
{
    HashMap<int,int> map;

    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    map.print();

    std::cout.rdbuf(old);

    EXPECT_TRUE(output.str().empty());
}

TEST(HashMapUtility, PrintSingleElement)
{
    HashMap<int,int> map;

    map.insert(1,100);

    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    map.print();

    std::cout.rdbuf(old);

    EXPECT_NE(output.str().find("1"),std::string::npos);
    EXPECT_NE(output.str().find("100"),std::string::npos);
}

TEST(HashMapUtility, PrintMultipleElements)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);
    map.insert(3,30);

    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    map.print();

    std::cout.rdbuf(old);

    EXPECT_NE(output.str().find("1"),std::string::npos);
    EXPECT_NE(output.str().find("2"),std::string::npos);
    EXPECT_NE(output.str().find("3"),std::string::npos);

    EXPECT_NE(output.str().find("10"),std::string::npos);
    EXPECT_NE(output.str().find("20"),std::string::npos);
    EXPECT_NE(output.str().find("30"),std::string::npos);
}