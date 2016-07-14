// Player.cpp
// @author: Thomas Morrison
// November 29, 2015
// Project 2 
//---------------------------------------
// Purpose: Player Class to keep track of 
//             players and scores. 
//                          
//---------------------------------------

#include <iostream>
#include <string> 
#include "Player.h"

using namespace std; 

Player::Player()
{
	id = "Unknown";
	score = 0;
	
}

Player::Player(string playerid, int playerscore)
{
	id = playerid;
	score = playerscore;
}

string Player::getId()
{
	return id;
}

int Player::getScore()
{
	return score; 
}

void Player::setId(string idb)
{
	id = idb;
}

void Player::setScore(int scr)
{
	score = score + scr;
}

string Player::toString()
{
	string s = to_string(score);
	return " ID = " + id + ": Score = " + s;
}

