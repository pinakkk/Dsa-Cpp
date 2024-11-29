Sindhu is working on implementing a hash table with linear probing to efficiently store a set of unique integer keys. She is seeking your help to develop a program that accomplishes this.



Your task is to write a program that takes a series of integers as input, hashes them into a hash table, resolves any collisions using linear probing, and then displays the keys and their corresponding indices in ascending order of their index.



Example

Input: 

5

5

14 16 17 26 10

Output: 

index: 0, value: 10

index: 1, value: 16

index: 2, value: 17

index: 3, value: 26

index: 4, value: 14



Explanation:
The keys are inserted into the hash table division method using linear probing to resolve any collisions.

Key 14 is inserted at index 4.
Key 16 is inserted at index 1.
Key 17 is inserted at index 2.
Key 26 initially collides with index 1 but is inserted at the next available slot, which is index 3, using linear probing.
Key 10 is inserted at index 0.

The keys and their respective indices are displayed in the ascending order of their index.

Input format :
The first line of input consists of an integer size, which represents the size of the hash table.

The second line of input consists of an integer n, which represents the number of keys to be inserted.

The third line of input consists of n integers separated by a space, representing the keys to be inserted.

Output format :
For each key, the output displays a line with the following format: "index: [index], value: [value]".

where [index] is the index in the hash table in ascending order, where the key is stored after resolving collisions, and [value] is the corresponding key value.



Refer to the sample output for the formatting specifications.

Code constraints :
The test cases will fall under the following constraints:

1 ≤ size ≤ 10

1 ≤ n ≤ 10

1 ≤ keys ≤ 100

Sample test cases :
Input 1 :
5
5
14 16 17 26 10
Output 1 :
index: 0, value: 10
index: 1, value: 16
index: 2, value: 17
index: 3, value: 26
index: 4, value: 14
Input 2 :
10
5
10 43 68 90 13
Output 2 :
index: 0, value: 10
index: 1, value: 90
index: 3, value: 43
index: 4, value: 13
index: 8, value: 68