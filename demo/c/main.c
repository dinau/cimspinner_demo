#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include "cimgui.h"
#include "cimgui_impl.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#ifdef _MSC_VER
#include <windows.h>
#endif
#include <GL/gl.h>

#include "setupFonts.h"
#include "IconsFontAwesome6.h"

#include "cimspinner.h"

#ifdef IMGUI_HAS_IMSTR
#define igBegin igBegin_Str
#define igSliderFloat igSliderFloat_Str
#define igCheckbox igCheckbox_Str
#define igColorEdit3 igColorEdit3_Str
#define igButton igButton_Str
#endif


//------"
// main
//------"
int main(int argc, char *argv[]) {
    if (!glfwInit())
        return -1;

    // Decide GL+GLSL versions
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    const char *glsl_version = "#version 330";

    // just an extra window hint for resize
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    GLFWwindow *window = glfwCreateWindow(1024, 900, "CImSpinner with C language 2025/02" , NULL, NULL);
    if (!window) {
        printf("Failed to create window! Terminating!\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // enable vsync
    glfwSwapInterval(1);

    // check opengl version sdl uses
    printf("opengl version: %s\n", (char *) glGetString(GL_VERSION));

    // setup imgui
    igCreateContext(NULL);

    // set docking
    ImGuiIO *ioptr = igGetIO();
    ioptr->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;// Enable Keyboard Controls
                                                             //ioptr->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
#undef IMGUI_HAS_DOCK
#ifdef IMGUI_HAS_DOCK
    ioptr->ConfigFlags |= ImGuiConfigFlags_DockingEnable;  // Enable Docking
    ioptr->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;// Enable Multi-Viewport / Platform Windows
#endif

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    igStyleColorsDark(NULL);
    //igStyleColorsClassic(NULL);
    //igStyleColorsLight(NULL);

    setupFonts();

    bool showDemoWindow = true;
    ImVec4 clearColor = {.x = 0.45f, .y = 0.55f, .z = 0.60f, .w = 1.0f};
    int showWindowDelay = 1;

    // main event loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // start imgui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        igNewFrame();

        if (showDemoWindow)
            igShowDemoWindow(&showDemoWindow);

        // show a simple window that we created ourselves.
        {
         #if 1
            char *title = "ImGui: ImSpinner / CImSpinner demo with C lang. " ICON_FA_CAT;
            igBegin(title, NULL, 0);
            static const ImColor red = {.Value = {.x = 1.f, .y = 0.f, .z = 0.f, .w = 1.f}};
            static const ImColor blue = {.Value = {.x = 0.f, .y = 0.f, .z = 1.f, .w = 1.f}};
            SpinnerRotatingHeart("RHeart", 16, 2, red, 4);
            igSameLine(0.0, -1.0);
            SpinnerRainbowMix("Rmix", 16, 2, blue, 4);
            igSameLine(0.0, -1.0);
            SpinnerAng8("Ang", 16, 2);
            igSameLine(0.0, -1.0);
            SpinnerPulsar("Pulsar", 16, 2);
            igSameLine(0.0, -1.0);
            SpinnerClock("Clock", 16, 2);
            igSameLine(0.0, -1.0);
            SpinnerAtom("atom", 16, 2);
            igSameLine(0.0, -1.0);
            SpinnerSwingDots("wheel", 16, 6);
            igSameLine(0.0, -1.0);
            SpinnerDotsToBar("tobar", 16, 2, 0.5);
            igSameLine(0.0, -1.0);
            SpinnerBarChartRainbow("rainbow", 16, 4, red, 4);

            igNewLine();
            igText("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / igGetIO()->Framerate, igGetIO()->Framerate);
            igEnd();
          #endif
        }
        {
         #ifdef IMSPINNER_DEMO
            igBegin("ImSpinner demo", NULL, 0);
            demoSpinners();
            igEnd();
         #endif
        }


        // render
        igRender();
        glfwMakeContextCurrent(window);
        glViewport(0, 0, (int) ioptr->DisplaySize.x, (int) ioptr->DisplaySize.y);
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
#ifdef IMGUI_HAS_DOCK
        if (ioptr->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow *backup_current_window = glfwGetCurrentContext();
            igUpdatePlatformWindows();
            igRenderPlatformWindowsDefault(NULL, NULL);
            glfwMakeContextCurrent(backup_current_window);
        }
#endif
        glfwSwapBuffers(window);

        if (showWindowDelay >= 0){ showWindowDelay--; }
        if (showWindowDelay == 0){ glfwShowWindow(window); }
    }

    // clean up
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    igDestroyContext(NULL);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
