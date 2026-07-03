#include <gtest/gtest.h>
#include <sstream>
#include <Redis.h>

class RedisTest : public ::testing::Test
{
protected:
    std::streambuf* oldCin;
    std::streambuf* oldCout;

    std::stringstream input;
    std::stringstream output;

    void SetUp() override
    {
        oldCin=std::cin.rdbuf();
        oldCout=std::cout.rdbuf();

        std::cin.rdbuf(input.rdbuf());
        std::cout.rdbuf(output.rdbuf());
    }

    void TearDown() override
    {
        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);
    }

    std::string Execute(const std::string& commands)
    {
        input.str("");
        input.clear();

        output.str("");
        output.clear();

        input<<commands;

        Redis redis;
        redis.run();

        return output.str();
    }
};

// COMMANDS

TEST_F(RedisTest, Help)
{
    auto result=Execute(
        "HELP\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Commands"),std::string::npos);
}

TEST_F(RedisTest, Stats)
{
    auto result=Execute(
        "SET a 1\n"
        "STATS\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Elements"),std::string::npos);
    EXPECT_NE(result.find("Buckets"),std::string::npos);
    EXPECT_NE(result.find("LoadFactor"),std::string::npos);
    EXPECT_NE(result.find("Collisions"),std::string::npos);
}

TEST_F(RedisTest, Debug)
{
    auto result=Execute(
        "SET a 1\n"
        "DEBUG\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Bucket"),std::string::npos);
}

TEST_F(RedisTest, Print)
{
    auto result=Execute(
        "SET name Garv\n"
        "PRINT\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("name"),std::string::npos);
    EXPECT_NE(result.find("Garv"),std::string::npos);
}

TEST_F(RedisTest, UnknownCommand)
{
    auto result=Execute(
        "HELLO\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Unknown Command"),std::string::npos);
}

TEST_F(RedisTest, InvalidGet)
{
    auto result=Execute(
        "GET\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("GET <key>"),std::string::npos);
}

TEST_F(RedisTest, InvalidDel)
{
    auto result=Execute(
        "DEL\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("DEL <key>"),std::string::npos);
}

TEST_F(RedisTest, InvalidExists)
{
    auto result=Execute(
        "EXISTS\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("EXISTS <key>"),std::string::npos);
}