counter = 0

def TOH(n, s, a, d):
    global counter
    counter = counter + 1
    
    if (n == 1):
        print(s + " -> " + d)
        return

    TOH(n-1, s, d, a)
    print(s + " -> " + d)
    TOH(n-1, a, s, d)


n = int(input("Enter the number of disks: "))
print("Tower of Hanoi for " + str(n) + " disks")
TOH(n, "s", "a", "d")
print("Cost is: " + str(counter))
