#include <cstdint>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <dlfcn.h>
#include <string>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include "Dobby/include/dobby.h"
#include "hack.h"
#include "imgui.h"
JNIEnv *g_env = nullptr;
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include "KittyMemory/MemoryPatch.h"

//
#include <map>
#include <string>
#include <string.h>
#include <cstring>
//typedef unsigned long ulong;
//
inline std::map < std::string, void*> _methods;
inline std::map < std::string, size_t > _fields;
/*
template<typename T>
inline T getFieldValue(void *instance,ulong offset) {
    return *(T*)((uintptr_t)instance + offset);
}

template<typename T>
inline T setFieldValue(void *instance,ulong offset, T value) {
    *(T*)((uintptr_t)instance + offset) = value;
}
*/
#include "Il2Cpp.h"
//
#include "xdl.h"
//

#include "main.h"

#include "ImGuiStuff.h"

//#include "Call_ESP_2.h"

bool mhack;

bool (*old_Bypass)(void *instance);
bool getBypass(void *instance) {
    if (instance != NULL) {
        if (mhack) {
            return true;
        }
    }
    return old_Bypass(instance);
}

#include "Menu.h"

/*
struct sConfig {
	struct sInitImGui {
		bool initImGui;
		bool bInitDone;
	};
	sInitImGui InitImGui;
};
sConfig Config{0};
*/

const char* gamePKG = "com.ngame.allstar.eu";

#define HOOK(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret my##func(__VA_ARGS__)


HOOK(void, Input, void *thiz, void *ex_ab, void *ex_ac){
    origInput(thiz, ex_ab, ex_ac);
    ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz);
    return;
}

bool SetCustomResolution = true;

void (*_SetResolutionn)(...);
void SetResolutionn(int width, int height, bool fullscreen){
if(SetCustomResolution){
  width = glWidth;
 height = glHeight;
}
_SetResolutionn(width, height, fullscreen);
}

jboolean (*orig_unity__nativeInjectEvent)(JNIEnv *env, jobject object, jobject inputEvent);
jboolean unity_nativeInjectEvent(JNIEnv *env, jobject object, jobject inputEvent) {
	ImGuiIO &io = ImGui::GetIO();
	
	jclass motionEventClass = env->FindClass(OBFUSCATE("android/view/MotionEvent"));
	
	if (env->IsInstanceOf(inputEvent, motionEventClass)) {
		jmethodID getActionMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getAction"), OBFUSCATE("()I"));
		jint getAction = env->CallIntMethod(inputEvent, getActionMethod);
		
		jmethodID getXMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getX"), OBFUSCATE("()F"));
		jfloat getX = env->CallFloatMethod(inputEvent, getXMethod);
		
		jmethodID getYMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getY"), OBFUSCATE("()F"));
		jfloat getY = env->CallFloatMethod(inputEvent, getYMethod);
		
		jmethodID getPointerCountMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getPointerCount"), OBFUSCATE("()I"));
		jint getPointerCount = env->CallIntMethod(inputEvent, getPointerCountMethod);
		
		switch(getAction) {
			
		case 0:
			io.MouseDown[0] = true;
			break;
		case 1:
			io.MouseDown[0] = false;
			break;
		case 2:
			if (getPointerCount > 1) {
				io.MouseDown[0] = false;
			} else {
				io.MouseWheel = 0;
            }
			break;
		}
		io.MousePos = ImVec2(getX, getY);
	}
	
	jclass KeyEventClass = env->FindClass(OBFUSCATE("android/view/KeyEvent"));
	if (env->IsInstanceOf(inputEvent, KeyEventClass)) {
		jmethodID getActionMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getAction"), OBFUSCATE("()I"));
		if (env->CallIntMethod(inputEvent, getActionMethod) == 0) {
			jmethodID getKeyCodeMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getKeyCode"), OBFUSCATE("()I"));
			jmethodID getUnicodeCharMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getUnicodeChar"), OBFUSCATE("(I)I"));
			jmethodID getMetaStateMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getMetaState"), OBFUSCATE("()I"));
			
			io.AddInputCharacter(env->CallIntMethod(inputEvent, getUnicodeCharMethod, env->CallIntMethod(inputEvent, getMetaStateMethod)));
		}
	}
	return orig_unity__nativeInjectEvent(env, object, inputEvent);
}

jint (*old_RegisterNatives)(JNIEnv*, jclass, const JNINativeMethod*, jint);
jint hook_RegisterNatives(JNIEnv* env, jclass klazz, const JNINativeMethod* methods, jint methodcount) {
	for (int i = 0; i < methodcount; ++i) {
		auto method = methods[i];
		
		if (strcmp(method.name, OBFUSCATE("nativeInjectEvent")) == 0) {
            DobbyHook((void *) method.fnPtr, (void *) unity_nativeInjectEvent, (void **) &orig_unity__nativeInjectEvent);
		}
	}
	return old_RegisterNatives(env, klazz, methods, methodcount);
}

EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {

eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    
    if (glWidth <= 0 || glHeight <= 0) {
       return eglSwapBuffers(dpy, surface);
    }
    
    SetupImGui();
    Menu::DrawImGui();
    
    return old_eglSwapBuffers(dpy, surface);
}

int isGame(JNIEnv *env, jstring appDataDir) {
    if (!appDataDir)
        return 0;
    g_env = env;
    const char *app_data_dir = env->GetStringUTFChars(appDataDir, nullptr);
    int user = 0;
    static char package_name[256];
    if (sscanf(app_data_dir, "/data/%*[^/]/%d/%s", &user, package_name) != 2) {
        if (sscanf(app_data_dir, "/data/%*[^/]/%s", package_name) != 1) {
            package_name[0] = '\0';
          //  LOGW(S("fuck cock limited and sniffed... %s"), app_data_dir);
            return 0;
        }
    }
    if (strcmp(package_name, gamePKG) == 0) {
      //  LOGI(S("sniffing cock and game: %s"), package_name);
        game_data_dir = new char[strlen(app_data_dir) + 1];
        strcpy(game_data_dir, app_data_dir);
        env->ReleaseStringUTFChars(appDataDir, app_data_dir);
        return 1;
    } else {
        env->ReleaseStringUTFChars(appDataDir, app_data_dir);
        return 0;
    }
}

static int GetAndroidApiLevel() {
    char prop_value[PROP_VALUE_MAX];
    __system_property_get("ro.build.version.sdk", prop_value);
    return atoi(prop_value);
}

void dlopen_process(const char *name, void *handle) {
    //LOGD("dlopen: %s", name);
    if (!il2cpp_handle) {
        if (strstr(name, "libil2cpp.so")) {
            il2cpp_handle = handle;
     //       LOGI(S("Getting new free cock..."));
        }
    }
    if (!unity_handle) {
        if (strstr(name, "libunity.so")) {
            unity_handle = handle;
      //      LOGI(S("Getting new free cock:2..."));
        }
    }
    if (!egl_handle) {
        if (strstr(name, "libEGL.so")) {
            egl_handle = handle;
      //      LOGI(S("Getting new free cock:3..."));
        }
    }
    if (!gl2_handle) {
        if (strstr(name, "libGLESv2.so")) {
            gl2_handle = handle;
        //    LOGI(S("Getting new free cock:4..."));
        }
    }
}

HOOK_DEF(void*, __loader_dlopen, const char *filename, int flags, const void *caller_addr) {
    void *handle = orig___loader_dlopen(filename, flags, caller_addr);
    dlopen_process(filename, handle);
    return handle;
}

HOOK_DEF(void*, do_dlopen_V24, const char *name, int flags, const void *extinfo,
         void *caller_addr) {
    void *handle = orig_do_dlopen_V24(name, flags, extinfo, caller_addr);
    dlopen_process(name, handle);
    return handle;
}

HOOK_DEF(void*, do_dlopen_V19, const char *name, int flags, const void *extinfo) {
    void *handle = orig_do_dlopen_V19(name, flags, extinfo);
    dlopen_process(name, handle);
    return handle;
}


