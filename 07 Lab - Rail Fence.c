#include <stdio.h>
#include <string.h>
#include <ctype.h>

void rail_fence_encrypt(const char* text, int num_rails) {
    int text_len = strlen(text);
    char rail[num_rails][text_len];
    int i, j, row = 0, dir = 1;
    
    for (i = 0; i < num_rails; i++) {
        for (j = 0; j < text_len; j++) {
            rail[i][j] = '\n';
        }
    }

    for (i = 0; i < text_len; i++) {
        if (row == 0) {
            dir = 1;
        }
        if (row == num_rails - 1) {
            dir = -1;
        }
        rail[row][i] = text[i];
        row += dir;
    }

    char encrypted_text[text_len + 1];
    int k = 0;

    for (i = 0; i < num_rails; i++) {
        for (j = 0; j < text_len; j++) {
            if (rail[i][j] != '\n') {
                encrypted_text[k++] = rail[i][j];
            }
        }
    }
    encrypted_text[k] = '\0';
    
    printf("Original message: %s\n", text);
    printf("Encrypted message: %s\n", encrypted_text);
}

int main() {
    char message[256];
    int num_rails;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
    
    printf("Enter the number of rails: ");
    scanf("%d", &num_rails);

    if (num_rails <= 1) {
        printf("Number of rails must be greater than 1.\n");
        return 1;
    }

    rail_fence_encrypt(message, num_rails);

    return 0;
}
