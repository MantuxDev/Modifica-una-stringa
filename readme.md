# Modifica una stringa

Semplice programma in c++ che prende in input una stringa e la modifica in base alla scelta dell'utente, la stringa può essere modificata nei seguenti modi:

1. Trasforma la stringa tutta in maiuscolo
1. Trasforma la stringa tutta in minusclo
1. Trasforma un singolo carattere della stringa in maiuscolo o miniscolo

---

## Spiegazione del codice

Il programma mostra inizialmente un menù dove l'utente decide cosa effettuare

```c++
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
```

in base alla scelta dell'utente viene eseguita una procedura attraverso uno switch nell' int main

```c++
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
```

---

## Inserimento

```c++
void Inserimento( string &str, bool &chek){

    cout<<"Inserisci una stringa: ";
    getline(cin,str);

    chek=true;

    cout<<"Premi qualsiasi tasto per continuare...";
    cin.ignore();
    cin.get();

}
```

la procedura inserimento richiede all'utente di inserire una stringa in input, l'input viene preso con l' istruzione ` getline(cin,str) `, l'istruzione getline ci permettere di prendere in input un intera linea, quindi  ti poter prendere stringhe che presentano anche degli spazi.

esempio:

```c++
cout<<"Inserisci una stringa: ";
cin>>str;

cout<<str<<endl;
```

Se la stringa in input è  `Ciao sono Raffaele` l' output della stringa sarà solo `Ciao`

Mentre utilizzando l'istruzione `getline`, prendiamo in input tutta la riga che scrive l'utente in input

```c++
cout<<"Inserisci una stringa: ";
getline(cin;str);
//stringa in input -> Ciao sono Raffaele

cout<<str<<endl;
//output -> Ciao sono Raffaele
```

Ho utilizzato anche una variabile `chek` di tipo booleano inizializzata con valore `false`,  quando l'utente inserisce la stringa la varibile assume valore `true`, questa variabile mi serve perchè se l'utente inserisce altre voci nel menù prima di aver inserito la stringa in input, stampa all'utente un messaggio di errore.

---

## Modifica la stringa in maiuscolo

```c++
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
```

Attraverso la variabile booleana citata prima, verifichiamo se l'utente ha prima inserito la stringa in input, se la condizione è vera, attraverso la funzione `.length()` vediamo la lunghezza della stringa escluso il carattere `null`, questo ci serve per poter accedere a ogni carattere della stringa e attraverso la funzione `toupper` trasformiamo ogni carattere della stringa in maiuscolo

---

## Modifica la stringa in minuscolo

Applichiamo lo stesso concetto che abbimo utilizzato per trasfomare tutta la stringa in minuscolo, solo che al posto di utilizzare la funzione `toupper`, utilizziamo la funzione `tolower` che ci permette di rendere ogni carattere minuscolo

```c++
for(int i = 0; i < str.length(); i++){
    str[i] = tolower(str[i]);
}

cout<<str<<endl;
    
```

---

## Modificare un singolo carattere

```c++
do{
    cout<<"Inserisci il numero del carattere da modificare: ";
    cin>>x;

    if(x<=0 || x > str.length()){
        cout<<"Numero non valido"<<endl;
    }

    cout<<endl;

}while(x<=0 || x > str.length());
```

Chiediamo all'utente quale carattere della stringa vuole modificare.

```c++
cout<<" Vuoi che il carattere "<<str[x-1]<<" venga trasformato in minuscolo o maiuscolo? "<<endl;
cout<<"1. Maiuscolo"<<endl;
cout<<"2. Minuscolo"<<endl;
```

Sucessivamente chiediamo se il carattere deve essere deve essere trasformato in maiuscolo o minuscolo.

Effetuiamo la verifica sulla scelta dell'utente

```c++
do{
    cout<<"Inserisci un numero: ";
    cin>>y;

    if(y!=1 && y!=2){
        cout<<"Numero non valido"<<endl;
    }

}while(y!=1 && y!=2);
```

Infine modifichiamo il carattere scelto dall'utente in base alle sue scelte

```c++
if(y==1){
    str[x-1] = toupper(str[x-1]);
}
else{
    str[x-1] = tolower(str[x-1]);
}
```
