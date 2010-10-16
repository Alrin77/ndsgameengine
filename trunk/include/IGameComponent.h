#pragma once

class IGameManager{
public:
	virtual void Initialize()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void Cleanup()=0;
};