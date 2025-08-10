#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(char text[], const char key[]) {
    int key_len = strlen(key);
    int key_index = 0;

    for (int i = 0; i < strlen(text); i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            char key_char = tolower(key[key_index % key_len]);
            int shift = key_char - 'a';

            if (isupper(current_char)) {
                current_char = ((current_char - 'A' + shift) % 26) + 'A';
            } else {
                current_char = ((current_char - 'a' + shift) % 26) + 'a';
            }
            text[i] = current_char;
            key_index++;
        }
    }
}

int main() {
    char message[256];
    char key[256];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
    
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    if (key[strlen(key) - 1] == '\n') {
        key[strlen(key) - 1] = '\0';
    }

    vigenere_encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
