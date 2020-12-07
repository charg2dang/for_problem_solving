class node:
    def __init__(self, key):
        self.key = key;
        self.data = None;
        self.nexts = {};

class trie:
    def __init__(self):
        self.head = node(None);

    def insert(self, word:str) -> None:
        cur_node = self.head;

        for ch in word:
            if ch not in cur_node.nexts:
                cur_node.nexts[ch] = node(ch);
            
            cur_node = cur_node.nexts[ch];
            
        cur_node.data = word;



    def search(self, word:str) -> bool : 
        cur_node = self.head;

        for ch in word:
            if ch in cur_node.nexts:
                cur_node = cur_node.nexts[ch];
            else :
                return False;

        return cur_node.data == word;



t = trie();
t.insert("abc");

print ( t.search("abc") );
print ( t.search("abd") );
