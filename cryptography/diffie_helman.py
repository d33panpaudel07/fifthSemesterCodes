from random import randint


class User:
    def __init__(self, p, g) -> None:
        self.private = randint(1, p)
        self.public = pow(g, self.private, p)

    def get_public_key(self):
        return self.public

    def get_shared_key(self, public_other, p):
        return pow(public_other, self.private, p)


def main():
    print("-------------------- diffie_helman --------------------\n")
    p = 321
    g = 31

    alice = User(p, g)
    bob = User(p, g)

    Ya = alice.get_public_key()
    Yb = bob.get_public_key()

    Ska = alice.get_shared_key(Yb, p)
    Skb = bob.get_shared_key(Yb, p)

    print("Public Key of Alice:", Ya)
    print("Public Key of Bob:", Yb)
    print("Shared Key of Alice:", Ska)
    print("Shared Key of Bob:", Skb)


main()
