#include <stdio.h>
#include <stdlib.h>
#include "init.h"

void error_callback(int error, const char* description);

int main() {
    printf("Program beginning\n");
    GLFWwindow* window = NULL;
    glfwSetErrorCallback(error_callback);

    int errCount = 0;

    // initialization code
    init_glfw(&errCount);
    window = init_glfw_window(&errCount);
    init_glad(&errCount);

    if (errCount > 0)
        return EXIT_FAILURE;

    printf("Passed initialization stage %p\n", window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
