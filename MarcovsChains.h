#pragma once
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>


class Mchain {
private:
	std::unordered_set<std::string> Words;
	std::unordered_set<const char *> FirstWords;
	std::unordered_map<const char *, std::vector<const char *>>Dict;
	
	const char* getWord(const std::string &str);
	const char* getNextWord(const char *word);
public:
    Mchain(const char *file_name);
    void generate(std::ostream &out,int n);
};

