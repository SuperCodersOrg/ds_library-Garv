#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include <HashMap.h>

class Redis
{
public:
    void run();

private:
    HashMap<std::string, std::string> storage;

    void printcommands();
    void handleSet(std::stringstream& ss);
    void handleGet(std::stringstream& ss);
    void handleDel(std::stringstream& ss);
    void handleExists(std::stringstream& ss);
    void handleCount();
    void handleClear();
    void print();
    void stats();
    void printdebug();
};

#include "../src/Redis.tpp"