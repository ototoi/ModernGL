#pragma once

#include "Python.hpp"

#define GL_CONTEXT_USE_EGL 1

#if defined(_WIN32) || defined(_WIN64)

struct GLContext {
	void * hwnd;
	void * hrc;
	void * hdc;
	bool standalone;
};

#elif defined(__APPLE__)

struct GLContext {
	void * context;
	bool standalone;
};

#else

#if GL_CONTEXT_USE_EGL
struct GLContext {
	void * display;
    void * window;
	void * context;
	bool standalone;
};
#else
struct GLContext {
	void * display;
	void * window;
	void * context;
	bool standalone;
};
#endif

#endif

GLContext LoadCurrentGLContext();
GLContext CreateGLContext(PyObject * settings);
void DestroyGLContext(const GLContext & context);
