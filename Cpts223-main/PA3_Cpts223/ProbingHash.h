#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
   // vector<list<pair<K,V>>> hash_table;
    int hash_table_size;
    int element_count;
    vector<pair<K,V>> hash_table;
    vector<EntryState> EntryStateVector;

public:
    ProbingHash(int n = 11) {
        hash_table_size = n;
        hash_table.resize(hash_table_size);
        EntryStateVector.resize(hash_table_size);
        for(int i = 0; i < hash_table_size; i++)
        {
            EntryStateVector[i] = EMPTY;
        }
    }

    ~ProbingHash() {
        //this->clear();
        // Free all the elements
    }

    bool empty()
    {
        return element_count == 0;
    }

    int size() {
        return element_count;
    }

    int count(const K& key) {
        int x = hash(key);
        int _count = 0;
        int index = 0;

        while(hash_table[x].first != EMPTY)
        {
            if(hash_table[x].second.first == key && hash_table[x].first != DELETED)
            {
                _count++;
            }

            index++;
            x = hash(key+index);
        }


        return _count;
    }

    V& at (const K& key)
    {
        int x = hash(key);
        if(EntryStateVector[x] == VALID)
        {
            return hash_table[x].second;
        }

        //The key is not in the hash
            V to_return = -1;
             return to_return;
    }

    V& operator[](const K& key) {
        return at (key);
    }

    void emplace(K key, V value){
        pair<K,V> _pair;
        _pair.first = key;
        _pair.second = value;
        insert(_pair);
    }

    void insert(const std::pair<K, V>& _pair) {
        int x = hash(_pair.first);

        while(EntryStateVector[x] == VALID)
        {
            if(hash_table.first == _pair.first)
            {
                hash_table[x] = _pair;
                return;
            }

            x++;
        }

        if(load_factor() > 0.75)
        {
            rehash();
        }

        EntryStateVector[x] = VALID;
        hash_table[x] = _pair;
        element_count++;
    }

//    bool insert(const std::pair<K, V>& pair) {
//        return true;
//    }


    void erase(const K& key) {
        int x = hash(key);

        // Check if the element we have matches the key we want and if it is valid
            if (hash_table[x].first == key && EntryStateVector[x] == VALID)
            {
                EntryStateVector[x] = DELETED;
                element_count--;
            }

    }

    void clear() {

        hash_table_size = 0;
        element_count = 0;
        EntryStateVector.clear();
        hash_table.clear();

    }

   int bucket(const K& key){
    int x = hash(key);
    return x;  // Return the hashValue
}

int bucket_count() {
    return hash_table_size;
}

int bucket_size(int n)
{
    if(EntryStateVector[n] == VALID)
    {
        return 1;
    }
    return 0;
}

//    int bucket_size(int n)
//    {
//
//    }

float load_factor() {

    float float_number;
    float_number = float(element_count);
    float_number = float_number / (float)hash_table_size;

    return float_number;
}

void rehash(int n)
{
    auto oldLists = hash_table;
    int new_hash_table_size = n;

    hash_table_size = new_hash_table_size;
    hash_table.resize(new_hash_table_size);

    for(int i = 0; i < hash_table.size(); i++)
    {
        hash_table[i].clear();
    }

    element_count = 0;
    for(int x = 0; x < oldLists.size(); x++)
    {
        typename list<pair<K, V>> :: iterator a = oldLists[x];
        while(a != oldLists[x].end())
            insert(*a++);
    }

}

void rehash()
{
     rehash(findNextPrime(2 * hash_table_size + 1));
}

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        int hash_value = hash(key);

        hash_value %= hash_table.size();

        if( hash_value < 0)
        {
            hash_value += hash_table.size();
        }
        return hash_value;
    }
    
};

#endif //__PROBING_HASH_H
