#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <chrono>     
#include <thread>
#include <conio.h>  

using namespace std;

string word_generator_animals() {

    srand(static_cast<unsigned int>(time(0)));
    
    string word_collection[10] = {"anjing", "babi", "rusa", "sapi", "domba", 
                                  "kucing", "kecoa", "semut", "jamur", "burung"};
    
    int arraySize = sizeof(word_collection) / sizeof(word_collection[0]);

    int randomIndex = rand() % arraySize;

    cout << "Press any key to generate a word...\n";
    getch();  

    string randomWord = word_collection[randomIndex];

    cout << "Your word has "; 
    for (int i = 0 ; i < randomWord.length(); i++){
        cout << "_";
    }
    
    cout << " letter";

    return randomWord;
}

string word_generator_sports() {

    srand(static_cast<unsigned int>(time(0)));
    
    string word_collection[10] = {"sepakbola", "bulutangkis", "basket", "renang", "tenis", 
                              "voli", "atletik", "bersepeda", "joging", "kasti"};
    
    int arraySize = sizeof(word_collection) / sizeof(word_collection[0]);

    int randomIndex = rand() % arraySize;

    cout << "Press any key to generate a word...\n";
    getch(); 

    string randomWord = word_collection[randomIndex]; 

    cout << "Your word has "; 
    for (int i = 0 ; i < randomWord.length(); i++){
        cout << "_";
    }
    
    cout << " letter";

    return randomWord;
}

string word_generator_fruits() {

    srand(static_cast<unsigned int>(time(0)));
    
    string word_collection[10] = {"apel", "jeruk", "mangga", "pisang", "durian", 
                              "semangka", "pepaya", "anggur", "nanas", "strawberi"};
    
    int arraySize = sizeof(word_collection) / sizeof(word_collection[0]);

    int randomIndex = rand() % arraySize;

    cout << "Press any key to generate a word...\n";
    getch();  

    string randomWord = word_collection[randomIndex];

    cout << "Your word has "; 
    for (int i = 0 ; i < randomWord.length(); i++){
        cout << "_ ";
    }
    
    cout << " letter";

    return randomWord;
}

void guess_mechanic(string word_to_guess){
    char ready;

    cout << "Do you ready to guess? [Y/N] : ";
    cin >> ready;

    ready = toupper(ready);

    if (ready != 'Y'){
        exit(0);
    }

    cout << "Guess the word! : ";
    
    string guess;
    cin.ignore();
    getline(cin, guess);

    transform(guess.begin(),guess.end(), guess.begin(), ::tolower);

    if (guess == word_to_guess){

        cout << "Congrats you're correctly guess the word right!";
    }else{
        cout << "Try next time! your word is " << word_to_guess;
    }

}

void game_timer(int seconds, string word_to_guess) {

    cout << "\nYou have " << seconds << " seconds to prepare.\n";
    for (int i = seconds; i > 0; i--) {
        cout << "Time left: " << i << " seconds...\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "Time's up! Now it's time to guess!\n";

    guess_mechanic(word_to_guess);
}

int main() {
    string theme;

    cout << "Welcome to WORD GUESSER GAME!\n";
    cout << "Pick a theme [Animals/Fruits/Sports]: ";
    getline(cin, theme);

    transform(theme.begin(), theme.end(), theme.begin(), ::tolower);

    if (theme != "animals" && theme != "fruits" && theme != "sports") {
        cout << "Theme is currently not available!\n";
        exit(0);
    }

    string random_word;
    if (theme == "animals") {
        random_word = word_generator_animals();
    } else if (theme == "fruits") {
        random_word = word_generator_fruits();
    } else {
        random_word = word_generator_sports();
    }

    game_timer(10, random_word);

    return 0;
}



