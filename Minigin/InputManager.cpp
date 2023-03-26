#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "xinput.lib") //places a library record file
#include <SDL.h>
#include "InputManager.h"
#include "imgui_impl_sdl2.h"
#include <iostream>
#include "Command.h"
//PIMPL DID NOT WORK DUE TO USE OF UNDEFINED TYPE, BUT DO NOT UNDERSTAND THE DIFFERENCE BETWEEN THIS AND CONTROLLER
//using namespace dae;
//class InputManager::InputManagerImpl
//{
//public:
//	InputManagerImpl() {};
//	void InitializeDefaultCommands()
//	{
//
//	}
//	bool ProcessInput()
//	{
//		//1. update controllers to check input
//		for (auto& controller : m_VectorControllers)
//		{
//			controller->Update();
//		}
//
//
//
//
//		SDL_Event e;
//		while (SDL_PollEvent(&e)) {
//			if (e.type == SDL_QUIT) {
//				return false;
//			}
//			if (e.type == SDL_KEYDOWN) {
//
//			}
//			if (e.type == SDL_MOUSEBUTTONDOWN) {
//
//			}
//			//IMGUI input
//			ImGui_ImplSDL2_ProcessEvent(&e);
//			// etc...
//		}
//
//		return true;
//	}
//
//
//private:
//	using ControllerKey = std::pair<unsigned, Controller::ControllerButton>;
//	using ControllerCommandsMap = std::map<ControllerKey, std::unique_ptr<Command>>;
//	ControllerCommandsMap m_controllerCommands{};
//
//	std::vector<std::unique_ptr<Controller>> m_VectorControllers{};
//
//};




bool dae::InputManager::ProcessInput()
{
	//1. update controllers to check input
	for (auto& controller : m_VectorControllers)
	{
		//update
		controller->Update();
	}



	SDL_Event e;
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&e))
	{
		//check keyboard imput
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {

		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {

		}
		//IMGUI input
		ImGui_ImplSDL2_ProcessEvent(&e);
		// etc...
		if (keystate[SDL_SCANCODE_UP])
		{
			std::cout << "up pressed" << std::endl;
		}
	}

	return true;

	//return m_pImpl->ProcessInput();
}

dae::InputManager::InputManager()
	//: m_pImpl {std::make_unique<InputManagerImpl>()}
{
	//is it okay to initialise the pimpl in the member init list? 
	std::cout << "Initialising InputManager: " << std::endl;
	DWORD dwResult;
	for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		dwResult = XInputGetState(i, &state);

		if (dwResult == ERROR_SUCCESS)
		{
			m_VectorControllers.push_back(std::make_unique<Controller>(i));
		}
		else
		{
			std::cout << "There is no controller with idx: " << i << std::endl;
		}
	}
}

//
void dae::InputManager::AddConsoleCommand(unsigned int controllerIndex, Controller::ControllerButton button, Command* command)
{
	if (controllerIndex <= m_VectorControllers.size() - 1)
	{
		
		std::pair<unsigned, Controller::ControllerButton> controllerKey{ std::pair<unsigned, Controller::ControllerButton>(controllerIndex, button) };
		
		//m_controllerCommands[controllerKey] = std::make_unique<Command>(command);


	}
	else
	{
		std::cout << "This Controller Index does not exist!" << std::endl;
	}
}
