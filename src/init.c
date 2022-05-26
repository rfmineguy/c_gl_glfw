#include "init.h"
#include <stdlib.h>
#include <stdio.h>

int init_glfw() {
    if (!glfwInit()) {
        printf("Failed to initialize glfw\n");
        return 1;
    }
    printf("Successfully initialized glfw\n");
    return 0;
}

GLFWwindow* init_glfw_window() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    GLFWwindow* windowPtr = glfwCreateWindow(640, 480, "Window", NULL, NULL);
    if (!windowPtr) {
        printf("Failed to create glfwWindow %p\n", windowPtr);
        glfwTerminate();
        return NULL;
    }
    printf("Successfully created GLFWwindow* %p\n", windowPtr);
    return windowPtr;
}

int init_glad() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize glad\n");
        return 1;
    }
    printf("Successfully initialized glad\n");
    return 0;
}
