import heapq


class Node:
    def _init_(self, freq, sym, code='') -> None:
        self.freq = freq
        self.code = code
        self.sym = sym
        self.left = None
        self.right = None

    def _lt_(self, nxt):
        return self.freq < nxt.freq


class HuffmanCoding:
    def _init_(self, message):
        self.message = message
        self.root = None
        self.encoding_table = {}

    def _traverse(self, node: Node, code: str, table):
        if node is None:
            return table
        if node.left is None and node.right is None:
            table[node.sym] = code
            return table
        table = self._traverse(node=node.left, code=code+'0', table=table)
        self._traverse(node=node.right, code=code+'1', table=table)
        return table

    def encode(self):
        cnt = {}
        for i in self.message:
            cnt[i] = cnt.get(i, 0) + 1

        count_arr = []
        for sym, freq in cnt.items():
            heapq.heappush(count_arr, Node(freq, sym))

        while len(count_arr) > 1:
            a = heapq.heappop(count_arr)
            b = heapq.heappop(count_arr)
            newNode = Node(freq=a.freq + b.freq, sym=None)
            newNode.left = a
            newNode.right = b
            heapq.heappush(count_arr, newNode)

        self.root = count_arr[0]
        self.encoding_table = self._traverse(node=self.root, code='', table={})
        print("Encoding Table:", self.encoding_table)

        original_size = sum(cnt[sym] * 8 for sym in cnt)
        compressed_size = sum(
            cnt[sym] * len(self.encoding_table[sym]) for sym in cnt)

        print('Size before compression =', original_size)
        print('Size after compression =', compressed_size)
        print('%Compression =',
              ((original_size - compressed_size) / original_size) * 100, "%")

        encoded_message = ''.join(
            self.encoding_table[char] for char in self.message)
        return encoded_message

    def decode(self, encoded_message):
        decoded_message = ''
        current_node = self.root

        for bit in encoded_message:
            if bit == '0':
                current_node = current_node.left
            else:
                current_node = current_node.right

            if current_node.left is None and current_node.right is None:
                decoded_message += current_node.sym
                current_node = self.root

        return decoded_message


message = input("Enter the message to encode: ")
huffman = HuffmanCoding(message)

encoded_message = huffman.encode()
print("Encoded Message:", encoded_message)

decoded_message = huffman.decode(encoded_message)
print("Decoded Message:", decoded_message)