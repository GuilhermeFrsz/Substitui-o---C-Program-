#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Caso não forneça a key, "./substitution KEY"
// Caso não seja 26 caracteres de key "KEY must contain 26 characters"
// Caso tenha algum numero na KEY "Key must only contain alphabetic characters "
// Caso a KEY tenha algum Repeated characters "Key must not contain repeated characters"

// Substitua apenas caracteres alfabéticos!
// Os caracteres devem permanecer do mesmo tamanho

// Todo erro deve retornar 1;

void cipherword(string plain, char *key);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("\n ERRO: %s KEY\n", argv[0]);
        return 1;
    }

    int length = strlen(argv[1]);

    if (length != 26) {
        printf("\n KEY must contain 26 characters \n");
        return 1;
    }

    int characters[26] = {0};

    for (int i = 0; i < length; i++) {
        if (!isalpha(argv[1][i])) {
            printf("\n Key must only contain alphabetic characters  \n");
            return 1;
        }

        int indice = toupper(argv[1][i]) - 'A';

        if (characters[indice] == 1) {
            printf("\n Key must not contain repeated characters \n ");
            return 1;
        }

        characters[indice] = 1;
    }

    // get_string para pedir o plain text
    string plain = get_string("\n Plaintext: ");

    // Chame a função cipherword corrigida passando a chave
    cipherword(plain, argv[1]);

    // cifrar preservando caractere maiúsculo e minúsculo e todos os caracteres especiais
    printf(" ciphertext: %s\n", plain);
    return 0;
}

void cipherword(string plain, char *key) {
    int comprimento = strlen(plain);

    for (int i = 0; i < comprimento; i++) {
        if (isalpha(plain[i])) {
            char caractereAtual = toupper(plain[i]);
            int deslocamento = caractereAtual - 'A';

            // Aplica a cifra de substituição usando a chave
            plain[i] = islower(plain[i]) ? tolower(key[deslocamento]) : key[deslocamento];
        }
    }
}
