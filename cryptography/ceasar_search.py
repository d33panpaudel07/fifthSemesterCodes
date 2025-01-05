def ceasar_encrypt(text, key):
    char_correction = 0
    result = ""
    for temp_char in text:
        char_correction = 65 if temp_char.isupper() else 97

        # converting from character to integer(i.e ascii integer value)
        ascii_value = ord(temp_char)
        # correcting the position from ascii to alphabetical index i.e(a is 97 and corrected is 0)
        alphabet_position = ascii_value - char_correction
        # applying ceasar function to encrypt
        encrypted_alphabet_position = (alphabet_position + key) % 26
        # converting the encrypted character to display by ascii index
        ascii_value = encrypted_alphabet_position + char_correction
        # converting the character from index to alphabet
        encrypted_char = chr(ascii_value)
        # appending to the result cause appaently you can't modify original string directly from here
        result += encrypted_char

    return result


def ceasar_decrypt(text, key):
    char_correction = 0
    result = ""
    for temp_char in text:
        char_correction = 65 if temp_char.isupper() else 97

        ascii_value = ord(temp_char)
        alphabet_position = ascii_value - char_correction
        encrypted_alphabet_position = (alphabet_position - key) % 26
        ascii_value = encrypted_alphabet_position + char_correction
        encrypted_char = chr(ascii_value)
        result += encrypted_char

    return text


def main():
    while True:
        user_input = input("Enter a text to encrypt or decrypt: ")
        user_operation = input('Enter "1" to encrypt or "2" to decrypt: ')
        user_key = int(input("Enter the key: "))

        result = ""
        if user_operation == "1":
            result = ceasar_encrypt(user_input, user_key)
            print(result)
            break
        elif user_operation == "2":
            result = ceasar_decrypt(user_input, user_key)
            print(result)
            break
        else:
            print("Wrong input, please try again...")


main()
