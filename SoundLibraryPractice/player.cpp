/** Your Name:
 * 	Assignment:
 * 	Date:
 **/
 
 /* ---------------------------------------------------------------
  * The Song class uses libsndfile and portaudio to read in, play,
  * and modify, array representations of WAV files.
  * ---------------------------------------------------------------
  * Modified from libsndfile and portaudio examples
  * Additional tips from: 
  * http://ubuntuforums.org/showthread.php?t=968690
  * http://music.columbia.edu/pipermail/portaudio/2009-December/009731.html
  * ---------------------------------------------------------------
  */

#include "sndfile.h"	//Provides libsndfile
#include "portaudio.h" 	//Provides libportaudio
#include <sstream>		//Provides stringstream
#include <cstdlib>      // Provides size_t and EXIT_SUCCESS
#include <iostream>     // Provides cin and cout
#include <string>       // Provides the string class

using namespace std;

struct SoundData
{
  const char* name;
  SNDFILE *sndFile;
  SF_INFO sfInfo;
  int position;
};

class Song{
	
	public:
		Song(const char* filename); 
		~Song();
		SoundData toStruct();
		SoundData* getStructPointer() { return myData; }
		void play(unsigned long long int secondsToPlay);
		void save_as(const char* outfilename);
		void reload();
		void close();

		//functions you need to add
		std::string toString(); 
		void change_speed(double factor);
		void change_volume(double factor);
		void reverse(); 
		void echo(unsigned long long int echoFactor);
		void fade_out(); //bonus function

	private:
		SNDFILE *mySndFile;
		SF_INFO myInfo;
		int myPosition;
		const char* myName;
		SoundData * myData;
		double * playbackData;
		unsigned long long int playbackDataSize;

		//private method to interact with audio libraries
		int playSong(unsigned long long int secondsToPlay, SoundData* data);
		
};

int main()
{
	
	Song mySong("kmun.wav"); //load a song
	cout << "The song you've loaded is: " << mySong.toString() << endl; //to string
	
	//make modifications between these lines
	mySong.change_speed(.3);
	//mySong.change_volume(2);
	mySong.reverse();

	
	
	//make modifications between these lines
	
	mySong.save_as("player-modified.wav");
	mySong.close(); //close old song before playing modifications
	
	Song modifiedSong("player-modified.wav");
	modifiedSong.play(15);
 
	
	
	
}

/* Creates a string representing the song file */
string Song::toString()
{
	std::stringstream ss, ss2;
	std::string songName(myName); 
	std::string str = "Name: " + songName;
	str += " Samplerate: ";
	str += to_string(myInfo.samplerate); // convert int
 return str;
	
}

/* Changes the speed at which the song plays
 * by modifying the sample rate of the song file
 * by factor
 */
void Song::change_speed(double factor)
{
	myInfo.samplerate = myInfo.samplerate * factor;
	if (myInfo.samplerate > 48484)
		myInfo.samplerate = 48484;

	
}


/* Changes the volume at which the song plays
 * by modifying the volume of each sample in 
 * the song file
 */
void Song::change_volume(double factor)
{
	for(int i = 0; i < playbackDataSize; i++)
	{
		playbackData[i] = (playbackData[i] * factor);
	}
	
}


/* adds an echo to the song starting at echoFactor */
void Song::echo(unsigned long long int echoFactor)
{
    
}

/* reverses the song by reversing playbackData */
void Song::reverse()
{
	
}

/* changes the song so that it fades out gradually */
void Song::fade_out() 
{

}

//----------------------------------------------------------------------------
// Main class body: do NOT modify below this liine 
//----------------------------------------------------------------------------

/* constructor */
Song::Song(const char* filename)
{
	myPosition = 0;
	myInfo.format = 0;
	 
	/* try to open the file */
	mySndFile = sf_open(filename, SFM_READ, &myInfo);
	myName = filename;
	
	 //make playback array
	 int itemsToRead = myInfo.frames * myInfo.channels;
	 playbackData = new double[itemsToRead];
	 playbackDataSize = sf_read_double(mySndFile, playbackData, itemsToRead);

}

/* destructor */
Song::~Song()
{
		sf_close(mySndFile);
		delete [] playbackData;
		playbackData = NULL;
}
	
