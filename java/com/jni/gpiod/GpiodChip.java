package com.jni.gpiod;

public class GpiodChip {
  	public int fd;
    public String path;


    @Override
    public String toString() {
        return String.format("\nTo string method returns: \n\nFile descriptor = %d\nPath = %s", fd, path);
    }
}
