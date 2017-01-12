#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include"leaderboard.h"
using namespace std;
ofstream g("nrr.out");
void startJoc();
bool gamePlayed;
void menu()
{
    cout<<"     ______ _               _____  _______     __  ____ _____ _____  _____"<<endl<<
     "    |  ____| |        /\\   |  __ \\|  __ \\ \\   / / |  _ \\_   _|  __ \\|  __ \\ "<<endl<<
     "    | |__  | |       /  \\  | |__) | |__) \\ \\_/ \/  | |_) || | | |__) | |  | |"<<endl<<
     "    |  __| | |      / /\\ \\ |  ___/|  ___/ \\   /   |  _ < | | |  _  /| |  | |"<<endl<<
     "    | |    | |____ / ____ \\| |    | |      | |    | |_) || |_| | \\ \\| |__| |"<<endl<<
     "    |_|    |______/_/    \\_\\_|    |_|      |_|    |____/_____|_|  \\_\\_____/ "<<endl<<  endl<<endl;







    cout<<"                           ";
    cout<<" __  __  ______  _   _  _    _ "<<endl<<"                           "
        <<"|  \\/  ||  ____|| \\ | || |  | |"<<endl<<"                           "
        <<"| \\  / || |__   |  \\| || |  | |"<<endl<<"                           "
        <<"| |\\/| ||  __|  |     || |  | |"<<endl<<"                           "
        <<"| |  | || |____ | |\\  || |__| |"<<endl<<"                           "
        <<"|_|  |_||______||_| \\_| \\____/ "<<endl;
    cout<<endl<<endl<<endl;
    cout<<"  To start the game, press S"<<endl;
    cout<<"  To see the highscores, press P"<<endl;
    cout<<"  To go back to the menu, press M"<<endl;

}
void highscores()
{
    cout<< "   _                       _              _                             _"<<endl<<
           "  | |                     | |            | |                           | | "<<endl<<
           "  | |      ___   __ _   __| |  ___  _ __ | |__    ___    __ _  _ __  __| | "<<endl<<
           "  | |     / _ \\ / _` | / _` | / _ \\| '__|| '_ \\  / _ \\  / _` || '__|/ _` | "<<endl<<
           "  | |____|  __/| (_| || (_| ||  __/| |   | |_) || (_) || (_| || |  | (_| | "<<endl<<
           "  |______|\\___| \\__,_| \\__,_| \\___||_|   |____/  \\___/  \\__,_||_|   \\__,_| "<<endl<<endl;


    int contor=0;
    lista *p=prim;
    if(gamePlayed)
    {
        cout<<"                            "<<++contor<<". Scor:"<<p->info<<" Timp:"<<p->timp<<endl;
        while(p->urm!=NULL)
        {
            p=p->urm;
            cout<<"                            "<<++contor<<". Scor:"<<p->info<<" Timp:"<<p->timp<<endl;
        }
    }
}

