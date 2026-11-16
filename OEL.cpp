#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

string shiftEncrypt(string);
string shiftDecrypt(string inp);
bool validateShift(string, string);
int score(int, bool);
void menu(int option);
void displayInstructions();

void Start();
string moveEncrypt(string);
string moveDecrypt(string);
bool validateMove(string, string);
string vowelEncrypt(string);
string vowelDecrypt(string);
bool validateVowel(string, string);
string hint(int);
string wordGen(int);
string getRank(int);
int timeBonus(time_t startTime);
string toLower(string s);

int main()
{
    srand(time(0));
    string option;
    while (true)
    {
        cout << "\n       Crypto Game" << endl;
        cout << "---------MENU---------" << endl;
        cout << "1. Start" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> option;

        if (option == "1")
        {
            menu(1);
        }
        else if (option == "2")
        {
            menu(2);
        }
        else if (option == "3")
        {
            cout << "Exiting Game..." << endl;
            break;
        }
        else
        {
            cout << "Invalid input! Please enter 1, 2, or 3." << endl;
        }
    }



    return 0;
}
void menu(int option) {
    switch (option) {
    case 1:
        Start();
        break;
    case 2:
        displayInstructions();
        break;
    default:
        cout << "Invalid Input" << endl;

    }
}
void Start() {

    int tries = 0;
    string inp, inp1, inp2;
    int sco = 0;
    time_t start;

    string original = wordGen(1);
    string encrypted = shiftEncrypt(original);
    cout << "Welcome to the Cryptoverse" << endl;
    cout << "You only have 3 chances for all levels!" << endl;
    if (tries < 3) {
        cout << "CLASSIFIED FILE 001: OPERATION HARBOR" << endl;
        cout << "Dock security has caught a radio message from a smuggling ring." << endl;
        cout << "Each letter was nudged by a small amount that changes with its position." << endl;
        cout << "Decode it before the ship leaves port." << endl;
        cout << "Sample from an old intercept:  radio  ->  scgjq" << endl;
    }
    start = time(0);
    while (tries < 3) {
        cout << "Encrypted Message: " << encrypted << endl;
        cout << "Try to Decrypt Message: ";
        cin >> inp;
        inp = toLower(inp);

        if (inp == "hint") {
            cout << hint(1) << endl;
            sco = score(sco, false);                        // hint penalty
        }
        else if (validateShift(inp, original)) {
            cout << "WELL DONE. PROCEEDING TO NEXT." << endl;
            sco = score(sco, true);
            sco += timeBonus(start);
            cout << "Score: " << sco << endl;
            break;
        }
        else {
            cout << "Failed, try again." << endl;
            tries++;
            sco = score(sco, false);
            cout << "You have " << 3 - tries << " tries left!" << endl;
            if (tries < 3)
                cout << "TYPE hint for a clue (costs points)" << endl;
        }
        cout << "Score: " << sco << endl;
    }
    string original1 = wordGen(2);
    string encrypted1 = moveEncrypt(original1);
    if (tries < 3) {
        cout << "CLASSIFIED FILE 002: THE DIGITAL HEIST" << endl;
        cout << "Someone has breached our servers and left a coded trail." << endl;
        cout << "The attacker converted every letter to its ASCII value," << endl;
        cout << "then subtracted one fixed number from each." << endl;
        cout << "Find the number. Recover the word." << endl;
        cout << "Sample from an old intercept:  key  ->  +%9" << endl;
    }
    start = time(0);
    while (tries < 3) {
        cout << "Encrypted Message: " << encrypted1 << endl;
        cout << "Try to Decrypt Message: ";
        cin >> inp1;
        inp1 = toLower(inp1);
        if (inp1 == "hint") {
            cout << hint(2) << endl;
            sco = score(sco, false);                        // hint penalty
        }
        else if (validateMove(inp1, original1)) {
            cout << "WELL DONE. PROCEEDING TO NEXT." << endl;
            sco = score(sco, true);
            sco += timeBonus(start);
            cout << "Score: " << sco << endl;
            break;
        }
        else {
            cout << "Failed, try again." << endl;
            tries++;
            sco = score(sco, false);
            cout << "You have " << 3 - tries << " tries left!" << endl;
            if (tries < 3)
                cout << "TYPE hint for a clue (costs points)" << endl;
        }
        cout << "Score: " << sco << endl;
    }
    string original2 = wordGen(3);
    string encrypted2 = vowelEncrypt(original2);
    if (tries < 3) {
        cout << "CLASSIFIED FILE 003: THE MOLE" << endl;
        cout << "Someone inside the agency is leaking secrets." << endl;
        cout << "Their messages treat vowels and consonants in opposite ways." << endl;
        cout << "Expose the pattern and name the traitor's word." << endl;
        cout << "Sample from an old intercept:  mole  ->  lpkf" << endl;
    }
    start = time(0);
    while (tries < 3) {

        cout << "Encrypted Message: " << encrypted2 << endl;
        cout << "Try to Decrypt Message: ";
        cin >> inp2;
        inp2 = toLower(inp2);
        if (inp2 == "hint") {
            cout << hint(3) << endl;
            sco = score(sco, false);                        // hint penalty
        }
        else if (validateVowel(inp2, original2)) {
            cout << "WELL DONE. PROCEEDING TO NEXT." << endl;
            sco = score(sco, true);
            sco += timeBonus(start);
            cout << "Score: " << sco << endl;
            break;
        }
        else {
            cout << "Failed, try again." << endl;
            tries++;
            sco = score(sco, false);
            cout << "You have " << 3 - tries << " tries left!" << endl;
            if (tries < 3)
                cout << "TYPE hint for a clue (costs points)" << endl;
        }
        cout << "Score: " << sco << endl;
    }
    cout << "\n========== MISSION REPORT ==========" << endl;
    if (tries >= 3)
        cout << "MISSION FAILED. The mole escaped and the files were lost." << endl;
    else
        cout << "MISSION COMPLETE. The mole is exposed and the files are safe." << endl;
    cout << "Final Score: " << sco << endl;
    cout << "Rank: " << getRank(sco) << endl;



}
void displayInstructions()
{
    cout << "\n========================================\n";
    cout << "       CYBER DETECTIVE\n";
    cout << "       CRACK THE HIDDEN RULE\n";
    cout << "========================================\n";

    cout << "\nGENERAL INSTRUCTIONS\n";

    cout << "\n1. The game consists of three missions.";
    cout << "\n2. Each mission uses a different encryption technique.";
    cout << "\n3. Read the mission description carefully.";
    cout << "\n4. Identify the hidden encryption pattern.";
    cout << "\n5. Decode the encrypted message.";
    cout << "\n6. You have three attempts in total across all missions.";
    cout << "\n7. Correct answers earn points.";
    cout << "\n8. Incorrect answers result in point deductions.";
    cout << "\n9. You can request hints, but points will be deducted.";
    cout << "\n10. Complete all missions to achieve the highest ranking.";
    cout << "\n11. Solve a mission in under 20 seconds for a +10 speed bonus.";

    cout << "\n\nOBJECTIVE:";
    cout << "\nRecover all classified files by identifying hidden";
    cout << "\nencryption patterns and decoding the messages.";

    cout << "\n\nRemember: Observe, Investigate, and Crack the Code!";

    cout << "\n========================================\n";
}
string wordGen(int level) {
    string easy[10] = { "harbor", "signal", "cargo", "falcon", "secret",
                         "pirate", "ghost", "agent", "target", "rocket" };
    string medium[10] = { "server", "hacker", "firewall", "backdoor", "network",
                         "malware", "cipher", "password", "trojan", "database" };
    string hard[10] = { "informer", "midnight", "sabotage", "conspiracy", "betrayal",
                         "hideout", "disguise", "evidence", "witness", "suspect" };

    if (level == 1) return easy[rand() % 10];
    if (level == 2) return medium[rand() % 10];
    return hard[rand() % 10];
}
string shiftEncrypt(string random) {
    int shiftEncrypt[3] = { 1,2,3 };
    for (int i = 0; i < random.length(); i++) {
        random[i] = random[i] + shiftEncrypt[i % 3];
    }
    return random;
}

