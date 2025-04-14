import numpy as np


def encryptMessage(plainText, key):
    cipherText = ""
    keylen = int(np.ceil(len(plainText) / len(key)))
    key *= keylen
    count = 0
    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index + shifter) % 26
            cipherText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index + shifter) % 26
            cipherText += upperCase[shiftedIndex]
            count += 1
        else:
            cipherText += letter
            count += 1
    return cipherText


def decryptMessage(cipherText, key):
    plainText = ""
    count = 0
    keylen = int(np.ceil(len(cipherText) / len(key)))
    key *= keylen
    for letter in cipherText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index - shifter) % 26
            plainText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index - shifter) % 26
            plainText += upperCase[shiftedIndex]
            count += 1
        else:
            plainText += letter
            count += 1
    return plainText


upperCase = []
lowerCase = []

for i in range(65, 91):
    upperCase.append(chr(i))

for j in range(97, 123):
    lowerCase.append(chr(j))

print("-------------------- vignere_cipher --------------------\n")
message = input("Enter your Message: ")
key = "mykey"
cipherText = encryptMessage(message, key)
print(f"Your encrypted Message: {cipherText}")
key2 = input("Please enter the secret key to decrypt the message: ")
plainText = decryptMessage(cipherText, key2)
print(f"Your hidden message is : {plainText}")
