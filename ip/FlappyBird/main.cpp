#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;
void startJoc();
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
    cout << "To start the game, press S"<<endl;
    cout<<"To see the highscores, press P"<<endl;
    cout<<"For help, press H"<<endl;
    cout<<"To go back to the menu, press M"<<endl;

}
void highscores()
{
    cout<<"tabel";
}

void help()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                      ";
    int timp=clock();

    cout<<"Press S to jump and Q to quit"<<endl;
    cout<<"                         "<<"To start, press any key";
    while(!kbhit());
    system("cls");
    //startJoc();

}
void gameOver(int score)
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                       ";
    cout<<"Your score is: "<< score<<endl;
    cout<<"                       "<<"To go back to main menu, press M"<<endl;
    cout<<"                       "<<"To play again, press S"<<endl;
    cout<<"                       "<<"To see the highscores, press P"<<endl;
}
void startJoc()
{cout<<"joc";
    int score=0;
    // design
    int a=158;
    char a1=char(a);
	string jucatorImag(1,a1);
	a=178;
	a1=char(a);
    string inamicImag(3,a1);// = "!!!";
    int inaltimeMax=20, latimeMax=60;
    int jucatorPozInaltime=inaltimeMax/2, jucatorPozLatime;


    //timp
    float timpStart, timpStop;

    //fizica
    float velInaltime=0, vitezaInaltime=4.0f, vitezaMax=2.0f, gravitate=0.4f;

    //inamic
    int inamicInaltimeMin=3, distantaSusJos=4;
    int inamicInaltimeMax=inaltimeMax-distantaSusJos-inamicInaltimeMin;
    int nrInamiciSerie=5, lungimeInamc=inamicImag.length();
    float *inaltimeInamic=new float[nrInamiciSerie];
    //logica
    bool verificaApasareTasta=kbhit(),aInceput=false;
    char tastaApasata=getch();

    //traseu
    double *scrollIndex = new double[nrInamiciSerie];
	double scrollSpeed = 1;
	int eroareIndex = 0;

    //joc

    while(tastaApasata!='q')
    {
        if(aInceput==false)
        {
            timpStart=clock();
            timpStop=clock();
            aInceput=true;  //cout<<timpStart<<" "<<timpActual<<endl;
            for(int i=0;i<nrInamiciSerie;i++)
                {
                    inaltimeInamic[i]=(float)(rand()%10/5);
                    scrollIndex[i]=inaltimeMax;
                }
        }
        tastaApasata=getch();

        if(tastaApasata=='q')
            {
                system("cls");  //clear screen
                gameOver(score);
                break;
            }
        if(tastaApasata=='w')
            velInaltime-=vitezaInaltime;

        velInaltime+=gravitate;

        if(velInaltime>vitezaMax)
            velInaltime=vitezaMax;
        else
            if(velInaltime<-vitezaMax*0.666)
                velInaltime=-vitezaMax*0.666;

        jucatorPozInaltime+=velInaltime;

        if(jucatorPozInaltime<0)
            jucatorPozInaltime=0;
        else
            if(jucatorPozInaltime>inaltimeMax-1)
                jucatorPozInaltime=inaltimeMax-1;
    }
    system("cls");  //clear screen
    gameOver(score);

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

	menu();
	char tastaApasata=getch();
	do{

        switch(tastaApasata)
        {
            case 's':   system("cls");  //clear screen
                        help();
                        startJoc();
                        break;
            case 'p':   system("cls");  //clear screen
                        highscores();
                        break;
            case 'm':   system("cls");  //clear screen
                        menu();
                        break;
        }
        tastaApasata=getch();
    }   while(tastaApasata!='q');
    return 0;

}
