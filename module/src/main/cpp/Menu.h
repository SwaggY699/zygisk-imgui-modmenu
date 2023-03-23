#ifndef MENU
#define MENU

#include "ESP.h"
namespace Menu
{
    
    
    ImVec4 color = ImVec4(1, 1, 1, 1);
    
    void DrawMenu()
    {
        if (ImGui::Begin(OBFUSCATE("SwaggY Projects | Discord : SwaggY#0779 ")), ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse) {
		
	    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
	        
            if (ImGui::BeginTabBar("VIP Mods", tab_bar_flags))
            {
                if (ImGui::BeginTabItem("View"))
                {
                ImGui::Checkbox(OBFUSCATE("Map Hack"), &mhack);
	        
		ImGui::EndTabItem();
                }
                
                ImGui::EndTabBar();
                
		}
                
		}
    }
    void DrawImGui()
    {
        if (init && glHeight)
        {
            static bool WantTextInputLast = false;
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
            ImGui::NewFrame();
            DrawESP(ImGui::GetBackgroundDrawList());
            DrawMenu();
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            ImGui::EndFrame();
        }
    }
}
#endif MENU
