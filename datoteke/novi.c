// u novu datoteku staviti lekove bez recepta, na osnovu cene rasporediti lekove, novi niz sa lekovima sa receptom
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct lekovi{
    char naziv[30];
    int mg;
    char recept;
    int cena;
}LEKOVI;
int ucitavanje(FILE *p, LEKOVI *niz ){
    fscanf(p,"%s %d %c %d", niz->naziv, &niz->mg, &niz->recept, &niz->cena);
    if(feof(p)) return 0;
    return 1;
}
void ispis(LEKOVI *niz, int n){
    int i=0;
    for(i=0; i<n; i++){
        printf("%s %d %c %d\n", niz[i].naziv, niz[i].mg, niz[i].recept, niz[i].cena);
    }
}
int main(){
    FILE *p=fopen("tekst2.txt", "r");
    if(p==NULL){
        return 1;
    }
LEKOVI niz[MAX];
int i=0, j=0;
while(ucitavanje(p, &niz[i])){
i++;}
int n=i;
ispis(niz, n);
fclose(p);
FILE *nova=fopen("novadat.txt", "w");
if(nova==NULL){
    return 1;}
for(i=0 ;i<n; i++){
    if (niz[i].recept == 'R') {
        fprintf(nova,"%s %d %c %d\n", niz[i].naziv, niz[i].mg, niz[i].recept, niz[i].cena);
    }
}
for(i=0; i<n-1; i++) {
    for(j=i+1; j<n; j++) {
    if(niz[j].cena < niz[i].cena){
        LEKOVI pom=niz[i];
        niz[i]=niz[j];
        niz[j]=pom;
    }
    }}
    printf("poredjani lekovi\n");
    for(i=0; i<n; i++) {
printf("%s %d %c %d\n", niz[i].naziv, niz[i].mg, niz[i].recept, niz[i].cena);}
LEKOVI niz2[MAX];
int k=0;
for(i=0; i<n; i++){
    if(niz[i].recept =='B'){
            niz2[k] = niz[i];
            k++;}}
 printf("poredjani lekovi BEZ RECEPTA\n");
for(i=0; i<k; i++){
    printf("%s %d %c %d\n", niz2[i].naziv, niz2[i].mg, niz2[i].recept, niz2[i].cena);
}
    return 0;
}