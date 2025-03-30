/**
 * @file funcoes.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"
/**
 * @brief criar antena(sem estrutura)
 * 
 * @param frequencia//letra da frequência
 * @param a //cordenada
 * @param b //cordenada
 * @return Antena* 
 */
Antena* Inserir(char frequencia,int a, int b){
Antena* quadrado= (Antena*)malloc(sizeof(Antena));//criação de espaço na memória para a estrutura 
quadrado->frequencia=frequencia;
quadrado->a=a;
quadrado->b=b;
quadrado->next=NULL;//apontador que aponta para o próximo que este está a apontar para nulo
return quadrado;
}
/**
 * @brief ligamento entre antenas pelo incio
 * 
 * @param inicio//variavel que vai apontar para a primeira Antena da função
 * @param quadrado//Antena criada
 * @return Antena* 
 */
Antena* Inicio(Antena* inicio, Antena*quadrado){
if(quadrado==NULL){
return inicio;//se o quadrado for nulo retorna o inicio esteja como estiver
}
if (inicio==NULL){
return quadrado;//se o inicio estiver a apontar para nulo o quadrado será o primeiro elemento da lista
}
else{
quadrado->next=inicio;//o quadrado aponta para o próximo,e o proximo é igual ao inicio
inicio=quadrado;//o incio passa a ser o quadrado atual
return inicio;//retorna a variavel inicio com o seu novo apontador
}
}
/**
 * @brief Listar as estruras ligadas 
 * 
 * @param incio//variável que aponta para o primeiro quadrado da função
 */
void Listar(Antena*incio){
Antena*atual=incio;
while(atual!=NULL){
printf("A Antena tem a frequência(%c), na posição(%d, %d)\n", atual->frequencia, atual->a, atual->b);
atual=atual->next;
}
}
/**
 * @brief Adiciona Antena ao fim da lista
 * 
 * @param inicio//variavel que aponta para o inicio da função
 * @param quadrado//Antena criada 
 * @return Antena* 
 */
Antena* InserirFim(Antena* inicio, Antena* quadrado){
if(quadrado==NULL){
return 0;//encerra o código caso o quadrado esteja vazio
}
if(inicio==NULL){
quadrado=inicio;
return inicio;//retorna a listagem com o quadrado no inicio, caso não haja ainda uma lista apontada pelo inicio
}
else{
Antena* fim=inicio;
while(fim->next!=NULL){
fim=fim->next;//vai até ao último quadrado, que este está a apontar para NULL
}
fim->next=quadrado;//o fim fica a pontar para o quadrado criado, que lhe faz o último quadrado da lista
quadrado->next==NULL;
return inicio;//retorna a listagem já na ordem atualizada 
}
}
/**
 * @brief Remover Antenas
 * 
 * @param inicio//Aponta para a primeiro quadrado da lista
 * @param quadrado//Antena criada
 * @return Antena 
 */
Antena* remover(Antena*inicio, Antena*quadrado){
Antena* percorre= inicio;
Antena* rmantena=NULL;
while(percorre!=NULL&&(percorre->frequencia!=quadrado->frequencia)){
rmantena=percorre;
percorre=percorre->next;
}
if(percorre==NULL){//Caso a Antena não seja encontrada ou que não seja válida
printf("n\n");
return 0;
}
if(rmantena==NULL){//caso a Antena a ser removida seja a primeira da lista
inicio=percorre->next;//passa para a proxima Antena ignorando a incial e a mesma fica sem ligação com a lista
}
else{
rmantena->next=percorre->next;
free (percorre);
}
return inicio;//retorna a lista já sem a Antena que foi removida
}
/**
 * @brief Carregamento das Antenas para um ficheiro
 * 
 * @param inicio//variavel que aponta para o primeio quadrado da lista
 * @param nome_arquivo//nome do arquivo pretendido
 * @return int 
 */
int CarregarParaFicheiro(Antena* inicio,char* nome_arquivo) {
FILE *f = fopen(nome_arquivo, "w");//Abre o arquivo em modo de escrita
if (f == NULL) {
printf("Erro ao abrir o arquivo para escrita.\n");
return 0;
}
Antena* atual = inicio;
while (atual != NULL) {
fprintf(f, "%c %d %d\n", atual->frequencia, atual->a, atual->b);//Escreve as informações da Antena num arquivo
atual = atual->next;
 }
fclose(f);
return 0;
}
/**
 * @brief Função que insere uma antena de forma ordenada na lista.
 * 
 * @param inicio//variavel que aponta para o primeiro quadrado da lista 
 * @param quadrado//Antena criada
 * @return Antena* 
 */
Antena* InserirOrdenada(Antena* inicio, Antena* quadrado) {
if (quadrado == NULL) {
return inicio;}  //retorna a lista sem mudanças
if (inicio == NULL) {//se o inicio estiver vazio
return quadrado; }//a nova antena criada torna-se o inico
if ((quadrado->a < inicio->a) || (quadrado->a == inicio->a && quadrado->b < inicio->b)) {//caso seja menor que  primeira da lista
return Inicio(inicio, quadrado);//a ordantena=inicio da lista
}
Antena* atual = inicio;
while (atual->next != NULL &&((quadrado->a > atual->next->a) || (quadrado->a == atual->next->a && quadrado->b > atual->next->b))) {
atual = atual->next;  //avança até encontrar a posição correta ou o final da lista
 }
quadrado->next = atual->next;//a antena nova fica a apontar exatamnete para o mesmo sítio que o atual assumindo a posição dele
atual->next = quadrado;//o next do atual fica a apontar para a ordantena ou a nova Antena criada
return inicio;  // Retorna a lista
}
/**
 * @brief Gravar em binário
 * 
 * @param nomeFicheiro nome do ficheiro pretendido
 * @param quadrado Antena da função
 * @return int 
 */
