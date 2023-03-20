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
//#include "TextObject.h"
#include "GameObject.h"
//#include "Component.h"
#include "TextureComponent.h"
#include "Scene.h"
#include "Transform.h"
#include "FPSComponent.h"
#include "TextComponent.h"
#include "RotatorComponent.h"


void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	//CAN APPLY RAII?
	//Load in font
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto fpsfont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 15);


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

	

	//== LOGO OBJECT ==
	//1. Initialize the pointers needed for the object 
	dae::GameObject* logoObject = new dae::GameObject{};
	//2. Fill in the gameObject
	logoObject->AddComponent<dae::TextureComponent>("logo.tga",false);
	logoObject->AddComponent<dae::Transform>(216.f, 90.f);
	//3. Add the pointer to the GameObjectPtr Vector in the scene	
	scene.Add(logoObject);



	

	//== TITLE OBJECT ==
	//1. Initialize the pointers needed for the object 
	dae::GameObject* to = new dae::GameObject{};
	//2. Fill in the gameObject
	to->AddComponent<dae::Transform>(80.f, 20.f);
	to->AddComponent<dae::TextureComponent>(false);
	to->AddComponent<dae::TextComponent>("Programming 4 Assignment", font);
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


	////== MOON  OBJECT ==
	//dae::GameObject* moonObject = new dae::GameObject{};
	////2. Fill in the gameObject
	//moonObject->AddComponent<dae::TextureComponent>("moon.png",true);
	//moonObject->AddComponent<dae::Transform>(0.f, 0.f); //just need to have one
	//moonObject->AddComponent<dae::RotatorComponent>(45.f, earthRotationSpeed*24.f, true);
	//moonObject->SetParent(earthObject, false);
	////3. Add the pointer to the GameObjectPtr Vector in the scene	
	//scene.Add(moonObject);
	//release pointers for rotating object
	//earthObject = nullptr;
	//moonObject = nullptr;
	//centerPoint = nullptr; 
	
	// END OF ROTATION EXERCISE //

	//Set all nullptrs just for safety of leaks
	bgo = nullptr;
	logoObject = nullptr;
	to = nullptr;
	fpsto = nullptr;

}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}