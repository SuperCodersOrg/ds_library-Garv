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
        oldCin = std::cin.rdbuf();
        oldCout = std::cout.rdbuf();

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

        input << commands;

        Redis redis;
        redis.run();

        return output.str();
    }
};

// SET / GET

TEST_F(RedisTest, SetSingleKey)
{
    auto result = Execute(
        "SET name Garv\n"
        "GET name\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Done"),std::string::npos);
    EXPECT_NE(result.find("Garv"),std::string::npos);
}

TEST_F(RedisTest, UpdateExistingKey)
{
    auto result = Execute(
        "SET age 20\n"
        "SET age 21\n"
        "GET age\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("21"),std::string::npos);
}

TEST_F(RedisTest, GetMissingKey)
{
    auto result = Execute(
        "GET xyz\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Not Found"),std::string::npos);
}

TEST_F(RedisTest, ValueWithSpaces)
{
    auto result = Execute(
        "SET quote Hello World From Redis Lite\n"
        "GET quote\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Hello World From Redis Lite"),std::string::npos);
}

TEST_F(RedisTest, EmptyValueRejected)
{
    auto result = Execute(
        "SET key\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("SET <key> <value>"),std::string::npos);
}

TEST_F(RedisTest, EmptyKeyRejected)
{
    auto result = Execute(
        "SET\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("SET <key> <value>"),std::string::npos);
}