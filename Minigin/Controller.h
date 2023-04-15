#pragma once
#include "memory"
namespace dae
{
	class Controller final
	{
		class ControllerImpl;
		std::unique_ptr<ControllerImpl> m_pImpl;
		unsigned int m_controllerIndex;
	public:
		enum class ControllerButton
		{
			DpadUp = 0x0001,
			DPadDown = 0x0002,
			DpadLeft = 0x0004,
			DPadRight = 0x0008,

			Start = 0x0010,
			Back = 0x0020,

			LeftThumb = 0x0040,
			RightThumb = 0x0080,

			LeftShoulder = 0x0100,
			RightShoulder = 0x0200,

			ButtonA = 0x1000,
			ButtonB = 0x2000,
			ButtonX = 0x4000,
			ButtonY = 0x8000
		};

		void Update();
		unsigned int GetControlledIdx() const { return m_controllerIndex; };
		bool IsDown(ControllerButton button) const;
		bool IsUp(ControllerButton button) const;
		bool IsPressed(ControllerButton button) const;

		explicit Controller(unsigned int controllerIndex);
		~Controller();
		
	};
}
