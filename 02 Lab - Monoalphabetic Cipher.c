#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoalphabetic_encrypt(char text[], const char key[]) {
    char standard_alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < strlen(text); i++) {
        if (islower(text[i])) {
            int index = text[i] - 'a';
            if (index >= 0 && index < 26) {
                text[i] = key[index];
            }
        } else if (isupper(text[i])) {
            int index = text[i] - 'A';
            if (index >= 0 && index < 26) {
                text[i] = toupper(key[index]);
            }
        }
    }
}

int main() {
    char message[100];
    const char* key = "qwertyuiopasdfghjklzxcvbnm";

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    printf("Original message: %s\n", message);

    monoalphabetic_encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
