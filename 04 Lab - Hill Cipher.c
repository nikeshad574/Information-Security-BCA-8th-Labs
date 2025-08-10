#include <stdio.h>
#include <string.h>
#include <ctype.h>

void hill_encrypt(char text[]) {
    int key_matrix[2][2] = {{9, 4}, {5, 7}};
    char prepared_text[100];
    int prepared_len = 0;
    int i;
    
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            prepared_text[prepared_len++] = tolower(text[i]);
        }
    }

    if (prepared_len % 2 != 0) {
        prepared_text[prepared_len++] = 'x';
    }
    prepared_text[prepared_len] = '\0';
    
    char encrypted_text[100];
    int encrypted_len = 0;

    for (i = 0; i < prepared_len; i += 2) {
        int p1 = prepared_text[i] - 'a';
        int p2 = prepared_text[i+1] - 'a';
        
        int c1 = (key_matrix[0][0] * p1 + key_matrix[0][1] * p2) % 26;
        int c2 = (key_matrix[1][0] * p1 + key_matrix[1][1] * p2) % 26;
        
        encrypted_text[encrypted_len++] = toupper(c1 + 'a');
        encrypted_text[encrypted_len++] = toupper(c2 + 'a');
    }
    encrypted_text[encrypted_len] = '\0';
    
    printf("Plaintext: %s\n", prepared_text);
    printf("Encrypted: %s\n", encrypted_text);
}

int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    hill_encrypt(message);

    return 0;
}
