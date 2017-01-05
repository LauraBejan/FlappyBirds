#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
void menu()
{
    cout<<" ______ _               _____  _______     __  ____ _____ _____  _____"<<endl<<
     "|  ____| |        /\\   |  __ \\|  __ \\ \\   / / |  _ \\_   _|  __ \\|  __ \\ "<<endl<<
     "| |__  | |       /  \\  | |__) | |__) \\ \\_/ \/  | |_) || | | |__) | |  | |"<<endl<<
     "|  __| | |      / /\\ \\ |  ___/|  ___/ \\   /   |  _ < | | |  _  /| |  | |"<<endl<<
     "| |    | |____ / ____ \\| |    | |      | |    | |_) || |_| | \\ \\| |__| |"<<endl<<
     "|_|    |______/_/    \\_\\_|    |_|      |_|    |____/_____|_|  \\_\\_____/ "<<endl<<  endl<<endl;







    cout<<"                           ";
    cout<<" __  __  ______  _   _  _    _ "<<endl<<"                           "
        <<"|  \\/  ||  ____|| \\ | || |  | |"<<endl<<"                           "
        <<"| \\  / || |__   |  \\| || |  | |"<<endl<<"                           "
        <<"| |\\/| ||  __|  |     || |  | |"<<endl<<"                           "
        <<"| |  | || |____ | |\\  || |__| |"<<endl<<"                           "
        <<"|_|  |_||______||_| \\_| \\____/ "<<endl;
    cout<<endl<<endl<<endl;
    cout << "To start the game, press any key"<<endl;
    cout<<"To see the highscores, press P"<<endl;
    cout<<"For help, press H"<<endl;

}
int main()
{
   /* cout <<"   _"<<endl<<
           "__(.)>"<<endl<<
           "\___)"<<endl;

    int a=200,//sj
        b=188, //dj
        c=187,//ds
        d=201,//ss
        e=186,//sus
        f=205;//jos
    char a1=char(a),b1=char(b),c1=char(c),d1=char(d),e1=char(e),f1=char(f);
    cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<" "<<e1<<" "<<f1<<endl;
    int i=0;
    cout<<d1;
    while(i++<=70)
        cout<<f1;
    cout<<c1<<endl;
    for(i=0;i<=70;i++)
    {

    }*/
    //joc
    char tastaApasata=' ';
    bool verifica=0;
    int inaltimeMax=20, lungimeMax=60;
    int a=158;
	char a1=char(a);
	string jucator(1,a1);
	a=178;
	a1=char(a);
    string inamic(3,a1);
	string spatiu=" ";

	//jucator
	float velY = 0;
	float vitezaY = 4.0f;
	float max_viteza = 2.0f;//afecteaza saritura
	float gravitate = 0.4f;//afecteaza saritura
	int jucatorY = (inaltimeMax - 1) /2;

	//inamic
	int distantaInamic=10; //distanta obstacole
	int lungimeInamic=lungimeMax/(distantaInamic+inamic.length()-1);
	int *inamicY = new int[lungimeInamic]; //Top of opening of size: openingSize
	int distantaCaleTrecere= 4; // distanta cale trecere
	int inamicSus= 3; //inamic sus
	int inamicJos=inaltimeMax-inamicSus-distantaCaleTrecere; //inamic jos

    //traseu
	double *traseuContor = new double[lungimeInamic];
	double traseuViteza = 0.7;
	int offsetIndex = 0; // face sa apara un singur obstacol intreg

	//timp
	double refreshTimp = 0.0, refreshDurata = 0.35;
	bool apasat = false;
	long timp, timpAnterior;
	timpAnterior = clock();
	timp= clock();
	double timpStart;
	bool start=0;
	double fps = 18.0;
	double convDT = 0.0;
	double timpTotal = 0.0;
	menu();
    return 0;

}
