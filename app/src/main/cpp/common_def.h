//
// Created by user on 6/24/2024.
//
#pragma once
#define CAPI extern "C"

#define ADSTOJAVA_FILE_VERSION_MAJOR 3
#define ADSTOJAVA_FILE_VERSION_MINOR 1
#define ADSTOJAVA_FILE_VERSION 3.1

#define DEVICE_NAME_MAX_LEN 128

#include <stddef.h>
#include <stdint.h>
#include "jni.h"
#include "ADS/AdsLib.h"

typedef uint32_t DWORD;
typedef uint32_t ULONG;
typedef int32_t LONG;
typedef unsigned int BOOL;
#ifndef FAR
#define FAR
#endif
#ifndef NULL
#define NULL 0 // required by the TwinCAT headers
#endif
#define ADSSTDCALL

#include "ADS/AdsDef.h"

typedef long ADS_INT32_OR_LONG;
typedef unsigned int ADS_NOTIFICATION_USER_HANDLE;
typedef uint32_t ADS_TIMEOUT;

typedef int ads_bool;
typedef int32_t ads_i32;
typedef uint32_t ads_ui32;
typedef AmsNetId* PAmsNetId;
typedef AmsAddr* PAmsAddr;
inline ads_i32 AdsGetDllVersion() {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortOpenEx instead
    return 0; // returning zero as a version number is probably safer than some
              // error code that could be mistaken for a very high version
              // number.
}
inline ADS_INT32_OR_LONG AdsPortOpen() {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortOpenEx instead
    return 0; // zero means no port could be opened. zero is not a valid ADS
              // port number.
}
inline ADS_INT32_OR_LONG AdsPortClose() {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsGetLocalAddress(AmsAddr*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsGetLocalAddressEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ads_i32 AdsAmsPortEnabled(ads_bool*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ads_i32 AdsAmsPortEnabledEx(ADS_INT32_OR_LONG, ads_bool*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncGetTimeout(ADS_TIMEOUT*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncSetTimeout(ADS_TIMEOUT) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncReadReq(const AmsAddr*, uint32_t, uint32_t,
                                        uint32_t, void*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncReadWriteReq(const AmsAddr*, uint32_t, uint32_t,
                                             uint32_t, void*, uint32_t,
                                             const void*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncReadWriteReqEx(const AmsAddr*, uint32_t,
                                               uint32_t, uint32_t, void*,
                                               uint32_t, const void*,
                                               uint32_t*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncWriteReq(const AmsAddr*, uint32_t, uint32_t,
                                         uint32_t, const void*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncReadStateReq(const AmsAddr*, uint16_t*,
                                             uint16_t*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncReadDeviceInfoReq(const AmsAddr*, char*,
                                                  AdsVersion*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncWriteControlReq(const AmsAddr*, uint16_t,
                                                uint16_t, uint32_t,
                                                const void*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG
AdsSyncAddDeviceNotificationReq(const AmsAddr*, uint32_t, uint32_t,
                                const AdsNotificationAttrib*,
                                PAdsNotificationFuncEx, uint32_t, uint32_t*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncDelDeviceNotificationReq(const AmsAddr*,
                                                         uint32_t) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncReadReqEx(const AmsAddr*, uint32_t, uint32_t,
                                          uint32_t, void*, uint32_t*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsSyncReadReqEx2(ads_i32, const AmsAddr*, uint32_t,
                                           uint32_t, uint32_t, void*,
                                           uint32_t*) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
typedef void (*PAmsRouterNotificationFuncEx)(ads_i32);
typedef void (*PAmsRouterNotificationFunc)(ads_i32);
inline ADS_INT32_OR_LONG
AdsAmsRegisterRouterNotification(PAmsRouterNotificationFunc) {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}
inline ADS_INT32_OR_LONG AdsAmsUnRegisterRouterNotification() {
    // not supported by the open-source ADS lib
    // (https://github.com/Beckhoff/ADS) use AdsPortCloseEx instead
    return ADSERR_DEVICE_SRVNOTSUPP;
}

