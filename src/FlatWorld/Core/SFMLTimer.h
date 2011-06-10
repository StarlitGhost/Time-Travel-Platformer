#pragma once

// Forward Declarations
namespace sf{class Window;}

namespace FlatWorld
{
	class CSFMLTimer
	{
	public:
		CSFMLTimer(void);
		CSFMLTimer(const float& timeCount, sf::Window& GameWindow);
		~CSFMLTimer(void);
	
		void Init(const float& timeCount, sf::Window& GameWindow);

		void Update();

		bool Ready();

		float DT() const {return dt * timeScale;};

		float TimeScale() const {return timeScale;};
		void TimeScale(const float& timeScale) {timeScale >= 0.f ? this->timeScale = timeScale : this->timeScale = 0.f;};

	private:
		float dt;
		float timeScale;
		float totalDt, intervalDt;
		sf::Window* GameWindow;

	};
}