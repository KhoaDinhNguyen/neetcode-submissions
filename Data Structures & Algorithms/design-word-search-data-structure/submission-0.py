class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isLeaf = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        curr = self.root

        for w in word:
            i = ord(w) - ord('a')

            if curr.children[i] is None:
                curr.children[i] = TrieNode()

            curr = curr.children[i]
        
        curr.isLeaf = True
    
    def search(self, word: str) -> None:
        curr = self.root

        for w in word:
            i = ord(w) - ord('a')

            if curr.children[i] is None:
                curr.children[i] = TrieNode()

            curr = curr.children[i]
        
        return curr.isLeaf

class WordDictionary:

    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        self.trie.insert(word)
    
    def search(self, word: str) -> bool:
        # print(self.generateString(word));

        allPossibleWords = self.generateString(word)

        for word in allPossibleWords:
            if self.trie.search(word):
                return True
        return False
            
    def generateString(self, word: str) -> [str]:
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        
        preS = ""

        for i in range(len(word)):
            w = word[i]
            if w == '.':
                words = []
                subword = word[(i + 1):]

                for c in alphabet:
                    subGenereatedWord = self.generateString(subword)

                    for sub in subGenereatedWord:
                        words.append(preS + c + sub)

                return words
            
            preS = preS + w

        return [word]
