#pragma once
#include <iostream>

class IParcer{
public:
	//������ �����
	virtual void IReaderFile(const std::string& file_name) = 0;
	//1. ����� ����� �� ������� (� ����� ������ ����)
	virtual void IfindKey(const std::string& find_key) = 0;
	//2. ���������� �� ������
	virtual void IfindSection(const std::string& find_section) = 0;
	//3. ���� � �����
	virtual void keyInFile(const std::string& find_key) = 0;
	//4. ���������� �� �������� � �����
	virtual void valueInFile(const std::string& find_value) = 0;
	//5. �������� ����� � ������
	virtual void keyValueInSection(const std::string& section_name, const std::string& key_name) = 0;
	//6. ������ �������� �����
	virtual void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) = 0;
	//7. ������ ������� � ���� writeToFile
	virtual const void writeToFile(const std::string& file_name) = 0;
	//����� ������� � �������
	virtual void showParcer() = 0;
	virtual ~IParcer() {}
};

