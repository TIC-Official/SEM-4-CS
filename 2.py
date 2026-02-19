class HashTable:
    def __init__(self):
        self.size = 10
        self.slots = [None] * self.size
        self.data = [None] * self.size
        self.indices = [-1] * self.size

    def insert(self, key, data):
        hashvalue = self.hashfunction(key, len(self.slots))
        if self.slots[hashvalue] == None:
            self.slots[hashvalue] = key
            self.data[hashvalue] = data
        else:
            if self.slots[hashvalue] == key:
                self.data[hashvalue] = data
            else:
                nextslot = self.nextloc(hashvalue, len(self.slots))
                while self.slots[nextslot] != None and self.slots[nextslot] != key:
                    nextslot = self.nextloc(nextslot, len(self.slots))
                if self.slots[nextslot] == None:
                    self.slots[nextslot] = key
                    self.data[nextslot] = data
                    self.indices[hashvalue] = nextslot
                else:
                    self.data[nextslot] = data

    def hashfunction(self, key, size):
        return key % size

    def nextloc(self, oldhash, size):
        return (oldhash + 1) % size

    def delete(self, key):
        hashvalue = self.hashfunction(key, len(self.slots))
        check = 0
        while check != 1:
            if self.slots[hashvalue] == key:
                self.slots[hashvalue] = None
                self.data[hashvalue] = None
                self.indices[hashvalue] = -1
                break
            else:
                if self.indices[hashvalue] != -1:
                    oldhash = hashvalue
                    hashvalue = self.indices[hashvalue]
                    self.indices[oldhash] = -1
                else:
                    break

    def get(self, key):
        startslot = self.hashfunction(key, len(self.slots))
        data = None
        stop = False
        found = False
        position = startslot
        while self.slots[position] != None and not found and not stop:
            if self.slots[position] == key:
                found = True
                data = self.data[position]
            else:
                position = self.nextloc(position, len(self.slots))
            if position == startslot:
                stop = True
        return data

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, data):
        self.insert(key, data)

H = HashTable()
H[54], H[26], H[93], H[17] = "Rohit", "Anaya", "Nikita", "Amar"
print(H.slots)
print(H[17])
H.delete(17)
print(H.slots)