import math

MX = 105


def sieve(isPrime):
    isPrime[0] = isPrime[1] = False
    for i in range(2, int(math.sqrt(MX))):
        if isPrime[i]:
            for j in range(2*i, MX, i):
                isPrime[j] = False


def printPrime(isPrime):
    for i in range(MX):
        if isPrime[i]:
            print(i, end=" ")
    print()


if __name__ == '__main__':
    isPrime = [True for _ in range(MX)]
    sieve(isPrime)
    printPrime(isPrime)
