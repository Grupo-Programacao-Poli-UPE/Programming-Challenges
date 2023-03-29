num = input('Digite dois valores: ')
steps = []
list = num.split( )

cycles = []

for x in range(int(list[0]), int(list[1])+1):
    steps.clear()
    lastValue = x
    while(lastValue>=1):
        if(lastValue==1):
            steps.append(0)
            lastValue = -1
        elif(lastValue%2==0):
            if(lastValue/2==1):
                steps.append(lastValue-1)
                lastValue = -1
                break
            lastValue = lastValue/2
            steps.append(lastValue)
        else:
            lastValue = (3*lastValue)+1
            steps.append(lastValue)
    cycles.append(len(steps))

print(f'{list[0]} {list[1]} {int(max(cycles))+1}')
