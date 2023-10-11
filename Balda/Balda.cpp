
#include <iostream>
using namespace std;

class Game
{
    string word;
    string lettersleft;
    string guessfield;
    unsigned short tries=6;
public:
    Game() = default;
    void removeLetters(char letter)
    {
        lettersleft.erase(remove(lettersleft.begin(), lettersleft.end(), letter), lettersleft.end());
    }
    void winInfo()
    {
        cout << "You won!!!" << endl;
        cout << "Word: " << word << endl;
        cout << "Tries left: " << tries << endl;
    }
    void checkGuess(string guess)
    {
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
    void startGame(string word)
    {
        this->word = word;
        lettersleft = word;
        for (size_t i = 0; i < word.length(); i++)
        {
            guessfield += "_ ";
        }
        cout << "The Game Has Started!" << endl;
        while (tries > 0 && lettersleft.length() > 0)
        {
            cout << guessfield << endl;
            checkGuess(doGuess());
            if (lettersleft.length() == 0)
                winInfo();
        }
        if (tries == 0)
        {
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

