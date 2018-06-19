# Radix Tree
A C++ implementation of a Radix Tree with some interesting features:
1- Insertion
2- Searching
3- Deletion

A Radix Tree is a data structure that represents a space-optimized trie in which each node that is the only child is merged with its parent. The result is that the number of children of every internal node is at most the radix r of the radix tree, where r is a positive integer and a power x of 2, having x ≥ 1. Unlike in regular tries, edges can be labeled with sequences of elements as well as single elements. This makes radix trees much more efficient for small sets (especially if the strings are long) and for sets of strings that share long prefixes.

First three words are inserted and it is checked and verified that they exist by performing searching and then each word is deleted and again searching is performed to verify that all words are deleted.

In order to run the project:
Just download the whole folder which contains all the neccessary files (i.e cpp and sln)
Run sln file and execute the code
If you want to change words you can do it by changing words in main function

Project prepared by
Syed Khawaja Fasih Uddin    (15B-018-SE-B)
Shahzar Hussain             (15B-017-SE-B)
