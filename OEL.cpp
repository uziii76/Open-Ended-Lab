// Cyber Detective (Crypto Game)
// CS110 Lab 08 - Open Ended Lab
// A text based game where the player has to find the hidden encryption rule
// in each mission and then use it to decode (or encode) a secret word.

#include <iostream>
#include <string>
#include <ctime>      // time() and difftime() for the speed bonus
#include <cstdlib>    // rand() and srand()
#include <cctype>     // tolower()

using namespace std;

// ---------- Game rules ----------
// kept as constants so we can change them in one place
const int MAX_TRIES = 3;          // wrong answers allowed in the whole game
const int POINTS_CORRECT = 20;    // points for a correct answer
const int POINTS_PENALTY = 5;     // points lost for a wrong answer or a hint
const int SPEED_BONUS = 10;       // extra points for a fast answer
const int SPEED_LIMIT = 20;       // seconds allowed to get the speed bonus

// ---------- Game modes ----------
const int DECRYPT = 1;
const int ENCRYPT = 2;
const int SURVIVAL = 3;

// ---------- Word lists (one list for each level) ----------
const string EASY[10] = { "harbor", "signal", "cargo", "falcon", "secret",
                         "pirate", "ghost", "agent", "target", "rocket" };
const string MEDIUM[10] = { "server", "hacker", "firewall", "backdoor", "network",
                         "malware", "cipher", "password", "trojan", "database" };
const string HARD[10] = { "informer", "midnight", "sabotage", "conspiracy", "betrayal",
                         "hideout", "disguise", "evidence", "witness", "suspect" };

// ---------- Function prototypes ----------
// menus
void start();
void displayInstructions();

// main game function (used by all three modes)
void runAct(int mode);

// the three ciphers
string shiftEncrypt(string);
string moveEncrypt(string);
string vowelEncrypt(string);
string encryptWord(const string&, int);

// helper functions
int updateScore(int, bool);
string hint(int);
string wordGen(int);
string getRank(int);
string toLower(string s);

int main()
{
    srand(time(0));    // so the random words are different every time
    string option;

    // main menu keeps coming back until the player chooses Exit
    while (true)
    {
        cout << "\n===========================================\n";
        cout << "                Crypto Game                \n";
        cout << "===========================================\n";
        cout << "------------------ MENU -------------------\n";
        cout << "1. Start\n";
        cout << "2. Instructions\n";
        cout << "3. Exit\n";
        cout << "-------------------------------------------\n";
        cout << "Enter your choice: ";

        cin >> option;    // read as a string so a wrong key doesn't break cin

        if (option == "1")
        {
            start();
        }
        else if (option == "2")
        {
            displayInstructions();
        }
        else if (option == "3")
        {
            cout << "Exiting Game...\n";
            break;
        }
        else
        {
            cout << "Invalid input! Please enter 1, 2, or 3.\n";
        }
    }
    return 0;
}

// Menu to choose which act (mode) to play
void start() {
    string choice;

    while(true){
        cout << "\n\n-------------- Choose an Act --------------\n";
        cout << "1. Decryption\n";
        cout << "2. Encryption\n";
        cout << "3. Survival Mode\n";
        cout << "4. Back to Main Menu\n";
        cout << "-------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // all three modes use the same function, only the mode number changes
        if (choice == "1")
        {runAct(DECRYPT);}
        else if (choice == "2")
        {runAct(ENCRYPT);}
        else if (choice == "3")
        {runAct(SURVIVAL);}
        else if (choice == "4")
        {return;}    // just goes back to the main menu loop
        else
        {cout << "Invalid Input!\n";}
    }
}

// Shows the rules of the game
void displayInstructions()
{
    cout << "\n===========================================\n";
    cout << "  CYBER DETECTIVE - CRACK THE HIDDEN RULE\n";
    cout << "===========================================\n";

    cout << "\nGENERAL INSTRUCTIONS\n";
    cout << "\n1. Decryption and Encryption each have three missions.";
    cout << "\n2. Each mission uses a different hidden rule.";
    cout << "\n3. Read the mission description and study the sample.";
    cout << "\n4. Decryption: decode the message. Encryption: encode the word.";
    cout << "\n5. You have " << MAX_TRIES << " tries in total across all missions.";
    cout << "\n6. Correct answers earn " << POINTS_CORRECT << " points.";
    cout << "\n7. Wrong answers lose " << POINTS_PENALTY << " points.";
    cout << "\n8. Type 'hint' for a clue (also costs " << POINTS_PENALTY << " points).";
    cout << "\n9. Solve a mission in under " << SPEED_LIMIT << " seconds for a +"
         << SPEED_BONUS << " speed bonus.";
    cout << "\n10. Survival Mode: random missions until you run out of tries.";

    cout << "\n\nOBJECTIVE:";
    cout << "\nRecover all classified files by identifying hidden";
    cout << "\nencryption patterns.";
    cout << "\n\nRemember: Observe, Investigate, and Crack the Code!\n";
    cout << "===========================================\n";
}

