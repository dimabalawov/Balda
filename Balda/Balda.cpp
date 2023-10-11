
#include <iostream>
#include "Timer.h"
using namespace std;

class Game
{
    string word;
    string lettersleft;
    string guessfield;
    Time elapsed;
    Timer timer;
    unsigned short tries=6;
public:
    Game() = default;
    void removeLetters(char letter)
    {
        lettersleft.erase(remove(lettersleft.begin(), lettersleft.end(), letter), lettersleft.end());
    }
    void printHangman()
    {
        cout << " ._____." << endl;
        cout << " | " << "    |" << endl;
        cout << " | ";
        if (tries <=5)
            cout << "    O" << endl;
        else
            cout << endl;
        cout << " | ";
        if (tries == 4)
            cout << "    |" << endl;
        else if(tries==3)
            cout << "   /|" << endl;
        else if(tries<=2)
            cout << "   /|\\" << endl;
        else
            cout << endl;
        cout << " | ";
        if (tries == 1)
            cout << "   /" << endl;
        else if(tries==0)
            cout << "   / \\" << endl;
        else
            cout << endl;
        cout << "_|_" << endl << endl;
    }
    void checkGuess(string guess)
    {
        system("cls");
        char letter;
        if (guess.length() == 1)
        {
            letter = guess[0];
            if (lettersleft.find(letter) != string::npos)
            {
                cout << "The guess was right" << endl;
                removeLetters(letter);
                for (size_t i = 0; i < word.length(); i++)
                {
                    if (letter == word[i])
                        guessfield[i * 2] = word[i];
                }
            }
            else
            {
                cout << "The guess was wrong" << endl;
                tries--;
            }
        }
        else if (guess.length() == word.length())
        {
            if (guess == word)
                lettersleft.clear();
            else
            {
                cout << "The guess was wrong" << endl;
                tries--;
            }
        }
        else
        {
            cout << "Incorrect guess" << endl;
        }
    }
    string doGuess()
    {
        string l;
        cout << "Do your guess: ";
        cin >> l;
        return l;
    }
    void winInfo()
    {
        elapsed = timer.stop();
        cout << "You won!!!" << endl;
        printHangman();
        cout << "Word: " << word << endl;
        cout << "Tries left: " << tries << endl;
        cout << "Time elapsed: ";
        elapsed.display();

    }
    void startGame(string word)
    {
        timer.start();
        this->word = word;
        lettersleft = word;
        for (size_t i = 0; i < word.length(); i++)
        {
            guessfield += "_ ";
        }
        cout << "The Game Has Started!" << endl << endl;
        while (tries > 0 && lettersleft.length() > 0)
        {
            printHangman();
            cout << guessfield << endl;
            checkGuess(doGuess());
            if (lettersleft.length() == 0)
                winInfo();
        }
        if (tries == 0)
        {
            elapsed = timer.stop();
            printHangman();
            cout << "You've lost" << endl;
            cout << "The word was: " << word << endl;
        }
    }
};

int main()
{
    string word = "jhinn";
    Game a;
    a.startGame(word);

}

