package com.jni.gpiod;

public class Gpiod {

    private static String GPIOCHIP_0 = "/dev/gpiochip0";
    private static String GPIOCHIP_1 = "/dev/gpiochip1";

    static {
        System.loadLibrary("gpiodgvc");
    }

    public static void main(String[] args) {
        Gpiod gpiodLocal = new Gpiod();

        GpiodChip gpiodChip0 = gpiodLocal.getGpiodChip(GPIOCHIP_0);
        if (gpiodChip0 != null) {
            System.out.println(gpiodChip0.toString());
        }
        else {
            System.out.println("Returned null from JNI land");
        }

        GpiodChip gpiodChip1 = gpiodLocal.getGpiodChip(GPIOCHIP_1);
        if (gpiodChip1 != null) {
            System.out.println(gpiodChip1.toString());
        }
        else {
            System.out.println("Returned null from JNI land");
        }

        GpiodChipInfo gpiodChipInfo0 = gpiodLocal.getGpiodChipInfo(GPIOCHIP_0);
        if (gpiodChipInfo0 != null) {
            System.out.println(gpiodChipInfo0.toString());
        }
        else {
            System.out.println("Returned null from JNI land");
        }

        GpiodChipInfo gpiodChipInfo1 = gpiodLocal.getGpiodChipInfo(GPIOCHIP_1);
        if (gpiodChipInfo1 != null) {
            System.out.println(gpiodChipInfo1.toString());
        }
        else {
            System.out.println("Returned null from JNI land");
        }
    }

    /**
     * Method to retrieve the following info from the GPIO chip:
     * - File descriptor
     * - GPIO path
     *
     * @parm - chipName: the GPIO chip for which to retrieve the GPIO chip information
     * @return - GpioChip object containing both the file descriptor as well as the GPIO path
     *         - null if retrieving the information failed
     */
    public native GpiodChip getGpiodChip(String chipName);

    /**
     * Method to retrieve the following info from the GPIO chip:
     * - Number of lines
     * - GPIO chip name
     * - GPIO chip label
     *
     * @parm - chipName: the GPIO chip for which to retrieve the GPIO chip information
     * @return - GpiodChipInfo object containing both the file descriptor as well as the GPIO path
     *         - null if retrieving the information failed
     */
    public native GpiodChipInfo getGpiodChipInfo(String chipName);
}