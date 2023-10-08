#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>

// Function to draw a line using DDA algorithm
void drawLineDDA(float x1, float y1, float x2, float y2) {
    glPointSize(1.0f); // Set the point size to 1 pixel
    glBegin(GL_LINES); // Start drawing lines

    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy); // Determine the number of steps

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        glVertex2f(x, y); // Plot the point
        x += xIncrement;
        y += yIncrement;
    }

    glEnd(); // End drawing lines
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
        drawLineDDA(-0.5, -0.5, 0.5, 0.5);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}