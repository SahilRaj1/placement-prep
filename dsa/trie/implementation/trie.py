""" Trie """

class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfString = False

class Trie:
    def init(self):
        self.root = TrieNode()

    def insertString(self, word):
        current = self.root
        for i in word:
            ch = i
            node = current.children.get(ch)
            if node == None:
                node = TrieNode()
                current.children.update({ch:node})
            current = node
        current.endOfString = True

    def searchString(self, word):
        current = self.root
        for i in word:
            node = current.children.get(i)
            if node == None:
                return False
            current = node
        if current.endOfString == True:
            return True
        else:
            return False

def deleteString(root, word, index):
    ch = word[index]
    current = root.children.get(ch)
    flag = False    # Can this node be deleted

    if len(current.children) > 1:
        deleteString(current, word, index+1)
        return False
    if index == len(word) - 1:
        if len(current.children) >= 1:
            current.endOfString = False
            return False
        else:
            root.children.pop(ch)
            return True
    if current.endOfString == True:
        deleteString(current, word, index+1)
        return False

    flag = deleteString(current, word, index+1)
    if flag == True:
        root.children.pop(ch)
        return True
    else:
        return False


sample = Trie()
