#include <iostream>

class persona
{
private:
        // Atributos
        int edad;
	int altura;
        std::string nombre;

protected:
public:
        // Metodos
        persona() {edad = 0; altura = 30; nombre = " ";}
        persona(float a, std::string n) {altura = a; nombre = n;}
        persona(int e, std::string n) {edad = e; nombre = n;}

		void habla()
        {
                std::cout << "Hola mi nombre es " << nombre << "\nTengo una altura de " << altura << std::endl;
        }
};

int main()
{
        persona Brayan(180, "Kevin");
        Brayan.habla();
        return 0;
}