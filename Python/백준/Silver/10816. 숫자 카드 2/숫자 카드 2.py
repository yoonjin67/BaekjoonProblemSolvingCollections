def main():
    n = int(input())
    cards = input().split()
    dictionary = {}
    for itm in cards:
        if itm in dictionary:
            dictionary[itm] = dictionary[itm] + 1
        else:
            dictionary[itm] =1
    n = int(input())
    cards = input().split()
    for i in range(n):
        itm = cards[i]
        if itm in dictionary:
            print(dictionary[itm],end="")
        else:
            print(0,end="")
        if itm != n:
            print(" ", end="")
if __name__=="__main__":
    main()