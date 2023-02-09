#include <stdio.h> //biblioteca de comunica��o com o usu�rio#include <stdlib.h> // bibblioteca de aloca��o de mem�ria#include <locale.h> //biblioteca de aloca��es de texte por regi�o#include <string.h> //biblioteca reponsavel pela STRINGs
int registro()//Fun��o responsavel pelo cadastro do usu�rio.{   //cria��o das vari�veis.    char arquivo[40];    char cpf[40];//'PrimeKey' que usaremos com refer�ncia para buscar os usu�rios.    char nome[40];    char sobrenome[40];    char cargo[40];    //fim da cria��o de var�veis.
    printf("## REGISTRO DE UM NOVO NOME ##\n");//t�tulo.    printf("Digite o cpf a ser cadastrado: \n");//coletando informa��o do usu�rio.    scanf("%s",cpf);//%s refere-se a string. atribui a informa��o dada pelo usu�rio a string 'cpf'.    strcpy(arquivo, cpf);// responsavel por copiar os valores das strings CPF =='PrimeKey'.    FILE *file; //acessamos a fun��o FILE, para criar o arquivo na pasta.    file = fopen(arquivo,"w"); //abra o aquivo file para escrever =='W'write.    fprintf(file, "CPF: ");// adicionamos o 'CPF:' para uma melhor visualiza��o quando consultado.
    fprintf(file, cpf);  // voc� salva no arquivo o cpf.    fclose(file);  // fecha o arquivo (IMPORTANTE).    file = fopen(arquivo, "a");  //"a" significa atualizar o arquivo incluiando uma nova informa��o(nome).    fprintf(file,"\nNome: ");// adiciona o 'nome:' no arquivo, para a melhor visualiza��o na consulta.    fclose(file);// fecha o arquivo.    //atribuindo o nome ao aruqivo.    printf("Digite o nome a ser cadastrado: \n");    scanf("%s", nome);//atribui a informa��o dada pelo usuario a string 'nome'.    file = fopen(arquivo, "a");//abre o arquivo e pede para tualizar.    fprintf(file, nome); //salvando informa��o no arquivo.    fclose(file);// fecha o arquivo.    file = fopen(arquivo, "a");  //abre o arquivo e pede para tualizar.    fprintf(file,"\nSobrenome: "); // adiciona o 'sobrenome:' no arquivo, para a melhor visualiza��o na consulta.    fclose(file);// fecha o arquivo.    //atribuindo o sobrenome ao arquivo.    printf("Digite o sobrenome a ser cadastrado: \n");    scanf("%s",sobrenome);//atribui a informa��o dada pelo usuario a string 'sobrenome'.    file = fopen(arquivo, "a");//abre o arquivo e pede para tualizar.    fprintf(file,sobrenome);//salvando informa��o no arquivo.    fclose(file);// fecha o arquivo.
    file = fopen(arquivo, "a");  //abre o arquivo e pede para tualizar.    fprintf(file,"\ncargo: ");  // adiciona o 'cargo' no arquivo, para a melhor visualiza��o na consulta    fclose(file);// fecha o arquivo.    //atribuindo o cargo    printf("Digite o cargo: \n");    scanf("%s",cargo);//atribui a informa��o dada pelo usuario a string 'cargo'.    file = fopen(arquivo, "a");//abre o arquivo e pede para tualizar.    fprintf(file,cargo);//salvando informa��o no arquivo.    fclose(file);// fecha o arquivo.    printf("pressione 'enter' para continuar.");//interagindo com o usu�rio    getchar();//aguarda o usu�rio apertar enter    getchar();}//Fun��o respons�vel pela consultaint consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    //cria��o das vari�veis    char cpf[40];    char conteudo[200];
    //fim da cria��o de vari�veis
    printf("## CONSULTA DE NOMES ##\n");//Titulo    printf("Digite o CPF a ser consultado: \n");    scanf("%s", cpf);//atribui o numero inserido pelo usuario no 'char cpf'
    printf("\nEssas s�o as informa��es do usu�rio: \n");    FILE *file;//acessando o arquivo file    file = fopen(cpf,"r");  //"r"(read) ler o arquivo cpf

    if(file == NULL) // se n�o for encontrado no arquivo retorna a mensagem dentro da condi��o    {        printf("Usu�rio n�o localizado.\n");// mensagem apresentada se o usu�rio n�o constar no sistema    }// fim da condi��o IF
    // repeti��o while para busca as strings dentro do arquivo    while(fgets(conteudo, 200, file) != NULL)    {        printf("%s", conteudo);//retorna o conteudo do arquivo
    }// fim da repeti��o while
    printf("\n\n");//duas linhas de espa��
    printf("\n\nAperte 'enter para retornaer ao menu.'");//interagindo com o usu�rio.
    getchar();//aguarda o usu�rio apertar enter
    getchar();}int deleta(){   //cria��o da vari�vel
    char cpf[40];
    //fim da cria��o    printf("## DELETAR NOME ##\n");//t�tulo

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
    getchar();//aguarda o usu�rio apertar enter    getchar();}int main()//inicio do programa principal.    {    int opcao=0; //definindo op��o como variavel (lembre-se de sempre setar  a vari�vel)    int laco=1;//definindo a vari�vel par o la�o for    //inicio do la�o de repeti��o 'for'.    for(laco=1;laco==1;)    {        system("clear");//limpa tela(IOS)        setlocale(LC_ALL, "Portuguese");//definido o idioma. comando linkado a biblioteca <locale.h> linha3        printf("#_# Cart�rio da EBAC #_#\n\n");//T�tulo cart�rio        printf("Escolha a op��o desejada do menu: \n\n");//Inicio do menu de op��es        printf("\t1 - Registrar nomes.\n");        printf("\t2 - Consultar nomes.\n");        printf("\t3 - Deletar nome.\n");
        printf("\t4 - Finalizar programa.\n");// fim do menu        printf("\n");        printf("op��o: ");        scanf("%d", &opcao);//"%d" refere-se a n�meros inteiros. opcao recebe (=) a resposta do usu�rio        system("clear");//limpa a tela(IOS)        //inicio da condi��o 'switch' (atentar na composi��o 'case:, instru��o, break;')        switch(opcao)        {            case 1:            registro();//chamada de fun��o de registro            break;            case 2:            consulta();//chama a fun��o de consulta            break;            case 3:            deleta();//chama a fun��o de delete            break;

            case 4:
            printf("\n");
            printf("\t\tMuito Obrigado, volte sempre!");
            printf("\n");
            return 0;
            break;            default:            printf("## OP��O N�O DISPON�VEL NO SISTEMA ##\n\n");// se o usuario selecionar uma op��o que n�o cosntano menu            printf("TENTE NOVAMENTE.\n\n");//interagindo com o usu�rio.            getchar();//aguarda o usu�rio apertar enter            getchar();            break;        }//fim do swith    }//fim do la�o for}// fim da fun��o main