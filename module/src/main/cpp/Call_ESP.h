////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//uintptr_t il2cppMap;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Enable_ESP;
bool PlayerLine;
bool PlayerBox;
bool PlayerHealth;
bool PlayerName;
bool HeroName;
bool PlayerDistance;
bool PlayerAlert;

struct sConfig {
	struct sInitImGui {
		bool initImGui;
		bool bInitDone;
	};
	sInitImGui InitImGui;
};

sConfig Config{0};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Transform;

class Component {
	public:
	
	Transform *get_transform() {
		Transform *(*get_transform_)(Component *component) = (Transform *(*)(Component *)) (Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_transform")));
		return get_transform_(this);
	}
};

class Transform : public Component {
	public:
	
	Vector3 get_position() {
		Vector3 (*get_position_)(Transform *transform) = (Vector3 (*)(Transform *)) (Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_position")));
		return get_position_(this);
    }
};

class Camera : public Component {
	public:
	
	static Camera *get_main() {
		Camera *(*get_main_)() = (Camera *(*)()) (Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Camera"), OBFUSCATE("get_main")));
		return get_main_();
	}
	
	Vector3 WorldToScreenPoint(Vector3 position) {
		Vector3 (*WorldToScreenPoint_)(Camera* camera, Vector3 position) = (Vector3 (*)(Camera *, Vector3)) (Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Camera"), OBFUSCATE("WorldToScreenPoint"), 1));
		return WorldToScreenPoint_(this, position);
	}
};

class Character {
	
}

class GameSystem {
	public:
	
	FasterDictionary<int, Character> m_playerCharacters;
};

class GameplayModule {
	public:
	
	static GameplayModule *get_Instance() {
		GameplayModule *(*get_Instance_)() = (GameplayModule *(*)()) (m_IL2Cpp + 0x68f678);
		//(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("CriticalOps.Gameplay"), OBFUSCATE("GameplayModule"), OBFUSCATE("get_Instance")));
		return get_Instance_();
	}
	
	GameSystem *get_Game() {
		GameSystem *(*get_Game_)(GameplayModule *gameplayModule) = (GameSystem *(*)(GameplayModule *)) (m_IL2Cpp + 0x68f76c);
		//(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("CriticalOps.Gameplay"), OBFUSCATE("GameplayModule"), OBFUSCATE("get_Instance")));
		return get_Game_(this);
	}
	
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawESP(ImDrawList *draw) {
	
	if (Config.ESPMenu.espEnable) {
		
		GameplayModule *get_Instance = GameplayModule::get_Instance();
		if (get_Instance != nullptr) {
			
			GameSystem *get_Game = get_Instance->get_Game();
			if (get_Game != nullptr) {
				
				List<Character *> *get_AllCharacters = get_Game->get_AllCharacters();
				if (get_AllCharacters != nullptr) {
					
					Character **characters = (Character **) get_AllCharacters->getItems();
					for (int i = 0; i < get_AllCharacters->getSize(); i++) {
						Character *character = characters[i];
						if (character != nullptr) {
							
							CharacterModel *get_Model = character->get_Model();
							if (get_Model != nullptr) {
								
								Vector3 rootTF = Vector3::zero();
								
								Transform *m_root = get_Model->m_root();
								
								if (m_root != nullptr) {
									rootTF = Camera::get_main()->WorldToScreenPoint(m_root->get_position());
								}
								
								if (rootTF.z > 0 ) {
									
									if (EspLine) {
										draw->AddLine(ImVec2(glWidth / 2, 0), ImVec2(rootTF.x, glHeight - rootTF.y), IM_COL32(255, 255, 0, 255), 1.5f);
									}
									
								}
							}
						}
					}
				}
			}
		}
	}
}
