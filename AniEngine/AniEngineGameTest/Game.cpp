#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

bool Game::OnStart()
{
	//renderer->SetProjectionMatrixToPerspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 1000.0f);
	//renderer->SetViewMatrix(glm::vec3(window->GetWidth()/2, window->GetHeight()/2, window->GetWidth()), glm::vec3(window->GetWidth()/2, window->GetHeight()/2, 0), glm::vec3(0, 1, 0));
	
	camera = new Camera(renderer);
	collManager = new CollisionManager();

	//bmp base = uvtemplate.bmp
	//bmp test spritesheet = Test-Spritesheet1.bmp

	cout << "Game::OnStart() " << endl;
	character = new Texture(
		renderer, 
		"Test-Spritesheet.bmp",
		20.0f,
		32,
		32,
		1,
		1);
	character->material = Material::CreateMaterial(
		"Shaders/TextureTransformVertexShader.txt",
		"Shaders/TextureFragmentShader.txt");

	character->testAnimation->AddFrame(2, 1);
	character->testAnimation->AddFrame(3, 1);
	character->testAnimation->AddFrame(4, 1);
	character->testAnimation->AddFrame(5, 1);
	character->testAnimation->AddFrame(6, 1);
	character->testAnimation->AddFrame(7, 1);
	character->testAnimation->AddFrame(8, 1);


	enemy = new Texture(
		renderer,
		"uvtemplate.bmp",
		100.0f,
		51.2f,
		51.2f,
		1,
		1
	);
	enemy->material = Material::CreateMaterial(
		"Shaders/TextureTransformVertexShader.txt",
		"Shaders/TextureFragmentShader.txt");

	enemy->testAnimation->AddFrame(2, 1);
	enemy->testAnimation->AddFrame(3, 1);
	enemy->testAnimation->AddFrame(4, 1);
	enemy->testAnimation->AddFrame(5, 1);
	enemy->testAnimation->AddFrame(6, 1);
	enemy->testAnimation->AddFrame(7, 1);
	enemy->testAnimation->AddFrame(8, 1);

	triangle = new Triangle(renderer);
	triangle->material = Material::CreateMaterial(
		"Shaders/VertexShader.txt",
		"Shaders/FragmentShader.txt");
	rectangle = new Rectangle(renderer, 10.0f);
	rectangle->material = Material::CreateMaterial(
		"Shaders/TransformVertexShader.txt",
		"Shaders/ColorFragmentShader.txt");

	cube = new Cube(renderer);
	cube->material = Material::CreateMaterial(
		"Shaders/TransformVertexShader.txt",
		"Shaders/ColorFragmentShader.txt");
	

	/*tilemap->material = Material::CreateMaterial(
	"Shaders/TextureTransformVertexShader.txt",
	"Shaders/TextureFragmentShader.txt");*/

	tilemap = new Tilemap(
		renderer,
		1,
		2,
		960,
		640,
		"BattleCityCloneTiles.bmp",
		"BattleCityCloneTiledMap.csv");

	collManager->RegisterBoundingBox(character->bbox);
	collManager->RegisterBoundingBox(rectangle->bbox);
	collManager->RegisterBoundingBox(enemy->bbox);

	/*collManager->RegisterBoundingCircle(character->bcircle);
	collManager->RegisterBoundingCircle(rectangle->bcircle);

	rectangle->Translate(600, 320, 0.0);
	texture->Translate(480, 320, 0.0);*/

	triangle->Translate(750, 400, 0.0);
	rectangle->Translate(320, 300, 0.0);
	character->Translate(320, 150, 0.0);
	enemy->Translate(600, 250, 0.0);
	cube->Translate(750, 400, 300.0);

	i = 0;

	return true;
}

bool Game::OnStop() 
{
	cout << "Game::OnStop()" << endl;

	delete character;
	delete triangle;
	delete rectangle;
	delete cube;
	delete collManager;

	return true;
}

bool Game::OnUpdate() 
{
	i++;
	timer += deltaTime;

	//camera->Walk(-50 * deltaTime);
	//camera->Strafe(-75 * deltaTime);

	//camera->Pitch(-0.1f);
	//camera->Yaw(0.5f);
	//camera->Roll(0.3);

	/*if (timer >= timeLim)
	{
		cout << "SALIO" << endl;
		renderer->SetProjectionMatrixToOrtho(0.0f, 450.0f, 0.0f, 500.0f, 0.0f, 100.0f);
	}*/

	//rectangle->Translate(rectangle->vectorPosition.x - 2, 320, 0.0);

	//rectangle->Translate(rectangle->vectorPosition.x, rectangle->vectorPosition.y - (100 * deltaTime), 0.0);

	//triangle->RotateZ(-i);

	//rectangle->RotateZ(56+i);

	//cout << rectangle->vectorPosition.y << endl;
	//cout << rectangle->bbox->vectorPosition.y << endl;
	//cout << character->vectorPosition.y << endl;
	//cout << character->bbox->vectorPosition.y << endl;

	//cout << rectangle->vectorPosition.y << endl;
	//cout << rectangle->bcircle->vectorPosition.y << endl;
	//cout << texture->vectorPosition.y << endl;
	//cout << texture->bcircle->vectorPosition.y << endl;

	//texture->Translate(texture->vectorPosition.x + 2, 320, 0.0);

	/*character->Translate(character->vectorPosition.x, character->vectorPosition.y + (100 * deltaTime), 0.0);
	character->UpdateDT(deltaTime);

	enemy->Translate(enemy->vectorPosition.x - (150 * deltaTime), 350, 0.0);
	enemy->UpdateDT(deltaTime);*/

	//texture->RotateZ(56 + i);

	//collManager->CheckForBoundingBoxCollisions();
	//collManager->CheckForBoundingCircleCollisions();
	cube->RotateY(-i);
	cube->RotateX(-i);
	return true;
}

void Game::OnDraw()
{
	//character->Draw();
	//enemy->Draw();
	//triangle->Draw();
	//rectangle->Draw();
	cube->Draw();
}