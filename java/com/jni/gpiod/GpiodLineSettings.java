package com.jni.gpiod;

public class GpiodLineSettings {
    Enum GpiodLineDirection lineDirectionEnum;
    Enum GpiodLineEdge lineEdgeDetectionEnum;
    Enum GpiodLineDrive lineDriveEnum;
    Enum GpiodLineBias lineBiasEnum;
    boolean activeLow;
    Enum GpiodLineClock lineClockEnum;
    long debouncePeriodUs;
    Enum GpiodLineValue lineValueEnum;
}
// struct gpiod_line_settings {
	// enum gpiod_line_direction direction;
	// enum gpiod_line_edge edge_detection;
	// enum gpiod_line_drive drive;
	// enum gpiod_line_bias bias;
	// bool active_low;
	// enum gpiod_line_clock event_clock;
	// long debounce_period_us;
	// enum gpiod_line_value output_value;
// };
