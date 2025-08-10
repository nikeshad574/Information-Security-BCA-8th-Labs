#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesar_encrypt(char text[], int key) {
    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i])) {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        } else if (islower(text[i])) {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
    }
}

int main() {
    char message[100];
    int shift_key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
    
    printf("Enter the shift key: ");
    scanf("%d", &shift_key);

    printf("Original message: %s\n", message);

    caesar_encrypt(message, shift_key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
