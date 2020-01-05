#include "struct.h"
using namespace std;

void start_test()
{
    cout<<"Otwieranie bazy... ";
    fstream baza ("baza.txt", ios::in);
    if (baza.fail())  {
        cout<<"Wystapil blad podczas otwierania pliku. Koncze..."<<endl;
        return;
        }
    cout<<"zakonczono."<<endl;
    cout<<"Podaj liczbe pytan: ";
    int pytania; cin>>pytania;
    cout<<"Ladowanie bazy... ";
    int total=0;
    vector<zadanie> tempbaza;
    string temp;
    while (getline(baza, temp)) {
        if (baza.eof())
            break;
        total++;
    }
    cout<<"znaleziono "<<total<<" pytan."<<endl;
    baza.seekg(0);
    baza.clear();
    zadanie zad_temp;
    cout<<"Ladowanie pytan do pamieci...";
    while (getline(baza, temp)) {
        istringstream iss(temp);
        getline(iss,zad_temp.pytanie,';');
        for (auto & i : zad_temp.odpowiedzi)
            getline(iss,i,';');
        iss.get(&zad_temp.prawidlowa, 2, ';');
        cout<<"Wczytano pytanie z pliku...";
        tempbaza.push_back(zad_temp);
        cout<<"wczytano do pamieci."<<endl;
    }
}
