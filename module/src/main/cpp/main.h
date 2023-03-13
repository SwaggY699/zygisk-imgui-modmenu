#include <pthread.h>
#include <jni.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include<list>
#include<vector>
#include<string.h>
#include<pthread.h>
#include<thread>
#include<cstring>
#include<jni.h>
#include<unistd.h>
#include<fstream>
#include<iostream>
#include<dlfcn.h>
#include <algorithm>
#include <string>
#include <map>

#include "Obfuscate.h"

#include "Utils.h"
#include "Logger.h"
#include "KittyMemory/MemoryPatch.h"
#include "json.hpp"
#include "autoaddr.h"

#include "font.h"
#include "autofont.h"
#include "autohelp.h"
#include "Rect.h"

#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/system_properties.h>
#include <dlfcn.h>

#include "KittyMemory/MemoryPatch.h"

#include <dlfcn.h>
#include <cstdlib>
#include <cinttypes>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "Vectorr3.h"

#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include "imgui.h"
#include "imgui_internal.h"

#include <pthread.h>

#include "zygisk.hpp"

bool openMenuuuu;

#include <sys/system_properties.h>

#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Macros.h"

JavaVM* publicVM;
JNIEnv* publicEnv;

#include <EGL/egl.h>
#include <GLES2/gl2.h>

uintptr_t address = 0;
int  glWidth, glHeight;

int page = 1;

