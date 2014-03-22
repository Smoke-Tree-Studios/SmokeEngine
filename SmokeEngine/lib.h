#include <android/log.h>
#include <jni.h>


#define  LOG_TAG    "Engine"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

// LOGE("Could not link program:\n%s\n", buf);

