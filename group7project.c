/*
Project: Multi-Cipher Encryption/Decryption Tool
Course: 2600.01
Group Members: David Lisberg, Justin Lee, Paul Nguyen, Swe Zin Myat, Taylor Szendzial
Date: April 19, 2026
Progress: Caeser Cipher implemented so far.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 1024

void clearBuffer();
void caeserCipher(char* text, int shift, int encrypt);
void atbashCipher(char* text);
void vigenereCipher(char* text, char* key, int encrypt);
void qwertyShiftCipher(char* text, int shift, int encrypt);

// Main Menu
int main() {
    int choice;
    int mode;
    char text[MAX_TEXT];
    int shift;
    char key[MAX_TEXT];

    while (1) {
        printf("\n========================================\n");
        printf("   MULTI-CIPHER ENCRYPTION PROGRAM\n");
        printf("========================================\n");
        printf("1. Caesar Cipher\n");
        printf("2. Atbash Cipher (Work in Progress)\n");
        printf("3. Vigenere Cipher (Work in Progress)\n");
        printf("4. QWERTY Shift Cipher (Work in Progress)\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearBuffer();

        if (choice == 5) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Please select a valid option from the menu.\n");
            continue;
        }

        if (choice != 2) {
            printf("Choose Mode - (1) Encrypt or (2) Decrypt: ");
            scanf("%d", &mode);
            clearBuffer();
            if (mode != 1 && mode != 2) {
                printf("Invalid Mode selected. Returning to menu.\n");
                continue;
            }
        }

        printf("Enter the text: ");
        fgets(text, MAX_TEXT, stdin);
        text[strcspn(text, "\n")] = 0;

        switch(choice) {
            case 1:
                printf("Enter shift amount (can be negative): ");
                scanf("%d", &shift);
                clearBuffer();
                caeserCipher(text, shift, mode == 1);
                printf("\nResult: %s\n", text);
                break;
            case 2:
                //WIP for Atbash
                break;
            case 3:
                //WIP for Vigenere
                break;
            case 4:
                //WIP for QWERTY
                break;
        }
    }
    return 0;
}

// Helper Functions
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// Cipher Implementations

/*
Caeser Cipher: Shifts letters by a given key.
- Handles both positive and negative shifts, k, and warps around the alphabet. 
*/

void caeserCipher(char* text, int shift, int encrypt) {
    if(!encrypt) {
        shift = -shift;
    }

    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        } else if (islower(text[i])) {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

void atbashCipher(char* text) {}
void vigenereCipher(char* text, char* key, int encrypt) {}
void qwertyShiftCipher(char* text, int shift, int encrypt) {}