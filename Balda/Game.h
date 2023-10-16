#pragma once
#include <fstream>
#include "Timer.h"
#include "Color.h"
using namespace std;
Color color;
class Game
{
    string word;
    string lettersleft;
    string guessfield;
    Time elapsed;
    Timer timer;
    unsigned short tries = 6;
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
        if (tries <= 5)
            color.red("    O", 1);
        else
            cout << endl;
        cout << " | ";
        if (tries == 4)
            color.red("    |", 1);
        else if (tries == 3)
            color.red("   /|", 1);
        else if (tries <= 2)
            color.red("   /|\\", 1);
        else
            cout << endl;
        cout << " | ";
        if (tries == 1)
            color.red("   /", 1);
        else if (tries == 0)
            color.red("   / \\", 1);
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
    string getWord(const char* path)
    {
        string word;
        ifstream in;
        int random = rand() % 190;
        ifstream file(path);
        if (file.is_open()) {
            string s;
            for (int i = 0; i < random; i++)
                file >> word;
            file.close();
            return word;
        }
        else
        {
            cout << "Cannot open file" << endl;
        }
    }
    void startGame(const char* path)
    {
        word = getWord(path);
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