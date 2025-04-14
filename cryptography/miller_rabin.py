from random import randint
import math


def miller_rabin(n, a):
    k = 0
    m = 1.0
    pow = 0
    prevm, prevk = m, k
    while m.is_integer():
        prevm, prevk = m, k
        m = (n - 1) / (2**pow)
        k = math.log(((n - 1) / m), 2)
        pow = k + 1
    m, k = int(prevm), int(prevk)
    T = (a**m) % n
    if T == 1 or T == n - 1:
        return True
    for i in range(0, k - 1):
        T = (T**2) % n
        if T == 1:
            return False
        if T == n - 1:
            return True
    return False


def main():
    print("-------------------- miller_rabin --------------------\n")
    n = 1231
    a = randint(1, n - 1)
    isprime = miller_rabin(n, a)
    if isprime:
        print(f"{n} is prime")
    else:
        print(f"{n} is composite")


main()
