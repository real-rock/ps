if __name__ == '__main__':
    n = int(input())
    k = int(input())
    l = sorted([int(x) for x in input().split(" ")])

    array = []
    for i in range(0, n - 1):
        array.append(l[i + 1] - l[i])

    array.sort()

    print(sum(array[: n - k]))
