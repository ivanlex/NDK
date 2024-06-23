#include <iostream>
#include <jni.h>
#include "jni_interface.h"

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_com_example_plcremote_MainActivity_deleteSLBufferQueueAudioPlayer(
        JNIEnv *env, jclass type) {
    std::cout << "hello world" << std::endl;
}

#ifdef  __cplusplus
}
#endif