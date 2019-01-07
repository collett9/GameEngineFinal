#pragma once
#include <fmod_studio.hpp>
#include <fmod.hpp>
#include <string>
#include <vector>
#include "gameEvent.h"

class audioSystem
{
public:

	FMOD::Studio::System* system;
	FMOD::System* lowLevelSystem;
	FMOD::Channel* channelToUse = NULL;
	FMOD::Sound* soundToUSe = NULL;

	std::vector <FMOD::Sound*> gameSounds;
	std::vector <int> soundIds;

	audioSystem();
	~audioSystem();
	void loadSound(char fileName[]);
	//void playAudio(std::string soundName);
	void playAudio(int soundIdToPlay);
	void audioEventSolver(gameEvent * gameEventToSolve);
	//void playAudio(std::string soundFilename);
};