void cmdExecuteSystem(const char* input){
    printf("%s", input);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool UnlockG;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct My_Patches {
    MemoryPatch UnG;
} hexPatches;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool drawBehindMenu = true;

ImDrawList* getDrawList(){
    ImDrawList *drawList;
    if(drawBehindMenu){
        drawList = ImGui::GetBackgroundDrawList();
    } else {
        drawList = ImGui::GetForegroundDrawList(ImGui::GetMainViewport());
    }
    return drawList;
}

#include <stdlib.h>
float scale = 1;

void stylesMeh() {
  


    float r = rand() / (RAND_MAX + 1.);
    float g = rand() / (RAND_MAX + 1.);
    float b = rand() / (RAND_MAX + 1.);
        ImGuiStyle& style = ImGui::GetStyle();
       /// style->FrameRounding = 0.0f;
        style.GrabRounding = 3.0f;/*/
        style.ButtonTextAlign = ImVec2(0.5,0.5);
        style.TabRounding = 13.0f;/*/
        /*/style.FrameBorderSize = 2.5f;
        style.WindowBorderSize = 2.5f;/*/
        //style->WindowMinSize = ImVec2(280, 180);
        //style.ScrollbarSize = 0.3f;
        style.ButtonTextAlign = ImVec2(0.5,0.65);
        style.WindowTitleAlign = ImVec2(0.5, 0.5);
        style.WindowBorderSize = 3.5f;
    style.WindowRounding = 6.0f;
    style.FrameRounding = 3.0f;
    style.ScrollbarRounding = 0.0f;
 //   style.PopupBorderSize = 2.0f;
    style.Colors[ImGuiCol_Text]                  = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
    style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
    style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_WindowBg]         = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
    style.Colors[ImGuiCol_Border]                = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
   // imgui.TextColored(
    style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.000f, 0.260f, 0.619f, 0.400f);
    style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.90f, 0.80f, 0.80f, 0.40f);
    style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.90f, 0.65f, 0.65f, 0.45f);
    style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
    style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.00f, 0.00f, 0.00f, 0.87f);
    style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
    style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.90f, 0.90f, 0.90f, 0.83f);
    style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_Button]                = ImVec4(0.48f, 0.72f, 0.89f, 0.49f);
    style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
    style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_Header]                = ImVec4(0.30f, 0.69f, 1.00f, 0.53f);
    style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.44f, 0.61f, 0.86f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.38f, 0.62f, 0.83f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.70f, 0.60f, 0.60f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.90f, 0.70f, 0.70f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
    style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
    style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
    style.Colors[ImGuiCol_Button]           = ImVec4(0.50f, 0.50f, 0.90f, 0.50f);
    style.Colors[ImGuiCol_ButtonHovered]    = ImVec4(0.70f, 0.70f, 0.90f, 0.60f);
    style.Colors[ImGuiCol_ButtonActive]     = ImVec4(0.70f, 0.7f, 0.70f, 1.00f);
    style.Colors[ImGuiCol_PlotLines]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
    style.Colors[ImGuiCol_ModalWindowDimBg]  = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
    style.Colors[ImGuiCol_WindowBg] = ImColor(16,16,16);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
    style.Colors[ImGuiCol_Text] = ImColor(255,255,255);
    style.Colors[ImGuiCol_Header] = ImColor(30,30,30);
    style.Colors[ImGuiCol_HeaderActive] = ImColor(28,28,28);
    style.Colors[ImGuiCol_HeaderHovered] = ImColor(28,28,28);
    style.Colors[ImGuiCol_Button] = ImColor(36, 36, 36);
    style.Colors[ImGuiCol_ButtonActive] = ImColor(40, 40, 40);
    style.Colors[ImGuiCol_ButtonHovered] = ImColor(40, 40,40);
       
    style.Colors[ImGuiCol_FrameBg] = ImColor(30, 30, 30);
    style.Colors[ImGuiCol_FrameBgActive] = ImColor(28, 28, 28);
    style.Colors[ImGuiCol_FrameBgHovered] = ImColor(28, 28, 28);

    style.Colors[ImGuiCol_TitleBg] = ImColor(30, 30, 30);
    style.Colors[ImGuiCol_TitleBgActive] = ImColor(28, 28, 28);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(28, 28, 28);
    
    
     style.Colors[ImGuiCol_Header]                 = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
     style.Colors[ImGuiCol_HeaderHovered]          = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
     style.Colors[ImGuiCol_HeaderActive]           = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
     style.Colors[ImGuiCol_Separator]              =  style.Colors[ImGuiCol_Border];
     style.Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
     style.Colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
     style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
     style.Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
     style.Colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
     style.Colors[ImGuiCol_Tab]                    = ImLerp(style.Colors[ImGuiCol_Header],        style.Colors[ImGuiCol_TitleBgActive], 0.80f);
     style.Colors[ImGuiCol_TabHovered]             =  style.Colors[ImGuiCol_HeaderHovered];
     style.Colors[ImGuiCol_TabActive]              = ImLerp( style.Colors[ImGuiCol_HeaderActive],  style.Colors[ImGuiCol_TitleBgActive], 0.60f);
     style.Colors[ImGuiCol_TabUnfocused]           = ImLerp( style.Colors[ImGuiCol_Tab],           style.Colors[ImGuiCol_TitleBg], 0.80f);
     style.Colors[ImGuiCol_TabUnfocusedActive]     = ImLerp( style.Colors[ImGuiCol_TabActive],     style.Colors[ImGuiCol_TitleBg], 0.40f);
     style.Colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
     style.Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
     style.Colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
     style.Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);      style.Colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
     style.Colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);   // Prefer using Alpha=1.0 here
     style.Colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);   // Prefer using Alpha=1.0 here
  //  style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.35f, 0.35f, 0.35f, 0.17f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
   
}
void styles() {
  


    float r = rand() / (RAND_MAX + 1.);
    float g = rand() / (RAND_MAX + 1.);
    float b = rand() / (RAND_MAX + 1.);
        ImGuiStyle& style = ImGui::GetStyle();
       /// style->FrameRounding = 0.0f;
        style.GrabRounding = 3.0f;/*/
        style.ButtonTextAlign = ImVec2(0.5,0.5);
        style.TabRounding = 13.0f;/*/
        /*/style.FrameBorderSize = 2.5f;
        style.WindowBorderSize = 2.5f;/*/
        //style->WindowMinSize = ImVec2(280, 180);
        //style.ScrollbarSize = 0.3f;
        style.ButtonTextAlign = ImVec2(0.5,0.65);
        style.WindowTitleAlign = ImVec2(0.5, 0.5);
        style.WindowBorderSize = 3.5f;
    style.WindowRounding = 6.0f;
    style.FrameRounding = 3.0f;
    style.ScrollbarRounding = 0.0f;
 //   style.PopupBorderSize = 2.0f;
    style.Colors[ImGuiCol_Text]                  = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
    style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
    style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_WindowBg]         = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
    style.Colors[ImGuiCol_Border]                = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
   // imgui.TextColored(
    style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.000f, 0.260f, 0.619f, 0.400f);
    style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.90f, 0.80f, 0.80f, 0.40f);
    style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.90f, 0.65f, 0.65f, 0.45f);
    style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
    style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.00f, 0.00f, 0.00f, 0.87f);
    style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
    style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.90f, 0.90f, 0.90f, 0.83f);
    style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.000f, 0.260f, 0.619f, 0.700f);
    style.Colors[ImGuiCol_Button]                = ImVec4(0.48f, 0.72f, 0.89f, 0.49f);
    style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
    style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_Header]                = ImVec4(0.30f, 0.69f, 1.00f, 0.53f);
    style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.44f, 0.61f, 0.86f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.38f, 0.62f, 0.83f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.70f, 0.60f, 0.60f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.90f, 0.70f, 0.70f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
    style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
    style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
    style.Colors[ImGuiCol_Button]           = ImVec4(0.50f, 0.50f, 0.90f, 0.50f);
    style.Colors[ImGuiCol_ButtonHovered]    = ImVec4(0.70f, 0.70f, 0.90f, 0.60f);
    style.Colors[ImGuiCol_ButtonActive]     = ImVec4(0.70f, 0.7f, 0.70f, 1.00f);
    style.Colors[ImGuiCol_PlotLines]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
    style.Colors[ImGuiCol_ModalWindowDimBg]  = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
    style.Colors[ImGuiCol_WindowBg] = ImColor(16,16,16);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
    style.Colors[ImGuiCol_Text] = ImColor(255,255,255);
    style.Colors[ImGuiCol_Header] = ImColor(30,30,30);
    style.Colors[ImGuiCol_HeaderActive] = ImColor(28,28,28);
    style.Colors[ImGuiCol_HeaderHovered] = ImColor(28,28,28);
    style.Colors[ImGuiCol_Button] = ImColor(36, 36, 36);
    style.Colors[ImGuiCol_ButtonActive] = ImColor(40, 40, 40);
    style.Colors[ImGuiCol_ButtonHovered] = ImColor(40, 40,40);
       
    style.Colors[ImGuiCol_FrameBg] = ImColor(30, 30, 30);
    style.Colors[ImGuiCol_FrameBgActive] = ImColor(28, 28, 28);
    style.Colors[ImGuiCol_FrameBgHovered] = ImColor(28, 28, 28);

    style.Colors[ImGuiCol_TitleBg] = ImColor(30, 30, 30);
    style.Colors[ImGuiCol_TitleBgActive] = ImColor(28, 28, 28);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(28, 28, 28);
    
    
     style.Colors[ImGuiCol_Header]                 = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
     style.Colors[ImGuiCol_HeaderHovered]          = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
     style.Colors[ImGuiCol_HeaderActive]           = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
     style.Colors[ImGuiCol_Separator]              =  style.Colors[ImGuiCol_Border];
     style.Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
     style.Colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
     style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
     style.Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
     style.Colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
     style.Colors[ImGuiCol_Tab]                    = ImLerp(style.Colors[ImGuiCol_Header],        style.Colors[ImGuiCol_TitleBgActive], 0.80f);
     style.Colors[ImGuiCol_TabHovered]             =  style.Colors[ImGuiCol_HeaderHovered];
     style.Colors[ImGuiCol_TabActive]              = ImLerp( style.Colors[ImGuiCol_HeaderActive],  style.Colors[ImGuiCol_TitleBgActive], 0.60f);
     style.Colors[ImGuiCol_TabUnfocused]           = ImLerp( style.Colors[ImGuiCol_Tab],           style.Colors[ImGuiCol_TitleBg], 0.80f);
     style.Colors[ImGuiCol_TabUnfocusedActive]     = ImLerp( style.Colors[ImGuiCol_TabActive],     style.Colors[ImGuiCol_TitleBg], 0.40f);
     style.Colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
     style.Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
     style.Colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
     style.Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);      style.Colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
     style.Colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);   // Prefer using Alpha=1.0 here
     style.Colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);   // Prefer using Alpha=1.0 here
  //  style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.35f, 0.35f, 0.35f, 0.17f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
   
}

