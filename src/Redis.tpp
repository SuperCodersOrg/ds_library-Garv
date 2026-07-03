inline void Redis::run()
{
    std::string line;
    std::cout << "===================================== Welcome to Redis Lite CLI =====================================" << std::endl;
    printcommands();

    while (true)
    {
        std::cout << "->";

        if (!std::getline(std::cin, line))
        {
            break;
        }

        if (line.empty())
        {
            continue;
        }

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "SET")
        {
            handleSet(ss);
        }
        else if (command == "GET")
        {
            handleGet(ss);
        }
        else if (command == "DEL")
        {
            handleDel(ss);
        }
        else if (command == "EXISTS")
        {
            handleExists(ss);
        }
        else if (command == "COUNT")
        {
            handleCount();
        }
        else if (command == "CLEAR")
        {
            handleClear();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else if (command == "STATS")
        {
            stats();
        }
        else if (command == "DEBUG")
        {
            printdebug();
        }
        else if (command == "PRINT")
        {
            print();
        }
        else if (command == "HELP")
        {
            printcommands();
        }
        else
        {
            std::cout << "Unknown Command";
        }
    }
}

inline void Redis::printcommands()
{
    std::cout << "Commands - " << std::endl;
    std::cout << "SET key value" << std::endl;
    std::cout << "GET key" << std::endl;
    std::cout << "DEL key" << std::endl;
    std::cout << "EXISTS key" << std::endl;
    std::cout << "COUNT key" << std::endl;
    std::cout << "CLEAR key" << std::endl;
    std::cout << "STATS" << std::endl;
    std::cout << "PRINT" << std::endl;
    std::cout << "DEBUG" << std::endl;
    std::cout << "EXIT" << std::endl << std::endl;
}

inline void Redis::handleSet(std::stringstream& ss)
{
    std::string key, value;
    ss >> key;
    std::getline(ss, value);

    if (!value.empty() && value[0] == ' ')
    {
        value.erase(0, 1);
    }

    if (key.empty() || value.empty())
    {
        std::cout << "To make an entry use - SET <key> <value>" << std::endl;
        return;
    }

    storage.insert(key, value);
    std::cout << "Done" << std::endl;
}

inline void Redis::handleGet(std::stringstream& ss)
{
    std::string key;
    ss >> key;

    if (key.empty())
    {
        std::cout << "To get a value from key use - GET <key>" << std::endl;
        return;
    }

    std::string value;
    if (storage.get(key, value))
    {
        std::cout << value << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }
}

inline void Redis::handleDel(std::stringstream& ss)
{
    std::string key;
    ss >> key;

    if (key.empty())
    {
        std::cout << "To delete a key use - DEL <key>" << std::endl;
        return;
    }

    if (storage.exists(key))
    {
        storage.remove(key);
        std::cout << "Deleted" << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
}

inline void Redis::handleExists(std::stringstream& ss)
{
    std::string key;
    ss >> key;

    if (key.empty())
    {
        std::cout << "To check if a key exists use - EXISTS <key>" << std::endl;
        return;
    }

    if (storage.exists(key))
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }
}

inline void Redis::handleCount()
{
    std::cout << storage.size() << std::endl;
}

inline void Redis::handleClear()
{
    storage.clear();
    std::cout << "Cleared" << std::endl;
}

inline void Redis::print()
{
    storage.print();
}

inline void Redis::stats()
{
    std::cout << "Elements : " << storage.size() << std::endl;
    std::cout << "Buckets : " << storage.bucketCount() << std::endl;
    std::cout << "LoadFactor : " << storage.loadFactor() << std::endl;
    std::cout << "Collisions : " << storage.collisions() << std::endl;
}

inline void Redis::printdebug()
{
    storage.debugPrint();
}