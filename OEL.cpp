#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string shift();
string shiftde(string inp);
bool validate(string);
int score(int, bool);
void menu(int option);
void displayInstructions();

void Start();
string move();
string movede(string);
bool validatemove(string);
string vowel();
string vowelde(string);
bool validatevowel(string);
string hint(int);
string wordGen();
int main()
{
    int option;
    cout << "Crypto Game" << endl;
    cout << "---------MENU---------" << endl;
    cout << "1. Start" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Exit" << endl;
    cin >> option;
    while (option != 3) {
        menu(option);
        cout << "---------MENU---------" << endl;
        cout << "1. Start" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl;
        cin >> option;

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
    bool b;
    cout << "Welcome to the Cryptoverse" << endl;
    cout << "CLASSIFIED FILE 001" << endl;
    cout << "You have intercepted a suspicious message. Intelligence suggests that each letter has been shifted according to a hidden pattern." << endl;
    cout << "You only have 3 chances for all levels!" << endl;
    while (tries < 3) {
        cout << "Encrypted Message: " << shift() << endl;
        cout << "Try to Decrypt Message: ";
        cin >> inp;
        b = validate(inp);
        if (validate(inp)) {
            cout << "WEllDONE. PROCEEDING TO NEXT." << endl;
            sco = score(sco, b);
            cout << "Score: " << sco << endl;
            break;

        }
        else if (inp == "hint") {
            cout << hint(1);
        }
        else {
            cout << "Failed , Try again." << endl;
            tries++;
            cout << "You have " << 3 - tries << " tries left!" << endl;
            if (tries < 3) {
                cout << "TYPE hint for a clue(but will result in negative scoring)" << endl;
                sco -= 5;
            }

        }
        sco = score(sco, b);
        cout << "Score: " << sco << endl;
    }
    while (tries < 3) {
        cout << "CLASSIFIED FILE 002" << endl;
        cout << "An intercepted message appears to have been transformed using ASCII character values. Investigators believe that a fixed numerical value has been subtracted from each character. Identify the hidden transformation and decode the message." << endl;
        cout << "Encrypted Message: " << move() << endl;
        cout << "Try to Decrypt Message: ";
        cin >> inp1;
        b = validatemove(inp1);
        if (validatemove(inp1)) {
            cout << "WEllDONE. PROCEEDING TO NEXT." << endl;
            sco = score(sco, b);
            cout << "Score: " << sco << endl;
            break;

        }
        else if (inp1 == "hint") {
            cout << hint(2);
        }
        else {
            cout << "Failed , Try again." << endl;
            tries++;
            if (tries < 3) {
                cout << "TYPE hint for a clue(but will result in negative scoring)" << endl;
                sco -= 5;
            }
        }
        sco = score(sco, b);
        cout << "Score: " << sco << endl;
    }
    while (tries < 3) {
        cout << "CLASSIFIED FILE 003" << endl;
        cout << "An intercepted message appears to have been altered using a special rule that treats vowels and consonants differently. Investigators must identify the hidden pattern and decode the message to recover the original text." << endl;
        cout << "Encrypted Message: " << vowel() << endl;
        cout << "Try to Decrypt Message: ";
        cin >> inp2;
        b = validatevowel(inp2);
        if (validatevowel(inp2)) {
            cout << "WEllDONE. PROCEEDING TO NEXT." << endl;
            sco = score(sco, b);
            cout << "Score: " << sco << endl;
            break;

        }
        else if (inp2 == "hint") {
            cout << hint(3);
        }
        else {
            cout << "Failed , Try again." << endl;
            tries++;
            if (tries < 3) {
                cout << "TYPE hint for a clue(but will result in negative scoring)" << endl;
                sco -= 5;
            }
        }
        sco = score(sco, b);
        cout << "Score: " << sco << endl;
    }



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
    cout << "\n6. You have three attempts per mission.";
    cout << "\n7. Correct answers earn points.";
    cout << "\n8. Incorrect answers result in point deductions.";
    cout << "\n9. You can request hints, but points will be deducted.";
    cout << "\n10. Complete all missions to achieve the highest ranking.";

    cout << "\n\nOBJECTIVE:";
    cout << "\nRecover all classified files by identifying hidden";
    cout << "\nencryption patterns and decoding the messages.";

    cout << "\n\nRemember: Observe, Investigate, and Crack the Code!";

    cout << "\n========================================\n";
}
string wordGen() {
    srand(time(0));
    string words[5] = { "hello", "bye", "cyaaaa", "aaaa", "teacher" };
    string random = words[rand() % 5];
    return random;
}
string shift() {
    string random = wordGen();
    int shift[3] = { 1,2,3 };
    for (int i = 0; i < random.length(); i++) {
        random[i] = random[i] + shift[i % 3];
    }
    return random;
}

string shiftde(string inp) {

    int shift[3] = { 1,2,3 };
    for (int i = 0; i < inp.length(); i++) {
        inp[i] = inp[i] + shift[i % 3]; //igomq
    }
    return inp;
}

bool validate(string inp) {
    if (shiftde(inp) == shift()) {

        return true;
    }
    else {
        return false;
    }
}
string move() {
    string word = wordGen();
    for (int i = 0; i < word.length(); i++) {
        word[i] = word[i] - 64;
    }
    return word;
}

string movede(string inp) {

    for (int i = 0; i < inp.length(); i++) {
        inp[i] = inp[i] - 64; //igomq
    }
    return inp;
}

bool validatemove(string inp1) {
    if (movede(inp1) == move()) {

        return true;
    }
    else {
        return false;
    }
}
string vowel() {
    string word = "hello";
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

string vowelde(string inp) {

    for (int i = 0; i < inp.length(); i++) {
        if (inp[i] == 'a' || inp[i] == 'e' || inp[i] == 'i' || inp[i] == 'o' || inp[i] == 'u') {
            inp[i] = inp[i] + 1;
        }
        else {
            inp[i] = inp[i] - 1;
        }
    }
    return inp;
}

bool validatevowel(string inp1) {
    if (movede(inp1) == move()) {

        return true;
    }
    else {
        return false;
    }
}
int score(int score, bool a) {
    if (a) {
        score += 20;
    }
    else {
        score -= 5;
    }
    return score;
}
string hint(int stage) {
    if (stage == 1) {
        return "Hint: Pay attention to the ASCII values of characters.";
    }
    else if (stage == 2)
    {
        return "Hint: Look at how vowels and consonants are transformed.";
    }
    else if (stage == 3)
    {
        return "Hint: Observe how letters are rearranged in pairs.";
    }
    else
    {
        return 0;
    }
}
