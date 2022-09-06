// Meta Assembler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct instData {
	string mnemonic;
	string hexCode;
};

int main()
{
	instData instructions[15] = { {"JMP", "E"}, {"ADDI", "D"}, {"MOVEI", "C"}, {"MOVE", "B"}, {"STORE", "A"},
								{"LDA", "9"}, {"STA", "8"}, {"STA+", "7"}, {"MOVEA", "6"}, {"MOVEA+", "5"},
								{"LDSP", "4"}, {"JSP", "3"}, {"RTS", "2"}, {"BZ", "FE"}, {"BNZ", "FD"} };

	ifstream file("Files/program.txt");
	ofstream memConts("Files/MemoryContents.cdm");

	int instNum = 0;

	while (file.good()) 
	{
		string opcode;
		string operand;

		getline(file, opcode, ',');
		getline(file, operand);

		for (int i = 0; i < 15; i++)
		{
			if (opcode == instructions[i].mnemonic)
			{
				string fullOperand = instructions[i].hexCode + operand;
				memConts << instNum << " : " << fullOperand << "\n";
				instNum++;
			}
		}

		cout << "Writing Complete!" << endl;
	}
};