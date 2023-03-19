#ifndef MENU
#define MENU

bool zzz;

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
                if (ImGui::BeginTabItem("ESP"))
                {
                 ImGui::Checkbox(OBFUSCATE("test"), &zzz);
                /*ImGui::Checkbox(OBFUSCATE("ESP"), &Enable_ESP);
				ImGui::Checkbox(OBFUSCATE("Line"), &PlayerLine);
				ImGui::Checkbox(OBFUSCATE("Box"), &PlayerBox);
				ImGui::Checkbox(OBFUSCATE("Health"), &PlayerHealth);	
				ImGui::Checkbox(OBFUSCATE("Name"), &PlayerName);
				ImGui::Checkbox(OBFUSCATE("Distance"), &PlayerDistance);
		     	ImGui::Checkbox(OBFUSCATE("Alert"), &PlayerAlert); */
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
            //DrawESP(ImGui::GetBackgroundDrawList());
            DrawMenu();
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            ImGui::EndFrame();
        }
    }
}
#endif MENU
