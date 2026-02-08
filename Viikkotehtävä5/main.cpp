#include <iostream>
#include <string>

using namespace std;

class Seuraaja {
public:
    string nimi;
    Seuraaja* next;

    Seuraaja(string n) {
        nimi = n;
        next = nullptr;
        cout << "Luodaan seuraaja " << nimi << endl;
    }

    string getNimi() {
        return nimi;
    }

    void paivitys(string viesti) {
        cout << "Seuraaja " << nimi << " sai viestin " << viesti << endl;
    }
};

class Notifikaattori {
public:
    Seuraaja* seuraajat;

    Notifikaattori() {
        seuraajat = nullptr;
        cout << "Luodaan notifikaattori" << endl;
    }

    void lisaa(Seuraaja* s) {
        cout << "Notifikaattori lisaa seuraajan " << s->getNimi() << endl;
        s->next = seuraajat;
        seuraajat = s;
    }

    void poista(Seuraaja* s) {
        cout << "Notifikaattori poistaa seuraajan " << s->getNimi() << endl;

        if (seuraajat == nullptr) return;

        if (seuraajat == s) {
            seuraajat = seuraajat->next;
            return;
        }

        Seuraaja* o = seuraajat;
        while (o->next != nullptr && o->next != s) {
            o = o->next;
        }

        if (o->next == s) {
            o->next = s->next;
        }
    }

    void tulosta() {
        cout << "Notifikaattorin seuraajat:" << endl;
        Seuraaja* o = seuraajat;
        while (o != nullptr) {
            cout << "Seuraaja " << o->getNimi() << endl;
            o = o->next;
        }
    }

    void postita(string viesti) {
        cout << "Notifikaattori postaa viestin " << viesti << endl;
        Seuraaja* o = seuraajat;
        while (o != nullptr) {
            o->paivitys(viesti);
            o = o->next;
        }
    }
};

int main() {
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.tulosta();

    n.postita("Tama on viesti 1");

    n.poista(&b);

    n.postita("Tama on viesti 2");

    return 0;
}