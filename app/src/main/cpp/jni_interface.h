#pragma once

#include "common_def.h"
#include <jni.h>

// ADSCallbacks
JavaVM* jvm;         // The java vm we are running
jobject javaSinkObj; // the java object to delegate calls

// global jclass definitions to use when ClassLoader is unavailable
// (e.g. when callbacks are redirected via native c code via AdsRouterCallback
// or AdsStateCallback)
jclass ljclass_glAmsAddrRef;
jclass ljclass_glAdsNotifHeader;
jclass ljclass_glJNILong;

jmethodID mid_AdsStateCallback = 0;
jmethodID mid_AdsRouterCallback = 0;

// AddLocalRoute
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAddLocalRoute(
        JNIEnv* env, jclass obj,
        jobject lj_AmsNetId, // AMS NetId of ADS server
        jstring lj_IpAddr);  // IP address, where the ADS server can be found

// DelLocalRoute
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllDelLocalRoute(
        JNIEnv* env, jclass obj,
        jobject lj_AmsNetId); // AMS NetId of ADS server

// SetLocalAddress
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllSetLocalAddress(
        JNIEnv* env, jclass obj,
        jobject lj_AmsNetId); // AMS NetId of ADS server

// AdsGetDllVersion
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsGetDllVersion(
        JNIEnv* env, jclass obj, jobject lResultDllVersion);

// AdsPortOpen
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsPortOpen(JNIEnv* env,
                                                                 jclass obj);

// AdsPortClose
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsPortClose(JNIEnv* env,
                                                                  jclass obj);

// AdsGetLocalAddress
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsGetLocalAddress(
        JNIEnv* env, jclass obj, jobject lj_AmsAddr);

// Historically important, needs to be untouched for backwards compatibility

// AdsGetLocalAddressn
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsGetLocalAddressn(
        JNIEnv* env, jclass obj, jobject lj_AmsAddr);

// AdsSyncReadReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadReq(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,   // AMS address of ADS server
        jlong lj_indexGroup,  // index group in ADS server interface
        jlong lj_indexOffset, // index offset in ADS server interface
        jlong lj_length,      // count of bytes to read
        jobject lj_pData);    // pointer to the client buffer

// AdsSyncReadReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadReqEx(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,       // AMS address of ADS server
        jlong lj_indexGroup,      // index group in ADS server interface
        jlong lj_indexOffset,     // index offset in ADS server interface
        jlong lj_length,          // count of bytes to read
        jobject lj_pData,         // pointer to the client buffer
        jobject lj_lengthReturn); // count of bytes read

// AdsSyncWriteReq jbyteArray
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncWriteReqArray(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,   // AMS address of ADS server
        jlong lj_indexGroup,  // index group in ADS server interface
        jlong lj_indexOffset, // index offset in ADS server interface
        jlong lj_length,      // count of bytes to read
        jbyteArray lj_pData); // pointer to the client buffer

// AdsSyncWriteReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncWriteReq(
        JNIEnv* env, jobject obj,
        jobject lj_AmsAddr,   // AMS address of ADS server
        jlong lj_indexGroup,  // index group in ADS server interface
        jlong lj_indexOffset, // index offset in ADS server interface
        jlong lj_length,      // count of bytes to read
        jobject lj_pData);    // pointer to the client buffer

// AdsSyncReadWriteReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadWriteReq(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,     // AMS address of ADS server
        jlong lj_indexGroup,    // index group in ADS server interface
        jlong lj_indexOffset,   // index offset in ADS server interface
        jlong lj_cbReadLength,  // count of bytes to read
        jobject lj_pReadData,   // pointer to the client buffer
        jlong lj_cbWriteLength, // count of bytes to write
        jobject lj_pWriteData); // pointer to the client buffer

// AdsSyncReadWriteReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadWriteReqEx(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,       // AMS address of ADS server
        jlong lj_indexGroup,      // index group in ADS server interface
        jlong lj_indexOffset,     // index offset in ADS server interface
        jlong lj_cbReadLength,    // count of bytes to read
        jobject lj_pReadData,     // pointer to the client buffer
        jlong lj_cbWriteLength,   // count of bytes to write
        jobject lj_pWriteData,    // pointer to the client buffer
        jobject lj_lengthReturn); // count to bytes read

// AdsSyncReadStateReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadStateReq(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,       // AMS address of ADS server
        jobject lj_nAdsState,     // pointer to client buffer
        jobject lj_nDeviceState); // pointer to the client buffer

// AdsSyncReadDeviceInfoReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadDeviceInfoReq(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,   // AMS address of ADS server
        jobject lj_pDevName,  // fixed length string (16 Byte)
        jobject lj_pVersion); // client buffer to store server version

// AdsSyncWriteControlReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncWriteControlReq(
        JNIEnv* env, jclass obj,
        jobject lj_AmsAddr,  // AMS address of ADS server
        jint lj_adsState,    // index group in ADS server interface
        jint lj_deviceState, // index offset in ADS server interface
        jlong lj_length,     // count of bytes to write
        jobject lj_pData);   // pointer to the client buffer

// AdsSyncSetTimeout
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncSetTimeout(
        JNIEnv* env, jclass obj,
        jlong lj_nMs); // Set timeout in ms

// AdsSyncGetTimeout
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncGetTimeout(
        JNIEnv* env, jclass obj,
        jobject lj_pMs); // Get timeout in ms

// AdsAmsRegisterRouterNotification
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsAmsRegisterRouterNotification(
        JNIEnv* env, jclass obj);

// AdsAmsUnRegisterRouterNotification
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsAmsUnRegisterRouterNotification(
        JNIEnv* env, jclass obj);

// AdsSyncAddDeviceNotificationReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncAddDeviceNotificationReq(
        JNIEnv* env, jclass obj,
        jobject lj_pAddr,          // AMS address of ADS server
        jlong lj_indexGroup,       // index group in ADS server interface
        jlong lj_indexOffset,      // index offset in ADS server interface
        jobject lj_pNoteAttrib,    // attributes of notification request
        jlong lj_hUser,            // user handle
        jobject lj_pNotification); // pointer to notification handle (return value)

// AdsSyncDelDeviceNotificationReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncDelDeviceNotificationReq(
        JNIEnv* env, jclass obj,
        jobject lj_pAddr,          // AMS address of ADS server
        jobject lj_hNotification); // notification handle

// callDllAdsDoInitCallbacks
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllDoInitCallbacks(
        JNIEnv* env, jclass obj, jobject aSinkObj);

// AdsDoInitDll
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllDoInitDll(JNIEnv* env,
                                                               jclass obj);

// AdsDoWhenUnloadDll
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllDoWhenUnloadDll(
        JNIEnv* env, jclass obj);

// AdsAmsPortEnabled
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsAmsPortEnabled(
        JNIEnv* env, jclass obj, jobject bEnabled);

// AdsGetLastError
// CAPI JNIEXPORT jlong JNICALL
// Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsGetLastError(
//  JNIEnv *env, jobject obj);

///////////////////////////////////////////////////////////////////////////
// extended methods

// AdsPortOpenEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsPortOpenEx(JNIEnv* env,
                                                                   jclass obj);

// AdsPortCloseEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsPortCloseEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort); // AMS port of ADS client

// AdsGetLocalAddressEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsGetLocalAddressEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,      // AMS port of ADS client
        jobject lj_AmsAddr); // AMS address of ADS server

// AdsSyncWriteReq
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncWriteReqEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,       // AMS port of ADS client
        jobject lj_AmsAddr,   // AMS address of ADS server
        jlong lj_indexGroup,  // index group in ADS server interface
        jlong lj_indexOffset, // index offset in ADS server interface
        jlong lj_length,      // count of bytes to read
        jobject lj_pData);    // pointer to the client buffer

// AdsSyncWriteReqEx jbyteArray
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncWriteReqExArray(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,       // AMS port of ADS client
        jobject lj_AmsAddr,   // AMS address of ADS server
        jlong lj_indexGroup,  // index group in ADS server interface
        jlong lj_indexOffset, // index offset in ADS server interface
        jlong lj_length,      // count of bytes to read
        jbyteArray lj_pData); // pointer to the client buffer

// AdsSyncWriteReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncWriteReqExArray__I(
        JNIEnv* env, jobject obj,
        jlong lj_nPort,       // AMS port of ADS client
        jobject lj_AmsAddr,   // AMS address of ADS server
        jlong lj_indexGroup,  // index group in ADS server interface
        jlong lj_indexOffset, // index offset in ADS server interface
        jlong lj_length,      // count of bytes to read
        jobject lj_pData);    // pointer to the client buffer

// AdsSyncReadReqEx2
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadReqEx2(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,           // AMS port of ADS client
        jobject lj_AmsAddr,       // AMS address of ADS server
        jlong lj_indexGroup,      // index group in ADS server interface
        jlong lj_indexOffset,     // index offset in ADS server interface
        jlong lj_length,          // count of bytes to read
        jobject lj_pData,         // pointer to the client buffer
        jobject lj_lengthReturn); // count of bytes read

// AdsSyncReadWriteReqEx2
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadWriteReqEx2(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,           // AMS port of ADS client
        jobject lj_AmsAddr,       // AMS address of ADS server
        jlong lj_indexGroup,      // index group in ADS server interface
        jlong lj_indexOffset,     // index offset in ADS server interface
        jlong lj_cbReadLength,    // count of bytes to read
        jobject lj_pReadData,     // pointer to the client buffer
        jlong lj_cbWriteLength,   // count of bytes to write
        jobject lj_pWriteData,    // pointer to the client buffer
        jobject lj_lengthReturn); // count of bytes read

// AdsSyncReadDeviceInfoReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadDeviceInfoReqEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,       // AMS port of ADS client
        jobject lj_AmsAddr,   // AMS address of ADS server
        jobject lj_pDevName,  // fixed length string (16 Byte)
        jobject lj_pVersion); // client buffer to store server version

// AdsSyncWriteControlReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncWriteControlReqEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,      // AMS port of ADS client
        jobject lj_AmsAddr,  // AMS address of ADS server
        jint lj_adsState,    // index group in ADS server interface
        jint lj_deviceState, // index offset in ADS server interface
        jlong lj_length,     // count of bytes to write
        jobject lj_pData);   // pointer to the client buffer

// AdsSyncReadStateReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncReadStateReqEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,           // AMS port of ADS client
        jobject lj_AmsAddr,       // AMS address of ADS server
        jobject lj_nAdsState,     // pointer to client buffer
        jobject lj_nDeviceState); // pointer to the client buffer

// AdsSyncSetTimeoutEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncSetTimeoutEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort, // AMS port of ADS client
        jlong lj_nMs);  // Set timeout in ms

// AdsSyncGetTimeoutEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncGetTimeoutEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,  // AMS port of ADS client
        jobject lj_nMs); // Get timeout in ms

// AdsSyncAddDeviceNotificationReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncAddDeviceNotificationReqEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,            // AMS port of ADS client
        jobject lj_pAddr,          // AMS address of ADS server
        jlong lj_indexGroup,       // index group in ADS server interface
        jlong lj_indexOffset,      // index offset in ADS server interface
        jobject lj_pNoteAttrib,    // attributes of notification request
        jlong lj_hUser,            // user handle
        jobject lj_pNotification); // pointer to notification handle (return value)

// AdsSyncDelDeviceNotificationReqEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsSyncDelDeviceNotificationReqEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort,            // AMS port of ADS client
        jobject lj_pAddr,          // AMS address of ADS server
        jobject lj_hNotification); // notification handle

// AdsAmsPortEnabledEx
CAPI JNIEXPORT jlong JNICALL
Java_de_beckhoff_jni_tcads_AdsCallDllFunction_callDllAdsAmsPortEnabledEx(
        JNIEnv* env, jclass obj,
        jlong lj_nPort, // AMS port of ADS client
        jobject bEnabled);
