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
    fscanf(fp,"%s%s%d%d%d%d",&niz->ime,&niz->prezime,&niz->predavanja,&niz->kolokvijumi,&niz->ispit, &niz->ukupanBrbodova);
    if(feof(fp)) return 0;
    return 1;

}
void ispis(int n, STUDENT *niz){
    for(int i=0; i<n; i++)
{
    printf("\n%s %s %d %d %d",niz[i].ime,niz[i].prezime,niz[i].kolokvijumi,niz[i].ispit,niz[i].predavanja);
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
 FILE *f2=fopen("tekst2.txt", "w");
 if(f2==NULL) {
 return 1;
 }
 for(int i=0; i<n; i++){
    if((studenti[i].kolokvijumi+studenti[i].ispit+studenti[i].predavanja)>50){
        fprintf(f2, "\n%s %s %d %d %d",studenti[i].ime,studenti[i].prezime,studenti[i].kolokvijumi,studenti[i].ispit,studenti[i].predavanja);
    }
 }

    return 0;
}