static int curTheme = 5;

typedef unsigned int uint;

char* data;
#define S(data)

static char buf[500];
static const char* buf1;

bool Tab(const char* label, const bool selected, const ImVec2& size_arg) {
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
    
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

    ImVec2 pos = window->DC.CursorPos;

    ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

    if (selected)
        window->DrawList->AddRectFilled({ bb.Min.x + 20,bb.Max.y - 7 }, { bb.Max.x - 20, bb.Max.y - 5 }, ImColor(255,255,255), 6);

    window->DrawList->AddText(ImVec2(bb.Min.x + size_arg.x / 2 - ImGui::CalcTextSize(label).x / 2, bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2),
        ImColor(IM_COL32_WHITE), label);

    return pressed;
}

typedef enum { TOUCH_ACTION_DOWN = 0, TOUCH_ACTION_UP, TOUCH_ACTION_MOVE } TOUCH_ACTION;

typedef struct {
    TOUCH_ACTION action;
    float x;
    float y;
    int pointers;
    float y_velocity;
    float x_velocity;
}TOUCH_EVENT;
TOUCH_EVENT g_LastTouchEvent;

bool openeds=true;
int height;
ImVec2 WinPos, WinSize;

#include "Drawing.h"

bool menuss = true;
bool menusss = false;
bool menussss = false;
bool menusssss = false;

