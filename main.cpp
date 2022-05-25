#include <bits/stdc++.h>
using namespace std;
class Animal
{
protected:
    string specie;
public:
    Animal();
    Animal(string specie);
    string getSpecie() const;
    virtual istream& citire(istream& is)
    {
        is>>specie;
    }
//    virtual ostream& afisare(ostream& os)
//    {
//        os<<specie;
//    }
    friend istream& operator >> (istream& is, Animal& ob)
    {
        return ob.citire(is);
        return is;
    }
    virtual ~Animal();
};
Animal::Animal()
{
    specie = "";
}
Animal::Animal(string specie):specie(specie){};
Animal::~Animal()
{
    specie.clear();
}
string Animal::getSpecie() const {
    return specie;
}
class Vertebrate : public Animal
{
protected:
    string specie;
public:
    Vertebrate():Animal(){};
    Vertebrate(string s = ""):Animal(s){};
    ~Vertebrate(){
        specie.clear();
    }
    virtual istream& citire(istream& is)
    {
        is>>specie;
    }
    friend ostream& operator << (ostream& os,Vertebrate& ob)
    {
        os<<ob.specie;
        return os;
    }
};
class Nevertebrate : public Animal
{
protected:
    string specie;
public:
//    Nevertebrate():Animal(){};
    Nevertebrate(string s=""):Animal(s){};
    ~Nevertebrate() {
        specie.clear();
    }
    virtual istream& citire(istream& is)
    {
        is>>specie;
    }
    friend ostream& operator << (ostream& os,Nevertebrate& ob)
    {
        os<<ob.specie;
        return os;
    }
};
class Peste : public Vertebrate
{
protected:
    string specie;
    long lungime;
public:
//    Peste():Vertebrate(){};
    Peste(string specie,int l):Vertebrate(specie),lungime(l){};
    ~Peste()
    {
        lungime = 0;
        specie.clear();
    }
    virtual int getLungime()
    {
        return lungime;
    }
    friend ostream& operator << (ostream& os,Peste& ob)
    {
        os<<ob.lungime;
        return os;
    }
};
class Reptila: public Vertebrate{
protected:
    long lungime;
public:
    Reptila(string specie, long lungime):Vertebrate(specie),lungime(lungime){};
    ~Reptila()
    {
        lungime = 0 ;
        specie.clear();
    }
};
class Pasari : public Vertebrate
{
protected:
    long lungime;
public:
    Pasari(string specie, long lungime):Vertebrate(specie),lungime(lungime){};
    ~Pasari()
    {
        lungime = 0 ;
        specie.clear();
    }

};
class Mamifer : public Vertebrate
{
protected:
    long lungime;
public:
    Mamifer(string specie, long lungime):Vertebrate(specie),lungime(lungime){};
    ~Mamifer()
    {
        lungime = 0 ;
        specie.clear();
    }

};
template<class T>
class AtlasZoologic{
protected:
    int nrAnimale;
    vector<string>pestiRapitori;
    list<T*>animale_tip;
public:
    AtlasZoologic()
    {
        this-> nrAnimale = 0;
        pestiRapitori.push_back("matei");
        pestiRapitori.push_back("tiberiu");
        pestiRapitori.push_back("adela ... ew");
        pestiRapitori.push_back("andrei");
        pestiRapitori.push_back("stefan");
        pestiRapitori.push_back("alex");
        pestiRapitori.push_back("petrica");
        pestiRapitori.push_back("colocviu poo");
        pestiRapitori.push_back("vericu");
        pestiRapitori.push_back("nelson");
    }
    ~AtlasZoologic();
    int getNrAnimale()
    {
        return nrAnimale;
    }
    friend ostream& operator << (ostream& os, AtlasZoologic& ob)
    {
        for(typename list<T*>::iterator it = ob.animale_tip.begin() ; it!= ob.animale_tip.end(); ++it)
            os<<(**it);
        return os;
    }
    void operator += (T anim)
    {
        animale_tip.push_back(&anim);
        nrAnimale ++;
        cout<<"Animalul adaugat este: "<<endl;
    }
    int getPestiMari()
    {
        int ok = 0;
        for(typename list<Vertebrate*>::iterator it = animale_tip.begin(); it!=animale_tip.end(); ++it)
        {
            Peste* p = dynamic_cast<Peste*> (*it);
            if(p->getLungime() > 1)
                ok++;
        }
        return ok;
    }
};
class singleton {
    static singleton * instanta;
    vector<Vertebrate*> ver;
    vector<Nevertebrate*> nev;
    singleton()
    {
        cout<<"Apasa tasta x pentru o anumita operatie:"<<endl;
        cout<<"Apasa 1 pentru a vedea ce animale sunt salvate (vertebrate sau nevertebrate)"<<endl;
        cout<<"Apasa 2 pentru a vedea pestii mai mari de 1 m"<<endl;
    }
public:
    static singleton * getInstanta()
    {
        if(instanta == nullptr)
            instanta = new singleton;
        return instanta;
    }
    void op1()
    {
        int n;
        string tipul;
        cout<<"Cate animale citim?"<<endl;
        cin>>n;
        cout<<"vertebrat sau nevertebrat?"<<endl;
        cin>>tipul;
        if(tipul == "vertebrat")
        {
            string specie;
            int lungime;
            cout<<"Numele tipului de peste este:"<<endl;
            cin>>specie;
            cout<<"Pestele are lungimea:"<<endl;
            cin>>lungime;
            Vertebrate * p = new Peste(specie,lungime);
            ver.push_back(p);
            cout<<"Afisam vertebratele stocate"<<endl;
            for(vector<Vertebrate*>::iterator it = ver.begin(); it!=ver.end();++it)
            {
                cout<<(**it);
            }
            cout<<endl;
        }
        else
        {
            cout<<"vrem animalul:"<<endl;
            Nevertebrate* p = new Nevertebrate();
            cin>>*p;
            nev.push_back(p);
            cout<<"Afisam nevertebratele stocate"<<endl;
            for(vector<Nevertebrate*>::iterator it = nev.begin(); it!=nev.end();++it)
            {
                cout<<(**it);
            }
            cout<<endl;
        }
    }
    void op2()
    {
        int nr;
        for(vector<Vertebrate*>::iterator it = ver.begin(); it!=ver.end();++it)
        {
            Peste * p = dynamic_cast<Peste*> (*it);
            if(p->getLungime() > 1)
            {
                nr++;
                break;//???
            }
        }
        cout<<nr<<endl;
    }
};
singleton * singleton::instanta = nullptr;

