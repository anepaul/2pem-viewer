#ifndef __VIEWER_GLFW_HPP__
#define __VIEWER_GLFW_HPP__

#include <cstddef>
#include <GLFW/glfw3.h>

struct rect {
	rect();
	rect(int width, int height);
	int width {0};
	int height {0};
};

namespace glfw {
	void init();
	void terminate();
	void pollEvents();

	struct library {
		library();
		~library();
	};
	
	struct window {
		window(std::size_t width = 640,
			   std::size_t height = 480,
			   char const * title = nullptr,
			   GLFWmonitor * monitor = nullptr,
			   GLFWwindow * share = nullptr);
		~window();
		void makeContextCurrent() const;
		bool shouldClose() const;
		rect getFramebufferSize() const;
		void swapBuffers() const;
		void setCloseCallback(GLFWwindowclosefun cbfun) const;
	private:
		int width_;
		int height_;
		char const * title_;
		GLFWmonitor * monitor_;
		GLFWwindow * share_;
		GLFWwindow * window_;
	};
}

#endif // __VIEWER_GLFW_HPP__
