# -- file read --
# with open('message.txt', 'w') as file:
#     file.write('Hello Python')


# -- File Write -- 
with open('message.txt', 'r') as file:
    text = file.read()
    print(text)