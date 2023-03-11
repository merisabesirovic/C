#include <stdio.h>
#define MAX 50
typedef struct igraci{
   char ime[30]; 
 int visina; 
 int tezina; 
 int brKoseva; 
 int brAsistencija; 
 int brUkradenihLopti; 
 int brBlokada; 
 float ukupanBrBodova;

}IGRACI;

int ucitajIgraca(FILE *fp, IGRACI *i) 
{ 
 fscanf(fp, "%s%d%d%d%d%d%d", i->ime, &(i->visina), &(i->tezina), 
 &(i->brKoseva), &(i->brAsistencija), &(i->brUkradenihLopti), 
 &(i->brBlokada)); 
 if(feof(fp)) return 0; 
 return 1; 
} 
IGRACI igrac[MAX]; 
IGRACI najbolji; 
int brIgraca=0; 
int brBodova=0; 
int UkBrojbod(IGRACI i) {
float pKoseva=i.brKoseva;
float pAsistencija=i.brAsistencija*0.5;
int pUkradenih=0.3*i.brUkradenihLopti;
float pBlokada=i.brBlokada * 0.2; 
 i.ukupanBrBodova=pKoseva+pAsistencija+pUkradenih+pBlokada;

if(i.ukupanBrBodova>brBodova) {
    brBodova = i.ukupanBrBodova; 
    najbolji=i;
    
    }return i.ukupanBrBodova;}
    void ispisiIgrace(IGRACI najbolji) 
{ printf("\n\n%-10s \t%d %d %d %d %d %d \t %f \n\n", 
 najbolji.ime, najbolji.visina, najbolji.tezina, 
 najbolji.brKoseva,najbolji.brAsistencija, 
 najbolji.brUkradenihLopti, najbolji.brBlokada, 
 najbolji.ukupanBrBodova); }

int main(){
    IGRACI igrac[MAX];
    FILE *fp=fopen("test.txt", "r");
    if(fp==NULL){
        printf("greska");
        return 1;}
        while( ucitajIgraca(fp,&igrac[brIgraca]))
        brIgraca++; 
 ispisiIgrace(najbolji); 
 fclose(fp);
           
        
    return 0;

}