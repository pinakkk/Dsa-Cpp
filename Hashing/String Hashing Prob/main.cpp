#include <iostream>
#include <string>
using namespace std;
#define HASH_TABLE_SIZE 1000


// You are using GCC
unsigned int customHash(string key) {
    unsigned int hashVal = 0;
    for(char ch : key){
        hashVal = (hashVal * 37) + ch;
    }
    
    return hashVal % HASH_TABLE_SIZE;
}

int main() {
    string subject;
    
    while(1){
        getline(cin, subject);
        if (subject == "exit"){
            break;
        }
        unsigned int hashVal = customHash(subject);
        cout << hashVal << endl;
    }
    return 0;
}