void help()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                      ";
    int timp=clock();

    cout<<"Press S to jump and Q to quit"<<endl;
    cout<<"                      "<<"To start, double press any key";
  //  while(!kbhit());
   // system("cls");
    //startJoc();

}
void gameOver(int score,float timp)
{
    listaInsertie(score,timp);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                       ";
    cout<<"Your score is: "<< score<<endl;
    cout<<"                       "<<"To go back to main menu, press M"<<endl;
    cout<<"                       "<<"To play again, press S"<<endl;
    cout<<"                       "<<"To see the highscores, press P"<<endl;
}
void startJoc()
{//<<endl<<
    int score=0;
    // design
    int a=158;
    char a1=char(a);
	string jucatorImag(1,a1);
	a=178;
	a1=char(a);
    string inamicImag(3,a1);// = "!!!";
    int inaltimeMax=20, latimeMax=60;
    a=3;
    a1=char(a);
    string viataImag(3,a1);

    //timp
    float timpStart, timpStop, timpAfisare;
    float updateLogic=0;
    int fps=12;
    float timp=clock(), timpAnterior=clock();
    float timpLovitInamic=0, timpLovitInamicStart;

    //fizica
    float velInaltime=0, vitezaInaltime=4.0f, vitezaMax=2.0f, gravitate=0.4f;

    //inamic
    int inamicInaltimeMin=3, distantaSusJos=4;
    int distantaInamic=8;
    int inamicInaltimeMax=inaltimeMax-distantaSusJos-inamicInaltimeMin;
    int nrInamiciSerie=latimeMax/(distantaInamic+inamicImag.length()-1), lungimeInamc=inamicImag.length();
    float *inaltimeInamic=new float[nrInamiciSerie];

    //logica
    bool verificaApasareTasta=kbhit(),aInceput=false;
    char tastaApasata=getch();

    //traseu
    double *scrollIndex = new double[nrInamiciSerie];
	double scrollSpeed = 1;
	int eroareIndex = 0;
	string drum=".";

    //jucator
    int jucatorPozInaltime=(inaltimeMax-1)/2;
    int jucatorPozLatime;

    //vieti
    int life=0,nrInima;
    //joc
    bool aApasat=kbhit();
    tastaApasata=' ';
    tastaApasata=getch();
    while(tastaApasata!='q')
    {
        if(aInceput==false)
        {
            gamePlayed=1;
            timpStart=clock()/1000;
            //timpStop=clock();
            aInceput=true;  //cout<<timpStart<<" "<<timpActual<<endl;
            for(int i=0;i<nrInamiciSerie;i++)
                {
                    inaltimeInamic[i]=(int)(((double)rand() / RAND_MAX) * (double)(inamicInaltimeMax -inamicInaltimeMin)) +inamicInaltimeMin;
                    scrollIndex[i]=latimeMax;
                }
            for(int i=0;i<nrInamiciSerie;i++)
                g<<inaltimeInamic[i]<<"h";
            g<<endl;
        }
        if(life==9)
            break;
       // tastaApasata=getch();
        float deltaTime=timpAnterior-timp;
        timp=clock();
        updateLogic+=deltaTime/(1000/fps);
        if(updateLogic>=1)
        {
            updateLogic--;
            string output="";
            system("cls");
            timpAfisare=clock()/1000-timpStart;
            cout<<"Time:"<<timpAfisare<<" Score:"<<score/3<<" Life:"<< viataImag<<endl;
            if(tastaApasata=='q')// && !aApasat)
            {
                system("cls");  //clear screen
                gameOver(score/3,timpAfisare);
                break;
            }
            if(tastaApasata=='s')// && !aApasat)
                {
                    velInaltime-=vitezaInaltime;
                    aApasat=true;
                }

            velInaltime+=gravitate;

            if(velInaltime<-vitezaMax*0.666)
                velInaltime=-vitezaMax*0.666;
            else
                if(velInaltime>vitezaMax)
                    velInaltime=vitezaMax;

            jucatorPozInaltime+=(int)velInaltime;

            if(jucatorPozInaltime<0)
                jucatorPozInaltime=0;
            else
                if(jucatorPozInaltime>inaltimeMax-1)
                    jucatorPozInaltime=inaltimeMax-1;
            //inamic

            for(int i=0;i<nrInamiciSerie;i++)
            {
                if(eroareIndex>=i)
                    scrollIndex[i]-=scrollSpeed;
                else
                    if(scrollIndex[i-1]<=latimeMax-distantaInamic-1)
                        eroareIndex++;
                int k=-(int)inamicImag.length()+1;
                if(scrollIndex[i]<=k)
                {
                    scrollIndex[i]=latimeMax;
                    inaltimeInamic[i]=(int)(((double)rand() / RAND_MAX) * (double)(inamicInaltimeMax -inamicInaltimeMin)) +inamicInaltimeMin;
                    g<<inaltimeInamic[i]<<" ";
                }
            }

            //vieti
            for(int i=0;i<nrInamiciSerie;i++)
                if(scrollIndex[i]<=latimeMax/4 && scrollIndex[i]>latimeMax/4-inamicImag.length())
                    if(jucatorPozInaltime<inaltimeInamic[i] || jucatorPozInaltime>=inaltimeInamic[i]+ distantaSusJos)
                        {
                            life++;//cout<<"hit";
                            nrInima=life/3;
                            viataImag[viataImag.length()-nrInima]=NULL;
                        }
                    else score++;

            //grafica
            int k=0;
            for(int i=0;i<inaltimeMax;i++)
                {
                for(int j=0;j<latimeMax;j++)
                    {
                        bool ok=false;

                        for(int k=0;k<nrInamiciSerie;k++)
                            if(j==(int)scrollIndex[k]&& j<=latimeMax-inamicImag.length())
                                if(i<inaltimeInamic[k] || i>=inaltimeInamic[k]+distantaSusJos)
                                {
                                    output+=inamicImag;
                                    j+=inamicImag.length()-1;
                                    k=nrInamiciSerie;
                                   // k++;
                                    //if(k==nrInamiciSerie)
                                      //  k=0;
                                    ok=false;
                                }
                                else
                                    //{
                                        ok=true;
                                   // output+=drum;}
                            else ok=true;
                        if(ok)
                            output+=drum;
                        // else output+=inamicImag;
                    }
                output+="\n";
                }
                int pozitieJucator;
                pozitieJucator=jucatorPozInaltime*(latimeMax+1)+latimeMax/4;
                output.replace(pozitieJucator,1,jucatorImag);
                output+="\n";
                cout << output;
                //aApasat=kbhit();
                if (kbhit())
                    tastaApasata = getch();

                else
                    tastaApasata= ' ';

        }
        timpAnterior=clock();

    }
    system("cls");  //clear screen
    gameOver(score/3,timpAfisare);

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
   //tabel=new lista;
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
                     //   lista *k=prim;
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
