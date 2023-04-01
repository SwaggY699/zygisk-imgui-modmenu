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
                if (ImGui::BeginTabItem("Chams"))
                {
                ImGui::Checkbox(OBFUSCATE("Default"), &chams);
	        ImGui::Checkbox(OBFUSCATE("Shading"), &shading);
	        ImGui::Checkbox(OBFUSCATE("Wireframe"), &wireframe);
	        ImGui::Checkbox(OBFUSCATE("Glow"), &glow);
	        ImGui::Checkbox(OBFUSCATE("Outline"), &outline);
	        ImGui::Checkbox(OBFUSCATE("Rainbow"), &rainbow);
		ImGui::EndTabItem();
                }
                
                ImGui::EndTabBar();
		}
		}
        
        if (chams) {
        SetWallhack(true);
        } else {
        SetWallhack(false);
        }
        
        if (shading) {
        SetWallhackS(true);
        } else {
        SetWallhackS(false);
        }
        
        if (wireframe) {
        SetWallhackW(true);  
        } else {
        SetWallhackW(false);  
        }
        
        if (glow) {
        SetWallhackG(true);
        } else {
        SetWallhackG(false);
        }
        
        if (outline) {
        SetWallhackO(true); 
        } else {
        SetWallhackO(false);
        }
        
        if (rainbow) {
        SetRainbow(true);
        } else {
        SetRainbow(false);
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
            //DrawESP(ImGui::GetBackgroundDrawList());
            DrawMenu();
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            ImGui::EndFrame();
        }
    }
}
#endif MENU
