# Crypto Game

A text-based detective game for the console, written in C++. Recover three classified files by working out the hidden encryption rule behind each message, and earn the rank of **Master Cryptanalyst**.

## Features

- Three missions, each with its own story and its own hidden cipher
- Three game modes: **Decryption**, **Encryption** and **Survival**
- Points, a speed bonus, a hint system and four ranks
- Random words every game, so no two runs are the same

## Getting started

**Requirements:** a C++ compiler with C++11 support (g++, Visual Studio, Code::Blocks, etc.). No external libraries are needed.

**Build and run with g++:**

```bash
g++ -std=c++11 -o crypto_game OEL.cpp
./crypto_game            # on Windows: crypto_game.exe
```

**Or use an IDE:** create a console project, add `OEL.cpp`, then build and run.

## How to play

### Menus

Type the number of your choice and press Enter.

```
MAIN MENU
 1. Start ──► Choose an Act:  1. Decryption   2. Encryption
                              3. Survival Mode   4. Back to Main Menu
 2. Instructions
 3. Exit
```

### Game modes

| Mode | What you do |
|---|---|
| **Decryption** | Read the story, study the sample, then decode the encrypted message shown. Type the original word. |
| **Encryption** | Same sample, but you are given the original word. Type its encrypted form. |
| **Survival** | Random missions keep coming (any file, either direction) until you run out of tries. See how many rounds you survive. |

In Decryption and Encryption you play through **three classified files in order**. Each file uses a different hidden rule that you must discover from the story text and the sample.

### Rules

| Rule | Value |
|---|---|
| Tries | **3 in total** across the whole run |
| Correct answer | **+20** points |
| Wrong answer | **-5** points and one try lost |
| Hint (type `hint`) | **-5** points, no try lost |
| Speed bonus | **+10** if you solve a mission in **under 20 seconds** |
| Score range | 0 to 90 (the score never goes below 0) |

### Ranks

| Score | Rank |
|---|---|
| 70 or more | Master Cryptanalyst |
| 45 to 69 | Field Agent |
| 20 to 44 | Rookie Detective |
| Below 20 | Trainee |

### Tips

- Type **one word** per answer, with no spaces. Answers are not case-sensitive.
- Compare the sample **letter by letter** to spot the rule.
- Stuck? Type `hint`. It costs fewer points than losing a try.
- Answer quickly for the speed bonus.

## Group Members and Contribution

| Name | Contribution |
|---|---|
| **Muhammad Mustafa Asim** |  **Code and README.md** |
| **Uzair Hassan Farooq** | **Code** |
| **Muhammad Daud** | **Report** |
