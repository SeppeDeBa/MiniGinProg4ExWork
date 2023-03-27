#pragma once
#include <memory>
#include "Singleton.h"
#include <utility>
#include "Controller.h"
#include "Command.h"
#include <map>
namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
		//class InputManagerImpl;
		//std::unique_ptr<InputManagerImpl> m_pImpl;
		
		using ControllerKey = std::pair<unsigned int, dae::Controller::ControllerButton>;
		using ControllerCommandsMap = std::map<ControllerKey, std::unique_ptr<Command>>;
		ControllerCommandsMap m_controllerCommands{};

		std::vector<std::unique_ptr<Controller>> m_VectorControllers{};

		std::unique_ptr<Command> arrowUp;


	public:
		bool ProcessInput();
		InputManager();
		void AddConsoleCommand(unsigned int controllerIndex, Controller::ControllerButton button, std::unique_ptr<dae::Command>& command);
	//	void SetUpArrow(Command* command) { arrowUp = std::make_unique<Command>(command);};
	};
}
