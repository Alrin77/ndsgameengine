#include "GameStateIntro.h"

GameStateIntro::GameStateIntro(IGameStateManager* machine){
	this->SetManager(machine);
}

GameStateIntro::~GameStateIntro(){
	this->SetManager(NULL);
}


void GameStateIntro::Initialize(){}

void GameStateIntro::Update(){}

void GameStateIntro::Draw(){}

void GameStateIntro::Cleanup(){}

void GameStateIntro::Pause(){}

void GameStateIntro::Resume(){}
