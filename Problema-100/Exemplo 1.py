value1 = int(input("Valor 1: "))
value2 = int(input("Valor 2: "))

countCycle = []

def cicle(num):
    count = 1
    while num != 1:
        if(num % 2 == 0):
            num = num/2
            count = count + 1
        else:
            num = num*3 + 1
            count = count + 1
    countCycle.append(count)

for i in range(value1, value2+1):
    cicle(i)

print("{} {} {}". format(value1, value2, max(countCycle)))

