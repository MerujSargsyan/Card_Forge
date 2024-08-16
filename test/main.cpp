#include <GLFW/glfw.h>

int main(void) {
    glfwInit();
    std::unique_ptr<GLFWwindow> window = glfwCreateWindow(500, 500, "Test", NULL, NULL);

    while(true) {
        char input;
        std::cin >> input;
        if(input == 'c') {
            break;
        }
    }
    
    gflwDestroyWindow(window);
    glfwTerminate();
}