void *hack_thread(void *arg) {
	int api_level = GetAndroidApiLevel();
   if (api_level < 33) {
    if (api_level >= 33) {
        void *addr = DobbySymbolResolver(nullptr,
                                         "__dl__Z9do_dlopenPKciPK17android_dlextinfoPKv");
        if (addr) {
             DobbyHook(addr, (void *) new_do_dlopen_V24,
                      (void **) &orig_do_dlopen_V24);
        }
    } else if (api_level >= 26) {
        void *libdl_handle = dlopen("libdl.so", RTLD_LAZY);
        void *addr = dlsym(libdl_handle, "__loader_dlopen");
        LOGI("__loader_dlopen at: %p", addr);
        DobbyHook(addr, (void *) new___loader_dlopen,
                  (void **) &orig___loader_dlopen);
    } else if (api_level >= 24) {
        void *addr = DobbySymbolResolver(nullptr,
                                         "__dl__Z9do_dlopenPKciPK17android_dlextinfoPv");
        if (addr) {
            LOGI("get cock at: %p", addr);
            DobbyHook(addr, (void *) new_do_dlopen_V24,
                      (void **) &orig_do_dlopen_V24);
        }
    } else {
        void *addr = DobbySymbolResolver(nullptr,
                                         "__dl__Z9do_dlopenPKciPK17android_dlextinfo");
        if (addr) {
            LOGI("get cock at: %p", addr);
            DobbyHook(addr, (void *) new_do_dlopen_V19,
                      (void **) &orig_do_dlopen_V19);
        }
    }
    while (!il2cpp_handle) {
        sleep(1);
    }
    origin_thread(il2cpp_handle);
    sleep(5);
    while (!unity_handle or !gl2_handle) {
        sleep(1);
    }
    
    Il2CppAttach();
    sleep(1);
    
    _methods["Screen::SetResolution"] = Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", "SetResolution", 3);
    DobbyHook((void *) _methods["Screen::SetResolution"], (void *) SetResolutionn, (void **) &_SetResolutionn);
    
    _methods["LVActorLinker::CalcVisible"] = Il2CppGetMethodOffset("Project.Plugins_d.dll", "NucleusDrive.Logic", "LVActorLinker", "CalcVisible");
    DobbyHook((void *) _methods["LVActorLinker::CalcVisible"], (void *) getBypass, (void **) &old_Bypass);
    
    /*
    _methods["Camera::get_main"] = Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "get_main");
    _methods["Camera::WorldToScreenPoint"] = Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "WorldToScreenPoint", 1);
    _methods["ValueLinkerComponent::get_actorHp"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ValueLinkerComponent", "get_actorHp");
    _methods["ValueLinkerComponent::get_actorHpTotal"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ValueLinkerComponent", "get_actorHpTotal");
    _fields["CActorInfo::ActorName"] = Il2CppGetFieldOffset("Project_d.dll", "Assets.Scripts.GameLogic", "CActorInfo", "ActorName");
    _fields["ActorLinker::ValueComponent"] = Il2CppGetFieldOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "ValueComponent");
    _methods["ActorLinker::get_position"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "get_position");
    _fields["ActorLinker::CharInfo"] = Il2CppGetFieldOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "CharInfo");
    _methods["ActorLinker::IsHostCamp"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "IsHostCamp");
    _methods["ActorManager::GetAllHeros"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ActorManager", "GetAllHeros");
    _methods["KyriosFramework::get_actorManager"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios", "KyriosFramework", "get_actorManager");
    _methods["Camera::set_fieldOfView"] = Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "set_fieldOfView", 1);
    */
    
    auto eglSwapBuffers = dlsym(unity_handle, "eglSwapBuffers");
    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
        DobbyHook(eglSwapBuffers, (void *) hook_eglSwapBuffers, (void **) &old_eglSwapBuffers);
    } else
    {
        DobbyHook(eglSwapBuffers, (void *) hook_eglSwapBuffers, (void **) &old_eglSwapBuffers);
    }
    void *sym_input = DobbySymbolResolver("/system/lib/libinput.so", "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE");
    if (NULL != sym_input){
        DobbyHook((void *)sym_input, (void *) myInput, (void **)&origInput);
    }
    
    offsets_load();
    
    return nullptr;
    
    }else{
    
    sleep(2);
    auto addr = (uintptr_t)dlsym(RTLD_NEXT, "eglSwapBuffers");
    DobbyHook((void*)addr, (void*)hook_eglSwapBuffers, (void**)&old_eglSwapBuffers);
    void *sym_input = DobbySymbolResolver(("/system/lib/libinput.so"), ("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"));
    if (NULL != sym_input) {
        DobbyHook(sym_input,(void*)myInput,(void**)&origInput);
    }
    
    Il2CppAttach();
    sleep(1);
    
    _methods["Screen::SetResolution"] = Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", "SetResolution", 3);
    DobbyHook((void *) _methods["Screen::SetResolution"], (void *) SetResolutionn, (void **) &_SetResolutionn);
    
    _methods["LVActorLinker::CalcVisible"] = Il2CppGetMethodOffset("Project.Plugins_d.dll", "NucleusDrive.Logic", "LVActorLinker", "CalcVisible");
    DobbyHook((void *) _methods["LVActorLinker::CalcVisible"], (void *) getBypass, (void **) &old_Bypass);
    
    /*
    _methods["Camera::get_main"] = Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "get_main");
    _methods["Camera::WorldToScreenPoint"] = Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "WorldToScreenPoint", 1);
    _methods["ValueLinkerComponent::get_actorHp"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ValueLinkerComponent", "get_actorHp");
    _methods["ValueLinkerComponent::get_actorHpTotal"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ValueLinkerComponent", "get_actorHpTotal");
    _fields["CActorInfo::ActorName"] = Il2CppGetFieldOffset("Project_d.dll", "Assets.Scripts.GameLogic", "CActorInfo", "ActorName");
    _fields["ActorLinker::ValueComponent"] = Il2CppGetFieldOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "ValueComponent");
    _methods["ActorLinker::get_position"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "get_position");
    _fields["ActorLinker::CharInfo"] = Il2CppGetFieldOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "CharInfo");
    _methods["ActorLinker::IsHostCamp"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ActorLinker", "IsHostCamp");
    _methods["ActorManager::GetAllHeros"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios.Actor", "ActorManager", "GetAllHeros");
    _methods["KyriosFramework::get_actorManager"] = Il2CppGetMethodOffset("Project_d.dll", "Kyrios", "KyriosFramework", "get_actorManager");
    _methods["Camera::set_fieldOfView"] = Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "set_fieldOfView", 1);
    */
    
    offsets_load();
    
    return nullptr;
    }
}
