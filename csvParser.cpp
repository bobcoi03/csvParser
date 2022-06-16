#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>
#include <vector>
#include <iterator>
#include <ctime>

std::vector<std::string> split(const std::string &s, char separator){
    std::vector<std::string> ret;
    std::string accum;
    for (auto c : s){
        if (c == separator){
            ret.emplace_back(std::move(accum));
            continue;
        }
        accum += c;
    }
    ret.emplace_back(std::move(accum));
    return ret;
}

class csvParser {
	public:
		// read file based on name
		std::string fileName;
		float fileSize;
		std::size_t rows = 0;
		int columns = 0;
		std::vector<std::vector<std::string>> fileData {};
	
		csvParser(std::string fileNameArg) {
			fileName = fileNameArg;
		// Read the csv file & adds the data to 2d vector called fileData
			std::ifstream fileRead(fileName);
			std::string text;		 	
			while (getline(fileRead, text)) {
				// REGEX for splitting string by comma
				std::vector<std::string> result = split(text, ',');
				fileData.push_back(result);
			}
			char buff[4096];
			// count the amount of rows
			while(fileRead.read(buff, sizeof(buff)) || fileRead.gcount())
			{
				rows += std::count(buff, buff + fileRead.gcount(), '\n');
			}
			fileRead.close();

		}
		std::vector<std::vector<std::string>> get(int rowMin, int rowMax, int columnMin, int columnMax) {
			std::vector<std::vector<std::string>> result{};
			for (int i = rowMin; i < rowMax; i++){
				std::vector<std::string> tempResult{};
				for (int j = columnMin; j < columnMax; j++) {
					tempResult.push_back(fileData[i][j]);
				}
				result.push_back(tempResult);
			}
			return result;
		}

		// Given min & max, return 2d vector of rows in csv file
		std::vector<std::vector<std::string>> getRows(int min, int max) {				
			std::vector<std::vector<std::string>> result{};
			for (int i = min; i < max; i++) {
				std::vector<std::string> tempResult{};
				for (int j = 0; j < fileData[min].size(); j++){	   
					tempResult.push_back(fileData[i][j]);	
				}
				result.push_back(tempResult);
			}
			return result;
		}
		// given row number, return 1d vector of row in csv file
		std::vector<std::string> getRow(int row) {
			std::vector<std::string> result{};
			for (int i = 0; i < fileData[row].size(); i++) {
				result.push_back(fileData[row][i]);
			}
			return result;
		}
		// given column number, return 1d vector of column in csv file
		std::vector<std::string> getColumn(int column) {
			std::vector<std::string> result {};
			for (int i = 0; i < fileData.size(); i++) {
				result.push_back(fileData[i][column]);
			}
			return result;
		}
		// Given min & max, return 2d vector of columns in csv file
		std::vector<std::vector<std::string>> getColumns(int min, int max) {
			std::vector<std::vector<std::string>> result {};
			for (int i = min;i < max; i++) {
				std::vector<std::string> tempResult {};
				for (int j = 0; j < fileData.size(); j++) {
					tempResult.push_back(fileData[j][i]);
				}
				result.push_back(tempResult);
			}
			return result;
		}
};

int main() {

	time_t timeStart = time(0);

	csvParser data {"dataTest/charts.csv"};

	// print out two 2d array of csv file

	int dataRows = data.fileData.size();
	int dataColumns = data.fileData[0].size();

	time_t timeEnd = time(0);

	double executionTime = difftime(timeEnd, timeStart) * 1000;

	std::cout << "Indexed " << dataRows * dataColumns << " items in " << executionTime << " milliseconds | " << "Rows: " << dataRows << " Columns: " << dataColumns << std::endl;

	std::vector<std::vector<std::string>> columnTest = data.get(299990,300000,0,4);

	for (int i = 0;i < columnTest.size(); i++){
		for (int j = 0; j < columnTest[i].size(); j++) {
			std::cout << columnTest[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
