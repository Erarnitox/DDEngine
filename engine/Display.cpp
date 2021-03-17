#include "Display.h"

Display::Display(int width, int height, const std::string& title){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	
	this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	
	this->context = SDL_GL_CreateContext(window);
	
	GLenum status{glewInit()};
	
	if(status != GLEW_OK){
		ENGINE_LOG_ERROR("Glew failed to initialize!");
	}
	
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	
	
	ImGui::CreateContext();
	this->io = ImGui::GetIO();
	
	ImGui_ImplSDL2_InitForOpenGL(this->window, this->context);
	ImGui_ImplOpenGL3_Init();
}

Display::~Display(){
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
	
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Display::endFrame(){
	//imgui end fullscreen:
	endGUI();
	
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	
	SDL_GL_SwapWindow(window);
	
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		ImGui_ImplSDL2_ProcessEvent(&e);
		if(e.type == SDL_QUIT) this->isClosed = true;
	}
}

void Display::startFrame(){
	glClearColor(0.2f, 0.2f, 0.2, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(this->window);
	ImGui::NewFrame();
	
	ImGui::ShowDemoWindow();
	
	//imgui fullscreen
	startGUI();
}

void Display::startGUI(){
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f });
	ImGui::PushStyleColor(ImGuiCol_WindowBg, { 0.0f, 0.0f, 0.0f, 0.0f });

	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_Always);

	ImGui::Begin("##Cavas", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus 
									| ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoResize);
}

void Display::endGUI(){
	ImGui::GetWindowDrawList()->PushClipRectFullScreen();
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
}

void Display::drawLine(const ImVec2& from, const ImVec2& to, float width, const ImColor& color){
	ImGui::GetWindowDrawList()->AddLine(from, to, colors::black, width+2);
	ImGui::GetWindowDrawList()->AddLine(from, to, color, width);
}

void Display::drawText(const std::string& text, const ImVec2& pos, float size, const ImColor& color, bool center){
	if (center) {
		const auto txtSize = ImGui::GetFont()->CalcTextSizeA(size, FLT_MAX, 0.0f, text.c_str());
		ImVec2 center{ pos.x - (txtSize.x / 2),pos.y - (txtSize.y / 2) };
		ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), size+2, pos, colors::black, text.c_str());
		ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), size, pos, color, text.c_str());
		return;
	}
	ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), size+2, pos, colors::black, text.c_str());
	ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), size, pos, color, text.c_str());
}

void Display::drawRect(const ImVec2& upperLeft, const ImVec2& lowerRight, float width, const ImColor& color){
	ImGui::GetWindowDrawList()->AddRect(upperLeft, lowerRight, colors::black, 0.0f, 15, width+2);
	ImGui::GetWindowDrawList()->AddRect(upperLeft, lowerRight, color, 0.0f, 15, width);
}

void Display::drawCircle(const ImVec2& pos, float radius, const ImColor& color){
	ImGui::GetWindowDrawList()->AddCircle(pos, radius, colors::black, 0, 3.0f);
	ImGui::GetWindowDrawList()->AddCircle(pos, radius, color);
}


