#include "librarii.h"
#include "leaderboard.h"

using namespace std;
void startJoc();
bool gamePlayed;
void menu()
{
    cout<<"     ______ _               _____  _______     __  ____ _____ _____  _____"<<endl<<
     "    |  ____| |        /\\   |  __ \\|  __ \\ \\   / / |  _ \\_   _|  __ \\|  __ \\ "<<endl<<
     "    | |__  | |       /  \\  | |__) | |__) \\ \\_/ /  | |_) || | | |__) | |  | |"<<endl<<
     "    |  __| | |      / /\\ \\ |  ___/|  ___/ \\   /   |  _ < | | |  _  /| |  | |"<<endl<<
     "    | |    | |____ / ____ \\| |    | |      | |    | |_) || |_| | \\ \\| |__| |"<<endl<<
     "    |_|    |______/_/    \\_\\_|    |_|      |_|    |____/_____|_|  \\_\\_____/ "<<endl<<  endl<<endl;







    cout<<"                         ";
    cout<<" __  __  ______  _   _  _    _ "<<endl<<"                         "
        <<"|  \\/  ||  ____|| \\ | || |  | |"<<endl<<"                         "
        <<"| \\  / || |__   |  \\| || |  | |"<<endl<<"                         "
        <<"| |\\/| ||  __|  |     || |  | |"<<endl<<"                         "
        <<"| |  | || |____ | |\\  || |__| |"<<endl<<"                         "
        <<"|_|  |_||______||_| \\_| \\____/ "<<endl<<endl;
    for(int i=0;i<80;i++)
        cout<<(char)205;
    cout<<endl<<endl;
    cout<<"                           To start the game, press S"<<endl;
    cout<<"                          To see the highscores, press P"<<endl;
    cout<<"                          To go back to the menu, press M"<<endl;

}
void highscores()
{
    cout<< "   _                       _              _                             _"<<endl<<
           "  | |                     | |            | |                           | | "<<endl<<
           "  | |      ___   __ _   __| |  ___  _ __ | |__    ___    __ _  _ __  __| | "<<endl<<
           "  | |     / _ \\ / _` | / _` | / _ \\| '__|| '_ \\  / _ \\  / _` || '__|/ _` | "<<endl<<
           "  | |____|  __/| (_| || (_| ||  __/| |   | |_) || (_) || (_| || |  | (_| | "<<endl<<
           "  |______|\\___| \\__,_| \\__,_| \\___||_|   |____/  \\___/  \\__,_||_|   \\__,_| "<<endl<<endl;

    cout<<endl<<endl;
    int contor=0;
    lista *p=prim;
    if(gamePlayed)
    {
        cout<<"                            "<<++contor<<". Score:"<<p->info<<" Time:"<<p->timp<<endl;
        while(p->urm!=NULL)
        {
            p=p->urm;
            cout<<"                            "<<++contor<<". Score:"<<p->info<<" Time:"<<p->timp<<endl;
        }
    }
}

