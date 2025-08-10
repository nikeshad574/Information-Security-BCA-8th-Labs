#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void otp_encrypt(char text[], const char key[]) {
    int text_len = strlen(text);

    for (int i = 0; i < text_len; i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            char key_char = tolower(key[i]);
            
            int plaintext_num, key_num;
            if (isupper(current_char)) {
                plaintext_num = current_char - 'A';
                key_num = key_char - 'a';
                int result = (plaintext_num ^ key_num) % 25;
                text[i] = result + 'A';
            } else {
                plaintext_num = current_char - 'a';
                key_num = key_char - 'a';
                int result = (plaintext_num ^ key_num) % 25;
                text[i] = result + 'a';
            }
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
    
    int message_len = strlen(message);
    srand(time(NULL));

    for (int i = 0; i < message_len; i++) {
        key[i] = 'a' + (rand() % 26);
    }
    key[message_len] = '\0';

    printf("Original message: %s\n", message);
    printf("Generated key: %s\n", key);

    otp_encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
