#include <iostream>
#include <string>

class Chef {
protected:
    std::string chefName;

public:
    Chef(const std::string& name) : chefName(name) {
        std::cout << "Chef " << chefName << " konstruktori.\n";
    }

    ~Chef() {
        std::cout << "Chef " << chefName << " destruktori.\n";
    }

    int makeSalad(int ingredients) {
        int servings = ingredients / 5;
        std::cout << chefName << " made " << servings << " salad(s).\n";
        return servings;
    }

    int makeSoup(int ingredients) {
        int servings = ingredients / 3;
        std::cout << chefName << " made " << servings << " soup(s).\n";
        return servings;
    }
};

class ItalianChef : public Chef {
private:
    std::string secretPassword = "pizza";

    int makePizza(int flour, int water) {
        int servings;
        if (flour < water)
            servings = flour / 5;
        else
            servings = water / 5;

        std::cout << chefName << " made " << servings << " pizza(s)!\n";
        return servings;
    }

public:
    ItalianChef(const std::string& name) : Chef(name) {
        std::cout << "ItalianChef " << chefName << " ready.\n";
    }

    ~ItalianChef() {
        std::cout << "ItalianChef " << chefName << " done.\n";
    }

    bool askSecret(const std::string& password, int flour, int water) {
        if (password == secretPassword) {
            makePizza(flour, water);
            return true;
        } else {
            std::cout << chefName << ": Wrong password!\n";
            return false;
        }
    }
};

int main() {
    Chef c("Mussolini");
    c.makeSalad(12);
    c.makeSoup(10);

    ItalianChef ic("Mangione");
    ic.makeSalad(10);
    ic.makeSoup(9);

    ic.askSecret("wrong", 15, 10);
    ic.askSecret("pizza", 15, 10);

    return 0;
}