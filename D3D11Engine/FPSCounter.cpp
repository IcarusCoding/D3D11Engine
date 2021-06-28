#include "FPSCounter.h"

FPSCounter::FPSCounter() noexcept {}

void FPSCounter::Tick() {
	frames++;
}

int FPSCounter::GetFrames() {
	return frames;
}

bool FPSCounter::HasSecondPassed() {
	return (((clock() - start) / (double) CLOCKS_PER_SEC) * 1000) > 1000;
}

void FPSCounter::Reset() {
	start = clock();
	frames = 0;
}
