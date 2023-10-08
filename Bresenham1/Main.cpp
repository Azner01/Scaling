#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <windows.h>

/* Algoritmo de dibujo de líneas de Bresenham para |m| < 1.0. */
void lineBres(float x0, float y0, float xEnd, float yEnd)
{
    glPointSize(1.0f); // Set the point size to 1 pixel
    glBegin(GL_LINES); // Start drawing lines
    float dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    float p = 2 * dy - dx;
    float twody = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    float x, y;
    /* Determinar qué extremo usar como posición inicial.*/
    if (x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }
    else {
        x = x0;
        y = y0;

    }
    
    while (x < xEnd) {
        x++;
        if (p < 0)
            p += twody;
        else
            y++;
        p += twoDyMinusDx;
        glVertex2f(x, y);
    }

}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "DDA Line Drawing", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a line from (-0.5, -0.5) to (0.5, 0.5)
        lineBres(-0.5, -0.5, 0.5, 0.5);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}