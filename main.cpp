#include "common.h"
#include "Image.h"
#include <vector>
#include <cstdlib>
#include <sstream>
//#include "shared.h"

#define GLFW_DLL

#include <GLFW/glfw3.h>
#include "SpriteManager.h"

struct InputState {
    bool keys[1024]{}; //массив состояний кнопок - нажата/не нажата
    GLfloat lastX = 400, lastY = 300; //исходное положение мыши
    bool firstMouse = true;
    bool captureMouse = true;  // Мышка захвачена нашим приложением или нет?
    bool capturedMouseJustNow = false;
    int x = 4;
} static Input;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;


void OnKeyboardPressed(GLFWwindow *window, int key, int scancode, int action, int mode) {
    switch (key) {
        case GLFW_KEY_ESCAPE:
            if (action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        case GLFW_KEY_1:
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            break;
        case GLFW_KEY_2:
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            break;
        default:
            if (action == GLFW_PRESS)
                Input.keys[key] = true;
            else if (action == GLFW_RELEASE)
                Input.keys[key] = false;
    }
}

void processPlayerMovement(Player *player) {
    if (Input.keys[GLFW_KEY_W])
        player->ProcessInput(MovementDir::UP);
    else if (Input.keys[GLFW_KEY_S])
        player->ProcessInput(MovementDir::DOWN);
    if (Input.keys[GLFW_KEY_A])
        player->ProcessInput(MovementDir::LEFT);
    else if (Input.keys[GLFW_KEY_D])
        player->ProcessInput(MovementDir::RIGHT);
    if (Input.keys[GLFW_KEY_Q]) {
        player->throw_snowball();
    }
}

void OnMouseButtonClicked(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        Input.captureMouse = !Input.captureMouse;

    if (Input.captureMouse) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        Input.capturedMouseJustNow = true;
    } else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

}

void OnMouseMove(GLFWwindow *window, double xpos, double ypos) {
    if (Input.firstMouse) {
        Input.lastX = float(xpos);
        Input.lastY = float(ypos);
        Input.firstMouse = false;
    }

    GLfloat xoffset = float(xpos) - Input.lastX;
    GLfloat yoffset = Input.lastY - float(ypos);

    Input.lastX = float(xpos);
    Input.lastY = float(ypos);
}


void OnMouseScroll(GLFWwindow *window, double xoffset, double yoffset) {
    // ...
}


int initGL() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    std::cout << "Controls: " << std::endl;
    std::cout << "press right mouse button to capture/release mouse cursor  " << std::endl;
    std::cout << "W, A, S, D - movement  " << std::endl;
    std::cout << "press ESC to exit" << std::endl;

    return 0;
}

std::string read_file(std::string &str) {
    std::fstream floor_input(str);
    std::string tmp{}, ans{};
    while (std::getline(floor_input, tmp)) {
        ans = ans + tmp;
    }

    return ans;
}

int main(int argc, char **argv) {
    if (!glfwInit())
        return -1;

//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "task1 base project", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, OnKeyboardPressed);
    glfwSetCursorPosCallback(window, OnMouseMove);
    glfwSetMouseButtonCallback(window, OnMouseButtonClicked);
    glfwSetScrollCallback(window, OnMouseScroll);

    if (initGL() != 0)
        return -1;
    //Reset any OpenGL errors which could be present for some reason
    GLenum gl_error = glGetError();
    while (gl_error != GL_NO_ERROR)
        gl_error = glGetError();

//    Point starting_pos{.x = PLAY_WINDOW_WIDTH / 2, .y = PLAY_WINDOW_HEIGHT / 2};
//    Player player_sprite{starting_pos, tileSize};

    Image img("../resources/default16x16.png");
    Image screenBuffer(WINDOW_WIDTH, WINDOW_HEIGHT, 4);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    GL_CHECK_ERRORS;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    GL_CHECK_ERRORS;

    //game loop
    std::vector<std::string> floors = {"../floors/first_floor.txt",
                                       "../floors/second_floor.txt"};
    int floor_complete = 0;
    int floor_num = 0;
    int modul = 0, frames_to_start = 20, frame_pause = 200;
    auto dead = Sprite("dead",
                      "../resources/loose.png",
                      {PLAY_WINDOW_WIDTH / 13, PLAY_WINDOW_HEIGHT / 3},
                      LAYER::FRONT_LAYER,
                      Position{0, 0},
                      Position{0, 0}
    );
    auto win = Sprite("win",
                       "../resources/win.png",
                       {PLAY_WINDOW_WIDTH / 13, PLAY_WINDOW_HEIGHT / 3},
                       LAYER::FRONT_LAYER,
                       Position{0, 0},
                       Position{0, 0}
    );
    for (auto &floor_path : floors) {
        std::cout << floor_path << "\n";

        std::string cur_floor = read_file(floor_path);
        SpriteManager mg(screenBuffer, floor_complete);
        while (!glfwWindowShouldClose(window) && floor_complete == floor_num && frame_pause) {
            if (frames_to_start != modul) {
                for (int i = 0; i < PLAY_WINDOW_HEIGHT / tileSize; ++i) {
                    for (int j = 0; j < PLAY_WINDOW_WIDTH / tileSize; ++j) {
                        int cur_ind = i * (PLAY_WINDOW_WIDTH / tileSize) + j;
                        unsigned char cur_tile = cur_floor[cur_ind];

                        if (cur_ind % frames_to_start == modul) {
                            mg.add(cur_tile,
                                   j * tileSize,
                                   (PLAY_WINDOW_HEIGHT / tileSize - i - 1) * tileSize);
                        }
                    }
                }
                modul += 1;
            }

            //
            GLfloat currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            glfwPollEvents();

            if (mg.player != nullptr && mg.player->is_alive()) {
                if (frames_to_start == modul) {
                    processPlayerMovement(mg.player);
                }

                mg.draw();
            }

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            GL_CHECK_ERRORS;
            glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data());
            GL_CHECK_ERRORS;

            glfwSwapBuffers(window);

            if (mg.player != nullptr && !mg.player->is_alive()){
                dead.draw(screenBuffer);
                frame_pause -= 1;
            }

        }
        if (!frame_pause) {
            break;
        }
        if (floor_complete == 2) {
            while (frame_pause) {
                glfwPollEvents();

                win.draw(screenBuffer);

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                GL_CHECK_ERRORS;
                glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data());
                GL_CHECK_ERRORS;

                glfwSwapBuffers(window);

                frame_pause -= 1;
            }
            break;
        }
        std::cout << "LVL COMPLETE\n";
        floor_num += 1;
        modul = 0;
        frame_pause = 200;
    }
    glfwTerminate();
    return 0;
}
