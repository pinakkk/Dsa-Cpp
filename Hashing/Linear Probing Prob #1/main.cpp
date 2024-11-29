#include <iostream>
using namespace std;
#define SIZE 100

int calHash(int key, int size) {
    return key % size;
}

int main() {
    int size, numKeys, keys[SIZE];
    cin >> size >> numKeys;
    
    // initialize
    int hashTable[SIZE];
    for(int i=0; i<size; i++){
        hashTable[i] = -1;
    }
    
    // Input
    for(int i=0; i<size; i++){
        cin >> keys[i];
    }
    
    // Linear Probing
    for(int i=0; i<numKeys; i++){
        int k = 1;
        int key = keys[i];
        int hashIndex = calHash(key, size);
        
        while(hashTable[hashIndex] != -1){
            hashIndex = (key + 1) % size;
            k++;
        }
        hashTable[hashIndex] = key;
    }
    
    // Printing
    for(int i=0; i<size; i++){
        if(hashTable[i] != -1){
            cout << "index: " << i << "," << " value: " << hashTable[i];
        }
    }

    return 0;
}
    