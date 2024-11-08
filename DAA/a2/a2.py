import heapq

class Node :
    def __init__(self , val , charsymbol) : 
        self.val = val    #freq
        self.symbol = charsymbol #char
        self.huffmanCode = ''  #0 or 1
        self.l = None
        self.r = None


    def __lt__(self , next) :   #comparator
        return self.val < next.val
    

nodesHeap = []   #heap to store nodes 
charsymbolArray = ['a' , 'b' , 'c' , 'd' , 'e']
frequency = [50 , 20 , 90 , 30 , 10]

for i in range(len(charsymbolArray)):
    heapq.heappush(nodesHeap , Node(frequency[i] , charsymbolArray[i]))



while(len(nodesHeap)) > 1 :
    left = heapq.heappop(nodesHeap)  #smallest
    right = heapq.heappop(nodesHeap) #2nd smallest
    left.huffmanCode = '0'
    right.huffmanCode = '1'


    #parent Node
    newNode = Node(left.val + right.val , left.symbol + right.symbol)
    newNode.l = left
    newNode.r = right
    heapq.heappush(nodesHeap , newNode)



def printNodes(node , val = '') : 
    newVal = val + node.huffmanCode

    if node.l :
        printNodes(node.l , newVal)

    if node.r :
        printNodes(node.r , newVal)

    if(not node.l and not node.r) :
        print(f"{node.symbol} - > {newVal}")

    

printNodes(nodesHeap[0])
    