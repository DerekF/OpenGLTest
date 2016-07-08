#pragma once
#include<ctime>
#include<GLFW/glfw3.h>

namespace Game {
	extern std::clock_t _first_frame_start_time, _frame_start_time, _last_frame_start_time, _last_frame_end_time;

	void GameLoop(GLFWwindow* window);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

	double ElapsedTime();
	double GameTime();
	double Framerate();

}