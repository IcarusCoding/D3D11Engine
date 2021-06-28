#pragma once

#include <chrono>

class FPSCounter {

private:
	clock_t start;
	int frames;

public:
	FPSCounter() noexcept;
	void Tick();
	int GetFrames();
	bool HasSecondPassed();
	void Reset();

};