void help()
{
    cout<<endl<<endl<<endl<<endl;

    int timp=clock();
    cout<<"                          _    _        _"<<endl<<
          "                         | |  | |      | |"<<endl<<
          "                         | |__| |  ___ | | _ __"<<endl<<
          "                         |  __  | / _ \\| || '_ \\ "<<endl<<
          "                         | |  | ||  __/| || |_) |"<<endl<<
          "                         |_|  |_| \\___||_|| .__/ "<<endl<<
          "                                          | |"<<endl<<
          "                                          |_|"<<endl<<endl;
    cout<<"                      ";
    cout<<"Press S to jump and Q to quit"<<endl;
    cout<<"         "<<"Be careful to not hit the walls as you only have 3 lives"<<endl;
    cout<<"    "<<"Your score will get a bonus every 3, 6, 9... seconds spent hitting no walls"<<endl;
    cout<<endl<<"                      "<<"To start, double press any key";


}
void gameOver(int score,float timp)
{
    listaInsertie(score,timp);
     cout<<endl<<endl;
    cout<<"       _____           __  __ ______    ______      ________ _____"<<endl<<
            "      / ____|    /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\"<<endl<<
            "      | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |"<<endl<<
            "      | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /"<<endl<<
            "      | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \ \\\\"<<endl<<
            "       \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|   \\_\\"<<endl;
    cout<<endl;
    for(int i=0;i<80;i++)
        cout<<(char)205;
    cout<<endl<<endl<<endl;
    cout<<"                               "<<"Your score is: "<< score<<endl;
    cout<<"                       "<<"To go back to main menu, press M"<<endl;
    cout<<"                              "<<"To play again, press S"<<endl;

    cout<<"                        "<<"To see the highscores, press P"<<endl;
}
int verificaBonus(float timpBonus)
{
    int interval=0,contor=0,aditie=3;
    if(timpBonus==0)
        return 1;
    while(interval<timpBonus)
        {
            interval+=aditie;
            aditie*=2;
            contor++;
        }
    return contor;

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
    string inamicImag(3,a1);
    int inaltimeMax=18, latimeMax=60;
    a=3;
    a1=char(a);
    string viataImag(3,a1);
    //bonus
    float timpScadereBonus=0, timpBonus=-1;
    int bonus;
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
    int nrInamiciSerie=latimeMax/(distantaInamic+inamicImag.length()-1);
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
    while(tastaApasata!='q' || tastaApasata=='Q')
    {
        if(aInceput==false)
        {
            gamePlayed=1;
            timpStart=clock()/1000;
            aInceput=true;
            for(int i=0;i<nrInamiciSerie;i++)
                {
                    inaltimeInamic[i]=(int)(((double)rand() / RAND_MAX) * (double)(inamicInaltimeMax -inamicInaltimeMin)) +inamicInaltimeMin;
                    scrollIndex[i]=latimeMax;
                }
        }
        if(life>6)
            break;
        float deltaTime=timpAnterior-timp;
        timp=clock();
        updateLogic+=deltaTime/(1000/fps);
        if(updateLogic>=1)
        {
            updateLogic--;
            string output="";
            system("cls");
            timpAfisare=clock()/1000-timpStart;
            if(timpAfisare>=6)
                {
                    if(timpBonus==-1)
                        timpScadereBonus=timpAfisare;
                    timpBonus=clock()/1000-timpScadereBonus-timpStart;
                }
            bonus=verificaBonus(timpBonus);
            if(timpBonus==-1)
                cout<<"Time:"<<timpAfisare<<" Score:"<<score/3<<"   Life:"<< viataImag<< " No hit in 0 seconds"<<endl;
            else
                    if(bonus==1)
                        cout<<"Time:"<<timpAfisare<<" Score:"<<score/3<<"   Life:"<< viataImag<< " No hit in "<<timpBonus<<" seconds"<<endl;
                    else
                         cout<<"Time:"<<timpAfisare<<" Score:"<<score/3<<" X"<<bonus<<" Life:"<< viataImag<< " No hit in "<<timpBonus<<" seconds"<<endl;
            //for(int i=0;i<latimeMax;i++)
                //cout<<(char)205;
            cout<<endl<<endl;
            if(tastaApasata=='q' || tastaApasata=='Q')// && !aApasat)
            {
                system("cls");  //clear screen
                gameOver(score/3,timpAfisare);
                break;
            }
            if(tastaApasata=='s'||tastaApasata=='S')// && !aApasat)
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
                }
            }

            //vieti
            for(int i=0;i<nrInamiciSerie;i++)
                if(scrollIndex[i]<=latimeMax/4 && scrollIndex[i]>latimeMax/4-inamicImag.length())
                    if(jucatorPozInaltime<inaltimeInamic[i] || jucatorPozInaltime>=inaltimeInamic[i]+ distantaSusJos)
                        {
                            timpBonus=-1;
                            life++;
                            nrInima=life/3;
                            viataImag[viataImag.length()-nrInima]=NULL;
                        }
                    else
                        score+=bonus;

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
                                    ok=false;
                                }

                                else
                                        ok=true;

                            else ok=true;
                        if(ok)
                            output+=drum;
                    }
                output+="\n";
                }
                int pozitieJucator;
                pozitieJucator=jucatorPozInaltime*(latimeMax+1)+latimeMax/4;
                output.replace(pozitieJucator,1,jucatorImag);
                output+="\n";
                cout << output;
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
	menu();
	char tastaApasata=getch();
	do{
        if(tastaApasata<97)
            tastaApasata+=32;
        switch(tastaApasata)
        {
            case 's' :   system("cls");  //clear screen
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
    }   while(tastaApasata!='q' || tastaApasata=='Q');
    return 0;

}
