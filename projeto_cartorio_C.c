#include <stdio.h> //biblioteca de comunica��o com o usu�rio


    fprintf(file, cpf);  // voc� salva no arquivo o cpf.

{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    //cria��o das vari�veis
    //fim da cria��o de vari�veis
    printf("## CONSULTA DE NOMES ##\n");//Titulo
    printf("\nEssas s�o as informa��es do usu�rio: \n");

    if(file == NULL) // se n�o for encontrado no arquivo retorna a mensagem dentro da condi��o


    printf("\n\n");//duas linhas de espa��
    printf("\n\nAperte 'enter para retornaer ao menu.'");//interagindo com o usu�rio.
    getchar();//aguarda o usu�rio apertar enter
    getchar();
    char cpf[40];
    //fim da cria��o

    printf("Digite o CPF do usu�rio a ser deletado: \n");//pede o cpf 'primekey' a ser deletado.
    scanf("%s",cpf);//atribui o numero inserido pelo usuario no 'char cpf'





    FILE *file;//acessando o arquivo file
    file = fopen(cpf, "r");//'r' (read) le o arquivo
    fclose(file);//fecha o arquivo
    //inicio da condi��o'if'.
    if(file == NULL)//se o usuario n�o for encontrado no sistema se retornado a mensagem abaixo.
    {
        printf("Usu�rio n�o localizado no sistema.\n");


    }//fim da condi��o 'if'.
    else// inicio da condi��o 'sen�o'.
    {
        remove(cpf);//deleta o cpf determinado pelo usu�rio
        printf("Usu�rio deletado com sucesso!!"); //mensagem exibidade ap�s o usu�rio ser deletado.
    }//fim da condi��o 'senao'.

    printf("\n\naperte 'enter' para voltar ao menu inicial.");//interagindo com o usu�rio.
