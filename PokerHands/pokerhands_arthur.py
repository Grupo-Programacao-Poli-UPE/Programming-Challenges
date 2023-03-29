hand = input('Digite a sua mao: ')
suits = []
cards = []
suits2 = []
cards2 = []
power = []
c = 0

def checkValue(value):
    if(value == '2'):
        return 1
    elif(value == '3'):
        return 2
    elif(value == '4'):
        return 3
    elif(value == '5'):
        return 4
    elif(value == '6'):
        return 5
    elif(value == '7'):
        return 6
    elif(value == '8'):
        return 7
    elif(value == '9'):
        return 8
    elif(value == 'T'):
        return 9
    elif(value == 'J'):
        return 10
    elif(value == 'Q'):
        return 11
    elif(value == 'K'):
        return 12
    elif(value == 'A'):
        return 13
    else:
        return value

def checkStraightFlush(suits, cards):
    c = 0
    i = 0
    while(i<4):
        i+=1
        if(suits[i-1]==suits[i]):
            c+=1
    if(c==4):
        c = 0
        i = 0
        while(i<4):
            i+=1
            if(cards[i-1]+1==cards[i]):
                c += 1
            else:
                pass
        if(c==4):
            return 12
    else:
        return 0

def checkFoaK(cards):
    i = 0
    while(i<2):
        i+=1
        if(cards[i-1]==cards[i] & cards[i]==cards[i+1]):
            if(cards[i+1]==cards[i+2]):
                return 8
            else:
                return 0
    
def checkFullHouse(cards):
    if(cards[0]==cards[1] & cards[1]==cards[2]):
        if(cards[3]==cards[4]):
            return 7
    elif(cards[0]==cards[1]):
        if(cards[2]==cards[3] & cards[3]==cards[4]):
            return 7

def checkFlush(suits):
    c = 0
    i = 0
    while(i<4):
        i+=1
        if(suits[i-1]==suits[i]):
            c+=1
    if(c==4):
        return 6
    
def checkStraight(cards):
    c = 0
    i = 0
    while(i<4):
        i+=1
        if(cards[i-1]+1==cards[i]):
            c += 1
    if(c==4):
        5
    
def checkToaK(cards):
    i = 0
    while(i<3):
        i+=1
        if(cards[i-1]==cards[i] & cards[i]==cards[i+1]):
            return 4
    
def checkTwoPairs(cards):
    i = 0
    while(i<2):
        i+=1
        if(cards[i-1]==cards[i]):
            if(cards[i+1]==cards[i+2]):
                return 3

def checkPair(cards):
    i = 0
    while(i<=3):
        i+=1
        if(cards[i-1]==cards[i]):
            return 2

def checkHighCard(cards):
    return cards[4]

for numbers in hand:
    if(numbers == ' '):
        pass
    else:
        num = checkValue(numbers)
        suits.append(num)

for suit in suits:
    if(suit != int):
        cards.append(suit)
        suits.remove(suit)

x = slice(0, 5)
suits2 = suits[x]
cards2 = cards[x]
x = slice(5, 10)
suits = suits[x]
cards = cards[x]

suits.sort()
suits2.sort()
cards.sort()
cards2.sort()

if(checkStraightFlush(suits, cards)==checkStraightFlush(suits2, cards2)):
    for card in cards:
        soma = 0
        soma += card
        power.append(soma)
    for card in cards2:
        soma = 0
        soma += card
        power.append(soma)
    if(power[0]>power[1]):
        print('White wins')
    elif(power[0]<power[1]):
        print('Black wins')
    else:
        print('Tie')
elif(checkStraightFlush(suits, cards)!=9 and checkStraightFlush(suits2, cards2)==9):
    print('Black wins')
elif(checkStraightFlush(suits, cards) == 9 and checkStraightFlush(suits2, cards2)!=9):
    print('White wins')
elif(checkFoaK(cards)==checkFoaK(cards2)):
    if(cards[4]>cards2[4]):
        print('White wins')
    elif(cards[4]<cards2[4]):
        print('Black wins')
    else:
        print('Tie')
elif(checkFoaK(cards) != 8 and checkFoaK(cards2) == 8):
    print('Black wins')
elif(checkFoaK(cards) == 8 and checkFoaK(cards2) != 8):
    print('White wins')
