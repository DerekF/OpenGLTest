#include<iostream>
#include<GLFW/glfw3.h>
#include "Game.h"

namespace Game {

	std::clock_t _first_frame_start_time, _frame_start_time, _last_frame_start_time, _last_frame_end_time;

	//	Returns the time (in seconds) since the game loop started
	double GameTime() {
		return (std::clock() - _first_frame_start_time) / (double)CLOCKS_PER_SEC;
	}

	//	Returns the time (in seconds) since the end of the last frame
	double ElapsedTime() {
		return (std::clock() - _last_frame_end_time) / (double)CLOCKS_PER_SEC;
	}

	//	Returns the frames per second
	double Framerate() {
		return (_last_frame_end_time - _last_frame_start_time) / (double)CLOCKS_PER_SEC;
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) 
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			std::cout << "Game time: " << GameTime() << std::endl;
			std::cout << "Elapsed time: " << ElapsedTime() << std::endl;
			std::cout << "FPS: " << Framerate() << std::endl;
		}
	}

	void GameLoop(GLFWwindow* window) 
	{
		_first_frame_start_time = std::clock();
		while (!glfwWindowShouldClose(window))
		{
			_frame_start_time = std::clock();
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Render
			// Clear the colorbuffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// Swap the screen buffers
			glfwSwapBuffers(window);
			_last_frame_start_time = _frame_start_time;
			_last_frame_end_time = std::clock();
		}

	}

}