#ifndef FREQUENCYCOUNTTABLE_H_
#define FREQUENCYCOUNTTABLE_H_
#include<string>
#include<vector>

class FrequencyCountTable
{
private:
	std::vector<std::pair<std::string, int>> words;
public:
	FrequencyCountTable();
	void readFromFile(std::string fileNme);
	void printFreq();
};
#endif