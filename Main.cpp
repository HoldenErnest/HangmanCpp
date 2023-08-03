// Holden Ernest - 8/2/23
// A simple hangman game built in cpp

#include <cstring>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

const int allWordsLen = 110;
const string allWords[] = {
    "cheese",   "labor",       "fill",        "sound",     "pair",
    "fun",      "fight",       "ago",         "sets",      "online",
    "frighten", "these",       "share",       "correct",   "electric",
    "complete", "plenty",      "character",   "negative",  "author",
    "income",   "former",      "saved",       "typical",   "buried",
    "family",   "widely",      "having",      "stream",    "lungs",
    "progress", "explanation", "let",         "customs",   "suddenly",
    "finally",  "old",         "again",       "pipe",      "does",
    "hunt",     "why",         "glass",       "kill",      "aid",
    "swept",    "mood",        "heard",       "interior",  "everywhere",
    "grade",    "appearance",  "excitement",  "addition",  "scientist",
    "solve",    "rhyme",       "above",       "tie",       "addition",
    "anywhere", "shoulder",    "hole",        "will",      "inside",
    "farmer",   "fighting",    "electricity", "till",      "up",
    "leg",      "obtain",      "wheat",       "neighbor",  "inside",
    "else",     "crew",        "empty",       "slight",    "numeral",
    "pen",      "tonight",     "dress",       "blue",      "call",
    "thick",    "mind",        "brush",       "bent",      "education",
    "rubber",   "attempt",     "song",        "principal", "function",
    "steady",   "impossible",  "final",       "represent", "history",
    "elephant", "long",        "sight",       "smallest",  "saw",
    "pack",     "definition",  "kids",        "similar",   "slipped"};

const int numLetters = 26;
const int totalAttempts = 8; // up this number if youre bad

string secretWord;  // the secret word!
string guessedWord; // what the user currently has guessed
char guesses[numLetters];
int attemptNum = 0;

bool takeGuess(string guess) { // returns if you win
  if (secretWord == guess)
    return true;
  attemptNum++;
  return false;
}
void takeGuess(char guess) {
  for (int i = 0; i < attemptNum; i++) { // you already guessed that letter
    if (guesses[i] == guess) {
      cout << "You already guessed that letter" << endl;
      return;
    }
  }
  for (int i = 0; i < secretWord.length(); i++) {
    // fill in the correct characters
    if (guess == secretWord[i]) { // the guess was correct
      guessedWord[i] = guess;
    }
  }
  guesses[attemptNum] = guess; // record the guess
  attemptNum++;
}
void printGuessed() { // print all your guessed letters
  cout << endl << "Letters used: ";
  for (int i = 0; i < attemptNum; i++) {
    cout << guesses[i] << " ";
  }
  cout << endl << "Word: ";
  for (int i = 0; i < guessedWord.length(); i++) {
    cout << ((guessedWord[i] == ' ') ? '_' : guessedWord[i]) << " ";
  }
  cout << endl;
}
string getRandomWord() { // generate a random word based off 'allWords'
  int random = rand() % allWordsLen;
  return allWords[random];
}
void setupWords() { // setup for the game(the secret word needs to be set)
  secretWord = getRandomWord();
  guessedWord = secretWord;
  for (int i = 0; i < secretWord.length(); i++) {
    guessedWord[i] = ' ';
  }
}
int main() {
  srand(time(NULL));
  bool playAgain = true;
  while (playAgain) {
    setupWords();

    string theGuess;
    for (attemptNum = 0; attemptNum < totalAttempts;) {
      // take your guesses
      printGuessed();
      cout << "[" << attemptNum + 1 << "/" << totalAttempts
           << "]Enter your guess: ";
      cin >> theGuess;
      if (theGuess.length() == 1) // if you guess a single char
        takeGuess(theGuess.c_str()[0]);
      else if (takeGuess(theGuess)) {
        cout << "Nice! You win! The word was: \"" << secretWord << "\"" << endl;
        break;
      }
    }
    if (attemptNum == totalAttempts) {
      printGuessed();
      cout << endl
           << "You lost, the word was \"" << secretWord
           << "\". Maybe next time." << endl;
    }

    cout << endl << "Do you want to play agian?(y/n) ";
    char tt;
    cin >> tt;
    playAgain = tt == 'y';
  }
  cout << "Goodbye" << endl;
}
