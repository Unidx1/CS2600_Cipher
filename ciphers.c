#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ============================================================
   CIPHER PROGRAM — 4 ciphers: Caesar, Vigenere, Atbash, Rail Fence
   Each cipher has an encrypt and decrypt function.
   ============================================================ */


/* ─────────────────────────────────────────────
   1. CAESAR CIPHER
   Shifts every letter by a fixed number (key).
   Example: 'A' with key 3 → 'D'
   ───────────────────────────────────────────── */

void caesar_encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }
}

void caesar_decrypt(char *text, int key) {
    caesar_encrypt(text, 26 - (key % 26));  /* Shift in reverse */
}


/* ─────────────────────────────────────────────
   2. VIGENÈRE CIPHER
   Uses a keyword. Each letter is shifted by the
   corresponding letter in the keyword.
   Example: text="HELLO", key="KEY"
     H + K(10) = R
     E + E(4)  = I
     L + Y(24) = J  ... and so on (keyword repeats)
   ───────────────────────────────────────────── */

void vigenere_encrypt(char *text, char *key) {
    int key_len = strlen(key);
    int j = 0;  /* tracks position in keyword */

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % key_len]) - 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }
}

void vigenere_decrypt(char *text, char *key) {
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % key_len]) - 'A';
            text[i] = (text[i] - base - shift + 26) % 26 + base;
            j++;
        }
    }
}


/* ─────────────────────────────────────────────
   3. ATBASH CIPHER
   Mirrors the alphabet: A↔Z, B↔Y, C↔X ...
   No key needed. Encryption = Decryption (same function).
   ───────────────────────────────────────────── */

void atbash(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            text[i] = 'Z' - (text[i] - 'A');
        } else if (islower(text[i])) {
            text[i] = 'z' - (text[i] - 'a');
        }
    }
}
/* atbash_decrypt is the same as atbash_encrypt */


/* ─────────────────────────────────────────────
   4. RAIL FENCE CIPHER
   Writes text in a zigzag pattern across 'rails' (rows),
   then reads row by row.
   Example: "HELLOWORLD" with 3 rails:
     Rail 0: H . . . O . . . L .
     Rail 1: . E . L . W . R . D
     Rail 2: . . L . . . O . . .
   Encrypted: HOLOLWRDELD  (read each rail top to bottom)
   ───────────────────────────────────────────── */

void rail_fence_encrypt(char *text, int rails) {
    int len = strlen(text);
    char fence[rails][len];
    memset(fence, '\0', sizeof(fence));

    int rail = 0, direction = 1;

    for (int i = 0; i < len; i++) {
        fence[rail][i] = text[i];
        if (rail == 0) direction = 1;
        if (rail == rails - 1) direction = -1;
        rail += direction;
    }

    int idx = 0;
    for (int r = 0; r < rails; r++) {
        for (int c = 0; c < len; c++) {
            if (fence[r][c] != '\0') {
                text[idx++] = fence[r][c];
            }
        }
    }
}

void rail_fence_decrypt(char *text, int rails) {
    int len = strlen(text);
    char fence[rails][len];
    memset(fence, '\0', sizeof(fence));

    /* Step 1: Mark where each character goes (using '*') */
    int rail = 0, direction = 1;
    for (int i = 0; i < len; i++) {
        fence[rail][i] = '*';
        if (rail == 0) direction = 1;
        if (rail == rails - 1) direction = -1;
        rail += direction;
    }

    /* Step 2: Fill in actual characters row by row */
    int idx = 0;
    for (int r = 0; r < rails; r++) {
        for (int c = 0; c < len; c++) {
            if (fence[r][c] == '*') {
                fence[r][c] = text[idx++];
            }
        }
    }

    /* Step 3: Read back in zigzag order */
    rail = 0; direction = 1;
    for (int i = 0; i < len; i++) {
        text[i] = fence[rail][i];
        if (rail == 0) direction = 1;
        if (rail == rails - 1) direction = -1;
        rail += direction;
    }
}


/* ─────────────────────────────────────────────
   MAIN — Menu-driven interface
   ───────────────────────────────────────────── */

int main() {
    int cipher_choice, action_choice;
    char text[256];
    char key_str[64];
    int key_int;

    printf("╔══════════════════════════════════════╗\n");
    printf("║        CIPHER PROGRAM                ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    printf("Choose a cipher:\n");
    printf("  1. Caesar Cipher\n");
    printf("  2. Vigenère Cipher\n");
    printf("  3. Atbash Cipher\n");
    printf("  4. Rail Fence Cipher\n");
    printf("Enter choice: ");
    scanf("%d", &cipher_choice);
    getchar(); /* clear newline */

    printf("\nEncrypt or Decrypt?\n");
    printf("  1. Encrypt\n");
    printf("  2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &action_choice);
    getchar();

    printf("\nEnter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; /* remove trailing newline */

    switch (cipher_choice) {

        case 1: /* Caesar */
            printf("Enter shift key (number): ");
            scanf("%d", &key_int);
            if (action_choice == 1)
                caesar_encrypt(text, key_int);
            else
                caesar_decrypt(text, key_int);
            break;

        case 2: /* Vigenère */
            printf("Enter keyword (letters only): ");
            scanf("%s", key_str);
            if (action_choice == 1)
                vigenere_encrypt(text, key_str);
            else
                vigenere_decrypt(text, key_str);
            break;

        case 3: /* Atbash — no key needed */
            atbash(text); /* same for encrypt and decrypt */
            break;

        case 4: /* Rail Fence */
            printf("Enter number of rails: ");
            scanf("%d", &key_int);
            if (key_int < 2) {
                printf("Rails must be at least 2.\n");
                return 1;
            }
            if (action_choice == 1)
                rail_fence_encrypt(text, key_int);
            else
                rail_fence_decrypt(text, key_int);
            break;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("\nResult: %s\n", text);
    return 0;
}
