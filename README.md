# CS2600_Cipher
Final Project for CS 2600 based on ciphers
# Cipher Encryption Program
**C Programming — Group Project**

---

## Purpose

This program lets you **encrypt and decrypt text** using four classical ciphers:

| # | Cipher | Key Required |
|---|--------|-------------|
| 1 | Caesar | A number (shift amount, e.g. `3`) |
| 2 | Vigenere | A word (e.g. `KEY`) |
| 3 | Atbash | None |
| 4 | Rail Fence | A number (rails, e.g. `3`) |

It is designed as an educational tool to demonstrate how classical substitution and transposition ciphers work.

---

## Requirements

- A C compiler: **gcc** (Linux/macOS) or **MinGW** (Windows)
- No external libraries — only the C standard library is used

---

## How to Compile

Open a terminal in the folder containing `ciphers.c` and run:

```bash
gcc ciphers.c -o ciphers
```

On Windows with MinGW:

```bash
gcc ciphers.c -o ciphers.exe
```

---

## How to Run

```bash
./ciphers
```

On Windows:

```bash
ciphers.exe
```

---

## How to Use

1. **Select a cipher** — type a number from 1 to 4 and press Enter.
2. **Select an action** — type `1` to Encrypt or `2` to Decrypt.
3. **Enter your text** — type the message you want to process.
4. **Enter a key** (if required) — follow the on-screen prompt.
5. **View the result** — it is printed immediately below your input.
6. **Run again or quit** — type `1` to go again or `2` to exit.

---

## Example Session

```
Select a cipher [1-4]: 1
Select action [1-2]: 1
Enter your text: Hello World
Enter shift key (1-25): 3

RESULT: Khoor Zruog
```

To decrypt, choose the same cipher, select Decrypt, and use the same key:

```
Select a cipher [1-4]: 1
Select action [1-2]: 2
Enter your text: Khoor Zruog
Enter shift key (1-25): 3

RESULT: Hello World
```

---

## Cipher Quick Reference

### Caesar
Shifts every letter by a fixed number. `A` with key `3` → `D`.  
Decrypt with the same number.

### Vigenere
Uses a keyword where each letter provides the shift.  
`HELLO` with key `KEY` → `RIJVS`.  
Decrypt with the same keyword.

### Atbash
Mirrors the alphabet: `A`↔`Z`, `B`↔`Y`, etc.  
Encrypt and Decrypt are identical — run it twice to get back the original.

### Rail Fence
Writes the text in a zigzag across rows, then reads row by row.  
`HELLOWORLD` with 3 rails → `HOLELWRDLO` (approximately).  
Decrypt with the same number of rails.

---

## Project Files

```
groupproject.c     ← main source code
cipher_report.docx ← group project report
README.md          ← this file
```

---

## Group Members

| Member | Contribution |
|--------|-------------|
| Member 1 | Caesar Cipher |
| Member 2 | Vigenere Cipher |
| Member 3 | Atbash + Rail Fence |
| Member 4 | Main menu, input validation, integration |

> 

