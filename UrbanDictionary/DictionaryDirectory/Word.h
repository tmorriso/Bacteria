// Word header file
#ifndef WORD_H
#define WORD_H
class Word
{
	// Instance variables 
	private:
		std::string word; 
		std::string definition;
	// Functions
	public:
		Word();
		Word(std::string, std::string);
		std::string getWord();
		std::string getDefinition();
		void setWord(std::string);
		void setDefinition(std::string);
		std::string wordToString();
		std::string definitionToString();
};
#endif
	
