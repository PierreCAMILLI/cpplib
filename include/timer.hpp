#pragma once

#include <cstdio>
#include <ctime>

typedef std::clock_t TimeInstance;

class Timer
{
	private:
		static TimeInstance start;
	public:
		static void Reset(){	start = std::clock();	}
		static TimeInstance const CurrentTime() {	return std::clock();	}

		static double Duration(){	return ( std::clock() - start ) / (double) CLOCKS_PER_SEC;	}
		static double DurationSince(const TimeInstance& start_){	return ( std::clock() - start_ ) / (double) CLOCKS_PER_SEC;	}
	
};