void DrawMenu() {
    
    stylesMeh();
    
	ImGuiIO& io = ImGui::GetIO();
    
    ImGui::GetStyle().Alpha = 20;

    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    
if(openMenuuuu){

ImGui::SetNextWindowSize(ImVec2(1043, 574), ImGuiCond_Once);
if(!ImGui::Begin(OBFUSCATE("SwaggY Projects | Discord : SwaggY#0779"), NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize)){
ImGui::End();
return;
}

int fps = int(io.Framerate);
float deltat = io.DeltaTime;
std::string t =  "FPS: " + std::to_string(fps);
// ImGui::Text(t.c_str());

ImGui::BeginChild("##leftChild", ImVec2(ImGui::GetWindowSize().x/8.35f, ImGui::GetContentRegionAvail().y )); 
        {
  //  ImGui::Text(" Player");
    if(ImGui::Button(ICON_FA_USER"", ImVec2(110.f, 100.f))){
    menuss = true;
menusss = false;
menussss = false;
menusssss = false;
    }
    
   // ImGui::Text(" Render");
    if(ImGui::Button(/*/ICON_FA_GAMEPAD/*/ICON_FA_CIRCLE_NOTCH"", ImVec2(110.f, 100.f))){
    menuss = false;
menusss = true;
menussss = false;
menusssss = false;
    }//ICON_FA_BOMB
    
  //  ImGui::Text(" Skins");
    if(ImGui::Button(ICON_FA_EYE"", ImVec2(110.f, 100.f))){
    menuss = false;
menusss = false;
menussss = false;
menusssss = true;    
    }
    
  //  ImGui::Text(" Aimbot");
    if(ImGui::Button(ICON_FA_CROSSHAIRS"", ImVec2(110.f, 100.f))){
    menuss = false;
menusss = false;
menussss = true;
menusssss = false;   
    }
    
        }
            ImGui::EndChild();

            {
                ImGui::SameLine(0);
                ImGui::SameLine();
            }
    ImGui::BeginChild("##rightChild", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));
    {

if(menuss){

if (ImGui::CollapsingHeader(OBFUSCATE(ICON_FA_USER " legit"))) {
	            ImGui::Separator();
	            // hacks
                ImGui::Separator();
                }
        
                if (ImGui::CollapsingHeader(OBFUSCATE(ICON_FA_USER " rage"))) {
                ImGui::Separator();
                // hacks
                ImGui::Separator();
                }
                
                if (ImGui::CollapsingHeader(OBFUSCATE(ICON_FA_BOX " world"))) {
                // hacks
                }
                
} else if(menusss){
	if (ImGui::CollapsingHeader(OBFUSCATE(ICON_FA_CUBE " chams"))) {
                ImGui::Separator();
                ImGui::Spacing();
                // hacks
                ImGui::Separator();
                }
	if (ImGui::CollapsingHeader(OBFUSCATE(ICON_FA_CAMERA " environment"))) {
		ImGui::Separator();
                // hacks
        ImGui::Separator();
            }
            
            
            if (ImGui::CollapsingHeader(OBFUSCATE(ICON_FA_CAMERA " camera")))
            {
            	ImGui::Separator();
                // hacks
                ImGui::Separator();
            }
            
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            // hacks
            ImGui::Spacing();
            
            if (curTheme == 0)
            {
                
                colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 0.95f);
                colors[ImGuiCol_TextDisabled] = ImVec4(0.73f, 0.75f, 0.74f, 1.00f);
                colors[ImGuiCol_WindowBg] = ImVec4(0.39f, 0.00f, 0.63f, 0.11f);
                colors[ImGuiCol_ChildBg] = ImVec4(0.39f, 0.00f, 0.63f, 0.15f);
                colors[ImGuiCol_PopupBg] = ImVec4(0.94f, 0.02f, 1.28f, 0.30f);
                colors[ImGuiCol_Border] = ImVec4(2.45f, 0.00f, 1.01f, 0.30f);
                colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                colors[ImGuiCol_FrameBg] = ImVec4(0.94f, 0.02f, 1.28f, 0.15f);
                colors[ImGuiCol_FrameBgHovered] = ImVec4(0.94f, 0.02f, 1.28f, 0.25f);
                colors[ImGuiCol_FrameBgActive] = ImVec4(0.94f, 0.02f, 1.28f, 0.07f);
                colors[ImGuiCol_TitleBg] = ImVec4(0.75f, 0.01f, 0.94f, 1.2f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0.39f, 0.00f, 0.63f, 0.15f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.39f, 0.00f, 0.63f, 0.15f);
                colors[ImGuiCol_MenuBarBg] = ImVec4(0.34f, 0.16f, 0.16f, 1.00f);
                colors[ImGuiCol_ScrollbarBg] = ImVec4(0.94f, 0.02f, 1.28f, 0.30f);
                colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.94f, 0.02f, 1.28f, 0.30f);
                colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.94f, 0.02f, 1.28f, 0.40f);
                colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.94f, 0.02f, 1.28f, 0.20f);
                colors[ImGuiCol_CheckMark] = ImVec4(2.45f, 0.00f, 0.50f, 0.25f);
                colors[ImGuiCol_SliderGrab] = ImVec4(2.45f, 0.00f, 0.50f, 0.25f);
                colors[ImGuiCol_SliderGrabActive] = ImVec4(2.45f, 0.00f, 0.50f, 0.15f);
                colors[ImGuiCol_Button] = ImVec4(0.39f, 0.00f, 0.63f, 0.0f);
                colors[ImGuiCol_ButtonHovered] = ImVec4(0.39f, 0.00f, 0.63f, 0.15f);
                colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.00f, 0.63f, 0.05f);
                colors[ImGuiCol_Header] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
                colors[ImGuiCol_HeaderHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.65f);
                colors[ImGuiCol_HeaderActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.00f);
                colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
                colors[ImGuiCol_SeparatorHovered] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
                colors[ImGuiCol_SeparatorActive] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
                colors[ImGuiCol_ResizeGrip] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
                colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
                colors[ImGuiCol_ResizeGripActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
                colors[ImGuiCol_Tab] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
                colors[ImGuiCol_TabHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
                colors[ImGuiCol_TabActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
                colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
                colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
                colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
                colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
                colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
                colors[ImGuiCol_TextSelectedBg] = ImVec4(2.45f, 0.00f, 1.01f, 0.30f);
                colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
                colors[ImGuiCol_NavHighlight] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
                colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
                colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
                colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
            }
            else if (curTheme == 1)
            {
                
                colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
                colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
                colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
                colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
                colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
                colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
                colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
                colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
                colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
                colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
                colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
                colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
                colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
                colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
                colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
                colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
                colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
                colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
                colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 0.00f);
                colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
                colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
                colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
                colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
                colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
                colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
                colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
                colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
                colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
                colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
                colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
                colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
                colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
                colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
                colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
                colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
                colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
                colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
                colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
                colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
                colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
                colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
                colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
            }
            else if (curTheme == 2)
            {
                colors[ImGuiCol_Text] = ImVec4(0.75f, 0.75f, 0.75f, 1.00f);
                colors[ImGuiCol_TextDisabled] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
                colors[ImGuiCol_WindowBg] = ImVec4(0.03f, 0.03f, 0.03f, 1.00f);
                colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 0.19f, 0.19f, 0.10f);
                colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
                colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);
                colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
                colors[ImGuiCol_FrameBgHovered] = ImVec4(0.37f, 0.14f, 0.14f, 0.67f);
                colors[ImGuiCol_FrameBgActive] = ImVec4(0.39f, 0.20f, 0.20f, 0.67f);
                colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
                colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
                colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
                colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
                colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
                colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
                colors[ImGuiCol_CheckMark] = ImVec4(0.56f, 0.10f, 0.10f, 1.00f);
                colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 0.19f, 0.19f, 0.40f);
                colors[ImGuiCol_SliderGrabActive] = ImVec4(0.89f, 0.00f, 0.19f, 1.00f);
                colors[ImGuiCol_Button] = ImVec4(1.00f, 0.19f, 0.19f, 0.00f);
                colors[ImGuiCol_ButtonHovered] = ImVec4(0.80f, 0.17f, 0.00f, 1.00f);
                colors[ImGuiCol_ButtonActive] = ImVec4(0.89f, 0.00f, 0.19f, 1.00f);
                colors[ImGuiCol_Header] = ImVec4(0.33f, 0.35f, 0.36f, 0.53f);
                colors[ImGuiCol_HeaderHovered] = ImVec4(0.76f, 0.28f, 0.44f, 0.67f);
                colors[ImGuiCol_HeaderActive] = ImVec4(0.47f, 0.47f, 0.47f, 0.67f);
                colors[ImGuiCol_Separator] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
                colors[ImGuiCol_SeparatorHovered] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
                colors[ImGuiCol_SeparatorActive] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
                colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
                colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
                colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
                colors[ImGuiCol_Tab] = ImVec4(0.07f, 0.07f, 0.07f, 0.51f);
                colors[ImGuiCol_TabHovered] = ImVec4(0.86f, 0.23f, 0.43f, 0.67f);
                colors[ImGuiCol_TabActive] = ImVec4(0.19f, 0.19f, 0.19f, 0.57f);
                colors[ImGuiCol_TabUnfocused] = ImVec4(0.05f, 0.05f, 0.05f, 0.90f);
                colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.13f, 0.13f, 0.74f);
                colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
                colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
                colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
                colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
                colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
                colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
                colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
                colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
            }
            else if (curTheme == 3)
            {
                colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
                colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
                colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
                colors[ImGuiCol_ChildBg] = ImVec4(0.13f, 0.75f, 0.55f, 0.10f);
                colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
                colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
                colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.44f, 0.44f, 0.60f);
                colors[ImGuiCol_FrameBgHovered] = ImVec4(0.57f, 0.57f, 0.57f, 0.70f);
                colors[ImGuiCol_FrameBgActive] = ImVec4(0.76f, 0.76f, 0.76f, 0.80f);
                colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.60f);
                colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
                colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
                colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
                colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
                colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
                colors[ImGuiCol_CheckMark] = ImVec4(0.13f, 0.75f, 0.55f, 0.80f);
                colors[ImGuiCol_SliderGrab] = ImVec4(0.13f, 0.75f, 0.75f, 0.80f);
                colors[ImGuiCol_SliderGrabActive] = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
                colors[ImGuiCol_Button] = ImVec4(0.13f, 0.75f, 0.55f, 0.00f);
                colors[ImGuiCol_ButtonHovered] = ImVec4(0.13f, 0.75f, 0.75f, 0.60f);
                colors[ImGuiCol_ButtonActive] = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
                colors[ImGuiCol_Header] = ImVec4(0.13f, 0.75f, 0.55f, 0.40f);
                colors[ImGuiCol_HeaderHovered] = ImVec4(0.13f, 0.75f, 0.75f, 0.60f);
                colors[ImGuiCol_HeaderActive] = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
                colors[ImGuiCol_Separator] = ImVec4(0.13f, 0.75f, 0.55f, 0.40f);
                colors[ImGuiCol_SeparatorHovered] = ImVec4(0.13f, 0.75f, 0.75f, 0.60f);
                colors[ImGuiCol_SeparatorActive] = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
                colors[ImGuiCol_ResizeGrip] = ImVec4(0.13f, 0.75f, 0.55f, 0.40f);
                colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.13f, 0.75f, 0.75f, 0.60f);
                colors[ImGuiCol_ResizeGripActive] = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
                colors[ImGuiCol_Tab] = ImVec4(0.13f, 0.75f, 0.55f, 0.80f);
                colors[ImGuiCol_TabHovered] = ImVec4(0.13f, 0.75f, 0.75f, 0.80f);
                colors[ImGuiCol_TabActive] = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
                colors[ImGuiCol_TabUnfocused] = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
                colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.36f, 0.36f, 0.36f, 0.54f);
                colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
                colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
                colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
                colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
                colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
                colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
                colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
                colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
            }
            else if (curTheme == 4)
            {
                colors[ImGuiCol_Text] = ImVec4(0.03f, 0.03f, 0.03f, 1.00f);
                colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
                colors[ImGuiCol_WindowBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
                colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
                colors[ImGuiCol_PopupBg] = ImVec4(0.93f, 0.93f, 0.93f, 0.98f);
                colors[ImGuiCol_Border] = ImVec4(0.71f, 0.71f, 0.71f, 0.08f);
                colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.04f);
                colors[ImGuiCol_FrameBg] = ImVec4(0.71f, 0.71f, 0.71f, 0.55f);
                colors[ImGuiCol_FrameBgHovered] = ImVec4(0.94f, 0.94f, 0.94f, 0.55f);
                colors[ImGuiCol_FrameBgActive] = ImVec4(0.71f, 0.78f, 0.69f, 0.98f);
                colors[ImGuiCol_TitleBg] = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.82f, 0.78f, 0.78f, 0.51f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0.78f, 0.78f, 0.78f, 1.00f);
                colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
                colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.61f);
                colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.90f, 0.90f, 0.90f, 0.30f);
                colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.92f, 0.92f, 0.92f, 0.78f);
                colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
                colors[ImGuiCol_CheckMark] = ImVec4(0.184f, 0.407f, 0.193f, 1.00f);
                colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
                colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                colors[ImGuiCol_Button] = ImVec4(0.71f, 0.78f, 0.69f, 0.00f);
                colors[ImGuiCol_ButtonHovered] = ImVec4(0.725f, 0.805f, 0.702f, 1.00f);
                colors[ImGuiCol_ButtonActive] = ImVec4(0.793f, 0.900f, 0.836f, 1.00f);
                colors[ImGuiCol_Header] = ImVec4(0.71f, 0.78f, 0.69f, 0.31f);
                colors[ImGuiCol_HeaderHovered] = ImVec4(0.71f, 0.78f, 0.69f, 0.80f);
                colors[ImGuiCol_HeaderActive] = ImVec4(0.71f, 0.78f, 0.69f, 1.00f);
                colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
                colors[ImGuiCol_SeparatorHovered] = ImVec4(0.14f, 0.44f, 0.80f, 0.78f);
                colors[ImGuiCol_SeparatorActive] = ImVec4(0.14f, 0.44f, 0.80f, 1.00f);
                colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
                colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.45f);
                colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
                colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
                colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
                colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
                colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
               // colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
                colors[ImGuiCol_DragDropTarget] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
                colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
                colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);
            }
            
} else if(menussss){
    // hacks
} else if(menusssss){
    
    // ImGui::Text(OBFUSCATE("knives"));
                      ImGui::Separator();
                      // hacks
                      ImGui::Separator();
                     // ImGui::Text(OBFUSCATE("gloves"));
                      // hacks
                      ImGui::Separator();
                    ///  ImGui::Text(OBFUSCATE("weapons"));
                      ImGui::Separator();
                      
}
ImGui::EndChild();
}
//
}
//
if (openMenuuuu){
ImGui::End();
}

