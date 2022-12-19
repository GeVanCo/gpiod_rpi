package com.jni.gpiod;

public class Gpiod {

    static {
        System.loadLibrary("gpiodgvc");
        System.loadLibrary("gpiod");
    }

    public static void main(String[] args) {
        Gpiod gpiodLocal = new Gpiod();
        System.out.println("\n\n---- Back in Java land ----\n");

        GpiodChip gpiodChip = gpiodLocal.getChip();
        if (gpiodChip != null) {
            System.out.println("GpiodChip content = " + gpiodChip.toString());
        }
        else {
            System.out.println("Returned null from JNI land");
        }

    }

    public native GpiodChip getChip();
}