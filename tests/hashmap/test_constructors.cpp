#include <gtest/gtest.h>
#include "HashMap.h"

// DEFAULT CONSTRUCTOR

TEST(HashMapConstructor, DefaultConstructor)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.size(),0);
    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.bucketCount(),16);
}

TEST(HashMapConstructor, CustomBucketCount)
{
    HashMap<int,int> map(32);

    EXPECT_EQ(map.bucketCount(),32);
    EXPECT_EQ(map.size(),0);
}

TEST(HashMapConstructor, InvalidBucketCount)
{
    HashMap<int,int> map(-5);

    EXPECT_EQ(map.bucketCount(),16);
}

TEST(HashMapConstructor, CustomLoadFactor)
{
    HashMap<int,int> map(20,0.50);

    EXPECT_EQ(map.bucketCount(),20);
    EXPECT_DOUBLE_EQ(map.loadFactor(),0.0);
}

// COPY CONSTRUCTOR

TEST(HashMapCopyConstructor, DeepCopy)
{
    HashMap<int,int> original;

    original.insert(1,10);
    original.insert(2,20);

    HashMap<int,int> copy(original);

    int value;

    EXPECT_TRUE(copy.get(1,value));
    EXPECT_EQ(value,10);

    original.insert(1,100);

    copy.get(1,value);

    EXPECT_EQ(value,10);
}

TEST(HashMapCopyConstructor, CopyEmptyMap)
{
    HashMap<int,int> original;

    HashMap<int,int> copy(original);

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(),0);
}

TEST(HashMapCopyConstructor, CopyLargeMap)
{
    HashMap<int,int> original;

    for(int i=0;i<1000;i++)
        original.insert(i,i);

    HashMap<int,int> copy(original);

    EXPECT_EQ(copy.size(),1000);

    int value;

    for(int i=0;i<1000;i++)
    {
        EXPECT_TRUE(copy.get(i,value));
        EXPECT_EQ(value,i);
    }
}

// ASSIGNMENT OPERATOR

TEST(HashMapAssignment, NormalAssignment)
{
    HashMap<int,int> map1;

    map1.insert(1,10);
    map1.insert(2,20);

    HashMap<int,int> map2;

    map2.insert(100,500);

    map2=map1;

    EXPECT_EQ(map2.size(),2);

    int value;

    map2.get(1,value);
    EXPECT_EQ(value,10);
}

TEST(HashMapAssignment, SelfAssignment)
{
    HashMap<int,int> map;

    map.insert(1,10);

    map=map;

    EXPECT_EQ(map.size(),1);

    int value;

    map.get(1,value);

    EXPECT_EQ(value,10);
}

TEST(HashMapAssignment, AssignEmptyToNonEmpty)
{
    HashMap<int,int> source;

    HashMap<int,int> destination;

    destination.insert(1,10);

    destination=source;

    EXPECT_TRUE(destination.isEmpty());
}

TEST(HashMapAssignment, AssignNonEmptyToEmpty)
{
    HashMap<int,int> source;

    source.insert(1,10);

    HashMap<int,int> destination;

    destination=source;

    EXPECT_EQ(destination.size(),1);

    int value;

    destination.get(1,value);

    EXPECT_EQ(value,10);
}