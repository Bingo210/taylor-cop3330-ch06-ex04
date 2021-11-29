/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Noah Taylor
 */

// Chapter 6 exercise 4

#include <iostream>
#include <vector>
using namespace std;

// Function declaration
void getNameAndScore();
void showNameAndScore();

// Creates a class of data type Name_value
class Name_value {
public:

    // Defines class attributes
    string name;
    int score;
};

// Defines vector of data type Name_value to hold names and scores
vector<Name_value> NameAndScore;

// Main function
int main()
{
    // Prints program's purpose and instructions
    cout << "This program takes in a name - score combination, checks for redundancies, and lists them.\n";
    cout << "Input a name and a score. To terminate input enter 'NoName' as the name and '0' as the score.\n";
    cout << "=============================================================================================\n";

    // Calls function to handle user input
    getNameAndScore();

    // Calls function to print list of names and scores
    showNameAndScore();

    // Hides directory information from console
    system("pause>0");
}

// Function to handle user input
void getNameAndScore() {

    // Defines variable of type Name_value to hold the int and string, and a flag to mark input termination
    Name_value input;
    int flag = 0, errorFlag = 0;

    // While loop repeats as long as flag isn't tripped
    while (flag == 0) {

        // Asks user for the name and score, stores input
        cout << "\nName: ";
        cin >> input.name;
        cout << "Score: ";
        cin >> input.score;

        // If the error flag is tripped, previous vector element is removed
        // Flag is then reset to prevent accidental future element deletion
        if (errorFlag == 1) {
            NameAndScore.pop_back();
            errorFlag = 0;
        }

        // When user enters NoName 0, flag is tripped and while loop is broken
        if (input.name == "NoName" && input.score == 0)
            flag = 1;

        // Loop traverses length of NameAndScore vector
        for (int i = 0; i < NameAndScore.size(); i++) {

            // If user's name input matches the name at any index of the NameAndScore vector,
            // an error is shown and the error flag is tripped
            while (NameAndScore[i].name == input.name) {
                cout << "\nERROR: Name already exists. Please re-name.\n";
                errorFlag = 1;
                break;
            }
        }

        // User's name (string) and score (int) are placed in the vector
        NameAndScore.push_back(input);
    }
}

// Function listing the names and scores
void showNameAndScore() {

    cout << "\n\n";

    // Traverses length of NameAndScore vector, writes out all of the names and scores
    for (int i = 0; i < NameAndScore.size() - 1; i++) {
        cout << "\t" << NameAndScore[i].name << "\t" << NameAndScore[i].score << endl;
    }
}