#pragma once
#include "JObjectBase.h"
#include "common_def.h"
#include "jni.h"

class JObjAdsNotificationAttrib : public JObjectBase {
  public:
    JObjAdsNotificationAttrib(JNIEnv* lEnv, jobject lJObject);
    ~JObjAdsNotificationAttrib() = default;

    void setValuesInJObject(AdsNotificationAttrib* pAdsNotificationAttrib);
    void getValuesOutJObject(AdsNotificationAttrib* pAdsNotificationAttrib);
};