int main() {
    singleton *s;
    s=singleton::getInstanta();
    while(true)
    {
        try{
            int optiune;
            cout<<"Ce optiune doriti?"<<endl;
            cin>>optiune;
            if(optiune <=0 or optiune >4)
                throw "Nu ai ales bine frate! \n";
            if(optiune == 1)
                s->op1();
            else
            if(optiune == 2)
                s->op2();
        }
        catch(string s)
        {
            cout<<s<<endl;
        }
    }
//AtlasZoologic<Vertebrate*> ver;
//AtlasZoologic<Nevertebrate*> nev;
//    int n;
//    string tipul;
//    cout<<"Cate animale citim?"<<endl;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<"vertebrat sau nevertebrat?"<<endl;
//        cin>>tipul;
//        if(tipul == "vertebrat")
//        {
//            string specie;
//            int lungime;
//            cout<<"Numele tipului de peste este:"<<endl;
//            cin>>specie;
//            cout<<"Pestele are lungimea:"<<endl;
//            cin>>lungime;
//            Vertebrate * p = new Peste(specie,lungime);
//            ver += p;
//
//        }
//        else
//        {
//            cout << "Numele animalului este ";
//            Nevertebrate* p= new Nevertebrate();
//            cin >> *p;
//            nev += p;
//        }
//    }
//    cout<<endl;
//    cout<<ver<<endl;
//    cout<<nev<<endl;
    return 0;
}
