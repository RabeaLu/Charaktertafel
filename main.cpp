#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Charaktertafel{ // int i verwendet für Zeilennummer, int j verwendet für Spaltennummer
private:
    int Ordnung;
    string Punktrguppe;
public:
    Charaktertafel(int h=10, string p=""):Ordnung(h), Punktrguppe(p) {Tafel.resize(h, vector<int>(h));}//KONSTRUKTOR ÄNDERT DIMENSIONEN DES VEKTORS AUF GRUPPENORDNUNG
    vector< vector<int> > Tafel;//VEKTOR SPEICHERT DIE CHARAKTERE
    void get_Tafel();
    vector<int> Addition(int ersteZeile, int zweiteZeile);
    vector<int> Multiplikation(int ersteZeile, int zweiteZeile);
};
//FUNKTION UM TAFEL AUSZUGEBEN
void Charaktertafel::get_Tafel(){
    cout << "Punktgruppe: " << Punktrguppe << endl;
     cout << "Ordnung: " << Ordnung << endl;
    for(int i=0; i<Ordnung;i++){
        for(int j=0; j<Ordnung; j++){
            if(Tafel[i][j]<0){
                cout << Tafel[i][j] << " ";
            }
            else {
                cout << " " << Tafel[i][j] << " ";
            }
        }
        cout << endl;
    }
}
//FUNKTION UM ZEILEN ZU ADDIEREN
vector<int> Charaktertafel::Addition(int ersteZeile, int zweiteZeile){
    vector<int> AdditionErgebnis (Ordnung);
    for(int j=0;j<Ordnung;j++){ // Schleife zum Berechnen der Vektorelemente
        AdditionErgebnis[j] = Tafel[ersteZeile][j]+Tafel[zweiteZeile][j];
    }
    cout << "Zeile " << ersteZeile << " + Zeile " << zweiteZeile << endl;
    for(int j=0;j<Ordnung;j++){ //Schleife um Ausgeben des Vektors
        if(AdditionErgebnis[j]<0){ cout << AdditionErgebnis[j] << " ";}
        else {cout << " " << AdditionErgebnis[j] << " "; }
    }
    cout << endl;
    return AdditionErgebnis;
}
//FUNKTION UM ZEILEN ZU MULTIPLIZIEREN
vector<int> Charaktertafel::Multiplikation(int ersteZeile, int zweiteZeile){
    vector<int> MultiplikationErgebnis (Ordnung);
    for(int j=0;j<Ordnung;j++){ // Schleife zum Berechnen der Vektorelemente
        MultiplikationErgebnis[j] = Tafel[ersteZeile][j]*Tafel[zweiteZeile][j];
    }
    cout << "Zeile " << ersteZeile << " * Zeile " << zweiteZeile << endl;
    for(int j=0;j<Ordnung;j++){ //Schleife um Ausgeben des Vektors
        if(MultiplikationErgebnis[j]<0){ cout << MultiplikationErgebnis[j] << " ";}
        else {cout << " " << MultiplikationErgebnis[j] << " "; }
    }
    cout << endl;
    return MultiplikationErgebnis;
}


int main()
{
    //+++++++++CARAKTERTAFELN DER PUNKTGRUPPEN+++++++++++++
    Charaktertafel C2v(4, "C2v");
    C2v.Tafel[0][0]= 1; C2v.Tafel[0][1]= 1; C2v.Tafel[0][2]= 1; C2v.Tafel[0][3]= 1;
    C2v.Tafel[1][0]= 1; C2v.Tafel[1][1]= 1; C2v.Tafel[1][2]=-1; C2v.Tafel[1][3]=-1;
    C2v.Tafel[2][0]= 1; C2v.Tafel[2][1]=-1; C2v.Tafel[2][2]= 1; C2v.Tafel[2][3]=-1;
    C2v.Tafel[3][0]= 1; C2v.Tafel[3][1]=-1; C2v.Tafel[3][2]=-1; C2v.Tafel[3][3]= 1;

    C2v.get_Tafel();
    C2v.Addition(0,2);
    C2v.Multiplikation(0,2);


    return 0;
}
