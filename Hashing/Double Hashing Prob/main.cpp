#include <iostream>
#include <vector>
using namespace std;

// Function to read keys into an array
void readKeys(vector<int>& keys, int numKeys) {
    for (int i = 0; i < numKeys; i++) {
        int key;
        cin >> key;
        keys.push_back(key);
    }
}

// Function to initialize the hash table
void initializeHashTable(vector<int>& hashTable, int tableSize) {
    hashTable.assign(tableSize, -1); // -1 indicates an empty slot
}

// Function to insert keys into the hash table using quadratic probing
void insertKeys(vector<int>& hashTable, int tableSize, const vector<int>& keys) {
    for (int key : keys) {
        int hashIndex = key % tableSize;
        int k = 1;

        // Quadratic probing
        while (hashTable[hashIndex] != -1) {
            hashIndex = (key + k * k) % tableSize;
            k++;
        }

        // Insert key into the hash table
        hashTable[hashIndex] = key;
    }
}

// Function to find the first and last non-empty slots in the hash table and their indices
void findFirstAndLast(const vector<int>& hashTable, int& first, int& last, int& firstIndex, int& lastIndex) {
    first = -1;
    last = -1;
    firstIndex = -1;
    lastIndex = -1;

    for (int i = 0; i < hashTable.size(); i++) {
        if (hashTable[i] != -1) {
            if (first == -1) {
                first = hashTable[i];
                firstIndex = i;
            }
            last = hashTable[i];
            lastIndex = i;
        }
    }
}

// Main function
int main() {
    int numKeys, tableSize;

    // Read the number of keys
    cin >> numKeys;
    vector<int> keys;
    readKeys(keys, numKeys);

    // Read the table size
    cin >> tableSize;
    vector<int> hashTable(tableSize);

    // Initialize the hash table
    initializeHashTable(hashTable, tableSize);

    // Insert keys into the hash table
    insertKeys(hashTable, tableSize, keys);

    // Find the first and last keys and their indices
    int first, last, firstIndex, lastIndex;
    findFirstAndLast(hashTable, first, last, firstIndex, lastIndex);

    // Print the results
    if (first != -1) {
        cout << "First key: " << first << " at index " << firstIndex << endl;
    } else {
        cout << "No keys in hash table" << endl;
    }

    if (last != -1) {
        cout << "Last key: " << last << " at index " << lastIndex << endl;
    }

    return 0;
}
