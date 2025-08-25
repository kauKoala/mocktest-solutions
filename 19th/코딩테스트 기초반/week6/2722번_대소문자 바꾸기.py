word = input()

for i in word:
    if i.islower():
        print(i.upper(), end="")
    else:
        print(i.lower(), end="")