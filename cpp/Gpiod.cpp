#include <jni.h>
#include <stdio.h>
#include <gpiod.h>
#include "com_jni_gpiod_Gpiod.h"


/*
 * Class:     com_jni_gpiod_Gpiod
 * Method:    getGpiodChip
 * Signature: (Ljava/lang/String;)Lcom/jni/gpiod/GpiodChip;
 */
JNIEXPORT jobject JNICALL Java_com_jni_gpiod_Gpiod_getGpiodChip
  (JNIEnv * env, jobject thisObject, jstring inString) {

    printf("-----------------------\n");

    jboolean isCopy;
    const char *inputString = env->GetStringUTFChars(inString, &isCopy);
    printf("Entered method [Java_com_jni_gpiod_Gpiod_getGpiodChip] with parameter [%s].\n", inputString);

	struct gpiod_chip *gpiodChipStruct;
    struct gpiod_chip_info *gpiodChipInfoStruct;

  	gpiodChipStruct = gpiod_chip_open(inputString);
    if (gpiodChipStruct == NULL) {
        perror("Error");
    }

    gpiodChipInfoStruct = gpiod_chip_get_info(gpiodChipStruct);
    if (gpiodChipInfoStruct == NULL) {
        perror("Error");
    }


    int chipFd = gpiod_chip_get_fd(gpiodChipStruct);
    const char *gpioPath = gpiod_chip_get_path(gpiodChipStruct);

    //------------------------------------------------------
    // begin separate small testcalls...

    // const char * versionNumber = gpiod_api_version();
    // printf("Version number: [%s].\n", versionNumber);

    // end separate small testcalls...
    //------------------------------------------------------

    jclass gpiodChipClass = env->FindClass("com/jni/gpiod/GpiodChip");
    // Create instance of class GpiodChip.
    jobject gpiodChip = env->AllocObject(gpiodChipClass);

    // Retrieve the fields of the class GpiodChip.
    jfieldID fdID = env->GetFieldID(gpiodChipClass, "fileDescriptor", "I");
    jfieldID pathID = env->GetFieldID(gpiodChipClass, "gpioChipPath", "Ljava/lang/String;");

    env->SetIntField(gpiodChip, fdID, chipFd);
    env->SetObjectField(gpiodChip, pathID, env->NewStringUTF(gpioPath));

    gpiod_chip_info_free(gpiodChipInfoStruct);

    return gpiodChip;
}


/*
 * Class:     com_jni_gpiod_Gpiod
 * Method:    getGpiodChipInfo
 * Signature: (Ljava/lang/String;)Lcom/jni/gpiod/GpiodChipInfo;
 */
JNIEXPORT jobject JNICALL Java_com_jni_gpiod_Gpiod_getGpiodChipInfo
  (JNIEnv * env, jobject thisObject, jstring inString) {

    printf("-----------------------\n");

    jboolean isCopy;
    const char *inputString = env->GetStringUTFChars(inString, &isCopy);
    printf("Entered method [Java_com_jni_gpiod_Gpiod_getGpiodChipInfo] with parameter [%s].\n", inputString);

 	struct gpiod_chip *gpiodChipStruct = gpiod_chip_open(inputString);
    if (gpiodChipStruct == NULL) {
        perror("Error");
    }

    struct gpiod_chip_info *gpiodChipInfoStruct = gpiod_chip_get_info(gpiodChipStruct);
    if (gpiodChipInfoStruct == NULL) {
        perror("Error");
    }

    jclass gpiodChipInfoClass = env->FindClass("com/jni/gpiod/GpiodChipInfo");
    // Create instance of class GpiodChipInfo.
    jobject gpiodChipInfo = env->AllocObject(gpiodChipInfoClass);

    // Retrieve the fields of the class GpiodChipInfo.
    jfieldID numLinesID = env->GetFieldID(gpiodChipInfoClass, "numLines", "I");
    jfieldID nameID = env->GetFieldID(gpiodChipInfoClass, "name", "Ljava/lang/String;");
    jfieldID labelID = env->GetFieldID(gpiodChipInfoClass, "label", "Ljava/lang/String;");

    int nroflines = gpiod_chip_info_get_num_lines(gpiodChipInfoStruct);
    // printf("Number of lines found: [%d].\n", nroflines);

    const char *chipLabel = gpiod_chip_info_get_label(gpiodChipInfoStruct);
    // printf("Chip label: [%s].\n", chipLabel);

    const char *chipName = gpiod_chip_info_get_name(gpiodChipInfoStruct);
    // printf("Chip name: [%s].\n", chipName);

    env->SetIntField(gpiodChipInfo, numLinesID, nroflines);
    env->SetObjectField(gpiodChipInfo, nameID, env->NewStringUTF(chipName));
    env->SetObjectField(gpiodChipInfo, labelID, env->NewStringUTF(chipLabel));

    gpiod_chip_info_free(gpiodChipInfoStruct);

    return gpiodChipInfo;
}
