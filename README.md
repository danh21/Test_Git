# Test_Git
Test operation of Git

led_hal

# Debug with SWV
    - Run -> Debug Configurations... 
        + In tab Debugger -> Enable Serial Wire Viewer (SWV) -> Debug
        ![](https://github.com/danh21/Test_Git/blob/main/img/enable_SWV.png)
    - Window -> Show View -> SWV -> SWV ITM Data Console
        + Configure trace -> Tick to ITM Stimulus port 0 -> OK
        + Start trace
    - Resume debugging (F8)