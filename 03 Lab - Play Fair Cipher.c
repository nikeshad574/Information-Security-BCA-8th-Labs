#include <stdio.h>
#include <string.h>
#include <ctype.h>

void create_key_matrix(const char key[], char matrix[5][5]) {
    char alphabet[] = "abcdefghiklmnopqrstuvwxyz";
    int used[26] = {0};
    int key_len = strlen(key);
    int k = 0;
    int i, j;

    for (i = 0; i < key_len; i++) {
        char c = tolower(key[i]);
        if (c == 'j') c = 'i';
        if (isalpha(c) && !used[c - 'a']) {
            matrix[k / 5][k % 5] = c;
            used[c - 'a'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (c == 'j') continue;
        if (!used[i]) {
            matrix[k / 5][k % 5] = c;
            k++;
        }
    }
}

void find_position(char matrix[5][5], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt_digraph(char matrix[5][5], char a, char b, char *result_a, char *result_b) {
    int r1, c1, r2, c2;
    find_position(matrix, tolower(a), &r1, &c1);
    find_position(matrix, tolower(b), &r2, &c2);

    if (r1 == r2) {
        *result_a = matrix[r1][(c1 + 1) % 5];
        *result_b = matrix[r2][(c2 + 1) % 5];
    } else if (c1 == c2) {
        *result_a = matrix[(r1 + 1) % 5][c1];
        *result_b = matrix[(r2 + 1) % 5][c2];
    } else {
        *result_a = matrix[r1][c2];
        *result_b = matrix[r2][c1];
    }
}

void playfair_encrypt(char text[], const char key[]) {
    char matrix[5][5];
    char prepared_text[200];
    int prepared_len = 0;
    int i;
    
    create_key_matrix(key, matrix);

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            prepared_text[prepared_len++] = tolower(text[i]);
        }
    }

    for (i = 0; i < prepared_len; i += 2) {
        if (i + 1 < prepared_len && prepared_text[i] == prepared_text[i + 1]) {
            for (int j = prepared_len; j > i + 1; j--) {
                prepared_text[j] = prepared_text[j - 1];
            }
            prepared_text[i + 1] = 'x';
            prepared_len++;
        }
    }
    
    if (prepared_len % 2 != 0) {
        prepared_text[prepared_len++] = 'x';
    }
    prepared_text[prepared_len] = '\0';
    
    char encrypted_text[200];
    int encrypted_len = 0;

    for (i = 0; i < prepared_len; i += 2) {
        char a, b;
        encrypt_digraph(matrix, prepared_text[i], prepared_text[i+1], &a, &b);
        encrypted_text[encrypted_len++] = toupper(a);
        encrypted_text[encrypted_len++] = toupper(b);
    }
    encrypted_text[encrypted_len] = '\0';

    printf("Plaintext: %s\n", prepared_text);
    printf("Encrypted: %s\n", encrypted_text);
}

int main() {
    char message[100];
    char key[27];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    printf("Enter the key: ");
    scanf("%26s", key);

    playfair_encrypt(message, key);

    return 0;
}
