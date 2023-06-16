#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//------------------------------Function bodies------------------------------//

void menu_view()
{
    cout<<endl;
    cout<<"1.Citirea listei."<<endl;
    cout<<"2.Afisarea listei."<<endl;
    cout<<"3.Cea mai lunga secventa de numere crescatoare"<<endl;
    cout<<"4.Cea mai lunga secventa munte"<<endl;
    cout<<"5.Cea mai lunag secventa in care exista cel mult 3 numere distincte"<<endl;
    cout<<"6.Iesire program."<<endl;
}

void vector_read(int &n,int* &v)
{
    cout<<"n=";
    cin>>n;
    v=new int[n];
    cout<<"Lista:";
    for(int i=0;i<n;i++)cin>>v[i];
}

void vector_write(int st,int fin,int* v)
{
    for(int i=st;i<fin;i++)
        cout<<v[i]<<" ";
}

void secv_max_crec(int n,int* v)
{
    int ct=0,ct_max=0,poz_st_max,poz_st;
    bool ok=0;
    for(int i=0;i<n;++i)
    {
        if(v[i]>v[i-1] && ct==0)
        {
            ct+=2;
            poz_st=i-1;
            ok=1;
        }
        else if(v[i]>v[i-1] && ct!=0)ct++;
        else
        {   
            if(ct_max<ct)
            {
                ct_max=ct;
                poz_st_max=poz_st;
            }
            ct=0;
        }
    }
    if(ct==n)
    {
        ct_max=ct;
        poz_st_max=poz_st;
    }
    if(ok==1)vector_write(poz_st_max,poz_st_max+ct_max,v);
    else cout<<"Nu exista";
    //todo afisarea vectorului de la 1 si rezolvare completa de la 11;
}

void secv_max_munte(int n,int* v)
{
    int ct=0,ct_max=0,poz_st_max,poz_st;
    bool ok=0;
    for(int i=0;i<n;++i)
    {
        if(v[i]>v[i-1] && ct==0)
        {
            ct+=2;
            poz_st=i-1;
        }
        else if(v[i]>v[i-1] && ct!=0)ct++;
        else
        {   
            if(ct>=2)
            {
                ok=1;
                for(int j=i;j<n;++j)
                {
                    if (v[j]<v[j-1])ct++;
                    else break;
                }
                
            }
            if(ct_max<ct)
            {
                ct_max=ct;
                poz_st_max=poz_st;
            }
            ct=0;
        }
    }
    if(ok==1)
    {
        vector_write(poz_st_max,poz_st_max+ct_max,v);
    }
    else cout<<"Nu exista";
}

void secv_max_three_dif(int n,int* v)
{
    int ct=0,poz_st=0,poz_st_max=0,ct_max=0,ct_chang=0, nr1, nr2, nr3;
    nr1=v[0];
    nr2=nr1;
    nr3=nr1;
    for(int i=0;i<n;++i)
    {
        if(v[i]!=nr1 && v[i]!=nr2 && v[i]!=nr3)
        {
            if(nr1==nr2)nr2=v[i];
            else if(nr2==nr3)nr3=v[i];
            else 
            {
                if(ct>ct_max)
                {
                    ct_max=ct;
                    poz_st_max=poz_st;
                }
                ct=0;
                poz_st=i;
                nr1=nr2;
                nr2=nr3;
                nr3=v[i];
            }
        }
        else ct++;
    }
    vector_write(poz_st_max,poz_st_max+ct_max,v);
}

void meniu()
{
    int n=0,*v,opt;
    while(true)
    {
        menu_view();
        cout<<endl<<"Optiunea aleasa:";
        cin>>opt;
        cout<<endl;
        switch (opt)
        {
        case 1:
            vector_read(n,v);
            cout<<endl;
            break;
        case 2:
            vector_write(0,n,v);
            cout<<endl;
            sleep_for(milliseconds(3000));
            break;
        case 3:
            secv_max_crec(n,v);
            cout<<endl;
            sleep_for(milliseconds(3000));
            break;
        case 4:
            secv_max_munte(n,v);
            cout<<endl;
            sleep_for(milliseconds(3000));
            break;
        case 5:
            secv_max_three_dif(n,v);
            cout<<endl;
            sleep_for(milliseconds(3000));
            break;
        case 6:
            delete[] v;
            cout<<"Va multumim pentru ca ne-ati folosit aplicatia!";
            cout<<endl;
            exit(0);
        default:
            cout<<"Optiune inexistena.Reincercati!"<<endl;
            sleep_for(milliseconds(2000));
            break;
        }
        system("clear");
    }
}

//------------------------------Main------------------------------//

int main()
{
    meniu();
}