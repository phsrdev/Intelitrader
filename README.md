# Criptografia na Rede do Navio

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

[Clique aqui](https://colab.research.google.com/drive/1ktU69FaMwE6JMlze9qUktHw_vBC5Wfhi?usp=sharing)
