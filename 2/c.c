#include <iostream>
#include <fstream>
#include <string>

void mostrarMenu()
{
    std::cout << "===== Editor de Archivos =====\n";
    std::cout << "1. Crear archivo\n";
    std::cout << "2. Guardar cambios\n";
    std::cout << "3. Abrir archivo\n";
    std::cout << "4. Salir\n";
    std::cout << "==============================\n";
    std::cout << "Seleccione una opción: ";
}

void crearArchivo(std::string &archivoActual)
{
    std::cout << "Ingrese el nombre del archivo que desea crear (con extensión .txt): ";
    std::cin >> archivoActual;

    std::ofstream archivo(archivoActual);
    if (archivo.is_open())
    {
        std::cout << "Archivo '" << archivoActual << "' creado exitosamente.\n";
        archivo.close();
    }
    else
    {
        std::cout << "Error al crear el archivo.\n";
    }
}

void guardarCambios(const std::string &archivoActual)
{
    if (archivoActual.empty())
    {
        std::cout << "No se ha creado o abierto ningún archivo.\n";
        return;
    }

    std::ofstream archivo(archivoActual);
    if (archivo.is_open())
    {
        std::cout << "Ingrese el contenido que desea guardar en el archivo: \n";
        std::cin.ignore(); // Limpiar el buffer
        std::string contenido;
        std::getline(std::cin, contenido);

        archivo << contenido;
        archivo.close();
        std::cout << "Cambios guardados en el archivo '" << archivoActual << "'.\n";
    }
    else
    {
        std::cout << "No se pudo abrir el archivo.\n";
    }
}

void abrirArchivo(std::string &archivoActual)
{
    std::cout << "Ingrese el nombre del archivo que desea abrir: ";
    std::cin >> archivoActual;

    std::ifstream archivo(archivoActual);
    if (archivo.is_open())
    {
        std::cout << "Contenido del archivo '" << archivoActual << "':\n";
        std::string linea;
        while (getline(archivo, linea))
        {
            std::cout << linea << '\n';
        }
        archivo.close();
    }
    else
    {
        std::cout << "No se pudo abrir el archivo.\n";
    }
}

int main()
{
    int opcion;
    std::string archivoActual;

    do
    {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            crearArchivo(archivoActual);
            break;
        case 2:
            guardarCambios(archivoActual);
            break;
        case 3:
            abrirArchivo(archivoActual);
            break;
        case 4:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
