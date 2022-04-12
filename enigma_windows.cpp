#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void menu();
void add_fraza();
void read_fraza();
string fun(string,int,int);

string wybor_menu;

//

int main()
{
	menu();

	system("pause");
	return 0;
}

void menu()
{
	// menu programu
    system("cls");
    cout << " ------------------------------------------------------------------------------------- " << endl;
    cout << "|                                                                                     |" << endl;
    cout << "|                          Menu programu >> ENIGMA v. 1.0 <<                          |" << endl;
    cout << "|                          ---------------------------------                          |" << endl;
    cout << "|                                                                                     |" << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "|                                                                                     |" << endl;
    cout << "|  1. Zakoduj tekst                                                                   |" << endl;
    cout << "|  2. Rozkoduj tekst                                                                  |" << endl;
    //cout << "|  3. Zmien ustawienia kodowania                                                      |" << endl;
    cout << "|                                                                                     |" << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "|                                                                                     |" << endl;
    cout << "|  0. Wyjscie z programu                                                              |" << endl;
    cout << "|                                                                                     |" << endl;
    cout << " ------------------------------------------------------------------------------------- " << endl;
    cout << "   Twoj wybor ? ";
    cin >> wybor_menu;
    int dlugosc = wybor_menu.length();
    if (dlugosc == 0 || dlugosc > 1)
    {
        cout << endl
             << endl;
        cout << "Prawdopodobnie podales zly parametr, za 2 sekundy ponow probe" << endl
             << endl;
        sleep(2);
        menu();
    }
    if (wybor_menu == "0")
    {
        cout << endl
             << endl;
        cout << "Wychodzisz z programu za 2 sekundy!" << endl
             << endl;
        sleep(2);
        exit(0);
    }
    else if (wybor_menu == "1")
    {
        // menu zakoduj tekst
        add_fraza();
    }
    else if (wybor_menu == "2")
    {
        // menu rozkoduj tekst
        read_fraza();
    }
    //else if (wybor_menu == "3")
    //{
        // menu zmienia ystawienia kodowania
    //}
    else
    {
        cout << endl
             << endl;
        cout << "Wyszedles poza skale, za 2 sekundy mozesz zaczac jeszcze raz" << endl;
        sleep(2);
        menu();
    }
}

void add_fraza()
{
	system("cls");
	string fraza;
	cout<<"Podaj fraze: "<<endl;
	cin.ignore();
	getline(cin, fraza);

	
	int liczba = fraza.length();
	int liczba2 = fraza.length()+1;
	cout<<endl<<endl;

	fun(fraza,liczba,liczba2);
}

