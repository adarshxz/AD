#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct Score {
    string name;
    int attempts;
};

int getHighScore() {
    ifstream file("highscore.txt");
    if (file.is_open()) {
        int score;
        file >> score;
        file.close();
        return score;
    }
    return 999;
}

void updateHighScore(int attempts, const string& name) {
    int current = getHighScore();
    if (attempts < current) {
        ofstream file("highscore.txt");
        file << attempts;
        file.close();
        cout << "New high score! " << name << ": " << attempts << " attempts." << endl;
    }
}

int getValidGuess() {
    int guess;
    while (!(cin >> guess) || guess < 1 || guess > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter 1-100: ";
    }
    return guess;
}

void playSingle(int maxAttempts) {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess, attempts = 0;
    string name;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Guess the number (1-100, " << maxAttempts << " max attempts):" << endl;

    while (attempts < maxAttempts) {
        guess = getValidGuess();
        attempts++;

        if (guess > secret) cout << "Too high!" << endl;
        else if (guess < secret) cout << "Too low!" << endl;
        else {
            cout << "Correct! " << name << " got it in " << attempts << " attempts." << endl;
            updateHighScore(attempts, name);
            return;
        }
    }
    cout << "Out of attempts! Secret was " << secret << "." << endl;
}

void playMulti() {
    string p1, p2;
    int secret, guess, maxAttempts = 7;
    cout << "Player 1 name: "; cin >> p1;
    cout << "Player 2 name: "; cin >> p2;
    cout << p1 << ", enter secret (1-100): ";
    secret = getValidGuess();
    cout << p2 << ", guess (" << maxAttempts << " max):" << endl;
    int attempts = 0;
    while (attempts < maxAttempts) {
        guess = getValidGuess();
        attempts++;
        if (guess > secret) cout << "Too high!" << endl;
        else if (guess < secret) cout << "Too low!" << endl;
        else {
            cout << p2 << " wins in " << attempts << " attempts!" << endl;
            return;
        }
    }
    cout << p1 << " wins! Secret was " << secret << "." << endl;
}

int main() {
    int choice;
    cout << "Number Guessing Game (High score: " << getHighScore() << ")" << endl;
    cout << "1. Single (Easy:10, Med:7, Hard:5)" << endl;
    cout << "2. Multiplayer" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;

    if (choice == 1) {
        int diff;
        cout << "Difficulty (1=Easy,2=Med,3=Hard): ";
        cin >> diff;
        int maxA = (diff == 1) ? 10 : (diff == 2) ? 7 : 5;
        playSingle(maxA);
    } else if (choice == 2) {
        playMulti();
    }
    return 0;
}