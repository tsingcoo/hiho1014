#include <iostream>
#include <cstring>
#include <sstream>

typedef struct Trie_node {
    int count;
    struct Trie_node *next[26];//这样子做已经不需要再加上字母的标记了，数组本身的序号就够了
    bool exist;
} TrieNode, *Trie;

TrieNode *creatTrieNode() {
    TrieNode *node = (TrieNode *) std::malloc(sizeof(TrieNode));
    node->count = 0;
    node->exist = 0;
    std::memset(node->next, 0, sizeof(node->next));
    return node;
}

void Trie_insert(Trie root, const char *word) {
    Trie node = root;
    const char *p = word;
    int id;
    while (*p) {
        id = *p - 'a';
        if (node->next[id] == NULL) {
            node->next[id] = creatTrieNode();
        }
        node = node->next[id];
        ++p;
        node->count += 1;
    }
    node->exist = true;
}

int Trie_search(Trie root, const char *word) {
    Trie node = root;
    const char *p = word;
    int id;
    while (*p) {
        id = *p - 'a';
        node = node->next[id];
        ++p;
        if (node == NULL) {
            return 0;
        }
    }
    return node->count;
}

int main() {

    Trie root = creatTrieNode();
    int cnt;
    std::string dic_len;
    std::getline(std::cin, dic_len);
    std::istringstream iss(dic_len);
    iss >> cnt;
    std::string word;
    for (int i = 0; i < cnt; ++i) {
        std::getline(std::cin, word);
        Trie_insert(root, word.c_str());
    }

    std::string search_cnt;
    std::getline(std::cin, search_cnt);
    std::istringstream iss2(search_cnt);
    iss2 >> cnt;
    for (int i = 0; i < cnt; ++i) {
        std::getline(std::cin, word);
        std::cout << Trie_search(root, word.c_str()) << std::endl;
    }
    return 0;
}