//Player header file
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
	// instance variables 
	private:
		std::string id;
		int score; 
		
	// Functions
	public:
		Player();
		Player(std::string, int);
		std::string getId();
		int getScore();
		void setId(std::string);
		void setScore(int);
		std::string toString();
		//int getWinner(Player otherPlayer); // Future work
};
#endif
