# Redis Lite

Redis Lite is a small interactive command-line layer built on top of the project’s `HashMap<std::string, std::string>` implementation. It provides a simple shell for inserting, reading, deleting, and inspecting key/value pairs.

## File layout

- `include/Redis.h` declares the `Redis` class and includes the implementation file.
- `src/Redis.tpp` contains the method definitions.

## Commands

- `SET <key> <value>` stores a key/value pair. Values may contain spaces.
- `GET <key>` prints the stored value for a key.
- `DEL <key>` removes a key if it exists.
- `EXISTS <key>` prints `True` or `False`.
- `COUNT` prints the number of stored entries.
- `CLEAR` removes all entries.
- `STATS` prints the current element count, bucket count, load factor, and collision count.
- `PRINT` prints all stored key/value pairs.
- `DEBUG` prints bucket-level debug information.
- `HELP` prints the command list again.
- `EXIT` leaves the shell.

# Notes - 

- Input is parsed one line at a time.
- `SET` preserves everything after the key as the value including spaces.
- Unknown commands print `Unknown Command`.
- The shell uses the project’s hash map as its only storage layer 