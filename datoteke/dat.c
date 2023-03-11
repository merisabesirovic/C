// // #include<stdio.h>
// // #include<string.h>
// // #define MAX 100
// // typedef struct artikli{
// //     int barKod;
// //     char proizvod[20];
// //     int cena;
// // }ARTIKLI;
// // int main(){
// //     FILE *fp=fopen("test.txt","r");
// //     if(fp==NULL) {
// //         printf("greska");
// //         return 1;
// //     }
// //     else printf("uspesno otvorena datoteka\n");
// //     int i=0, n;
// //     ARTIKLI artikal[MAX];
// //     printf("proizvodi koji imaju cenu nizu od 500\n");
// //     while(1){
// //         fscanf(fp, "%d %s %d" ,&artikal[i].barKod, &artikal[i].proizvod, &artikal[i].cena);
// //         if(feof(fp))break;
// //         if(artikal[i].cena<500){
// //             printf("proizvod cija je cena manja od 500 %d%s%d\n",artikal[i].barKod, artikal[i].proizvod, artikal[i].cena);
// //             i++;
// //         }
// //     }
// //     fclose(fp);


// //     return 0;
// // }

// #include <stdio.h>
// #include <string.h>
// #define MAX 50
// typedef struct gradjanin{
//     char ime[15];
//     char prezime[20];}
//     GRADJANIN;
// void SortirajIme(GRADJANIN *a, int n){
//     int i, j, min;
//     GRADJANIN pom;
//     for(i=0; i<n-1; i++){
//         min = i;
//         for(j=i-1; j<n; j++){
//             if(strcmp(a[j].prezime, a[min].prezime) < 0) 
//             min=j; 
//             if(min != i) 
//             {
//             pom=a[i]; 
//             a[i]=a[min]; 
//             a[min]=pom; 

//         }
//     }
// }}
// void SortirajPrezime(GRADJANIN a[], int n) 
// { 
//  int i, j, min; 
//  GRADJANIN pom; 
//  for(i=0; i<n-1; i++) 
//  { 
//  /*Unutrasnja petlja pronalazi poziciju min, na kojoj se nalazi 
//  najmanji od elemenata a[i].prezime,...,a[n-1].prezime.*/ 
//  min=i; 
//  for(j=i+1; j<n; j++) 
//  if(strcmp(a[j].prezime, a[min].prezime) < 0) 
//  min=j; 
//  /*Zamena elemenata na pozicijama (i) i min. Ovo se radi 
//  samo ako su (i) i min razliciti, inace je nepotrebno.*/ 
//  if(min != i) 
//  { 
//  pom=a[i]; 
//  a[i]=a[min]; 
//  a[min]=pom; 
//  } 
//  } 
// } 
// int Pretraga(GRADJANIN a[], int n, GRADJANIN *x ) 
// { 
//  int i; 
//  for(i=0; i<n; i++) 
//  if(strcmp(a[i].ime, x->ime)==0 && 
//  strcmp(a[i].prezime, x->prezime)==0) 
//  return i; 
//  return -1; 
// } 
// int main(){
// GRADJANIN spisak1[MAX], spisak2[MAX];
// int i, n ,istiRbr=0;;
// FILE *fp = fopen("test.txt","r");
// if(fp == NULL){
//     printf("greska");
//     return 1;
// }
// for(i=0; fscanf(fp,"%s %s", spisak1[i].ime, spisak1[i].prezime) != 
//  EOF; i++ ) 
//  spisak2[i]=spisak1[i]; 
//  n=i++; 
//  SortirajIme(spisak1, n); 
//  printf("\n\n -Biracki spisak [uredjen prema imenima]-\n"); 
//  for(i=0; i<n; i++) 
//  printf(" %d. %s %s\n",i+1,spisak1[i].ime, spisak1[i].prezime); 
//  SortirajPrezime(spisak2, n); 
//  printf("\n\n -Biracki spisak [uredjen prema prezimenima]-\n"); 
//  for(i=0; i<n; i++) 
//  printf(" %d. %s %s\n",i+1,spisak2[i].ime, spisak2[i].prezime);
//  for(i=0; i<n ;i++) 
//  if(i==Pretraga(spisak2,n, &spisak1[i])) 
//  istiRbr++; 
//  printf("broj gradjana sa istim bojem %d", istiRbr); 
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct ucenici{
    char ime[15];
    char prezime[15];
    int predavanja;
    int kolokvijumi;
    int ispit;
    int ukupanBrbodova;
}STUDENT;
int ucitaj(FILE *fp, STUDENT *niz)
{
    fscanf(fp,"%s%s%d%d%d",&niz->ime,&niz->prezime,&niz->predavanja,&niz->kolokvijumi,&niz->ispit);
    if(feof(fp)) return 0;
    return 1;

}
void ispis(int n, STUDENT *niz){
    for(int i=0; i<n; i++)
{
    printf("%s%s%d%d%d%d",niz[i].ime,niz[i].prezime,niz[i].kolokvijumi,niz[i].ispit,niz[i].predavanja, niz[i].ukupanBrbodova);
}
}
int main(){
    FILE *fp = fopen("test.txt", "r");
    if (fp==NULL) {
        printf("greska");
        return 1;
    }
    int i=0;
    STUDENT studenti [MAX];
    while(ucitaj(fp, &studenti[i]))
 i++; 
 int n=i;
 ispis(n,studenti);
    return 0;
}
