#pragma once
#include "JObjectBase.h"
#include "common_def.h"
#include <jni.h>

class JObjAdsDevName : public JObjectBase {
  public:
    JObjAdsDevName(JNIEnv* lEnv, jobject lJObject);
    ~JObjAdsDevName() = default;

    void setValuesInJObject(const char** pAdsDevName);
    void getValuesOutJObject(const char** pAdsDevName);
};
