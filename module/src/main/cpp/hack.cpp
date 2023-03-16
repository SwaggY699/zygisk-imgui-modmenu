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
#include "main.h"

#include "ImGuiStuff.h"
#include "Menu.h"


const char* gamePKG = "com.nobodyshot.POLYWAR";

#define HOOK(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret my##func(__VA_ARGS__)

bool UnlockG;

HOOK(void, Input, void *thiz, void *ex_ab, void *ex_ac){
    origInput(thiz, ex_ab, ex_ac);
    ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz); 
    return;
}

EGLBoolean (*old_eglSwapBuffers)(...);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    
    /*
    ImGui::Checkbox("Unlock All Guns", &UnlockG);
    
    if (UnlockG) {
        hexPatches.UnG.Modify();
    } else {
        hexPatches.UnG.Restore();
    }
    */
    
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
    
    Menu::Screen_get_height = (int (*)()) getAbsoluteAddress("libil2cpp.so", 0x68F7C4);
    Menu::Screen_get_width = (int (*)()) getAbsoluteAddress("libil2cpp.so", 0x68F77C);
    
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
    do {
        sleep(1);
    } while (!isLibraryLoaded(OBFUSCATE("libil2cpp.so")));
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
    ProcMap il2cppMap;
    
    Menu::Screen_get_height = (int (*)()) getAbsoluteAddress("libil2cpp.so", 0x68F7C4);
    Menu::Screen_get_width = (int (*)()) getAbsoluteAddress("libil2cpp.so", 0x68F77C);
    
    do {
        il2cppMap = KittyMemory::getLibraryMap(libName);
        sleep(1);
    } while (!il2cppMap.isValid());
    offsets_load();
    return nullptr;
    }
}
