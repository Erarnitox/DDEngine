#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <GL/glew.h>

#include "imgui-1.82/imgui.h"
#include "imgui-1.82/backends/imgui_impl_opengl3.h"
#include "imgui-1.82/backends/imgui_impl_sdl.h"

#include "Log.h"


namespace colors {
	const ImColor red		{ 1.0f, 0.0f, 0.0f, 0.7f };
	const ImColor green		{ 0.0f, 1.0f, 0.0f, 0.7f };
	const ImColor blue		{ 0.0f, 0.0f, 1.0f, 0.7f };
	const ImColor gray		{ 0.2f, 0.2f, 0.2f, 0.7f };
	const ImColor lightgray	{ 0.7f, 0.7f, 0.7f, 0.4f };
	const ImColor solidgray	{ 0.6f, 0.6f, 0.6f, 1.0f };
	const ImColor yellow	{ 1.0f, 1.0f, 0.0f, 0.7f };
	const ImColor orange	{ 0.7f, 0.5f, 0.0f, 0.7f };
	const ImColor pink		{ 0.7f, 0.5f, 0.7f, 0.7f };
	const ImColor cyan		{ 0.0f, 0.7f, 0.7f, 0.7f };
	const ImColor black		{ 0.0f, 0.0f, 0.0f, 0.7f };
	const ImColor white		{ 1.0f, 1.0f, 1.0f, 1.0f };
	const ImColor shaddow	{ 0.0f, 0.0f, 0.0f, 0.4f };
}

class Display{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();
	
	void startFrame();
	void endFrame();
	
	bool isClosed{false};
	bool isWireFrame();
	
	int getHeight();
	int getWidth();
	
	void setWireFrame(bool drawWire);
	
	void drawLine(const ImVec2& from, const ImVec2& to, float width, const ImColor& color);
	void drawText(const std::string& text, const ImVec2& pos, float size, const ImColor& color, bool center=true);
	void drawRect(const ImVec2& upperLeft, const ImVec2& lowerRight, float width, const ImColor& color);
	void drawFilledRect(const ImVec2& upperLeft, const ImVec2& lowerRight, const ImColor& color);
	void drawCircle(const ImVec2& pos, float radius, const ImColor& color, int seg = 0, float thickness = 3.0f);
	void drawFilledCircle(const ImVec2& pos, float radius, const ImColor& color, int seg = 0);
	
	void startGUI();
	void endGUI();
	SDL_Window* getWindow();
	
private:
	int width, height;
	
	Display(const Display& other) = delete;
	Display& operator=(const Display& other) = delete;
	
	SDL_Window* window;
	SDL_GLContext context;
	ImGuiIO io;
};
