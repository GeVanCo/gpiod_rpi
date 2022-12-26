export JAVA_HOME=/home/pi/mystuff/jdk11
export OUT_DIR=${PWD}/out
export LIBGPIOD_DIR=/home/pi/mystuff/libgpiod/gvcresult/lib
export LIBGPIOD_HEADER_DIR=/home/pi/mystuff/libgpiod/gvcresult/include
export MY_JNI_HEADERS=${OUT_DIR}/jniHeaders
export PROJECT_PACKAGE=${PWD}/java/com/jni/gpiod
export CPP_FOLDER=${PWD}/cpp
export LD_LIBRARY_PATH=${LIBGPIOD_DIR}

#CC=gcc
CFLAGS=-Wall

all: clean
	mkdir -p ${OUT_DIR} ${MY_JNI_HEADERS}
	javac -h ${MY_JNI_HEADERS} -d ${OUT_DIR} ${PROJECT_PACKAGE}/*.java
	$(CC) -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${MY_JNI_HEADERS} -I${LIBGPIOD_HEADER_DIR} ${CPP_FOLDER}/Gpiod.cpp -o ${OUT_DIR}/gpiodLib.o
	$(CC) -shared -fPIC -o ${OUT_DIR}/libgpiodgvc.so ${OUT_DIR}/gpiodLib.o -lc -L${LIBGPIOD_DIR} -lgpiod

run: all go

go:
	java -cp ${OUT_DIR} -Djava.library.path=${OUT_DIR}:${LIBGPIOD_DIR} com.jni.gpiod.Gpiod

clean:
	rm -rf ${OUT_DIR} ${MY_JNI_HEADERS}
