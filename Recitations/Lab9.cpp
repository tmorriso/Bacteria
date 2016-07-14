#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//----These are the functions you must write for the lab
char encryptChar(char toEncrypt, int offset);
char recEncryptChar(char toEncrypt,int offset);
char decryptChar(char toDecrypt, int offset);
char recDecryptChar(char toDecrypt,int offset);
//-------------------------------------------------------
string readFile(string fileName);
int getOffset(int theOffset);
string encryptMessage(string message, int offset);
string decryptMessage(string message, int offset);
void writeToFile(string message, string filename, string command);
bool specialRange(char aChar);

//---------------DO NOT CHANGE MAIN----------------------------------------

int main(int argc, char* argv[]){

	string command=argv[1];
	int offset=stoi(argv[2]);
	offset=getOffset(offset);
	
	string fileName=argv[3];
	string message=readFile(fileName);
	if(command=="-e"){
		cout<<"Encrypting file: "<<fileName<<endl;
		cout<<message<<endl;
		string newMessage=encryptMessage(message,offset);
		cout<<newMessage<<endl;
		writeToFile(newMessage,fileName,command);
	}
	else if(command=="-d"){
		cout<<"Decrypting file: "<<fileName<<endl;
		cout<<message<<endl;
		string newMessage=decryptMessage(message,offset);
		cout<<newMessage<<endl;
		writeToFile(newMessage,fileName,command);
	}
	else{
		cout<<"Incorrect command."<<endl;
	}

	return 0;
}



//-----------Functions to write for Lab9----------------------
char recEncryptChar(char toEncrypt,int offset)
{
	if (offset == 0 )
		return toEncrypt;
	if (toEncrypt == 'z' || toEncrypt == 'Z')
			return recEncryptChar(toEncrypt-25, offset-1);
	else
		return recEncryptChar(toEncrypt+1, offset-1);

}

char recDecryptChar(char toDecrypt,int offset)
{ 
	if (offset == 0 )
		return toDecrypt;
	if (toDecrypt == 'a' || toDecrypt == 'A')
			return recDecryptChar(toDecrypt+25, offset-1);
	else
		return recDecryptChar(toDecrypt-1, offset-1);
	

	
}


//-----------------------------Extra Functions to make your life easier-----------------------------------------


bool specialRange(char aChar){ //returns true if aChar is not between a-z or A-Z
	if(aChar<65){
		return true;
	}
	if(aChar>90 && aChar<97){
		return true;
	}
	if(aChar>122){
		return true;
	}
	return false;
}


int getOffset(int theOffset){ //normalizes offset to be between 0-26
	int offset=theOffset;
	offset=offset%26;
	if(offset<0){
		offset=26+offset;
	}
	return offset;
}


//-----------------------------From HW7---------------------------------


char encryptChar(char toEncrypt, int offset) //checks if toEncrypt is a special character, else call recEncryptChar
{
	if(specialRange(toEncrypt)){
		return toEncrypt;
	}

	else{
		return recEncryptChar(toEncrypt,offset);
	}
		
}

char decryptChar(char toDecrypt, int offset){ //checks if toEncrypt is a special character, else call recDecryptChar
	if(specialRange(toDecrypt)){
		return toDecrypt;
	}

	else{
		return recDecryptChar(toDecrypt,offset);
	}
}



string readFile(string fileName){
	ifstream theFile;
	theFile.open(fileName);
	string fromFile;
	getline(theFile, fromFile);
	theFile.close();
	return fromFile;
}

string encryptMessage(string message, int offset){
	string encrypted;
	for(int i=0; i<message.length(); i++){
		encrypted=encrypted+encryptChar(message[i],offset);
	}
	return encrypted;
}

string decryptMessage(string message, int offset){
	string decrypted;
	for(int i=0; i<message.length(); i++){
		decrypted=decrypted+decryptChar(message[i],offset);
	}

	return decrypted;
}

void writeToFile(string message, string filename, string command){
	ofstream theFile;
	if(command=="-e"){
		string theFileName=filename+".enc";
		theFile.open(theFileName);

		theFile<<message;

		theFile.close();

	}

	else if(command=="-d"){
		string theFileName=filename+".dec";
		theFile.open(theFileName);

		theFile<<message;

		theFile.close();
	}

	else{
		cout<<"Incorrect command."<<endl;
	}

	theFile.close();
}













