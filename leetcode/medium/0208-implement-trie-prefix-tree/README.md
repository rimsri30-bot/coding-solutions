# Implement Trie (Prefix Tree)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A  **trie**  (pronounced as "try") or  **prefix tree**  is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

 

 **Example 1:** 

```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

```

 

 **Constraints:** 

- 1 <= word.length, prefix.length <= 2000
- word and prefix consist only of lowercase English letters.
- At most 3 * 104 calls in total will be made to insert, search, and startsWith.

## Solution

**Language:** C++  
**Runtime:** 36 ms (beats 56.79%)  
**Memory:** 50.6 MB (beats 31.04%)  
**Submitted:** 2026-11-26T08:51:34.772Z  

```cpp
class Trie {
    struct Node {
        Node* links[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++)
                links[i] = nullptr;

            isEnd = false;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->links[index] == nullptr)
                node->links[index] = new Node();

            node = node->links[index];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->links[index] == nullptr)
                return false;

            node = node->links[index];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (node->links[index] == nullptr)
                return false;

            node = node->links[index];
        }

        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/implement-trie-prefix-tree/)