ImVec2 texts = ImGui::CalcTextSize("Zygisk MM");
ImGui::SetNextWindowPos(ImVec2(200, 50), ImGuiCond_Once);
ImGui::SetNextWindowSize(ImVec2(400, 50), ImGuiCond_Once);

ImGui::Begin("##watermark", nullptr, 315);
std::string water = "SwaggY Projects | FPS: " + std::to_string(int(io.Framerate));
Color colColors(255, 255, 255);
                Color colRainbows = colColors;
                static float flRainbow;
                float flSpeed = 1.0f;
                int height, width;
                height = scrH;
                width = scrW;
                ImVec2 curPos = ImGui::GetCursorPos();
                ImVec2 curWindowPos = ImGui::GetWindowPos();
                curPos.x += curWindowPos.x;
                curPos.y += curWindowPos.y;
                ImDrawList *windowDrawList = ImGui::GetWindowDrawList();
                Drawing::ImDrawRectRainbow(curPos.x - 10, curPos.y - 10,
                                           ImGui::GetWindowSize().x + height, curPos.y-3, flSpeed,
                                           flRainbow);
ImGui::GetStyle().Alpha = 50;
ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(0.20f, 0.25f, 0.29f, 0.00f));
ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.25f, 0.29f, 0.00f));
ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.20f, 0.25f, 0.29f, 0.00f));
ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.20f, 0.25f, 0.29f, 0.00f));
ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.20f, 0.25f, 0.29f, 0.00f));
ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.20f, 0.25f, 0.29f, 0.00f));
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.20f, 0.25f, 0.29f, 0.00f));

