//
// Created by Administrator on 6/22/2024.
//

#ifndef PLCREMOTE_JNI_INTERFACE_H
#define PLCREMOTE_JNI_INTERFACE_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_com_example_plcremote_MainActivity_deleteSLBufferQueueAudioPlayer(JNIEnv *env,
                                                             jclass type);

#ifdef __cplusplus
}
#endif

#endif //PLCREMOTE_JNI_INTERFACE_H
