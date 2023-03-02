#include <iostream>
#include <fstream>
#include <iostream>
#include <memory> 
#include <string>
#include <chrono>
#include "IParcer.h"
#include "Parcer_ini.h"

/*int main(int argc, char** argv) {
    //Аргументы командной строки
    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            std::string s = std::string(argv[i]);
            std::cout << s << std::endl;
        }
        std::string filename = std::string(argv[1]);
        std::cout << filename << std::endl; //в проекте выводить не надо
        std::ifstream fin(filename); // тоже самое std::ifstream fin("filename.ini");
    }
    else {
        std::cout << "Only one argument was provided" << std::endl;
    }
    return 0;
}*/

int main() {    
    short answer;
    do {
        std::shared_ptr <IParcer> parser = std::make_shared<Parcer_ini>();       
        std::string key, section, value, pathFile;
        std::cout << "\t\t\t   File Parser\n\t\t\t*****************\n\n";
        std::cout << "Enter the path to the file -> ";
        getline(std::cin, pathFile);
        parser->IReaderFile(pathFile);
        system("cls");
        std::cout << "File data:\n\n";
        parser->showParcer();
        std::cout << "\n";
        system("pause");
        system("cls");
        std::cout << "What do you want to do?\n";
        std::cout << "1.Find in which section the key is located.\n";
        std::cout << "2.Check header existence.\n";
        std::cout << "3.Check for the existence of a key.\n";
        std::cout << "4.Check if a value exists.\n";
        std::cout << "5.Find key value in section.\n";
        std::cout << "6.Replace key value.\n";
        std::cout << "7.Save data to file.\n";
        std::cout << "0.To finish work.\n";
        std::cout << "\nEnter -> ";
        std::cin >> answer;
        system("cls");
        switch (answer) {
        case 0:
        {
            std::cout << "\nThank you for using the app" << '"' << "File Parser" << '"' << "\n\Exiting the program..." << '\n';
        }
        break;

        case 1:
        {
            std::cin.ignore();
            std::cout << "Enter key -> ";
            getline(std::cin, key);
            system("cls");
            parser->IfindKey(key);
            system("pause");
            main();
            break;
        }
        case 2:
        {
            std::cin.ignore();
            std::cout << "Enter section name -> ";
            getline(std::cin, section);
            system("cls");
            parser->IfindSection(section);
            system("pause");
            main();
            break;
        }
        case 3:
        {
            std::cin.ignore();
            std::cout << "Enter key -> ";
            getline(std::cin, key);
            system("cls");
            parser->keyInFile(key);
            system("pause");
            main();
            break;
        }
        case 4:
        {
            std::cin.ignore();
            std::cout << "Enter value -> ";
            getline(std::cin, value);
            system("cls");
            parser->valueInFile(value);
            system("pause");
            main();
            break;
        }
        case 5:
        {
            std::cin.ignore();
            std::cout << "Enter section name -> ";
            getline(std::cin, section);
            std::cout << "Enter key -> ";
            getline(std::cin, key);
            system("cls");
            parser->keyValueInSection(section, key);
            system("pause");
            main();
            break;
        }
        case 6: 
        {
            std::cin.ignore();
            std::cout << "Enter section name -> ";
            getline(std::cin, section);
            std::cout << "Enter key -> ";
            getline(std::cin, key);
            std::cout << "Enter value -> ";
            getline(std::cin, value);
            system("cls");
            parser->keyValueReplacement(section, key, value);
            system("pause");
            system("cls");
            std::cout << "Updated data:\n";
            parser->showParcer();
            system("pause");
            system("cls");
            std::cout << "Enter the path to the file to write the updated data -> ";
            getline(std::cin, pathFile);
            system("cls");
            parser->writeToFile(pathFile);
            main();
            break;
        }
        case 7:
        {
            std::cin.ignore();
            std::cout << "Enter the path to the file to write -> ";
            getline(std::cin, pathFile);
            system("cls");
            parser->writeToFile(pathFile);
            main();
            break;
        }
        } break;
    } while (answer != 0 && answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5 && answer != 6 && answer != 7);
    return 0;
}