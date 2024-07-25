#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma oferta
typedef struct {
    double valor;
    int quantidade;
} Oferta;

// Função para inserir uma oferta
void inserir_oferta(Oferta* lista_ofertas, int* tamanho, int posicao, double valor, int quantidade) {
    for (int i = *tamanho; i > posicao; i--) {
        lista_ofertas[i] = lista_ofertas[i - 1];
    }
    lista_ofertas[posicao].valor = valor;
    lista_ofertas[posicao].quantidade = quantidade;
    (*tamanho)++;
}

// Função para modificar uma oferta
void modificar_oferta(Oferta* lista_ofertas, int tamanho, int posicao, double valor, int quantidade) {
    if (posicao >= tamanho) {
        printf("Erro: Modificar em posição %d não é válido.\n", posicao);
        return;
    }
    if (valor > 0) {
        lista_ofertas[posicao].valor = valor;
    }
    if (quantidade > 0) {
        lista_ofertas[posicao].quantidade = quantidade;
    }
}

// Função para deletar uma oferta
void deletar_oferta(Oferta* lista_ofertas, int* tamanho, int posicao) {
    if (posicao >= 0 && posicao < *tamanho) {
        for (int i = posicao; i < *tamanho - 1; i++) {
            lista_ofertas[i] = lista_ofertas[i + 1];
        }
        (*tamanho)--;
        printf("Oferta removida com sucesso.\n");
    } else {
        printf("Posição inválida. A oferta não pode ser removida.\n");
    }
}

// Função para imprimir as ofertas de maneira formatada
void imprimir_ofertas(Oferta* lista_ofertas, int tamanho) {
    printf("+---------+--------+-----------+\n");
    printf("| POSICAO | VALOR  | QUANTIDADE|\n");
    printf("+---------+--------+-----------+\n");
    for (int i = 0; i < tamanho; i++) {
        printf("| %-7d | %-6.2f | %-9d |\n", i + 1, lista_ofertas[i].valor, lista_ofertas[i].quantidade);
        printf("+---------+--------+-----------+\n");
    }
}

int main() {
    char input[] = "12\n"
                   "1,0,15.4,50\n"
                   "2,0,15.5,50\n"
                   "2,2,0,0\n"
                   "2,0,15.4,10\n"
                   "3,0,15.9,30\n"
                   "3,1,0,20\n"
                   "4,0,16.50,200\n"
                   "5,0,17.00,100\n"
                   "5,0,16.59,20\n"
                   "6,2,0,0\n"
                   "1,2,0,0\n"
                   "2,1,15.6,0";

    int num_acoes;
    sscanf(input, "%d\n", &num_acoes);

    Oferta lista_ofertas[100]; // Assumindo no máximo 100 ofertas
    int tamanho = 0;

    char* linha = strtok(input + 3, "\n"); // Pula o número inicial de ações
    while (linha != NULL) {
        int posicao, acao, quantidade;
        double valor;
        sscanf(linha, "%d,%d,%lf,%d", &posicao, &acao, &valor, &quantidade);
        posicao -= 1; // Ajusta a posição para índice 0

        if (acao == 0) {
            inserir_oferta(lista_ofertas, &tamanho, posicao, valor, quantidade);
        } else if (acao == 1) {
            modificar_oferta(lista_ofertas, tamanho, posicao, valor, quantidade);
        } else if (acao == 2) {
            deletar_oferta(lista_ofertas, &tamanho, posicao);
        }

        linha = strtok(NULL, "\n");
    }

    // Ordena a lista de ofertas antes de imprimir
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (lista_ofertas[i].valor > lista_ofertas[j].valor) {
                Oferta temp = lista_ofertas[i];
                lista_ofertas[i] = lista_ofertas[j];
                lista_ofertas[j] = temp;
            }
        }
    }

    imprimir_ofertas(lista_ofertas, tamanho);

    return 0;
}
