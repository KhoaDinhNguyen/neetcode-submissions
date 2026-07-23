class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isLeaf = False

class PrefixTree:
    def __init__(self):
       self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root

        for w in word:
            idx = ord(w) - ord('a')
            
            if curr.children[idx] is None:
                curr.children[idx] = TrieNode()
            
            curr = curr.children[idx]
        
        curr.isLeaf = True

    def search(self, word: str) -> bool:
        curr = self.root

        for w in word:
            idx = ord(w) - ord('a')

            if curr.children[idx] is None:
                return False
            
            curr = curr.children[idx]
        
        return curr.isLeaf;

    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for w in prefix:
            idx = ord(w) - ord('a')

            if curr.children[idx] is None:
                return False

            curr = curr.children[idx]
            
        return True;
        