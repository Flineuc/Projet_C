#include <iostream>
#include <cmath>
using namespace std;
#define MAXNOTES 4

typedef struct Complexe {
    float reel;
    float img;
} Complexe;

void initComplexe (Complexe *c, double reel, double img){
    (*c).reel = reel; //c->reel
    (*c).img = img;
}

void afficheComplexe(Complexe c){
    cout << "c = " << c.reel << " + " << c.img << "* i";
}

Complexe sommeComplexe(Complexe cUn, Complexe CDeux){
    Complexe c;
    double reel = cUn.reel + CDeux.reel;
    double img = cUn.img + CDeux.img;
    initComplexe (&c, reel, img);
    return c;
}

Complexe produitComplexe(Complexe cUn, Complexe cDeux){
    Complexe c;
    double reel = (cUn.reel * cDeux.reel - cUn.img * cDeux.img) ;
    double img = (cUn.reel * cDeux.img + cDeux.reel * cUn.img) ;
    initComplexe (&c, reel, img);
    return c;
}

Complexe conjugue(Complexe c){
    Complexe c1;
    double reel = c.reel ;
    double img = (-c.img) ;
    initComplexe (&c1, reel, img);
    return c1;
}

double moduleComplexe(Complexe c) {
    double mod=sqrt(c.reel * c.reel + c.img * c.img);
    return mod;
}

Complexe inverseComplexe (Complexe c){
    Complexe inverse;
    Complexe conj = conjugue (c);
    double mod2 = moduleComplexe(c) * moduleComplexe(c);
    double reel = conj.reel/mod2 ;
    double img = conj.img/mod2 ;
    if (mod2==0) {
        cout << "Division par 0 impossible ! ";
    } else {
        initComplexe(&inverse, reel, img );
        return inverse;
    }
}

typedef struct Date {
    int jour;
    char mois [10];
    int annee;
} Date;

void ecrireDate(Date date){
    cout << date.jour << date.mois << date.annee << "\n";
}

void lireDate(Date *date){
    cout << "Jour : ";
    cin >> (*date).jour;
    cout << "Mois : " ;
    cin >> (*date).mois;
    cout << "Annee : " ;
    cin >> (*date).annee;
}

typedef struct Fiche {
    char nom [20];
    char prenom [20];
    Date dateDeNaissance;
    float Notes [MAXNOTES];
    int nbNotes;
} Fiche;

void lireFiche(Fiche *fiche) {
    cout << "Nom : ";
    cin >> (*fiche).nom;
    cout << "Prenom : " ;
    cin >> (*fiche).prenom;
    lireDate (&(fiche->dateDeNaissance));
    (*fiche).nbNotes=0;
}

void ajoutNote (Fiche *fiche,float note){
    if (fiche->nbNotes==4) cout << "Notes est plein !" ;
    else {
        fiche->Notes[(fiche->nbNotes)+1] = note;
        fiche->nbNotes = ((fiche->nbNotes)+1);
    }
}


void ecrireFiche(Fiche fiche){
    cout << "Nom : " << fiche.nom;
    cout << "\nPrenom : " << fiche.prenom;
    cout << "\nDate de naissance : ";
    ecrireDate(fiche.dateDeNaissance);
    if (fiche.nbNotes!=0){
        cout << "\n Notes : ";
        for (int i=0 ; i!=fiche.nbNotes ; i++){
            cout << " " << fiche.Notes[i] ;
        }
    }
}


int main (int argc, char** argv){
    Fiche fiche;
    lireFiche(&fiche);
    ajoutNote(&fiche,10);
    ecrireFiche(fiche);
}
    