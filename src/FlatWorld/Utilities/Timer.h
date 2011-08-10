#pragma once

#include <SFML/System.hpp>

namespace FlatWorld
{
	class Timer
	{
    public:
        Timer();
        Timer(float readyPerSecond);
        ~Timer();

        void Init(float readyPerSecond);

        void Update();
        bool Ready();
        bool ReadyAndReinit();
        float DT();

        void TimeScale(float timeScale);
        float TimeScale() { return _timeScale; }

    private:
	    sf::Clock _clock;

	    float _dt;
	    float _interval;

	    float _timeScale;

	};
}
