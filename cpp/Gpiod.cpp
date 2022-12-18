#include <jni.h>
#include <iostream>
#include "com_jni_gpiod_Gpiod.h"


/*
 * Class:     com_jni_gpiod_Gpiod
 * Method:    getChip
 * Signature: ()Lcom/jni/gpiod/GpiodChip;
 */
JNIEXPORT jobject JNICALL Java_com_jni_gpiod_Gpiod_getChip
  (JNIEnv * env, jobject thisObject) {

    std::cout << "Entered method [Java_com_jni_gpiod_Gpiod_getChip]." << std::endl;

    jclass gpiodChipClass = env->FindClass("com/jni/gpiod/GpiodChip");
    jobject gpiodChip = env->AllocObject(gpiodChipClass);

    jfieldID fdID = env->GetFieldID(gpiodChipClass, "fd", "I");
    jfieldID pathID = env->GetFieldID(gpiodChipClass, "path", "Ljava/lang/String;");

    env->SetIntField(gpiodChip, fdID, 120);
    env->SetObjectField(gpiodChip, pathID, env->NewStringUTF("gpiochip365"));

    std::cout << "Returning detailed GpiodChip information." << std::endl;

    return gpiodChip;
}
