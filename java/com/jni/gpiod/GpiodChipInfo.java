package com.jni.gpiod;

public class GpiodChipInfo {
    public int numLines;
    public String name;
    public String label;


    @Override
    public String toString() {
        return String.format(
            "\n  GpiodChipInfo content:\n" +
            "  - Number of lines = [%d]\n" +
            "  - Name            = [%s]\n" +
            "  - Label           = [%s]\n"
            , numLines
            , name
            , label
        );
    }
}