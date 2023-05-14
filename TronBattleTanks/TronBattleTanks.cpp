#include <SDL.h>


#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

//#include "TextObject.h"
#include "GameObject.h"

//#include "Component.h"
#include "TextureComponent.h"
#include "Scene.h"
#include "Transform.h"
#include "FPSComponent.h"
#include "TextComponent.h"
#include "RotatorComponent.h"

//Commands
#include "MoveCommand.h"
#include "Command.h"
#include "GameObjectCommand.h"
#include "MoveCommand.h"

void load()
{

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	//CAN APPLY RAII?
	//Load in font
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	auto fpsfont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 15);
	auto scoreboardfont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 14);

	//SPINNING EXERCISE
	//== BACKGROUND OBJECT ==
	//1. Initialize the pointers needed for the object 
	dae::GameObject* bgo = new dae::GameObject{};
	//2. Fill in the gameObject
	bgo->AddComponent<dae::Transform>(0.f, 0.f);
	bgo->AddComponent<dae::TextureComponent>("Background.tga");
	//dae::TextureComponent* bgoTextureComponent = new dae::TextureComponent("Background.tga");
	//dae::Transform* bgoTransformComponent = new dae::Transform(0.f, 0.f);

	//3. Add the pointer to the GameObjectPtr Vector in the scene	
	scene.Add(bgo);



	////== LOGO OBJECT ==
	////1. Initialize the pointers needed for the object 
	//dae::GameObject* logoObject = new dae::GameObject{};
	////2. Fill in the gameObject
	//logoObject->AddComponent<dae::TextureComponent>("logo.tga", false);
	//logoObject->AddComponent<dae::Transform>(216.f, 90.f);
	////3. Add the pointer to the GameObjectPtr Vector in the scene	
	//scene.Add(logoObject);





	//== TITLE OBJECT ==
	//1. Initialize the pointers needed for the object 
	dae::GameObject* to = new dae::GameObject{};
	//2. Fill in the gameObject
	to->AddComponent<dae::Transform>(20.f, 20.f);
	to->AddComponent<dae::TextureComponent>(false);
	to->AddComponent<dae::TextComponent>("numpad = movement, X = take damage, Y/B/A = different AddScore Values", scoreboardfont);
	//3. Add the pointer to the GameObjectPtr Vector in the scene	
	scene.Add(to);



	//== FPS OBJECT ==
	//1. Initialize the pointers needed for the object 
	dae::GameObject* fpsto = new dae::GameObject{};
	//2. Fill in the gameObject
	fpsto->AddComponent<dae::Transform>(5.f, 5.f);
	fpsto->AddComponent<dae::TextureComponent>(false);
	fpsto->AddComponent<dae::TextComponent>("FPS", fpsfont);
	fpsto->AddComponent<dae::FPSComponent>();
	//3. Add the pointer to the GameObjectPtr Vector in the scene	
	scene.Add(fpsto);



	// START OF ROTATION EXERCISE //
	////CENTER POINT WHICH EVERYTHING REVOLVES AROUND
	//dae::GameObject* centerPoint = new dae::GameObject{};
	//centerPoint->AddComponent<dae::TextureComponent>("sun.png", true);
	//centerPoint->AddComponent<dae::Transform>( 640.f/ 2.f , 480 / 2.f);
	////g_Window is stored in Minigin, not sure how to get it from there yet so using magic numbers, also manually made it so it draws on center.
	//scene.Add(centerPoint);
	//

	////== EARTH  OBJECT ==
	////1. Initialize the pointers needed for the object 
	//dae::GameObject* earthObject = new dae::GameObject{};
	////2. Fill in the gameObject
	//const float earthRotationSpeed{ 365.f/20.f };
	//earthObject->AddComponent<dae::TextureComponent>("earth.png",true);
	//earthObject->AddComponent<dae::Transform>(0.f, 0.f); //just need to have one
	//earthObject->AddComponent<dae::RotatorComponent>( 140.f ,earthRotationSpeed, false);
	//earthObject->SetParent(centerPoint, false);
	////3. Add the pointer to the GameObjectPtr Vector in the scene	
	//scene.Add(earthObject);


	//== MOON  OBJECT ==
	//dae::GameObject* moonObject = new dae::GameObject{};
	////2. Fill in the gameObject
	//moonObject->AddComponent<dae::TextureComponent>("moon.png",true);
	//moonObject->AddComponent<dae::Transform>(0.f, 0.f); //just need to have one
	//moonObject->AddComponent<dae::RotatorComponent>(45.f, earthRotationSpeed*24.f, true);
	//moonObject->SetParent(earthObject, false);
	////3. Add the pointer to the GameObjectPtr Vector in the scene	
	//scene.Add(moonObject);




	//MOVABLE P1
	//== MOON ONE ==
	//can replace moonObjectOne by just the name playerOne
	dae::GameObject* moonObjectOne = new dae::GameObject{};
	//const int playerOneNumber{ 1 };
	//const int p1Health{ 5 };
	//2. Fill in the gameObject
	moonObjectOne->AddComponent<dae::TextureComponent>("moon.png", true);
	moonObjectOne->AddComponent<dae::Transform>(640 / 3.f, 480 / 4.f * 3);
	//3. Add the pointer to the GameObjectPtr Vector in the scene	
	scene.Add(moonObjectOne);




	//MOVABLE P2
		//== MOON TWO ==
	dae::GameObject* moonObjectTwo = new dae::GameObject{};
	//const int playerTwoNumber{ 2 };
	//const int p2Health{ 5 };
	//2. Fill in the gameObject
	moonObjectTwo->AddComponent<dae::TextureComponent>("moon.png", true);
	moonObjectTwo->AddComponent<dae::Transform>(640 / 3.f * 2, 480 / 4.f * 3);
	//3. Add the pointer to the GameObjectPtr Vector in the scene	
	scene.Add(moonObjectTwo);

	//THESE COULD BE EITHER MADE INTO ONE CLASS OR JUST HAVE A PARENT CHILD LOCATION FOR A UI GROUP (this might be my prefered method)
	//  =====OBSERVERS=====
	//Adding p1 Scoreboard -> Same as using a normal textGO, but using HealthUiObserverComp since it also is a textComp
	dae::GameObject* p1healthInfo = new dae::GameObject{};
	p1healthInfo->AddComponent<dae::Transform>(10.f, 350.f);
	p1healthInfo->AddComponent<dae::TextureComponent>(false);
	scene.Add(p1healthInfo);

	dae::GameObject* p1Scoreboard = new dae::GameObject{};
	p1Scoreboard->AddComponent<dae::Transform>(10.f, 370.f);
	p1Scoreboard->AddComponent<dae::TextureComponent>(false);
	scene.Add(p1Scoreboard);


	//player two observer
	dae::GameObject* p2healthInfo = new dae::GameObject{};
	p2healthInfo->AddComponent<dae::Transform>(10.f, 420.f);
	p2healthInfo->AddComponent<dae::TextureComponent>(false);
	scene.Add(p2healthInfo);

	dae::GameObject* p2Scoreboard = new dae::GameObject{};
	p2Scoreboard->AddComponent<dae::Transform>(10.f, 440.f);
	p2Scoreboard->AddComponent<dae::TextureComponent>(false);
	scene.Add(p2Scoreboard);




	//  =====INPUT=====
	auto& input = dae::InputManager::GetInstance();
	[[maybe_unused]] const unsigned int controllerOne{ 0 }, controllerTwo{ 1 };
	//==PLAYER ONE
	const float moveSpeed{ 100.f };
	//up
	input.AddConsoleCommand(controllerOne, dae::Controller::ControllerButton::DpadUp,
		std::make_unique<dae::MoveCommand>(moonObjectOne, moveSpeed,
			glm::vec2{ 0.f, 1.f }), dae::InputType::ISHELD);

	//down
	input.AddConsoleCommand(controllerOne, dae::Controller::ControllerButton::DPadDown,
		std::make_unique<dae::MoveCommand>(moonObjectOne, moveSpeed,
			glm::vec2{ 0.f, -1.f }), dae::InputType::ISHELD);

	//left
	input.AddConsoleCommand(controllerOne, dae::Controller::ControllerButton::DpadLeft,
		std::make_unique<dae::MoveCommand>(moonObjectOne, moveSpeed,
			glm::vec2{ -1.f, 0.f }), dae::InputType::ISHELD);

	//right
	input.AddConsoleCommand(controllerOne, dae::Controller::ControllerButton::DPadRight,
		std::make_unique<dae::MoveCommand>(moonObjectOne, moveSpeed,
			glm::vec2{ 1.f, 0.f }), dae::InputType::ISHELD);







	//==PLAYER TWO
	//Up
	input.AddKeyboardCommand(SDL_SCANCODE_UP,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ 0.f, 1.f }));
	input.AddConsoleCommand(controllerTwo, dae::Controller::ControllerButton::DpadUp,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ 0.f, 1.f }), dae::InputType::ISHELD);

	//Down
	input.AddKeyboardCommand(SDL_SCANCODE_DOWN,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ 0.f, -1.f }));
	input.AddConsoleCommand(controllerTwo, dae::Controller::ControllerButton::DPadDown,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ 0.f, -1.f }), dae::InputType::ISHELD);

	//left
	input.AddKeyboardCommand(SDL_SCANCODE_LEFT,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ -1.f, 0.f }));
	input.AddConsoleCommand(controllerTwo, dae::Controller::ControllerButton::DpadLeft,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ -1.f, 0.f }), dae::InputType::ISHELD);

	//right
	input.AddKeyboardCommand(SDL_SCANCODE_RIGHT,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ 1.f, 0.f }));
	input.AddConsoleCommand(controllerTwo, dae::Controller::ControllerButton::DPadRight,
		std::make_unique<dae::MoveCommand>(moonObjectTwo, moveSpeed,
			glm::vec2{ 1.f, 0.f }), dae::InputType::ISHELD);


	//release pointers for rotating object
	//earthObject = nullptr;
	//moonObject = nullptr;
	//centerPoint = nullptr; 

	// END OF ROTATION EXERCISE //

	//Set all nullptrs just for safety of leaks
	//bgo = nullptr;
	//logoObject = nullptr;
	//to = nullptr;
	//fpsto = nullptr;

}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}