// This is the main part of the game.
// mode = DECRYPT, ENCRYPT or SURVIVAL
void runAct(int mode)
{
    int tries = 0;           // wrong answers so far
    int score = 0;
    int level = 1;           // which file/mission we are on (1 to 3)
    int solved = 0;          // missions solved (used in survival mode)
    int taskMode = mode;     // decode or encode for the current mission

    // welcome message
    if (mode == SURVIVAL)
    {
        cout << "\n===========================================\n";
        cout << "               SURVIVAL MODE               \n";
        cout << "===========================================\n";
        cout << "Random Missions keep coming. " << MAX_TRIES << " tries total. How long can you last?\n";
    }
    else
    {
        cout << "\nWelcome to the Cryptoverse\n";
        cout << "You only have " << MAX_TRIES << " chances for all levels!\n";
    }

    // each time through this loop is one mission
    // stops when tries run out, or after level 3 in the normal modes
    while (tries < MAX_TRIES && (mode == SURVIVAL || level <= 3))
    {
        // ----- show the mission intro -----
        if (mode == SURVIVAL)
        {
            // survival picks a random level and a random direction each round
            level = 1 + rand() % 3;
            taskMode = 1 + rand() % 2;

            cout << "\n--- Round " << solved + 1 << " (cipher of File 00" << level << ") ---\n";

            if (taskMode == DECRYPT)
            {
                cout << "Task: Decode the message.\n";
            }
            else
            {
                cout << "Task: Encode the message.\n";
            }
        }
        else
        {
            // story for each file, with a sample so the player can find the rule
            if (level == 1)
            {
                cout << "\n===========================================\n";
                cout << "  CLASSIFIED FILE 001: OPERATION HARBOR\n";
                cout << "===========================================\n";
                cout << "Dock security has caught a radio message from a smuggling ring.\n";
                cout << "Each letter was nudged by a small amount that changes with its position.\n";
                cout << "Sample from an old intercept:  radio  ->  scgjq\n";
            }
            else if (level == 2)
            {
                cout << "\n===========================================\n";
                cout << "  CLASSIFIED FILE 002: THE DIGITAL HEIST\n";
                cout << "===========================================\n";
                cout << "Someone has breached our servers and left a coded trail.\n";
                cout << "The attacker converted every letter to its ASCII value,\n";
                cout << "then subtracted one fixed number from each.\n";
                cout << "Sample from an old intercept:  key  ->  +%9\n";
            }
            else
            {
                cout << "\n===========================================\n";
                cout << "  CLASSIFIED FILE 003: THE MOLE\n";
                cout << "===========================================\n";
                cout << "Someone inside the agency is leaking secrets.\n";
                cout << "Their messages treat vowels and consonants in opposite ways.\n";
                cout << "Sample from an old intercept:  mole  ->  lpkf\n";
            }
            if (mode == DECRYPT)
            {
                cout << "Your task: find the rule and decode the message.\n";
            }
            else
            {
                cout << "Your task: use the rule to encode the word you are given.\n";
            }

            cout << "Type 'hint' for a clue (costs " << POINTS_PENALTY << " points).\n\n";
        }

        // ----- set up the word for this mission -----
        string original = wordGen(level);               // random word for this level
        string encrypted = encryptWord(original, level);   // its encrypted form
        bool isSolved = false;
        time_t startTime = time(0);    // start the timer for the speed bonus

        // keep asking until the mission is solved or the tries are finished
        while (tries < MAX_TRIES && !isSolved)
        {
            string inp;

            // decryption shows the encrypted word, encryption shows the original
            if (taskMode == DECRYPT)
            {
                cout << "Encrypted message: " << encrypted << "\n";
                cout << "Your answer (original word): ";
            }
            else
            {
                cout << "Original word: " << original << "\n";
                cout << "Your answer (encrypted form): ";
            }

            cin >> inp;
            inp = toLower(inp);    // so capital letters also work

            if (inp == "hint")
            {
                cout << hint(level) << "\n";
                score = updateScore(score, false);    // hint costs points
            }
            else
            {
                bool correct;
                if (taskMode == DECRYPT)
                {
                    // we encrypt the player's answer and compare it with the message
                    // (the vowel cipher can give the same result for different words,
                    // so decrypting and comparing would not always work)
                    correct = (encryptWord(inp, level) == encrypted);
                }
                else
                {
                    correct = (inp == encrypted);
                }

                if (correct)
                {
                    score = updateScore(score, true);
                    int elapsed = (int)difftime(time(0), startTime);    // seconds taken

                    // speed bonus if solved quickly
                    if (elapsed < SPEED_LIMIT)
                    {
                        cout << "SPEED BONUS! Solved in " << elapsed << " seconds. +" << SPEED_BONUS << "\n";
                        score += SPEED_BONUS;
                    }
                    isSolved = true;
                }
                else
                {
                    // wrong answer: lose a try and some points
                    cout << "Failed, try again.\n";
                    tries++;
                    score = updateScore(score, false);
                    if (tries < MAX_TRIES)
                    {
                        cout << "TYPE hint for a clue (costs points)\n";
                    }
                }
            }

            // status line after every answer
            cout << "[ Tries Left : " << MAX_TRIES - tries << "/" << MAX_TRIES << " | Score: " << score << "]\n\n";

            // move on to the next file once this one is solved
            if (isSolved)
            {
                solved++;
                if (mode != SURVIVAL)
                {
                    if (level < 3)
                    {
                        cout << "WELL DONE. PROCEEDING TO NEXT.\n";
                    }
                    level++;
                }
            }
        }
    }

    // ----- final result -----
    if (mode == SURVIVAL)
    {
        cout << "\n============== SURVIVAL OVER ==============\n";
        cout << "Rounds survived: " << solved << "\n";
        cout << "Final Score: " << score << "\n";
        cout << "Rank: " << getRank(score) << "\n";
    }
    else
    {
        cout << "\n============= MISSION REPORT ==============\n";
        if (tries >= MAX_TRIES)
        {
            // the message depends on which file the player failed at
            if (level == 1)
                cout << "MISSION FAILED. The smugglers sailed away with the cargo.\n";
            else if (level == 2)
                cout << "MISSION FAILED. The attacker wiped the trail.\n";
            else
                cout << "MISSION FAILED. The mole escaped and the files were lost.\n";
        }
        else
        {
            cout << "MISSION COMPLETE. The mole is exposed and the files are safe.\n";
        }
        cout << "Final Score: " << score << "\n";
        cout << "Rank: " << getRank(score) << "\n";
    }
}

