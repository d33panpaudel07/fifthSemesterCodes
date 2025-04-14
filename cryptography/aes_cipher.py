from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes


def generate_key():
    return get_random_bytes(16)


def encrypt(plain_text, key):
    cipher = AES.new(key, AES.MODE_GCM)
    ciphertext, tag = cipher.encrypt_and_digest(plain_text.encode())
    return cipher.nonce + tag + ciphertext  # concatenation


def decrypt(encrypted_data, key):
    nonce = encrypted_data[:16]
    tag = encrypted_data[16:32]
    ciphertext = encrypted_data[32:]
    cipher = AES.new(key, AES.MODE_GCM, nonce=nonce)
    return cipher.decrypt_and_verify(ciphertext, tag).decode()


def main():
    key = generate_key()
    print(f"Generate Key (hex): {key.hex()}")

    plain_text = input("Enter text to encrypt: ")
    encrypted_data = encrypt(plain_text, key)

    print(f"Encrypted Data (hex): {encrypted_data.hex()}")

    decrypt_text = decrypt(encrypted_data, key)
    print(f"Decrypted Text: {decrypt_text}")


if __name__ == "__main__":  # Correct check to run the script
    main()
