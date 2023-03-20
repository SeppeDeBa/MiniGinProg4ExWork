#pragma once
#include <string>
#include <functional>
#include "Component.h"

namespace dae
{
	class Minigin
	{
	public:
		explicit Minigin(const std::string& dataPath);
		~Minigin();
		void Run(const std::function<void()>& load);

		Minigin(const Minigin& other) = delete;
		Minigin(Minigin&& other) = delete;
		Minigin& operator=(const Minigin& other) = delete;
		Minigin& operator=(Minigin&& other) = delete;
	private:
		const float m_fixedTimeStep{0.02f};//0.016 should be 60 fps, check this
		const float m_desiredFPS{ 60.f };
	};
}