int GravarElementBinario(char* nomeFicheiro, Antena* quadrado) {
FILE* ant;
if (quadrado == NULL) return 0;
if ((ant = fopen(nomeFicheiro, "wb")) == NULL) return 0;
//grava todos registos da lista no ficheiro
Antena* aux = quadrado;
AntenaFile Antenaaux;	//struct auxiliar para gravar em ficheiro!
while (aux!=NULL){			//while(aux!=NULL)
//Colocar no registo de ficheiro a inf que esta no registo de memoria
Antenaaux.a = aux->a;
Antenaaux.b = aux->b;
Antenaaux.frequencia = aux->frequencia;
fwrite(&Antenaaux, sizeof(AntenaFile), 1, ant);
aux = aux->next;
}
fclose(ant);
return 0;
}
/**
 * @brief 
 * 
 * @param nomeFicheiro Nome do ficheiro pretendido
 * @return Antena* 
 */
Antena* LerElementsBinario(char* nomeFicheiro) {
FILE* ant;
Antena* quadrado = NULL;
Antena* aux;
if ((ant = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
//le os registos dentro do ficheiro
AntenaFile auxAntena;
while (fread(&auxAntena, sizeof(AntenaFile), 1, ant)) {
//Insere as Antenas no ficheiro
aux = Inserir(auxAntena.a, auxAntena.b, auxAntena.frequencia);
quadrado = InserirOrdenada(quadrado, aux);
}
fclose(ant);
return quadrado;
}
/**
 * @brief 
 * 
 * @param nomeFicheiro 
 */
void lerFicheirotxt(const char* nomeFicheiro) {
FILE* file = fopen(nomeFicheiro, "r");
if (file == NULL) {
printf("Erro ao abrir o arquivo.\n");
return;
}
char matriz[8][12];//Cria uma matriz de 8n linhas e 12 colunas
for (int i = 0; i < 8; i++) {//lê o arquivo linha por liha 
for (int j = 0; j < 12; j++) {//Lê coluna por coluna
matriz[i][j] = fgetc(file);  // Lê um caractere do arquivo
}
fgetc(file); // Para consumir o '\n' (quebra de linha) ao final de cada linha
}
fclose(file); // Fecha o arquivo
printf("Conteúdo do ficheiro:\n");//Mostra o conteúdo da matriz
for (int i = 0; i < 8; i++) {
for (int j = 0; j < 12; j++) {
printf("%c", matriz[i][j]);  // Exibe o caractere
}
printf("\n"); }
}
/**
 * @brief Calcula o efeito nefasto
 * 
 * @param inicio//variável que aponta para o incio ou cabeça da lista ligada das Antenas
 * @return EfeitoNefasto* 
 */
EfeitoNefasto* CalculaNefasto(Antena* inicio){
Antena* antena1 = inicio;//a antena1 aponta para a primeira estrutura da lista
EfeitoNefasto* head;//cria a variável "incio", da lista do EfeitoneFasto
while(antena1!=NULL){
Antena*antena2 = antena1->next;//a antena2 passa a ser a Antena a seguir da antena1
while(antena2!=NULL){
if(antena1->frequencia==antena2->frequencia){//se a antena1 e """"2 tiverem a frequencia igual
int dist1=abs(antena2->a-antena1->a);
int dist2=abs(antena2->b-antena1->b);
if(dist1==2 && dist2==2){//se ambas forem iguais a 2
EfeitoNefasto* nefasto = (EfeitoNefasto*)malloc(sizeof(EfeitoNefasto));//cria uma estrura na memoria do tipo structc EfeitoNefasto
nefasto->a=((antena1->a+antena2->a)/2);
nefasto->b=((antena1->b+antena2->b)/2);
nefasto->next=NULL;
if(nefasto==NULL){
return 0;//se 
}
if(head==NULL){//caso a head esteja vazia o nefasto torna-se a cabeça da lista
head=nefasto;
}
else{
nefasto->next=head;//aponta para o inicio ou head da lista que aponta para a primeira estrutura da lista
head=nefasto;//o novo nefasto torna se o incio ou head
}}
}
antena2=antena2->next;//a antena2 passa para a posicao seguinte
}
antena1=antena1->next;//a antena1 passa para a posicao seguinte
}
return head;//retrona a lista do efeitonefasto
}
/**
 * @brief Listar o efeito nefasto
 * 
 * @param head Cabeça da lista do efeito nefasto
 */
void ListarNefasto(EfeitoNefasto*head){
EfeitoNefasto*atual;
atual=head;//aponta para o mesmo que a variável head aponta(neste caso o incio da lista)
while(atual!=NULL){
printf("%d, %d\n", atual->a, atual->b);
atual=atual->next;//passa sempre a apontar o proximo da lista
}
}
