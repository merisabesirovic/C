
#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b,c;
    float x, y, x1, x2,D;
    cout << "Unesite koeficijente a, b, c";
    cin >> a >> b >> c ;
    if(a==0){
        if(b==0) cout << "Nema resenja";
    x=-c/(float)b;
    cout << "Resenje je"<<x;
    }
    D=pow(b,2)-(4*a*c);
    if(D<0){
        cout << "Resenja su kompleksna";

    }
    else {
    x1=(-b+sqrt(D))/2*(float)a;
    x2=(-b-sqrt(D))/2*(float)a;
    cout << "Imamo dva resenja " << x1 << " " << x2;
    cout <<"det je "<<D; 
    }


    return 0;
}