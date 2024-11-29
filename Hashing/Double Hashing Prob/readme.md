## Quadratic Probing : 

### Problem Statement:
1. **Quadratic Probing in Hashing**:
   - If the slot `hash(x) % S` is full, then try `(hash(x) + 1*1) % S`.
   - If that slot is also full, try `(hash(x) + 2*2) % S`.
   - Continue this process `(hash(x) + 3*3) % S` and so on until an empty slot is found.

### Input Format:
1. **Size of the Array**: The first line of input consists of the size of the array.
2. **Array of Elements**: The second line of input consists of the array of elements separated by spaces.
3. **Size of the Hashtable**: The last line of input consists of the size of the hashtable.

### Output Format:
- Print the space-separated array elements after implementing the conditions mentioned in the problem statement.

### Sample Test Cases:
**Input 1**:
```
7
50 700 76 85 92 73 101
7
```
**Output 1**:
```
700 50 85 73 101 92 76
```

**Input 2**:
```
4
76 101 50 700
3
```
**Output 2**:
```
50 76 101
```

### Task:
- Implement the hashing function with quadratic probing.
- Complete the functions: `printArray`, `hashing`, `initializeHashTable`, and optionally `readKeys`, if necessary.

The final implementation should include a way to read the keys, initialize the hash table, insert keys using quadratic probing, and finally find the first and last non-empty slots in the hash table, printing the results accordingly.

