#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

const int MAX_TRIES = 3;
const int POINTS_CORRECT = 20;
const int POINTS_PENALTY = 5;
const int SPEED_BONUS = 10;
const int SPEED_LIMIT = 20;

const int DECRYPT = 1;
const int ENCRYPT = 2;
const int SURVIVAL = 3;

const string EASY[10] = { "harbor", "signal", "cargo", "falcon", "secret",
                         "pirate", "ghost", "agent", "target", "rocket" };
const string MEDIUM[10] = { "server", "hacker", "firewall", "backdoor", "network",
                         "malware", "cipher", "password", "trojan", "database" };
const string HARD[10] = { "informer", "midnight", "sabotage", "conspiracy", "betrayal",
                         "hideout", "disguise", "evidence", "witness", "suspect" };

void start();
void displayInstructions();

void runAct(int mode);

string shiftEncrypt(string);
string moveEncrypt(string);
string vowelEncrypt(string);
string encryptWord(const string&, int);

int updateScore(int, bool);
string hint(int);
string wordGen(int);
string getRank(int);
string toLower(string s);

int main()
{
    srand(time(0));
    string option;

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

        cin >> option;

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

        if (choice == "1")
        {runAct(DECRYPT);}
        else if (choice == "2")
        {runAct(ENCRYPT);}
        else if (choice == "3")
        {runAct(SURVIVAL);}
        else if (choice == "4")
        {return;}
        else 
        {cout << "Invalid Input!\n";}
    }
}
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
void runAct(int mode)
{
    int tries = 0;
    int score = 0;
    int level = 1;
    int solved = 0;
    int taskMode = mode;
    
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

    while (tries < MAX_TRIES && (mode == SURVIVAL || level <= 3))
    {
        if (mode == SURVIVAL)
        {
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

        string original = wordGen(level);
        string encrypted = encryptWord(original, level);
        bool isSolved = false;
        time_t startTime = time(0);

        while (tries < MAX_TRIES && !isSolved)
        {
            string inp;

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
            inp = toLower(inp);

            if (inp == "hint")
            {
                cout << hint(level) << "\n";
                score = updateScore(score, false);
            }
            else
            {
                bool correct;
                if (taskMode == DECRYPT)
                {
                    correct = (encryptWord(inp, level) == encrypted); 
                }
                else
                {
                    correct = (inp == encrypted);
                }

                if (correct)
                {
                    score = updateScore(score, true);
                    int elapsed = (int)difftime(time(0), startTime);

                    if (elapsed < SPEED_LIMIT)
                    {
                        cout << "SPEED BONUS! Solved in " << elapsed << " seconds. +" << SPEED_BONUS << "\n";
                        score += SPEED_BONUS;
                    }
                    isSolved = true;
                }
                else
                {
                    cout << "Failed, try again.\n";
                    tries++;
                    score = updateScore(score, false);
                    if (tries < MAX_TRIES)
                    {
                        cout << "TYPE hint for a clue (costs points)\n";
                    }
                }
            }

            cout << "[ Tries Left : " << MAX_TRIES - tries << "/" << MAX_TRIES << " | Score: " << score << "]\n\n";

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
string wordGen(int level) {
    if (level == 1) return EASY[rand() % 10];
    if (level == 2) return MEDIUM[rand() % 10];
    return HARD[rand() % 10];
}
string shiftEncrypt(string word) {
    for (int i = 0; i < word.length(); i++) {
        int shift = 1 + (i % 3);
        word[i] = 'a' + (word[i] - 'a' + shift) % 26;
    }
    return word;
}
string moveEncrypt(string word) {
    for (int i = 0; i < word.length(); i++) {
        word[i] = word[i] - 64;
    }
    return word;
}
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
string encryptWord(const string& word, int level)
{
    if (level == 1)
        return shiftEncrypt(word);
    else if (level == 2)
        return moveEncrypt(word);
    else
        return vowelEncrypt(word);
}
int updateScore(int current, bool correct) {
    if (correct) 
    {
        return current + POINTS_CORRECT;
    }

    current -= POINTS_PENALTY;

    if (current < 0)
    {
        current = 0;
    }
    return current;
}
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
string getRank(int s) {
    if (s >= 70) return "Master Cryptanalyst";
    if (s >= 45) return "Field Agent";
    if (s >= 20) return "Rookie Detective";
    else return "Trainee";

}
string toLower(string s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower((unsigned char)s[i]);
    return s;
}