from pickletools import decimalnl_long
from random import randint


class User:
    def __init__(self, p, alpha) -> None:
        self.private = randint(2, p - 2)
        self.public = alpha**self.private % p

    def get_public_key(self):
        return self.public

    def Ephemeral_key(self, alpha, p):
        self.i = randint(2, p - 2)
        self.ke = (alpha**self.i) % p
        return self.ke

    def mask_key_enc(self, other_public, p):
        self.km_enc = (other_public**self.i) % p

    def mask_key_dec(self, ke, p):
        self.km_dec = (ke**self.private) % p

    def encrypt(self, msg, p):
        return (msg * self.km_enc) % p

    def decrypt(self, msg, p):
        inv = 1
        while (self.km_dec * inv) % p != 1:
            inv += 1
        return (msg * inv) % p


def main():
    p = 29
    alpha = 2
    bob = User(p, alpha)
    alice = User(p, alpha)

    pub_bob = bob.get_public_key()
    pub_alice = alice.get_public_key()

    ke_alice = alice.Ephemeral_key(alpha, p)
    alice.mask_key_enc(pub_bob, p)
    msg = 14
    enc = alice.encrypt(msg, p)

    bob.mask_key_dec(ke_alice, p)
    dec = bob.decrypt(enc, p)

    print("Public Key Alice: ", pub_alice)
    print("Public Key Bob: ", pub_bob)
    print("Ephemeral Key Alice: ", ke_alice)
    print("Encrypted Message:", enc)
    print("Decrypted Message:", dec)


if __name__ == "__main__":
    print("-------------------- elgamal --------------------\n")
    main()
