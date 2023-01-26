function playGuessingGame(numToGuess, totalGuesses=10) {
    guess = 1;
    out = false;
    let input = prompt("Enter a number between 1 and 100.")
    while(guess<totalGuesses) {
        if (input == numToGuess) {
            out = true;
            break;
        }
        else if (input > numToGuess) {
            guess++;
            input = prompt(input +" is too large. Guess a smaller number.")
        }
        else if (input < numToGuess) {
            guess++;
            input = prompt(input+" is too small. Guess a larger number.")
        }
        else if (input || isNaN(input)) {
            input = prompt("Please enter a number.")
        }
        else if (input==Cancel) {
            guess = totalGuesses;
        }
        
    }
    if ((guess == totalGuesses)&&(!out)) {
        guess = 0;
    }
    return guess;
}