# HashMap
It uses separate chaining using linkedlist for handling collisions and DynamicArray to manage the bucket table. It has an  hashing functor and a configurable load factor, allowing the user to change memory and performance tradeoffs based on their specific dataset.
Methods - 

## Public API -
```cpp
template<typename Key> struct DefaultHash; //an empty blueprint for hashing 
template<>
struct DefaultHash<string>//default hash blueprint for string keys(DJB2 algorithm)
template<>
struct DefaultHash<int>//default hash blueprint for integer keys (simple modulo with key multiplied with a large prime number)
template<typename Key, typename Value, typename Hash = DefaultHash<Key>> //template to make the hashmap generic and allow custom hash functors.
class HashMap {
    private:
        struct Node {
            Key key; Value value; Node* next;
            Node(const Key& k, const Value& v)
        };
        DynamicArray<Node*> buckets; //It is an array where every slot holds a chain of boxes (Nodes)
        double loadFactor; //threshold to trigger rehashing
        int elementCount; 
        int primeindex; 
        int PRIME_SIZES[] //takes some memory - giving O(1) lookup for next prime size 
        int getBucketIndex(const Key& key) const //internal method to compute bucket index using the hash functor
    public:
        HashMap(int initialBucketCount = 13, double loadFactor = 0.75); //construct with bucket count and load factor
        void set(const Key& key, const Value& value); //insert or update key-value pair
        bool get(const Key& key, Value& value) const; //safely retrieve value by key
        bool exists(const Key& key) const; //check if key exists
        void remove(const Key& key); //remove key-value pair
        void clear(); //delete all entries and reset state
        int size() const; //return sstored element count    
        double loadFactor() const; //return current load factor
        void rehash(); //resize bucket table and rehash entries
        ~HashMap(); //destructor
        HashMap(const HashMap&); //copy constructor
        HashMap& operator=(const HashMap&); //assignment operator
}
```
- The `get()` method returns the associated value through a reference parameter and uses a boolean return value to indicate success, avoiding ambiguous sentinel values for missing keys.
- Trades ~100 bytes of memory for a static array of prime numbers. This prevents massive CPU stalls during resizing and naturally scatters keys to avoid collision clustering.
- Uses an injectable functor for custom data types.
- Constructor accepts custom capacities and load factors, allowing systems to explicitly tune the tradeoff between memory footprint and guaranteed O(1) lookup speeds.

## Internal Representation - 

![HashMap](HashmapMemoryLayout.jpeg)

### Rule of Three:
- Destructor : Traverses each bucket and deletes all nodes in the collision chains, then deletes the bucket array.
- Copy Constructor : Allocates a new bucket array and deep copy each key-value pair from the source Hashmap .
- Assignment Operator : Deletes the existing HashMap, allocates a new bucket array & deep copy each key-value pair from the source HashMap.
- Shallow copy was not used because both HashMaps would share the same bucket array and linked lists, leading to double deletion and shared modification issues.

## Complexity Estimates - 

**set(const Key& key, const Value& value)**
* **Best / Average Case:** O(1)
* **Worst Case:** O(n)
* **Why:** The hash functor computes the bucket index instantly using arithmetic. It achieves O(1) average performance assuming a good hash distribution. The worst case O(n) occurs if an insertion triggers the load factor threshold forcing a complete `rehash()` or if severe collision clustering forces traversal on the chained list.

**get(const Key& key, Value& value) / exists(const Key& key)**
* **Best / Average Case:** O(1)
* **Worst Case:** O(n)
* **Why:** The hash functor calculates the exact memory bucket instantly. The operation is typically O(1), but degrades to O(n) in the worst case if weak hashing causes severe collisions forcing the algorithm to linearly traverse a long linked list chain to find the matching key.

**remove(const Key& key)**
* **Best / Average Case:** O(1)
* **Worst Case:** O(n)
* **Why:** Finding the correct bucket is instantaneous via hashing. If the item is at the head of the collision chain, deletion is O(1). If the item is deep inside the chain it requires O(n) traversal to locate and switch the pointers.

**rehash()**
* **Best / Average / Worst Case:** O(n)
* **Why:** To properly redistribute data a new bucket array must be allocated. Every single key-value pair currently stored in the map must be visited have its hash mathematically recalculated against the new prime capacity, and be re-inserted into the new list.

**clear()**
* **Best / Average / Worst Case:** O(n)
* **Why:** The map must loop through every array bucket and traverse and delete every linked node within every collision chain to properly release all heap memory.

**size() / currentLoadFactor()**
* **Best / Average / Worst Case:** O(1)
* **Why:** These methods perform basic arithmetic or simply return tracked primitive state variables, independent of the volume of data stored in the map.

## Design Decisions -
* Prime Capacity Array is used instead of Resizing by powers of 2 (capacity * 2) or calculating prime numbers algorithmically at runtime using a while(!isPrime()) loop because power-of-2 capacities cause severe collision clustering if a user provides a weak hash function, because the modulo operator effectively ignores the higher order bits of the hash. While calculating primes at runtime solves this it introduces an unacceptable O(n​) CPU stall during the already expensive O(n) rehashing phase. A static prime array resolves both issues, trading ~100 bytes of memory for instantaneous& mathematically safe capacity lookups.
* Selected separate chaining using linked lists for collision handling because it simplifies deletion and integrates naturally with the LinkedList implementation.
* Configured the HashMap to rehash when the load factor reaches 0.75 in default case, maintaining efficient average-case lookup performance while the load factor can be set by passing the required load factor in the constructor.
* Implemented `get()` using a reference parameter and boolean return value, avoiding ambiguous sentinel values for missing keys.
* Considered linear probing, but rejected it due to clustering and more complex deletion.
* Considered*Red-Black Tree buckets, but rejected them because the additional balancing logic and implementation complexity were not justified for the expected performance.
