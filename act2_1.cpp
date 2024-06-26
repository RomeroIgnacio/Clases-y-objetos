#include <iostream>
#include <string>
#include <tuple>

class Materia
{
private:
    // Atributos
    int clave;
    std::string nombre;
    std::string profesorTit;
    std::string libroTexto;

public:
    // Constructor
    Materia(int id, std::string nom, std::string prof, std::string libro) {clave = id; nombre = nom; profesorTit = prof; libroTexto = libro;}

    // Métodos
    void imprime()
    {
        std::cout << "\nClave: " << clave << "\nNombre: " << nombre << "\nProfesor Titular: " << profesorTit << "\nLibro de Texto: " << libroTexto << "\n" << std::endl;
    }

    void CambiaClave(int nuevaClave)
    {
        clave = nuevaClave;
    }

    void CambiaProfesor(const std::string& nuevoProfesor)
    {
        profesorTit = nuevoProfesor;
    }

    int ObtenerClave() const
    {
        return clave;
    }
};

int main()
{
    // Crear objetos de la clase Materia
    Materia Programacion(1, "Programación", "Profesor1", "LibroProgramacion");
    Materia BasesDatos(2, "Bases de Datos", "Profesor2", "LibroBasesDatos");

    // Menú de opciones
    int opcion;

    do
    {
        std::cout << "Menú:\n1. Cambiar clave de Materia\n2. Cambiar profesor de Materia\n3. Imprimir datos de Materia\n0. Salir\nIngrese la opción: ";

        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Cambiar clave de Programación
            {
                int clave;
                int nuevaClave;
                std::cout << "\nIngresa la clave de la Materia: ";
                std::cin >> clave;

                std::cout << "\nIngrese la nueva clave para Programación: ";
                std::cin >> nuevaClave;
                
                if (clave == Programacion.ObtenerClave())
                    Programacion.CambiaClave(nuevaClave);
                else if (clave == BasesDatos.ObtenerClave())
                    BasesDatos.CambiaClave(nuevaClave);

                std::cout << "\n";
            }
            break;

        case 2:
            // Cambiar profesor de Bases de Datos
            {
                int clave;
                std::string nuevoProfesor;
                std::cout << "\nIngresa la clave de la Materia: ";
                std::cin >> clave;

                std::cout << "\nIngrese el nuevo profesor para Bases de Datos: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoProfesor);

                if (clave == Programacion.ObtenerClave())
                    Programacion.CambiaProfesor(nuevoProfesor);
                else if (clave == BasesDatos.ObtenerClave())
                    BasesDatos.CambiaProfesor(nuevoProfesor);
                std::cout << "\n";
            }
            break;

        case 3:
            // Imprimir datos de Bases de Datos
            Programacion.imprime();
            BasesDatos.imprime();
            break;

        case 0:
            // Salir del programa
            std::cout << "\nSaliendo del programa.\n" << std::endl;
            break;

        default:
            std::cout << "\nOpción no válida. Intente de nuevo.\n" << std::endl;
            break;
        }

    } while (opcion != 0);
    return 0;
}