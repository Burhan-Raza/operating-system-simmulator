#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
# include <fstream>

int main() {
 int process_choice = 16, terminate_signal = 1, yet_to_read = 1; 
    char terminate = 'n';
    while (terminate != 'y') {
    // Set up the list of words to choose from
    std::vector<std::string> words {"apple", "banana", "cherry", "orange", "kiwi", "pear"};

    // Seed the random number generator
    srand(time(nullptr));

    // Choose a random word from the list
    std::string word = words[rand() % words.size()];

    // Set up the game variables
    const int max_attempts = 3; // Number of incorrect guesses allowed
    int attempts = 0; // Number of incorrect guesses so far
    std::string guessed_letters; // String containing all letters guessed so far
    std::string hidden_word(word.size(), '_'); // String containing the hidden word

    // Play the game until the player wins or loses
    while (attempts < max_attempts && hidden_word != word) {
        // Display the current state of the game
        std::cout << "Guess the word: " << hidden_word << std::endl;
        std::cout << "Attempts remaining: " << max_attempts - attempts << std::endl;
        std::cout << "Guessed letters: " << guessed_letters << std::endl;

        // Get a letter guess from the player
        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;

        // Check if the letter has already been guessed
        if (guessed_letters.find(guess) != std::string::npos) {
            std::cout << "You already guessed that letter." << std::endl;
            continue;
        }

        // Add the letter to the list of guessed letters
        guessed_letters += guess;

        // Check if the letter is in the word
        bool found = false;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == guess) {
                hidden_word[i] = guess;
                found = true;
            }
        }

        // If the letter is not in the word, increment the attempts counter
        if (!found) {
            std::cout << "Incorrect guess." << std::endl;
            ++attempts;
        }
    }

    // Display the final state of the game
    if (hidden_word == word) {
        std::cout << "Congratulations! You guessed the word: " << word << std::endl;
    } else {
        std::cout << "Sorry, you ran out of attempts. The word was: " << word << std::endl;
    }
    
    std::cout << "Want to terminate the program? Press y if yes, or any other key to continue." << std::endl;
    std::cin >> terminate;
    }
   
    std::ofstream outfile("IPC.txt");
    char a = ',';
    // Write two integer values to the file
    outfile << yet_to_read << a << terminate_signal << a << process_choice << std::endl;
    // Close the file
    outfile.close();

    return 0;
}