string shiftDecrypt(string inp) {

    int shift[3] = { 1,2,3 };
    for (int i = 0; i < inp.length(); i++) {
        inp[i] = inp[i] - shift[i % 3]; //igomq
    }
    return inp;
}

bool validateShift(string inp, string original) {
    return inp == original;
}
string moveEncrypt(string word) {
    for (int i = 0; i < word.length(); i++) {
        word[i] = word[i] - 64;
    }
    return word;
}

string moveDecrypt(string inp) {
    for (int i = 0; i < inp.length(); i++) {
        inp[i] = inp[i] + 64; //igomq
    }
    return inp;
}

bool validateMove(string inp, string original) {
    return original == inp;
}
string vowelEncrypt(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            word[i] = word[i] + 1;
        }
        else {
            word[i] = word[i] - 1;
        }
    }

    return word;
}

string vowelDecrypt(string inp) {
    for (int i = 0; i < inp.length(); i++) {
        if (inp[i] == 'a' || inp[i] == 'e' || inp[i] == 'i' || inp[i] == 'o' || inp[i] == 'u') {
            inp[i] = inp[i] - 1;
        }
        else {
            inp[i] = inp[i] + 1;
        }
    }
    return inp;
}

bool validateVowel(string inp, string original) {
    return original == inp;
}
int score(int score, bool a) {
    if (a) {
        score += 20;
    }
    else {
        score -= 5;
        if (score < 0) {
            score = 0;
        }
    }
    return score;
}
string hint(int stage) {
    if (stage == 1) {
        return "Hint: Compare the sample letter by letter. The shift is 1, 2, 3, then repeats.";
    }
    else if (stage == 2) {
        return "Hint: Every character moved down by the same amount in the ASCII table.";
    }
    else if (stage == 3) {
        return "Hint: In the sample, vowels moved up one letter and consonants moved down one.";
    }
    else
        return "";
}
string getRank(int s) {
    if (s >= 70) return "Master Cryptanalyst";
    if (s >= 45) return "Field Agent";
    if (s >= 20) return "Rookie Detective";
    else return "Trainee";

}
int timeBonus(time_t startTime) {
    double elapsed = difftime(time(0), startTime);
    if (elapsed < 20) {
        cout << "SPEED BONUS! Solved in " << (int)elapsed << " seconds. +10" << endl;
        return 10;
    }
    return 0;
}
string toLower(string s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}