#include <iostream>
#include <random>
#include <cctype>  //to make things uppercase :)

using namespace std;

int main() {

    // my variables
    char userChoice;
    char gameChoice;
    int tieCounter = 0;
    int winCounter = 0;
    int loseCounter = 0;
    int gameCounter = 0;

    //CHAT GPT CODE
    // Create a random number generator
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 eng(rd());  // Seed the generator
    std::uniform_int_distribution<> distr(0, 2);  // Define the range (0 to 2)

    // Define the characters
    char choices[] = {'R', 'P', 'S'};

    cout << "Do you want to play rock, paper, or scissors?" << endl;
    cout << "Type (Y/N): ";
    cin >> gameChoice;
    gameChoice = toupper(gameChoice); // making it uppercase for easier input validation

    //input validation
    char gameChoiceValidation;
    while (gameChoice != 'Y' &&  gameChoice != 'N') {
        cout << "That was not valid input, try again" << endl;
        cout << "Type (Y/N): ";
        cin >> gameChoiceValidation;
        gameChoice = toupper(gameChoiceValidation);  // making it uppercase for easier input validation
    }

    cout << "-----------------------------" << endl;
    cout << endl;

    while (gameChoice == 'Y') {
        // Generate a random index and choose the corresponding character
        char computer = choices[distr(eng)];
        // cout << "COMPUTER " << computer << endl;

        // MY CODE
        cout << "Do you choose rock, paper, or scissors? " << endl;
        cout << "Type 'R', 'P', or 'S': ";
        cin >> userChoice;
        userChoice = toupper(userChoice); // making it uppercase for easier input validation

        char userChoiceValidation;
        //input validation
        while (userChoice != 'R' &&  userChoice != 'P' && userChoice != 'S') {
            cout << "That was not valid input, try again" << endl;
            cout << "Type 'R', 'P', or 'S': ";
            cin >> userChoiceValidation;
            userChoice = toupper(userChoiceValidation); // making it uppercase for easier input validation
        }

        cout << endl;
        cout << "You chose: " << userChoice << endl;
        cout << "The computer chose: " << computer << endl;
        cout << "-----------------------------" << endl;
        cout << endl;

        if (userChoice == 'R' && computer == 'R'){
            cout << "tie" << endl;
            tieCounter++;
        }
        else if (userChoice == 'R' && computer == 'P') {
            cout << "loser" << endl;
            loseCounter++;
        }
        else if (userChoice == 'R' && computer == 'S') {
            cout << "winner" << endl;
            winCounter++;
        }
        else if (userChoice == 'P' && computer == 'P') {
            cout << "tie" << endl;
            tieCounter++;
        }
        else if (userChoice == 'P' && computer == 'R') {
            cout << "winner" << endl;
            winCounter++;
        }
        else if (userChoice == 'P' && computer == 'S') {
            cout << "loser" << endl;
            loseCounter++;
        }
        else if (userChoice == 'S' && computer == 'S') {
            cout << "tie" << endl;
            tieCounter++;
        }
        else if (userChoice == 'S' && computer == 'R') {
            cout << "lose" << endl;
            loseCounter++;
        }
        else if (userChoice == 'S' && computer == 'P') {
            cout << "winner" << endl;
            winCounter++;
        }
        gameCounter++;

        char inGameChoice;

        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "Do you want to play again?" << endl;
        cout << "Type (Y/N): ";
        cin >> inGameChoice;
        inGameChoice = toupper(inGameChoice); // making it uppercase for easier input validation

        //input validation
        char inGameValidation;
        while (inGameChoice != 'Y' &&  inGameChoice != 'N') {
            cout << "That was not valid input, try again" << endl;
            cout << "Type (Y/N): ";
            cin >> inGameValidation;
            inGameChoice = toupper(inGameValidation);  // making it uppercase for easier input validation
        }
        cout << "-----------------------------" << endl;
        cout << endl;
        gameChoice = inGameChoice;
    }

    cout << "Game Stats: " << endl;
    cout << "-----------------------------" << endl;
    cout << "You played " << gameCounter << " time(s)!" << endl;
    cout << "You won " << winCounter << " time(s)!" << endl;
    if (winCounter > loseCounter)
        cout << "You're amazing! You won!" << endl;
    else if (winCounter < loseCounter)
        cout << "You suck! The computer won." << endl;
    else if (winCounter == loseCounter)
        cout << "TIE" << endl;


    return 0;
}
