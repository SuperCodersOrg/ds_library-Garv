#include <gtest/gtest.h>
#include <sstream>
#include <Redis>

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
// DELETE / EXISTS

TEST_F(RedisTest, DeleteExistingKey)
{
    auto result=Execute(
        "SET city Delhi\n"
        "DEL city\n"
        "GET city\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Deleted"),std::string::npos);
    EXPECT_NE(result.find("Not Found"),std::string::npos);
}

TEST_F(RedisTest, DeleteMissingKey)
{
    auto result=Execute(
        "DEL abc\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Not found"),std::string::npos);
}

TEST_F(RedisTest, ExistsTrue)
{
    auto result=Execute(
        "SET a 1\n"
        "EXISTS a\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("True"),std::string::npos);
}

TEST_F(RedisTest, ExistsFalse)
{
    auto result=Execute(
        "EXISTS xyz\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("False"),std::string::npos);
}

TEST_F(RedisTest, Count)
{
    auto result=Execute(
        "SET a 1\n"
        "SET b 2\n"
        "COUNT\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("2"),std::string::npos);
}

TEST_F(RedisTest, Clear)
{
    auto result=Execute(
        "SET a 1\n"
        "SET b 2\n"
        "CLEAR\n"
        "COUNT\n"
        "EXIT\n"
    );

    EXPECT_NE(result.find("Cleared"),std::string::npos);
    EXPECT_NE(result.find("0"),std::string::npos);
}