/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//

template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
     // Creating elements of the private function
   vector<list<pair<K,V>>> hash_table;
     int hash_table_size;
     int element_count;

public:
   ChainingHash(int n = 11) {
    //ChainingHash(int n ) {
        hash_table_size = n;
       hash_table.resize(hash_table_size);
       element_count = 0;
      // hash_table.resize(findNextPrime(n), list<pair<K,V>>());
    }

    ~ChainingHash() {
        this->clear();
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
        list<pair<K,V>> listA = hash_table[x];
        int _count = 0;

        // Go through the list listA
        typename list<pair<K,V>> :: iterator z;
        for(auto z: listA)
        {
            if( ((*z).first )== key)   // Check if the key we have matches the key we want
                _count++;   // Keep track of how many times an element matches the key
        }
         return _count;
    }

    V& at (const K& key)
    {
       int x = hash(key);
        list<pair<K,V>> listA = hash_table[x];

        typename list<pair<K,V>> :: iterator y;

           // Go through the list listA
        for(auto y: listA)
        {
            if( (*y).first == key)   // Check if the key we have matches the key we want
                return (*y).second;   // Return the value
        }

              // x < 0 or x > hashTable size
           throw std::out_of_range("The key is not in the hashTable");
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
      hash_table[x].push_back(_pair);
      element_count++;

      if(load_factor() > 0.75)
      {
          rehash();
      }
    }

//    bool insert(const std::pair<K, V>& pair) {
//        return true;
//    }


    void erase(const K& key) {
        int x = hash(key);
        list<pair<K,V>> listA = hash_table[x];

        typename list<pair<K,V>> :: iterator y;

        // Go through the list listA
        for(auto y: listA) {
            if ((*y).first == key)   // Check if the key we have matches the key we want
            {
                hash_table[x].clear();
                element_count--;
            }
        }
    }

    void clear() {

        for(auto i = 0; i < hash_table.size(); i++)
        {
            hash_table[i].clear();
        }
    }

    int bucket(const K& key){
        int x = hash(key);
        list<pair<K,V>> listA = hash_table[x];
        typename list<pair<K,V>> :: iterator y;

        // Go through the list listA
        for(auto y: listA)
        {
            if( (*y).first == key)   // Check if the key we have matches the key we want
                return x;  // Return the hashValue
        }

             // The key is not in the hash
        return -1;
    }

    int bucket_count() {
        return hash_table.size();
    }

    int bucket_size(int n)
    {
        return hash_table[n].size();
    }

//    int bucket_size(int n)
//    {
//
//    }
    float load_factor() {
       // return -1;
        float float_number;
        float_number = float(element_count);
        float_number = float_number / (float)hash_table_size;

        return float_number;
    }

    void rehash(int n)
    {
        vector<list<pair<K,V>>> oldLists = hash_table;
        if(isPrime(n)) {
            hash_table_size = n;
        }

        else
        {
            hash_table_size = findNextPrime(n);
        }

        hash_table.resize(hash_table_size);
        for(auto & thisList : hash_table)
        {
            thisList.clear();
        }

        // Copy table over
        element_count = 0;
        for( auto & thisList : oldLists ) {
            for (auto &x: thisList)
                insert(std::move(x));
        }
    }

    void rehash()
    {
        vector<list<pair<K,V>>> oldLists = hash_table;

        // Create new double-sized, empty table
        hash_table.resize(findNextPrime( 2 * hash_table.size( ) ) );
        for( auto & thisList : hash_table )
            thisList.clear( );

              // Copy table over
        element_count = 0;
         for( auto & thisList : oldLists )
             for( auto & x : thisList )
            insert( std::move( x ) );
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

   // int hash(const K & key) const
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

#endif //__CHAINING_HASH_H
