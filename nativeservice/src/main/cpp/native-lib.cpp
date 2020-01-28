#include <jni.h>
#include <string>

#include <android/binder_ibinder_jni.h>
#include <android/log.h>

#include "RemoteService.h"

JNIEXPORT jint JNI_OnLoad(JavaVM* pVM, void*) {
    JNIEnv *env;
    if (pVM->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_EVERSION;
    }

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNI_OnUnload(JavaVM* vm, void* reserved) {
    return;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativeservice_NativeServiceActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    return env->NewStringUTF( "Hello from C++");
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_nativeservice_NativeLibrary_getNativeBinderJNI(JNIEnv *env, jclass thiz,
                                                                jstring jaction) {
    auto str = env->GetStringUTFChars(jaction, nullptr);
    if (!str) return nullptr;
    std::string action(str);
    env->ReleaseStringUTFChars(jaction, str);

    ::ndk::SpAIBinder binder = ::ndk::SharedRefBase::make<RemoteService>()->asBinder();

    jobject obj = AIBinder_toJavaBinder(env, binder.get());



    return obj;
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_nativeservice_NativeLibrary_releaseNativeBinderJNI(JNIEnv *env, jclass clazz,
                                                                    jobject jbinder) {
    AIBinder* binder = AIBinder_fromJavaBinder(env, jbinder);
    env->DeleteLocalRef(jbinder);

}