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
        allPossibleWords = self.generateWords(word)

        for word in allPossibleWords:
            if self.trie.search(word):
                return True
        return False
            
    def generateWords(self, word: str) -> [str]:
        preDot = ""
        i = 0

        while i in range(len(word)):
            if word[i] == '.':
                break;
            preDot = preDot + word[i]
            i = i + 1
        
        # if i equals word size, then there is no dot in the word
        # returns array with the word itself
        if i == len(word):
            return [word]

        # Get the string after dot, and continue to generate
        postDot = word[(i + 1): ]
        postDotWords = self.generateWords(postDot)
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        words = []

        for c in alphabet:
            for postWord in postDotWords:
                words.append(preDot + c + postWord)    
    
        return words
