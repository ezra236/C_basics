#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <conio.h> // Required for _getch()

using namespace std;

string getHiddenPassword();

class Ezra {
private:
    string adminpass = "123";

public:
    int i;

    Ezra() : i(0) {}

    bool isNumber(const string& str) const {
        std::istringstream iss(str);
        double d;
        char c;

        if (!(iss >> d) || iss.get(c)) {
            return false;
        }
        return true;
    }

    bool validate(string& pass) {
        int attempts = 0;
        bool isCorrect = false;

        while (attempts < 3) {
            if (pass == adminpass) {
                isCorrect = true;
                break; // Exit the loop if the password is correct
            } else {
                cout << "Incorrect password!" << endl;
                attempts++;
                if (attempts < 3) {
                    cout << "You have " << 3 - attempts << " attempts left.\nEnter the password again: ";
                    pass = getHiddenPassword();
                } else {
                    cout << "Maximum attempts reached. Exiting." << endl;
                    exit(0);
                }
            }
        }
        return isCorrect;
    }

    void Quest(int i) {
        string str = to_string(i);
        if ((!isNumber(str)) || (i > 5) || (i < 1)) {
            std::cout << "The input is not a valid number or out of range (1-5)." << std::endl;
            exit(0);  // Exit the program if the input is invalid
        } else {
            cout << "The Question:" << std::endl;
        }

        switch (i) {
        case 1:
            cout << "What is the capital of France?\n a) London\n b) Berlin\n c) Paris\n d) Madrid" << endl;
            break;
        case 2:
            cout << "What is the largest planet in our solar system?\n a) Earth\n b) Jupiter\n c) Mars\n d) Venus" << endl;
            break;
        case 3:
            cout << "Who wrote \"Romeo and Juliet\"?\n a) William Shakespeare\n b) Mark Twain\n c) Charles Dickens\n d) Jane Austen" << endl;
            break;
        case 4:
            cout << "What is the chemical symbol for gold?\n a) Au\n b) Ag\n c) Fe\n d) Pb" << endl;
            break;
        case 5:
            cout << "Which element has the atomic number 1?\n a) Helium\n b) Oxygen\n c) Hydrogen\n d) Carbon" << endl;
            break;
        default:
            cout << "Quiz over!" << endl;
            break;
        }
    }
};

class David : public Ezra {
public:
    string m;
    int i;
    int score = 0;

    David(string answ, int num) : Ezra() {
        m = answ;
        i = num;
    }

    void Answer(char m) {
        char lowerM = tolower(m);

        switch (i) {
        case 1:
            if (lowerM == 'c') {
                cout << "Answer is: Paris" << endl;
                score++;
            } else {
                cout << "Incorrect!" << endl;
            }
            break;
        case 2:
            if (lowerM == 'b') {
                cout << "Answer is: Jupiter" << endl;                
                score++;
            } else {
                cout << "Incorrect!" << endl;
            }
            break;
        case 3:
            if (lowerM == 'a') {
                cout << "Answer is: William Shakespeare" << endl;
                score++;
            } else {
                cout << "Incorrect!" << endl;
            }
            break;
        case 4:
            if (lowerM == 'a') {
                cout << "Answer is: Au" << endl;
                score++;
            } else {
                cout << "Incorrect!" << endl;
            }
            break;
        case 5:
            if (lowerM == 'c') {
                cout << "Answer is: Hydrogen" << endl;
                score++;
            } else {
                cout << "Incorrect!" << endl;
            }
            break;
        default:
            cout << "Invalid question number!" << endl;
            break;
        }
    }

    int calculateScore() {
        return score;
    }
};

string getHiddenPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') { // Read until Enter is pressed
        if (ch == '\b') { // Handle backspace
            if (!password.empty()) {
                cout << "\b \b"; // Move cursor back, erase character, move cursor back again
                password.pop_back(); // Remove last character from the password
            }
        } else {
            cout << '*'; // Print * instead of the actual character
            password += ch; // Add character to the password
        }
    }
    cout << endl; // New line after password entry
    return password;
}

int main() {
    Ezra instance;
    int que;
    char an;
    string password;

    cout << "Welcome to the Quiz App" << endl;
    cout << "Enter the password: " << endl;
    password = getHiddenPassword();

    if (!instance.validate(password)) {
        return 0; 
    }

    David instance1("placeholder", 0); // Initialize with dummy values
    
    for (int u = 1; u <= 5; u++) {
        cout << "Question " << u << ":" << endl;
        instance.Quest(u);

        instance1.i = u; // Set the question number in instance1

        cout << "Enter your Answer (a, b, c, d): ";
        cin >> an;
        cin.ignore();

        instance1.Answer(an);
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    }

    int finalScore = instance1.calculateScore();
    cout << "Your final score is: " << finalScore << " out of 5." << endl;

    return 0;
}
