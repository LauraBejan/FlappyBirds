#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<iomanip>
#include<fstream>
using namespace std;
ofstream g("nrr.out");
void startJoc();
struct lista{
            int info, timp;
            lista*urm;
            }*prim,*ultim;
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
    int contor=0;
    lista *p=prim;
    cout<<"                            "<<++contor<<". Scor:"<<p->info<<" Timp:"<<p->timp<<endl;
    while(p->urm!=NULL)
        {
            p=p->urm;
            cout<<"                            "<<++contor<<". Scor:"<<p->info<<" Timp:"<<p->timp<<endl;
        }

}
void unElement(int score, float time)
{

        lista *p=new lista;
        p->urm=NULL;
        p->info=score;
        p->timp=time;
        if(prim->info>score)
        {g<<"OK";
            ultim=p;
            prim->urm=ultim;
        }
        else if(prim->info<score)
            {
                 p->urm=prim;
                 ultim=prim;
                 prim=p;
            }
            else    if(prim->timp>time)
                    {
                        p->urm=prim;
                        ultim=prim;
                        prim=p;
                    }
                    else   {
                            ultim->urm=p;
                            ultim=ultim->urm;
                            }
        return;


}
void generateHighscoresList(int score, float time)
{
    if(prim==NULL)
    {
        prim=new lista;
        prim->info=score;
        prim->timp=time;
        prim->urm=NULL;
        ultim=prim;
        return;
    }
    if(prim->urm==NULL)
        {
            unElement(score,time);
            return;
        }
    lista *p=prim;
    int ok=0;
    if(p->info<score)
        {
            unElement(score,time);
            return;
        }

    while(p->urm->info>score && p->urm!=NULL)
            p=p->urm;
    int auxScore=p->urm->info;
    if(p->urm->info==auxScore && p->urm->timp>time && p==prim)
    {
        unElement(score,time);
        return;
    }
    while(p->urm->info==auxScore && p->urm!=NULL)
        if(p->urm->timp>time)
    {
        lista *aux=new lista;
        aux->urm=p->urm;
        aux->info=score;
        aux->timp=time;
        p->urm=aux;
        return;
    }
        else p=p->urm;

    lista *aux=new lista;
    aux->urm=p->urm;
    aux->info=score;
    aux->timp=time;
    p->urm=aux;
    //lista *p=prim;
    //highscores();

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
void gameOver(int score,float timp)
{
    generateHighscoresList(score,timp);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                       ";
    cout<<"Your score is: "<< score<<endl;
    cout<<"                       "<<"To go back to main menu, press M"<<endl;
    cout<<"                       "<<"To play again, press S"<<endl;
    cout<<"                       "<<"To see the highscores, press P"<<endl;
}
void startJoc()
{
    int score=0;
    // design
    int a=158;
    char a1=char(a);
	string jucatorImag(1,a1);
	a=178;
	a1=char(a);
    string inamicImag(3,a1);// = "!!!";
    int inaltimeMax=20, latimeMax=60;


    //timp
    float timpStart, timpStop, timpAfisare;
    float updateLogic=0;
    int fps=12;
    float timp=clock(), timpAnterior=clock();

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

    //joc
    bool aApasat=kbhit();
    tastaApasata=' ';
    tastaApasata=getch();
    while(tastaApasata!='q')
    {
        if(aInceput==false)
        {
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
            cout<<"Time:"<<timpAfisare<<" Score:"<<score/3<<endl;
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
                        score=score+1-1;//cout<<"hit";
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
