#include <stdio.h> //biblioteca de comunicação com o usuário#include <stdlib.h> // bibblioteca de alocação de memória#include <locale.h> //biblioteca de alocações de texte por região#include <string.h> //biblioteca reponsavel pela STRINGs
int registro()//Função responsavel pelo cadastro do usuário.{   //criação das variáveis.    char arquivo[40];    char cpf[40];//'PrimeKey' que usaremos com referência para buscar os usuários.    char nome[40];    char sobrenome[40];    char cargo[40];    //fim da criação de varáveis.
    printf("## REGISTRO DE UM NOVO NOME ##\n");//título.    printf("Digite o cpf a ser cadastrado: \n");//coletando informação do usuário.    scanf("%s",cpf);//%s refere-se a string. atribui a informação dada pelo usuário a string 'cpf'.    strcpy(arquivo, cpf);// responsavel por copiar os valores das strings CPF =='PrimeKey'.    FILE *file; //acessamos a função FILE, para criar o arquivo na pasta.    file = fopen(arquivo,"w"); //abra o aquivo file para escrever =='W'write.    fprintf(file, "CPF: ");// adicionamos o 'CPF:' para uma melhor visualização quando consultado.
    fprintf(file, cpf);  // você salva no arquivo o cpf.    fclose(file);  // fecha o arquivo (IMPORTANTE).    file = fopen(arquivo, "a");  //"a" significa atualizar o arquivo incluiando uma nova informação(nome).    fprintf(file,"\nNome: ");// adiciona o 'nome:' no arquivo, para a melhor visualização na consulta.    fclose(file);// fecha o arquivo.    //atribuindo o nome ao aruqivo.    printf("Digite o nome a ser cadastrado: \n");    scanf("%s", nome);//atribui a informação dada pelo usuario a string 'nome'.    file = fopen(arquivo, "a");//abre o arquivo e pede para tualizar.    fprintf(file, nome); //salvando informação no arquivo.    fclose(file);// fecha o arquivo.    file = fopen(arquivo, "a");  //abre o arquivo e pede para tualizar.    fprintf(file,"\nSobrenome: "); // adiciona o 'sobrenome:' no arquivo, para a melhor visualização na consulta.    fclose(file);// fecha o arquivo.    //atribuindo o sobrenome ao arquivo.    printf("Digite o sobrenome a ser cadastrado: \n");    scanf("%s",sobrenome);//atribui a informação dada pelo usuario a string 'sobrenome'.    file = fopen(arquivo, "a");//abre o arquivo e pede para tualizar.    fprintf(file,sobrenome);//salvando informação no arquivo.    fclose(file);// fecha o arquivo.
    file = fopen(arquivo, "a");  //abre o arquivo e pede para tualizar.    fprintf(file,"\ncargo: ");  // adiciona o 'cargo' no arquivo, para a melhor visualização na consulta    fclose(file);// fecha o arquivo.    //atribuindo o cargo    printf("Digite o cargo: \n");    scanf("%s",cargo);//atribui a informação dada pelo usuario a string 'cargo'.    file = fopen(arquivo, "a");//abre o arquivo e pede para tualizar.    fprintf(file,cargo);//salvando informação no arquivo.    fclose(file);// fecha o arquivo.    printf("pressione 'enter' para continuar.");//interagindo com o usuário    getchar();//aguarda o usuário apertar enter    getchar();}//Função responsável pela consultaint consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    //criação das variáveis    char cpf[40];    char conteudo[200];
    //fim da criação de variáveis
    printf("## CONSULTA DE NOMES ##\n");//Titulo    printf("Digite o CPF a ser consultado: \n");    scanf("%s", cpf);//atribui o numero inserido pelo usuario no 'char cpf'
    printf("\nEssas são as informações do usuário: \n");    FILE *file;//acessando o arquivo file    file = fopen(cpf,"r");  //"r"(read) ler o arquivo cpf

    if(file == NULL) // se não for encontrado no arquivo retorna a mensagem dentro da condição    {        printf("Usuário não localizado.\n");// mensagem apresentada se o usuário não constar no sistema    }// fim da condição IF
    // repetição while para busca as strings dentro do arquivo    while(fgets(conteudo, 200, file) != NULL)    {        printf("%s", conteudo);//retorna o conteudo do arquivo
    }// fim da repetição while
    printf("\n\n");//duas linhas de espaçõ
    printf("\n\nAperte 'enter para retornaer ao menu.'");//interagindo com o usuário.
    getchar();//aguarda o usuário apertar enter
    getchar();}int deleta(){   //criação da variável
    char cpf[40];
    //fim da criação    printf("## DELETAR NOME ##\n");//título

    printf("Digite o CPF do usuário a ser deletado: \n");//pede o cpf 'primekey' a ser deletado.
    scanf("%s",cpf);//atribui o numero inserido pelo usuario no 'char cpf'





    FILE *file;//acessando o arquivo file
    file = fopen(cpf, "r");//'r' (read) le o arquivo
    fclose(file);//fecha o arquivo
    //inicio da condição'if'.
    if(file == NULL)//se o usuario não for encontrado no sistema se retornado a mensagem abaixo.
    {
        printf("Usuário não localizado no sistema.\n");


    }//fim da condição 'if'.
    else// inicio da condição 'senão'.
    {
        remove(cpf);//deleta o cpf determinado pelo usuário
        printf("Usuário deletado com sucesso!!"); //mensagem exibidade após o usuário ser deletado.
    }//fim da condição 'senao'.

    printf("\n\naperte 'enter' para voltar ao menu inicial.");//interagindo com o usuário.
    getchar();//aguarda o usuário apertar enter    getchar();}int main()//inicio do programa principal.    {    int opcao=0; //definindo opção como variavel (lembre-se de sempre setar  a variável)    int laco=1;//definindo a variável par o laço for    //inicio do laço de repetição 'for'.    for(laco=1;laco==1;)    {        system("clear");//limpa tela(IOS)        setlocale(LC_ALL, "Portuguese");//definido o idioma. comando linkado a biblioteca <locale.h> linha3        printf("#_# Cartório da EBAC #_#\n\n");//Título cartório        printf("Escolha a opção desejada do menu: \n\n");//Inicio do menu de opções        printf("\t1 - Registrar nomes.\n");        printf("\t2 - Consultar nomes.\n");        printf("\t3 - Deletar nome.\n");
        printf("\t4 - Finalizar programa.\n");// fim do menu        printf("\n");        printf("opção: ");        scanf("%d", &opcao);//"%d" refere-se a números inteiros. opcao recebe (=) a resposta do usuário        system("clear");//limpa a tela(IOS)        //inicio da condição 'switch' (atentar na composição 'case:, instrução, break;')        switch(opcao)        {            case 1:            registro();//chamada de função de registro            break;            case 2:            consulta();//chama a função de consulta            break;            case 3:            deleta();//chama a função de delete            break;

            case 4:
            printf("\n");
            printf("\t\tMuito Obrigado, volte sempre!");
            printf("\n");
            return 0;
            break;            default:            printf("## OPÇÃO NÃO DISPONÍVEL NO SISTEMA ##\n\n");// se o usuario selecionar uma opção que não cosntano menu            printf("TENTE NOVAMENTE.\n\n");//interagindo com o usuário.            getchar();//aguarda o usuário apertar enter            getchar();            break;        }//fim do swith    }//fim do laço for}// fim da função main