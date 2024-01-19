#include <iostream>
#include <string>

class Empleado
{
private:
    // Atributos
    int claveEmpl;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string reportaA;

public:
    // Constructor
    Empleado(int clave, std::string nom, std::string dom, float sal, std::string repA) : claveEmpl(clave), nombre(nom), domicilio(dom), sueldo(sal), reportaA(repA) {}

    void imprime()
    {
        std::cout << "\nClave: " << claveEmpl << "\nNombre: " << nombre << "\nDomicilio: " << domicilio << "\nSueldo: " << sueldo << "\nReporta a: " << reportaA << "\n" << std::endl;
    }

    void CambiaDomicilio(const std::string& nuevoDomicilio)
    {
        domicilio = nuevoDomicilio;
    }

    void CambiaReportaA(const std::string& nuevoJefe)
    {
        reportaA = nuevoJefe;
    }

    void ActualSueldo(float porcentajeIncremento)
    {
        sueldo *= (1 + porcentajeIncremento / 100);
    }

    int ObtenerClave() const
    {
        return claveEmpl;
    }
};

int main()
{
    // Crear objetos de la clase Empleado
    Empleado JefePlanta(1, "Jefe Planta", "Calle 1", 50000, "Director General");
    Empleado JefePersonal(2, "Jefe Personal", "Calle 2", 45000, "Director General");

    // Menú de opciones
    int opcion;
    do
    {
        std::cout << "Menú:\n1. Cambiar domicilio\n2. Actualizar sueldo\n3. Imprimir datos\n4. Cambiar jefe\n0. Salir\nIngrese la opción: ";
        std::cin >> opcion;

        int clave; // Variable para almacenar la clave ingresada por el usuario

        switch (opcion)
        {
        case 1:
            // Cambiar domicilio
            {
                std::string nuevoDomicilio;
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> clave;

                std::cout << "\nIngrese el nuevo domicilio: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);

                if (clave == JefePlanta.ObtenerClave())
                    JefePlanta.CambiaDomicilio(nuevoDomicilio);
                else if (clave == JefePersonal.ObtenerClave())
                    JefePersonal.CambiaDomicilio(nuevoDomicilio);
                else
                    std::cout << "\nEmpleado no encontrado.\n" << std::endl;
            }
            break;

        case 2:
            // Actualizar sueldo
            {
                float porcentajeIncremento;
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> clave;

                std::cout << "\nIngrese el porcentaje de incremento del sueldo: ";
                std::cin >> porcentajeIncremento;

                if (clave == JefePlanta.ObtenerClave())
                    JefePlanta.ActualSueldo(porcentajeIncremento);
                else if (clave == JefePersonal.ObtenerClave())
                    JefePersonal.ActualSueldo(porcentajeIncremento);
                else
                    std::cout << "\nEmpleado no encontrado.\n" << std::endl;
            }
            break;

        case 3:
            // Imprimir datos
            {
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> clave;

                if (clave == JefePlanta.ObtenerClave())
                    JefePlanta.imprime();
                else if (clave == JefePersonal.ObtenerClave())
                    JefePersonal.imprime();
                else
                    std::cout << "\nEmpleado no encontrado.\n" << std::endl;
            }
            break;

        case 4:
            // Cambiar jefe
            {
                std::string nuevoJefe;
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> clave;

                std::cout << "\nIngrese el nombre del nuevo jefe: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoJefe);

                if (clave == JefePlanta.ObtenerClave())
                    JefePlanta.CambiaReportaA(nuevoJefe);
                else if (clave == JefePersonal.ObtenerClave())
                    JefePersonal.CambiaReportaA(nuevoJefe);
                else
                    std::cout << "\nEmpleado no encontrado.\n" << std::endl;
            }
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