if (ImGui::Button(water.c_str(), ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y))) {
    openMenuuuu = !openMenuuuu;
}

ImGui::PopStyleColor(7);

ImGui::End();
}

#include <iostream>
#include <iomanip>
#include <sstream>

static bool init;

void SetBlackGoldTheme()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    
    style.ButtonTextAlign = ImVec2(0.5,0.65);
        style.WindowTitleAlign = ImVec2(0.5, 0.5);
    style.WindowRounding = 0.0f;
    style.FrameRounding = 0.0f;
    style.ScrollbarRounding = 0.0f;
    //style.PopupBorderSize = 0.0f;
    colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg]               = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border]                 = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_TitleBg]                = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark]              = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Button]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
    colors[ImGuiCol_HeaderHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator]              = colors[ImGuiCol_Border];
    colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 0.00f);
    colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0);
    colors[ImGuiCol_Tab]                    = ImLerp(colors[ImGuiCol_Header],       colors[ImGuiCol_TitleBgActive], 0.80f);
    colors[ImGuiCol_TabHovered]             = colors[ImGuiCol_HeaderHovered];
    colors[ImGuiCol_TabActive]              = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
    colors[ImGuiCol_TabUnfocused]           = ImLerp(colors[ImGuiCol_Tab],          colors[ImGuiCol_TitleBg], 0.80f);
    colors[ImGuiCol_TabUnfocusedActive]     = ImLerp(colors[ImGuiCol_TabActive],    colors[ImGuiCol_TitleBg], 0.40f);
    colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
    colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);   // Prefer using Alpha=1.0 here
    colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);   // Prefer using Alpha=1.0 here
    colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
    colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

