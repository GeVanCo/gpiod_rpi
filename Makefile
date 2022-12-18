export JAVA_HOME=/home/pi/mystuff/jdk11
export OUT_DIR=${PWD}/out
export MY_JNI_HEADERS=${OUT_DIR}/jniHeaders
export PROJECT_PACKAGE=${PWD}/java/com/jni/gpiod
export CPP_FOLDER=${PWD}/cpp

temperaturesampler: clean
	mkdir -p ${OUT_DIR} ${MY_JNI_HEADERS}
	javac -h ${MY_JNI_HEADERS} -d ${OUT_DIR} ${PROJECT_PACKAGE}/*.java
	g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${MY_JNI_HEADERS} ${CPP_FOLDER}/Gpiod.cpp -o ${OUT_DIR}/gpiodLib.o
	g++ -shared -fPIC -o ${OUT_DIR}/libgpiodgvc.so ${OUT_DIR}/gpiodLib.o -lc

run: temperaturesampler
	java -cp ${OUT_DIR} -Djava.library.path=${OUT_DIR} com.jni.gpiod.Gpiod

go:
	java -cp ${OUT_DIR} -Djava.library.path=${OUT_DIR} com.jni.gpiod.Gpiod

clean:
	rm -rf ${OUT_DIR} ${MY_JNI_HEADERS}
