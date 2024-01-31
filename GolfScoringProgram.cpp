#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Function to get player's name
string getPlayerName(int playerNumber) {
    string playerName;
    cout << "Enter the name of Player " << playerNumber << ": ";
    cin >> playerName;
    return playerName;
}

// Function to simulate a single shot distance randomly
int simulateShot() {
    // Generate a random distance between 5 to 200 yards
    return rand() % 196 + 5;
}

// Function to categorize the shot result
string categorizeResult(int distance) {
    if (distance <= 10) {
        return "Gimme";
    } else if (distance >= 200) {
        return "Hole in one";
    } else if (distance >= 180) {
        return "Eagle";
    } else if (distance >= 150) {
        return "Birdie";
    } else if (distance >= 135) {
        return "Par";
    } else if (distance >= 100) {
        return "Bogey";
    } else {
        return "Double Bogey";
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    cout << "Scoring in Golf:" << endl;
    cout << "In golf, the objective is to complete each hole in as few strokes as possible." << endl;
    cout << "The score for each hole is based on the number of strokes taken to get the ball into the hole." << endl;
    cout << "There are different terms used for various scores on each hole:" << endl;
    cout << "- Hole in one: When the ball is holed with the first stroke." << endl;
    cout << "- Eagle: Two strokes under par on a hole." << endl;
    cout << "- Birdie: One stroke under par on a hole." << endl;
    cout << "- Par: The expected number of strokes to complete a hole, typically determined by the hole's length and difficulty." << endl;
    cout << "- Bogey: One stroke over par on a hole." << endl;
    cout << "- Double Bogey: Two strokes over par on a hole." << endl;
    cout << "The total score for a round of golf is the sum of the scores for each hole." << endl;

    int numPlayers;
    cout << "\nEnter the number of players: ";
    cin >> numPlayers;

    // Get player names
    vector<string> playerNames(numPlayers);
    vector<int> totalScores(numPlayers, 0);
    int numHoles;

    for (int i = 0; i < numPlayers; ++i) {
        playerNames[i] = getPlayerName(i + 1);
    }

    cout << "Enter the number of holes to play: ";
    cin >> numHoles;

    // Loop through each hole
    for (int hole = 1; hole <= numHoles; ++hole) {
        cout << "\nHole #" << hole << endl;

        // Loop through each player
        for (int player = 0; player < numPlayers; ++player) {
            cout << "\nPlayer: " << playerNames[player] << endl;

            // Ask for club selection (not used for shot generation)
            int clubNumber;
            cout << "Select club (1: Driver/Wood, 2: Iron, 3: Wedge, 4: Putter): ";
            cin >> clubNumber;

            // Simulate shot distance
            int distance = simulateShot();
            cout << "Distance: " << distance << " yards" << endl;

            // Categorize result
            string result = categorizeResult(distance);
            cout << "Result: " << result << endl;

            // Update total score for the player
            if (result != "Gimme") {
                totalScores[player] += distance;
            }
        }

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Press Enter to continue to the next hole or enter 'x' to exit...";
        char choice;
        cin.get(choice);

        if (choice == 'x' || choice == 'X') {
            break;
        }
    }

    // Display final results
    cout << "\nGolf round completed!\n";
    cout << "Final Scores:\n";
    for (int i = 0; i < numPlayers; ++i) {
        cout << playerNames[i] << ": " << totalScores[i] << " yards" << endl;
    }

    return 0;
}