bool HandleInputEvent(JNIEnv *env, int motionEvent, int x, int y, int p);
float initialTouchX, initialTouchY;

bool  HandleInputEvent(JNIEnv *env, int motionEvent, int x, int y, int p) {
    float velocity_y = (float)((float)y - g_LastTouchEvent.y) / 100.f;
    g_LastTouchEvent = {.action = (TOUCH_ACTION) motionEvent, .x = static_cast<float>(x), .y = static_cast<float>(y), .pointers = p, .y_velocity = velocity_y};
    ImGuiIO &io = ImGui::GetIO();
    io.MousePos.x = g_LastTouchEvent.x;
    io.MousePos.y = g_LastTouchEvent.y;
    if(motionEvent == 2){
        if (g_LastTouchEvent.pointers > 1) {
            io.MouseWheel = g_LastTouchEvent.y_velocity;
            io.MouseDown[0] = false;
        }
        else {
            io.MouseWheel = 0;
        }
    }
    if(motionEvent == 0){
        io.MouseDown[0] = true;
    }
    if(motionEvent == 1){
        io.MouseDown[0] = false;
    }
    if (g_LastTouchEvent.action == 0) {
            initialTouchX = g_LastTouchEvent.x;
            initialTouchY = g_LastTouchEvent.y;
    }
     if (g_LastTouchEvent.action == 1
        && g_LastTouchEvent.x >= WinPos.x
        && g_LastTouchEvent.y >= (WinPos.y)
        && g_LastTouchEvent.x <= (WinPos.x + WinSize.x)
        && g_LastTouchEvent.y <= (WinPos.y + WinSize.y)
            && (g_LastTouchEvent.x - initialTouchX) < 10
            && (g_LastTouchEvent.y - initialTouchY) < 10
    ) {
               openeds = !openeds;
    }
    return true;
}
 
bool (*old_nativeInjectEvent )(JNIEnv*, jobject ,jobject event);
bool hook_nativeInjectEvent(JNIEnv* env, jobject instance,jobject event){
        jclass MotionEvent = env->FindClass(("android/view/MotionEvent"));
        if(!MotionEvent){
      //      LOGI("Can't find MotionEvent!"); 
        }
        
        if(!env->IsInstanceOf(event, MotionEvent)){
            return old_nativeInjectEvent(env, instance, event);
        }
        //LOGD("Processing Touch Event!");
        jmethodID id_getAct = env->GetMethodID(MotionEvent, ("getActionMasked"), ("()I"));
        jmethodID id_getX = env->GetMethodID(MotionEvent, ("getX"), ("()F"));
        jmethodID id_getY = env->GetMethodID(MotionEvent, ("getY"), ("()F"));
        jmethodID id_getPs = env->GetMethodID(MotionEvent, ("getPointerCount"), ("()I"));
        HandleInputEvent(env, env->CallIntMethod(event, id_getAct),env->CallFloatMethod(event, id_getX), env->CallFloatMethod(event, id_getY), env->CallIntMethod(event, id_getPs));
        if (true){
            return old_nativeInjectEvent(env, instance, event);
        }
        return false;
}

