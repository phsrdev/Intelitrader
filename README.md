# Desafio 1 - Criptografia na Rede do Navio

## Descrição do Projeto

A Intelitrader foi contratada para traduzir uma mensagem capturada na rede de um navio, e essa mensagem está criptografada. Não sabemos que tipo de criptografia foi utilizada, mas sabemos o seguinte:

1. A cada 8 bits, os dois últimos estão invertidos.
2. A cada 8 bits, os primeiros 4 bits foram trocados com os próximos 4 bits.

### Mensagem Criptografada
10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011
## Instruções

Para resolver esse problema, é necessário descriptografar a mensagem de modo que ela se torne legível e esteja em inglês. Caso haja qualquer bit errado, a mensagem resultante será cheia de símbolos.

### Dicas e Conceitos Úteis

- **Tabela ASCII**: Utilize a tabela ASCII para converter os binários em caracteres legíveis.
- **Operadores Lógicos**: Conhecimento sobre operadores lógicos pode ser útil para manipulação de bits.
- **Números Binários e Hexadecimais**: Familiaridade com sistemas numéricos binários e hexadecimais.

## Solução:

[Clique aqui, para Solução em Python](https://colab.research.google.com/drive/1ktU69FaMwE6JMlze9qUktHw_vBC5Wfhi?usp=sharing)

[Clique aqui, para Solução em C](https://onlinegdb.com/accIFlUip)


# Desafio 2 - Livro de Ofertas

Parabéns!! você foi contratado por uma corretora para montar  um sistema de livro de ofertas de vendas e compras.  
Um livro de ofertas nada mais é que uma lista de um mesmo produto organizadas pelo seu preço.

A cada negocicão de compra ou venda  os livros de ofertas são atualizados, podendo inserir , remover ou modifcar as ofertas presentes no livro. 
Cada operação na livro gera uma nova mensagem que é composta por 4 paramêtros, o primeiro valor é a posição da atualização, já segunda é o tipo de ação a ser tomada, em  terceiro temos o valor e por último a quantidade. Cada propriedade é descrita na tabela abaixo:


PROPRIEDADE  |  TIPO    |    VALORES
-------------|----------|------------
POSIÇÃO      |   INTEIRO   |  valores positivos diferente de 0
ACÃO         |   INTEIRO   |  **0** = INSERIR, **1** = MODIFICAR, **2** = DELETAR**
VALORES      |   DOUBLE    |  Qualquer valor positivo diferente de 0
QUANTIDADE   |   INTEIRO   |  Qualquer valor positivo diferente de 0


## Exemplo:

**LIVRO DE OFERTA**

POSICAO | VALOR | QUANTIDADE 
--------|-------|------------
1       | 15.4  | 50         
2       | 15.4  | 10         
3       | 15.9  | 20         
4       | 16.1  | 100        
5       | 16.20 | 20         
6       | 16.43 | 30         
7       | 17.20 | 70         
8       | 17.35 | 80         
9       | 17.50 | 200         

Seu objetivo é fazer um programa que receba e processe todas as notificações de atualizações de um livro de ofertas e imprima seu resultado.

## Input:
A primeira linha é composta por um inteiro informando o número de notificações e as linhas subsequences contem as notificações no seguinte formato: **posição,ação,valor,quantidade**.

### exemplo:
12\
1,0,15.4,50\
2,0,15.5,50\
2,2,0,0\
2,0,15.4,10\
3,0,15.9,30\
3,1,0,20\
4,0,16.50,200\
5,0,17.00,100\
5,0,16.59,20\
6,2,0,0\
1,2,0,0\
2,1,15.6,0

## Output:
O output deve seguir o seguinte formato onde cada linha representa uma posição.

1,15.4,10\
2,15.6,20\
3,16.50,200\
4,16.59,20\


*representação do resultado*

POSICAO | VALOR | QUANTIDADE 
--------|-------|------------
1       | 15.4  | 10         
2       | 15.6  | 20         
3       | 16.50 | 200
4       | 16.59 | 20   


## Solução:

[Clique aqui, para Solução em Python](https://colab.research.google.com/drive/1RcdD8CVI9HejgvlBfnQCxh_0Rm2-J8Vs?usp=sharing)

[Clique aqui, para Solução em C](https://onlinegdb.com/ZvPL8piN3)

-----------------------------------------------------------------------------------------------------------------------------

