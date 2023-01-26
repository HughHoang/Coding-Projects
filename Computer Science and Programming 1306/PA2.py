import random

def numberToName(number):
    result=""
    if number==1:
        result="rock"
    elif number==2:
        result="paper"
    elif number==3:
        result="scissors"
    return result
        
def rockPaperScissors():
    number = int(input())
    print("Player 1 Chooses ", numberToName(number))
    number2 = random.randint(1, 3)
    print("Player 2 Chooses ", numberToName(number2))
    if number == number2:
        return ("T")
    elif number == 1:
        if number2 == 2:
            return ("L")
        else:
            return ("W")
    elif number == 2:
        if number2 == 3:
            return ("L")
        else:
            return ("W")
    elif number == 3:
        if number2 == 1:
            return ("L")
        else:
            return ("W")

def countLetters(word, char):
    return word.count(char)


if __name__ == '__main__': 
  userInput = 0

  while userInput != -1:
    print("\nPlease select one of the menu options")
    print(" 1. Start game of rock, paper, scissors")
    print("-1. to exit the program.")

    userInput = input()
    if (userInput == '1'):
        print('\nStarting Game... Input 1 for rock, 2 for paper or 3 for scissor.\n')
        matchHistory = ""
        while (True):
            result1 = rockPaperScissors()
            matchHistory+=result1
            if result1=="W":
                print("Player 1 Wins")
            elif result1=="L":
                print("Player 2 Wins")
            elif result1=="T":
                print("Player 1 and Player 2 Ties")
            if countLetters(matchHistory, "W") == 2:
                    print("Player 1 wins the best 2 out of 3")
                    break
            if countLetters(matchHistory, "L") == 2:
                    print("Player 2 wins the best 2 out of 3")
                    break



    elif(userInput == '-1'):
        break