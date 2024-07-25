/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para trocar o valor dos últimos dois bits de cada byte
void trocar_valor_ultimos_dois_bits(char* byte) {
    char ultimos_dois_bits[3];
    strncpy(ultimos_dois_bits, byte + 6, 2);
    ultimos_dois_bits[2] = '\0';

    if (strcmp(ultimos_dois_bits, "00") == 0) {
        strncpy(byte + 6, "11", 2);
    } else if (strcmp(ultimos_dois_bits, "01") == 0) {
        strncpy(byte + 6, "10", 2);
    } else if (strcmp(ultimos_dois_bits, "10") == 0) {
        strncpy(byte + 6, "01", 2);
    } else { // "11"
        strncpy(byte + 6, "00", 2);
    }
}

// Função para trocar os primeiros 4 bits com os últimos 4 bits
void trocar_4bits(char* byte) {
    char temp[5];
    strncpy(temp, byte, 4);
    temp[4] = '\0';
    strncpy(byte, byte + 4, 4);
    strncpy(byte + 4, temp, 4);
}

int main() {
    const char* mensagem_criptografada[] = {
        "10010110", "11110111", "01010110", "00000001",
        "00010111", "00100110", "01010111", "00000001",
        "00010111", "01110110", "01010111", "00110110",
        "11110111", "11010111", "01010111", "00000011"
    };
    int tamanho = sizeof(mensagem_criptografada) / sizeof(mensagem_criptografada[0]);

    char bits_descriptografados[129] = ""; // 128 bits + 1 para o terminador nulo
    for (int i = 0; i < tamanho; i++) {
        char byte[9];
        strncpy(byte, mensagem_criptografada[i], 8);
        byte[8] = '\0';

        trocar_valor_ultimos_dois_bits(byte);
        trocar_4bits(byte);

        strcat(bits_descriptografados, byte);
    }

    char mensagem_ascii[17] = ""; // 16 caracteres + 1 para o terminador nulo
    for (int i = 0; i < 128; i += 8) {
        char byte[9];
        strncpy(byte, bits_descriptografados + i, 8);
        byte[8] = '\0';

        char caractere = strtol(byte, NULL, 2);
        strncat(mensagem_ascii, &caractere, 1);
    }

    printf("Mensagem descriptografada: %s\n", mensagem_ascii);

    return 0;
}