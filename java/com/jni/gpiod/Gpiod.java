package com.jni.gpiod;

public class Gpiod {

    static {
        System.loadLibrary("gpiodgvc");
    }

    public static void main(String[] args) {
        Gpiod gpiodLocal = new Gpiod();
        System.out.println("---- Back in Java land");
        System.out.println("     Final output");

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