# wap to encrypt and decrrypt through rail fence
def EncrytMessage(message, key):
    cipherText = ""
    c = 0
    r = 0
    i = 0
    down = True
    matrix = [[None for _ in range(len(message))] for _ in range(key)]
    while c < len(message):
        matrix[r][c] = message[i]
        r = r + 1 if down else r - 1

        down = True if r == 0 else False

        c += 1
        i += 1

    for row in matrix:
        # print("Printing ROW XDXDXD")
        print(row)
        for item in row:
            if item != None:
                cipherText += item
    return cipherText


print(EncrytMessage("INFORMATIONSECURITY", 4))
print(EncrytMessage("CRYPTOGRAPHY", 2))
