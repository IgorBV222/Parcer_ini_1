#include "Parcer_ini.h"

//Чтение файла
void Parcer_ini::IReaderFile(const std::string& file_name) {
	std::ifstream path;
	path.open(file_name);	
	std::string currenLine, sectionTitle, key, value;	
	if (path.is_open()) {
		while (getline(path, currenLine)) {			
			if (currenLine[0] == '[') {
				sectionTitle = currenLine.substr(1, currenLine.find(']') - 1);
				_section[sectionTitle];				
			}
			else {
				if (currenLine.size() !=0 && currenLine[0] != ';' && currenLine[0] != '#' && currenLine[0] != '[' && currenLine[0] != ' ') {
					for (int i = 0; i < currenLine.size(); i++) {
						if (currenLine[i] == '=') {
							key = currenLine.substr(0, currenLine.find('='));							
							value = currenLine.substr(currenLine.find('=') + 1);
							for (int i = 0; i < value.size(); i++) {
								std::string tmp_value = currenLine.substr(currenLine.find('=') + 1);
								if (tmp_value[i] == ';' || tmp_value[i] == '#') {
									value = tmp_value.erase(i);
								}
								else
									value = tmp_value;
							}							
						}									
					}
				}
				if(key!="")
					_section[sectionTitle][key] = value;
			}			
		}		
	}
	else
		throw "Error open file";
	path.close();
}
//1. Поиск ключа по секциям (в какой секции ключ)
void Parcer_ini::IfindKey(const std::string& find_key){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.first == find_key) {
				std::cout << "The key: " << element.first << " in section " << section.first << std::endl;
				return;
			}
		}	
	}	
	std::cout << "The key is not in the sections...." << std::endl;
	return;
}
//2. Существует ли секция
void Parcer_ini::IfindSection(const std::string& find_section) {
	for (const auto& section : _section) {
		if (section.first == find_section) {
			std::cout << "Section exists!" << std::endl;
			return;
		}
	}
	std::cout << "There is no such section...." << std::endl;
	return;
}
//3. Ключ в файле
void Parcer_ini::keyInFile(const std::string& find_key) {
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.first == find_key){
				std::cout << "The key is in the file!" << std::endl;
			return;
			}
		}
	}	
	std::cout << "The key is not in the file...." << std::endl;
	return;
}
//4. Существует ли значение в файле
void Parcer_ini::valueInFile(const std::string& find_value){
	bool found;
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			found = element.second.find(find_value) != std::string::npos; //если у ключа несколько значений через ","
			if (found) {
				std::cout << "The value exists in the file!" << std::endl;
				return;
			}			
		}
	}	
	std::cout << "The value is not in the file...." << std::endl;
	return;
}
//5. Значение ключа в секции
void Parcer_ini::keyValueInSection(const std::string& section_name, const std::string& key_name) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name) {
					std::cout << "Key value in section: " << element.second << std::endl;
					return;
				}
			}
			std::cout << "The key is not in the file...." << std::endl;
			return;
		}
	}
	std::cout << "There is no such section...." << std::endl;
	return;
}
//6. Замена значения ключа
void Parcer_ini::keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name) {
					_section[section.first][element.first] = value_newName;
					std::cout << "Section: " << section.first << "\nKey: " << element.first << "\nNew value created: " << element.second << std::endl;
					return;
				}
			}
			_section[section.first][key_name] = value_newName;
			std::cout << "Section: " << section.first << "\nNew key created: " << key_name << "\nNew value created: " << value_newName << std::endl;
			return;
		}
	}
	_section[section_name][key_name] = value_newName;
	std::cout << "New section created: " << section_name << "\nNew key created: " << key_name << "\nNew value created: " << value_newName << std::endl;
	return;
}
//7. Запись парсера в файл.
const void Parcer_ini::writeToFile(const std::string& file_name){	
	std::ofstream out;	
	out.open(file_name);
	if (out.is_open()) {
		
		for (const auto& section : _section) {			
			out << ('[' + section.first + ']' + '\n');
			for (const auto& element : section.second) {				
				out << (element.first + '=' + element.second + '\n');
			}
		}
		std::cout << "\nThe parser is written to the specified file!\n";		
	}
	else
		std::cout << "Error opening file! File does not exist.\n";	
	out.close(); 
	system("pause");
	system("cls");
}
//Вывод Парсера в консоль
void Parcer_ini::showParcer(){
	for (const auto& section : _section) {
		std::cout << "[" << section.first << "]" << std::endl;
			for (const auto& element : section.second) {
					std::cout << element.first << "=" << element.second << std::endl;
			}
	}
}

