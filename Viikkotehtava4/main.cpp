#include <iostream>
#include <string>
using namespace std;


class Pankkitili {
protected:
    string omistaja;
    double saldo;

public:
    Pankkitili(string nimi) {
        omistaja = nimi;
        saldo = 0;
        cout << "Pankkitili luotu " << omistaja << ":lle" << endl;
    }

    virtual bool deposit(double summa) {
        if (summa <= 0) return false;
        saldo += summa;
        return true;
    }

    virtual bool withdraw(double summa) {
        if (summa <= 0 || summa > saldo) return false;
        saldo -= summa;
        return true;
    }

    double getBalance() const {
        return saldo;
    }
};


class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(string nimi, double raja)
        : Pankkitili(nimi) {
        luottoRaja = raja;
        saldo = raja;
        cout << "Luottotili luotu " << omistaja
             << ":lle, luottoraja " << luottoRaja << endl;
    }

    bool withdraw(double summa) override {
        if (summa <= 0 || summa > saldo) return false;
        saldo -= summa;
        return true;
    }

    bool deposit(double summa) override {
        if (summa <= 0) return false;
        saldo += summa;
        if (saldo > luottoRaja)
            saldo = luottoRaja;
        return true;
    }
};


class Asiakas {
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(string n, double luotto)
        : nimi(n),
          kayttotili(n),
          luottotili(n, luotto) {
        cout << "Asiakkuus luotu " << nimi << endl;
    }

    void showSaldo() const {
        cout << "Kayttotilin saldo " << kayttotili.getBalance() << endl;
        cout << "Luottotilin saldo " << luottotili.getBalance() << endl;
    }

    void talletus(double summa) {
        if (kayttotili.deposit(summa))
            cout << "\nPankkitili: talletus " << summa << " tehty" << endl;
    }

    void luotonNosto(double summa) {
        if (luottotili.withdraw(summa))
            cout << "Luottotili: nosto " << summa
                 << " tehty, luottoa jaljella "
                 << luottotili.getBalance() << endl;
    }

    void tiliSiirto(double summa, Asiakas& vastaanottaja) {
        cout << "\nPankkitili: " << nimi
             << " siirtaa " << summa
             << " " << vastaanottaja.nimi << ":lle" << endl;

        if (kayttotili.withdraw(summa)) {
            cout << nimi << " Pankkitili: nosto "
                 << summa << " tehty" << endl;

            vastaanottaja.kayttotili.deposit(summa);
            cout << vastaanottaja.nimi
                 << " Pankkitili: talletus "
                 << summa << " tehty" << endl;
        }
    }
};


int main() {
    Asiakas ismo("Ismo", 1000);

    ismo.showSaldo();

    ismo.talletus(250);
    ismo.luotonNosto(150);

    ismo.showSaldo();

    cout << endl;

    Asiakas seppo("Seppo", 1000);
    seppo.showSaldo();

    cout << "\nIsmo" << endl;
    ismo.showSaldo();

    ismo.tiliSiirto(50, seppo);

    cout << "\nSeppo" << endl;
    seppo.showSaldo();

    return 0;
}