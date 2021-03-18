#include "../engine/dropengine.h"

class Sandbox : public drop::App{
private:
	//Declare members here
	Shader basicShader;
	GameObject suzanne;
	GameObject player;
	
public:
	Sandbox(int width, int height, std::string title)
	:App(width, height, title), //super constructor call
	
	//initialize members:
	basicShader{"../res/shaders/basicShader"},
	suzanne("../res/models/suzanne.obj","../res/textures/Wall/albedo.png", basicShader),
	player("../res/models/ball.obj","../res/textures/green.jpg", basicShader)
	{
		/*Constructor: 
		 * Use for memory allocation
		 * and Member initialization
		 */
	}
	
	~Sandbox(){
		//Destructor: Use to free memory
	}
	
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
		
		//Add object to the render Queue:
		Instatiate(suzanne);
		Instatiate(player);
	}
	
	//Called once every frame:
	virtual void Update() override{
		static float count{};
		static float timeout{};
		
		if(timeout > 0){
			timeout -= Time::deltaTimeSec();
		}
		
		float scaledSpeed{2.0f * Time::deltaTimeSec()};
		count += scaledSpeed;
		
		suzanne.transform.getPos().x = sinf(count)*3.0f;
		suzanne.transform.getPos().z = sinf(count);
		suzanne.transform.getRot().y += scaledSpeed;
		
		//get Input:
		auto input{getIO()};
		
		
		if(ImGui::IsAnyMouseDown() && timeout < 0.1f){
			Mesh::wireframe = !Mesh::wireframe;
			timeout = 0.5f;
		}
	}
	
	//called once every frame:
	virtual void GUI() override{
		
	}
	
	//called once every frame:
	virtual void FullScreenUI() override{
		//center of Radar:
		ImVec2 radarCenter{ImVec2(screen.getWidth() - 100, screen.getHeight() - 100)};
		
		//max values:
		float radarRadius{80}; //max distance on the 2d Radius
		float maxDistance{5};  //max distance in (top down) world space 
		
		//Draw Distance Label:
		screen.drawFilledRect(
			ImVec2(screen.getWidth() - 250, screen.getHeight() - 70),
			ImVec2(screen.getWidth() - 140, screen.getHeight() - 50),
			colors::shaddow
		);
		
		//Draw Radar Frame:
		screen.drawFilledCircle(radarCenter, radarRadius, colors::solidgray, 10);
 		screen.drawCircle(radarCenter, radarRadius, colors::gray, 10, 5.0f);
		
		//Calculate Enemy Position on Radar:
		glm::vec3 vecToTarget = suzanne.transform.getPos() - player.transform.getPos();
		
		//trow out the upwards coordinate:
		glm::vec2 vecToTarget2D{vecToTarget.x, vecToTarget.z};
		
		float distance2d{ glm::length(vecToTarget2D) };
		
		//Draw Distance text:
		screen.drawText(
			std::to_string((int)distance2d), 
			ImVec2(screen.getWidth() - 220, screen.getHeight() - 70),
			20, 
			colors::white
		);
		
		//check if enemy is within range:
		if(distance2d < maxDistance){
			//Scale Vector to match max distance on radar:
			vecToTarget2D *= (radarRadius/maxDistance);
			
			glm::vec2 enemyScreenPos = glm::vec2{radarCenter.x, radarCenter.y} - vecToTarget2D;
		
			//Draw Enemy on Radar:
			screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 7, colors::black);
			screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 5, colors::red);
		}
		//Draw green Player dot to the Center of the Radar:
		screen.drawFilledCircle(radarCenter, 7, colors::black);
		screen.drawFilledCircle(radarCenter, 5, colors::green);
		
		//healhbar:
		float perc(1.0f);
		screen.drawFilledRect(ImVec2(90, 50), ImVec2(screen.getWidth()/2, 100), colors::shaddow);
		screen.drawFilledRect(ImVec2(100, 60), ImVec2((screen.getWidth()/2-10)*perc, 80), colors::white);
		
		//player icon:
		screen.drawFilledCircle(ImVec2(75,75), 50, colors::black, 5);
		screen.drawFilledCircle(ImVec2(75,75), 40, colors::white, 5);
	}
};

//Create new Drop Engine Application:
drop::App* drop::createApp(){
	return new Sandbox(1600, 900, "Sandbox");
}