// Gives a random word from the list of the given level
string wordGen(int level) {
    if (level == 1) return EASY[rand() % 10];
    if (level == 2) return MEDIUM[rand() % 10];
    return HARD[rand() % 10];
}

// Cipher 1: shifts the letters by 1, 2, 3 and then repeats (radio -> scgjq)
string shiftEncrypt(string word) {
    for (int i = 0; i < word.length(); i++) {
        int shift = 1 + (i % 3);    // gives 1, 2, 3, 1, 2, 3 ...
        word[i] = 'a' + (word[i] - 'a' + shift) % 26;    // % 26 wraps around after z
    }
    return word;
}

// Cipher 2: subtracts 64 from the ASCII value of every character (key -> +%9)
string moveEncrypt(string word) {
    for (int i = 0; i < word.length(); i++) {
        word[i] = word[i] - 64;
    }
    return word;
}

// Cipher 3: vowels go 1 letter forward, other letters go 1 letter back (mole -> lpkf)
string vowelEncrypt(string word) {
    for (int i = 0; i < word.length(); i++)
    {
        char c = word[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            word[i] = c + 1;
        }
        else
        {
            word[i] = c - 1;
        }
    }
    return word;
}

// Picks the cipher that belongs to the level
string encryptWord(const string& word, int level)
{
    if (level == 1)
        return shiftEncrypt(word);
    else if (level == 2)
        return moveEncrypt(word);
    else
        return vowelEncrypt(word);
}

// Adds points for a correct answer, takes points away for a wrong one
int updateScore(int current, bool correct) {
    if (correct)
    {
        return current + POINTS_CORRECT;
    }

    current -= POINTS_PENALTY;

    // score should not go below 0
    if (current < 0)
    {
        current = 0;
    }
    return current;
}

// Gives a clue for the cipher of the current level
string hint(int level) {
    if (level == 1) {
        return "Hint: Compare the sample letter by letter. The shift is 1, 2, 3, then repeats.";
    }
    else if (level == 2) {
        return "Hint: Every character moved down by the same amount in the ASCII table.";
    }
    else
    {
        return "Hint: In the sample, vowels moved up one letter and consonants moved down one.";
    }
}

// Gives the rank for a score
string getRank(int s) {
    if (s >= 70) return "Master Cryptanalyst";
    if (s >= 45) return "Field Agent";
    if (s >= 20) return "Rookie Detective";
    else return "Trainee";

}

// Changes a string to lowercase (so "HARBOR" and "harbor" are the same)
string toLower(string s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower((unsigned char)s[i]);
    return s;
}
