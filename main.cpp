//Chiedi una stringa all'utente e chiedi quali 
//carattari trasformare in maiuscolo o minuscolo

#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

//prototipi 
void clearScreen();
int menu();
void Inserimento( string &str, bool &chek);
void maiuscolo(string str,bool chek);
void minuscolo(string str, bool chek);
void singolocarattere(string str, bool chek);

int main(){

    int s;
    bool chek = false;
    string str;
    
    do{

        clearScreen();

        s = menu();

        switch(s){

            case 1:{
                Inserimento(str,chek);
                break;
            }

            case 2:{
                maiuscolo(str,chek);
                break;
            }

            case 3:{
                minuscolo(str, chek);
                break;
            }

            case 4:{
                singolocarattere(str, chek);
                break;
            }

            case 0:{
                cout<<"Arrivederci"<<endl;
                break;
            }

            default:{
                cout<<"Scelta non valida"<<endl;
                break;
            }

        }

    }while(s != 0);

    return 0;
}


void clearScreen() {
    // Utilizza il carattere di escape ANSI per pulire la console
    cout << "\033[2J\033[H";
}




int menu(){

    int scelta;

    cout<<"\t ---MENU---"<<endl;
    cout<<"1. Inserisci una stringa"<<endl;
    cout<<"2. Trasforma la stringa in maiuscolo"<<endl;
    cout<<"3. Trasforma la stringa in minuscolo"<<endl;
    cout<<"4. Trasforma solo un carattere"<<endl;
    cout<<"0. Esci"<<endl;

    cout<<endl;

    cout<<"Inserisci un numero: ";
    cin>>scelta;

    cin.ignore();
    return scelta;
}


void Inserimento( string &str, bool &chek){

    cout<<"Inserisci una stringa: ";
    getline(cin,str);

    chek=true;

    cout<<"Premi qualsiasi tasto per continuare...";
    cin.ignore();
    cin.get();

}


void maiuscolo(string str,bool chek){

    if(chek==true){
        for(int i = 0; i < str.length(); i++){
            str[i] = toupper(str[i]);
        }

        cout<<str<<endl;
    }else{
        cout<<"Inserisci prima una stringa"<<endl;
    }

    cout<<"Premi qualsiasi tasto per continuare...";
    cin.ignore();
    cin.get();
}


void minuscolo(string str,bool chek){

    if(chek==true){
        for(int i = 0; i < str.length(); i++){
            str[i] = tolower(str[i]);
        }

        cout<<str<<endl;
    }
    else{
        cout<<"Inserisci prima una stringa"<<endl;
    }

    

    cout<<"Premi qualsiasi tasto per continuare...";
    cin.ignore();
    cin.get();
}


void singolocarattere(string str,bool chek){

    int x,y;

    if(chek==true){

        cout<<"\t "<<str<<endl;

        cout<<endl;

        do{
            cout<<"Inserisci il numero del carattere da modificare: ";
            cin>>x;

            if(x<=0 || x > str.length()){
                cout<<"Numero non valido"<<endl;
            }

            cout<<endl;

        }while(x<=0 || x > str.length());

        cout<<" Vuoi che il carattere "<<str[x-1]<<" venga trasformato in minuscolo o maiuscolo? "<<endl;
        cout<<"1. Maiuscolo"<<endl;
        cout<<"2. Minuscolo"<<endl;

        cout<<endl;

        do{
            cout<<"Inserisci un numero: ";
            cin>>y;

            if(y!=1 && y!=2){
                cout<<"Numero non valido"<<endl;
            }

        }while(y!=1 && y!=2);

        if(y==1){
            str[x-1] = toupper(str[x-1]);
        }
        else{
            str[x-1] = tolower(str[x-1]);
        }

        cout<<str<<endl;
    }
    else{
        cout<<"Inserisci prima una stringa"<<endl;
    }

    cout<<"Premi qualsiasi tasto per continuare...";
    cin.ignore();
    cin.get();

}