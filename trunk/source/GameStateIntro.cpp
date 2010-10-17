#include "GameStateIntro.h"

GameStateIntro::GameStateIntro(){
}

GameStateIntro::~GameStateIntro(){
}

void GameStateIntro::Initialize(){
	for(int x = 0; x < 500; x++)
	//***********************GET RID OF ME
	pixel(rand() % 256, rand() % 192, RGB15(rand()%31, rand()%31, rand()%31));
	//****************
}

void GameStateIntro::Update(){
}

void GameStateIntro::Draw(){
	//***********************GET RID OF ME
	pixel(rand() % 256, rand() % 192, RGB15(rand()%31, rand()%31, rand()%31));
	//***********************GET RID OF ME
}

void GameStateIntro::Cleanup(){
}

void GameStateIntro::Pause(){
}

void GameStateIntro::Resume(){
}
