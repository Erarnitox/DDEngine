#include "../engine/dropengine.h"

class Sandbox : public drop::App{
private:
	//Declare members here
	Shader basicShader;
	GameObject suzanne;
	GameObject player;
	float perc;
	float camYaw;
	float camPitch;

	
public:
	Sandbox(int width, int height, std::string title)
	:App(width, height, title), //super constructor call
	
	//initialize members:
	basicShader{"../res/shaders/basicShader"},
	suzanne("../res/models/suzanne.obj","../res/textures/Wall/albedo.png", basicShader),
	player("../res/models/ball.obj","../res/textures/Wall/albedo.png", basicShader),
	perc{1.0f},
	camYaw{0.0f},
	camPitch{0.0f}{
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
		
		//set the perspective for the camere:
		MainCamera.setPerspective(76.0f, ((float)screen.getWidth())/((float)screen.getHeight()));
		
		//disable suzanne from drawing:
		suzanne.setActive(false);
	}
	
	//Called once every frame:
	virtual void Update() override{
		static float count{};
		static float timeout{};
		
		float scaledSpeed{2.0f * Time::deltaTimeSec()};
		count += scaledSpeed;
		
		//suzanne.transform.getPos().x = sinf(count)*3.0f;
		suzanne.transform.getPos().z = sinf(count);
		suzanne.transform.getRot().y += scaledSpeed;
		
		
		if(isKeyDown(DROP_KEY_W)){
			//player.transform.getPos().z += scaledSpeed;
			MainCamera.getPos().z += scaledSpeed;
		}else if(isKeyDown(DROP_KEY_S)){
			//player.transform.getPos().z -= scaledSpeed;
			MainCamera.getPos().z -= scaledSpeed;
		}
		
		if(isKeyDown(DROP_KEY_A)){
			//player.transform.getPos().x += scaledSpeed;
			MainCamera.getPos().x += scaledSpeed;
		}else if(isKeyDown(DROP_KEY_D)){
			//player.transform.getPos().x -= scaledSpeed;
			MainCamera.getPos().x -= scaledSpeed;
		}
		
		if(isKeyDown(DROP_KEY_Q)){
			//player.transform.getPos().y += scaledSpeed;
			MainCamera.getPos().y += scaledSpeed;
		}else if(isKeyDown(DROP_KEY_E)){
			//player.transform.getPos().y -= scaledSpeed;
			MainCamera.getPos().y -= scaledSpeed;
		}
		
		if(isKeyDown(DROP_KEY_3)){
			//player.transform.getPos().y += scaledSpeed;
			camPitch += scaledSpeed;
		}else if(isKeyDown(DROP_KEY_4)){
			//player.transform.getPos().y -= scaledSpeed;
			camPitch -= scaledSpeed;
		}
		
		if(isKeyDown(DROP_KEY_5)){
			//player.transform.getPos().y += scaledSpeed;
			camYaw += scaledSpeed;
		}else if(isKeyDown(DROP_KEY_6)){
			//player.transform.getPos().y -= scaledSpeed;
			camYaw -= scaledSpeed;
		}
		
		MainCamera.rotate(camPitch, camYaw);
		
		scaledSpeed *= 0.2f;
		if(isKeyDown(DROP_KEY_1)){
			if(perc+scaledSpeed<1.0f) perc += scaledSpeed;
		}else if(isKeyDown(DROP_KEY_2)){
			if(perc-scaledSpeed>0.14f) perc -= scaledSpeed;
		}
		
		//Toggle wireframe:
		if(isKeyPressed(DROP_KEY_X)){
			Mesh::wireframe = !Mesh::wireframe;
		}
	}
	
	//gets called at a fixed 30 FPS:
	virtual void FixedUpdate() override{
		
	}
	
	//called once every frame:
	virtual void GUI() override{
		//ImGui::ShowDemoWindow();
	}
	
	//called once every frame:
	virtual void FullScreenUI() override{
		//center of Radar:
		ImVec2 radarCenter{ImVec2(screen.getWidth() - 100, screen.getHeight() - 100)};
		
		//max values:
		const static float radarRadius{80}; //max distance on the 2d Radius
		const static float maxDistance{10};  //max distance in (top down) world space 
		
		//Draw Distance Label:
		screen.drawFilledRect(
			ImVec2(screen.getWidth() - 250, screen.getHeight() - 70),
			ImVec2(screen.getWidth() - 140, screen.getHeight() - 50),
			colors::shaddow
		);
		
		//Draw Radar Frame:
		screen.drawFilledCircle(radarCenter, radarRadius, colors::solidgray);
 		screen.drawCircle(radarCenter, radarRadius, colors::shaddow, 0, 10.0f);
		
		//Calculate Enemy Position on Radar:
		glm::vec3 vecToTarget = player.transform.getPos() - MainCamera.getPos();
		
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
		
		//rotation matrix:
		glm::mat2 rot{
			glm::cos(camYaw), -glm::sin(camYaw),
		    glm::sin(camYaw), glm::cos(camYaw)	
		};
		
		//rotate Vecotor to target:
		vecToTarget2D = rot * vecToTarget2D;
		
		//check if enemy is within range:
		if(distance2d < maxDistance){
			//Scale Vector to match max distance on radar:
			vecToTarget2D *= (radarRadius/maxDistance);
			
			glm::vec2 enemyScreenPos = glm::vec2{radarCenter.x, radarCenter.y} - vecToTarget2D;
		
			//Draw Enemy on Radar:
			screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 7, colors::black);
			screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 5, colors::red);
		}else{
			//Scale Vector to match max distance on radar:
			vecToTarget2D /= distance2d;
			vecToTarget2D *= radarRadius;
			
			glm::vec2 enemyScreenPos = glm::vec2{radarCenter.x, radarCenter.y} - vecToTarget2D;
		
			//Draw Enemy on Radar:
			if(distance2d < maxDistance+5.0f){
				screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 6, colors::black);
				screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 4, colors::yellow);
			}else if(distance2d < maxDistance+10.0f){
				screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 5, colors::black);
				screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 3, colors::cyan);
			}else{
				screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 4, colors::black);
				screen.drawFilledCircle(ImVec2{enemyScreenPos.x, enemyScreenPos.y}, 2, colors::gray);
			}
		}
		
		//Draw green Player dot to the Center of the Radar:
		screen.drawFilledCircle(radarCenter, 7, colors::black);
		screen.drawFilledCircle(radarCenter, 5, colors::green);
		
		//healhbar:
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
