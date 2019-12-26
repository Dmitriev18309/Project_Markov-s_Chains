#include "MarcovsChains.h"

using namespace std;

Mchain::Mchain(const char *file_name){
 		try{
		 	ifstream fin(file_name);
 			if(fin.is_open() == false) throw "can't open the file";
 			const char *prev_word = nullptr;
 			string line;
			while(getline(fin,line)) {
				istringstream sbase(line);
				string str;
				while(getline(sbase,str,' ')) {
					auto *word = getWord(str);
					Dict[prev_word].push_back(word);
					if(isupper(word[0])){
						FirstWords.insert(word);
					}
					prev_word=word;
				}
			}
 			fin.close();
 		}	
		catch(char *error){
			cout<<error;
		}
}

const char* Mchain::getWord(const string &str){
		return Words.insert(str).first->c_str();
}
	
static int getRandomNum(int max){
 return rand()%max;
}

const char* Mchain::getNextWord(const char *word){
	return Dict[word][getRandomNum(Dict[word].size())];
}

void Mchain::generate(ostream &out,int n){
	string sequence;
	auto isLast = [&](const char *word) -> bool {
		string str(word);
		return str.back() == '.' || str.back() == '!' || str.back() == '?';
	};
	const char* word = *std::next(FirstWords.begin(), getRandomNum(FirstWords.size()));
	while(n){
		sequence+=word;
		if(isLast(word)){
			sequence+='\n';
			--n;
		}
		sequence+=" ";
		word=getNextWord(word);
	}
	out<<sequence;
}


