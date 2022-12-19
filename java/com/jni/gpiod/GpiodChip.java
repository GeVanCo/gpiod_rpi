package com.jni.gpiod;

public class GpiodChip {
  	public int fd;
    public String path;


    @Override
    public String toString() {
        return String.format("\n  - File descriptor = %d\n  - Path = %s", fd, path);
    }
}
