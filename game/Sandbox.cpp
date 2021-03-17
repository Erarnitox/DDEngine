#include "../engine/toxengine.h"

class Sandbox : public tox::App{
private:
	//Declare members here
public:
	Sandbox(int width, int height, std::string title)
	:App(width, height, title){
		/*Constructor: 
		 * Use for memory allocation
		 * and Member initialization
		 */
	}
	
	~Sandbox(){
		//Destructor: Use to free memory
	}
	
	//Transform simpleTrans;
	//Shader basicShader{"../res/shaders/basicShader"};
	//Mesh suzanneObj{"../res/models/suzanne.obj"};
	//Texture simpleTexture{"../res/textures/Wall/albedo.png"};
	//Camera cam{glm::vec3(0, 0, -3), 90.0f, 800.0f/600.0f, 0.001f, 1000.0f};
	
	//Called at game start
	virtual void Start() override{
		//this is a Trace message for Debugging:
		LOG_TRACE("Welcome to Drop Engine!");
		
		//Debug Info:
		LOG_INFO("Info Message!");
		
		//Debug Warning:
		LOG_WARNING("Warning!");
		
		//Debug Error:
		LOG_ERROR("Error!");
		
		
		/*
		vertex verteces[]{
			{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)},
			{glm::vec3( 0.0f,  0.5f, 0.0f), glm::vec2(0.5f, 1.0f)},
			{glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)}
		};
	
		unsigned indeces[]{0, 1, 2};
	
		Mesh mesh(verteces, sizeof(verteces)/sizeof(vertex), 
				   indeces, sizeof(indeces)/sizeof(indeces[0]));
	
		*/
		
		//Texture simpleTexture("../res/textures/Wall/albedo.png");
	
		
		//Camera cam(glm::vec3(0, 0, -3), 90.0f, 800.0f/600.0f, 0.001f, 1000.0f);
	}
	
	//Called once evry frame:
	virtual void Update() override{
		//simpleTrans.getPos().z = sinf(count*0.2f);
		//simpleTrans.getRot().y = count*0.3f;
		
		//basicShader.Bind();
		//basicShader.Update(simpleTrans, cam);
		//simpleTexture.Bind();
		
		//mesh.Draw();
		//suzanneObj.Draw();
			
	}
	
	//called onc every frame:
	virtual void GUI() override{
		
	}
};

//Create new Drop Engine Application:
tox::App* tox::createApp(){
	return new Sandbox(800, 600, "Sandbox");
}