/* callback function for audio output */
int myCallback(const void *input,
             void *output,
             unsigned long frameCount,
             const PaStreamCallbackTimeInfo* paTimeInfo,
             PaStreamCallbackFlags statusFlags,
             void *userData)
{
	  SoundData *data = (SoundData *)userData; /* we passed a data structure into the callback so we have something to work with */
	  int *cursor; /* current pointer into the output  */
	  int *out = (int *)output;
	  int thisSize = frameCount;
	  int thisRead;

	  cursor = out; /* set the output cursor to the beginning */
	  while (thisSize > 0)
	  {
		/* seek to our current file position */
		sf_seek(data->sndFile, data->position, SEEK_SET);

		/* are we going to read past the end of the file?*/
		if (thisSize > (data->sfInfo.frames - data->position))
		{
		  /*if we are, only read to the end of the file*/
		  thisRead = data->sfInfo.frames - data->position;
		  /* and then loop to the beginning of the file */
		  data->position = 0;
		}
		else
		{
		  /* otherwise, we'll just fill up the rest of the output buffer */
		  thisRead = thisSize;
		  /* and increment the file position */
		  data->position += thisRead;
		}

		/* since our output format and channel interleaving is the same as
		   sf_readf_int's requirements */
		   
		/* we'll just read straight into the output buffer */
		sf_readf_int(data->sndFile, cursor, thisRead);
		/* increment the output cursor*/
		cursor += thisRead;
		/* decrement the number of samples left to process */
		thisSize -= thisRead;
	  }

	  return 0;
}

/* plays the songfile for secondsToPlay seconds
 * directly interfaces with portaudio methods 
 */
int Song::playSong(unsigned long long int secondsToPlay, SoundData* data)
{
	
	PaStream *stream;
	PaError error;
	PaStreamParameters outputParameters;
	 
	  /* start portaudio */
	  Pa_Initialize();

	  /* set the output parameters */
	  outputParameters.device = 0;//Pa_GetDefaultOutputDevice(); /* use the default device */
	  outputParameters.channelCount = data->sfInfo.channels; /* use the same number of channels as our sound file */
	  outputParameters.sampleFormat = paInt32; /* 32bit int format */
	  outputParameters.suggestedLatency = 0.2; /* 200 ms ought to satisfy even the worst sound card */
	  outputParameters.hostApiSpecificStreamInfo = 0; /* no api specific data */
			 
	  /* try to open the output */
	  error = Pa_OpenStream(&stream,  // stream is a 'token' that we need to save for future portaudio calls */
							0,  // no input 
							&outputParameters,
							data->sfInfo.samplerate,  // use the same sample rate as the sound file 
							paFramesPerBufferUnspecified,  // let portaudio choose the buffersize 
							paNoFlag,  // no special modes (clip off, dither off) 
							myCallback,  /* callback function defined above */
							data ); /* pass in our data structure so the
	callback knows what's up */

	  /* if we can't open it, then bail out */
	  if (error)
	  {
		printf("\nerror opening output, error code = %i\n", error);
		Pa_Terminate();
		return 1;
	  }

	  /* when we start the stream, the callback starts getting called */
	  printf("\nstarting playback\n\n");
	  Pa_StartStream(stream);
	  Pa_Sleep(secondsToPlay*1000); /* pause for secondsToPlay seconds so we can hear a bit	of the output */
	  Pa_StopStream(stream); // stop the stream
	  Pa_Terminate(); // and shut down portaudio
	  return 0;
}

/* save the results of modifications as outfilename */
void Song::save_as(const char* outfilename)
{
	SNDFILE* outfile;
	outfile = sf_open(outfilename, SFM_WRITE, &myInfo);
	sf_write_double (outfile, playbackData, playbackDataSize);
	sf_write_sync(outfile);
	sf_close(outfile);
}

void Song::reload()
{
	 
	/* try to open the file */
	close();
	mySndFile = sf_open(myName, SFM_READ, &myInfo);
	
	
	 //make playback array
	 int itemsToRead = myInfo.frames * myInfo.channels;
	 playbackData = new double[itemsToRead];
	 playbackDataSize = sf_read_double(mySndFile, playbackData, itemsToRead);
	
}

/* plays the song, wrapper to simplify playback */
void Song::play(unsigned long long int secondsToPlay)
{	
	SoundData *data = (SoundData *)malloc(sizeof(SoundData));
	data->position = myPosition;
	data->sfInfo = myInfo;
	data->sndFile = mySndFile;
	
	playSong(secondsToPlay, data);
}

/* close the song file 
 * must be called before another song is played!*/
void Song::close()
{
	sf_close(mySndFile);
		delete [] playbackData;
		playbackData = NULL;
}
