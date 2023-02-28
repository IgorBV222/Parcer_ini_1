#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "IParcer.h"

class Parcer_ini : public IParcer{
public:
	//������ �����
	void IReaderFile(const std::string& file_name) override;
	//1. ����� ����� �� ������� (� ����� ������ ����)
	void IfindKey(const std::string& find_key) override;
	//2. ���������� �� ������
	void IfindSection(const std::string& find_section) override;
	//3. ���� � �����
	void keyInFile(const std::string& find_key) override;
	//4. ���������� �� �������� � �����
	void valueInFile(const std::string& find_value) override;	
	//5. �������� ����� � ������
	void keyValueInSection(const std::string& section_name, const std::string& key_name) override;
	//6. ������ �������� �����
	void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) override;
	//7. ������ ������� � ����
	const void writeToFile(const std::string& file_name) override;
	//����� ������� � �������
	void showParcer() override;
private:	
	std::map <std::string, std::map < std::string, std::string>> _section;	
};

