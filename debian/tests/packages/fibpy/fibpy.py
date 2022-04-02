import sys


def fib(n):
    if n < 0:
        raise ValueError()
    if n < 2:
        return 1
    return fib(n - 1) + fib(n - 2)


if __name__ == '__main__':
    print(fib(int(sys.argv[1])))
