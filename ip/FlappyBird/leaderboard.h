
struct lista{
            int info, timp;
            lista*urm;
            }*prim,*ultim;
void unElement(int score, float time)
{

        lista *p=new lista;
        p->urm=NULL;
        p->info=score;
        p->timp=time;
        if(prim->info>score)
        {//g<<"OK";
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

void adaugaInfoInainte(int score, int time, lista*&p)
{
    lista *aux=new lista;
    aux->info=score;
    aux->timp=time;
    aux->urm=p;
    prim=aux;

}
void sortareTimpInainte(int score, int time, lista *&p)
{
    lista* aux=new lista;
    aux->urm=prim;
    aux->info=score;
    aux->timp=time;
    prim=aux;

}
void adaugaInfo(int score, int time, lista *&p)
{
    lista *aux=new lista;
    aux->urm=p->urm;
    aux->timp=time;
    aux->info=score;
    p->urm=aux;

}
void sortareTimp(int score, int time, lista *&p)
{
    if(p->urm->timp>time) //prima pozitie
    {
        lista *aux=new lista;
        aux->timp=time;
        aux->info=score;
        aux->urm=p->urm;
        p->urm=aux;
        return;
    }

   while(p->urm->info==score && p->urm->timp<time && p->urm->urm!=NULL)
        p=p->urm;
   // p=p->urm;
    if(p->urm->urm==NULL)
    {
        lista *aux=new lista;
        aux->info=score;
        aux->timp=time;
        aux->urm=NULL;
        if(p->urm->info==score)
            if(p->urm->timp<time)
                {
                    p->urm->urm=aux;
                    return;
                }
            else
            {
                aux->urm=p->urm;
                p->urm=aux;
                return;
            }
        else if(p->urm->info<score)
                {
                    aux->urm=p->urm;
                    p->urm=aux->urm;
                    return;
                }
    }
    lista *aux=new lista;
    aux->urm=p->urm;
    aux->info=score;
    aux->timp=time;
    p->urm=aux;

}
void listaInsertie(int score, int time)
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
    if(score>prim->info)
       {
           adaugaInfoInainte(score,time,p);
           return;
       }
    if(score==prim->info && time<=prim->timp && p->urm!=NULL)
        {
            sortareTimpInainte(score,time,p);
            return;
        }
    int ok=0;
    while(p->urm->info>score)// && p->urm!=NULL)
    {
        if(p->urm->urm==NULL) //ultim
            {
                ok=1;
                break;
            }
        p=p->urm;
    }
    if(ok==1)
    {
        p=p->urm;
        lista *aux=new lista;
        aux->urm=NULL;
        aux->info=score;
        aux->timp=time;
        p->urm=aux;
        return;
    }
    if(p->urm->info<score)
        {
            adaugaInfo(score,time,p);
            return;
        }
    if(p->urm->info==score)
        {
            sortareTimp(score,time,p);
            return;
        }

}
/*void afisare()
{
    lista *p=prim;
    while(p)
    {
        cout<<p->info<<" "<<p->timp<<endl;
        p=p->urm;
    }
}*/