string fun(string wyraz,int liczba,int liczba2)
{
	string *tab = new string[liczba2];

	// zamiana na male litery
	transform(wyraz.begin(), wyraz.end(), wyraz.begin(), ::tolower);

	// zapisanie znakow do tablicy
	for(int i=0;i<liczba; i++)
	{
		tab[i]=wyraz[i];
				
	}
	// kodowanie - samogloski	
	for(int i=0;i<liczba;i++)
	{
		if(tab[i]=="a")tab[i]="1050";
		if(tab[i]=="e")tab[i]="1150";
		if(tab[i]=="i")tab[i]="1200";
		if(tab[i]=="o")tab[i]="1250";
		if(tab[i]=="y")tab[i]="1300";
		if(tab[i]=="u")tab[i]="1350";
		if(tab[i]==" ")tab[i]="1001";
	}
	// gloski
	for(int i=0;i<liczba;i++)
	{
		if(tab[i]=="b")tab[i]="1032";
		if(tab[i]=="c")tab[i]="1062";
		if(tab[i]=="d")tab[i]="1124";
		if(tab[i]=="f")tab[i]="1154";
		if(tab[i]=="g")tab[i]="1186";
		if(tab[i]=="h")tab[i]="1216";
		if(tab[i]=="j")tab[i]="1248";
		if(tab[i]=="k")tab[i]="1278";
		if(tab[i]=="l")tab[i]="1308";
		if(tab[i]=="m")tab[i]="1344";
		if(tab[i]=="n")tab[i]="1372";
		if(tab[i]=="p")tab[i]="1402";
		if(tab[i]=="r")tab[i]="1434";
		if(tab[i]=="s")tab[i]="1464";
		if(tab[i]=="t")tab[i]="1496";
		if(tab[i]=="w")tab[i]="1526";
		if(tab[i]=="z")tab[i]="1558";
		if(tab[i]=="q")tab[i]="1588";
		if(tab[i]=="x")tab[i]="1618";
		if(tab[i]=="v")tab[i]="1650";
	}
	//cyfry
	for(int i=0;i<liczba;i++)
	{
		if(tab[i]=="1")tab[i]="1041";
		if(tab[i]=="2")tab[i]="1083";
		if(tab[i]=="3")tab[i]="1125";
		if(tab[i]=="4")tab[i]="1167";
		if(tab[i]=="5")tab[i]="1209";
		if(tab[i]=="6")tab[i]="1241";
		if(tab[i]=="7")tab[i]="1283";
		if(tab[i]=="8")tab[i]="1325";
		if(tab[i]=="9")tab[i]="1367";
		if(tab[i]=="0")tab[i]="1401";
	}
	//znaki specjalne
	for(int i=0;i<liczba;i++)
	{
		if(tab[i]==".")tab[i]="2033";
		if(tab[i]==",")tab[i]="2066";
		if(tab[i]=="?")tab[i]="2099";
		if(tab[i]=="!")tab[i]="2132";
		if(tab[i]=="@")tab[i]="2165";
		if(tab[i]=="%")tab[i]="2198";
		if(tab[i]=="$")tab[i]="2231";
		if(tab[i]=="#")tab[i]="2264";
		if(tab[i]=="+")tab[i]="2297";
		if(tab[i]=="*")tab[i]="2330";
		if(tab[i]=="-")tab[i]="2363";
		if(tab[i]=="/")tab[i]="2396";
		if(tab[i]==":")tab[i]="2429";
		if(tab[i]==";")tab[i]="2462";
		if(tab[i]=="(")tab[i]="2495";
		if(tab[i]==")")tab[i]="2528";
		if(tab[i]=="&")tab[i]="2561";
		if(tab[i]=="_")tab[i]="2594";
	}

	// wypisywanie zawartosci tablicy i zapisywanie do pliku

	cout<<endl<<"Zakodowany tekst: "<<endl;
	for(int i=1;i<liczba;i++)
	{
		cout<<tab[i-1]<<" | ";
		if(i%10==0)cout<<endl;
	}

	//zapis do plku
	cout<<endl<<endl;
	string wybor;
	cout<<"Czy zapisac do plku? (t/n) ";
	cin>>wybor;
	if(wybor=="t"||wybor=="y"||wybor=="T"||wybor=="Y")
	{
		fstream plik;
		plik.open("koder.txt",ios::out);
		for(int o=0;o<liczba;o++)
		{
			plik<<tab[o]<<" | ";
			if(o!=0&&o%10==0)plik<<endl;
		}
		plik.close();
		cout<<endl<<endl;
		cout<<"Plik utworzono, sprawdz zawartosc foldera.";
	}
	else if(wybor=="n"||wybor=="N")
	{
		cout<<endl<<endl;
		cout<<"OK! Za chwile zostaniesz przeniesiony do menu glownego.";
		sleep(3);
		menu();
	}

	cout<<endl<<endl;
	cout<<"Za dwie sekundy zostaniesz przeniesiony do menu";
	sleep(2);
	menu();
	return wyraz;
}

