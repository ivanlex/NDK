#pragma once
#include "JObjectBase.h"
#include "common_def.h"
#include "jni.h"

class JObjAmsNetId : public JObjectBase {
  public:
    JObjAmsNetId(JNIEnv* lEnv, jobject lJObject);
    ~JObjAmsNetId() = default;

    void setValuesInJObject(const AmsNetId* pNetId);
    void getValuesOutJObject(PAmsNetId pNetId);
};
