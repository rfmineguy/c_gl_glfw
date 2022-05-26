#include "init.h"
#include <stdlib.h>
#include <stdio.h>

void init_glfw(int* code) {
    if (!glfwInit()) {
        printf("Failed to initialize glfw\n");
        (*code)++;
    }
    printf("Successfully initialized glfw\n");
}

GLFWwindow* init_glfw_window(int* code) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    GLFWwindow* windowPtr = glfwCreateWindow(640, 480, "Window", NULL, NULL);
    if (!windowPtr) {
        printf("Failed to create glfwWindow %p\n", windowPtr);
        glfwTerminate();
        (*code)++;
        return NULL;
    }
    printf("Successfully created GLFWwindow* %p\n", windowPtr);
    glfwMakeContextCurrent(windowPtr);
    return windowPtr;
}

void init_glad(int* code) {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize glad\n");
        (*code)++;
    }
    printf("Successfully initialized glad\n");
}