jint (*old_RegisterNatives )(JNIEnv*, jclass, JNINativeMethod*,jint);
jint hook_RegisterNatives(JNIEnv* env, jclass destinationClass, JNINativeMethod* methods,
                          jint totalMethodCount){

    int currentNativeMethodNumeration;
    for (currentNativeMethodNumeration = 0; currentNativeMethodNumeration < totalMethodCount; ++currentNativeMethodNumeration )
    {
        if (!strcmp(methods[currentNativeMethodNumeration].name, ("nativeInjectEvent")) ){
            DobbyHook(methods[currentNativeMethodNumeration].fnPtr, (void*)hook_nativeInjectEvent, (void **)&old_nativeInjectEvent);
        }
    }
    //SearchActivity(env);
    return old_RegisterNatives(env, destinationClass, methods, totalMethodCount);
}

void glInit()
{
	
    if (!init)
    {
        auto context = ImGui::CreateContext();
        if (!context)
        {
            return;
        }
        ImGuiIO &io = ImGui::GetIO();
        ImFontConfig font_cfg2;
        font_cfg2.SizePixels = 30.f; 
        font_cfg2.GlyphRanges = io.Fonts->GetGlyphRangesCyrillic();
        io.Fonts->AddFontFromMemoryTTF(&Font, sizeof Font, 30.f,&font_cfg2);
        ImFontConfig font_cfg;
        font_cfg.MergeMode = true;
        static const ImWchar icon_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0x0};
        io.Fonts->AddFontFromMemoryCompressedBase85TTF(FontAwesome6_compressed_data_base85, 33.0f, &font_cfg, icon_ranges);

        io.IniFilename = NULL;
        io.KeyMap[ImGuiKey_UpArrow] = 19;
        io.KeyMap[ImGuiKey_DownArrow] = 20;
        io.KeyMap[ImGuiKey_LeftArrow] = 21;
        io.KeyMap[ImGuiKey_RightArrow] = 22;
        io.KeyMap[ImGuiKey_Enter] = 66;
        io.KeyMap[ImGuiKey_Backspace] = 67;
        io.KeyMap[ImGuiKey_PageUp] = 92;
        io.KeyMap[ImGuiKey_PageDown] = 93;
        io.KeyMap[ImGuiKey_Escape] = 111;
        io.KeyMap[ImGuiKey_Delete] = 112;
        io.KeyMap[ImGuiKey_Home] = 122;
        io.KeyMap[ImGuiKey_End] = 123;
        io.KeyMap[ImGuiKey_Insert] = 124;
        io.KeyMap[ImGuiKey_UpArrow] = 19;
        io.KeyMap[ImGuiKey_DownArrow] = 20;
        io.KeyMap[ImGuiKey_LeftArrow] = 21;
        io.KeyMap[ImGuiKey_RightArrow] = 22;
        io.KeyMap[ImGuiKey_Enter] = 66;
        io.KeyMap[ImGuiKey_Backspace] = 67;
        io.KeyMap[ImGuiKey_PageUp] = 92;
        io.KeyMap[ImGuiKey_PageDown] = 93;
        io.KeyMap[ImGuiKey_Escape] = 111;
        io.KeyMap[ImGuiKey_Delete] = 112;
        io.KeyMap[ImGuiKey_Home] = 122;
        io.KeyMap[ImGuiKey_End] = 123;
        io.KeyMap[ImGuiKey_Insert] = 124;

        SetBlackGoldTheme();

        ImGui::GetStyle().ScaleAllSizes(3.0f*scale);

        ImGui_ImplAndroid_Init(nullptr);
        ImGui_ImplOpenGL3_Init();
        
    switch (g_LastTouchEvent.action) {
        case TOUCH_ACTION_MOVE:
            if (g_LastTouchEvent.pointers > 1) {
                io.MouseWheel = g_LastTouchEvent.y_velocity;
                io.MouseDown[0] = false;
            }
            else {
                io.MouseWheel = 0;
            }
            break;
        case TOUCH_ACTION_DOWN:
            io.MouseDown[0] = true;
            break;
        case TOUCH_ACTION_UP:
            io.MouseDown[0] = false;
            
            break;
        default:
            break;
    }
        
        init = true;
    }
    if (init){
        ImGuiIO &io = ImGui::GetIO();
        static bool WantTextInputLast = false;
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplAndroid_NewFrame(scrW, scrH);;
        ImGui::NewFrame();
        DrawMenu(); //
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        io.KeysDown[io.KeyMap[ImGuiKey_UpArrow]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_DownArrow]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_LeftArrow]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_RightArrow]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_Tab]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_Enter]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_Backspace]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_PageUp]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_PageDown]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_Escape]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_Delete]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_Home]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_End]] = false;
        io.KeysDown[io.KeyMap[ImGuiKey_Insert]] = false;
        ImGuiStyle& style = ImGui::GetStyle();
        ImVec4* colors = style.Colors;
        colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        ImGui::EndFrame();
    }
}
// Input.get_touchCount
int (*old_touches)(void *instance);
int touches(void* instance){
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse) {
        return 0;
    }
    return old_touches(instance);
}

void offsets_load() {
 
  DobbyHook((void*)KittyMemory::getAbsoluteAddress(libName, string2Offset(OBFUSCATE("0x126D438"))), (void *) touches, (void **) &old_touches);
  
  hexPatches.UnG = MemoryPatch::createWithHex(targetLibName, 0x140B390, OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
  
  
pthread_exit(nullptr);
}

