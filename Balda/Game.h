#pragma once
#include <fstream>
#include "Timer.h"
#include "Color.h"
#include <iostream>
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
            cout << "Incorrect guess" << endl;
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
        printHangman();
        color.blue("You've won!", 1);
        cout << "Word: " << word << endl;
        cout << "Tries left: " << tries << endl;
        cout << "Time elapsed: ";
        elapsed.display();

    }
    void loseInfo()
    {
        elapsed = timer.stop();
        printHangman();
        color.red("You've lost", 1);
        cout << "The word was: " << word << endl;
        cout << "Time elapsed: ";
        elapsed.display();
    }
    string getWord(const char* path)
    {
        string word;
        ifstream in;
        int random = 1+ rand() % 198;
        ifstream file(path);
        if (file.is_open()) {
            string s;
            for (int i = 0; i < random; i++)
                file >> word;
            file.close();
            return word;
        }
        else
            cout << "Cannot open file" << endl;
    }
    void startGame(const char* path)
    {
        word = getWord(path);
        timer.start();
        lettersleft = word;
        for (size_t i = 0; i < word.length(); i++)
        {
            guessfield += "_ ";
        }
        cout << "The Game Has Started!" << endl << endl;
        while (tries > 0 && lettersleft.length() > 0)
        {
            printHangman();
            for (size_t i = 0; i < guessfield.length(); i++)
            {
                if(guessfield[i]!=' ' && guessfield[i] != '_')
                    printf("\033[1;32m");
                cout << guessfield[i];
                printf("\033[0m");
            }
            cout << endl;
            checkGuess(doGuess());
            if (lettersleft.length() == 0)
                winInfo();
        }
        if (tries == 0)
            loseInfo();
    }
};