void read_fraza()
{
	//odczyt z pliku
	string nazwa_p;
	string fraza_odczyt;
	fstream plik;
	string tmp_zm;
	string linia;
	string wyb_user;

	system("cls");
	cout<<"Podaj nazwe pliku do odczytu zakodowanej tresci, \n(jesli nic nie zmieniles plik nazywa sie >>koder.txt<<  ? ";
	cin>>nazwa_p;

	plik.open(nazwa_p, ios::in);
	if(plik.good()==false)
	{
		cout<<endl<<endl;
		cout<<"Niestety plik nie istnieje lub nie masz uprawnien do jego otworzenia."<<endl;
		cout<<"Za chwile zostaniesz przeniesiony do menu glownego.";
		sleep(3);
		menu();
	}
		
	//odczyt lini pliku
	while(getline(plik,fraza_odczyt))
	{
		tmp_zm=tmp_zm+fraza_odczyt;
	}
	plik.close();

	
	// zamiana znakow
	for(int i=0;i<tmp_zm.length();i++)
	{
		if(tmp_zm[i]==' '){tmp_zm.replace(i,1,"");}
		if(tmp_zm[i]=='|'){tmp_zm.replace(i,1,"");}
		if(tmp_zm[i]==' '){tmp_zm.replace(i,1,"\n");}
	}

	// zapis do pliku tymczasowego
	plik.open("tmp",ios::out);
	plik<<tmp_zm;
	plik.close();

	//liczenie lini w pliku
	int count = 0;
	ifstream f("tmp");
	while(getline(f,linia))
	{
		count++;
	}
	int k=count+1;

	//tworzenie tablicy odczytu z pliku
	string *tab_odczyt = new string[k];

	// zapis do tablicy rekordow
	ifstream g("tmp");
	int count2=0;
	while(getline(g,linia))
	{
		tab_odczyt[count2]=linia;
		count2++;
	}

	

	// dekodowanie samogloski
	for(int i=0;i<k;i++)
	{
		if(tab_odczyt[i]=="1050")tab_odczyt[i]="a";
		if(tab_odczyt[i]=="1150")tab_odczyt[i]="e";
		if(tab_odczyt[i]=="1200")tab_odczyt[i]="i";
		if(tab_odczyt[i]=="1250")tab_odczyt[i]="o";
		if(tab_odczyt[i]=="1300")tab_odczyt[i]="y";
		if(tab_odczyt[i]=="1350")tab_odczyt[i]="u";
		if(tab_odczyt[i]=="1001")tab_odczyt[i]="__";
	}
	// dekodowanie gloski
	for(int i=0;i<k;i++)
	{
		if(tab_odczyt[i]=="1032")tab_odczyt[i]="b";
		if(tab_odczyt[i]=="1062")tab_odczyt[i]="c";
		if(tab_odczyt[i]=="1124")tab_odczyt[i]="d";
		if(tab_odczyt[i]=="1154")tab_odczyt[i]="f";
		if(tab_odczyt[i]=="1186")tab_odczyt[i]="g";
		if(tab_odczyt[i]=="1216")tab_odczyt[i]="h";
		if(tab_odczyt[i]=="1248")tab_odczyt[i]="j";
		if(tab_odczyt[i]=="1278")tab_odczyt[i]="k";
		if(tab_odczyt[i]=="1308")tab_odczyt[i]="l";
		if(tab_odczyt[i]=="1344")tab_odczyt[i]="m";
		if(tab_odczyt[i]=="1372")tab_odczyt[i]="n";
		if(tab_odczyt[i]=="1402")tab_odczyt[i]="p";
		if(tab_odczyt[i]=="1434")tab_odczyt[i]="r";
		if(tab_odczyt[i]=="1464")tab_odczyt[i]="s";
		if(tab_odczyt[i]=="1496")tab_odczyt[i]="t";
		if(tab_odczyt[i]=="1526")tab_odczyt[i]="w";
		if(tab_odczyt[i]=="1558")tab_odczyt[i]="z";
		if(tab_odczyt[i]=="1588")tab_odczyt[i]="q";
		if(tab_odczyt[i]=="1618")tab_odczyt[i]="x";
		if(tab_odczyt[i]=="1650")tab_odczyt[i]="v";
	}
	//cyfry
	for(int i=0;i<k;i++)
	{
		if(tab_odczyt[i]=="1041")tab_odczyt[i]="1";
		if(tab_odczyt[i]=="1083")tab_odczyt[i]="2";
		if(tab_odczyt[i]=="1125")tab_odczyt[i]="3";
		if(tab_odczyt[i]=="1167")tab_odczyt[i]="4";
		if(tab_odczyt[i]=="1209")tab_odczyt[i]="5";
		if(tab_odczyt[i]=="1241")tab_odczyt[i]="6";
		if(tab_odczyt[i]=="1283")tab_odczyt[i]="7";
		if(tab_odczyt[i]=="1325")tab_odczyt[i]="6";
		if(tab_odczyt[i]=="1367")tab_odczyt[i]="9";
		if(tab_odczyt[i]=="1401")tab_odczyt[i]="0";
	}
	//znaki specjalne
	for(int i=0;i<k;i++)
	{
		if(tab_odczyt[i]=="2033")tab_odczyt[i]=",";
		if(tab_odczyt[i]=="2066")tab_odczyt[i]=",";
		if(tab_odczyt[i]=="2099")tab_odczyt[i]="?";
		if(tab_odczyt[i]=="2132")tab_odczyt[i]="!";
		if(tab_odczyt[i]=="2165")tab_odczyt[i]="@";
		if(tab_odczyt[i]=="2198")tab_odczyt[i]="%";
		if(tab_odczyt[i]=="2231")tab_odczyt[i]="$";
		if(tab_odczyt[i]=="2264")tab_odczyt[i]="#";
		if(tab_odczyt[i]=="2297")tab_odczyt[i]="+";
		if(tab_odczyt[i]=="2330")tab_odczyt[i]="*";
		if(tab_odczyt[i]=="2363")tab_odczyt[i]="-";
		if(tab_odczyt[i]=="2396")tab_odczyt[i]="/";
		if(tab_odczyt[i]=="2429")tab_odczyt[i]=":";
		if(tab_odczyt[i]=="2462")tab_odczyt[i]=";";
		if(tab_odczyt[i]=="2495")tab_odczyt[i]="(";
		if(tab_odczyt[i]=="2528")tab_odczyt[i]=")";
		if(tab_odczyt[i]=="2561")tab_odczyt[i]="&";
		if(tab_odczyt[i]=="2594")tab_odczyt[i]="_";
	}

	cout<<endl<<endl;

	// odczyt listy
	for(int i=0;i<count;i++)
		cout<<tab_odczyt[i]<<" ";

	cout<<endl<<endl;
	cout<<"Czy zapisac do pliku?   (t/n)";
	cin>>wyb_user;

	if(wyb_user=="t"||wyb_user=="y"||wyb_user=="T"||wyb_user=="Y")
	{
		// zapisanie do pliku odkodowanego tekstu
		fstream plik2;
		plik2.open("dekoding.txt",ios::out);
		for(int i=0;i<count;i++)
		{
			plik2<<tab_odczyt[i]<<" ";
			cout<<tab_odczyt[i]<<" ";
		}
		plik2.close();
		cout<<endl<<endl;
		cout<<"Plik zostal zapisany i nosi nazwe >>dekoding.txt<<"<<endl;
		cout<<"za 3 sekundy wrocisz do glownego menu."<<endl<<endl;
		sleep(3);
		menu();
	}
	else
	{
		cout<<endl<<endl;
		cout<<"Co chcesz zrobic?"<<endl;
		cout<<"   1. powrot do menu"<<endl;
		cout<<"   2. koniec programu"<<endl;
		cout<<"?";cin>>wyb_user;
		if(wyb_user=="1"){menu();}
		else if(wyb_user=="2"){exit(0);}
		else {exit(0);}
	}
}   