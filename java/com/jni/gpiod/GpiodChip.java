package com.jni.gpiod;

public class GpiodChip {
  	public int fileDescriptor;
    public String gpioChipPath;


    @Override
    public String toString() {
        return String.format(
            "\n  GpioChip content:\n" +
            "  - File descriptor = [%d]\n" +
            "  - Path            = [%s]\n", fileDescriptor, gpioChipPath
        );
    }
}
