#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "IParcer.h"

class Parcer_ini : public IParcer{
public:
	//Чтение файла
	void IReaderFile(const std::string& file_name) override;
	//1. Поиск ключа по секциям (в какой секции ключ)
	void IfindKey(const std::string& find_key) override;
	//2. Существует ли секция
	void IfindSection(const std::string& find_section) override;
	//3. Ключ в файле
	void keyInFile(const std::string& find_key) override;
	//4. Существует ли значение в файле
	void valueInFile(const std::string& find_value) override;	
	//5. Значение ключа в секции
	void keyValueInSection(const std::string& section_name, const std::string& key_name) override;
	//6. Замена значения ключа
	void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) override;
	//7. Запись парсера в файл
	const void writeToFile(const std::string& file_name) override;
	//Вывод Парсера в консоль
	void showParcer() override;
private:	
	std::map <std::string, std::map < std::string, std::string>> _section;	
};

