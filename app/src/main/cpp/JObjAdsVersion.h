#pragma once
#include "JObjectBase.h"
#include "common_def.h"
#include "jni.h"

class JObjAdsVersion : public JObjectBase {
  public:
    JObjAdsVersion(JNIEnv* lEnv, jobject lJObject);
    ~JObjAdsVersion() = default;

    void setValuesInJObject(AdsVersion* pAdsVersion);
    void getValuesOutJObject(AdsVersion* pAdsVersion);
};
